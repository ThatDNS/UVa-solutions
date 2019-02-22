# Problem: 10523 - Very Easy !!!

'''
Author: DNS404
'''

import sys
# import math


inputs = []
while True:
    try:
        line = input()
    except EOFError:
        break
    if line == "":
        break
    no1, no2 = line.split()
    line = [int(no1), int(no2)]
    inputs.append(line)

for i in range(0, len(inputs)):
    s = 0
    for j in range(1, inputs[i][0]+1):
        s += j * pow(inputs[i][1], j)
    print(s)

