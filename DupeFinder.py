import hashlib
import sys
import argparse
import os


def initArgParse():
    parser = argparse.ArgumentParser(description='An application for finding duplicate files using the md5 hashing algorithm')

    parser.add_argument('-bf','--buffersize', default=64000, type=int,
                    help='An integer for determining chunk size of a file being read into memory at a given time (default is 64000 (64Kb) )')

    parser.add_argument('-d','--directory', default=".", type=str,
                help='The file path given to look for duplicate files in')
    
    parser.add_argument('-p','--pairs', default=True, action='store_false',
                    help='A boolean value to determine if like named files will be checked against each other. For example test.txt will only be checked against text.txt (1) and other similar files. This is True by default, setting this to true could impact search performance')

    return parser.parse_args()


def fileGuardRail(path):

    WARNING_STRING = "WARNING! Either no directory was chosen or you chose '.' which means the current directory you are in. Continuing to proceed could lead to undefined behaviour. Do you wish to proceed? y/n "
    currentBoolean = True # Assume everything is okay from the get go

    if path == ".":
        choice = input(WARNING_STRING).lower()
        
        if len(choice) == 0:
            print("No answer was given to the prior warning, exiting program for safety")
            exit()
        else:
            currentBoolean = True if choice[0] == 'y' else False

    currentBoolean = os.path.isdir(path)

    return currentBoolean


def generateHash(fileName,BUFFER_SIZE):
    md5 = hashlib.md5() # could not find a flush method so a new object has to be created per file hashing procedure, hopefully its not slow
    # with thanks to https://stackoverflow.com/questions/22058048/hashing-a-file-in-python
    with open(fileName, 'rb') as f:
        while True:
            data = f.read(BUFFER_SIZE)
            if not data:
                break
            md5.update(data)
    return md5.hexdigest()


if __name__ == "__main__":
    args = initArgParse()
    fileGuardRail(args.directory)
    BUFFER_SIZE = args.buffersize
    