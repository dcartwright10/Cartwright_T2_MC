import numpy as np
import matplotlib.pylab as plt
from scipy.fftpack import *
##Almacenamiento de los datos##
data1 = np.genfromtxt("signalSuma.dat")
data2 = np.genfromtxt("signal.dat")

N = 2048
dt = abs(data1[1,0]-data1[2,0])


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



##implementacion de la transformada discreta de Fourier##
def Fourier(N,data):
	amplitudes = []
	for n in range(N):
		suma = 0
		for k in range(N):			
			suma += data[k]*np.exp(-1j*2*np.pi*k*(1.0*n/N))
		#print(suma)
		amplitudes.append(suma)
	return np.asarray(amplitudes)

res = abs(Fourier(N,data1[:,1]))
res2 = abs(Fourier(N,data2[:,1]))
freq = fftfreq(N,d=dt)

####Prueba de grafico####
#sci_res = fft(data1[:,1])
#plt.figure()
#plt.plot(freq,abs(sci_res))
#plt.xlim(0,3000)
#plt.show()

##graficos de la transformada de Fourier de ambas senales##

plt.figure()
plt.plot(freq,res2,c="black", label="suma")
plt.plot(freq, res, c="red", label="separadas")
plt.legend(loc="upper right")
plt.title("Transformada de Fourier de las senales")
plt.xlabel("Frecuencia")
plt.ylabel("Densidad de frecuencia")
plt.xlim(0,1000)
plt.savefig("Fourier_senales.pdf")


##espectrograma de las senales##
plt.figure()
plt.subplot(2,1,1)
plt.specgram(data1[:,1])
plt.ylabel("Frecuencia(Hz)")
plt.title("Suma senales")


plt.subplot(2,1,2)
plt.specgram(data2[:,1])
plt.xlabel("tiempo(s)")
plt.title("senales individuales")
plt.savefig("espectrogramas1.pdf")

##Almacenamiento de datos y grafica de la senal "temblor" en funcion de tiempo##

temblor = np.genfromtxt("temblor(1).txt", skip_header=4)
Num = len(temblor)
dt1= (0.01)

plt.figure()
plt.plot(temblor[:],c="red")
plt.title("Grafica de senal sismica(freq. muestreo = 100Hz)")
plt.xlabel("tiempo(s)")
plt.ylabel("Amplitud(d.u.)")
plt.savefig("temblor.pdf")

##Transformada de Fourier de la senal##

freq_t = fftfreq(Num,d=dt1)
Trans_temblor = fft(temblor)
plt.figure()
plt.plot(freq_t,abs(Trans_temblor))
plt.title("Transformada de Fourier de senal de temblor")
plt.xlabel("Frecuencia")
plt.ylabel("Densidad de Frecuencia")
plt.savefig("Fourier_temblor.pdf")

##espectrograma de senal de temblor##
plt.figure()
plt.specgram(temblor)
plt.title("Espectrograma de la senal de temblor")
plt.xlabel("tiempo(s)")
plt.ylabel("Frecuencia(Hz)")
plt.savefig("espec_temblor.pdf")
