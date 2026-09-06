BASIC_CC = gcc

BASIC_CFLAGS = -IC/INCLUDE -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

BASIC_SRC = C/src/Vector/vector.c C/Unity/src/unity.c

BASIC_TEST_SRC = C/tests/vector_test/basic/test_basic.c C/tests/vector_test/basic/test_basic_runner.c

BASIC_TARGET = basic_test

basic:
	$(BASIC_CC) $(BASIC_SRC) $(BASIC_TEST_SRC) $(BASIC_CFLAGS) -o $(BASIC_TARGET)


basic_run:
	./$(BASIC_TARGET)

