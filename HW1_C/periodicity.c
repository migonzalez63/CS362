#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Nim_Game.h"

#define TRUE 1
#define FALSE 0

int isWinning(struct NimGameInst* nimGame, int start)
{
  int next;
  int i;
  if(start < 0)
    {
      return TRUE;
    }
  if(start == 0)
    {
      nimGame -> winningTable[start].winFlag = FALSE;
      return FALSE;
    }

  if(nimGame -> winningTable[start].visited == FALSE)
    {
      nimGame -> winningTable[start].visited = TRUE;
      for(i = 0; i < nimGame -> moveSize; i++)
	{
	  next = start - (nimGame -> allowedMoves[i]);

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

/* Finds the minimum excluded integer in a set */
int mex(int nimber[], int nimbSet[], int size)
{
  int i;
  int j;
  int smallest;
  int missingFlag = TRUE;

  for(i = 0; i <= size; i++)
    {
      for(j = 0; j < size; j++)
	{
	  if(nimbSet[j] == nimber[i])
	    {
	      missingFlag = FALSE;
	      break;
	    }
	  else
	    {
	      missingFlag = TRUE;
	    }
	}

      if(missingFlag == TRUE)
	{
	  smallest = nimber[i];
	  break;
	}
    }

  return smallest;
}

/* Calculates the nimber for the nimGame winningTable */
int calculateNimber(struct NimGameInst* nimGame, int n, int nimber[])
{
  int i;
  int nimbSet[nimGame -> moveSize];
  
  if(n < 0)
    {
      return 1000;
    }
  if(nimGame -> winningTable[n].nimber != -1)
    {
      return nimGame -> winningTable[n].nimber; 
    }

  
  for(i = 0; i < nimGame -> moveSize; i++)
    {
      nimbSet[i] = calculateNimber(nimGame , n - (nimGame -> allowedMoves[i]), nimber);
    }

  
  nimGame -> winningTable[n].nimber = mex(nimber, nimbSet, nimGame -> moveSize);
  
  return nimGame -> winningTable[n].nimber;  
}

/* Finds the period of a given Nim Game Instance */
void findPeriod(struct NimGameInst* nimGame)
{
  int i = 0;
  int j;
  int start = 0;
  int maxPeriod = 0;
  int matchFlag = FALSE;
  int offset = 0;
  int maxMove = nimGame -> allowedMoves[nimGame -> moveSize - 1];
  int period = 1;
  struct node* firstSeq = NULL;
  struct node* secondSeq = NULL;
  maxPeriod = 1 + pow(2, maxMove);
  secondSeq = &nimGame -> winningTable[maxPeriod];

  for(i = 0; i < maxPeriod; i++)
    {
      firstSeq = &nimGame -> winningTable[i];
      for(j = 0; j < period; j++)
	{
	  if(firstSeq[j].nimber == secondSeq[j].nimber)
	    {
	      matchFlag = TRUE;
	    }
	  else
	    {
	      break;
	    }
	}
      
      if(matchFlag == FALSE)
	{
	  offset = i;
	  continue;
	}

      period++;
    }

  printf("The period is %d \n", period);
  printf("The sequence is: ");
  while(start < period)
    {
      printf("%d ", nimGame -> winningTable[start].winFlag);
      start++;
    }
  printf("\n");
} 

int main(int argc, char *argv[])
{
  int period = 0;
  int nimber = 0;
  int result = 0;
  int i = 0;
  int j = 1;
  int arrSize = argc - j;
  int moveSize = 0;
  int allowedMoves[arrSize];

  while(argv[j] != NULL)
    {
      allowedMoves[i++] = atoi(argv[j++]);
      moveSize++;
    }

  struct NimGameInst* nimGame = createNimGameInst(10000, moveSize, allowedMoves);
  result = isWinning(nimGame, 8);

  int nimbSet[moveSize + 1];

  for(i = 0; i <= moveSize; i++)
    {
      nimbSet[i] = i;
    }

  nimber = calculateNimber(nimGame, nimGame -> size - 1, nimbSet);
  findPeriod(nimGame);
  
  free(nimGame);

  return 0;
}
