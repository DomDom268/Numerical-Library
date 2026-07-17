CC = gcc

CFLAGS = -IC/INCLUDE -IC/Unity/src

SRC = C/src/vector.c C/Unity/src/unity.c

TEST_SRC = C/tests/vector_test/mathematical/test_math.c C/tests/vector_test/mathematical/test_math_runner.c

TARGET = math

math:
	$(CC) $(SRC) $(TEST_SRC) $(CFLAGS) -o $(TARGET)


math_run:
	./$(TARGET)