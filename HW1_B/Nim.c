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

/* Method that runs the game until completion against a computer player.
   Will will take a Nim Game instance and play the game with knowledge 
   of what the best move is. Computer player will always choose the largest possible
   move.
*/
void startGame(struct NimGameInst* nimGame, int size, int computerFlag)
{
  int i = 0;
  int remaining = size;
  int best = 0;
  int illegalFlag = TRUE;
  int noMoveFlag = TRUE;

  /* If there is nothing to take away from the pile, the game is over and 
     the current player has lost */
  if(size <= 0)
    {
      if(computerFlag == TRUE)
	{
	  printf("Player has won!\n");
	  return;
	}
      else
	{
	  printf("Computer has won!\n");
	  return;
	}
    }

  /* Algorithm for Computer player. Iterates through every move and looks at where that
     move would land them in the table. If the position is losing for the next player, 
     it will choose it. Otherwise, it will discard that move and move on to the next.
     Will always choose the biggest move possible. */
  if(computerFlag == TRUE)
    {
      printf("%d remaining. \n", remaining);
      printf("Computer's Turn! ");
      printf("How many will you take?\n");
      for(i = 0; i < nimGame -> moveSize; i++)
	{
	  remaining = size - (nimGame -> allowedMoves[i]);
	  if(remaining >= 0)
	    {
	      noMoveFlag = FALSE;
	    }
	  else
	    {
	      break;
	    }

	  if(nimGame -> winningTable[remaining].winFlag == FALSE)
	    {
	      best = nimGame -> allowedMoves[i];
	    }
	  
	  remaining = size;
	}

       if(noMoveFlag == TRUE)
	    {
	      printf("Computer cannot move! ");
	      printf("Player Wins!\n");
	      return;
	    }

      remaining = size - best;
      printf("Computer took %d!\n\n", best);
      computerFlag = FALSE;
    }
  else
    {
      printf("%d remaining. \n", remaining);
      printf("Player's Turn! ");
      printf("How many will you take?\n");
      while(illegalFlag == TRUE)
	{
	  scanf("%d", &best);
	  for(i = 0; i < nimGame -> moveSize; i++)
	    {
	      if(best == (nimGame -> allowedMoves[i]))
		{
		  illegalFlag = FALSE;
		}
	    }

	  remaining = size - best;
	  if(remaining < 0)
	    {
	      printf("Player cannot move! Computer Wins!\n");
	      return;
	    }

	  if(illegalFlag == FALSE)
	    {
	      break;
	    }
	  printf("Illegal Move! Please choose another number in the allowed");
          printf(" move set!\n");
	}
      remaining = size - best;
      printf("Player took %d!\n\n", best);
      computerFlag = TRUE;
    }

  startGame(nimGame, remaining, computerFlag);
}

int main()
{
  int result;
  int size;
  int moveSize;
  int arr[100];
  char temp;
  int j;
  int computerFlag= TRUE;
  int i = 0;
  

  printf("Welcome to One-Pile Nim.\n");
  printf("What size would you want your pile?\n");
  scanf("%d", &size);
  printf("What will be the allowed moves? (Please seperate by space)\n");

  /* Reads in the arguments for the allowed moves */
  do
    {
      scanf("%d%c", &arr[i], &temp);
      i++;
    } while(temp != '\n');

  moveSize = i;
  int allowedMoves[i];
  
  for(j = 0; j < i; j++)
    {
      allowedMoves[j] = arr[j];
    }

  /* Creates an instance of the Nim game we will play */
  struct NimGameInst* nimGame = createNimGameInst(size, moveSize, allowedMoves);
  result = isWinning(nimGame, size);

  /* If the beginnning position puts the computer player at a disadvantage, we will
     let the player go first, otherwise, the computer will go first */
  if(result == FALSE)
    {
      computerFlag = FALSE;
      startGame(nimGame, size, computerFlag);
    }
  else
    {
      startGame(nimGame, size, computerFlag);
    }
  
  free(nimGame);

  return 0;
}
