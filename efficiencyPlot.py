import matplotlib.pyplot as plt
import numpy as np

# Input sizes
n = [10000, 100000, 1000000, 10000000]

# Time taken
t = [0.005, 0.031, 0.219, 1.886]

# Create a scatter plot
plt.scatter(n, t)

# Fit a line of best fit
coefficients = np.polyfit(n, t, 1)
m = coefficients[0]
b = coefficients[1]

# Plot the line of best fit
plt.plot(n, m*np.array(n) + b, '-')

# Add labels and title
plt.xlabel('Input size')
plt.ylabel('Time taken (s)')
plt.title('Runtime vs. input size')

# Show the plot
plt.show()