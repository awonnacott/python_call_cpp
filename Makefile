all: libfoo.so

test: all
	./fooWrapper.py

libfoo.so: foo.o
	g++ -shared -Wl,-soname,libfoo.so -o libfoo.so foo.o
foo.o: foo.cpp
	g++ -c -fPIC foo.cpp -o foo.o
