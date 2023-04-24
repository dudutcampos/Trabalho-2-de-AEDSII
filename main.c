#include "hash.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
    // M = numero de indices, N = numero de elementos, X = indice a ser mostrado ao usuario.
    int M, N, X;
    while (scanf(" %d %d", &M, &N) != EOF){
        // parametro de parada.
        if(M == 0 && N == 0){
            break;
        }
 
        // vetor utilizado para armazenar N valores.
        int *v = (int*)malloc(N*sizeof(int));
        for (int i = 0; i < N; i++){
            int num;
            scanf(" %d", &num);
            v[i] = num;
        }
 
        // criando vetor hash de arvores comindices de 0 a (M-1)
        Arvore **hash = cria_hash(M);
        
        insere_hash(hash, v, M, N);
        
        // recebendo o indice a ser mostrado ao usuario
        scanf(" %d", &X);
        imprime_hash(hash, X);
        printf("\n");

        // desalocando memoria utilizada
        destroi_hash(hash, M);
        free(v);
    }
}