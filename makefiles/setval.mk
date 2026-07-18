SVB_CC = gcc

SVB_CFLAGS = -IC/INCLUDE

SVB_SRC = C/src/vector.c C/src/benchmark.c 

SVB_TEST_SRC = C/tests/vector_test/benchmarks/setval_bench.c 

SVB_TARGET = benchmarks

setval_bench:
	$(SVB_CC) $(SVB_SRC) $(SVB_TEST_SRC) $(SVB_CFLAGS) -o $(SVB_TARGET)


setval_run:
	./$(SVB_TARGET)

