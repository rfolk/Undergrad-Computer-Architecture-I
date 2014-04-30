#include "cachelab.h"



/* function protoypes */
void printHelp( void );




int main()
{
    printSummary(0, 0, 0);
    return 0;
}













/**
  *	printHelp
  *
  *	This will print out the default help option and is called whenever the -h
  *	argument is passed via the run line.
  */

void printHelp( void )
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
