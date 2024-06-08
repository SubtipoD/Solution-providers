# Solution-providers
El melhor trabalho da vida


[ Estudiante ] funciona como nodo
typedef struct estudiante {
    char[] nombre;
    int    edad;
    linked_list_materias *materias;
    struct estudiante* next_estudiante;
} estudiante;


[ Lista estudiantes ]
typedef struct linked_list_estudiantes {
    estudiante* head;
    estudiante* tail;
} linked_list_estudiantes;


[ Materia ]
// Los nombres de las materias deberian estar definidos como constantes
typedef struct materia {
    char[] nombre;
    float  nota = NULL;
    char[] fecha_cursada = NULL;
    struct materia* next_materia;
} materia;


[ Lista materias ]
typedef struct linked_list_materia{
    materia* head;
    mateira* tail;
} linked_list_materia; 
