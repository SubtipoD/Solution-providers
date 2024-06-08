#include <stdio.h>
#include <stdlib.h>
#include "materias.c"

// [ Estudiante ] funciona como nodo
typedef struct estudiante {
	char nombre[50];
	int  edad;
	linked_list_materias* materias;
	struct estudiante* next_estudiante;
} estudiante;

// [ Lista estudiantes ]
typedef struct linked_list_estudiantes {
	estudiante* head;
	estudiante* tail;
} linked_list_estudiantes;






estudiante* crear_estudiante(char nombre[50], int edad)
{
    estudiante* nuevo_estudiante = malloc(sizeof(estudiante*));

    strcpy(nuevo_estudiante->nombre, nombre);
    nuevo_estudiante->edad = edad;
    nuevo_estudiante->materias = NULL;
    nuevo_estudiante->next_estudiante = crear_linked_list_materia();

    return nuevo_estudiante;
}

linked_list_estudiantes* crear_linked_list_estudiantes() {
    linked_list_estudiantes* ll = malloc(sizeof(linked_list_estudiantes*));
    ll->head = NULL;
    ll->tail = NULL;
}

int lista_estudiantes_vacia(linked_list_materia* ll) {
    return ll->head == NULL;
}

void dar_alta_estudiante(linked_list_estudiantes* ll, char nombre[50], int edad) {
    // Crear el nodo
    estudiante* nuevo_estudiante = crear_estudiante(nombre, edad);

    // Agregar estudiante con lista vacia    
    if (lista_estudiante_vacia(ll)) {
        ll->head = nuevo_estudiante;
        ll->tail = nuevo_estudiante;

        return;
    }

    // Agregar materia con lista no vacia
    ll->tail->next_estudiante = nuevo_estudiante;
    ll->tail = nuevo_estudiante;

    return;
}

void modificar_estudiante(linked_list_estudiantes* ll, char nombre_a_buscar[50], char nuevo_nombre[50], int nueva_edad) {
    estudiante* estudiante_actual = ll->head;

    while (estudiante_actual != NULL) {
        if (strcmp(nombre_a_buscar, estudiante_actual->nombre) == 0) {
            printf("Modificando valores del estudiante '%s' \n", nombre_a_buscar);
            strcpy(estudiante_actual->nombre, nuevo_nombre);
            estudiante_actual->nota = nueva_nota;

            return;
        }

        estudiante_actual = estudiante_actual->next_estudiante;
    }

    printf("estudiante '%s' no encontrada.\n", nombre_a_buscar);
}

void eliminar_estudiante(linked_list_estudiantes* ll, char nombre[50]) {
    // Eliminar primer elemento de la lista
    if (strcmp(nombre_a_buscar, ll->head->nombre) == 0) {
        estudiante* estudiante_a_eliminar = ll->head;
        ll->head = ll->head->next_estudiante;
        free(estudiante_a_eliminar);

        return;
    }
    
    estudiante* estudiante_actual = ll->head;

    while (estudiante_actual != NULL) {
        // Se encontro el nodo a eliminar
        if (strcmp(nombre_a_buscar, estudiante_actual->next_estudiante->nombre) == 0) {
            // El nodo a eliminar es el ultimo de la lista
            if (estudiante_actual->next_estudiante->next_estudiante == NULL) {
                estudiante* estudiante_a_eliminar = estudiante_actual->next_estudiante;
                ll->tail = estudiante_actual;
                free(estudiante_a_eliminar);

                return;
            }
            else {
                estudiante* estudiante_a_eliminar = estudiante_actual->next_estudiante;
                estudiante_actual->next_estudiante = estudiante_actual->next_estudiante->next_estudiante;
                free(estudiante_a_eliminar);

                return;
            }
        }

        estudiante_actual = estudiante_actual->next_estudiante;
    }

    return;
}

void listar_estudiantes(linked_list_estudiantes* ll) {
    if (lista_estudiantes_vacia(ll)) {
        printf("No hay estudiantes definidas.\n");
    }

    estudiante* estudiante_actual = ll->head;

    while (estudiante_actual != NULL) {
        printf("[%s]\n", estudiante_actual->nombre);
        printf("Edad: %d\n", estudiante_actual->edad);
        printf("Materias cursadas:\n");
        printf("------------------\n");
        listar_materias(estudiante_actual->materias);
        printf("\n");

        estudiante_actual = estudiante_actual->next_estudiante;
    }

    return;
}
