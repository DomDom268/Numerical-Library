CC = gcc
CLANG = clang

CFLAGS = -IC/include -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

ASAN_FLAGS = -g -fsanitize=address -fno-omit-frame-pointer

SRC = C/src/vector.c C/Unity/src/unity.c C/src/benchmark.c

TEST_SRC = C/tests/vector_test/basic/test_basic.c C/tests/vector_test/basic/test_basic_runner.c 

TARGET = asan_test

asan:
	$(CLANG) $(SRC) $(TEST_SRC) $(CFLAGS) $(ASAN_FLAGS) -o $(TARGET)

asan_run:
	./$(TARGET)

