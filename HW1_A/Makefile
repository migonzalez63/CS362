all: IsWinning NimGame

clear: rm NimGame IsWinning

IsWinning: Nim_Game.h Nim_Game.c isWinning.c
	gcc -std=c99 -pedantic -g -o IsWinning Nim_Game.c isWinning.c

Nim: Nim_Game.h Nim_Game.c Nim.c
	gcc -std=c99 -pedantic -g -o Nim Nim_Game.c Nim.c
