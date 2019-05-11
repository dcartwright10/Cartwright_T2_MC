import numpy as np
import matplotlib.pylab as plt

datos = np.genfromtxt("datos(2).dat")

tiempo = datos[:,0]
a_p1 = datos[:,1]
a_p2 = datos[:,2]
a_p3 = datos[:,3]
v_p1 = datos[:,4]
v_p2 = datos[:,5]
v_p3 = datos[:,6]

plt.figure()
plt.title("A en funcion de t")
plt.plot(tiempo, a_p1, label="primer piso",c="blue")
plt.plot(tiempo, a_p2, label="segundo piso",c="green")
plt.plot(tiempo, a_p3, label="tercer piso",c="red")
plt.xlabel("tiempo")
plt.ylabel("amplitud")
plt.legend(loc="best")
plt.show()

