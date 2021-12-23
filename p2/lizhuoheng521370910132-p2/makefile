all: main

main: main.c checkcard.c demomode.c distribute.c drawcard.c help.c initialize.c printcard.c printcards.c shuffle.c usecard.c clearscreen.c
	gcc main.c checkcard.c demomode.c distribute.c drawcard.c help.c initialize.c printcard.c printcards.c shuffle.c usecard.c clearscreen.c -o main -O2 -Werror -Wall -Wextra -Wconversion -Wvla -Wpedantic

clean:
	rm -f main