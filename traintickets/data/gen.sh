#!/bin/sh

python3 gen_random.py n=10 q=2000 pricing=random 1 > secret/small-random.in
python3 gen_random.py n=20000 q=2000 pricing=linearish maxcases=1 2 > secret/large.in
python3 gen_random.py n=20000 q=2000 pricing=linearish 3 > secret/1.in
python3 gen_random.py n=20000 q=2000 pricing=random 4 > secret/2.in
python3 gen_random.py n=20000 q=2000 pricing=linearish highmid=1 5 > secret/3.in
python3 gen_random.py n=20000 q=2000 pricing=random highmid=1 6 > secret/4.in
python3 gen_random.py n=100 q=2000 pricing=linearish 7 > secret/5.in
python3 gen_random.py n=100 q=2000 pricing=random 8 > secret/6.in
python3 gen_random.py n=100 q=2000 pricing=linearish highmid=1 9 > secret/7.in
python3 gen_random.py n=100 q=2000 pricing=random highmid=1 10 > secret/8.in
