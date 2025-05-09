#include <stdio.h>

int eh_digito(char c);
char eh_letra(char c);
char maiuscula(char c);

int main(){

    char c = 'z';

    printf("%d : %c", c, c);

    if(eh_digito(c))
        printf("%c eh um digito...\n", c);
    else
        printf("%c nao eh um digito...", c);

    printf("\n");
    if(eh_letra(c))
        printf("%c eh uma letra...\n", c);
    else
        printf("%c nao eh uma letra...", c);

    printf("\n");
    maiuscula(c);
    printf("\n %c em maiusculo.", c);
    return 0;


}

int eh_digito(char c){
    return c >= 48 && c <= 57; // mesma coisa que if return 1 else return 0
      
}

char eh_letra(char c){
    if((c >= 65 && c <= 90) || (c >= 97 && c <= 122))
        return 1;
    else
        return 0;
}

char maiuscula(char c){
    if (c >= 'a' && c <= 'z')
        return c - 'a' + 'A';
    
     return c;
}