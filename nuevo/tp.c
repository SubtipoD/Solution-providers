#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estructura para representar una materia
typedef struct {
    char nombre[50];
    int codigo;
    // Otros campos de materia como creditos, etc.
} Materia;


// Nodo de la lista enlazada para estudiantes o materias
typedef struct Nodo {
    void* data;
    struct Nodo* next;
} Nodo;

// Estructura para representar un estudiante
typedef struct {
    char nombre[50];
    int edad;
    // Otros campos de estudiante como ID, etc.
     Nodo* inscripciones;
} Estudiante;


typedef struct {
    int codigo_materia;
    int rendido; // 0 para no rendido, 1 para rendido
} Inscripcion;

// Implementacion de las funciones para estudiantes
void altaEstudiante(Nodo** listaEstudiantes) {
    Estudiante* nuevoEstudiante = malloc(sizeof(Estudiante));
    if (nuevoEstudiante == NULL) {
        printf("Error: No se pudo asignar memoria para el estudiante.\n");
        return;
    }
    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nuevoEstudiante->nombre);
    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &nuevoEstudiante->edad);

    Nodo* nuevoNodo = malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        free(nuevoEstudiante);
        return;
    }
    nuevoNodo->data = nuevoEstudiante;
    nuevoNodo->next = *listaEstudiantes;
    *listaEstudiantes = nuevoNodo;

    printf("Estudiante agregado con exito.\n");
}

void modificarEstudiante(Nodo* listaEstudiantes) {
    char nombre[50];
    printf("Ingrese el nombre del estudiante a modificar: ");
    scanf("%s", nombre);

    Nodo* current = listaEstudiantes;
    while (current != NULL) {
        Estudiante* estudiante = (Estudiante*)current->data;
        if (strcmp(estudiante->nombre, nombre) == 0) {
            printf("Ingrese el nuevo nombre del estudiante: ");
            scanf("%s", estudiante->nombre);
            printf("Ingrese la nueva edad del estudiante: ");
            scanf("%d", &estudiante->edad);
            printf("Estudiante modificado con exito.\n");
            return;
        }
        current = current->next;
    }

    printf("No se encontro ningun estudiante con ese nombre.\n");
}

