#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATERIAS 10

// Estructura para representar una materia
typedef struct {
    char nombre[50];
    int codigo;
    int nota; // Nota de la materia (inicialmente -1 para indicar que no ha sido rendida)
    int aprobado; // 1 si esta aprobada, 0 si no
} Materia;

// Estructura para representar un estudiante
typedef struct {
    char nombre[50];
    int edad;
    Materia* materias[MAX_MATERIAS]; // Lista de punteros a materias
    int num_materias; // Numero de materias inscritas
} Estudiante;

// Nodo de la lista enlazada para estudiantes o materias
typedef struct Nodo {
    void* data;
    struct Nodo* next;
} Nodo;

// Funciones para estudiantes
void altaEstudiante(Nodo** listaEstudiantes);
void modificarEstudiante(Nodo* listaEstudiantes);
void eliminarEstudiante(Nodo** listaEstudiantes);
void listarEstudiantes(Nodo* listaEstudiantes);
void buscarEstudiantePorNombre(Nodo* listaEstudiantes, char nombre[]);
void buscarEstudiantePorEdad(Nodo* listaEstudiantes, int edad);
void anotarEstudianteEnMateria(Nodo* listaEstudiantes, Nodo* listaMaterias);
void rendirMateria(Nodo* listaEstudiantes);
void calcularEstadisticas(Nodo* listaEstudiantes, Nodo* listaMaterias);

// Funciones para materias
void altaMateria(Nodo** listaMaterias);
void modificarMateria(Nodo* listaMaterias);
void eliminarMateria(Nodo** listaMaterias);
void listarMaterias(Nodo* listaMaterias);

int main() {
    Nodo* listaEstudiantes = NULL;
    Nodo* listaMaterias = NULL;
    
    int opcion;
    do {
        printf("\n1. Alta de estudiante\n");
        printf("2. Alta de materia\n");
        printf("3. Anotar estudiante en materia\n");
        printf("4. Rendir materia\n");
        printf("5. Listar estudiantes\n");
        printf("6. Listar materias\n");
        printf("7. Modificar estudiante\n");
        printf("8. Modificar materia\n");
        printf("9. Eliminar estudiante\n");
        printf("10. Eliminar materia\n");
        printf("11. Buscar estudiante por nombre\n");
        printf("12. Buscar estudiante por edad\n");
        printf("13. Calcular estadisticas\n");
        printf("14. Salir\n");
        printf("Seleccione una opcion: ");
        scanf("%d", &opcion);
        
        switch (opcion) {
            case 1:
                altaEstudiante(&listaEstudiantes);
                break;
            case 2:
                altaMateria(&listaMaterias);
                break;
            case 3:
                anotarEstudianteEnMateria(listaEstudiantes, listaMaterias);
                break;
            case 4:
                rendirMateria(listaEstudiantes);
                break;
            case 5:
                listarEstudiantes(listaEstudiantes);
                break;
            case 6:
                listarMaterias(listaMaterias);
                break;
            case 7:
                modificarEstudiante(listaEstudiantes);
                break;
            case 8:
                modificarMateria(listaMaterias);
                break;
            case 9:
                eliminarEstudiante(&listaEstudiantes);
                break;
            case 10:
                eliminarMateria(&listaMaterias);
                break;
            case 11:
                {
                    char nombre[50];
                    printf("Ingrese el nombre del estudiante: ");
                    scanf("%s", nombre);
                    buscarEstudiantePorNombre(listaEstudiantes, nombre);
                }
                break;
            case 12:
                {
                    int edad;
                    printf("Ingrese la edad del estudiante: ");
                    scanf("%d", &edad);
                    buscarEstudiantePorEdad(listaEstudiantes, edad);
                }
                break;
            case 13:
                calcularEstadisticas(listaEstudiantes, listaMaterias);
                break;
            case 14:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida. Intente de nuevo.\n");
        }
    } while (opcion != 14);

    return 0;
}

