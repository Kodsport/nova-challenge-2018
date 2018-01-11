import random
import string

LOWER_ALPHA = string.ascii_lowercase
UPPER_ALPHA = string.ascii_uppercase

def inclusive(lo, hi):
    return range(lo, hi + 1)

def random_word(alphabet, length_range):
    if isinstance(length_range, int):
        length = length_range
    else:
        length = random.choice(length_range)
    return ''.join(random.choice(alphabet) for _ in range(length))

def rep(count, func, *args):
    return [func(*args) for _ in range(count)]

def flatten(array):
    ret = []
    for val in array:
        ret.extend(val)
    return ret

def choice(array):
    return random.choice(array)
