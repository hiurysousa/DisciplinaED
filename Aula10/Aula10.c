#include <stdio.h>
#include <stdlib.h>

void imprime(char *s);
int comprimento(char *s);
void copia(char *dest, char *orig);
void concatena(char *dest, char *orig);

int main(){
    int size;

    char nome[] = "Hiury";    
    char* nome_copia = (char *)malloc((comprimento(nome) + 1) * sizeof(char));
    char sobrenome[] = "Sousa";

    imprime(nome);

    size = comprimento(nome);
    printf("\nO tamanho do seu nome e %d \n", size);

    copia(nome_copia, nome);
    imprime(nome_copia);

    concatena(nome, sobrenome);
    printf("\nResultado da concatenacao: %s", nome);

    return 0;
}

void imprime(char *s){
    int i;
    for (i = 0; s[i] != '\0'; i++){
        printf("%c", s[i]);
    }

}

int comprimento(char *s){
    int i = 0;
    int n = 0; //contador
    for (i = 0; s[i] != '\0'; i++){
        n++;
    }
    return n;
}

void copia(char *dest, char *orig){
    int i;
    for(i = 0; orig[i] != '\0'; i++){
        dest[i] = orig[i];
    }
    dest[i] = '\0';
}

void concatena(char *dest, char *orig){
    int i = 0;
    int j;
    i = 0;
    while(dest[i] != '\0'){
        i++;
    }
    for (j = 0; orig[j] != '\0'; j++){
        dest[i] = orig[j];
        i++;
    }
    dest[i] = '\0';
}