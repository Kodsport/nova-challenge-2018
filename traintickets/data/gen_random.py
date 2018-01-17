#!/usr/bin/python3

import sys
import random

def cmdlinearg(name, default=None):
    for arg in sys.argv:
        if arg.startswith(name + "="):
            return arg.split("=")[1]
    assert default is not None
    return default

random.seed(int(cmdlinearg('seed', sys.argv[-1])))
n = int(cmdlinearg('n'))
q = int(cmdlinearg('q'))
pricing = cmdlinearg('pricing')
highmid = int(cmdlinearg('highmid', '0'))
maxcases = int(cmdlinearg('maxcases', '0'))

print(n)
for i in range(n):
    prices = [0] * 12
    if pricing == 'linearish':
        for i in range(12):
            prices[i] = (i+1) * 200 + random.randint(-100, 100)
    elif pricing == 'random':
        for i in range(12):
            prices[i] = random.randint(0, 10000)
            if i > 0:
                prices[i] = max(prices[i], prices[i-1])
    else:
        assert False
    if highmid and n//4 < i < n - n//4:
        prices = [9000 + random.randint(-10, 10) for _ in range(12)]
    print(*prices)

print(q)
for i in range(q):
    if maxcases:
        assert 2*q <= n
        a = i+1
        b = n - i
    else:
        a = random.randint(1, n)
        b = random.randint(1, n)
    if a > b:
        a,b = b,a
    print(a, b)
