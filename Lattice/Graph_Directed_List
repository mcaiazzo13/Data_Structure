//-----------------------------------------------------GRAPH DIRECTED WITH LIST-------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int num;
//-----------------------------------------------------STRUCT NODE-----------------------------------------------------
struct node{
  int info;
  struct node *pNext;
} node;
typedef struct node *Node;

void makeGrafph(Node graph[]);
void insertLink(Node graph[],Node node,int index);
void print(Node node);

int verify(Node node,int info);

//----------------------------------------------------- MAKE GRAPH-----------------------------------------------------
void makeGraph(Node graph[]){
  Node ptr;
  int i,info;
  for(i=0;i<num;i++){
    printf("insert info : ");
    scanf("%d",&info);
    ptr = calloc(1,sizeof(node));
    ptr->info = info;
    graph[i] = ptr;
  }
}
//----------------------------------------------------- INSERT LINK-----------------------------------------------------
void insertLink(Node graph[],Node node,int index){
  Node ptr;
  int i,info,choice;
  do{
    printf("Insert link to %d :\n",graph[index]->info);
    scanf("%d",&info);
    for(i=0;i<num;i++){
      if(graph[i]->info == info){
        ptr = calloc(1,sizeof(node));
        ptr->info = info;
        node->pNext = ptr;
        node = ptr;
        i = num;
      }
    }
    printf("\n0 -> Keep insert \t 1 -> Quit insert \n");
    scanf("%d",&choice);
  }while(choice != 1);
}
//----------------------------------------------------- VERIFY-----------------------------------------------------
int verify(Node node,int info){
  if(node == NULL)
    return 0;
  else if(node->info == info)
    return 1;
  else
    return verify(node->pNext,info);
}
//----------------------------------------------------- PRINT-----------------------------------------------------
void print(Node node){
  while(node != NULL){
    printf("\t%d ->",node->info);
    node = node->pNext;
  }
  printf("\tNULL");
}
//----------------------------------------------------- MAIN-----------------------------------------------------
int main(int argc,char *argv[]){
  if(argc < 2){
    printf("Insert number of nodes.\n");
    exit(1);
  }
  int i;
  num = atoi(argv[1]);

  Node graph[num];
  for(i=0;i<num;i++)
    graph[i] = calloc(1,sizeof(Node));
  
  makeGraph(graph);

  for(i=0;i<num;i++)
    insertLink(graph,graph[i],i);

  sleep(1);
  for(i=0;i<num;i++){
    printf("\n");
    print(graph[i]);
  }
  return 0;
}
