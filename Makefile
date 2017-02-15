all:
	mkdir bin
	c++ src/interpretor.cpp -o bin/interpretor

clean:
	rm -r bin
