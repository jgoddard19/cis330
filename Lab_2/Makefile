#I am a comment
CC=gcc
#Set c flag
CFLAGS=-g
INSTALL_DIR=~/330/multiplier

AR=ar
AR_FLAGS=r

SOURCES=doubler.c tripler.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=better_multiplier


all:example_multiplier

example_multiplier:lib
	$(CC) -o $(EXECUTABLE) t.c -I$(shell pwd)/multiplier/include -L$(shell pwd)/multiplier/lib -lmultiplier

lib: $(OBJECTS)
	$(AR) $(AR_FLAGS) libmultiplier.a $(OBJECTS)
	cp libmultiplier.a $(INSTALL_DIR)/lib
	cp multiplier.h $(INSTALL_DIR)/include

.c.o:
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf *o $(EXECUTABLE)  #You can clean more if you want