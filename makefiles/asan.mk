CC = gcc
CLANG = clang

CFLAGS = -IC/include -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

ASAN_FLAGS = -g -fsanitize=address -fno-omit-frame-pointer

SRC = C/src/vector.c C/Unity/src/unity.c C/src/benchmark.c

#Test Suites
BASIC_TESTS = C/tests/vector_test/basic/test_basic.c C/tests/vector_test/basic/test_basic_runner.c

EDGE_TESTS = C/tests/vector_test/edge/test_edge.c C/tests/vector_test/edge/test_edge_runner.c

MATH_TESTS = C/tests/vector_test/mathematical/test_math.c C/tests/vector_test/mathematical/test_math_runner.c

BENCH_TESTS = C/tests/vector_test/benchmarks/add_bench.c \
C/tests/vector_test/benchmarks/comprehensive_bench.c \
C/tests/vector_test/benchmarks/create_bench.c \
C/tests/vector_test/benchmarks/dot_bench.c \
C/tests/vector_test/benchmarks/eucdist_bench.c \
C/tests/vector_test/benchmarks/eucnorm_bench.c \
C/tests/vector_test/benchmarks/mannorm_bench.c \
C/tests/vector_test/benchmarks/normdist_bench.c \
C/tests/vector_test/benchmarks/print_bench.c \
C/tests/vector_test/benchmarks/scale_bench.c \
C/tests/vector_test/benchmarks/setval_bench.c \
C/tests/vector_test/benchmarks/sub_bench.c \


#Build each test suite with ASAN enabled
asan_basic:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRC) $(BASIC_TESTS) -o asan_basic -lm

asan_edge:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRC) $(EDGE_TESTS) -o asan_edge -lm

asan_math:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRC) $(MATH_TESTS) -o asan_math -lm

asan_bench:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRC) $(BENCH_TESTS) -o asan_bench -lm

#Run all test suites with ASAN enabled
asan_all: asan_basic asan_edge asan_math asan_bench
	./asan_basic
	./asan_edge
	./asan_math
	./asan_bench