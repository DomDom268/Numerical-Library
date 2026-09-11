SCALAR_GC = gcc

SCALAR_CFLAGS = -IC/include

SCALAR_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

SCALAR_TEST_SRC = C/tests/matrix_test/benchmarks/scalar_multiply_bench.c

SCALAR_TARGET = mat_scalar

mat_scalar:
	$(SCALAR_GC) $(SCALAR_CFLAGS) $(SCALAR_SRC) $(SCALAR_TEST_SRC) -o $(SCALAR_TARGET)

mat_scalar_run:
	./$(SCALAR_TARGET)
