from os import listdir
from os.path import isfile, join, getsize

class File:
   
   def __init__(self,path,size,type):
      self.path = path
      self.size = size
      self.type = type


def grabFiles(path):
   return [f for f in listdir(path) if isfile(join(path, f))]

def hasExtension(file):
   parts = file.split(".")
   if len(parts) > 1:
      return len(parts[len(parts)-1]) > 0
   return False
  

def generateFileObjs(files):
    fileObjs = []

    for file in files:
       fileObj = File(
          file,
          getsize(file),
          file.split(".")[1] if hasExtension(file) else None
        )
       fileObjs.append(fileObj)

    return fileObjs