// Funciones para estudiantes
void altaEstudiante(Nodo** listaEstudiantes) {
    Estudiante* nuevoEstudiante = (Estudiante*)malloc(sizeof(Estudiante));
    if (nuevoEstudiante == NULL) {
        printf("Error: No se pudo asignar memoria para el estudiante.\n");
        return;
    }

    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nuevoEstudiante->nombre);
    printf("Ingrese la edad del estudiante: ");
    scanf("%d", &nuevoEstudiante->edad);
    nuevoEstudiante->num_materias = 0;

    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        free(nuevoEstudiante);
        return;
    }

    nuevoNodo->data = nuevoEstudiante;
    nuevoNodo->next = NULL;

    if (*listaEstudiantes == NULL) {
        *listaEstudiantes = nuevoNodo;
    } else {
        Nodo* temp = *listaEstudiantes;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuevoNodo;
    }

    printf("Estudiante agregado exitosamente.\n");
}

void listarEstudiantes(Nodo* listaEstudiantes) {
    if (listaEstudiantes == NULL) {
        printf("No hay estudiantes registrados.\n");
        return;
    }

    printf("Lista de Estudiantes:\n");
    while (listaEstudiantes != NULL) {
        Estudiante* estudiante = (Estudiante*)listaEstudiantes->data;
        printf("Nombre: %s, Edad: %d\n", estudiante->nombre, estudiante->edad);
        for (int i = 0; i < estudiante->num_materias; i++) {
            printf("\tMateria: %s, Nota: %d, Aprobada: %s\n", estudiante->materias[i]->nombre, estudiante->materias[i]->nota, estudiante->materias[i]->aprobado ? "Si" : "No");
        }
        listaEstudiantes = listaEstudiantes->next;
    }
}

