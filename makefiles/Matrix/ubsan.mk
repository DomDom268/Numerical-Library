CC = gcc

CFLAGS += -IC/include -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

UBSAN_FLAGS = -g -fsanitize=undefined -fno-omit-frame-pointer

MSRC = C/src/Matrix/matrix.c C/Unity/src/unity.c C/src/Matrix/benchmark.c

MBENCH_SRC = C/src/Matrix/benchmark.c C/src/Matrix/matrix.c 

#Test Suites
MBASIC_TESTS = C/tests/matrix_test/basic/test_basic.c C/tests/matrix_test/basic/test_basic_runner.c

MEDGE_TESTS = C/tests/matrix_test/edge/test_edge.c C/tests/matrix_test/edge/test_edge_runner.c

MMATH_TESTS = C/tests/matrix_test/mathematical/test_math.c C/tests/matrix_test/mathematical/test_math_runner.c

MADD_BENCH_TESTS = C/tests/matrix_test/benchmarks/add_bench.c
MSUB_BENCH_TESTS = C/tests/matrix_test/benchmarks/sub_bench.c
MSETVAL_BENCH_TESTS = C/tests/matrix_test/benchmarks/set_bench.c
MGETVAL_BENCH_TESTS = C/tests/matrix_test/benchmarks/getVal_bench.c
MCREATE_BENCH_TESTS = C/tests/matrix_test/benchmarks/create_bench.c
MELM_MUL_BENCH_TESTS = C/tests/matrix_test/benchmarks/elm_multiply_bench.c
MID_BENCH_TESTS = C/tests/matrix_test/benchmarks/id_bench.c
MMUL_BENCH_TESTS = C/tests/matrix_test/benchmarks/multiply_bench.c
MSCALAR_BENCH_TESTS = C/tests/matrix_tests/benchmarks/scalar_multiply_bench.c
MTRAN_BENCH_TESTS = C/tests/matrix_test/benchmarks/transpose_bench.c

#Build each test suite with ASAN enabled
ubsan_mat_basic:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MSRC) $(MBASIC_TESTS) -o ubsan_mat_basic -lm

ubsan_mat_edge:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MSRC) $(MEDGE_TESTS) -o ubsan_mat_edge -lm

ubsan_mat_math:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MSRC) $(MMATH_TESTS) -o ubsan_mat_math -lm

ubsan_mat_add:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MBENCH_SRC) $(MADD_BENCH_TESTS) -o ubsan_mat_add -lm
ubsan_mat_sub:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MBENCH_SRC) $(MSUB_BENCH_TESTS) -o ubsan_mat_sub -lm
ubsan_mat_setval:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MBENCH_SRC) $(MSETVAL_BENCH_TESTS) -o ubsan_mat_setval -lm
ubsan_mat_getval:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MBENCH_SRC) $(MGETVAL_BENCH_TESTS) -o ubsan_mat_getval -lm
ubsan_mat_create:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MBENCH_SRC) $(MCREATE_BENCH_TESTS) -o ubsan_mat_create -lm
ubsan_mat_elm:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MBENCH_SRC) $(MELM_MUL_BENCH_TESTS) -o ubsan_mat_elm -lm
ubsan_mat_id:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MBENCH_SRC) $(MID_BENCH_TESTS) -o ubsan_mat_id -lm
ubsan_mat_mul:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MBENCH_SRC) $(MMUL_BENCH_TESTS) -o ubsan_mat_mul -lm
ubsan_mat_scalar:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MBENCH_SRC) $(MSCALAR_BENCH_TESTS) -o ubsan_mat_scalar -lm
ubsan_mat_tran:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(MBENCH_SRC) $(MTRAN_BENCH_TESTS) -o ubsan_mat_tran -lm




ubsan_mat_bench:ubsan_mat_add ubsan_mat_sub ubsan_mat_setval ubsan_mat_getval ubsan_mat_create ubsan_mat_elm ubsan_mat_id ubsan_mat_mul ubsan_mat_scalar ubsan_mat_tran
	./ubsan_mat_add
	./ubsan_mat_sub
	./ubsan_mat_setval
	./ubsan_mat_getval
	./ubsan_mat_create
	./ubsan_mat_elm
	./ubsan_mat_id
	./ubsan_mat_mul
	./ubsan_mat_scalar
	./ubsan_mat_tran
	
ubsan_mat_all:ubsan_mat_basic ubsan_mat_edge ubsan_mat_math 
	./ubsan_mat_basic
	./ubsan_mat_edge
	./ubsan_mat_math