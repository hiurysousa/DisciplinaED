#include <stdio.h>
#include <stdlib.h>

float** cria_matriz(int n_linhas, int n_colunas);
void exibe_matriz(float **matriz, int n_linhas, int n_colunas);

int main(){

    int linhas, colunas;
    printf("Digite o numero de linhas e colunas: ");
    scanf("%d %d", &linhas, &colunas);

    float **mat = cria_matriz(linhas, colunas);

    for (int i = 0; i < linhas; i++){
        for (int j = 0; j < colunas; j++){
            printf("Digite o valor do elemento [%d][%d]: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }

    exibe_matriz(mat, linhas, colunas);

    return 0;
}

float** cria_matriz(int n_linhas, int n_colunas){

    float **matriz = (float**)malloc(n_linhas * sizeof(float*));

    for (int i = 0; i < n_linhas; i++){ // ALOCA LINHA 1, EM SEGUIDA, 2 E ASSIM POR DIANTE.
        matriz[i] = (float*)malloc(n_colunas * sizeof(float));
    }

    return matriz;
}

void exibe_matriz(float **matriz, int n_linhas, int n_colunas){

    for (int i = 0; i < n_linhas; i++){
        for (int j = 0; j < n_colunas; j++){
            printf("%.2f ", matriz[i][j]);
        }
        printf("\n");
    }

}