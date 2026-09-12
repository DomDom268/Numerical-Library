COMP_CC = gcc

COMP_CFLAGS += -IC/include 

COMP_SRC = C/src/Vecotr/vector.c C/src/Vector/benchmark.c

COMP_TEST_SRC = C/tests/vector_test/benchmarks/comprehensive_bench.c

COMP_TARGET = comprehensive

comprehensive:
	$(COMP_CC) $(COMP_CFLAGS) $(COMP_SRC) $(COMP_TEST_SRC) -o $(COMP_TARGET) -lm


comp_run:
	./$(COMP_TARGET)

