import numpy as np
import matplotlib.pyplot as plt

datos = np.loadtxt('datos.txt')
q2 = datos[:,0]
p2 = datos[:,1]
#q2 = datos[:,2]
#q3 = datos[:,3]

plt.figure()
plt.scatter(q2,p2)
plt.xlabel('q2')
plt.ylabel('p2')
#plt.plot(t,q2)
#plt.plot(t,q3)
plt.savefig('caos.pdf')
