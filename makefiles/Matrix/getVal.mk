GET_GC = gcc

GET_CFLAGS += -IC/include

GET_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

GET_TEST_SRC = C/tests/matrix_test/benchmarks/getVal_bench.c

GET_TARGET = mat_get

mat_get:
	$(GET_GC) $(GET_CFLAGS) $(GET_SRC) $(GET_TEST_SRC) -o $(GET_TARGET)

mat_get_run:
	./$(GET_TARGET)
