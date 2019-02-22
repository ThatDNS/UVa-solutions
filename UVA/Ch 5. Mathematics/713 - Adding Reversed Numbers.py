# Problem: 713 - Adding Reversed Numbers

'''
Author: DNS404
'''


def reverse(s):
    s = "".join(reversed(s))
    return s


t = int(input())

for i in range(0, t):
    num1, num2 = input().split()
    num1 = reverse(num1)
    num2 = reverse(num2)
    result = int(num1) + int(num2)
    result = reverse(str(result))
    print(int(result))

