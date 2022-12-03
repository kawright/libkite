"""Run tests."""

import os
import subprocess
import sys

def main():

    ret = 0

    for filename in os.listdir("build/bin/test"):
        if subprocess.call(["build/bin/test/{}".format(filename)]): ret = 1

    return ret

if __name__ == "__main__":
    sys.exit(main())