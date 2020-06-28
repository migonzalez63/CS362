#ifndef NIM_GAME_H
#define NIM_GAME_h



struct node
{
  int visited;
  int winFlag;
  int nimber;
};

struct NimGameInst
{
  int size;
  struct node* winningTable;
  int* allowedMoves;
  int moveSize;
};

/* Creates a node that we will store into our winningTable */
struct node* createTableNode();

/* Creates an instance of a Nim Game with a specefied size and allowed moves */
struct NimGameInst* createNimGameInst(int size, int moveSize, int allowedMoves[]);

#endif
