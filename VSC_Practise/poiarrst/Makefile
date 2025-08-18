SRCS=main.c minor.c testcase.c tallest.c unity.c adult_ornot.c
OBJS=main.o minor.o testcase.o tallest.o unity.o adult_ornot.o
object.o:$(SRCS)
	gcc $^ -c
all:$(OBJS)
	gcc $^ -o $@
run:all
	./all
clean:
	del *.o *.exe all 