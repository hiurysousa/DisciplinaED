#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 50

char *duplica(char *s);
char *lelinha(void);
int lenomes(char **alunos);
void imprimenomes(int n, char **alunos);
void liberanomes(int n, char **alunos);

int main(){

    char *alunos[MAX];
    int n = lenomes(alunos);
    imprimenomes(n, alunos);
    liberanomes(n, alunos);
    return 0;

}

char *duplica(char *s){
    int n = 0;
    int i = 0;
    for (i = 0; s[i] != '\0'; i++){
        n++;
    }
     char *d = (char*)malloc((n+1)*sizeof(char));

    strcpy(d,s);
    return d;
}

char *lelinha(void){
    char linha[121];
    printf("Digite um nome: ");
    scanf("%120[^\n]", linha);
    getchar();
    return duplica(linha);
}

int lenomes(char **alunos){
    int i;
    int n;
    do {
        printf("Digite o numero de alunos: ");
        scanf("%d", &n);
        getchar();
    }   while(n > MAX);

    for(i = 0; i < n; i++){
        alunos[i] = lelinha();
    }
    return n;
}

void imprimenomes(int n, char **alunos){
    int i = 0;
    for (i = 0; i < n; i++){
        printf("%s\n", alunos[i]);
    }
}

void liberanomes(int n, char **alunos){
    for(int i = 0; i<n; i++){
        free(alunos[i]);
    }
}