import numpy as np
import matplotlib.pylab as plt

data = np.genfromtxt("datos.dat")

frecuencias = data[:,0]
max1 = data[:,1]
max2 = data[:,2]
max3 = data[:,3]
p1 = data[:,4]
p2 = data[:,5]
p3 = data[:,6]
tiempo = data[:,7]

plt.figure()

plt.subplot(3,1,1)
plt.title("Amplitudes maximas en funcion de la frecuencia")
plt.plot(frecuencias,max1,label="primer piso",c="red")
plt.legend(loc="best")
plt.subplot(3,1,2)
plt.plot(frecuencias, max2, label="segundo piso",c="blue")
plt.ylabel("amplitud")
plt.legend(loc="best")
plt.subplot(3,1,3)
plt.plot(frecuencias,max3, label="tercer piso",c="green")
plt.xlabel("frecuencia(Hz)")
plt.legend(loc="best")
plt.savefig("amp_max_edificio.pdf")


plt.figure()
plt.subplot(3,1,1)
plt.title("Amplitud en funcion del tiempo para cada piso")
plt.plot(tiempo, p1,label="primer piso",c="red")
plt.legend(loc="best")

plt.subplot(3,1,2)
plt.ylabel("Amplitud")
plt.plot(tiempo, p2,label="segundo piso",c="blue")
plt.legend(loc="best")

plt.subplot(3,1,3)
plt.plot(tiempo, p3, label="tercer piso",c="green")
plt.xlabel("tiempo(s)")
plt.legend(loc="best")
plt.savefig("amp_contra_tiempo.pdf")




