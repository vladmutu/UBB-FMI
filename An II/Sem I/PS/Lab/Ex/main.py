from matplotlib.pyplot import hist, title, xlabel, ylabel, show
import numpy as np

data = np.random.randn(1000)  # Generate random data
hist(data, bins=30, color='blue', alpha=0.7, edgecolor='black')
title("Histogram")
xlabel("Value")
ylabel("Frequency")
show()
