# Problem: 11879 - Multiple of 17

'''
Author: DNS404
'''

inputs = []
while True:
    try:
        line = input()
    except EOFError:
        break
    if line == "0":
        break
    inputs.append(line)

for strNum in inputs:
    start = strNum[:-1]
    if start == "":
        start = 0
    else:
        start = int(start)
    d = int(strNum) % 10
    if (start - 5*d)%17 == 0:
        print("1")
    else:
        print("0")

