MCREATE_GC = gcc

MCREAT_CFLAGS += -IC/include

MCREATE_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

MCREATE_TEST_SRC = C/tests/matrix_test/benchmarks/create_bench.c

MCREATE_TARGET = mat_create

mat_create:
	$(MCREATE_GC) $(MCREATE_CFLAGS) $(MCREATE_SRC) $(MCREATE_TEST_SRC) -o $(MCREATE_TARGET)

mat_create_run:
	./$(MCREATE_TARGET)
