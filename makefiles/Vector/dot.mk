DOT_CC = gcc

DOT_CFLAGS = -IC/include 

DOT_SRC = C/src/Vector/vector.c C/src/Vector/benchmark.c

DOT_TEST_SRC = C/tests/vector_test/benchmarks/dot_bench.c

DOT_TARGET = dot

dot:
	$(DOT_CC) $(DOT_CFLAGS) $(DOT_SRC) $(DOT_TEST_SRC) -o $(DOT_TARGET)


dot_run:
	./$(DOT_TARGET)