placas.pdf: datos.txt grafica.py
	python3 grafica.py
datos.txt: placas.cpp
	c++ placas.cpp
	./a.out > datos.txt
	rm a.out