#include <stdio.h>
#include <stdlib.h>
#include "materias.c"
#include "estudiantes.c"

/* MATERIAS
-Dar de alta, modificar, eliminar y listar estudiantes
-Buscar estudiantes por nombre
-Buscar estudiantes por rango de edad
*/

/*
int main()
{
    linked_list *ll = new_linked_list();
    // append(ll, 1);
    
    print_linked_list(ll);
    printf("\n");
    
    append(ll, 2);
    append(ll, 3);
    print_linked_list(ll);
    preppend(ll, 4);
    printf("\n");
    print_linked_list(ll);
    
    
    printf("\n");
    print_linked_list(ll);

    delete_last(ll);

    printf("\n");
    print_linked_list(ll);
    

    int n = 1;
    delete_node(ll, n);

    printf("\nAFTER DELETE NODE WITH %d\n", n);

    print_linked_list(ll);
    
    return 0;
}
*/

int main() {
    char nombre[50] = "Pepe";
    int edad = 20;

    linked_list_estudiantes* ll_estudiantes = crear_linked_list_estudiantes();
    listar_estudiantes(ll_estudiantes);

    dar_alta_estudiante(ll_estudiantes, nombre, edad, NULL);
    listar_estudiantes(ll_estudiantes);
    
    estudiante* e = buscar_estudiante_por_nombre(ll_estudiantes, "Pepe");
    // printf("EDAD=%d\n", e->edad);
    anotarse_en_materia(e, "Algebra", 11.0, "10-03-24");

    listar_estudiantes(ll_estudiantes);

    // printf("EDAD=%d\n", e->edad);
}
