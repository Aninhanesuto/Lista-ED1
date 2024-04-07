#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct no{
    char nucleotideo[4];
    struct no* prox;
    struct no* prev;

}No;

No *inserir (No* Lista, char *nucleotideo)
{
    // 1. allocate node
    No* novo = (No*)malloc(sizeof(No));
 
    // 2. put in the data
    strcpy(novo->nucleotideo, nucleotideo);
 
    // 3. Make next of new node as head and previous as NULL
    novo->prox = Lista;
    novo->prev = NULL;
 
    // 4. change prev of head node to new node
    if (Lista != NULL)
        Lista->prev = novo;
 
    // 5. move the head to point to the new node
    Lista = novo;
    return novo;
}
void imprimeAminoacidos(No* Lista) {
    No* aux = Lista;
    while (aux != NULL) {
        if (strcmp(aux->nucleotideo, "UGA") == 0 || strcmp(aux->nucleotideo, "UAA") == 0 || strcmp(aux->nucleotideo, "UAG") == 0) {
            break;
        } else if (strcmp(aux->nucleotideo, "UUU") == 0 || strcmp(aux->nucleotideo, "UUC") == 0) {
            printf("Phe");
        } else if (strcmp(aux->nucleotideo, "UUA") == 0 || strcmp(aux->nucleotideo, "UUG") == 0) {
            printf("Leu");
        }
        else if (strcmp(aux->nucleotideo, "UCU") == 0 || strcmp(aux->nucleotideo, "UCC") == 0 || strcmp(aux->nucleotideo, "UCA") == 0 || strcmp(aux->nucleotideo, "UCG") == 0) {
            printf("Ser");
        }
        else if (strcmp(aux->nucleotideo, "UAU") == 0 || strcmp(aux->nucleotideo, "UAC") == 0){
            printf("Try");
        }
        else if (strcmp(aux->nucleotideo, "UGU") == 0 || strcmp(aux->nucleotideo, "UGC") == 0){
            printf("Cys");
        }
        else if (strcmp(aux->nucleotideo, "UGG") == 0){
            printf("Trp");
        }
        else if (strcmp(aux->nucleotideo, "CUU") == 0 || strcmp(aux->nucleotideo, "CUC") == 0 || strcmp(aux->nucleotideo, "CUA") == 0 || strcmp(aux->nucleotideo, "CUG") == 0) {
            printf("Leu");
        }
        else if (strcmp(aux->nucleotideo, "CCU") == 0 || strcmp(aux->nucleotideo, "CCC") == 0 || strcmp(aux->nucleotideo, "CCA") == 0 || strcmp(aux->nucleotideo, "CCG") == 0) {
            printf("Pro");
        }
        else if (strcmp(aux->nucleotideo, "CAU") == 0 || strcmp(aux->nucleotideo, "CAC") == 0){
            printf("His");
        }
        else if (strcmp(aux->nucleotideo, "CAA") == 0 || strcmp(aux->nucleotideo, "CAG") == 0){
            printf("Cys");
        }
        else if (strcmp(aux->nucleotideo, "CGU") == 0 || strcmp(aux->nucleotideo, "CGC") == 0 || strcmp(aux->nucleotideo, "CGA") == 0 || strcmp(aux->nucleotideo, "CGG") == 0) {
            printf("Arg");
        }
        else if (strcmp(aux->nucleotideo, "AUU") == 0 || strcmp(aux->nucleotideo, "AUC") == 0 || strcmp(aux->nucleotideo, "AUA") == 0) {
            printf("Ile");
        }
        else if (strcmp(aux->nucleotideo, "AUG") == 0) {
            printf("Met");
        }
        else if (strcmp(aux->nucleotideo, "ACU") == 0 || strcmp(aux->nucleotideo, "ACC") == 0 || strcmp(aux->nucleotideo, "ACA") == 0 || strcmp(aux->nucleotideo, "ACG") == 0) {
            printf("Thr");
        }
        else if (strcmp(aux->nucleotideo, "AAU") == 0 || strcmp(aux->nucleotideo, "AAC") == 0){
            printf("Asn");
        }
        else if (strcmp(aux->nucleotideo, "AAA") == 0 || strcmp(aux->nucleotideo, "AAG") == 0){
            printf("Lys");
        }
        else if (strcmp(aux->nucleotideo, "AGU") == 0 || strcmp(aux->nucleotideo, "AGC") == 0){
            printf("Ser");
        }
        else if (strcmp(aux->nucleotideo, "AGA") == 0 || strcmp(aux->nucleotideo, "AGG") == 0){
            printf("Arg");
        }
        else if (strcmp(aux->nucleotideo, "GUU") == 0 || strcmp(aux->nucleotideo, "GUC") == 0 || strcmp(aux->nucleotideo, "GUA") == 0 || strcmp(aux->nucleotideo, "GUG") == 0) {
            printf("Val");
        }
        else if (strcmp(aux->nucleotideo, "GCU") == 0 || strcmp(aux->nucleotideo, "GCC") == 0 || strcmp(aux->nucleotideo, "GCA") == 0 || strcmp(aux->nucleotideo, "GCG") == 0) {
            printf("Ala");
        }
        else if (strcmp(aux->nucleotideo, "GAU") == 0 || strcmp(aux->nucleotideo, "GAC") == 0){
            printf("Asp");
        }
        else if (strcmp(aux->nucleotideo, "GAA") == 0 || strcmp(aux->nucleotideo, "GAG") == 0){
            printf("Glu");
        }
        else if (strcmp(aux->nucleotideo, "GGU") == 0 || strcmp(aux->nucleotideo, "GGC") == 0 || strcmp(aux->nucleotideo, "GGA") == 0 || strcmp(aux->nucleotideo, "GGG") == 0) {
            printf("Gly");
        }
        
        // Adicione outras condições conforme necessário para os outros aminoácidos.
        
        // Adicione um hífen após cada aminoácido, exceto o último
        if (aux->prox != NULL) {
            printf("-");
        }
        
        aux = aux->prox;
    }
    printf("\n");
}


int main() {
    No* Lista = NULL;
    // Suponha que você tenha uma string representando o RNA, por exemplo:
    char rna[] = "AUUGCGAUCGAUUAG";
    
    // Verifique se a string tem um tamanho múltiplo de 3
    if (strlen(rna) % 3 != 0) {
        printf("Erro: A entrada não é uma sequência válida de RNA.\n");
        return 1;
    }
    
    // Divide a string em trincas de nucleotídeos e insere na lista
    for (int i = 0; i < strlen(rna); i += 3) {
        char trinca[4];  // Para armazenar uma trinca de nucleotídeos (3 letras + terminador de string)
        strncpy(trinca, rna + i, 3);
        trinca[3] = '\0';  // Adiciona o terminador de string
        Lista = inserir(Lista, trinca);
    }

    // Imprime os aminoácidos correspondentes aos códons na lista
    imprimeAminoacidos(Lista);
    
    // Libera a memória alocada para a lista (o código para liberar a memória não foi incluído neste exemplo)
    
    return 0;
}
