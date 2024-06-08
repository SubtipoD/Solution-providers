#include <stdio.h>
#include <stdlib.h>


// [ Estudiante ] funciona como nodo
typedef struct estudiante {
	char nombre[50];
	int  edad;
	linked_list_materias materias;
	struct estudiante* next_estudiante;
} estudiante;

// [ Lista estudiantes ]
typedef struct linked_list_estudiantes {
	estudiante* head;
	estudiante* tail;
} linked_list_estudiantes;
