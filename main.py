import hashlib
import sys


def generateHash(fileName,md5,BUFFER_SIZE):
    # with thanks to https://stackoverflow.com/questions/22058048/hashing-a-file-in-python
    with open(fileName, 'rb') as f:
        while True:
            data = f.read(2**10)
            if not data:
                break
            md5.update(data)
    return md5.hexdigest()


def parseArgs(args):

    args = args[1::]

    if len(args) % 2 == 0:
        print(args)
    else:
        print("ERR")
        exit()


if __name__ == "__main__":

    parseArgs(sys.argv)

    BUFFER_SIZE = 2**10
    md5 = hashlib.md5()


    generateHash("test.txt",md5,sha1)



