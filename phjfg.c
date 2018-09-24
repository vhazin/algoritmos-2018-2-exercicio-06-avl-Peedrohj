#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int info;
    int altura;
    struct No* esquerda;
    struct No* direita;
    struct No* pai;
    
} No;
 
No* criarArvore(int info){
    No* raiz = (No*)malloc(sizeof(No));

    raiz->info = info;
    raiz->altura = 0;
    raiz->esquerda = NULL;
    raiz->direita = NULL;

    return raiz;
}

No* inserir(No* raiz, int info){
    int balanceamento;
    

    if(raiz == NULL){
        raiz = criarArvore(info);
    }else{
        if(info < raiz->info){
            inserir(raiz->esquerda, info);
        }else{
            inserir(raiz->direita, info);
        }
    }

    balanceamento = labs((raiz->esquerda) - (raiz->direita));
    printf("%d", balanceamento);
    if(balanceamento >= 2){
        printf("F\n");
    }else{
        printf("T\n");
    }

    return raiz;
}

int main(){
    int t, n, node;
    No* arvore;

    scanf("%d", &t);
    for(int i=t; i<=t; i++){
        scanf("%d", &n);
        scanf("%d", &node);
        No* arvore = criarArvore(node);
        for(int j = 1; j<n; j++){
            scanf("%d", &node);      
            inserir(arvore, node);
        } 
    }
}