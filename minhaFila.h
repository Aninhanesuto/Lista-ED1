
#include<minhaLista.h>
typedef Lista Fila;


void fila_criar(Fila **p);
void fila_inserir(Fila *p, int valor);

int fila_topo(Fila *p);
void fila_remover(Fila *p);

int fila_tamanho(Fila *p);
void fila_liberar(Fila **p);