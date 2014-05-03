/**
  * Name: Russell Folk
  * loginID: rfolk
  */


/*
 * trans.c - Matrix transpose B = A^T
 *
 * Each transpose function must have a prototype of the form:
 * void trans(int M, int N, int A[N][M], int B[M][N]);
 *
 * A transpose function is evaluated by counting the number of misses
 * on a 1KB direct mapped cache with a block size of 32 bytes.
 */
#include <stdio.h>
#include "cachelab.h"

int is_transpose(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_1_1(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_1_2(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_1_3(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_1_4(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_1_5(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_1_6(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_1_7(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_1_8(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_1_9(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_2_1(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_2_2(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_2_3(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_2_4(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_2_5(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_2_6(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_2_7(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_2_8(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_2_9(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_3_1(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_3_2(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_3_3(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_3_4(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_3_5(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_3_6(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_3_7(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_3_8(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_3_9(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_4_1(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_4_2(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_4_3(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_4_4(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_4_5(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_4_6(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_4_7(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_4_8(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_4_9(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_5_1(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_5_2(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_5_3(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_5_4(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_5_5(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_5_6(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_5_7(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_5_8(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_5_9(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_6_1(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_6_2(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_6_3(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_6_4(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_6_5(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_6_6(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_6_7(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_6_8(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_6_9(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_7_1(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_7_2(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_7_3(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_7_4(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_7_5(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_7_6(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_7_7(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_7_8(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_7_9(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_8_1(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_8_2(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_8_3(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_8_4(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_8_5(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_8_6(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_8_7(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_8_8(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_8_9(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_9_1(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_9_2(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_9_3(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_9_4(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_9_5(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_9_6(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_9_7(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_9_8(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_9_9(int M, int N, int A[N][M], int B[M][N]);

/*
 * transpose_submit - This is the solution transpose function that you
 *     will be graded on for Part B of the assignment. Do not change
 *     the description string "Transpose submission", as the driver
 *     searches for that string to identify the transpose function to
 *     be graded.
 */
char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
	int i, j, k, l;
	int tmp;
	for ( i = 0; i < N; i += blocksize1 )
	{
		for ( j = 0; j < M; j += blocksize2 )
		{
			for ( k = i; k < i + blocksize1; ++k )
			{
				for ( l = j; l < j + blocksize2; ++l )
				{
					tmp = A[ k ][ l ];
					B[ l ][ k ] = tmp;
				}
			}
		}
	}
}

/*
 * You can define additional transpose functions below. We've defined
 * a simple one below to help you get started.
 */

/*
 * trans - A simple baseline transpose function, not optimized for the cache.
 */
char trans_desc[] = "Simple row-wise scan transpose";
void trans(int M, int N, int A[N][M], int B[M][N])
{
    int i, j, tmp;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; j++) {
            tmp = A[i][j];
            B[j][i] = tmp;
        }
    }

}


char transpose_submit_desc_1_1[] = "Transpose 1x1 submission";
void transpose_submit_1_1(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 1;
        block2 = 1;
  }
 else if ( M == 64 )
    {
     block1 = 1;
        block2 = 1;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_1_2[] = "Transpose 1x2 submission";
void transpose_submit_1_2(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 1;
        block2 = 2;
  }
 else if ( M == 64 )
    {
     block1 = 1;
        block2 = 2;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_1_3[] = "Transpose 1x3 submission";
void transpose_submit_1_3(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 1;
        block2 = 3;
  }
 else if ( M == 64 )
    {
     block1 = 1;
        block2 = 3;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_1_4[] = "Transpose 1x4 submission";
void transpose_submit_1_4(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 1;
        block2 = 4;
  }
 else if ( M == 64 )
    {
     block1 = 1;
        block2 = 4;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_1_5[] = "Transpose 1x5 submission";
void transpose_submit_1_5(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 1;
        block2 = 5;
  }
 else if ( M == 64 )
    {
     block1 = 1;
        block2 = 5;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_1_6[] = "Transpose 1x6 submission";
void transpose_submit_1_6(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 1;
        block2 = 6;
  }
 else if ( M == 64 )
    {
     block1 = 1;
        block2 = 6;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_1_7[] = "Transpose 1x7 submission";
void transpose_submit_1_7(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 1;
        block2 = 7;
  }
 else if ( M == 64 )
    {
     block1 = 1;
        block2 = 7;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_1_8[] = "Transpose 1x8 submission";
void transpose_submit_1_8(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 1;
        block2 = 8;
  }
 else if ( M == 64 )
    {
     block1 = 1;
        block2 = 8;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_1_9[] = "Transpose 1x9 submission";
void transpose_submit_1_9(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 1;
        block2 = 9;
  }
 else if ( M == 64 )
    {
     block1 = 1;
        block2 = 9;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_2_1[] = "Transpose 2x1 submission";
void transpose_submit_2_1(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 2;
        block2 = 1;
  }
 else if ( M == 64 )
    {
     block1 = 2;
        block2 = 1;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_2_2[] = "Transpose 2x2 submission";
void transpose_submit_2_2(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 2;
        block2 = 2;
  }
 else if ( M == 64 )
    {
     block1 = 2;
        block2 = 2;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_2_3[] = "Transpose 2x3 submission";
void transpose_submit_2_3(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 2;
        block2 = 3;
  }
 else if ( M == 64 )
    {
     block1 = 2;
        block2 = 3;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_2_4[] = "Transpose 2x4 submission";
void transpose_submit_2_4(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 2;
        block2 = 4;
  }
 else if ( M == 64 )
    {
     block1 = 2;
        block2 = 4;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_2_5[] = "Transpose 2x5 submission";
void transpose_submit_2_5(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 2;
        block2 = 5;
  }
 else if ( M == 64 )
    {
     block1 = 2;
        block2 = 5;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_2_6[] = "Transpose 2x6 submission";
void transpose_submit_2_6(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 2;
        block2 = 6;
  }
 else if ( M == 64 )
    {
     block1 = 2;
        block2 = 6;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_2_7[] = "Transpose 2x7 submission";
void transpose_submit_2_7(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 2;
        block2 = 7;
  }
 else if ( M == 64 )
    {
     block1 = 2;
        block2 = 7;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_2_8[] = "Transpose 2x8 submission";
void transpose_submit_2_8(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 2;
        block2 = 8;
  }
 else if ( M == 64 )
    {
     block1 = 2;
        block2 = 8;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_2_9[] = "Transpose 2x9 submission";
void transpose_submit_2_9(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 2;
        block2 = 9;
  }
 else if ( M == 64 )
    {
     block1 = 2;
        block2 = 9;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_3_1[] = "Transpose 3x1 submission";
void transpose_submit_3_1(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 3;
        block2 = 1;
  }
 else if ( M == 64 )
    {
     block1 = 3;
        block2 = 1;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_3_2[] = "Transpose 3x2 submission";
void transpose_submit_3_2(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 3;
        block2 = 2;
  }
 else if ( M == 64 )
    {
     block1 = 3;
        block2 = 2;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_3_3[] = "Transpose 3x3 submission";
void transpose_submit_3_3(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 3;
        block2 = 3;
  }
 else if ( M == 64 )
    {
     block1 = 3;
        block2 = 3;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_3_4[] = "Transpose 3x4 submission";
void transpose_submit_3_4(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 3;
        block2 = 4;
  }
 else if ( M == 64 )
    {
     block1 = 3;
        block2 = 4;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_3_5[] = "Transpose 3x5 submission";
void transpose_submit_3_5(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 3;
        block2 = 5;
  }
 else if ( M == 64 )
    {
     block1 = 3;
        block2 = 5;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_3_6[] = "Transpose 3x6 submission";
void transpose_submit_3_6(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 3;
        block2 = 6;
  }
 else if ( M == 64 )
    {
     block1 = 3;
        block2 = 6;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_3_7[] = "Transpose 3x7 submission";
void transpose_submit_3_7(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 3;
        block2 = 7;
  }
 else if ( M == 64 )
    {
     block1 = 3;
        block2 = 7;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_3_8[] = "Transpose 3x8 submission";
void transpose_submit_3_8(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 3;
        block2 = 8;
  }
 else if ( M == 64 )
    {
     block1 = 3;
        block2 = 8;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_3_9[] = "Transpose 3x9 submission";
void transpose_submit_3_9(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 3;
        block2 = 9;
  }
 else if ( M == 64 )
    {
     block1 = 3;
        block2 = 9;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_4_1[] = "Transpose 4x1 submission";
void transpose_submit_4_1(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 4;
        block2 = 1;
  }
 else if ( M == 64 )
    {
     block1 = 4;
        block2 = 1;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_4_2[] = "Transpose 4x2 submission";
void transpose_submit_4_2(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 4;
        block2 = 2;
  }
 else if ( M == 64 )
    {
     block1 = 4;
        block2 = 2;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_4_3[] = "Transpose 4x3 submission";
void transpose_submit_4_3(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 4;
        block2 = 3;
  }
 else if ( M == 64 )
    {
     block1 = 4;
        block2 = 3;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_4_4[] = "Transpose 4x4 submission";
void transpose_submit_4_4(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 4;
        block2 = 4;
  }
 else if ( M == 64 )
    {
     block1 = 4;
        block2 = 4;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_4_5[] = "Transpose 4x5 submission";
void transpose_submit_4_5(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 4;
        block2 = 5;
  }
 else if ( M == 64 )
    {
     block1 = 4;
        block2 = 5;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_4_6[] = "Transpose 4x6 submission";
void transpose_submit_4_6(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 4;
        block2 = 6;
  }
 else if ( M == 64 )
    {
     block1 = 4;
        block2 = 6;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_4_7[] = "Transpose 4x7 submission";
void transpose_submit_4_7(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 4;
        block2 = 7;
  }
 else if ( M == 64 )
    {
     block1 = 4;
        block2 = 7;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_4_8[] = "Transpose 4x8 submission";
void transpose_submit_4_8(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 4;
        block2 = 8;
  }
 else if ( M == 64 )
    {
     block1 = 4;
        block2 = 8;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_4_9[] = "Transpose 4x9 submission";
void transpose_submit_4_9(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 4;
        block2 = 9;
  }
 else if ( M == 64 )
    {
     block1 = 4;
        block2 = 9;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_5_1[] = "Transpose 5x1 submission";
void transpose_submit_5_1(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 5;
        block2 = 1;
  }
 else if ( M == 64 )
    {
     block1 = 5;
        block2 = 1;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_5_2[] = "Transpose 5x2 submission";
void transpose_submit_5_2(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 5;
        block2 = 2;
  }
 else if ( M == 64 )
    {
     block1 = 5;
        block2 = 2;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_5_3[] = "Transpose 5x3 submission";
void transpose_submit_5_3(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 5;
        block2 = 3;
  }
 else if ( M == 64 )
    {
     block1 = 5;
        block2 = 3;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_5_4[] = "Transpose 5x4 submission";
void transpose_submit_5_4(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 5;
        block2 = 4;
  }
 else if ( M == 64 )
    {
     block1 = 5;
        block2 = 4;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_5_5[] = "Transpose 5x5 submission";
void transpose_submit_5_5(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 5;
        block2 = 5;
  }
 else if ( M == 64 )
    {
     block1 = 5;
        block2 = 5;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_5_6[] = "Transpose 5x6 submission";
void transpose_submit_5_6(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 5;
        block2 = 6;
  }
 else if ( M == 64 )
    {
     block1 = 5;
        block2 = 6;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_5_7[] = "Transpose 5x7 submission";
void transpose_submit_5_7(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 5;
        block2 = 7;
  }
 else if ( M == 64 )
    {
     block1 = 5;
        block2 = 7;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_5_8[] = "Transpose 5x8 submission";
void transpose_submit_5_8(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 5;
        block2 = 8;
  }
 else if ( M == 64 )
    {
     block1 = 5;
        block2 = 8;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_5_9[] = "Transpose 5x9 submission";
void transpose_submit_5_9(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 5;
        block2 = 9;
  }
 else if ( M == 64 )
    {
     block1 = 5;
        block2 = 9;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_6_1[] = "Transpose 6x1 submission";
void transpose_submit_6_1(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 6;
        block2 = 1;
  }
 else if ( M == 64 )
    {
     block1 = 6;
        block2 = 1;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_6_2[] = "Transpose 6x2 submission";
void transpose_submit_6_2(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 6;
        block2 = 2;
  }
 else if ( M == 64 )
    {
     block1 = 6;
        block2 = 2;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_6_3[] = "Transpose 6x3 submission";
void transpose_submit_6_3(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 6;
        block2 = 3;
  }
 else if ( M == 64 )
    {
     block1 = 6;
        block2 = 3;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_6_4[] = "Transpose 6x4 submission";
void transpose_submit_6_4(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 6;
        block2 = 4;
  }
 else if ( M == 64 )
    {
     block1 = 6;
        block2 = 4;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_6_5[] = "Transpose 6x5 submission";
void transpose_submit_6_5(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 6;
        block2 = 5;
  }
 else if ( M == 64 )
    {
     block1 = 6;
        block2 = 5;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_6_6[] = "Transpose 6x6 submission";
void transpose_submit_6_6(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 6;
        block2 = 6;
  }
 else if ( M == 64 )
    {
     block1 = 6;
        block2 = 6;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_6_7[] = "Transpose 6x7 submission";
void transpose_submit_6_7(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 6;
        block2 = 7;
  }
 else if ( M == 64 )
    {
     block1 = 6;
        block2 = 7;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_6_8[] = "Transpose 6x8 submission";
void transpose_submit_6_8(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 6;
        block2 = 8;
  }
 else if ( M == 64 )
    {
     block1 = 6;
        block2 = 8;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_6_9[] = "Transpose 6x9 submission";
void transpose_submit_6_9(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 6;
        block2 = 9;
  }
 else if ( M == 64 )
    {
     block1 = 6;
        block2 = 9;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_7_1[] = "Transpose 7x1 submission";
void transpose_submit_7_1(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 7;
        block2 = 1;
  }
 else if ( M == 64 )
    {
     block1 = 7;
        block2 = 1;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_7_2[] = "Transpose 7x2 submission";
void transpose_submit_7_2(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 7;
        block2 = 2;
  }
 else if ( M == 64 )
    {
     block1 = 7;
        block2 = 2;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_7_3[] = "Transpose 7x3 submission";
void transpose_submit_7_3(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 7;
        block2 = 3;
  }
 else if ( M == 64 )
    {
     block1 = 7;
        block2 = 3;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_7_4[] = "Transpose 7x4 submission";
void transpose_submit_7_4(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 7;
        block2 = 4;
  }
 else if ( M == 64 )
    {
     block1 = 7;
        block2 = 4;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_7_5[] = "Transpose 7x5 submission";
void transpose_submit_7_5(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 7;
        block2 = 5;
  }
 else if ( M == 64 )
    {
     block1 = 7;
        block2 = 5;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_7_6[] = "Transpose 7x6 submission";
void transpose_submit_7_6(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 7;
        block2 = 6;
  }
 else if ( M == 64 )
    {
     block1 = 7;
        block2 = 6;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_7_7[] = "Transpose 7x7 submission";
void transpose_submit_7_7(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 7;
        block2 = 7;
  }
 else if ( M == 64 )
    {
     block1 = 7;
        block2 = 7;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_7_8[] = "Transpose 7x8 submission";
void transpose_submit_7_8(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 7;
        block2 = 8;
  }
 else if ( M == 64 )
    {
     block1 = 7;
        block2 = 8;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_7_9[] = "Transpose 7x9 submission";
void transpose_submit_7_9(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 7;
        block2 = 9;
  }
 else if ( M == 64 )
    {
     block1 = 7;
        block2 = 9;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_8_1[] = "Transpose 8x1 submission";
void transpose_submit_8_1(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 8;
        block2 = 1;
  }
 else if ( M == 64 )
    {
     block1 = 8;
        block2 = 1;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_8_2[] = "Transpose 8x2 submission";
void transpose_submit_8_2(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 8;
        block2 = 2;
  }
 else if ( M == 64 )
    {
     block1 = 8;
        block2 = 2;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_8_3[] = "Transpose 8x3 submission";
void transpose_submit_8_3(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 8;
        block2 = 3;
  }
 else if ( M == 64 )
    {
     block1 = 8;
        block2 = 3;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_8_4[] = "Transpose 8x4 submission";
void transpose_submit_8_4(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 8;
        block2 = 4;
  }
 else if ( M == 64 )
    {
     block1 = 8;
        block2 = 4;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_8_5[] = "Transpose 8x5 submission";
void transpose_submit_8_5(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 8;
        block2 = 5;
  }
 else if ( M == 64 )
    {
     block1 = 8;
        block2 = 5;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_8_6[] = "Transpose 8x6 submission";
void transpose_submit_8_6(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 8;
        block2 = 6;
  }
 else if ( M == 64 )
    {
     block1 = 8;
        block2 = 6;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_8_7[] = "Transpose 8x7 submission";
void transpose_submit_8_7(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 8;
        block2 = 7;
  }
 else if ( M == 64 )
    {
     block1 = 8;
        block2 = 7;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_8_8[] = "Transpose 8x8 submission";
void transpose_submit_8_8(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 8;
        block2 = 8;
  }
 else if ( M == 64 )
    {
     block1 = 8;
        block2 = 8;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_8_9[] = "Transpose 8x9 submission";
void transpose_submit_8_9(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 8;
        block2 = 9;
  }
 else if ( M == 64 )
    {
     block1 = 8;
        block2 = 9;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_9_1[] = "Transpose 9x1 submission";
void transpose_submit_9_1(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 9;
        block2 = 1;
  }
 else if ( M == 64 )
    {
     block1 = 9;
        block2 = 1;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_9_2[] = "Transpose 9x2 submission";
void transpose_submit_9_2(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 9;
        block2 = 2;
  }
 else if ( M == 64 )
    {
     block1 = 9;
        block2 = 2;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_9_3[] = "Transpose 9x3 submission";
void transpose_submit_9_3(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 9;
        block2 = 3;
  }
 else if ( M == 64 )
    {
     block1 = 9;
        block2 = 3;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_9_4[] = "Transpose 9x4 submission";
void transpose_submit_9_4(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 9;
        block2 = 4;
  }
 else if ( M == 64 )
    {
     block1 = 9;
        block2 = 4;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_9_5[] = "Transpose 9x5 submission";
void transpose_submit_9_5(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 9;
        block2 = 5;
  }
 else if ( M == 64 )
    {
     block1 = 9;
        block2 = 5;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_9_6[] = "Transpose 9x6 submission";
void transpose_submit_9_6(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 9;
        block2 = 6;
  }
 else if ( M == 64 )
    {
     block1 = 9;
        block2 = 6;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_9_7[] = "Transpose 9x7 submission";
void transpose_submit_9_7(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 9;
        block2 = 7;
  }
 else if ( M == 64 )
    {
     block1 = 9;
        block2 = 7;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_9_8[] = "Transpose 9x8 submission";
void transpose_submit_9_8(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 9;
        block2 = 8;
  }
 else if ( M == 64 )
    {
     block1 = 9;
        block2 = 8;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}
char transpose_submit_desc_9_9[] = "Transpose 9x9 submission";
void transpose_submit_9_9(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 9;
        block2 = 9;
  }
 else if ( M == 64 )
    {
     block1 = 9;
        block2 = 9;
    }
 else
    {
        block1 = 1;
        block2 = 1;
    }
 for ( i = 0; i < N; i += block1 )
    {
        for ( j = 0; j < M; j += block2 )
        {
            for ( k = i; k < i + block1; ++k )
            {
                for ( l = j; l < j + block2; ++l )
                {
                    tmp = A[ k ][ l ];
                    B[ l ][ k ] = tmp;
                }
            }
        }
    }
}


/*
 * registerFunctions - This function registers your transpose
 *     functions with the driver.  At runtime, the driver will
 *     evaluate each of the registered functions and summarize their
 *     performance. This is a handy way to experiment with different
 *     transpose strategies.
 */
void registerFunctions()
{
    /* Register your solution function */
    registerTransFunction(transpose_submit, transpose_submit_desc);

    /* Register any additional transpose functions */
    registerTransFunction(trans, trans_desc);


    registerTransFunction(transpose_submit_1_1, transpose_submit_desc_1_1);
    registerTransFunction(transpose_submit_1_2, transpose_submit_desc_1_2);
    registerTransFunction(transpose_submit_1_3, transpose_submit_desc_1_3);
    registerTransFunction(transpose_submit_1_4, transpose_submit_desc_1_4);
    registerTransFunction(transpose_submit_1_5, transpose_submit_desc_1_5);
    registerTransFunction(transpose_submit_1_6, transpose_submit_desc_1_6);
    registerTransFunction(transpose_submit_1_7, transpose_submit_desc_1_7);
    registerTransFunction(transpose_submit_1_8, transpose_submit_desc_1_8);
    registerTransFunction(transpose_submit_1_9, transpose_submit_desc_1_9);
    registerTransFunction(transpose_submit_2_1, transpose_submit_desc_2_1);
    registerTransFunction(transpose_submit_2_2, transpose_submit_desc_2_2);
    registerTransFunction(transpose_submit_2_3, transpose_submit_desc_2_3);
    registerTransFunction(transpose_submit_2_4, transpose_submit_desc_2_4);
    registerTransFunction(transpose_submit_2_5, transpose_submit_desc_2_5);
    registerTransFunction(transpose_submit_2_6, transpose_submit_desc_2_6);
    registerTransFunction(transpose_submit_2_7, transpose_submit_desc_2_7);
    registerTransFunction(transpose_submit_2_8, transpose_submit_desc_2_8);
    registerTransFunction(transpose_submit_2_9, transpose_submit_desc_2_9);
    registerTransFunction(transpose_submit_3_1, transpose_submit_desc_3_1);
    registerTransFunction(transpose_submit_3_2, transpose_submit_desc_3_2);
    registerTransFunction(transpose_submit_3_3, transpose_submit_desc_3_3);
    registerTransFunction(transpose_submit_3_4, transpose_submit_desc_3_4);
    registerTransFunction(transpose_submit_3_5, transpose_submit_desc_3_5);
    registerTransFunction(transpose_submit_3_6, transpose_submit_desc_3_6);
    registerTransFunction(transpose_submit_3_7, transpose_submit_desc_3_7);
    registerTransFunction(transpose_submit_3_8, transpose_submit_desc_3_8);
    registerTransFunction(transpose_submit_3_9, transpose_submit_desc_3_9);
    registerTransFunction(transpose_submit_4_1, transpose_submit_desc_4_1);
    registerTransFunction(transpose_submit_4_2, transpose_submit_desc_4_2);
    registerTransFunction(transpose_submit_4_3, transpose_submit_desc_4_3);
    registerTransFunction(transpose_submit_4_4, transpose_submit_desc_4_4);
    registerTransFunction(transpose_submit_4_5, transpose_submit_desc_4_5);
    registerTransFunction(transpose_submit_4_6, transpose_submit_desc_4_6);
    registerTransFunction(transpose_submit_4_7, transpose_submit_desc_4_7);
    registerTransFunction(transpose_submit_4_8, transpose_submit_desc_4_8);
    registerTransFunction(transpose_submit_4_9, transpose_submit_desc_4_9);
    registerTransFunction(transpose_submit_5_1, transpose_submit_desc_5_1);
    registerTransFunction(transpose_submit_5_2, transpose_submit_desc_5_2);
    registerTransFunction(transpose_submit_5_3, transpose_submit_desc_5_3);
    registerTransFunction(transpose_submit_5_4, transpose_submit_desc_5_4);
    registerTransFunction(transpose_submit_5_5, transpose_submit_desc_5_5);
    registerTransFunction(transpose_submit_5_6, transpose_submit_desc_5_6);
    registerTransFunction(transpose_submit_5_7, transpose_submit_desc_5_7);
    registerTransFunction(transpose_submit_5_8, transpose_submit_desc_5_8);
    registerTransFunction(transpose_submit_5_9, transpose_submit_desc_5_9);
    registerTransFunction(transpose_submit_6_1, transpose_submit_desc_6_1);
    registerTransFunction(transpose_submit_6_2, transpose_submit_desc_6_2);
    registerTransFunction(transpose_submit_6_3, transpose_submit_desc_6_3);
    registerTransFunction(transpose_submit_6_4, transpose_submit_desc_6_4);
    registerTransFunction(transpose_submit_6_5, transpose_submit_desc_6_5);
    registerTransFunction(transpose_submit_6_6, transpose_submit_desc_6_6);
    registerTransFunction(transpose_submit_6_7, transpose_submit_desc_6_7);
    registerTransFunction(transpose_submit_6_8, transpose_submit_desc_6_8);
    registerTransFunction(transpose_submit_6_9, transpose_submit_desc_6_9);
    registerTransFunction(transpose_submit_7_1, transpose_submit_desc_7_1);
    registerTransFunction(transpose_submit_7_2, transpose_submit_desc_7_2);
    registerTransFunction(transpose_submit_7_3, transpose_submit_desc_7_3);
    registerTransFunction(transpose_submit_7_4, transpose_submit_desc_7_4);
    registerTransFunction(transpose_submit_7_5, transpose_submit_desc_7_5);
    registerTransFunction(transpose_submit_7_6, transpose_submit_desc_7_6);
    registerTransFunction(transpose_submit_7_7, transpose_submit_desc_7_7);
    registerTransFunction(transpose_submit_7_8, transpose_submit_desc_7_8);
    registerTransFunction(transpose_submit_7_9, transpose_submit_desc_7_9);
    registerTransFunction(transpose_submit_8_1, transpose_submit_desc_8_1);
    registerTransFunction(transpose_submit_8_2, transpose_submit_desc_8_2);
    registerTransFunction(transpose_submit_8_3, transpose_submit_desc_8_3);
    registerTransFunction(transpose_submit_8_4, transpose_submit_desc_8_4);
    registerTransFunction(transpose_submit_8_5, transpose_submit_desc_8_5);
    registerTransFunction(transpose_submit_8_6, transpose_submit_desc_8_6);
    registerTransFunction(transpose_submit_8_7, transpose_submit_desc_8_7);
    registerTransFunction(transpose_submit_8_8, transpose_submit_desc_8_8);
    registerTransFunction(transpose_submit_8_9, transpose_submit_desc_8_9);
    registerTransFunction(transpose_submit_9_1, transpose_submit_desc_9_1);
    registerTransFunction(transpose_submit_9_2, transpose_submit_desc_9_2);
    registerTransFunction(transpose_submit_9_3, transpose_submit_desc_9_3);
    registerTransFunction(transpose_submit_9_4, transpose_submit_desc_9_4);
    registerTransFunction(transpose_submit_9_5, transpose_submit_desc_9_5);
    registerTransFunction(transpose_submit_9_6, transpose_submit_desc_9_6);
    registerTransFunction(transpose_submit_9_7, transpose_submit_desc_9_7);
    registerTransFunction(transpose_submit_9_8, transpose_submit_desc_9_8);
    registerTransFunction(transpose_submit_9_9, transpose_submit_desc_9_9);



}

/*
 * is_transpose - This helper function checks if B is the transpose of
 *     A. You can check the correctness of your transpose by calling
 *     it before returning from the transpose function.
 */
int is_transpose(int M, int N, int A[N][M], int B[M][N])
{
    int i, j;

    for (i = 0; i < N; i++) {
        for (j = 0; j < M; ++j) {
            if (A[i][j] != B[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}

