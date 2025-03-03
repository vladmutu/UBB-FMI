from random import choices, sample
from math import comb, perm

def prob_cond(nr_sim):
    countA, countAB = 0, 0
    for _ in range(nr_sim):
        bile_extrase = sample(['red', 'blue', 'green'], counts=[5,3,2], k=3)
        if 'red' in bile_extrase:
            countA += 1
            if len(set(bile_extrase)) == 1:
                countAB += 1
    return countAB/countA

print(prob_cond(5000))

prob_teoretica_AB = comb(5,3)/comb(10,3)
prob_teoretica_A = 1-comb(5,3)/comb(10,3)
prob_B_cond_A_teoretica = prob_teoretica_AB/prob_teoretica_A
print(prob_B_cond_A_teoretica)