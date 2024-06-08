#include <stdio.h>
#include <stdlib.h>
// #include "materias.c"

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

// Crear estudiante
estudiante* crear_estudiante(char nombre[50], int edad, linked_list_materias* materias)
{
    estudiante* nuevo_estudiante = malloc(sizeof(estudiante*));

    strcpy(nuevo_estudiante->nombre, nombre);
    nuevo_estudiante->edad = edad;

    if (materias == NULL) {
        nuevo_estudiante->materias = crear_linked_list_materias();
    } else {
        nuevo_estudiante->materias = materias;
    }
    nuevo_estudiante->next_estudiante = NULL;

    return nuevo_estudiante;
}

linked_list_estudiantes* crear_linked_list_estudiantes() {
    linked_list_estudiantes* ll = malloc(sizeof(linked_list_estudiantes*));
    ll->head = NULL;
    ll->tail = NULL;
}

int lista_estudiantes_vacia(linked_list_estudiantes* ll) {
    return ll->head == NULL;
}

// Dar alta estudiante, agregarlo a la lista linkeada
void dar_alta_estudiante(linked_list_estudiantes* ll, char nombre[50], int edad, linked_list_materias* materias) {
    // Crear el nodo
    estudiante* nuevo_estudiante = crear_estudiante(nombre, edad, materias);

    // Agregar estudiante con lista vacia    
    if (lista_estudiantes_vacia(ll)) {
        ll->head = nuevo_estudiante;
        ll->tail = nuevo_estudiante;

        return;
    }

    // Agregar materia con lista no vacia
    ll->tail->next_estudiante = nuevo_estudiante;
    ll->tail = nuevo_estudiante;

    return;
}

// Modificar estudiante
void modificar_estudiante(linked_list_estudiantes* ll, char nombre_a_buscar[50], char nuevo_nombre[50], int nueva_edad) {
    estudiante* estudiante_actual = ll->head;

    while (estudiante_actual != NULL) {
        if (strcmp(nombre_a_buscar, estudiante_actual->nombre) == 0) {
            printf("Modificando valores del estudiante '%s' \n", nombre_a_buscar);
            strcpy(estudiante_actual->nombre, nuevo_nombre);
            estudiante_actual->edad = nueva_edad;

            return;
        }

        estudiante_actual = estudiante_actual->next_estudiante;
    }

    printf("estudiante '%s' no encontrada.\n", nombre_a_buscar);
}

// Eliminar estudiantes
void eliminar_estudiante(linked_list_estudiantes* ll, char nombre_a_buscar[50]) {
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

// Listar estudiantes
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

// Buscar estudiante por nombre
estudiante* buscar_estudiante_por_nombre(linked_list_estudiantes* ll, char nombre_a_buscar[50]) {
    estudiante* estudiante_actual = ll->head;

    while (estudiante_actual != NULL) {
        // Se encontro el nodo a eliminar
        if (strcmp(nombre_a_buscar, estudiante_actual->nombre) == 0) {
            return estudiante_actual;
        }

        estudiante_actual = estudiante_actual->next_estudiante;
    }

    return NULL;
}

/* Buscar estudiantes por rango de edad
    Devuelve una lista linkeada de estudiantes comprendidos entre el rango [min_edad ; max_edad]. La lista
    queda vacia si no hay estudiantes que cumplan con el requisito
*/
linked_list_estudiantes* buscar_estudiantes_rango_de_edad(linked_list_estudiantes* ll, int min_edad, int max_edad) {
    linked_list_estudiantes* nueva_ll = crear_linked_list_estudiantes();

    if (min_edad < 0 || max_edad < 0) {
        return nueva_ll;
    }

    if (max_edad < min_edad) {
        return nueva_ll;
    }

    estudiante* estudiante_actual = ll->head;

    while (estudiante_actual != NULL) {
        // Se encontro el nodo a eliminar
        if (min_edad <= estudiante_actual->edad && estudiante_actual->edad <= max_edad) {
            dar_alta_estudiante(nueva_ll, estudiante_actual->nombre, estudiante_actual->edad, estudiante_actual->materias);
        }

        estudiante_actual = estudiante_actual->next_estudiante;
    }

    return nueva_ll;
}

void anotarse_en_materia(estudiante* e, char nombre[50], float nota, char fecha_cursada[50]) {
    dar_alta_materia(e->materias, nombre, nota, fecha_cursada);
}
