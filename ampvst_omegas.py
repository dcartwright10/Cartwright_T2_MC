import numpy as np
import matplotlib.pylab as plt


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
plt.savefig("avst_o1")
