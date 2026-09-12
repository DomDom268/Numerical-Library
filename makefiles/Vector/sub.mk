SUB_CC = gcc

SUB_CFLAGS = -IC/include 

SUB_SRC = C/src/Vector/vector.c C/src/Vector/benchmark.c

SUB_TEST_SRC = C/tests/vector_test/benchmarks/sub_bench.c

SUB_TARGET = sub

sub:
	$(SUB_CC) $(SUB_CFLAGS) $(SUB_SRC) $(SUB_TEST_SRC) -o $(SUB_TARGET)


sub_run:
	./$(SUB_TARGET)