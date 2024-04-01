#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor) {
    No* novo_No = (No*)malloc(sizeof(No));
    if (novo_No == NULL) {
        printf("Falha!\n");
        exit(1);
    }
    novo_No->valor = valor;
    novo_No->esquerda = NULL;
    novo_No->direita = NULL;
    return novo_No;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    } else {
        if (valor < raiz->valor) {
            raiz->esquerda = inserir(raiz->esquerda, valor);
        } else if (valor > raiz->valor) {
            raiz->direita = inserir(raiz->direita, valor);
        }
        return raiz;
    }
}

void imprimirNosFolha(No* raiz) {
    if (raiz == NULL) {
        return;
    }
    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        printf("%d ", raiz->valor);
    }
    imprimirNosFolha(raiz->esquerda);
    imprimirNosFolha(raiz->direita);
}

int encontrarAncestrais(No* raiz, int valor) {
    if (raiz == NULL) {
        return 0;
    }
    if (raiz->valor == valor) {
        return 1;
    }
    if (encontrarAncestrais(raiz->esquerda, valor) || encontrarAncestrais(raiz->direita, valor)) {
        printf("%d ", raiz->valor);
        return 1;
    }
    return 0;
}

void encontrarDescendentes(No* raiz, int valor) {
    if (raiz == NULL) {
        return;
    }
    if (raiz->valor == valor) {
        if (raiz->esquerda != NULL) {
            printf("%d ", raiz->esquerda->valor);
        }
        if (raiz->direita != NULL) {
            printf("%d ", raiz->direita->valor);
        }
        return;
    }
    encontrarDescendentes(raiz->esquerda, valor);
    encontrarDescendentes(raiz->direita, valor);
}

void imprimirPaiEFilhos(No* raiz, int valor) {
    if (raiz == NULL) {
        return;
    }
    if ((raiz->esquerda != NULL && raiz->esquerda->valor == valor) ||
        (raiz->direita != NULL && raiz->direita->valor == valor)) {
        printf("Pai: %d\n", raiz->valor);
        printf("Filhos: ");
        if (raiz->esquerda != NULL) {
            printf("%d ", raiz->esquerda->valor);
        }
        if (raiz->direita != NULL) {
            printf("%d ", raiz->direita->valor);
        }
        printf("\n");
        return;
    }
    imprimirPaiEFilhos(raiz->esquerda, valor);
    imprimirPaiEFilhos(raiz->direita, valor);
}

int main() {
    No* raiz = NULL;
    int opcao, valor;

    while (1) {
        printf("\nMenu\n");
        printf("1 - Inserir número\n");
        printf("2 - Mostrar os nós folha\n");
        printf("3 - Mostrar os nós ancestrais de um nó\n");
        printf("4 - Mostrar os nós descendentes de um nó\n");
        printf("5 - Mostrar o nó pai e os nós filhos de um nó\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número a ser inserido: ");
                scanf("%d", &valor);
                raiz = inserir(raiz, valor);
                break;
            case 2:
                printf("Nós folha: ");
                imprimirNosFolha(raiz);
                printf("\n");
                break;
            case 3:
                printf("Digite o número para encontrar os ancestrais: ");
                scanf("%d", &valor);
                printf("Nós ancestrais: ");
                encontrarAncestrais(raiz, valor);
                printf("\n");
                break;
            case 4:
                printf("Digite o número para encontrar os descendentes: ");
                scanf("%d", &valor);
                printf("Nós descendentes: ");
                encontrarDescendentes(raiz, valor);
                printf("\n");
                break;
            case 5:
                printf("Digite o número para encontrar o nó pai e os nós filhos: ");
                scanf("%d", &valor);
                printf("Nó pai e nós filhos:\n");
                imprimirPaiEFilhos(raiz, valor);
                break;
            case 6:
                printf("Encerrando o programa.\n");
                exit(0);
            default:
                printf("Opção inválida. Tente novamente.\n");
        }
    }

    return 0;
}
