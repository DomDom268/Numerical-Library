DOT_CC = gcc

DOT_CFLAGS = -IC/INCLUDE 

DOT_SRC = C/src/Vector/vector.c C/src/Vector/benchmark.c

DOT_TEST_SRC = C/tests/vector_test/benchmarks/dot_bench.c

DOT_TARGET = dot

dot:
	$(DOT_CC) $(DOT_SRC) $(DOT_TEST_SRC) $(DOT_CFLAGS) -o $(DOT_TARGET)


dot_run:
	./$(DOT_TARGET)