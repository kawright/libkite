"""Build libkite."""


import os
import subprocess
import sys
import tarfile

VERSION_NUMBER = "v0.3.0"

SOURCE_OBJECTS = {
    "kite_Char.o": "src/text/source/kite_Char.c",
    "kite_ErrorState.o": "src/error/source/kite_ErrorState.c",
    "kite_Quiz.o": "src/quiz/source/kite_Quiz.c",
    "kite_String.o": "src/text/source/kite_String.c",  
}

INCLUDE_FILES = {
    "libkite.h": "src/libkite.h",

    "kite_text.h": "src/text/kite_text.h",
    "kite_error.h": "src/error/kite_error.h",
    "kite_quiz.h": "src/quiz/kite_quiz.h",

    "kite_Char.h": "src/text/include/kite_Char.h",
    "kite_ErrorCode.h": "src/error/include/kite_ErrorCode.h",
    "kite_ErrorState.h": "src/error/include/kite_ErrorState.h",
    "kite_Quiz.h": "src/quiz/include/kite_Quiz.h",
    "kite_String.h": "src/text/include/kite_String.h"
}

INCLUDE_PATHS = [
    "src",

    "src/text",
    "src/error",
    "src/quiz",

    "src/text/include",
    "src/error/include",
    "src/quiz/include"
]

TESTS = {
    "test_Char": "test/test_Char.c",
    "test_ErrorState": "test/test_ErrorState.c",
    "test_Quiz": "test/test_Quiz.c",
    "test_String": "test/test_String.c"
}

def main():


    print("Cleaning up old build artifacts...", end="")
    subprocess.call(["rm", "-Rf", "./build"], stdout=subprocess.DEVNULL)
    print("DONE!")
    
    print("Setting up build directory structure...", end="")
    subprocess.call(["mkdir", "build"], stdout=subprocess.DEVNULL)
    subprocess.call(["mkdir", "build/object"], stdout=subprocess.DEVNULL)
    subprocess.call(["mkdir", "build/object/static"], stdout=subprocess.DEVNULL)
    subprocess.call(["mkdir", "build/object/shared"], stdout=subprocess.DEVNULL)
    subprocess.call(["mkdir", "build/object/test"], stdout=subprocess.DEVNULL)
    subprocess.call(["mkdir", "build/bin"], stdout=subprocess.DEVNULL)
    subprocess.call(["mkdir", "build/bin/static"], stdout=subprocess.DEVNULL)
    subprocess.call(["mkdir", "build/bin/static/include"], 
        stdout=subprocess.DEVNULL)
    subprocess.call(["mkdir", "build/bin/shared"], stdout=subprocess.DEVNULL)
    subprocess.call(["mkdir", "build/bin/shared/include"], 
        stdout=subprocess.DEVNULL)
    subprocess.call(["mkdir", "build/bin/test"], stdout=subprocess.DEVNULL)

    print("DONE!")
    
    print("Building static object files...", end="")
    static_object_files = []
    for outfile, infile in SOURCE_OBJECTS.items():
        static_object_files.append("build/object/static/{}".format(outfile))
        args = [
            "gcc", 
            "-c", 
            infile,
            "-o", 
            "build/object/static/{}".format(outfile)]
        for include_path in INCLUDE_PATHS:
            args.append("-I")
            args.append(include_path)
        subprocess.call(args)
    print("DONE!")

    print("Building shared object files...", end="")
    shared_object_files = []
    for outfile, infile in SOURCE_OBJECTS.items():
        shared_object_files.append("build/object/shared/{}".format(outfile))
        args = [
            "gcc", 
            "-c", 
            infile,
            "-o",
            "build/object/shared/{}".format(outfile),
            "-fPIC"]
            
        for include_path in INCLUDE_PATHS:
            args.append("-I")
            args.append(include_path)
        subprocess.call(args)
    print("DONE!")
    
    print("Building static library binary...", end="")
    arg_list = ["ar", "rcs", "build/bin/static/libkite.a"]
    arg_list.extend(static_object_files)
    subprocess.call(arg_list)
    print("DONE!")

    print("Building shared library binary...", end="")
    arg_list = ["gcc", "-shared", "-o", "build/bin/shared/libkite.so"]
    arg_list.extend(shared_object_files)
    subprocess.call(arg_list)
    print("DONE!")

    print("Building test binaries...", end="")
    for outfile, infile in TESTS.items():
        arg_list = [
            "gcc", 
            "-c", 
            infile, 
            "-o", 
            "build/object/test/{}.o".format(outfile)]
        for include_path in INCLUDE_PATHS:
            arg_list.append("-I")
            arg_list.append(include_path)
        subprocess.call(arg_list)
        arg_list = [
            "gcc",
            "-o",
            "build/bin/test/{}".format(outfile),
            "build/object/test/{}.o".format(outfile),
            "-I",
            "src"]
        arg_list.extend(static_object_files)
        subprocess.call(arg_list)
        arg_list = ["sudo", "chmod", "+x", "build/bin/test/{}".format(outfile)]
    print("DONE!")
    
    print("Archiving static binaries...", end="")
    for outfile, infile in INCLUDE_FILES.items():
        arg_list = ["cp", infile, "build/bin/static/include/{}".format(outfile)]
        subprocess.call(arg_list)
    with tarfile.open("build/libkite-static-{}.tar.gz".format(VERSION_NUMBER), 
            "w:gz") as tar:
        tar.add("build/bin/static", 
            arcname=os.path.basename("build/bin/static"))
    print("DONE!")

    print("Archiving shared binaries...", end="")
    for outfile, infile in INCLUDE_FILES.items():
        arg_list = ["cp", infile, "build/bin/shared/include/{}".format(outfile)]
        subprocess.call(arg_list)
    with tarfile.open("build/libkite-shared-{}.tar.gz".format(VERSION_NUMBER), 
            "w:gz") as tar:
        tar.add("build/bin/shared", 
            arcname=os.path.basename("build/bin/shared"))
    print("DONE!")
    
    return 0

if __name__ == "__main__":
    sys.exit(main())