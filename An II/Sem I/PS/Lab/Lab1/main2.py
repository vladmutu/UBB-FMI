import random
from random import sample
from math import perm,comb,factorial
from itertools import permutations, combinations

def aranjamente(word, length, total_count=False, random_choice = False ):
    if total_count:
        print(factorial(len(word)))
    elif random_choice:
        print(sample(word,  length))
    else:
        for word in permutations(word, length):
            print(word)

aranjamente("word", 2)
print("\n\n")
aranjamente("word", 2, random_choice=True)
print("\n\n")
aranjamente("word", 2, total_count=True)

print("\n\n")


def combinari(word, k, total_count=False, random_choice = False):
    if random_choice:
        random_indexes = random.choice(list(combinations(word, k)))
        print(random_indexes)
    elif total_count:
        print(comb(len(word), k))
    else:
        for x in combinations(word,k):
            print(x)

combinari("word", 2)
print("\n\n")
combinari("word", 2, total_count=True)
print("\n\n")
combinari("word", 2, random_choice=True)