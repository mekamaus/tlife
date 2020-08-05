CC=gcc
CFLAGS=-Werror

# here I don't feel like learning how makefiles work yet, so I'm writing a
# bunch of commands out the long way
run: src/app
	@[ -d bin ] && $(RM) -rf bin; mkdir bin; $(CC) -o bin/app src/app.c && bin/app

build: src/app
	@[ -d bin ] && $(RM) -rf bin; mkdir bin; $(CC) -o bin/app src/app.c

clean:
	@[ -d bin ] && $(RM) -rf bin

