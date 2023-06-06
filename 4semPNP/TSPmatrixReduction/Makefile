FLAGS = -fsanitize=address -mfpmath=sse -fstack-protector-all -g -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -Woverloaded-virtual -Wnon-virtual-dtor -Wcast-qual -Wno-suggest-attribute=format
all: do-test clean

test.o: test.cpp func.h
#       g++ -c $(FLAGS) -03 test.cpp

a.out: test.o
	g++ -Wextra -Wall -Wfloat-equal test.o -lm

do-test: a.out

clean: test.o
	rm test.o
