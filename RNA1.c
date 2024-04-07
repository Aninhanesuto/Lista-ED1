#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct no{
    char nucleotideo;
    struct no* prox;
    struct no* prev;
}No;


No *inserir (No* Lista, char nucleotideo)
{
    // 1. allocate node
    No* novo = (No*)malloc(sizeof(No));
 
    // 2. put in the data
    novo->nucleotideo = nucleotideo;
 
    // 3. Make next of new node as head and previous as NULL
    novo->prox = Lista;
    novo->prev = NULL;
 
    // 4. change prev of head node to new node
    if (Lista != NULL)
        Lista->prev = novo;
 
    // 5. move the head to point to the new node
    Lista = novo;
    return novo;
}

No *transcreve(No* Lista){
    No *aux = Lista;
    while (aux != NULL)
    {
        if (aux->nucleotideo == 'G'){
            aux->nucleotideo = 'C';
        }
        else if (aux->nucleotideo == 'C'){
            aux->nucleotideo = 'G';
        }
        else if (aux->nucleotideo == 'T'){
            aux->nucleotideo = 'A';
        }
        else if (aux->nucleotideo == 'A'){
            aux->nucleotideo = 'U';
        }
        aux = aux->prox;
    }
    
    
    return Lista;    
}

void imprimir(No *L){
    while (L != NULL)
    {
        printf("%c ", L->nucleotideo);
        L = L->prox;
    }
    printf("\n");
    
}
int main(){
    No *Lista = NULL;
    Lista = inserir(Lista, 'C');
    Lista = inserir(Lista, 'G');
    imprimir(Lista);
    Lista = transcreve(Lista);
    imprimir(Lista);
    
}