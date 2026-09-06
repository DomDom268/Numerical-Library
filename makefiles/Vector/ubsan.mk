CC = gcc

CFLAGS = -IC/include -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

UBSAN_FLAGS = -g -fsanitize=undefined -fno-omit-frame-pointer

SRC = C/src/Vector/vector.c C/Unity/src/unity.c C/src/Vector/benchmark.c

BENCH_SRC = C/src/Vector/benchmark.c C/src/Vector/vector.c 

#Test Suites
BASIC_TESTS = C/tests/vector_test/basic/test_basic.c C/tests/vector_test/basic/test_basic_runner.c

EDGE_TESTS = C/tests/vector_test/edge/test_edge.c C/tests/vector_test/edge/test_edge_runner.c

MATH_TESTS = C/tests/vector_test/mathematical/test_math.c C/tests/vector_test/mathematical/test_math_runner.c

ADD_BENCH_TESTS = C/tests/vector_test/benchmarks/add_bench.c
SUB_BENCH_TESTS = C/tests/vector_test/benchmarks/sub_bench.c
SCALE_BENCH_TESTS = C/tests/vector_test/benchmarks/scale_bench.c
SETVAL_BENCH_TESTS = C/tests/vector_test/benchmarks/setval_bench.c
PRINT_BENCH_TESTS = C/tests/vector_test/benchmarks/print_bench.c
NORMDIST_BENCH_TESTS = C/tests/vector_test/benchmarks/normdist_bench.c
MANNORM_BENCH_TESTS = C/tests/vector_test/benchmarks/mannorm_bench.c
EUCNORM_BENCH_TESTS = C/tests/vector_test/benchmarks/eucnorm_bench.c
EUCDIST_BENCH_TESTS = C/tests/vector_test/benchmarks/eucdist_bench.c
DOT_BENCH_TESTS = C/tests/vector_test/benchmarks/dot_bench.c
CREATE_BENCH_TESTS = C/tests/vector_test/benchmarks/create_bench.c
COMPREHENSIVE_BENCH_TESTS = C/tests/vector_test/benchmarks/comprehensive_bench.c

#Build each test suite with UBSAN enabled
ubsan_basic:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(SRC) $(BASIC_TESTS) -o ubsan_basic -lm

ubsan_edge:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(SRC) $(EDGE_TESTS) -o ubsan_edge -lm

ubsan_math:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(SRC) $(MATH_TESTS) -o ubsan_math -lm

ubsan_add_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(ADD_BENCH_TESTS) -o ubsan_add_bench -lm
ubsan_sub_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(SUB_BENCH_TESTS) -o ubsan_sub_bench -lm
ubsan_scale_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(SCALE_BENCH_TESTS) -o ubsan_scale_bench -lm
ubsan_setval_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(SETVAL_BENCH_TESTS) -o ubsan_setval_bench -lm
ubsan_print_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(PRINT_BENCH_TESTS) -o ubsan_print_bench -lm
ubsan_normdist_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(NORMDIST_BENCH_TESTS) -o ubsan_normdist_bench -lm
ubsan_mannorm_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(MANNORM_BENCH_TESTS) -o ubsan_mannorm_bench -lm
ubsan_eucnorm_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(EUCNORM_BENCH_TESTS) -o ubsan_eucnorm_bench -lm
ubsan_eucdist_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(EUCDIST_BENCH_TESTS) -o ubsan_eucdist_bench -lm
ubsan_dot_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(DOT_BENCH_TESTS) -o ubsan_dot_bench -lm
ubsan_create_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(CREATE_BENCH_TESTS) -o ubsan_create_bench -lm
ubsan_comprehensive_bench:
	$(CC) $(CFLAGS) $(UBSAN_FLAGS) $(BENCH_SRC) $(COMPREHENSIVE_BENCH_TESTS) -o ubsan_comprehensive_bench -lm

ubsan_bench:ubsan_add_bench ubsan_sub_bench ubsan_scale_bench ubsan_setval_bench ubsan_print_bench ubsan_normdist_bench ubsan_mannorm_bench ubsan_eucnorm_bench ubsan_eucdist_bench ubsan_dot_bench ubsan_create_bench ubsan_comprehensive_bench
	./ubsan_add_bench
	./ubsan_sub_bench
	./ubsan_scale_bench
	./ubsan_setval_bench
	./ubsan_print_bench
	./ubsan_normdist_bench
	./ubsan_mannorm_bench
	./ubsan_eucnorm_bench
	./ubsan_eucdist_bench
	./ubsan_dot_bench
	./ubsan_create_bench
	./ubsan_comprehensive_bench

ubsan_all:ubsan_basic ubsan_edge ubsan_math 
	./ubsan_basic
	./ubsan_edge
	./ubsan_math