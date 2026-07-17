MATH_CC = gcc

MATH_CFLAGS = -IC/INCLUDE -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

MATH_SRC = C/src/vector.c C/Unity/src/unity.c

MATH_TEST_SRC = C/tests/vector_test/mathematical/test_math.c C/tests/vector_test/mathematical/test_math_runner.c

MATH_TARGET = math

math:
	$(MATH_CC) $(MATH_SRC) $(MATH_TEST_SRC) $(MATH_CFLAGS) -o $(MATH_TARGET)


math_run:
	./$(MATH_TARGET)