#include <stdio.h>
#include <stdlib.h>

typedef struct node Node;

struct node{
    int data;
    Node *next;
};

int main() {
    
    Node* list = NULL;
    Node *n = (Node *) malloc(sizeof(Node));
    if(n != NULL){
        n -> data = 12;
        n -> next = NULL;
    }
    
    list = n;
    
    n = (Node *) malloc(sizeof(Node));
    if(n == NULL){
        free(list);
        return 1;
    }
    n -> data = 25;
    n -> next = NULL;
    
    list -> next = n;
    
    printf("\n%d", list -> next -> data);
    puts("\n");
    
    free(list);
    free(n);
    
    return 0;
}
