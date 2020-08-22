CC=gcc

CFLAGS= \
				-Werror \
				-Wall

# here I don't feel like learning how makefiles work yet, so I'm writing a
# bunch of stuff out the long way
SRC= \
	   src/main.c  \
     src/block.c \
	   src/cell.c \
	   src/block_visual.c \
	   src/color.c \
	   src/control.c \
	   src/map.c \
	   src/map_persistence.c \
	   src/player.c \
	   src/screen.c \
	   src/map_visual.c \
	   src/bool.c \
	   src/shape.c \
	   src/player_visual.c \
	   src/terminal.c \
	   src/window.c \
	   src/player_persistence.c \
	   src/game.c \
	   src/constants.c \
	   src/frame.c \
     src/player_target.c \
	   src/player_building.c \
	   src/init.c \
	   src/loop.c \
	   src/destroy.c \
	   src/vector_math.c \
	   src/control_delta.c \
		 src/time.c

APP=bin/app

run:
	$(RM) -r bin
	mkdir bin
	$(CC) -lcurses $(SRC) -o $(APP)
	bin/app

build:
	$(RM) -r bin
	mkdir bin
	$(CC) -lcurses $(SRC) -o $(APP)

clean:
	$(RM) -r bin

