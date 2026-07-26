SCALE_CC = gcc

SCALE_CFLAGS = -IC/INCLUDE 

SCALE_SRC = C/src/vector.c C/src/benchmark.c

SCALE_TEST_SRC = C/tests/vector_test/benchmarks/scale_bench.c

SCALE_TARGET = scale

scale:
	$(SCALE_CC) $(SCALE_SRC) $(SCALE_TEST_SRC) $(SCALE_CFLAGS) -o $(SCALE_TARGET)


scale_run:
	./$(SCALE_TARGET)