libakh.so: libakh.o
	gcc -Wall -Wextra -g -O2 -shared -fPIC -o libakh.so libakh.o
