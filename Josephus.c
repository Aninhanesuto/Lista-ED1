#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int player;
    struct no *prox;
} No;

No *start, *ptr, *new_node;

int main() {
    int n, k, i, count;
    printf("Digite a quantidade de jogadores: \n");
    scanf("%d", &n);
    printf("Digite o valor de k (quantidade de pulos para eliminar um jogador)\n");
    scanf("%d", &k);

    start = malloc(sizeof(No));
    start->player = 1;
    start->prox = start; // Point to itself to form a circular list
    ptr = start;

    for (int i = 2; i <= n; i++) {
        new_node = malloc(sizeof(No));
        new_node->player = i;
        new_node->prox = start; // Point to start to maintain circular structure
        ptr->prox = new_node;
        ptr = new_node;
    }

    ptr = start;

    for (count = n; count > 1; count--) {
        for (i = 0; i < k - 1; ++i) {
            ptr = ptr->prox;
        }
        No *temp = ptr->prox;
        ptr->prox = temp->prox;
        printf("%d deleted\n", temp->player);
        free(temp);
    }

    printf("The Winner is Player %d\n", ptr->player);

    free(ptr); // Free the last remaining player
    return 0;
}
