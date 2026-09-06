MBASIC_CC = gcc

MBASIC_CFLAGS = -IC/include -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

MBASIC_SRC = C/src/Matrix/matrix.c C/Unity/src/unity.c

MBASIC_TEST_SRC = C/tests/matrix_test/basic/test_basic.c C/tests/matrix_test/basic/test_basic_runner.c

MBASIC_TARGET = mat_basic

mat_basic: 
	$(MBASIC_CC) $(MBASIC_SRC) $(MBASIC_TEST_SRC) $(MBASIC_CFLAGS) -o $(MBASIC_TARGET)

mat_basic_run:
	./$(MBASIC_TARGET)
