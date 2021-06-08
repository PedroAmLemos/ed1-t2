from os import system
from glob import glob
tests = glob("/home/pedro/Documents/t2-ed/t2/*.geo")
for item in tests:
    system(f'valgrind ./src/progr -f {item} -o /home/pedro/Documents/t2-ed/output/')
