import matplotlib.pyplot as plt
import numpy as np

# Primer caso

data1 = np.loadtxt("4-1.txt", skiprows=1, dtype='float')

theta1 = data1[:,0]
r1 = data1[:,1]

# Segundo caso

data2 = np.loadtxt("4-2.txt", skiprows=1, dtype='float')

theta2 = data2[:,0]
r2 = data2[:,1]

plt.figure()
ax = plt.subplot(111, polar=True)
ax.plot(theta1, r1, label='l=0,s=0')
ax.plot(theta2, r2, label='l=0,s=1')
ax.set_title("Sección eficaz diferencial")
ax.grid(True)
ax.legend()

plt.savefig("4-polar.pdf")
