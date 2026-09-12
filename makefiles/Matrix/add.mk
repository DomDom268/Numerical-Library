MADD_GC = gcc

MADD_CFLAGS += -IC/include

MADD_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

MADD_TEST_SRC = C/tests/matrix_test/benchmarks/add_bench.c

MADD_TARGET = mat_add

mat_add:
	$(MADD_GC) $(MADD_CFLAGS) $(MADD_SRC) $(MADD_TEST_SRC) -o $(MADD_TARGET)

mat_add_run:
	./$(MADD_TARGET)
