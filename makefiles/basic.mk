CC = gcc

CFLAGS = -IC/INCLUDE -IC/Unity/src

SRC = C/src/vector.c C/Unity/src/unity.c

TEST_SRC = C/tests/vector_test/basic/test_basic.c C/tests/vector_test/basic/test_basic_runner.c

TARGET = basic

basic:
	$(CC) $(SRC) $(TEST_SRC) $(CFLAGS) -o $(TARGET)


basic_run:
	./$(TARGET)

