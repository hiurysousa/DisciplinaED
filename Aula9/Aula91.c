#include <stdio.h>

int main(void){

    char cidade[] = "Sao Goncalo";
    char nome[51];

    printf("Digite seu nome: ");
    scanf("%s%*c    ", nome);
    
    printf("Seu nome eh %s \n", nome);
    printf("Vc nasceu em %s", cidade);

    return 0;
}