#include <stdio.h>
int main()
{
    int numeros[] = {1, -9, 3, 24, 15, 7};
    int longitud = {sizeof(numeros) / sizeof(int)};
    int min = numeros[0];
    for (int i = 1; i < longitud; i++) {
    if (numeros[i] < min) {
        min= numeros[i];
    }
}
printf("min: %d", min);
return 0;
}