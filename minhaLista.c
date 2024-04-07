#include<stdio.h>
#include<stdlib.h>
#include "minhaLista.h"

void criar_lista(Lista **p){
    Lista *q = (Lista*)malloc(sizeof(Lista));
    q ->v = 0;
    q->prox =NULL;
    *p = q;

}

void insere_final(Lista *p, int valor){
    Lista *q, *aux;
    q = (Lista*)malloc(sizeof(Lista));
    q->v = valor;
    q->prox = NULL;
    aux = p;
    while (aux->prox != NULL) aux = aux->prox;
    aux->prox = q;
}

void insere_comeco(Lista *p, int valor){
    Lista *q = (Lista*)malloc(sizeof(Lista));
    q->v = valor;
    q->prox = p->prox;
    p->prox = q;
}

void remove_final(Lista *p){
    Lista *q = p;
    if (q->prox != NULL)
    {
        while (q->prox->prox != NULL)
        {
            q = q->prox;
        }
        Lista *aux = q->prox;
        q->prox = NULL;
        free(aux);
    }
    
}

void remove_comeco(Lista *p){
    Lista *q;
    if (p->prox != NULL)
    {
        q = p->prox;
        p->prox = q->prox;
        free(q);
    }
    
}
void imprime_lista(Lista *p){
    Lista *q;
    for (q = p->prox; q != NULL; q = q->prox)
    {
        printf("%d\n", q->v);
    }
    
}

void libera_lista(Lista **p){
    Lista* q;
    while (*p != NULL)
    {
        q = *p;
        *p = (*p)->prox;
        free(q);
    }
    
}