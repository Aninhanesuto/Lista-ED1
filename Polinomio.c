#include<stdio.h>
#include<stdlib.h>

typedef struct poli{
    float coeficiente;
    int expoente;
    struct poli *prox;

}Poli;

Poli *insere(Poli *Lista, float coef, int expo){
    Poli *aux;
    Poli *novo = (Poli*)malloc(sizeof(Poli));
    novo->coeficiente = coef;
    novo->expoente = expo;
    novo->prox = NULL;
    if (Lista == NULL || expo > Lista->expoente)
    {
        novo->prox = Lista;
        Lista = novo;
    }
    else{
        aux = Lista;
        while (aux->prox != NULL && aux->prox->expoente> expo)
            aux = aux->prox;
        novo->prox = aux->prox;
        aux->prox = novo;  
    }
    return Lista;
    
}

Poli *criar(Poli *Lista){
    int n, expo;
    float coef;
    printf("Digite os numeros de termos do polinomio: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
        printf("Digite o coeficiente do termo %d: \n", i + 1);
        scanf("%f", &coef);
        printf("Digite o expoente do termo %d: \n", i + 1);
        scanf("%d", &expo);
        Lista = insere(Lista, coef, expo);
    }
    return Lista;
}





void imprime(Poli *Lista){
    if (Lista == NULL){
        printf("Nao tem nenhum polinomio!\n");
    }else{
        Poli *aux = Lista;
        while (aux != NULL){
            printf("(%.fx^%d)", aux->coeficiente, aux->expoente);
            aux = aux->prox;
            if (aux != NULL){
                printf(" + ");
            }else{
                printf("\n");
            }
        }
        
    }
    
}
int main(){
    Poli *Lista = NULL;
    printf("Digite o polinomio: \n");
    Lista = criar(Lista);
    imprime(Lista);

}