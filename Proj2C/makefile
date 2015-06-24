CC=gcc
CFLAGS=-c

AR=ar
AR_FLAGS=r

SOURCES=struct.h prototypes.h driver.c
OBJECTS=$(SOURCES:.c=.o)

driver.o: driver.c
	$(CC) $(CFLAGS) ./driver.c -I./
struct.o: struct.h
	$(CC) $(CFLAGS) ./struct.h -I./
prototypes.o: prototypes.h
	$(CC) $(CFLAGS) ./prototypes.h -I./
