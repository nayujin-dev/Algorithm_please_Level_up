import sys
from sys import stdin

stack = []
a = list(sys.stdin.readline().rstrip())
while(a.index(".")!=0):
    for x in a:
        if (x == "[" or x == "("):
            stack.append(x)
        elif (x == "]"):
            if (not stack or stack.pop() != "["):
                print("no")
                break
        elif (x == ")"):
            if (not stack or stack.pop() != "("):
                print("no")
                break
        elif (x == "."):
            if(not stack):
                print("yes")
            else:
                print("no")
            break
    a = list(sys.stdin.readline().rstrip())
    stack.clear()