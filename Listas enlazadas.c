//Codigo basico sobre listas enlazadas explicado para que me sirva de apoyo

#include <stdio.h>     // Para funciones de entrada/salida como printf y scanf
#include <stdlib.h>    // Para funciones como malloc y free (gestión de memoria)
#include <string.h>    // Para manejo de strings (no se usa en este código, pero está incluido)
#define CANT 30        // Cantidad máxima de caracteres para nombre y apellido
#define SALIR 1        // Constante que representa la opción para salir del ingreso de alumnos

// Definición de la estructura alumno
typedef struct alumno {
    char nombre[CANT];         // Nombre del alumno
    char apellido[CANT];       // Apellido del alumno
    struct alumno *next;       // Puntero al siguiente alumno en la lista
} alumno_t;

// Prototipos de funciones
void imprimir(alumno_t *);            // Imprime todos los alumnos de la lista
alumno_t * agregar_alumno(alumno_t *);// Agrega un nuevo alumno a la lista
int salir(void);                      // Pregunta si el usuario quiere salir
void liberar(alumno_t *);             // Libera la memoria de la lista

// Función principal
int main() {
    alumno_t *_6TEL = NULL;   // Inicializa la lista vacía (puntero a NULL)

    do {
        _6TEL = agregar_alumno(_6TEL);  // Agrega un alumno y actualiza la lista
    } while (salir() != SALIR);         // Repite hasta que el usuario elija salir

    imprimir(_6TEL);    // Imprime todos los alumnos de la lista
    liberar(_6TEL);     // Libera la memoria ocupada por la lista

    return 0;           // Fin del programa
}

// Función para imprimir la lista de alumnos
void imprimir(alumno_t *lista) {
    while (lista != NULL) {                                // Mientras haya nodos en la lista
        printf("Nombre %s\n", lista->nombre);              // Imprime el nombre
        printf("Apellido %s\n", lista->apellido);          // Imprime el apellido
        lista = lista->next;                               // Avanza al siguiente nodo
    }
}

// Función para agregar un alumno a la lista
alumno_t * agregar_alumno(alumno_t *lista) {
    alumno_t *alu_ptr = (alumno_t *)malloc(sizeof(alumno_t));  // Reserva memoria para un nuevo alumno

    alu_ptr->next = lista;        // El nuevo nodo apunta al inicio de la lista actual

    printf("Ingrese el nombre:\n");    // Pide el nombre
    scanf("%s", alu_ptr->nombre);      // Guarda el nombre ingresado

    printf("Ingrese el apellido:\n");  // Pide el apellido
    scanf("%s", alu_ptr->apellido);    // Guarda el apellido ingresado

    lista = alu_ptr;                   // Actualiza la lista: ahora empieza por el nuevo alumno

    printf("Alumno creado exitosamente!\n");  // Mensaje de éxito
    return lista;                     // Devuelve el nuevo comienzo de la lista
}

// Función que pregunta si se desea seguir ingresando alumnos
int salir(void) {
    int salir = 0;                                     // Variable que guarda la decisión del usuario

    printf("Desea agregar un alumno más?\n");          // Mensaje de consulta
    printf("0 para sí, %d para no\n", SALIR);          // Opciones disponibles

    scanf("%d", &salir);                               // Lee la opción elegida
    return salir;                                      // Devuelve la decisión
}

// Función para liberar la memoria de la lista
void liberar(alumno_t *lista) {
    alumno_t *aux;                           // Puntero auxiliar para recorrer la lista

    while (lista != NULL) {                  // Mientras haya nodos
        aux = lista;                         // Guarda el nodo actual
        lista = lista->next;                 // Avanza al siguiente
        free(aux);                           // Libera el nodo guardado
    }
}
