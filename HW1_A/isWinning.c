#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Nim_Game.h"

#define TRUE 1
#define FALSE 0

/* Method that runs a version of the game with a set amount of pile size and
   allowed moves in order to determine if the starting pile size will result in
   a win or loss for the person that goes first. 
*/
int isWinning(struct NimGameInst* nimGame, int start)
{
  int next;
  int i;

  /* Base Cases: If equal to zero, player can't move, thus a loss
                 If pile size is negative, that is an illegal move,
		 In order to prevent the algorithm choosing those values,
		 we set all negative numbers to true.                     
  */
  if(start == 0)
    {
      return FALSE;
    }
  if(start < 0)
    {
      return TRUE;
    }

  /* Recursively iterates through every value with the set amount of moves and checks
     is the next position is winning or losing, and saves the current position result
     in a table. After a position is discovered, we will mark it as visited in order to
     return the value of the position if we must revisited again 
  */
  if(nimGame -> winningTable[start].visited == FALSE)
    {
      nimGame -> winningTable[start].visited = TRUE;
      for(i = 0; i < nimGame -> moveSize; i++)
	{
	  next = start -(nimGame -> allowedMoves[i]);

	  if(next < 0)
	    {
	      continue;
	    }
	  else
	    {
	      if(isWinning(nimGame, next) == FALSE)
		{
		  nimGame -> winningTable[start].winFlag = TRUE;
		}
	    }
	}
    }
  return nimGame -> winningTable[start].winFlag;
} 


int main(int argc, char *argv[])
{
  int result;
  int i = 0;
  int j = 2;
  int arrSize = argc - 2;
  int moveSize = 0;
  int allowedMoves[arrSize];
  int size = atoi(argv[1]);

  while(argv[j] != NULL)
    {
      allowedMoves[i++] = atoi(argv[j++]);
      moveSize++;
    }

  struct NimGameInst* nimGame = createNimGameInst(size, moveSize, allowedMoves);
  result = isWinning(nimGame, size);
  printf("%d\n", result);

  free(nimGame->winningTable);
  free(nimGame);

  return 0;
}
