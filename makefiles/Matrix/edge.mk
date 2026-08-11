MEDGE_CC = gcc

MEDGE_CFLAGS = -IC/INCLUDE -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

MEDGE_SRC = C/src/matrix.c C/Unity/src/unity.c

MEDGE_TEST_SRC = C/tests/matrix_test/edge/test_edge.c C/tests/matrix_test/edge/test_edge_runner.c

MEDGE_TARGET = matrix_edge

mat_edge:
	$(MEDGE_CC) $(MEDGE_SRC) $(MEDGE_TEST_SRC) $(MEDGE_CFLAGS) -o $(MEDGE_TARGET)


mat_edge_run:
	./$(MEDGE_TARGET)