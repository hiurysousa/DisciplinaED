#include "TAD_MATRIZ.h"
#include <stdlib.h>

Matrix *mat_create(int lines, int columns){

    Matrix *mat = (Matrix*)malloc(sizeof(Matrix));
    if(!mat){
        printf("Nao ha memoria suficiente para alocar matriz.\n");
    }
    mat->colunas = columns;
    mat->linhas = lines;

    mat->values = (float**)malloc(lines * sizeof(float *));

    for(int i = 0; i < lines; i++){
        mat->values[i] = (float*)malloc(columns * sizeof(float));
        if(!mat->values[i]){
            printf("nao ha memorica suficiente para as linhas\n");
        }
        for (int j = 0; j < columns; j++){
            mat->values[i][j] = 0.0;
        }
    }

    return mat;
}

void mat_free(Matrix *mat);
float mat_read(Matrix *mat, int line, int column);
void mat_update(Matrix *mat, int line, int column, float value);
int mat_lines(Matrix *mat);
int mat_columns(Matrix *mat);
Matrix *mat_cpy(Matrix *mat);
void mat_transpose(Matrix *mat);
void mat_transpose_in_place(Matrix *mat);
Matrix *mat_sum(Matrix *A, Matrix *B);
void *mat_sum_in_place(Matrix *A, Matrix *B); // nao retorna nada, soma e volta pra A
Matrix *mat_sub(Matrix *A, Matrix *B);
Matrix *mat_mul(Matrix *A, Matrix *B);