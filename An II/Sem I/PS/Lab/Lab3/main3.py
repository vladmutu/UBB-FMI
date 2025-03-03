from random import choices, sample, randrange
from math import comb, perm

from matplotlib.pyplot import hist, bar, legend, grid, show
from scipy.stats import binom

nr_sim = 1000
n,p=5,0.6
x = binom.rvs(n,p,size=nr_sim)
print(x)

data = x
bin_edges = [k+0.5 for k in range(-1,6)]
hist(data, bin_edges, density=True, rwidth=0.9, color='green', edgecolor='black', alpha=0.5, label='frecvente relative')

distribution = dict([(i,binom.pmf(i, n, p)) for i in range(6)])
bar(distribution.keys(), distribution.values(),width=0.85, color='red', edgecolor='black', alpha=0.6, label='probabilitati')

legend(loc='upper left')
grid()
show()