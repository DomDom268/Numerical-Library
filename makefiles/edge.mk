CC = gcc

CFLAGS = -IC/INCLUDE -IC/Unity/src

SRC = C/src/vector.c C/Unity/src/unity.c

TEST_SRC = C/tests/vector_test/edge/test_edge.c C/tests/vector_test/edge/test_edge_runner.c

TARGET = edge

edge:
	$(CC) $(SRC) $(TEST_SRC) $(CFLAGS) -o $(TARGET)


edge_run:
	./$(TARGET)