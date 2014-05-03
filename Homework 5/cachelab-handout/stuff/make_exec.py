import os

cwd = os.getcwd() # get current directory

for i in range(1,65):
    for j in range(1,65):
        build_dir = "test_" + str(i) + "_" + str(j)
        try:
        		os.chdir(build_dir)
        		os.system("chmod +x csim-ref")
        finally:
        		os.chdir(cwd)