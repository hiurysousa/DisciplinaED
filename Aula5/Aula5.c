#include <stdio.h>

//argv vetor de strings -> ponteiro de ponteiro. Indíce 0 primeiro argumento e assim por diante.


int main(int argc, char *argv[]){
    
    printf("\n%d\n", argc);

    for(int i = 0; i < argc; i++){
        printf("%s\n\n", argv[i]);
    }

    return 0;
}

/*
Numeros de argv

Aulas_Main.exe - 0
--Force - 1 
Pull - 2
Fetch - 3
1,2,3,4 - 4

*/
