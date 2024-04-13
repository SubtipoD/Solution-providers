#include <stdio.h>


int sacarMinimo(int arreglo[], int length){
    int minimo = arreglo[0];
    for (int i = 0; i <  length; i++){
        if (arreglo[i]<minimo){
            minimo = arreglo[i];
        }
        
    }
    return minimo;
 }

int main(){
    int arregloUno[] = {3,2,6,8,1,123,53,5,3};
    int lengthUno = sizeof(arregloUno) / sizeof(int);
    int maxUno = sacarMinimo(arregloUno, lengthUno);
    printf("primer minimo %d\n", maxUno);

    int arregloDos[] = {3,-1,6,8,0,1,13,-53,1,3};
    int lengthDos = sizeof(arregloDos) / sizeof(int);
    int maxDos = sacarMinimo(arregloDos, lengthDos);
    printf("segundo minimo %d\n", maxDos);

    int arregloTres[] = {-3,1,6,-8,0,1,1,3};
    int lengthTres = sizeof(arregloTres) / sizeof(int);
    int maxTres = sacarMinimo(arregloTres, lengthTres);
    printf("tercer minimo %d\n", maxTres);
    
    return 0;
}