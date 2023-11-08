numTestCases: int = int(input())

for t in range(0, numTestCases):
    
    a,b = tuple(map(int,input().split()))
    res: int = a - b
    if not res:
        print('=')
    if res < 0:
        print('<')
    if res > 0:
        print('>')