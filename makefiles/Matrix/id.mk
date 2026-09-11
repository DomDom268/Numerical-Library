ID_GC = gcc

ID_CFLAGS = -IC/include

ID_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

ID_TEST_SRC = C/tests/matrix_test/benchmarks/id_bench.c

ID_TARGET = mat_id

mat_id:
	$(ID_GC) $(ID_CFLAGS) $(ID_SRC) $(ID_TEST_SRC) -o $(ID_TARGET)

mat_id_run:
	./$(ID_TARGET)
