MANHATTAN_NORM_CC = gcc

MANHATTAN_NORM_CFLAGS = -IC/INCLUDE 

MANHATTAN_NORM_SRC = C/src/vector.c C/src/benchmark.c

MANHATTAN_NORM_TEST_SRC = C/tests/vector_test/benchmarks/mannorm_bench.c

MANHATTAN_NORM_TARGET = manhattan_norm

manhattan_norm:
	$(MANHATTAN_NORM_CC) $(MANHATTAN_NORM_SRC) $(MANHATTAN_NORM_TEST_SRC) $(MANHATTAN_NORM_CFLAGS) -o $(MANHATTAN_NORM_TARGET)


manhattan_norm_run:
	./$(MANHATTAN_NORM_TARGET)