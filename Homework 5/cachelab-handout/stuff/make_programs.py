#!/opt/local/bin/python

for i in range(1,65):
    for j in range(1,65):
        filename = "runner_" + str(i) + "_" + str(j) + "/trans.c"
        f = open(filename,"w")
        f.write("#include <stdio.h>\n#include \"cachelab.h\"\n")
        f.write("int is_transpose(int M, int N, int A[N][M], int B[M][N]);\n")
        f.write("void transpose_submit_{0}_{1}(int M, int N, int A[N][M], int B[M][N]);\n".format(i, j))

        f.write("\n\n\n\n\n")

        f.write("char transpose_submit_desc[] = \"Transpose submission\";\n")
        f.write("void transpose_submit(int M, int N, int A[N][M], int B[M][N])\n")
        f.write("{\n")
        f.write(" int i, j, k, l;\n int tmp;\n    int block1;\n    int block2;\n")
        f.write(" if ( M == 32 )\n{\n")
        f.write("     block1 = {0};\n        block2 = {1};\n".format(i, j))
        f.write("  }\n")
        f.write(" else if ( M == 64 )\n    {\n")
        f.write("     block1 = {0};\n        block2 = {1};\n".format(i, j))
        f.write("    }\n")
        f.write(" else\n    {\n        block1 = 1;\n        block2 = 1;\n    }\n")
        f.write(" for ( i = 0; i < N; i += block1 )\n    {\n        for ( j = 0; j < M; j += block2 )\n        {\n            for ( k = i; k < i + block1; ++k )\n            {\n                for ( l = j; l < j + block2; ++l )\n                {\n")
        f.write("                    tmp = A[ k ][ l ];\n                    B[ l ][ k ] = tmp;\n")
        f.write("                }\n            }\n        }\n    }\n")
        f.write("}\n")

        f.write("\n\n\n\n\n")

        f.write("void registerFunctions()\n")
        f.write("{\n")
        f.write("    registerTransFunction(transpose_submit, transpose_submit_desc);\n".format(i, j))
        f.write("}\n")

        f.write("int is_transpose(int M, int N, int A[N][M], int B[M][N])\n")
        f.write("{\n")
        f.write("    int i, j;\n")
        f.write("    for (i = 0; i < N; i++) {\n")
        f.write("        for (j = 0; j < M; ++j) {\n")
        f.write("            if (A[i][j] != B[j][i]) {\n")
        f.write("                return 0;\n")
        f.write("            }\n")
        f.write("        }\n")
        f.write("    }\n")
        f.write("    return 1;\n")
        f.write("}\n")
        f.close()

