dCC=gcc
CFLAGS=-c

AR=ar
AR_FLAGS=r

SOURCES=Proj2B.c Proj2B_driver.c
OBJECTS=$(SOURCES:.c=.o)

lib: $(OBJECTS)
	mkdir ./lib
	mkdir ./include
	ar r libProj2B.a $(OBJECTS)
	cp libProj2B.a ./lib
	cp prototypes.h ./include

Proj2B_driver.o: Proj2B_driver.c
	$(CC) $(CFLAGS) ./Proj2B_driver.c -I./
Proj2B.o: Proj2B.c
	$(CC) $(CFLAGS) ./Proj2B.c -I./
