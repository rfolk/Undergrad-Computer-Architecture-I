#include "cachelab.h"
#include <stdbool.h> /* for boolean types */
#include <getopt.h>  /* for parsing command line arguments */



/* validate the pointer exists learned this trick in senior thesis */
#define CHECK_PTR(p) if (NULL == (p)) { \
  fprintf(stdout, "\n\aNO MEMORY in file %s:%d\n\n", __FILE__, __LINE__); \
  exit(1); \
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
	char * trace_file;
} Arguments;





/* function protoypes */
void print_help( void );
Arguments * initialize_arguments( void );







int main( int argc , char ** argv )
{
	char arg, index;
	printSummary(0, 0, 0);

	Arguments * args = initialize_arguments();

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
				args->trace_file = ( char * ) calloc( strlen( optarg ) + 1 );
				CHECK_PTR( args->trace_file );
				strcpy( args->trace_file , optarg );
				break;
		}
	}

	/* if no arguments or help is requested */
	if ( args->no_arguments || args->help )
	{
		print_help();
		exit( 0 );
	}


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
  *	with all arguments set to false and the trace filename set to null.
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
	args->trace_file = NULL;

	return args;
}

