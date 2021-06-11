from os import system
from glob import glob
# tests = glob("/home/pedro/Documents/t2-ed/t2/*.geo")
qry = glob("/home/pedro/Documents/t2-ed/t2/aldeia-alguns-abrigados-grande/*.qry")
for item in qry:
    print(f'./src/progr -f /home/pedro/Documents/t2-ed/t2/aldeia-alguns-abrigados-grande.geo -o /home/pedro/Documents/t2-ed/output/ -q {item}')
    system(f'./src/progr -f /home/pedro/Documents/t2-ed/t2/aldeia-alguns-abrigados-grande.geo -o /home/pedro/Documents/t2-ed/output/ -q {item}')
