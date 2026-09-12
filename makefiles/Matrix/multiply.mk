MUL_GC = gcc

MUL_CFLAGS += -IC/INCLUDE/Matrix

MUL_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

MUL_TEST_SRC = C/tests/matrix_test/benchmarks/multiply_bench.c

MUL_TARGET = mat_mul

mat_mul:
	$(MUL_GC) $(MUL_SRC) $(MUL_TEST_SRC) $(MUL_CFLAGS) -o $(MUL_TARGET)

mat_mul_run:
	./$(MUL_TARGET)
