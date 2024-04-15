#include <stdio.h>
int main()
{
    int numeros[] = {12, 2, 3, 4, 11, 6, 547, 8, 9};
    int longitud = {sizeof(numeros) / sizeof(int)};
    int max = numeros[0];
    for (int i = 1; i < longitud; i++) {
    if (numeros[i] > max) {
        max= numeros[i];
    }
}
printf("maximo: %d", max);
return 0;
}