ADD_CC = gcc

ADD_CFLAGS = -IC/INCLUDE 

ADD_SRC = C/src/Vector/vector.c C/src/Vector/benchmark.c

ADD_TEST_SRC = C/tests/vector_test/benchmarks/add_bench.c

ADD_TARGET = add

add:
	$(ADD_CC) $(ADD_SRC) $(ADD_TEST_SRC) $(ADD_CFLAGS) -o $(ADD_TARGET)


add_run:
	./$(ADD_TARGET)