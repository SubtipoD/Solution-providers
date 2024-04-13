#include <stdio.h>


int main(){
    char nombre[100];
    int edad;
    int confirmaciones;
    printf("Nombre por favor ");
    scanf("%s", nombre);
    printf("ingrese su edad ");
    scanf("%d", &edad);
    printf("se llama %s y tiene %d anos, verdad? (ponga 1 para correcto o 0 para incorrecto)\n", nombre, edad);
    scanf("%d", &confirmaciones);
    
    

    if (confirmaciones == 1)
    {
        printf("perfecto, ya tenemos sus datos");
    } else if (confirmaciones == 0)
    {
        printf("Se ha producido un error en el sistema, intente nuevamente o contactese con soporte tecnico");
    } else{
        printf("Vuelva a ingresar sus datos correctamente");
    }
    
    return 0;
}