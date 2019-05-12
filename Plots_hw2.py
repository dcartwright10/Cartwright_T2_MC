import numpy as np
import matplotlib.pylab as plt

##Grafico de amplitudes maximas en funcion de frecuencia##
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


##Graficos de la amplitud en funcion de tiempo para omegas elegidos##

##omega1
dat1 = np.genfromtxt("omega1.dat")
tiempo = dat1[:,3]
p1 = dat1[:,0]
p2 = dat1[:,1]
p3 = dat1[:,2]

plt.figure()
plt.title("Amplitud en funcion de tiempo (omega = 2.6587)")
plt.plot(tiempo,p1,label="primer piso")
plt.plot(tiempo,p2,label="segundo piso")
plt.plot(tiempo,p3,label="tercer piso")
plt.xlabel("tiempo(s)")
plt.ylabel("Amplitud")
plt.legend(loc="best")
plt.savefig("avst_o1.pdf")

##omega2
dat2 = np.genfromtxt("omega2.dat")

f1 = dat2[:,0]
f2 = dat2[:,1]
f3 = dat2[:,2]

plt.figure()
plt.title("Amplitud en funcion de tiempo (omega =1.7479)")
plt.plot(tiempo,f1,label="primer piso")
plt.plot(tiempo,f2,label="segundo piso")
plt.plot(tiempo,f3,label="tercer piso")
plt.xlabel("tiempo(s)")
plt.ylabel("Amplitud")
plt.legend(loc="best")
plt.savefig("avst_o2.pdf")

##omega3
dat3 = np.genfromtxt("omega3.dat")

g1 = dat3[:,0]
g2 = dat3[:,1]
g3 = dat3[:,2]

plt.figure()
plt.title("Amplitud en funcion de tiempo (omega =0.6788)")
plt.plot(tiempo,g1,label="primer piso")
plt.plot(tiempo,g2,label="segundo piso")
plt.plot(tiempo,g3,label="tercer piso")
plt.xlabel("tiempo(s)")
plt.ylabel("Amplitud")
plt.legend(loc="best")
plt.savefig("avst_o3.pdf")

##omega4
dat4 = np.genfromtxt("omega4.dat")

h1 = dat4[:,0]
h2 = dat4[:,1]
h3 = dat4[:,2]

plt.figure()
plt.title("Amplitud en funcion de tiempo (omega =3.1339)")
plt.plot(tiempo,h1,label="primer piso")
plt.plot(tiempo,h2,label="segundo piso")
plt.plot(tiempo,h3,label="tercer piso")
plt.xlabel("tiempo(s)")
plt.ylabel("Amplitud")
plt.legend(loc="best")
plt.savefig("avst_o4.pdf")





