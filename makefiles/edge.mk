EDGE_CC = gcc

EDGE_CFLAGS = -IC/INCLUDE -IC/Unity/src -DUNITY_INCLUDE_DOUBLE

EDGE_SRC = C/src/vector.c C/Unity/src/unity.c

EDGE_TEST_SRC = C/tests/vector_test/edge/test_edge.c C/tests/vector_test/edge/test_edge_runner.c

EDGE_TARGET = edge

edge:
	$(EDGE_CC) $(EDGE_SRC) $(EDGE_TEST_SRC) $(EDGE_CFLAGS) -o $(EDGE_TARGET)


edge_run:
	./$(EDGE_TARGET)