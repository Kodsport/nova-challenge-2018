import random
w = sorted(set([random.choice(range(1, 100000)) for _ in range(10000)])) + [1000000]
print(1000000, len(w))
print(*w)
