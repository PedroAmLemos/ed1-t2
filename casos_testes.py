from os import system
from glob import glob
# tests = glob("/home/pedro/Documents/t2-ed/t2/*.geo")
qry = glob("/home/pedro/Documents/t2-ed/t2/aldeia-protegida-alguns-abrigados-grande/*.qry")
for item in qry:
    system(f'valgrind ./src/progr -f /home/pedro/Documents/t2-ed/t2/aldeia-protegida-alguns-abrigados-grande.geo -o /home/pedro/Documents/t2-ed/output/ -q {item}')
