#include<stdio.h>
#include<stdlib.h>


typedef struct no{
    int valor;
    struct no *pred;
    struct no* prox;
}No;

No *criaNo(int valor){
    No *novo = malloc(sizeof(No));
    novo->pred = novo;
    novo->valor = valor;
    novo->prox = novo;
    return novo;
}

No *InsereInicio(No *Lista, int valor){
    No *novo = criaNo(valor);
    if (Lista == NULL)
    {
        return novo;
    }
    else{
        No *temp = Lista->prox;
        novo->pred = Lista;
        novo->prox = temp;
        temp->pred = novo;
        Lista->prox = novo;
        return novo;
    }
    
}
No *busca(No *Lista, int k){
    No *temp = Lista;
    for (int i = 0; i < k; i++)
    {
        temp = temp->pred;
        if (temp == Lista)
        {
            return NULL;
        }
        return temp;
    }

    
}

int main(){
    No *Lista = NULL;
    Lista = InsereInicio(Lista, 5);
    Lista = InsereInicio(Lista, 7);
    Lista = InsereInicio(Lista,9);
    Lista = InsereInicio(Lista, 12);
    No *resultado = busca(Lista, 3);
    printf("%d", resultado->valor);

}