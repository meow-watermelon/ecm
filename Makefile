CC = gcc
CFLAGS = -g -Wall -Wextra -Wpedantic -Iecm
C_DEBUG_FLAGS = -DDEBUG

SOURCES = test.c ecm/ecm_math.c ecm/ecm_string.c
OBJECTS = $(SOURCES:.c=.o)

LDFLAGS = -static

all: test

test: $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

debug: CFLAGS += $(C_DEBUG_FLAGS)
debug: test

debug-static: CFLAGS += $(C_DEBUG_FLAGS)
debug-static: CFLAGS += $(LDFLAGS)
debug-static: test

clean:
	rm -f $(OBJECTS) test
