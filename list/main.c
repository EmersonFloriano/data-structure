#include<stdio.h>
#include<stdlib.h>

int main(){
  int *list = (int *) malloc(sizeof(int) * 3);
  int *tmp = (int *) malloc(sizeof(int) * 4);

  if(list == NULL){
    return 1;
  }

  list[0] = 1;
  list[1] = 2;
  list[2] = 3;

  for(int i = 0; i < 3; i++){
    printf("\n%d", list[i]);
  }
  
  /* 
    Copia valores da lista antiga para nova
    aumentando sua capacidade.
  */

  printf("\nNova Lista");

  if(tmp == NULL){
    free(list);
    return 1;
  }

  for(int i = 0; i < 3; i++){
    tmp[i] = list[i];
  }

  free(list);
  list = tmp;

  list[3] = 77;
  
  for(int i = 0; i < 4; i++){
    printf("\n%d", list[i]);
  }

  printf("\n");

  free(list);
}