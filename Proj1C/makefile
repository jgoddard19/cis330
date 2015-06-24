CC=gcc
CFLAGS=-c
INSTALL_DIR=~Proj1C

AR=ar
AR_FLAGS=r

#cli.o: math330.h libmath330.a
	#$(CC) $(CFLAGS) -o cli cli.o -lmath330.h -lm
	#$(CC) $(CFLAGS) -o cli cli.o libmath330.a -L

SOURCES=cos330.c sin330.c tan330.c exp330.c log330.c
OBJECTS=$(SOURCES:.c=.o)

lib: $(OBJECTS)
	mkdir ./
	mkdir ./lib
	mkdir ./include
	$(AR) $(AR_FLAGS) libmath330.a $(OBJECTS)
	cp libmath330.a ./lib
	cp math330.h ./include

cos330.o: cos330.c
	$(CC) $(CFLAGS) ./trig/cos330.c -I./
tan330.o: tan330.c
	$(CC) $(CFLAGS) ./trig/tan330.c -I./
sin330.o: sin330.c
	$(CC) $(CFLAGS) ./trig/sin330.c -I./
exp330.o: exp330.c
	$(CC) $(CFLAGS) ./exp/exp330.c -I./
log330.o: log330.c
	$(CC) $(CFLAGS) ./exp/log330.c -I./
