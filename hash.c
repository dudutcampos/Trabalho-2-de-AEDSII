#include "hash.h"
#include <stdlib.h>

Arvore** cria_hash(int M){
    Arvore **hash = cria_array_poteiros(M);
    for (int i = 0; i < M; i++){
        hash[i] = cria_arvore_vazia();
    }
    return hash;
}

//
void imprime_hash(Arvore **hash, int X){
    pre_ordem(hash[X]->raiz);
}

// distribuindo os elementos utilizado hash com arvores.
void insere_hash(Arvore **hash, int *v, int M, int N){
    int mod;
    for (int i = 0; i < N; i++){
        // mod = elemento mod Numero de indices.
        mod = v[i]%M;
        //insere elemento na arvore de indice mod.
        insere(hash[mod], v[i]);
    }
}

// libera toda a memoria alocada para as arvores.
void destroi_hash(Arvore **hash, int M){
    for (int i = 0; i < M; i++){
        destroi(hash[i]->raiz);
        free(hash[i]);
    }
    free(hash);
}