#include<stdio.h>
#include<stdlib.h>
#include"ListaSequencial.h"

struct lista{

    int qtde;
    struct aluno dados[MAX];
};

Lista* crialista(){
    Lista *l1;
    l1 = (Lista*)malloc(sizeof(struct lista));
    if (l1 != NULL)
    {
        l1->qtde =  0;

    }
    return l1;
} 

void liberalista(Lista *li){
    free(li);
}

int tamanho_lista(Lista *li){
    if (li == NULL){
        return -1;
    }
    else 
        return li->qtde;
}
int lista_cheia(Lista *li){
    if (li == NULL)
    {
        return -1;
    }
    return (li->qtde == MAX);
    
}

int lista_vazia(Lista *li){
    if (li == NULL)
    {
        return -1;

    }
    return (li->qtde == 0);
    
}