run:
	mkdir basura
	mv *.cpp basura/
	g++ -std=c++14 -Wall -o ./bin/avl ./src/Demo.cpp ./src/DNI.cpp ./src/AVL.cpp ./src/ArbolBB.cpp 
	./bin/avl 

clean:
	rm -f arbol_binario *.o ./bin/*