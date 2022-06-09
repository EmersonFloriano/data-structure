#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;

struct node{
  int data;
  Node *next;
};

Node* create(){
  return NULL;
}

Node* insert(Node *list, int data){
  Node *temp = (Node *) malloc(sizeof(Node));

  if(temp == NULL){
    free(list);
    exit(0);
  }

  temp -> data = data;
  temp -> next = list;

  return temp;
}

void read(Node* list){

  Node *invert = create();

  for(Node *i = list; i != NULL; i = i -> next){
    // printf("%d ", i -> data);
    invert = insert(invert, i -> data);
  }
  printf("\n");
  for(Node *i = invert; i != NULL; i = i -> next){
    printf("%d ", i -> data);
  }
  printf("\n");
}

int main(){
  Node *list = create();
  
  list = insert(list, 5);
  list = insert(list, 12);
  
  read(list);
}

