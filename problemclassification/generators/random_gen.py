import libinput as I

MAX_LENGTH = 30
MAX_WORDS = 10000

def word():
    return I.random_word(I.LOWER_ALPHA, MAX_LENGTH)

cats = I.rep(10, I.rep, 10, word)

print(10)
for c in cats:
    print(word(), 10, *c)

allwords = I.flatten(cats)

for i in range(MAX_WORDS):
    print(I.choice(allwords))
