import os

cwd = os.getcwd() # get current directory

for i in range(1,65):
    for j in range(1,65):
        build_dir = "test_" + str(i) + "_" + str(j)
        try:
        		os.chdir(build_dir)
        		os.system("./test-trans -M 32 -N 32 | grep TEST_TRANS_RESULTS")
        		os.system("./test-trans -M 64 -N 64 | grep TEST_TRANS_RESULTS")
        		os.system("./test-trans -M 61 -N 67 | grep TEST_TRANS_RESULTS")
        finally:
        		os.chdir(cwd)
