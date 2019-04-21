all: libfoo.so somemodule.so
# from python2-config --includes
PYTHON_INCLUDES=-I/usr/include/python2.7 -I/usr/include/python2.7 -I/usr/lib/python2.7/site-packages/numpy/core/include

test: all
	./nr3python_test.py

libfoo.so: foo.o
	g++ -shared -Wl,-soname,libfoo.so -o libfoo.so foo.o
foo.o: foo.cpp
	g++ -c -fPIC foo.cpp -o foo.o

somemodule.so: somemodule.o
	g++ -shared somemodule.o -o somemodule.so
somemodule.o: somemodule.cpp nr3python.h
	g++ ${PYTHON_INCLUDES} -c -fPIC -fpermissive -w somemodule.cpp -o somemodule.o
