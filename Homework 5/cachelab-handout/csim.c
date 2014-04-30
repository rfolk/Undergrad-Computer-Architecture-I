#include "cachelab.h"
#include <getopt.h>   /* for parsing command line arguments */
#include <stdio.h>    /* for input and output */
#include <stdlib.h>   /* for basic funcionality */
#include <string.h>   /* for string and memory functions */
#include <stdbool.h>  /* for boolean types */



/* validate the pointer exists learned this trick in senior thesis */
#define CHECK_PTR( p ) if ( NULL == ( p ) ) \
{ \
  fprintf( stdout, "\n\aNO MEMORY in file %s:%d\n\n", __FILE__, __LINE__ ); \
  exit( 1 ); \
}



/* data structures */
typedef struct _Arguments
{
	bool no_arguments;
	bool help;
	bool verbose;
	int set_index_bits_exp;
	int set_index_bits;
	int lines_per_set;
	int block_offset_bits_exp;
	int block_offset_bits;
	char * trace_filename;
} Arguments;

typedef struct _Result
{
	int hits;
	int misses;
	int evictions;
} Result;

typedef struct _CacheObject
{
	int timer;
	int value;
} CacheObject;

/* function protoypes */
void print_help( void );
Arguments * initialize_arguments( void );
Result * initialize_result( void );
Result * run_trace( Arguments * );






int main( int argc , char ** argv )
{
	char arg, index;
	/*printSummary(0, 0, 0);*/

	Arguments * args = initialize_arguments();
	Result * results;

	/* parse input */
	while ( ( arg = getopt( argc, argv, "hv:s:E:b:t:") ) != -1 )
	{
		switch ( arg )
		{
			case 'h':
				args->help = true;
				break;
			case 'v':
				args->no_arguments = false;
				args->verbose = true;
				break;
			case 's':
				args->no_arguments = false;
				args->set_index_bits_exp = atoi( optarg );
				for ( index = 1; index < ( args->set_index_bits_exp ); ++index )
					args->set_index_bits = ( args->set_index_bits << 1 ) | 1;
				break;
			case 'E':
				args->no_arguments = false;
				args->lines_per_set = atoi( optarg );
				break;
			case 'b':
				args->no_arguments = false;
				args->block_offset_bits_exp = atoi( optarg );
				for ( index = 1; index < args->block_offset_bits_exp; ++index )
					args->block_offset_bits = ( args->block_offset_bits << 1 ) | 1;
				break;
			case 't':
				args->no_arguments = false;
				// no trace file? print help.
				if ( strlen( optarg ) == 0 )
					args->help = true;
				args->trace_filename = ( char * ) calloc( 1, strlen( optarg ) + 1 );
				CHECK_PTR( args->trace_filename );
				strcpy( args->trace_filename , optarg );
				break;
		}
	}

	/* if no arguments or help is requested */
	if ( args->no_arguments || args->help )
	{
		print_help();
		exit( 0 );
	}

	results = run_trace( args );

	printSummary( results->hits, results->misses, results->evictions );

	return 0;
}













/**
  *	print_help
  *
  *	This will print out the default help option and is called whenever the -h
  *	argument is passed via the run line.
  */

void print_help( void )
{
	printf( "Usage: ./csim-ref [-hv] -s <num> -E <num> -b <num> -t <file>\n" );
	printf( "Options:\n" );
	printf( "  -h         Print this help message.\n" );
	printf( "  -v         Optional verbose flag.\n" );
	printf( "  -s <num>   Number of set index bits.\n" );
	printf( "  -E <num>   Number of lines per set.\n" );
	printf( "  -b <num>   Number of block offset bits.\n" );
	printf( "  -t <file>  Trace file.\n\n" );
	printf( "Examples:\n" );
	printf( "linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n" );
	printf( "linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n" );
}





/**
  *	initialize_arguments
  *
  *	This will return the address to an Arguments struct that will be initialized
  *	with all arguments set to false or 0 and the trace filename set to null.
  */

Arguments * initialize_arguments( void )
{
	Arguments * args = ( Arguments * ) calloc( 1, sizeof( Arguments ) );
	CHECK_PTR( args );

	args->no_arguments = true;
	args->help = false;
	args->verbose = false;
	args->set_index_bits_exp = 0;
	args->set_index_bits = 1;
	args->lines_per_set = 0;
	args->block_offset_bits_exp = 0;
	args->block_offset_bits = 1;
	args->trace_filename = NULL;

	return args;
}



