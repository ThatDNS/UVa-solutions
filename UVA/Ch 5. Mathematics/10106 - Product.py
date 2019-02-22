# Problem: 10106 - Product
'''
Author: DNS404
'''

inputs = []
while True:
  try:
    line = input()
  except EOFError:
    break
  if line == "":
    break
  inputs.append(int(line))

for i in range(0, len(inputs), 2):
  print(inputs[i]*inputs[i+1])
