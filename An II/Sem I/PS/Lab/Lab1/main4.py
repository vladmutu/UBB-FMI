import math
from itertools import permutations
from math import factorial

def prob5():

    total_asezari = math.comb(12,5) * factorial(5)

    bloc_persoane = 1
    scaune_libere = 12-5

    total_blocuri = scaune_libere + bloc_persoane

    asezari_fara_libere = math.comb(total_blocuri, bloc_persoane) * factorial(5)

    print(total_asezari - total_blocuri)

prob5()
