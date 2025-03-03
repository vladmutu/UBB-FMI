import random
from random import sample
from math import factorial, perm, comb
from itertools import permutations, combinations

sequence = [1,2,3,4]

list_permutations = permutations(sequence)
#list_permutations = permutations('word') -- by default se ia direct lungimea secventei de permutat

number_of_permutations = factorial(len(sequence))

for word in list_permutations:
    print(word)

print(number_of_permutations)

print(random.sample(sequence, 4))