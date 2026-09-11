ADD_GC = gcc

ADD_CFLAGS = IC/include

ADD_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

ADD_TEST_SRC = C/tests/matrix_test/benchmarks/add_bench.c

ADD_TARGET = mat_add

mat_add:
	$(ADD_GCC) $(ADD_CFLAGS) $(ADD_SRC) $(ADD_TEST_SRC) -o $(ADD_TARGET)

mat_add_run:
	./$(ADD_TARGET)
