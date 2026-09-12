CC = gcc

CFLAGS = -IC/include -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

ASAN_FLAGS = -g -fsanitize=address -fno-omit-frame-pointer

SRC = C/src/Matrix/matrix.c C/Unity/src/unity.c C/src/Matrix/benchmark.c

BENCH_SRC = C/src/Matrix/benchmark.c C/src/Matrix/matrix.c 

#Test Suites
BASIC_TESTS = C/tests/matrix_test/basic/test_basic.c C/tests/matrix_test/basic/test_basic_runner.c

EDGE_TESTS = C/tests/matrix_test/edge/test_edge.c C/tests/matrix_test/edge/test_edge_runner.c

MATH_TESTS = C/tests/matrix_test/mathematical/test_math.c C/tests/matrix_test/mathematical/test_math_runner.c

ADD_BENCH_TESTS = C/tests/matrix_test/benchmarks/add_bench.c
SUB_BENCH_TESTS = C/tests/matrix_test/benchmarks/sub_bench.c
SETVAL_BENCH_TESTS = C/tests/matrix_test/benchmarks/set_bench.c
GETVAL_BENCH_TESTS = C/tests/matrix_test/benchmarks/getVal_bench.c
CREATE_BENCH_TESTS = C/tests/matrix_test/benchmarks/create_bench.c
ELM_MUL_BENCH_TESTS = C/tests/matrix_test/benchmarks/elm_multiply_bench.c
ID_BENCH_TESTS = C/tests/matrix_test/benchmarks/id_bench.c
MUL_BENCH_TESTS = C/tests/matrix_test/benchmarks/multiply_bench.c
SCALAR_BENCH_TESTS = C/tests/matrix_tests/benchmarks/scalar_multiply_bench.c
TRAN_BENCH_TESTS = C/tests/matrix_test/benchmarks/transpose_bench.c

#Build each test suite with ASAN enabled
asan_mat_basic:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRC) $(BASIC_TESTS) -o asan_mat_basic -lm

asan_mat__edge:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRC) $(EDGE_TESTS) -o asan_mat_edge -lm

asan_mat_math:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRC) $(MATH_TESTS) -o asan_mat_math -lm

asan_mat_add:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(BENCH_SRC) $(ADD_BENCH_TESTS) -o asan_mat_add -lm
asan_mat_sub:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(BENCH_SRC) $(SUB_BENCH_TESTS) -o asan_mat_sub -lm
asan_mat_setval:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(BENCH_SRC) $(SETVAL_BENCH_TESTS) -o asan_mat_setval -lm
asan_mat_getval:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(BENCH_SRC) $(GETVAL_BENCH_TESTS) -o asan_mat_getval -lm
asan_mat_create:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(BENCH_SRC) $(CREATE_BENCH_TESTS) -o asan_mat_create -lm
asan_mat_elm:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(BENCH_SRC) $(ELM_MUL_BENCH_TESTS) -o asan_mat_elm -lm
asan_mat_id:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(BENCH_SRC) $(ID_BENCH_TESTS) -o asan_mat_id -lm
asan_mat_mul:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(BENCH_SRC) $(MUL_BENCH_TESTS) -o asan_mat_mul -lm
asan_mat_scalar:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(BENCH_SRC) $(SCALAR_BENCH_TESTS) -o asan_mat_scalar -lm
asan_mat_tran:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(BENCH_SRC) $(TRAN_BENCH_TESTS) -o asan_mat_tran -lm




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
	