from os import system
from glob import glob
tests = glob("/home/pedro/Documents/t2-ed/testes-t2/*.geo")
for item in tests:
    system(f'./src/progr -f {item} -o /home/pedro/Documents/t2-ed/output/')
