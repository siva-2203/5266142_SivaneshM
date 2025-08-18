
object.o:main.c square.c sum.c unity.c
	gcc main.c square.c sum.c unity.c -c
all:main.o square.o sum.o unity.o
	gcc main.o square.o sum.o unity.o -o all.exe
run:all
	./all.exe
clean:
	rm -f *.o *.out all