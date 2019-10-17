//------------------------------------------------------- TREE WITH QUEUE -------------------------------------------
// n-tree each node has n childs
#include <stdio.h>
#include <stdlib.h>
int num;
//------------------------------------- STRUCT
struct node{
  int info;
  int rank; // number of child
};
typedef struct node Node;

void insertNode(Node Tree[]);
void enqueue(int info, int rank,Node queue[],int *tail);
void dequeue(int *info,int *rank,Node queue[],int *head);

//------------------------------------------------------- INSERT --------------------------------------------------
void insertNode(Node Tree[]){
  int tail = 0, head = 0, rank, i=0,k;
  int info;
  // this is the queue as an array
  Node queue[num];
  // insert ROOT
  printf("Insert node:");
  scanf("%d",&Tree[i].info);
  printf("Insert rank:");
  scanf("%d",&Tree[i].rank);

  // control if the queue is full
  if(tail > num-1){
    printf("\nqueue full\n");
    exit(1);
  }
  
  // insert node in the queue
  enqueue(Tree[i].info,Tree[i].rank,queue, &tail);

  // insert until the queue has at least one element
  while(tail != head){
    // take the firt element
    dequeue(&info,&rank,queue,&head);

    // insert all the child for the extracted element
    for(k=0;k<rank;k++){
      printf("%d figlio di [%d]",k+1,info);
      i++;
      printf("Insert info :");
      scanf("%d",&Tree[i].info);
      printf("Insert rank :");
      scanf("%d",&Tree[i].rank);
      if(tail > num-1){
        printf("Queue full\n");
        exit(1);
      }
      // extract another element
      enqueue(Tree[i].info,Tree[i].rank,queue,&tail);
    }
  }
}
//--------------------------------------------------- DEQUEUE ---------------------------------------------------
void dequeue(int *info,int *rank,Node queue[],int *head){
  *info = queue[*head].info;
  *rank = queue[*head].rank;
  *head+=1;
}
//----------------------------------------------------- ENQUEUE ------------------------------------------------
void enqueue(int info,int rank,Node queue[],int *tail){
  queue[*tail].info = info;
  queue[*tail].rank = rank;
  *tail+=1;
}
//------------------------------------------------------- MAIN -------------------------------------------------
int main(int argc,char *argv[]){
  if(argc < 2){
    printf("Insert number of nodes.\n");
    exit(1);
  }
  num = atoi(argv[1]);
  Node Tree[num];
  insertNode(Tree);
  return 0;
}
