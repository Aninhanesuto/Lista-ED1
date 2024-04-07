#include<stdio.h>
#include<stdlib.h>
#include "minhaLista.h"

int main(){
    int i;
    Lista *L;
    criar_lista(&L);
    for (int i = 1; i < 10; i++)
    {
        insere_comeco(L,i);
    }
    remove_final(L);
    remove_comeco(L);
    imprime_lista(L);
    libera_lista(&L);
    
}