from setup import *

if __name__ == "__main__":
    args = initArgParse()
    fileGuardRail(args.directory)
    BUFFER_SIZE = args.buffersize
    print(generateHash("./test/test.txt",BUFFER_SIZE))
    