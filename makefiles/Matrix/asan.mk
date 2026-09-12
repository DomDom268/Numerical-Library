CC = gcc

CFLAGS += -IC/include -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

ASAN_FLAGS = -g -fsanitize=address -fno-omit-frame-pointer

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
asan_mat_basic:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MSRC) $(MBASIC_TESTS) -o asan_mat_basic -lm

asan_mat_edge:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MSRC) $(MEDGE_TESTS) -o asan_mat_edge -lm

asan_mat_math:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MSRC) $(MMATH_TESTS) -o asan_mat_math -lm

asan_mat_add:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MBENCH_SRC) $(MADD_BENCH_TESTS) -o asan_mat_add -lm
asan_mat_sub:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MBENCH_SRC) $(MSUB_BENCH_TESTS) -o asan_mat_sub -lm
asan_mat_setval:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MBENCH_SRC) $(MSETVAL_BENCH_TESTS) -o asan_mat_setval -lm
asan_mat_getval:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MBENCH_SRC) $(MGETVAL_BENCH_TESTS) -o asan_mat_getval -lm
asan_mat_create:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MBENCH_SRC) $(MCREATE_BENCH_TESTS) -o asan_mat_create -lm
asan_mat_elm:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MBENCH_SRC) $(MELM_MUL_BENCH_TESTS) -o asan_mat_elm -lm
asan_mat_id:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MBENCH_SRC) $(MID_BENCH_TESTS) -o asan_mat_id -lm
asan_mat_mul:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MBENCH_SRC) $(MMUL_BENCH_TESTS) -o asan_mat_mul -lm
asan_mat_scalar:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MBENCH_SRC) $(MSCALAR_BENCH_TESTS) -o asan_mat_scalar -lm
asan_mat_tran:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(MBENCH_SRC) $(MTRAN_BENCH_TESTS) -o asan_mat_tran -lm




asan_mat_bench:asan_mat_add asan_mat_sub asan_mat_setval asan_mat_getval asan_mat_create asan_mat_elm asan_mat_id asan_mat_mul asan_mat_scalar asan_mat_tran
	./asan_mat_add
	./asan_mat_sub
	./asan_mat_setval
	./asan_mat_getval
	./asan_mat_create
	./asan_mat_elm
	./asan_mat_id
	./asan_mat_mul
	./asan_mat_scalar
	./asan_mat_tran
	
asan_mat_all:asan_mat_basic asan_mat_edge asan_mat_math 
	./asan_mat_basic
	./asan_mat_edge
	./asan_mat_math
	