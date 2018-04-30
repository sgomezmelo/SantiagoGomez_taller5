caos.pdf: caos.py datos.txt
	python3 caos.py
datos.txt: caos.cpp
	c++ -o caos.x caos.cpp
	./caos.x > datos.txt
