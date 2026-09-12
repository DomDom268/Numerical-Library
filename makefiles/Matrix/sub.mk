SUB_GC = gcc

SUB_CFLAGS += -IC/INCLUDE/Matrix

SUB_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

SUB_TEST_SRC = C/tests/matrix_test/benchmarks/sub_bench.c

SUB_TARGET = mat_sub

mat_sub:
	$(SUB_GC) $(SUB_SRC) $(SUB_TEST_SRC) $(SUB_CFLAGS) -o $(SUB_TARGET)

mat_sub_run:
	./$(SUB_TARGET)
