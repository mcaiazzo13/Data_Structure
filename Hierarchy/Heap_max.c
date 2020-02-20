//----------------------------------------------------------- MAX HEAP ------------------------------------------------------
// build heap (max-heap)
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int n;

void swap(int a,int b,int *A[]);
int leftSon(int node);
int rightSon(int node);
int parent(int node);

void buildHeap(int *A[]);
void heapify(int *A[],int node); // array, node

//--------------------------------------------------------------  SWAP  --------------------------------------------------
void swap(int x,int y,int *A[]){
  int *temp;
  temp = A[x];
  A[x] = A[y];
  A[y] = temp;
}
//----------------------------------------------------------- FIND LEFT SON ---------------------------------------------
int leftSon(int node){
  return 2*node;
}
//----------------------------------------------------------- FIND RIGHT SON --------------------------------------------
int rightSon(int node){
  return 2*node+1;
}
//----------------------------------------------------------- FIND PARENT------------------------------------------------

int parent(int node){
  return node/2;
}
//----------------------------------------------------------- HEAPIFY ---------------------------------------------------
void heapify(int *A[],int node){
  int i;
  int l,r,max;
  int  m;
  m = n-1;
  l = leftSon(node);
  r = rightSon(node);
  if(l <= m && *A[l] > *A[node]){
    max = l;
  }else{
    max = node;
  }
  if(r <= m && *A[r] > *A[max]){
    max = r;
  }
  if(max != node){
    swap(node,max,A);
    printf("\n");
    for(i=0;i<n;i++)
     printf("%d \t",*A[i]);
    heapify(A,max);
  }
}
//---------------------------------------------- BUILD HEAP FROM DISORDERED ARRAY HEAP ---------------------------------
void buildHeap(int *A[]){
  int i;
  for(i=n/2;i>0;i--){
    heapify(A,i);
  }
}
//------------------------------------------------------------ MAIN ----------------------------------------
int main(int argc, char *argv[]){
  if(argc < 2){
    printf("Write the number of nodes you want in the heap\n");
    exit(1);
  }
  int i;
  n = atoi(argv[1]);
  n = n+1;
  int *A[n]; 
  for(i=0;i<n;i++)
    A[i] = (int*)calloc(1,sizeof(int));

  for(i=1;i<n;i++){
    printf("\nInsert node %d :",i);
    scanf("%d",A[i]);
  }
   sleep(1);
   buildHeap(A);
   printf("\n");
  for(i=0;i<n;i++)
    printf("Node %d\n",*A[i]);
  return 0;
}
