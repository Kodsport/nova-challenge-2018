#!/bin/sh

python3 gen_random.py n=1 k=100 ak=1000 bk=1000 av=1000 bv=1000 0 > secret/0.in
python3 gen_random.py n=100000 k=300 ak=1000 bk=1000 av=3000 bv=3000 1 > secret/1.in
python3 gen_random.py n=100000 k=10000 ak=1000 bk=1000 av=50000 bv=50000 12 > secret/1b.in
python3 gen_random.py n=100000 k=2000 ak=1000 bk=1000 av=5000 bv=5000 13 > secret/1c.in
python3 gen_random.py n=100000 k=1000000 ak=1000 bk=1000 av=10000 bv=10000 2 > secret/2.in
python3 gen_random.py n=100000 k=1000000000 ak=1000 bk=1000 av=10000 bv=10000 3 > secret/3.in
python3 gen_random.py n=100000 k=1000 ak=2000 bk=0 av=1000 bv=900 4 > secret/4.in
python3 gen_random.py n=100000 k=1000 ak=0 bk=0 av=1000000 bv=1000000 5 > secret/5.in
python3 gen_random.py n=100000 k=400000 ak=0 bk=0 av=1000000 bv=1000000 6 > secret/6.in
python3 gen_random.py n=100000 k=1 ak=3 bk=0 av=1 bv=1 lastsmall=1 7 > secret/7.in
