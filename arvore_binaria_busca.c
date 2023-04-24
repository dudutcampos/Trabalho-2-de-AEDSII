#include "arvore_binaria_busca.h"
#include <stdio.h>
#include <stdlib.h>

// retorna uma array com M pnteiros pra arvore.
Arvore** cria_array_poteiros(int M){
    Arvore **A = (Arvore**)malloc(M*sizeof(Arvore*));
    for (int i = 0; i < M; i++){
        A[i] = NULL;
    }
    return A;
}

Arvore* cria_arvore_vazia(){
    Arvore *A = (Arvore*)malloc(sizeof(Arvore));
    A->raiz = NULL;
    return A;
}

No* cria_no(int n){
    No *no = (No*)malloc(sizeof(No));
    no->esq = NULL;
    no->dir = NULL;
    no->chave = n;
    return no;
}

void insere(Arvore *A, int n){
    if(A->raiz == NULL){
        A->raiz = cria_no(n);
        return;
    }else{
        insere_com_elementos(A->raiz, n);
    }
}

void insere_com_elementos(No *t, int n){
    if(n == t->chave){
        return;
    }else if(n > t->chave){
        if(t->dir == NULL){
            t->dir = cria_no(n);
            return;
        }else{
            insere_com_elementos(t->dir, n);
        }
    }else if(n < t->chave){
        if(t->esq == NULL){
            t->esq = cria_no(n);
            return;
        }else{
            insere_com_elementos(t->esq, n);
        }
    }
}

void pre_ordem(No *t){
    if (t == NULL){
        return;
    }
    printf("%d ", t->chave);
    pre_ordem(t->esq);
    pre_ordem(t->dir);
}

void destroi(No *t){
    if (t == NULL){
        return;
    }
    destroi(t->esq);
    destroi(t->dir);
    free(t);
}