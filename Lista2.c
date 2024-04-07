#include<stdio.h>
#include<stdlib.h>
/*
Função Iterativa: 
int soma(No *L){
    int soma = 0;
    No *aux = L;
    while(aux != NULL){
        soma += aux->valor;
        aux = aux->prox;
    }
    return soma;
//Função para substituir;
    No *substitui(No *Lista, int x, int y){
    No *aux = Lista;
    while (aux != NULL){
        if (aux->valor == x)
        {
            aux->valor = y;
        }
        aux = aux->prox;
        
    }
    return Lista;
    
}

    
}
*/

typedef struct no{
    int valor;
    struct no *prox;
}No;

No *criaNo(int valor){
    No *nova = (No*)malloc(sizeof(No));
    if (nova == NULL)
    {
        printf("Erro de Alocacao!");
        exit(1);
    }
    nova->valor = valor;
    nova->prox = NULL;
    return nova;   
}

No *InsereInicio(No *L, int valor){
    No* nova = criaNo(valor);
    nova->prox = L;
    L = nova;
    return L;

}
void imprime(No *Lista){
    No *aux = Lista;
    while (aux != NULL)
    {
        printf("%d ", aux->valor);
        aux = aux->prox;
    }
    printf("\n");
    
}

int ultimo(No *L){
    No *aux = L;
    int ultimo;
    while (aux ->prox != NULL)
    {
        aux = aux->prox;
    }
    ultimo = aux->valor;
    return ultimo;
    
}



int ocorrencia(No *L, int valor){
    int ocorrencia = 0;
    No *aux = L;
    while (aux != NULL)
    {
        if (aux->valor == valor){
            ocorrencia++;
            
        }
        aux = aux->prox;
        
    }
    return ocorrencia;
    
}

int soma(No *L){
    No *aux = L;
    if (aux == NULL) return 0;
    return aux->valor + soma(aux->prox);
}

No *substitui(No *Lista, int x, int y){
    if (Lista == NULL) return NULL;
    if (Lista->valor == x) Lista->valor = y;
    // Chama a função recursivamente para o próximo nó na lista
    Lista->prox = substitui(Lista->prox, x, y);
    // Retorna o ponteiro para o nó atual (ou para o próximo nó, se houve substituição)
    return Lista;
}
int igual(No *Lista, No* Lista2){
    int i;
    if (Lista == NULL && Lista2 == NULL) return 1;
    if (Lista == NULL || Lista2 == NULL) return 0;
    if (Lista->valor != Lista2->valor) return 0;
    return igual(Lista->prox, Lista2->prox);
    
    
}
int esimo_igual(No *Lista, No *Lista2, int x){
    No *aux = Lista;
    No *aux2 = Lista2;
    while (aux != NULL)
    {
        while (aux2 != NULL)
        {
            if (aux->valor == x && aux->valor == x)
            {
                return 1;
            }
            else{
                return 0;
            }
            
        }
        
    }
    
}

int main(){
    No *Lista = NULL;
    int operacao = -1;
    int n, valor;
    No *Lista2 = NULL;  
    int n2;
    int valor2;
    int i;
    printf("Digite quantos elementos voce quer inserir na lista: \n");
    scanf("%d", &n);
    for (int i = 0; i < n; i++){
    printf("Digite o valor pra inserir na lista: \n");
        scanf("%d", &valor);
        Lista = InsereInicio(Lista, valor);
    }
    imprime(Lista);
    while(operacao != 8){
        printf("1 - Achar o número de ocorrencia de um valor na Lista \n");
        printf("2 - Achar o último elemento da lista: \n");
        printf("3 - Inverter a lista: \n");
        printf("4 - Somar os elementos da lista: \n");
        printf("5 - Substitui toda ocorrencia de x por y na lista: \n");
        printf("6 - Verifica se a Lista A é igual a Lista B: \n");
        printf("7 - Verifica se o i-esima elemento de A é igual ao i-esimo elemento de B: \n");
        printf("8 - Sair do programa \n");
        printf("Escolha a operação que voce quer realizar na lista:\n");
        scanf("%d", &operacao);
        if (operacao == 1)
        {
            int x;
            printf("Digite o elemento que voce quer procurar: \n");
            scanf("%d", &x);
            printf("Numero de ocorrencia do elemento é igual: %d \n", ocorrencia(Lista, x));
        }
        else if (operacao == 2)
        {
            printf("Ultimo elemento da Lista é: %d \n", ultimo(Lista));
        }
        //else if(operacao == 3){

       // }
       else if(operacao == 4){
            printf("Soma dos elementos da Lista é: %d \n", soma(Lista));
       }
       else if(operacao == 5){
            int x1, y1;
            printf("Digite o valor que voce quer trocar na lista: \n");
            scanf("%d", &x1);
            printf("Voce quer substituir esse valor por qual: \n");
            scanf("%d", &y1);
            Lista = substitui(Lista, x1, y1);
            imprime(Lista);
       }
       else if (operacao == 6){
            printf("Digite quantos elementos voce quer inserir na lista: \n");
            scanf("%d", &n2);
            for (int i = 0; i < n2; i++){
                printf("Digite o valor pra inserir na lista: \n");
                scanf("%d", &valor2);
                Lista2 = InsereInicio(Lista2, valor2);
            }
            imprime(Lista2);
            if (igual(Lista, Lista2) == 1)
            {
                printf("As duas listas sao iguais!\n");
            }
            else{
                printf("Sao listas diferentes\n");
            }
    }
    else if (operacao == 7){

    }


       }
       
        
        
    }

    
    