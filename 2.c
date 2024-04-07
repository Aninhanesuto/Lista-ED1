#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *pred;
    struct no *prox;

}No;

No *CriaNo(int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->prox = novo;
    novo->pred = novo;
    return novo;
}
No *InsereInicio(No *Lista, int valor){
    No *novo = CriaNo(valor);
    if (Lista == NULL)
    {
        return novo;
    }
    else{
        No *temp = Lista->pred;
        novo->pred = temp;
        novo->prox = Lista;
        temp->prox = novo;
        Lista->pred = novo;
        return novo;
    }
}

int tamanho(No *Lista){
    int conta= 0;
    No *aux = Lista;
    do{
        conta++;
        aux = aux->prox;
    }while (aux != Lista);
    
    return conta;
    
}
int elimina(No *Lista, int x){
    int conta = 0;
    No *aux = Lista;
    do
    {
        if (Lista == NULL){
                return NULL;
            }
        if (aux->valor == x){

            No *aux2 = Lista;
            conta++;
            Lista->prox = aux->prox->prox;
            Lista->pred->pred = aux;
            free(aux2);

        }
        aux = aux->prox;
    } while (aux != Lista);
    
}

void imprime(No *Lista){
    No *aux = Lista;
    do{
        printf("%d ", aux->valor);
        aux = aux->prox;
    }while (aux != Lista);
    printf("\n");
}

int main(){
    No *Lista = NULL;
    Lista = InsereInicio(Lista, 12);
    Lista = InsereInicio(Lista, 5);
    Lista = InsereInicio(Lista, 7);
    Lista = InsereInicio(Lista, 5);
    //No *resultado = busca(Lista, 3);
    //printf("%d", resultado->valor);
    imprime(Lista);
    printf("%d ", tamanho(Lista));
    printf("%d", elimina(Lista, 5));

}