/**
  *	initialize_result
  *
  *	This will return the address to a Result struct that will be initialized
  *	with all values set to zero.
  */

Result * initialize_result( void )
{
	Result * res = ( Result * ) calloc( 1, sizeof( Result ) );
	CHECK_PTR( res );

	res->hits = 0;
	res->misses = 0;
	res->evictions = 0;

	return res;
}








/**
  * run_trace
  *
  */
Result * run_trace( Arguments * args )
{
	Result * results = initialize_result();

	int i, j;
	int cache_entries = pow( 2, args->set_index_bits_exp );
	CacheObject cache[ cache_entries ][ args->lines_per_set ];

	for ( i = 0; i < cache_entries; ++i )
	{
		for ( j = 0; j < args->lines_per_set; ++j )
		{
			cache[ i ][ j ].timer = -1;
			cache[ i ][ j ].value = -1;
		}
	}


	char operation;
	char[256] memory_address;
	int number_bytes;
	bool hit;
	bool miss;
	bool eviction;


	char char_input;
	int number_lines = 0;
	int cache_timer = 0;

	int index, position;

	FILE * trace_file = fopen( args->trace_filename, "r" );



	/* count the number of lines */
	while ( ( char_input = fgetc( trace_file ) ) != EOF )
	{
		if ( char_input == '\n' )
			++number_lines;
	}
	rewind( trace_file );

	/* parse each line */
	for ( index = 0; index < number_lines; ++index )
	{
		/* get the operation */
		while ( ( char_input = fgetc( trace_file ) ) != EOF )
		{
			if ( c == ' ' )
				continue;
			operation = char_input;
			break;
		}

		/* get the address */
		position = 0;
		while ( ( char_input = fgetc( trace_file ) ) != EOF )
		{
			if ( char_input == ' ' )
				continue;
			else if ( char_input == ',' )
				break;
			else
				memory_address[ position++ ] = char_input;
		}
		memory_address[ position ] = '\0';

		/* get the size */
		position = 0;
		while ( ( char_input = fgetc( trace_file ) ) != EOF )
		{
			if ( char_input == '\n' )
				break;
			number_bytes[ position++ ] = char_input;
		}

		hit = 0;
		miss = 0;
		eviction = 0;

		/* we gotta parse this line... */
		if ( operation != 'I' )
		{
			long decimal_memory_address = strtol( memory_address, '\0', 16 );
			int cache_index = ( ( int ) ( decimal_memory_address >> block_offset_bits_exp ) ) & set_index_bits;
			int cache_value = decimal_memory_address >> ( set_index_bits_exp + block_offset_bits_exp );

			for ( i = 0; i < lines_per_set; ++i )
			{
				/* cache hit */
				if ( cache[ cache_index ][ i ].value == cache_value )
				{
					++hit;
					results->hits += 1;
					cache[ cache_index ][ i ].timer = cache_timer++;

					if ( operation == 'M' )
					{
						++hit;
						results->hits += 1;
					}
					break;
				}
				/* no entry in the cache */
				else if ( cache[ cache_index ][ i ].value == -1 )
				{
					++miss;
					results->misses += 1;

					/* add to cache */
					cache[ cache_index ][ i ].value = cache_value;
					cache[ cache_index ][ i ].timer = cache_timer++;
					break;
				}
				/* last one, need to remove one to make room */
				else if ( i == lines_per_set - 1 )
				{
					int smallest = i;
					for ( j = 0; j < lines_per_set; ++j )
					{
						if ( cache[ cache_index ][ j ].timer < cache[ cache_index ][ smallest ].timer )
							smallest = j;
					}

					++miss;
					results->misses += 1;
					++eviction;
					results->evictions += 1;

					if ( operation == 'M' )
					{
						++hit;
						results->hits += 1;
					}

					cache[ cache_index ][ smallest ].value = cache_value;
					cache[ cache_index ][ smallest ].timer = cache_timer++;
					break;
				}
			}
			/* print verbose if neccessary */
		}
	} /* end each line */

	fclose( trace_file );


	return results;
}




