CC = gcc
CLANG = clang

CFLAGS = -IC/include -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

ASAN_FLAGS = -g -fsanitize=address -fno-omit-frame-pointer

SRC = C/src/vector.c C/Unity/src/unity.c 

#Test Suites
BASIC_TESTS = C/tests/vector_test/basic/test_basic.c C/tests/vector_test/basic/test_basic_runner.c

EDGE_TESTS = C/tests/vector_test/edge/test_edge.c C/tests/vector_test/edge/test_edge_runner.c

MATH_TESTS = C/tests/vector_test/mathematical/test_math.c C/tests/vector_test/mathematical/test_math_runner.c

BENCH_TESTS = C/src/benchmark.c


#Build each test suite with ASAN enabled
asan_basic:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRC) $(BASIC_TESTS) -o asan_basic -lm

asan_edge:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRC) $(EDGE_TESTS) -o asan_edge -lm

asan_math:
	$(CC) $(CFLAGS) $(ASAN_FLAGS) $(SRC) $(MATH_TESTS) -o asan_math -lm

asan_bench:
	gcc -IC/include -DUNITY_INCLUDE_DOUBLE $(ASAN_FLAGS) C/src/benchmark.c -o asan_bench -lm

#Run all test suites with ASAN enabled
asan_all: asan_basic asan_edge asan_math asan_bench
	./asan_basic
	./asan_edge
	./asan_math
	./asan_bench