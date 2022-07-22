#include<stdio.h>
#include<stdlib.h>


struct pilha{
  int topo;
  char string[21];
};
typedef struct pilha Pilha;

// Protótipos de função
Pilha* criar(Pilha *p);
void push(Pilha *p, char x);
char top (Pilha *p);
void pop(Pilha *p);
int estaVazia(Pilha *p);


int main(){
  Pilha *pilha = criar(pilha);
  push(pilha, 'A');
  push(pilha, 'B');
  push(pilha, 'C');
  pop(pilha);
  // char string[5];
  // fgets(string, 5, stdin);
  
  // for(int i=0; p -> string[i] != '\0'; i++){
  // printf("\n%c", p -> string[p -> topo]);
  // }
  
  printf("\n%c", top(pilha));
  printf("\n");
}

// Cria Pilha vazia
Pilha* criar(Pilha *p){
  p = (Pilha*) malloc(sizeof(Pilha));
  p -> topo = -1;
  return p;
}

// Insere novo elemento na pilha
void push(Pilha *p, char x){
  p -> topo++;
  p -> string[p -> topo] = x;
}

// Mostra elemento do topo da pilha
char top (Pilha *p){
  return (p -> string[p -> topo]);
}

// Remove elemento do topo da pilha
void pop(Pilha *p){
  if(estaVazia(p)){
    printf("\n--Pilha Vazia--\n");
    return;
  }
  p -> string[p -> topo] = '\0';
  p -> topo--;
}

// Verifica se a pilha está vazia
int estaVazia(Pilha *p){
  if(p -> topo == -1){
    return 1;
  }
  return 0;
}

