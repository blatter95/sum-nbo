#Makefile
all: sum-nbo

binfile: 
	echo -n -e \\x00\\x00\\x03\\xe8 > thousand.bin
	echo -n -e \\x00\\x00\\x01\\xf4 > five-hundred.bin
	echo -n -e \\x00\\x00\\x00\\xc8 > two-hundred.bin

sum-nbo: sum-nbo.o
	g++ -o sum-nbo sum-nbo.o

sum-nbo.o: sum-nbo.cpp
	g++ -c -o sum-nbo.o sum-nbo.cpp

clean:
	rm -f sum-test
	rm -f *.o
	rm -f *.bin
