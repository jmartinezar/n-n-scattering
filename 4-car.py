import numpy as np
import matplotlib.pyplot as plt

# Leer los datos desde el archivo
data1 = np.loadtxt('4-1.txt', skiprows=1, dtype='float')

# Separar los datos en dos columnas: ángulo y valor
angles1 = data1[:, 0]
values1 = data1[:, 1]

# Leer los datos desde el archivo
data2 = np.loadtxt('4-2.txt', skiprows=1, dtype='float')

# Separar los datos en dos columnas: ángulo y valor
angles2 = data2[:, 0]
values2 = data2[:, 1]

# Crear la gráfica en coordenadas cartesianas
plt.figure()
plt.plot(angles1, values1, linestyle='-', color='b', label='l=0,s=0')
plt.plot(angles2, values2, linestyle='-', color='r', label='l=0,s=1')

# Configurar la gráfica
plt.title("Sección eficaz diferencial")
plt.xlabel(r"$\theta (radianes)$")
plt.ylabel(r"$f(\theta)$")
plt.grid(True)
plt.legend()

# Guardar la gráfica en un archivo PDF
plt.savefig("4-car.pdf")
