#include <stdio.h>
#include "cachelab.h"
int is_transpose(int M, int N, int A[N][M], int B[M][N]);
void transpose_submit_29_1(int M, int N, int A[N][M], int B[M][N]);





char transpose_submit_desc[] = "Transpose submission";
void transpose_submit(int M, int N, int A[N][M], int B[M][N])
{
 int i, j, k, l;
 int tmp;
    int block1;
    int block2;
 if ( M == 32 )
{
     block1 = 29;
        block2 = 1;
  }
 else if ( M == 64 )
    {
     block1 = 29;
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





void registerFunctions()
{
    registerTransFunction(transpose_submit, transpose_submit_desc);
}
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
