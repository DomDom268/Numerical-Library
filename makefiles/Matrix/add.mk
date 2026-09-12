ADD_GC = gcc

ADD_CFLAGS = -IC/INCLUDE/Matrix

ADD_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

ADD_TEST_SRC = C/tests/matrix_test/benchmarks/add_bench.c

ADD_TARGET = mat_add

mat_add:
	$(ADD_GC) $(ADD_SRC) $(ADD_TEST_SRC) $(ADD_CFLAGS) -o $(ADD_TARGET)

mat_add_run:
	./$(ADD_TARGET)
