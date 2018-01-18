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
k = int(cmdlinearg('k'))
ak = int(cmdlinearg('ak'))
bk = int(cmdlinearg('bk'))
av = int(cmdlinearg('av'))
bv = int(cmdlinearg('bv'))
lastsmall = int(cmdlinearg('lastsmall', '0'))

print(n, k)
li = list(range(n))
random.shuffle(li)

ar = [None] * n
br = [None] * n
for i in range(n):
    ar[i] = li[i] * ak + random.randint(0, av)
    br[i] = li[i] * bk + random.randint(0, bv)
    if lastsmall and li[i] < n-1:
        br[i] += 10

print(*ar)
print(*br)
