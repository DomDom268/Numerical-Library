CC = gcc

CFLAGS = -IC/INCLUDE

SRC = C/src/vector.c C/src/benchmark.c 

TEST_SRC = C/tests/vector_test/benchmarks/setval_bench.c 

TARGET = benchmarks

setval_bench:
	$(CC) $(SRC) $(TEST_SRC) $(CFLAGS) -o $(TARGET)


setval_run:
	./$(TARGET)

