TRAN_GC = gcc

TRAN_CFLAGS = -IC/include

TRAN_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

TRAN_TEST_SRC = C/tests/matrix_test/benchmarks/transpose_bench.c

TRAN_TARGET = mat_transpose

mat_tran:
	$(TRAN_GC) $(TRAN_CFLAGS) $(TRAN_SRC) $(TRAN_TEST_SRC) -o $(TRAN_TARGET)

mat_tran_run:
	./$(TRAN_TARGET)
