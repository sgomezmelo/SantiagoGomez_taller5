import numpy as np
import matplotlib.pyplot as plt
import matplotlib.cm as cm

datos = np.loadtxt('datos.txt')
n = 513
h = 5.0/n
L  = 5.0
X = np.linspace(-L/2,L/2,n-1)
Y = np.linspace(-L/2,L/2,n-1)

#X , Y = np.mgrid[-L/2.0:L/2.0:(n-1)*1j,-L/2.0:L/2.0:(n-1)*1j]

V_t = datos[0:n-1,0:n-1]
Ex_t = datos[n:2*n-1,0:n-1]
Ey_t = datos[2*n:3*n-1,0:n-1]

V = np.transpose(V_t)
Ex = -np.transpose(Ex_t)
Ey = -np.transpose(Ey_t)


print(Ex[253,253],Ey[253,253])

plt.imshow(V, extent = [-L/2.0,L/2.0,-L/2.0,L/2.0],cmap=cm.RdYlGn)
plt.streamplot(Y,X,Ex,Ey, density = 2, arrowsize = 0.5)
m = cm.ScalarMappable(cmap=cm.RdYlGn)
m.set_array(V)
plt.colorbar(m)
plt.savefig('placas.pdf')
