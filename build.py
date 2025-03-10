# too lazy to use cmake or any other build tool, dont need any fancy stuff
import os

source = [file for file in os.listdir("src") if ".c" in file]
source[0] = "src/" + source[0] # stupid join function grumble grumble grumble

build = "gcc " + " src/".join(source) + " -o build/main.exe"

os.system(build)