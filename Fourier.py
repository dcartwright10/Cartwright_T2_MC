import numpy as np
import matplotlib.pylab as plt

##Almacenamiento de los datos##
data1 = np.genfromtxt("signalSuma.dat")
data2 = np.genfromtxt("signal.dat")

##subplots con el grafico para cada senal##
plt.figure()
plt.subplot(2,1,1)
plt.title("signalSuma")
plt.xlabel("Tiempo(s)")
plt.ylabel("Amplitud")
plt.plot(data1[:,0],data1[:,1])

plt.subplot(2,1,2)
plt.title("signal")
plt.xlabel("Tiempo(s)")
plt.ylabel("Amplitud")
plt.plot(data2[:,0],data2[:,1])

plt.savefig("signal_subplots.pdf")

##implementacion de la transformada discreta de fourier##

##graficos de la transformada de Fourier de ambas senales##

##espectrograma de las senales##
plt.figure()
plt.subplot(2,1,1)
plt.specgram(data1[:,1])

plt.subplot(2,1,2)
plt.specgram(data2[:,1])
plt.show()
