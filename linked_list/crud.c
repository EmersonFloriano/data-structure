#include<stdio.h>
#include<stdlib.h>

typedef struct node Node;
typedef struct list List;

struct node{
  int data;
  Node *next;
};

struct list{
  Node *head;
};

List* create(void){
  List *list = (List *) malloc(sizeof(List));
  list -> head = NULL;

  return list;
}

void insert_begin(List *list, int data){
  Node *temp = (Node *) malloc(sizeof(Node));

  if(temp == NULL){
    free(list);
    exit(0);
  }

  temp -> data = data;
  temp -> next = list -> head;

  list -> head = temp;
}

void insert_end(List *list, int data){
  Node *end = NULL;
  for(Node* i = list -> head; i != NULL; i = i -> next){
    if(i -> next == NULL){
      end = i;
      break;
    }
  }

  Node* temp = (Node *) malloc(sizeof(Node));
  temp -> data = data; 
  temp -> next = NULL;
  end -> next = temp;
}

void read(List *list){
  printf("\n[ ");

  for(Node *i = list -> head; i != NULL; i = i -> next){
    printf("%d ", i -> data);
  }

  printf("]\n");
}

void delete_first(List *list){
  Node *temp = list -> head;
  list -> head = temp -> next;
  free(temp);
}

int main(){
  int op = 0, created = 0;
  List *list = NULL;

  while(op != 9){
    printf("\n1 - Criar"
      "\n2 - Imprimir"
      "\n3 - Inserir no inicio"
      "\n4 - Inserir no final"
      "\n5 - Deletar do inicio"
      "\n9 - Sair"
    );
    printf("\n\nInforme a opcao: ");
    scanf("%d", &op);

    if(op == 9) break;
    if(op == 1){
      list = create();
      created = 1;
    }
    else if(!created){
      printf(
        "\n-- A lista deve ser criada "
        "antes de qualquer operacao! --\n"
      );
    }
    else{
        if(op == 2){
        read(list);
      }
      if(op == 3){
        int data = 0;
        printf("\nInforme o valor: ");
        scanf("%d", &data);
        insert_begin(list, data);
      }
      if(op == 4){
        int data = 0;
        printf("\nInforme o valor: ");
        scanf("%d", &data);
        insert_end(list, data);
      }
      if(op == 5){
        delete_first(list);
      }
      if(op == 6){

      }
      if(op == 7){
        
      }
      if(op == 8){
        
      }
    }
    
  }
}

