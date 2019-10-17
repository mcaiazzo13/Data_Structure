
//---------------------------------------------------- CIRCLE ARRAY (QUEUE) --------------------------------------------------
#include <stdio.h>
#include <stdlib.h>
int num;
int head;
int tail;
void insert(int *array[]);
void delete(int *array[]);
void print(int *array[]);
int calculateTail(int *array[]);
//---------------------------------------------------  INSERT
void insert(int *array[]){
  int node;
  printf("Insert node :");
  scanf("%d",&node);
  if(head == 0){
    *array[0] = node;
  }else{
    tail = calculateTail(array);
    tail = tail+1;
    *array[tail] = node;
  }
}
//---------------------------------------------------  CALCULATE TAIL
int calculateTail(int *array[]){
  int i;
  for(i=0;i<num;i++){
    if(array[i] == 0)
      return i;
  }
  return num-1;
}
//---------------------------------------------------  DELETE
void delete(int *array[]){
  if(head == num-1 && tail == num-1){
    printf("Array is ended start again.");
    head = 0;
    tail = 0;
  }else{
    *array[head] = 0;
    head = head+1;
  }
}
//---------------------------------------------------  PRINT
void print(int *array[]){
  int i;
  for(i=head;i<num;i++){
    printf("Node %d\n",*array[i]);
  }
}
//--------------------------------------------------- MAIN
int main(int argc, char* argv[]){
  if(argc < 2){
    printf("Insert number of elements.\n");
    exit(1);
  }
  num = atoi(argv[1]);
  int choice,i;
  head = 0;
  tail = 0;
  int *array[num];
  for(i=0;i<num;i++)
    array[i] = calloc(1,sizeof(int));
  do{
    printf("\n1.Insert\n2.Delete\n3.Print\n");
    scanf("%d",&choice);
    switch(choice){
    case 1:
      insert(array);
      break;
    case 2:
      delete(array);
      break;
    case 3:
      print(array);
      break;
     default:
      printf("4 for EXIT.\n");
    }
  }while(choice != 4); 
  return 0;
}
