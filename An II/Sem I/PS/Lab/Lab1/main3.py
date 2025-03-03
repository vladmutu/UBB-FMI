from itertools import combinations_with_replacement
from random import sample
from math import factorial

def prob_4():
    for i in combinations_with_replacement("ABCDE", 4):
        print(''.join(i))

prob_4()
