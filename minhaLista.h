typedef struct no{
    int v;
    struct no *prox;

}Lista;

void criar_lista(Lista **p);
void insere_final(Lista *p, int valor);
void insere_comeco(Lista *p, int valor);

void remove_final(Lista* p);
void remove_comeco(Lista *p);

void imprime_lista(Lista *p);
void libera_lista(Lista **p);