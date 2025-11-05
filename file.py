from os import listdir
from os.path import isfile, isdir, join, getsize,abspath

class File:
   
   def __init__(self,path,size,type):
      self.path = path
      self.size = size
      self.type = type

def grabFiles(path):
   return [abspath(join(path, f)) for f in listdir(path) if isfile(join(path, f))]

def grabFilesRecursive(path):

   files = []
   print(path)
   for f in listdir(path):
      if isfile(join(path, f)):
         files.append(f)
      elif isdir(join(path, f)):
         files.extend(grabFilesRecursive(join(path, f)))

   return files



def hasExtension(file):
   parts = file.split(".")
   if len(parts) > 1:
      return len(parts[len(parts)-1]) > 0
   return False

def groupFiles(files):
   groups = {}
   for file in files:
      key = file.type 
      groups.setdefault(key, []).append(file)
   return groups

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

