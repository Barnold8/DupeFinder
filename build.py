# too lazy to use cmake or any other build tool, dont need any fancy stuff
import os
import platform
import sys


binary_name = "main"

binary = f" -o build/{binary_name}.exe" if platform.system().lower() == "windows" else f" -o build/{binary_name}"

source = [file for file in os.listdir("src") if ".c" in file]
source[0] = "src/" + source[0] # stupid join function grumble grumble grumble

if len(sys.argv) > 1:
    build = f"gcc {sys.argv[1] } " + " src/".join(source) + binary
else:
    build = "gcc " + " src/".join(source) + binary

os.system(build)