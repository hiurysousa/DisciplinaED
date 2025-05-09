#include <stdio.h>
#include <stdlib.h>
// MATRIZES (VETOR DE VETOR (LINHAS X COLUNAS))

float** cria_matriz(int linhas, int colunas);
void imprime_matriz(float **mat, int n, int m);
float soma_matriz(float** mat, int n, int m);
float subtracao_matriz(float** mat, int n, int m);
void libera_matriz(float** mat, int n);
float** transpor_matriz(float** mat, int n, int m);


int main(){

    int n, m;
    
    printf("Digite o numero de linhas e colunas: ");
    scanf("%d %d", &n, &m);

    float** mat = cria_matriz(n, m);
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("Digite o valor do elemento %d %d: ", i+1, j+1);
            scanf("%f", &mat[i][j]);
        }
    }
    imprime_matriz(mat, n, m);

    float** mat_t = transpor_matriz(mat, n, m);
    printf("\n");
    imprime_matriz(mat_t, n, m);


    float total_soma = soma_matriz(mat, n, m);
    printf("SOMA TOTAl: %f", total_soma);

    float total_subtracao = subtracao_matriz(mat, n, m);
    printf("\nSUBTRACAO TOTAL: %f", total_subtracao);

    return 0;
}

float** cria_matriz(int linhas, int colunas) {
    float **mat = (float**)malloc(linhas * sizeof(float*));
    if (mat == NULL) {
        printf("Erro ao alocar linhas da matriz!\n");
        exit(1);
    }

    for (int i = 0; i < linhas; i++) {
        mat[i] = (float*)malloc(colunas * sizeof(float));
        if (mat[i] == NULL) {
            printf("Erro ao alocar colunas da matriz!\n");
            exit(1);
        }
    }

    return mat;
}


void imprime_matriz(float **mat, int n, int m){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%.2f ", mat[i][j]);
        }
        printf("\n");  
    }

}

float soma_matriz(float** mat, int n, int m){
    float soma = 0.0;

    for (int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            soma+=mat[i][j];
        }
    }
    return soma;
}

float subtracao_matriz(float** mat, int n, int m){
    float subtracao = 0.0;

    for (int i=0; i < n; i++){
        for(int j=0; j < m; j++){
            subtracao-=mat[i][j];
        }
    }
    return subtracao;
}

void libera_matriz(float** mat, int n){
    for(int i = 0; i < n; i++){
        free(mat[i]);
    }
    free(mat);
}

float** transpor_matriz(float** mat, int n, int m){

    float** mat_t = cria_matriz(n, m);

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            mat_t[j][i] = mat[i][j];
        }
    }
    return mat_t;
}