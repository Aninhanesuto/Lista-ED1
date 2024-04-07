#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct circular{
    int qtde;
    int valor[MAX];
    int inicio;
    int final;
}Circular;
Circular* crialista(){
    Circular* Lista = (Circular*)malloc(sizeof(Circular));
    if (Lista != NULL)
    {
        Lista->qtde = 0;
        Lista->inicio = 0;
        Lista->final = 0;

    }
    return Lista;
} 
void liberalista(Circular *li){
    free(li);
}

int tamanho_lista(Circular *li){
    if (li == NULL){
        return -1;
    }
    else 
        return li->qtde;
}
int lista_cheia(Circular *li){
    if (li == NULL)
    {
        return -1;
    }
    return (li->qtde == MAX);
    
}

int lista_vazia(Circular *li){
    if (li == NULL)
    {
        return -1;

    }
    return (li->qtde == 0);
    
}
int insereInicio(Circular *Lista, int x){
    if (Lista == NULL) return 0;
    if (lista_cheia(Lista) != 0 )
    {
        printf("Lista Cheia, não tem como inserir mais!");
        exit(1);
    }
    else if (Lista->qtde >= MAX){
        printf("Vetor Cheio!"); 
    }
    else{
        if (lista_vazia(Lista) != 0){
        Lista->valor[Lista->inicio] = x;
        Lista->final = (Lista->inicio + 1 % MAX);
        Lista->qtde++;
        }
        else {
        Lista->inicio = (Lista->inicio - 1 + MAX) % MAX;
        Lista->valor[Lista->inicio] = x;
    Lista->qtde++;
        }
        }

    }
int insereFinal(Circular *Lista, int x){
    if (Lista == NULL) return 0;    
    if (lista_cheia(Lista) != 0)
    {
        printf("Não é possível inserir, lista cheia!");
        return 0;
    }
    Lista->valor[Lista->final] = x;
    Lista->qtde++;
    Lista->final++;
    
}

int excluirInicio(Circular *Lista){
    if (Lista == NULL || lista_vazia(Lista)) return 0;
    
    Lista->valor[Lista->inicio] = 0;
    Lista->inicio = (Lista->inicio + 1) % MAX;
    Lista->qtde--;

    return 1; // Indica sucesso na exclusão
}
int excluirFinal(Circular *Lista){
    if (Lista == NULL || lista_vazia(Lista)) return 0;
    
    Lista->final = (Lista->final - 1 + MAX) % MAX;
    Lista->valor[Lista->final] = 0;
    Lista->qtde--;

    return 1; // Indica sucesso na exclusão
}

void imprime(Circular *Lista){
    int i = Lista->inicio;
    if (lista_vazia(Lista)) {
        printf("A lista está vazia.\n");
    } else {
        do {
            
            printf("%d ", Lista->valor[i]);
            i = (i + 1) % MAX;
        } while (i != Lista->final);
        printf("\n");
    }
}

int main(){
    Circular* Lista = crialista();
    insereInicio(Lista, 1);
    insereInicio(Lista, 3);
    insereInicio(Lista, 5);
    excluirInicio(Lista);
    excluirInicio(Lista);
    imprime(Lista);
}