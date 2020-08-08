CC=gcc
CFLAGS=-Werror

# here I don't feel like learning how makefiles work yet, so I'm writing a
# bunch of commands out the long way
run:
	@[ -d bin ] && $(RM) -rf bin
	mkdir bin
	$(CC) -Wall src/main.c src/block.c src/cell.c src/block_renderer.c src/color.c src/controls.c src/map.c src/map_io.c src/player.c src/screen.c src/map_renderer.c src/bool.c src/shape.c src/player_renderer.c -o bin/app
	bin/app

build:
	@[ -d bin ] && $(RM) -rf bin
	mkdir bin
	$(CC) -Wall src/main.c src/block.c src/cell.c src/block_renderer.c src/color.c src/controls.c src/map.c src/map_io.c src/player.c src/screen.c src/map_renderer.c src/bool.c src/shape.c src/player_renderer.c -o bin/app

clean:
	@[ -d bin ] && $(RM) -rf bin

