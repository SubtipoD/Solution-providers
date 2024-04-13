#include <stdio.h>


int sacarMaximo(int arreglo[], int length){
    int maximo = arreglo[0];
    for (int i = 0; i <  length; i++){
        if (arreglo[i]>maximo){
            maximo = arreglo[i];
        }
        
    }
    return maximo;
 }

int main(){
    int arregloUno[] = {3,1,6,8,0,1,123,53,1,3};
    int lengthUno = sizeof(arregloUno) / sizeof(int);
    int maxUno = sacarMaximo(arregloUno, lengthUno);
    printf("primer maximo %d\n", maxUno);

    int arregloDos[] = {3,1,6,8,0,1,13,53,1,3};
    int lengthDos = sizeof(arregloDos) / sizeof(int);
    int maxDos = sacarMaximo(arregloDos, lengthDos);
    printf("segundo maximo %d\n", maxDos);

    int arregloTres[] = {-3,1,6,-8,0,1,1,3};
    int lengthTres = sizeof(arregloTres) / sizeof(int);
    int maxTres = sacarMaximo(arregloTres, lengthTres);
    printf("tercer maximo %d\n", maxTres);
    
    return 0;
}

 