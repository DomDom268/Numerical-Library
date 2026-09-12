SET_GC = gcc

SET_CFLAGS += -IC/INCLUDE

SET_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

SET_TEST_SRC = C/tests/matrix_test/benchmarks/set_bench.c

SET_TARGET = mat_set

mat_set:
	$(SET_GC) $(SET_CFLAGS) $(SET_SRC) $(SET_TEST_SRC) -o $(SET_TARGET)

mat_set_run:
	./$(SET_TARGET)
