cs257final: main.cpp image.cpp image.h
	g++ -Wall -O2 -g main.cpp image.cpp -std=c++11 -o ./cs257final

.PHONY: clean
clean:
	rm -f cs257final

