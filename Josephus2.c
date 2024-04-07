#include<stdio.h>
#include<stdlib.h>

typedef struct no{
    int valor;
    struct no *prox;
}No;

No *insere(int valor){
    No *novo = (No*)malloc(sizeof(No));
    novo->prox = novo;
    novo->valor = valor;
    return novo;

}
void getJosephus(int m, int n){
    No *head = insere(1);
    No *prev = head;
    for (int i = 2; i <= n; i++)
    {
        prev->prox = insere(i);
        prev = prev->prox;
    }
    prev->prox = head;
    No *ptr1 = head, *ptr2 = head;
    while (ptr1->prox != ptr1)
    {
        int count = 1;
        while (count != m)
        {
            ptr2 = ptr1;
            ptr1 = ptr1->prox;
            count++;
        }
        ptr2->prox = ptr1->prox;
        free(ptr1);
        ptr1 = ptr2->prox;
        
    }
    printf("A ultima pessoa a permanecer é %d\n",ptr1->valor);
    
    
}
int main() 
{ 
    int n = 14, m = 2; 
    getJosephus(m, n); 
    return 0; 
}