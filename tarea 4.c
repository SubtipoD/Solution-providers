#include<stdio.h>
int main() {
    int ingreso[3];
    int longitud = {sizeof(ingreso) / sizeof(int)};
    int sum = 0;
    printf("ingrese 3 enteros:");
    scanf("%d %d %d", &ingreso[0], &ingreso[1], ingreso [2]);
    for (int i = 0; i < longitud; i++) 
    {sum = sum + ingreso[i];
    }
float avg = (float) sum / sizeof(ingreso) * sizeof(int);
printf("Promedio: %f", avg);
return 0;
}