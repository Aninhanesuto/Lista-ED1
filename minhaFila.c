#include<stdio.h>
#include<stdlib.h>
#include"minhaFila.h"

void fila_criar(Fila **p){
    criar_lista(p);
}

void inserir_final(Fila **p){
    insere_final(p, valor);
    p->v++;
}
int fila_topo(Fila *p){
    Fila *aux = p->prox;
    if (aux!= NULL) return aux->v;
    else return -1;
    
}
void fila_remover(Fila *p){
    remove_comeco(p);
    p->v--;
}
int tamanho(Fila *p){
    return p->v;
}
void fila_liberar(Fila **p){
    libera_lista(p);
}
int main(){

}