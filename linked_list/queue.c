#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node Node;
typedef struct list List;

struct node {
  int data;
  Node *next;
};

struct list {
  Node *head;
};

void create(List *list) {
  static int password = 1;

  Node* temp = (Node *) malloc(sizeof(Node));
  Node *end = NULL;

  if(list -> head == NULL){
    temp -> data = password; 
    temp -> next = NULL;
    list -> head = temp;
    password++;
    return;
  }

  for(Node* i = list -> head; i != NULL; i = i -> next){
    if(i -> next == NULL){
      end = i;
      break;
    }
  }

  temp -> data = password; 
  temp -> next = NULL;
  end -> next = temp;

  password++;
}

int attend(List *list){
  static int count = 0;
  Node *temp = (Node *) malloc(sizeof(Node));
  
  if(list -> head == NULL){
    printf("Não ha pessoas a serem atendidas\n");
    free(temp);
    return count;
  }

  printf("Pessoa com seguinte senha sera atendida: %d\n", list -> head -> data);
  
  temp = list -> head -> next;
  free(list -> head);
  list -> head = temp;

  return ++count;
}

void show(List *list){
  int count = 0;

  printf("Senhas de pessoas a serem atendidas: [ ");
  
  for(Node *i = list -> head; i != NULL; i = i -> next){
    printf("%d ", i -> data);
    count++;
  }

  printf("]\nQuantidade a ser atendida: %d\n", count);
}

void show_waiting(int count){
  printf("Pessoas que foram atendidas: %d\n", count);
}
    
int main() {
  List *list = (List *)malloc(sizeof(List));
  list -> head = NULL;

  int op = 0;
  int count = 0;

  while (1) {
    printf(
      "\n--------------\n"
      "\n1 - Gerar senha"
      "\n2 - Atender pessoa "
      "\n3 - Visualizar fila "
      "\n4 - Consultar atendimentos realizados"
      "\n5 - Sair");
    printf("\n\nInforme a opcao: ");
    scanf("%d", &op);

    if (op == 5) {
      break;
    }
    if (op == 1) {
      system("clear");
      create(list);
    }
    if (op == 2) {
      system("clear");
      count = attend(list);
    }
    if (op == 3) {
      system("clear");
      show(list);
    }
    if (op == 4) {
      system("clear");
      show_waiting(count);
    }
  }

  while(list -> head != NULL){
    Node *temp = list -> head -> next;
    free(list -> head);
    list -> head = temp;
  }
  free(list);
}
