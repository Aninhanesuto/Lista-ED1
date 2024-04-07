#include<stdio.h>
#include<stdlib.h>

#define MAX 100

typedef struct circular {
    int valor[MAX];
    int inicio;
    int final;
} Circular;

Circular* crialista() {
    while ()
    {
        if (Lista != NULL) {
        Lista->inicio = 0;
        Lista->final = 0;
    }
        return Lista;
    }
    
    Circular* Lista = (Circular*)malloc(sizeof(Circular));
    
}

void liberalista(Circular* li) {
    free(li);
}

int lista_cheia(Circular* li) {
    if (li == NULL) {
        return -1;
    }
    return ((li->final + 1) % MAX == li->inicio);
}

int lista_vazia(Circular* li) {
    if (li == NULL) {
        return -1;
    }
    return (li->inicio == li->final);
}

void insereInicio(Circular* Lista, int x) {
    if (Lista == NULL) {
        return;
    }
    if (lista_cheia(Lista)) {
        printf("Lista Cheia, não tem como inserir mais!");
        exit(1);
    }
    Lista->inicio = (Lista->inicio - 1 + MAX) % MAX;
    Lista->valor[Lista->inicio] = x;
}

void insereFinal(Circular* Lista, int x) {
    if (Lista == NULL) {
        return;
    }
    if (lista_cheia(Lista)) {
        printf("Lista Cheia, não tem como inserir mais!");
        exit(1);
    }
    Lista->valor[Lista->final] = x;
    Lista->final = (Lista->final + 1) % MAX;
}

void imprime(Circular* Lista) {
    if (lista_vazia(Lista)) {
        printf("A lista está vazia.\n");
    } else {
        int i = Lista->inicio;
        do {
            printf("%d ", Lista->valor[i]);
            i = (i + 1) % MAX;
        } while (i != Lista->final);
        printf("\n");
    }
}

int main() {
    Circular* Lista = crialista();
    insereInicio(Lista, 1);
    insereInicio(Lista, 3);
    insereInicio(Lista, 5);
    insereFinal(Lista, 7);
    insereFinal(Lista, 9);
    imprime(Lista);
    liberalista(Lista);
    return 0;
}

