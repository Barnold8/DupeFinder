from setup import *
from file import *

if __name__ == "__main__":
    args = initArgParse()
    # fileGuardRail(args.directory)
    # BUFFER_SIZE = args.buffersize


    # files = generateFileObjs(grabFiles(args.directory))
    # print(groupFiles(files))

    print(grabFiles(args.directory))