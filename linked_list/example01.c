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

void show(List *list){
  printf("\n[ ");

  for(Node *i = list -> head; i != NULL; i = i -> next){
    printf("%d ", i -> data);
  }

  printf("]\n");
}

int show_qtd(List *list){
  int count = 0;
  for(Node *i = list -> head; i != NULL; i = i -> next){
    count++;
  }
  return count;
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
  Node* temp = (Node *) malloc(sizeof(Node));
  Node *end = NULL;

  if(list -> head == NULL){
    temp -> data = data; 
    temp -> next = NULL;
    list -> head = temp;
    return;
  }

  for(Node* i = list -> head; i != NULL; i = i -> next){
    if(i -> next == NULL){
      end = i;
      break;
    }
  }

  temp -> data = data; 
  temp -> next = NULL;
  end -> next = temp;
}

void insert_after(List *list, int data, int pos){
  int j = 0;
  Node* temp = (Node *) malloc(sizeof(Node));

  temp -> data = data;

  for(Node* i = list -> head; i != NULL; i = i -> next){
    if(j == pos){
      temp -> next = i -> next;
      i -> next = temp;
      break;
    }
    j++;
  }
}

void delete_first(List *list){
  Node *temp = list -> head;
  list -> head = temp -> next;
  free(temp);
}

void delete_N(List *list, int data){
  int j = 0;
  Node *temp = (Node *) malloc(sizeof(Node));

  temp -> data = data;

  if(list -> head == NULL){
    return;
  }
  if(list -> head -> data == data){
    temp = list -> head;
    list -> head = list -> head -> next;
    free(temp);
    return;
  }

  for(Node* i = list -> head; i != NULL; i = i -> next){
    if(data == i -> next -> data){
      temp = i -> next;
      i -> next = i -> next -> next;
      free(temp);
      break;
    }
    j++;
  }
}

void find(List *list, int data){
  int pos = 0;

  for(Node* i = list -> head; i != NULL; i = i -> next){
    if(data == i -> data){
      printf(
        "\n------"
        "\nposicao na lista: %d"
        "\nvalor: %d"
        "\nendereco: %p"
        "\n------\n",
        pos,
        i -> data,
        i
      );
      break;
    }
    pos++;
  }
}

int main(){
  int op = -1, created = 0;
  List *list = NULL;

  while(op != 9){
    printf(
      "\n0 - Criar"
      "\n1 - Exibir"
      "\n2 - Exibir qtd elementos"
      "\n3 - Inserir no inicio"
      "\n4 - Inserir no final"
      "\n5 - Inserir apos N"
      "\n6 - Deletar do inicio"
      "\n7 - Deletar N"
      "\n8 - Procurar elemento"
      "\n9 - Sair"
    );
    printf("\n\nInforme a opcao: ");
    scanf("%d", &op);

    if(op == 9) break;
    if(op == 0){
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
      if(op == 1){
        show(list);
      }
      if(op == 2){
        printf("\n-- %d --\n", show_qtd(list));
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
        int data = 0, pos = -1;
        printf("\nInforme o valor e a posicao(0 ... N): ");
        scanf("%d %d", &data, &pos);
        insert_after(list, data, pos);
      }
      if(op == 6){
        delete_first(list);
      }
      if(op == 7){
        int data = 0;
        printf("\nInforme o valor: ");
        scanf("%d", &data);
        delete_N(list, data);
      }
      if(op == 8){
        int data = 0;
        printf("\nInforme o valor: ");
        scanf("%d", &data);
        find(list, data);
      }
    }
    
  }
}

