PRINT_CC = gcc

PRINT_CFLAGS = -IC/INCLUDE 

PRINT_SRC = C/src/vector.c C/src/benchmark.c

PRINT_TEST_SRC = C/tests/vector_test/benchmarks/print_bench.c

PRINT_TARGET = print

print:
	$(PRINT_CC) $(PRINT_SRC) $(PRINT_TEST_SRC) $(PRINT_CFLAGS) -o $(PRINT_TARGET)


print_run:
	./$(PRINT_TARGET)