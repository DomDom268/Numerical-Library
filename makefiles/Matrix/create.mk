CREATE_GC = gcc

CREAT_CFLAGS = -IC/INCLUDE/Matrix

CREATE_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

CREATE_TEST_SRC = C/tests/matrix_test/benchmarks/create_bench.c

CREATE_TARGET = mat_create

mat_create:
	$(CREATE_GC) $(CREATE_SRC) $(CREATE_TEST_SRC) $(CREATE_CFLAGS) -o $(CREATE_TARGET)

mat_create_run:
	./$(CREATE_TARGET)