void eliminarEstudiante(Nodo** listaEstudiantes) {
    char nombre[50];
    printf("Ingrese el nombre del estudiante a eliminar: ");
    scanf("%s", nombre);

    Nodo* current = *listaEstudiantes;
    Nodo* prev = NULL;

    while (current != NULL) {
        Estudiante* estudiante = (Estudiante*)current->data;
        if (strcmp(estudiante->nombre, nombre) == 0) {
            if (prev == NULL) {
                *listaEstudiantes = current->next;
            } else {
                prev->next = current->next;
            }
            free(estudiante);
            free(current);
            printf("Estudiante eliminado con exito.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("No se encontro ningun estudiante con ese nombre.\n");
}

void listarEstudiantes(Nodo* listaEstudiantes) {
    printf("\nLista de estudiantes:\n");
    Nodo* current = listaEstudiantes;
    while (current != NULL) {
        Estudiante* estudiante = (Estudiante*)current->data;
        printf("Nombre: %s, Edad: %d\n", estudiante->nombre, estudiante->edad);
        current = current->next;
    }
}

void buscarEstudiantePorNombre(Nodo* listaEstudiantes, char nombre[]) {
    Nodo* current = listaEstudiantes;
    while (current != NULL) {
        Estudiante* estudiante = (Estudiante*)current->data;
        if (strcmp(estudiante->nombre, nombre) == 0) {
            printf("Nombre: %s, Edad: %d\n", estudiante->nombre, estudiante->edad);
            return;
        }
        current = current->next;
    }

    printf("No se encontro ningun estudiante con ese nombre.\n");
}

void buscarEstudiantePorEdad(Nodo* listaEstudiantes, int edad) {
    Nodo* current = listaEstudiantes;
    int found = 0;
    while (current != NULL) {
        Estudiante* estudiante = (Estudiante*)current->data;
        if (estudiante->edad == edad) {
            printf("Nombre: %s, Edad: %d\n", estudiante->nombre, estudiante->edad);
            found = 1;
        }
        current = current->next;
    }

    if (!found) {
        printf("No se encontro ningun estudiante con esa edad.\n");
    }
}

// Implementacion de las funciones para materias
void altaMateria(Nodo** listaMaterias) {
    Materia* nuevaMateria = malloc(sizeof(Materia));
    if (nuevaMateria == NULL) {
        printf("Error: No se pudo asignar memoria para la materia.\n");
        return;
    }
    printf("Ingrese el nombre de la materia: ");
    scanf("%s", nuevaMateria->nombre);
    printf("Ingrese el codigo de la materia: ");
    scanf("%d", &nuevaMateria->codigo);

    Nodo* nuevoNodo = malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        free(nuevaMateria);
        return;
    }
    nuevoNodo->data = nuevaMateria;
    nuevoNodo->next = *listaMaterias;
    *listaMaterias = nuevoNodo;

    printf("Materia agregada con exito.\n");
}

void modificarMateria(Nodo* listaMaterias) {
    int codigo;
    printf("Ingrese el codigo de la materia a modificar: ");
    scanf("%d", &codigo);

    Nodo* current = listaMaterias;
    while (current != NULL) {
        Materia* materia = (Materia*)current->data;
        if (materia->codigo == codigo) {
            printf("Ingrese el nuevo nombre de la materia: ");
            scanf("%s", materia->nombre);
            printf("Materia modificada con exito.\n");
            return;
        }
        current = current->next;
    }

    printf("No se encontro ninguna materia con ese codigo.\n");
}

void eliminarMateria(Nodo** listaMaterias) {
    int codigo;
    printf("Ingrese el codigo de la materia a eliminar: ");
    scanf("%d", &codigo);

    Nodo* current = *listaMaterias;
    Nodo* prev = NULL;

    while (current != NULL) {
        Materia* materia = (Materia*)current->data;
        if (materia->codigo == codigo) {
            if (prev == NULL) {
                *listaMaterias = current->next;
            } else {
                prev->next = current->next;
            }
            free(materia);
            free(current);
            printf("Materia eliminada con exito.\n");
            return;
        }
        prev = current;
        current = current->next;
    }

    printf("No se encontro ninguna materia con ese codigo.\n");
}

void listarMaterias(Nodo* listaMaterias) {
    printf("\nLista de materias:\n");
    Nodo* current = listaMaterias;
    while (current != NULL) {
        Materia* materia = (Materia*)current->data;
        printf("Nombre: %s, Codigo: %d\n", materia->nombre, materia->codigo);
        current = current->next;
    }
}

void inscribirEstudiante(Nodo** listaEstudiantes, Nodo** listaMaterias) {
    char nombreEstudiante[50];
    int codigoMateria;

    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nombreEstudiante);
    
    printf("Ingrese el codigo de la materia: ");
    scanf("%d", &codigoMateria);

    // Buscar el estudiante por nombre
    Nodo* currentEstudiante = *listaEstudiantes;
    Estudiante* estudiante = NULL;
    while (currentEstudiante != NULL) {
        Estudiante* currentEstudianteData = (Estudiante*)currentEstudiante->data;
        if (strcmp(currentEstudianteData->nombre, nombreEstudiante) == 0) {
            estudiante = currentEstudianteData;
            break;
        }
        currentEstudiante = currentEstudiante->next;
    }

    if (estudiante == NULL) {
        printf("No se encontró ningún estudiante con ese nombre.\n");
        return;
    }

    // Buscar la materia por código
    Nodo* currentMateria = *listaMaterias;
    Materia* materia = NULL;
    while (currentMateria != NULL) {
        Materia* currentMateriaData = (Materia*)currentMateria->data;
        if (currentMateriaData->codigo == codigoMateria) {
            materia = currentMateriaData;
            break;
        }
        currentMateria = currentMateria->next;
    }

    if (materia == NULL) {
        printf("No se encontró ninguna materia con ese código.\n");
        return;
    }

    // Crear una nueva inscripción
    Inscripcion* nuevaInscripcion = malloc(sizeof(Inscripcion));
    if (nuevaInscripcion == NULL) {
        printf("Error: No se pudo asignar memoria para la inscripción.\n");
        return;
    }
    nuevaInscripcion->codigo_materia = codigoMateria;
    nuevaInscripcion->rendido = 0; // No rendido aún

    // Agregar la inscripción a la lista de inscripciones del estudiante
    Nodo* nuevoNodo = malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        free(nuevaInscripcion);
        return;
    }
    nuevoNodo->data = nuevaInscripcion;
    nuevoNodo->next = estudiante->inscripciones;
    estudiante->inscripciones = nuevoNodo;

    printf("Estudiante inscrito en la materia con éxito.\n");
}

// void rendirExamen(Nodo* listaEstudiantes, int codigo_materia) {
//     char nombre[50];
//     printf("Ingrese el nombre del estudiante que rindió el examen: ");
//     scanf("%s", nombre);

