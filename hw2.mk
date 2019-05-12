Resultados_hw2.pdf : amp_max_edificio.pdf avst_o1.pdf avst_o2.pdf avst_o3.pdf avst_o4.pdf espec_temblor.pdf espectrogramas1.pdf Fourier_senales.pdf Fourier_temblor.pdf signal_subplots.pdf temblor.pdf Resultados_hw2.tex
	pdflatex Resultados_hw2.tex

amp_max_edificio.pdf avst_o1.pdf avst_o2.pdf avst_o3.pdf avst_o4.pdf : datos.dat omega1.dat omega2.dat omega3.dat omega4.dat Plots_hw2.py
	python Plots_hw2.py

espec_temblor.pdf espectrogramas1.pdf Fourier_senales.pdf Fourier_temblor.pdf signal_subplots.pdf temblor.pdf : Fourier.py
	python Fourier.py

datos.dat omega1.dat omega2.dat omega3.dat omega4.dat : a.out
	./a.out > datos.dat omega1.dat omega2.dat omega3.dat omega4.dat

a.out : Edificio.cpp
	g++ Edificio.cpp






