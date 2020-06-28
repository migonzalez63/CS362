/* Utility file that implements a Nim_Game instance.*/

#include <stdlib.h>
#include "Nim_Game.h"

#define FALSE 0

/* Creates a node that we will store into our winning table */
struct node* createTableNode()
{
  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  newNode -> visited = FALSE;
  newNode -> winFlag = FALSE;

  return newNode;
}

/* Creates an instance of a nim game with a specified size and allowed moves */
struct NimGameInst* createNimGameInst(int size, int moveSize, int allowedMoves[])
{
  int i;
  struct NimGameInst* newNimGame = (struct NimGameInst*) malloc(sizeof(struct
								       NimGameInst));
  newNimGame -> size = size;
  newNimGame -> allowedMoves = allowedMoves;
  newNimGame -> moveSize = moveSize;
  newNimGame -> winningTable = malloc(sizeof(struct node)*size);;
  for(i = 0; i <= size; i++)
    {
      newNimGame -> winningTable[i] = *createTableNode();
    }
  
  return newNimGame;
}

