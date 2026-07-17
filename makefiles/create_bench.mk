CC = gcc

CFLAGS = -IC/INCLUDE

SRC = C/src/vector.c C/src/benchmark.c 

TEST_SRC = C/tests/vector_test/benchmarks/create_bench.c 

TARGET = benchmarks

create_bench:
	$(CC) $(SRC) $(TEST_SRC) $(CFLAGS) -o $(TARGET)


create_run:
	./$(TARGET)


