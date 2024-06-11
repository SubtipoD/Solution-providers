#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_MATERIAS 10

// Estructura para representar una materia
typedef struct {
    char nombre[50];
    int codigo;
    int nota; // Nota de la materia (inicialmente -1 para indicar que no ha sido rendida)
    int aprobado; // 1 si está aprobada, 0 si no
} Materia;

// Estructura para representar un estudiante
typedef struct {
    char nombre[50];
    int edad;
    Materia* materias[MAX_MATERIAS]; // Lista de punteros a materias
    int num_materias; // Número de materias inscritas
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
void calcularPromedioEstudiante(Nodo* listaEstudiantes, char nombre[]);
void calcularPromedioMateria(Nodo* listaEstudiantes, int codigoMateria);

// Funciones para materias
void altaMateria(Nodo** listaMaterias);
void modificarMateria(Nodo* listaMaterias);
void eliminarMateria(Nodo** listaMaterias);
void listarMaterias(Nodo* listaMaterias);
