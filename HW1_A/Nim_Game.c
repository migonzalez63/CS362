/* Utility file that implement a Nim Game Instance */

#include <stdlib.h>
#include "Nim_Game.h"

#define FALSE 0

/* Creates a node that we will store into our winning Table */
struct node* createTableNode()
{
  struct node* newNode = (struct node*) malloc(sizeof(struct node));
  newNode -> visited = FALSE;
  newNode -> winFlag = FALSE;
 
  return newNode;
}

/* Creates an instance of a Nim Gmae with a specefied size and allowed moves */
struct NimGameInst* createNimGameInst(int size, int moveSize, int allowedMoves[])
{
  int i;
  struct NimGameInst* newNimGame = (struct NimGameInst*) malloc(sizeof(struct
								       NimGameInst));
  newNimGame -> size = size;
  newNimGame -> allowedMoves = allowedMoves;
  newNimGame -> moveSize = moveSize;
  newNimGame -> winningTable = (struct node*) malloc(sizeof(struct node)*size);
  for(i = 0; i < size; i++)
    {
      newNimGame -> winningTable[i] = *createTableNode();
    }
  
  return newNimGame;
}


