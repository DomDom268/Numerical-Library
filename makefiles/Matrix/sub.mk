MSUB_GC = gcc

MSUB_CFLAGS += -IC/include

MSUB_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

MSUB_TEST_SRC = C/tests/matrix_test/benchmarks/sub_bench.c

MSUB_TARGET = mat_sub

mat_sub:
	$(MSUB_GC) $(MSUB_CFLAGS) $(MSUB_SRC) $(MSUB_TEST_SRC) -o $(MSUB_TARGET)

mat_sub_run:
	./$(MSUB_TARGET)
