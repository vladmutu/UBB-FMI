from scipy.stats import bernoulli,binom
from matplotlib.pyplot import bar,show,hist,grid,legend,xticks

def mers_aleator_axa(nr_pasi,p):
    pozitii = [0]
    for _ in range(nr_pasi):
        x=bernoulli.rvs(p)
        pas = 2*x-1
        pozitii.append(pozitii[-1]+pas)
    return pozitii

print(mers_aleator_axa(10,0.5))

def sim_mersa_aleator_cerc(nr_pasi,nr_pcte,p,nr_sim=1000):
    pozitii_finale = [mers_aleator_axa(nr_pasi,p)[-1] % nr_pcte for _ in range(nr_sim)]
    bin_edges = [i+0.5 for i in range(-1,nr_pcte)]
    hist(pozitii_finale, bin_edges, density=True, rwidth=0.9, align='mid',
         edgecolors='black')

    distributie = nr_pcte*[0]
    for k in range(nr_pasi):
        distributie[(k-(nr_pasi-k))%nr_pcte]+=binom.pmf(k,nr_pasi,p)
    grid()
    show()