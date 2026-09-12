ELM_GC = gcc

ELM_CFLAGS += -IC/include

ELM_SRC = C/src/Matrix/matrix.c C/src/Matrix/benchmark.c

ELM_TEST_SRC = C/tests/matrix_test/benchmarks/elm_multiply_bench.c

ELM_TARGET = mat_elm

mat_elm:
	$(ELM_GC) $(ELM_CFLAGS) $(ELM_SRC) $(ELM_TEST_SRC) -o $(ELM_TARGET)

mat_elm_run:
	./$(ELM_TARGET)
