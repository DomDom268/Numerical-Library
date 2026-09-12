CB_CC = gcc

CB_CFLAGS += -IC/include

CB_SRC = C/src/Vector/vector.c C/src/Vector/benchmark.c 

CB_TEST_SRC = C/tests/vector_test/benchmarks/create_bench.c 

CB_TARGET = benchmarks

create_bench:
	$(CB_CC) $(CB_CFLAGS) $(CB_SRC) $(CB_TEST_SRC) -o $(CB_TARGET)


create_run:
	./$(CB_TARGET)


