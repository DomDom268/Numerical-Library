COMP_CC = gcc

COMP_CFLAGS = -IC/INCLUDE 

COMP_SRC = C/src/Vecotr/vector.c C/src/Vector/benchmark.c

COMP_TEST_SRC = C/tests/vector_test/benchmarks/comprehensive_bench.c

COMP_TARGET = comprehensive

comprehensive:
	$(COMP_CC) $(COMP_SRC) $(COMP_TEST_SRC) $(COMP_CFLAGS) -o $(COMP_TARGET)


comp_run:
	./$(COMP_TARGET)

