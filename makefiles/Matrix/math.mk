MMBASIC_CC = gcc

MMBASIC_CFLAGS = -IC/include -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

MMBASIC_SRC = C/src/matrix.c C/Unity/src/unity.c

MMBASIC_TEST_SRC = C/tests/matrix_test/mathematical/test_math.c C/tests/matrix_test/mathematical/test_math_runner.c

MMBASIC_TARGET = mat_math

mat_math: 
	$(MMBASIC_CC) $(MMBASIC_SRC) $(MMBASIC_TEST_SRC) $(MMBASIC_CFLAGS) -o $(MMBASIC_TARGET)

mat_math_run:
	./$(MMBASIC_TARGET)