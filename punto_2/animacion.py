import numpy as np
import matplotlib.pyplot as plt
import imageio
import os

datos = np.loadtxt('datos.txt')
t = datos[1:,0]
n_t = len(t)
x = datos[0,1:]
imagenes = []

for i in range(1,n_t):
    u = datos[i,1:]
    plt.figure()
    plt.xlabel('x')
    plt.ylabel('u')
    plt.ylim((-1.0,1.0))
    plt.plot(x,u)
    plt.savefig(str(i))
    nombre = str(i) + '.png'
    imagenes.append(imageio.imread(nombre))
    os.system('rm ' + nombre)

imageio.mimsave('cuerda.gif', imagenes)


