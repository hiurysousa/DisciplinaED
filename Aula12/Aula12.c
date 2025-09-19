#include <stdio.h>
#include <stdlib.h>
// typedef char* String; -> Isso basicamente define o termo char* como String, então posso usar String nome[6] = "Hiury";


void imprime_rec(char *s);
void imprime_inv(char *s);
int comprimento_rec(char *s);
void copia_rec(char *dest, char *orig);


int main(){

    char string[8] = "Aracati";
    imprime_rec(string);

    int tamanho = comprimento_rec(string);
    printf("\n tamanho da palavra %d", tamanho);

    char copia_nome[8];
    copia_rec(copia_nome, string);

    printf("\n");
    imprime_rec(copia_nome);

    return 0;
}

void imprime_rec(char *s){
    if(s[0] != '\0'){
        printf("%c", s[0]); // ou putchar(*s) ou putchar(s[0]);
        imprime_rec(&s[1]);
    }
}

void imprime_inv(char *s){
    if(s[0] != '\0'){
        imprime_inv(&s[1]);
        printf("%c", s[0]);
    }
}

int comprimento_rec(char *s){
    if(s[0] == '\0'){
        return 0;
    } else {
        return 1 + comprimento_rec(&s[1]);
    }
}

void copia_rec(char *dest, char *orig){
    if(orig[0] == '\0'){
        dest[0] = '\0';
    } else {
        dest[0] = orig[0];
        copia_rec(&dest[1], &orig[1]);
    }
}