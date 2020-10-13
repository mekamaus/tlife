CC=gcc
CFLAGS=-Wall -lcurses -lpthread -std=c++17
SRC=src/*.cc
APP=bin/app
APP_DEBUG=bin/a.out

run:
	$(RM) -r bin
	mkdir bin
	$(CC) $(CFLAGS) $(SRC) -o $(APP)
	bin/app

build:
	$(RM) -r bin
	mkdir bin
	$(CC) $(CFLAGS) $(SRC) -o $(APP)

build_debug:
	$(RM) -r bin
	mkdir bin
	$(CC) $(CFLAGS) $(SRC) -o $(APP_DEBUG)

clean:
	$(RM) -r bin

