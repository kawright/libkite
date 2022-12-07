"""Run tests."""

import datetime
import os
import subprocess
import sys

def main():


    runs = 0
    passes = 0
    fails = 0

    for filename in os.listdir("build/bin/test"):
        runs += 1
        if subprocess.call(["build/bin/test/{}".format(filename)]): 
            fails += 1
        else:
            passes += 1

    print("***************************************************************")
    print("***************************************************************")
    print("RUN DATE: {}".format(datetime.datetime.now()))
    print("SUITES RUN:    {}".format(runs))
    print("SUITES PASSED: {}".format(passes))
    print("SUITES FAILED: {}".format(fails))
    print("***************************************************************")
    print("***************************************************************")
    print("")
    print("END OF REPORT")

    return 0 if fails == 0 else 1

if __name__ == "__main__":
    sys.exit(main())