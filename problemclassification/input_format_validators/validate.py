#!/usr/bin/python
from sys import stdin
import re, sys

integer = "[1-9]\d*"
line = stdin.readline()
assert re.match(integer + "\n", line)
N = int(line)
assert 1 <= N <= 10

cats = []
for i in range(N):
    line = stdin.readline()
    assert re.match("[a-z]{1,30} " + integer + "( [a-z]{1,30})+\n", line)
    w = line.split()
    assert int(w[1]) == len(w) - 2
    assert w[0] not in cats
    cats.append(w[0])

wc = 0
while True:
    line = stdin.readline()
    if len(line) == 0:
        break
    assert re.match("[a-z]{1,30}( [a-z]{1,30})*", line)
    wc += len(line.split())

assert 1 <= wc <= 10000
sys.exit(42)
