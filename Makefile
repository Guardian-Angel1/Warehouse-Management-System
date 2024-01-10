CC = g++
CFLAGS = -Wall -g -w

SOURCES = function.cpp
HEADERS = header.h
EXECUTABLE=run

all: $(EXECUTABLE)

$(EXECUTABLE):$(SOURCES) $(HEADERS)
	$(CC) $(CFLAGS) $^ -o $@
clean:
	rm -f $(EXECUTABLE)
