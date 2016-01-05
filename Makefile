PLATFORM=$(shell uname)
CC = gcc

CFLAGS = -c -O3 -Wall
LIBS = 
LDFLAGS = -O3 -Wall $(LIBS)

BIN = test
OBJS = test.o \
       proc.o

all : $(BIN)

$(BIN): $(OBJS)
	$(CC) -o $@ $^ $(LDFLAGS) 

$(OBJS) : %.o : %.c
	$(CC) -o $@ $(CFLAGS) $<

clean : 
	rm -f $(OBJS) $(BIN)

.PHONY : clean

