#include <stdio.h>

int main (){

   /* int f;
    float p;
    float h;

    printf("Digite a altura em metros: ");
    scanf("%f", &h);

    h = 100*h;
    f = (int) (h/30.48);
    p = (h-f*30.48)/2.54;

    printf("Altura: %d ft %.1f pol\n", f, p);

    return 0;
    */

   int a, b, maior;

   scanf("%d", &a);
   scanf("%d", &b);

    printf("Maior numero digitado foi %d", a > b ? a : b);

    return 0;
}