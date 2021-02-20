# © 2021-02-20 06:45:53 Franco1010 All Rights Reserved
# import sys
# sys.stdin = open('file.in', 'r')
# sys.stdout = open('file.out', 'w')
# [n, m] = map(int, input().split(' '))
# mat = [[0 for i in range(m)] for j in range(n)] # n * m matrix
def f(x, b, m):
    pot = 1;
    res = 0;
    for i in range(len(x)):
        res += int(x[len(x) - i - 1]) * pot;
        if(res > m): return False;
        pot *= b;
    return True;
x = input();
m = int(input());
mn = 0;
for i in x: mn = max(mn, int(i));
mn = mn + 1;
if(not f(x, mn, m)): print(0);
elif(int(x) < 10): print(1);
else:
    pos = int(mn)
    while(f(x, pos, m)): pos *= int(2)
    p = pos;
    while(p):
        while(pos - p >= mn and not f(x, pos - p, m)): pos -= p;
        p //= 2;
    pos -= 1;
    print(max(0, pos - mn + 1));
