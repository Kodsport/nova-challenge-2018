import libinput as I

MAX_LENGTH = 30
MAX_WORDS = 10000

def word():
    return I.random_word(I.LOWER_ALPHA, MAX_LENGTH)

all_words = I.rep(10, word)

print(10)
for i in range(10):
    print(word(), 10, *all_words)
for i in range(MAX_WORDS // len(all_words)):
    print(*all_words)
