NORM_CC = gcc

NORM_CFLAGS = -IC/INCLUDE 

NORM_SRC = C/src/Vector/vector.c C/src/Vector/benchmark.c

NORM_TEST_SRC = C/tests/vector_test/benchmarks/normdist_bench.c

NORM_TARGET = norm

norm:
	$(NORM_CC) $(NORM_SRC) $(NORM_TEST_SRC) $(NORM_CFLAGS) -o $(NORM_TARGET)


norm_run:
	./$(NORM_TARGET)