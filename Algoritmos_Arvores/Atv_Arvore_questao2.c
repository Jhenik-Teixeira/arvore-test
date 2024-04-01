#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int valor;
    struct No* esquerda;
    struct No* direita;
} No;

No* criarNo(int valor) {
    No* novoNo = (No*)malloc(sizeof(No));
    if (novoNo == NULL) {
        printf("Erro: Falha na alocação de memória.\n");
        exit(1);
    }
    novoNo->valor = valor;
    novoNo->esquerda = NULL;
    novoNo->direita = NULL;
    return novoNo;
}

No* inserir(No* raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }
    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }
    return raiz;
}

void imprimirArvore(No* raiz) {
    if (raiz != NULL) {
        imprimirArvore(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirArvore(raiz->direita);
    }
}

void imprimirSubArvoreDireita(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimirSubArvoreDireita(raiz->direita);
    }
}

void imprimirSubArvoreEsquerda(No* raiz) {
    if (raiz != NULL) {
        printf("%d ", raiz->valor);
        imprimirSubArvoreEsquerda(raiz->esquerda);
    }
}

void imprimirPaiEFilhos(No* raiz, int valor) {
    if (raiz == NULL) {
        printf("Nó não encontrado.\n");
        return;
    }
    if (raiz->valor == valor) {
        printf("Nó pai: %d\n", raiz->valor);
        printf("Nós filhos: ");
        if (raiz->esquerda != NULL) {
            printf("%d ", raiz->esquerda->valor);
        }
        if (raiz->direita != NULL) {
            printf("%d ", raiz->direita->valor);
        }
        printf("\n");
        return;
    }
    if (valor < raiz->valor) {
        imprimirPaiEFilhos(raiz->esquerda, valor);
    } else {
        imprimirPaiEFilhos(raiz->direita, valor);
    }
}

int main() {
    // Criando a árvore especificada: 6(2(1 4(3)) 8)
    No* raiz = criarNo(6);
    raiz->esquerda = criarNo(2);
    raiz->esquerda->esquerda = criarNo(1);
    raiz->esquerda->direita = criarNo(4);
    raiz->esquerda->direita->esquerda = criarNo(3);
    raiz->direita = criarNo(8);

    int opcao, numero;

    while (1) {
        printf("\nMenu\n");
        printf("1 - Inserir número\n");
        printf("2 - Mostrar todos\n");
        printf("3 - Mostrar a subárvore da direita\n");
        printf("4 - Mostrar a subárvore da esquerda\n");
        printf("5 - Mostrar o nó pai e os nós filhos de um nó\n");
        printf("6 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("Digite o número a ser inserido: ");
                scanf("%d", &numero);
                raiz = inserir(raiz, numero);
                break;
            case 2:
                printf("Elementos da árvore em ordem: ");
                imprimirArvore(raiz);
                printf("\n");
                break;
            case 3:
                printf("Subárvore da direita: ");
                imprimirSubArvoreDireita(raiz->direita);
                printf("\n");
                break;
            case 4:
                printf("Subárvore da esquerda: ");
                imprimirSubArvoreEsquerda(raiz->esquerda);
                printf("\n");
                break;
            case 5:
                printf("Digite o número do nó para encontrar o nó pai e os nós filhos: ");
                scanf("%d", &numero);
                imprimirPaiEFilhos(raiz, numero);
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
