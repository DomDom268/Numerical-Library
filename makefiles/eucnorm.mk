EUCLIDEAN_NORM_CC = gcc

EUCLIDEAN_NORM_CFLAGS = -IC/INCLUDE 

EUCLIDEAN_NORM_SRC = C/src/vector.c C/src/benchmark.c

EUCLIDEAN_NORM_TEST_SRC = C/tests/vector_test/benchmarks/eucnorm_bench.c

EUCLIDEAN_NORM_TARGET = euclidean_norm

euclidean_norm:
	$(EUCLIDEAN_NORM_CC) $(EUCLIDEAN_NORM_SRC) $(EUCLIDEAN_NORM_TEST_SRC) $(EUCLIDEAN_NORM_CFLAGS) -o $(EUCLIDEAN_NORM_TARGET)


euclidean_norm_run:
	./$(EUCLIDEAN_NORM_TARGET)