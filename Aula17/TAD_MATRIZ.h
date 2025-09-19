#ifndef __TAD_MATRIZ__
    #define __TAD_MATRIZ__

    typedef struct matrix {
            int linhas;
            int colunas;
            float **values;
        } Matrix;

Matrix *mat_create(int lines, int columns);
void mat_free(Matrix *mat);
float mat_read(Matrix *mat, int line, int column);

void mat_update(Matrix *mat, int id_line, int id_column, float value){
    if(!(0 <= id_line && id_line < mat->linhas)){
       printf("a matriz nao tem %d linhas", id_line+1);
       exit(1);
    }
    if(!(0 <= id_column && id_column < mat->colunas)){
       printf("a matriz nao tem %d colunas", id_column+1);
       exit(1);
    }
}

int mat_lines(Matrix *mat);
int mat_columns(Matrix *mat);
Matrix *mat_cpy(Matrix *mat);
void mat_transpose(Matrix *mat);
void mat_transpose_in_place(Matrix *mat);
Matrix *mat_sum(Matrix *A, Matrix *B);
void *mat_sum_in_place(Matrix *A, Matrix *B); // nao retorna nada, soma e volta pra A
Matrix *mat_sub(Matrix *A, Matrix *B);
Matrix *mat_mul(Matrix *A, Matrix *B);



    #include "matriz.C"
#endif