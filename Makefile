.PHONY: clean

CFLAGS=-Wall -std=gnu11
LDFLAGS=-lpthread

all: server client

chatroom.o: chatroom.c chatroom.h common.h

common.o: common.c common.h

server.o: server.c chatroom.h common.h

server: server.o chatroom.o common.o

client.o: client.c common.h

client: client.o common.o 

clean:
	rm -rf *.o
	rm -rf server client

realclean: clean
	rm -rf *~
