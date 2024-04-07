#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no* prox;
    struct no* prev;

}No;

void inserir (No** Lista, int valor)
{
    // 1. allocate node
    No* novo = (No*)malloc(sizeof(No));
 
    // 2. put in the data
    novo->valor = valor;
 
    // 3. Make next of new node as head and previous as NULL
    novo->prox = (*Lista);
    novo->prev = NULL;
 
    // 4. change prev of head node to new node
    if ((*Lista) != NULL)
        (*Lista)->prev = novo;
 
    // 5. move the head to point to the new node
    (*Lista) = novo;
}


int main(){}