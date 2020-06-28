Miguel Gonzalez
CS 362

Issues:
     - Program crashes when any of the inputs is anything but a positive integer.

Part 1A:
      - Folder HW1_A contains Nim_Game.h, Nim_Game.c, isWinning.c, trancript_1A, and a Makefile.
      - Nim_Game contains the struct for an instance of a Nim game and a node
        for each value in the pile size that has information to whether the
        current position is winning or not.
      - Included in the .zip, there is a MakeFile that will compile the code
        with the necessary instruction
            - Use instruction make IsWinning: will create an executable output
	      file named IsWinning
      - If you wish to compile this part of the code by yourself, use
        gcc -std=c99 -pedantic -g -o IsWinning Nim_Gamee.c isWinning.c
      - In order to run the program, you will need to type
        ./IsWinning (pile size) (allowed moves)
            - Pile size can be any positive integer.
	    - Allowed moves can be any positive integer seperated by a space and must be in ascending order.

 Part 1B:
      - Folder HW1_B contains Nim_Game.h, Nim_Game.c, Nim.c, trsnscript_1B.txt, and a Makefile
      - Nim_Game remains the same as in HW1_A
      - In order to compile the code, please use make Nim.
      	    - Will generate an executable output file named Nim
      - In order to run the program, you will need to type ./Nim
      	    - The game has a simple command line UI and should to input:
	      	  1. Size of pile (Has to be positive integer)
		  2. Allowed Moves (Has to be positive integer and in ascending order)
	
 Part 2A:
      -Folder HW1_C contains periodicity.c Nim_Game.g, Nim_Game.c, and a Makefile
      -Nim_Game was changed to contain a nimber.
      - In order to compile code, please use make Period
      	   - Will compile an executable output called Period
      - In order to run the program, you will need to type ./Period (allowed Moves)
      -Issues: The program finds the biggest possible periodicitt, but cannot
      	       reduce the size of the period. Works sometimes, but fails most
	       of the time. Could not find out how to get the period through
	       just nimbers.

