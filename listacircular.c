#include<stdio.h>
#include<stdlib.h>


#define MAX 100

typedef struct CircularLista{
    int data[100];
    int inicio;
    int final;
}Circular;

void inicializa(Circular *lista){
    lista->inicio = -1;
    lista->final = -1;
}

int isFull(Circular* lista) {
    return ((lista->final + 1) % MAX == lista->inicio);
}

int isEmpty(Circular* lista) {
    return (lista->inicio == -1);
}

void insereInicio(Circular* lista, int x) {
    if (isFull(lista)) {
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
    } else {
        if (isEmpty(lista)) {
            lista->inicio = 0;
            lista->final = 0;
        } else {
            lista->inicio = (lista->inicio - 1 + MAX) % MAX;
        }
        lista->data[lista->inicio] = x;
    }
}
void insereFinal(Circular* lista, int x) {
    if (isFull(lista)) {
        printf("A lista está cheia. Não é possível inserir mais elementos.\n");
    } else {
        if (isEmpty(lista)) {
            lista->inicio = 0;
            lista->final = 0;
        } else {
            lista->final = (lista->final + 1) % MAX;
        }
        lista->data[lista->final] = x;
    }
}
int removeInicio(Circular* lista) {
    int elemremov = -1;
    if (isEmpty(lista)) {
        printf("A lista está vazia. Não é possível remover elementos.\n");
    } else {
        elemremov = lista->data[lista->inicio];
        if (lista->inicio == lista->final) {
            // Último elemento na lista
            lista->inicio = -1;
            lista->final = -1;
        } else {
            lista->inicio = (lista->inicio + 1) % MAX;
        }
    }
    return elemremov;
}

int removeFromEnd(Circular* lista) {
    int elemremov = -1;
    if (isEmpty(lista)) {
        printf("A lista está vazia. Não é possível remover elementos.\n");
    } else {
        elemremov = lista->data[lista->final];
        if (lista->inicio == lista->final) {
            // Último elemento na lista
            lista->inicio = -1;
            lista->final = -1;
        } else {
            lista->final = (lista->final - 1 + MAX) % MAX;
        }
    }
    return elemremov;
}

void imprime(Circular* lista) {
    if (isEmpty(lista)) {
        printf("A lista está vazia.\n");
    } else {
        int i = lista->inicio;
        printf("Lista Circular Estática: ");
        do {
            printf("%d -> ", lista->data[i]);
            i = (i + 1) % MAX;
        } while (i != (lista->final + 1) % MAX);
        printf("...\n");
    }
}

int main() {
    Circular Lista;
    inicializa(&Lista);

    //insereInicio(&Lista, 12);
    insereInicio(&Lista, 12);
    insereInicio(&Lista, 14);
    imprime(&Lista);

    return 0;
}

