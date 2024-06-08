#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// [ Materia ] funciona como nodo
// Los nombres de las materias deberian estar definidos como constantes
typedef struct materia {
	char  nombre[50];
	float nota;
	char  fecha_cursada[50];
	struct materia* next_materia;
} materia;

// [ Lista materias ]
typedef struct linked_list_materias {
	materia* head;
	materia* tail;
} linked_list_materias;

// Crear materia
materia* crear_materia(char nombre[50], float nota, char fecha_cursada[50])
{
    materia* nueva_materia = malloc(sizeof(materia*));
    strcpy(nueva_materia->nombre, nombre);
    // nueva_materia->nombre = nombre;
    nueva_materia->nota = nota;
    strcpy(nueva_materia->fecha_cursada, fecha_cursada);
    // nueva_materia->fecha_cursada = fecha_cursada;
    nueva_materia->next_materia = NULL;

    return nueva_materia;
}

linked_list_materias* crear_linked_list_materias() {
    linked_list_materias* ll = malloc(sizeof(linked_list_materias*));
    ll->head = NULL;
    ll->tail = NULL;
}

int lista_materia_vacia(linked_list_materias* ll) {
    return ll->head == NULL;
}

// Dar de alta materia
void dar_alta_materia(linked_list_materias* ll, char nombre[50], float nota, char fecha_cursada[50]) {
    
    // Crear el nodo
    materia* nueva_materia = crear_materia(nombre, nota, fecha_cursada);

    // Agregar materia con lista vacia    
    if (lista_materia_vacia(ll)) {
        ll->head = nueva_materia;
        ll->tail = nueva_materia;

        return;
    }

    // Agregar materia con lista no vacia
    ll->tail->next_materia = nueva_materia;
    ll->tail = nueva_materia;

    return;
}

// Modificar materia
void modificar_materia(linked_list_materias* ll, char nombre_a_buscar[50], char nuevo_nombre[50], float nueva_nota, char nueva_fecha_cursada[50]) {
    materia* materia_actual = ll->head;

    while (materia_actual != NULL) {
        if (strcmp(nombre_a_buscar, materia_actual->nombre) == 0) {
            printf("Modificando valores de la materia '%s' \n", nombre_a_buscar);
            strcpy(materia_actual->nombre, nuevo_nombre);
            materia_actual->nota = nueva_nota;
            strcpy(materia_actual->fecha_cursada, nueva_fecha_cursada);

            return;
        }

        materia_actual = materia_actual->next_materia;
    }

    printf("Materia '%s' no encontrada.\n", nombre_a_buscar);
}

// Eliminar materia
void eliminar_materia(linked_list_materias* ll, char nombre_a_buscar[50]) {
    // Eliminar primer elemento de la lista
    if (strcmp(nombre_a_buscar, ll->head->nombre) == 0) {
        materia* materia_a_eliminar = ll->head;
        ll->head = ll->head->next_materia;
        free(materia_a_eliminar);

        return;
    }
    
    materia* materia_actual = ll->head;

    while (materia_actual != NULL) {
        // Se encontro el nodo a eliminar
        if (strcmp(nombre_a_buscar, materia_actual->next_materia->nombre) == 0) {
            // El nodo a eliminar es el ultimo de la lista
            if (materia_actual->next_materia->next_materia == NULL) {
                materia* materia_a_eliminar = materia_actual->next_materia;
                ll->tail = materia_actual;
                free(materia_a_eliminar);

                return;
            }
            else {
                materia* materia_a_eliminar = materia_actual->next_materia;
                materia_actual->next_materia = materia_actual->next_materia->next_materia;
                free(materia_a_eliminar);

                return;
            }
        }

        materia_actual = materia_actual->next_materia;
    }

    return;
}

// Listar materias
void listar_materias(linked_list_materias* ll) {
    if (lista_materia_vacia(ll)) {
        printf("No hay materias definidas.\n");
    }

    materia* materia_actual = ll->head;

    while (materia_actual != NULL) {
        printf("[%s]\n", materia_actual->nombre);
        printf("Nota: %.2f\n", materia_actual->nota);
        printf("Fecha de cursada: %s\n", materia_actual->fecha_cursada);
        printf("\n");

        materia_actual = materia_actual->next_materia;
    }

    return;
}
