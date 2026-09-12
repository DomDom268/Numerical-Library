SCALE_CC = gcc

SCALE_CFLAGS += -IC/include 

SCALE_SRC = C/src/Vector/vector.c C/src/Vector/benchmark.c

SCALE_TEST_SRC = C/tests/vector_test/benchmarks/scale_bench.c

SCALE_TARGET = scale

scale:
	$(SCALE_CC) $(SCALE_CFLAGS) $(SCALE_SRC) $(SCALE_TEST_SRC) -o $(SCALE_TARGET) -lm


scale_run:
	./$(SCALE_TARGET)