//     Nodo* current = listaEstudiantes;
//     while (current != NULL) {
//         Estudiante* estudiante = (Estudiante*)current->data;
//         if (strcmp(estudiante->nombre, nombre) == 0) {
//             Nodo* inscripcionActual = estudiante->inscripciones;
//             while (inscripcionActual != NULL) {
//                 Inscripcion* inscripcion = (Inscripcion*)inscripcionActual->data;
//                 if (inscripcion->codigo_materia == codigo_materia) {
//                     inscripcion->rendido = 1; // Marcar examen como rendido
//                     printf("Examen registrado con éxito para el estudiante.\n");
//                     return;
//                 }
//                 inscripcionActual = inscripcionActual->next;
//             }
//             printf("El estudiante no está inscrito en esa materia.\n");
//             return;
//         }
//         current = current->next;
//     }

//     printf("No se encontró ningún estudiante con ese nombre.\n");
// }

void listarInscripcionesEstudiante(Nodo* listaEstudiantes, char nombre[]) {
    Nodo* current = listaEstudiantes;
    while (current != NULL) {
        Estudiante* estudiante = (Estudiante*)current->data;
        if (strcmp(estudiante->nombre, nombre) == 0) {
            printf("\nInscripciones para el estudiante %s:\n", nombre);
            Nodo* inscripcionActual = estudiante->inscripciones;
            while (inscripcionActual != NULL) {
                Inscripcion* inscripcion = (Inscripcion*)inscripcionActual->data;
                printf("Código de materia: %d, Rendido: %s\n", inscripcion->codigo_materia, inscripcion->rendido ? "Sí" : "No");
                inscripcionActual = inscripcionActual->next;
            }
            return;
        }
        current = current->next;
    }

    printf("No se encontró ningún estudiante con ese nombre.\n");
}

int main() {
    Nodo* listaEstudiantes = NULL;
    Nodo* listaMaterias = NULL;
    
    // Menu principal para seleccionar acciones
    int opcion;
    do {
        printf("\n1. Gestion de estudiantes\n");
        printf("2. Gestion de materias\n");
        printf("3. Inscribir estudiante en una materia\n");
        printf("4. Registrar resultado de examen\n");
        printf("50. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                // Menu para gestion de estudiantes
                printf("\n1. Alta de estudiante\n");
                printf("2. Modificar estudiante\n");
                printf("3. Eliminar estudiante\n");
                printf("4. Listar estudiantes\n");
                printf("5. Buscar estudiante por nombre\n");
                printf("6. Buscar estudiante por edad\n");
                printf("7. Volver al menu principal\n");
                printf("Seleccione una opcion: ");
                scanf("%d", &opcion);
                switch(opcion) {
                    case 1:
                        altaEstudiante(&listaEstudiantes);
                        break;
                    case 2:
                        modificarEstudiante(listaEstudiantes);
                        break;
                    case 3:
                        eliminarEstudiante(&listaEstudiantes);
                        break;
                    case 4:
                        listarEstudiantes(listaEstudiantes);
                        break;
                    case 5: {
                        char nombre[50];
                        printf("Ingrese el nombre del estudiante a buscar: ");
                        scanf("%s", nombre);
                        buscarEstudiantePorNombre(listaEstudiantes, nombre);
                        break;
                    }
                    case 6: {
                        int edad;
                        printf("Ingrese la edad del estudiante a buscar: ");
                        scanf("%d", &edad);
                        buscarEstudiantePorEdad(listaEstudiantes, edad);
                        break;
                    }
                    case 7:
                        // Volver al menu principal
                        break;
                    default:
                        printf("Opcion invalida. Intente de nuevo.\n");
                }
                break;
            case 2:
                // Menu para gestion de materias
                printf("\n1. Alta de materia\n");
                printf("2. Modificar materia\n");
                printf("3. Eliminar materia\n");
                printf("4. Listar materias\n");
                printf("5. Volver al menu principal\n");
                printf("Seleccione una opcion: ");
                scanf("%d", &opcion);
                switch(opcion) {
                    case 1:
                        altaMateria(&listaMaterias);
                        break;
                    case 2:
                        modificarMateria(listaMaterias);
                        break;
                    case 3:
                        eliminarMateria(&listaMaterias);
                        break;
                    case 4:
                        listarMaterias(listaMaterias);
                        break;
                    case 5:
                        // Volver al menu principal
                        break;
                    default:
                        printf("Opcion invalida. Intente de nuevo.\n");
                }
                break;
                 case 3:
                // Inscribir estudiante en una materia
                inscribirEstudiante(&listaEstudiantes, &listaMaterias);
                break;
            // case 4:
            //     // Registrar resultado de examen
            //     rendirExamen(listaEstudiantes);
            //     break;
            case 50:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 50);

    return 0;
}
