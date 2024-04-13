#include <stdio.h>



// int sacarPromedio(/*int a, int b, int c*/){
//     return (a+b+c)/3;
// }

int main(){
    // printf("Primer promedio: %d\n", sacarPromedio(2,3,4));
    // printf("Segundo promedio: %d\n", sacarPromedio(10,5,15));
    // printf("Tercer promedio: %d\n", sacarPromedio(1,100,-2));

    int a = 0;
    int b = 0;
    int c = 0;
    printf("ingrese el primer numero ");
    scanf( "%d", &a);
    printf("ingrese el segundo numero ");
    scanf( "%d", &b);
    printf("ingrese el tercer numero ");
    scanf("%d", &c);
    printf("Promedio: %d\n", (a+b+c)/3);
    return 0;
}