void modificarEstudiante(Nodo* listaEstudiantes) {
    char nombre[50];
    printf("Ingrese el nombre del estudiante a modificar: ");
    scanf("%s", nombre);

    Nodo* temp = listaEstudiantes;
    while (temp != NULL) {
        Estudiante* estudiante = (Estudiante*)temp->data;
        if (strcmp(estudiante->nombre, nombre) == 0) {
            printf("Ingrese el nuevo nombre del estudiante: ");
            scanf("%s", estudiante->nombre);
            printf("Ingrese la nueva edad del estudiante: ");
            scanf("%d", &estudiante->edad);
            printf("Estudiante modificado exitosamente.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Estudiante no encontrado.\n");
}

void eliminarEstudiante(Nodo** listaEstudiantes) {
    char nombre[50];
    printf("Ingrese el nombre del estudiante a eliminar: ");
    scanf("%s", nombre);

    Nodo *temp = *listaEstudiantes, *prev = NULL;
    while (temp != NULL) {
        Estudiante* estudiante = (Estudiante*)temp->data;
        if (strcmp(estudiante->nombre, nombre) == 0) {
            if (prev == NULL) {
                *listaEstudiantes = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(estudiante);
            free(temp);
            printf("Estudiante eliminado exitosamente.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Estudiante no encontrado.\n");
}

void buscarEstudiantePorNombre(Nodo* listaEstudiantes, char nombre[]) {
    while (listaEstudiantes != NULL) {
        Estudiante* estudiante = (Estudiante*)listaEstudiantes->data;
        if (strcmp(estudiante->nombre, nombre) == 0) {
            printf("Nombre: %s, Edad: %d\n", estudiante->nombre, estudiante->edad);
            for (int i = 0; i < estudiante->num_materias; i++) {
                printf("\tMateria: %s, Nota: %d, Aprobada: %s\n", estudiante->materias[i]->nombre, estudiante->materias[i]->nota, estudiante->materias[i]->aprobado ? "Si" : "No");
            }
            return;
        }
        listaEstudiantes = listaEstudiantes->next;
    }
    printf("Estudiante no encontrado.\n");
}

void buscarEstudiantePorEdad(Nodo* listaEstudiantes, int edad) {
    int encontrado = 0;
    while (listaEstudiantes != NULL) {
        Estudiante* estudiante = (Estudiante*)listaEstudiantes->data;
        if (estudiante->edad == edad) {
            printf("Nombre: %s, Edad: %d\n", estudiante->nombre, estudiante->edad);
            for (int i = 0; i < estudiante->num_materias; i++) {
                printf("\tMateria: %s, Nota: %d, Aprobada: %s\n", estudiante->materias[i]->nombre, estudiante->materias[i]->nota, estudiante->materias[i]->aprobado ? "Si" : "No");
            }
            encontrado = 1;
        }
        listaEstudiantes = listaEstudiantes->next;
    }
    if (!encontrado) {
        printf("No se encontraron estudiantes con la edad %d.\n", edad);
    }
}

void anotarEstudianteEnMateria(Nodo* listaEstudiantes, Nodo* listaMaterias) {
    char nombreEstudiante[50];
    int codigoMateria;

    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nombreEstudiante);
    printf("Ingrese el codigo de la materia: ");
    scanf("%d", &codigoMateria);

    Nodo* tempEstudiante = listaEstudiantes;
    while (tempEstudiante != NULL) {
        Estudiante* estudiante = (Estudiante*)tempEstudiante->data;
        if (strcmp(estudiante->nombre, nombreEstudiante) == 0) {
            Nodo* tempMateria = listaMaterias;
            while (tempMateria != NULL) {
                Materia* materia = (Materia*)tempMateria->data;
                if (materia->codigo == codigoMateria) {
                    if (estudiante->num_materias < MAX_MATERIAS) {
                        estudiante->materias[estudiante->num_materias] = materia;
                        estudiante->num_materias++;
                        printf("Estudiante %s anotado en la materia %s.\n", estudiante->nombre, materia->nombre);
                    } else {
                        printf("El estudiante ya esta inscrito en el maximo de materias permitidas.\n");
                    }
                    return;
                }
                tempMateria = tempMateria->next;
            }
            printf("Materia no encontrada.\n");
            return;
        }
        tempEstudiante = tempEstudiante->next;
    }
    printf("Estudiante no encontrado.\n");
}

void rendirMateria(Nodo* listaEstudiantes) {
    char nombreEstudiante[50];
    int codigoMateria, nota;

    printf("Ingrese el nombre del estudiante: ");
    scanf("%s", nombreEstudiante);
    printf("Ingrese el codigo de la materia: ");
    scanf("%d", &codigoMateria);
    printf("Ingrese la nota: ");
    scanf("%d", &nota);

    Nodo* tempEstudiante = listaEstudiantes;
    while (tempEstudiante != NULL) {
        Estudiante* estudiante = (Estudiante*)tempEstudiante->data;
        if (strcmp(estudiante->nombre, nombreEstudiante) == 0) {
            for (int i = 0; i < estudiante->num_materias; i++) {
                if (estudiante->materias[i]->codigo == codigoMateria) {
                    estudiante->materias[i]->nota = nota;
                    estudiante->materias[i]->aprobado = (nota >= 4) ? 1 : 0;
                    printf("Nota registrada para la materia %s. %s.\n", estudiante->materias[i]->nombre, estudiante->materias[i]->aprobado ? "Materia aprobada" : "Materia no aprobada");
                    return;
                }
            }
            printf("Materia no encontrada en la lista del estudiante.\n");
            return;
        }
        tempEstudiante = tempEstudiante->next;
    }
    printf("Estudiante no encontrado.\n");
}

// Funciones para materias
void altaMateria(Nodo** listaMaterias) {
    Materia* nuevaMateria = (Materia*)malloc(sizeof(Materia));
    if (nuevaMateria == NULL) {
        printf("Error: No se pudo asignar memoria para la materia.\n");
        return;
    }

    printf("Ingrese el nombre de la materia: ");
    scanf("%s", nuevaMateria->nombre);
    printf("Ingrese el codigo de la materia: ");
    scanf("%d", &nuevaMateria->codigo);
    nuevaMateria->nota = -1; // Inicialmente sin nota
    nuevaMateria->aprobado = 0; // Inicialmente no aprobada

    Nodo* nuevoNodo = (Nodo*)malloc(sizeof(Nodo));
    if (nuevoNodo == NULL) {
        printf("Error: No se pudo asignar memoria para el nodo.\n");
        free(nuevaMateria);
        return;
    }

    nuevoNodo->data = nuevaMateria;
    nuevoNodo->next = NULL;

    if (*listaMaterias == NULL) {
        *listaMaterias = nuevoNodo;
    } else {
        Nodo* temp = *listaMaterias;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = nuevoNodo;
    }

    printf("Materia agregada exitosamente.\n");
}

void listarMaterias(Nodo* listaMaterias) {
    if (listaMaterias == NULL) {
        printf("No hay materias registradas.\n");
        return;
    }

    printf("Lista de Materias:\n");
    while (listaMaterias != NULL) {
        Materia* materia = (Materia*)listaMaterias->data;
        printf("Nombre: %s, Codigo: %d\n", materia->nombre, materia->codigo);
        listaMaterias = listaMaterias->next;
    }
}

void modificarMateria(Nodo* listaMaterias) {
    int codigo;
    printf("Ingrese el codigo de la materia a modificar: ");
    scanf("%d", &codigo);

    Nodo* temp = listaMaterias;
    while (temp != NULL) {
        Materia* materia = (Materia*)temp->data;
        if (materia->codigo == codigo) {
            printf("Ingrese el nuevo nombre de la materia: ");
            scanf("%s", materia->nombre);
            printf("Materia modificada exitosamente.\n");
            return;
        }
        temp = temp->next;
    }
    printf("Materia no encontrada.\n");
}

void eliminarMateria(Nodo** listaMaterias) {
    int codigo;
    printf("Ingrese el codigo de la materia a eliminar: ");
    scanf("%d", &codigo);

    Nodo *temp = *listaMaterias, *prev = NULL;
    while (temp != NULL) {
        Materia* materia = (Materia*)temp->data;
        if (materia->codigo == codigo) {
            if (prev == NULL) {
                *listaMaterias = temp->next;
            } else {
                prev->next = temp->next;
            }
            free(materia);
            free(temp);
            printf("Materia eliminada exitosamente.\n");
            return;
        }
        prev = temp;
        temp = temp->next;
    }
    printf("Materia no encontrada.\n");
}

void calcularEstadisticas(Nodo* listaEstudiantes, Nodo* listaMaterias) {
    int totalEstudiantes = 0;
    int totalMaterias = 0;
    int estudiantesPorMateria[100] = {0};
    char* nombresMaterias[100];
    int numMaterias = 0;
    int totalAprobados = 0;
    int totalReprobados = 0;

    Nodo* tempEstudiante = listaEstudiantes;
    while (tempEstudiante != NULL) {
        Estudiante* estudiante = (Estudiante*)tempEstudiante->data;
        totalEstudiantes++;
        for (int i = 0; i < estudiante->num_materias; i++) {
            Materia* materia = estudiante->materias[i];
            int encontrada = 0;
            for (int j = 0; j < numMaterias; j++) {
                if (strcmp(nombresMaterias[j], materia->nombre) == 0) {
                    estudiantesPorMateria[j]++;
                    encontrada = 1;
                    break;
                }
            }
            if (!encontrada) {
                nombresMaterias[numMaterias] = materia->nombre;
                estudiantesPorMateria[numMaterias]++;
                numMaterias++;
            }
            if (materia->aprobado) {
                totalAprobados++;
            } else {
                totalReprobados++;
            }
        }
        tempEstudiante = tempEstudiante->next;
    }

    Nodo* tempMateria = listaMaterias;
    while (tempMateria != NULL) {
        totalMaterias++;
        tempMateria = tempMateria->next;
    }

    printf("\nEstadisticas:\n");
    printf("Total de estudiantes: %d\n", totalEstudiantes);
    printf("Total de materias: %d\n", totalMaterias);
    for (int i = 0; i < numMaterias; i++) {
        printf("Materia: %s, Estudiantes inscritos: %d\n", nombresMaterias[i], estudiantesPorMateria[i]);
    }
    printf("Total de materias aprobadas: %d\n", totalAprobados);
    printf("Total de materias reprobadas: %d\n", totalReprobados);

    // Determinar la materia mas concurrida
    int maxInscritos = 0;
    char* materiaMasConcurrida = NULL;
    for (int i = 0; i < numMaterias; i++) {
        if (estudiantesPorMateria[i] > maxInscritos) {
            maxInscritos = estudiantesPorMateria[i];
            materiaMasConcurrida = nombresMaterias[i];
        }
    }
    if (materiaMasConcurrida) {
        printf("La materia mas concurrida es: %s con %d estudiantes.\n", materiaMasConcurrida, maxInscritos);
    }
}