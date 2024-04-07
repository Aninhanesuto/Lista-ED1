#include<stdio.h>
#include<stdlib.h>

typedef struct celula Celula;

struct celula{
    int conteudo;
    Celula *prox
};

void imprime(Celula *lst){
    Celula *p = lst;
    while (p != NULL)
    {
        printf("%d ", p->conteudo);
        p = p->prox;

    }
    printf("\n");
    
}

Celula *busca(Celula *lst, int x){
    Celula *p = lst;
    while (p != NULL && p->conteudo != x)
    {
        p = p->prox;
    }
    return p;
    
}
Celula *selecao(Celula *lst, int k){
    Celula *p = lst;
    int q = 0;
    while (p != NULL && q < k)
    {
        p = p->prox;
        q++;
    }
    return p;
    
}
Celula *inserir(Celula *lst, int x){
    Celula *nova;
    nova = malloc(sizeof(Celula));
    nova->conteudo = x;
    nova->prox = lst;
    return nova;
}

void remover(Celula *p){
    Celula *morta;
    morta = p->prox;
    p->prox = morta->prox;
    free(morta);
}

Celula *buscaInsere(Celula *lst, int x, int y){
    Celula *p, *q, *nova;
    nova = malloc(sizeof(Celula));
    nova->conteudo = y;
    if (lst == NULL || lst->conteudo == x){
        nova->prox = lst;
        return nova;
    }
    p = lst;
    q = p->prox;
    while (q != NULL && q->conteudo != x)
    {
        p = q;
        q = p->prox;
    }
    p->prox = nova;
    nova->prox = q;
    return lst;
}

Celula *buscaRemove(Celula *lst, int x){
    Celula *p, *morta;
    if (p == NULL){
        return p;
    }
    if (p->conteudo == x){
        morta = p;
        p = morta->prox;
        free(morta);
        return p;
    }
    while ()
    {
        /* code */
    }
    

    
    

}

int main(int argc, char *argv[]){
    int i, n;
    Celula *ini = NULL;

    if (argc != 2)
    {
        printf("Numero de parametros incorretos. Ex.: .\\lista2 10\n");
        return 0;

    }
    
    n = atoi(argv[1]);
    printf("Insere n elementos na lista: \n");
    for (int i = 0; i < n; i++)
    {
        ini = inserir(ini, i);
    }
    imprime(ini);
    printf("Buscando Elemento :\n");
    Celula *p = busca(ini, 10);
    if (p != NULL)
    {
        printf("%d\n", p->conteudo);
    }
    else
        printf("nao encontrou\n");
    printf("Selecionando Elementos: \n");
    Celula *q = selecao(ini, 10);
    if (q != NULL)
    {
        printf("%d\n", p->conteudo);
    }
    else
        printf("nao existe\n");
    printf("remove(ini)\n");
    remover(ini);
    imprime(ini);
    printf("remove(ini->prox)\n");
    remover(ini->prox);
    imprime(ini);
    printf("busaInsere(ini, 2,3)\n");
    ini = buscaInsere(ini,2,3);
    imprime(ini);
    printf("buscaInsere(ini, ini->conteudo, 49)\n");
    ini = buscaInsere(ini, ini->conteudo, 49);
    imprime(ini);
    printf("buscaInsere(ini, 15, 17)\n");
    imprime(ini);
    
    


}