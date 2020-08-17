CC=gcc
CFLAGS=-Werror

# here I don't feel like learning how makefiles work yet, so I'm writing a
# bunch of commands out the long way
run:
	$(RM) -r bin
	mkdir bin
	$(CC) -Wall src/main.c src/block.c src/cell.c src/block_visual.c src/color.c src/controls.c src/map.c src/map_io.c src/player.c src/screen.c src/map_visual.c src/bool.c src/shape.c src/player_visual.c src/terminal.c src/window.c src/player_io.c src/game.c src/constants.c src/frame.c src/player_movement.c src/player_target.c -o bin/app
	bin/app

build:
	[ -d bin ] && $(RM) -rf bin
	mkdir bin
	$(CC) -Wall src/main.c src/block.c src/cell.c src/block_visual.c src/color.c src/controls.c src/map.c src/map_io.c src/player.c src/screen.c src/map_visual.c src/bool.c src/shape.c src/player_visual.c src/terminal.c src/window.c src/player_io.c src/game.c src/constants.c src/frame.c src/player_movement.c src/player_target.c -o bin/app

clean:
	[ -d bin ] && $(RM) -rf bin

