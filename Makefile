CC = gcc

CFLAGS = -IC/include 

UFLAGS = -IC/Unity/src

UNITY_SRC = C/Unity/src/unity.c

SRC = C/src/vector.c C/src/benchmark.c 

TEST_SRC = C/tests/vector_test/benchmarks/create_bench.c 

TEST_MATH_SRC = C/tests/vector_test/mathematical/test_math.c C/tests/vector_test/mathematical/test_math_runner.c

TARGET = benchmarks

MATH_TARGET = math

bench:
	$(CC) $(SRC) $(TEST_SRC) $(CFLAGS) -o $(TARGET)


math:
	$(CC) $(UNITY_SRC) $(SRC) $(TEST_MATH_SRC) $(CFLAGS) $(UFLAGS) -DUNITY_INCLUDE_DOUBLE -o $(MATH_TARGET)


run:
	./$(TARGET)


clean:
	rm -f $(TARGET)
