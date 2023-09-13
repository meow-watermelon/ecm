CC = gcc
CFLAGS = -Wall -Iecm -g

SOURCES = test.c ecm/ecm_math.c ecm/ecm_string.c
OBJECTS = $(SOURCES:.c=.o)

all: test

test: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJECTS) test
