CC = gcc

CFLAGS = -ic/INCLUDE

SRC = src/vector.c src/benchmark.c

TEST_SRC = tests/vector_test/benchmarks/create_bench.c tests/vector_test/benchmarks/setval_bench.c

TARGET = benchmarks

bench:
	$(CC) $(SRC) $(TEST_SRC) $(CFLAGS) -o $(TARGET)


run:
	./$(TARGET)


clean:
	rm -f $(TARGET)
