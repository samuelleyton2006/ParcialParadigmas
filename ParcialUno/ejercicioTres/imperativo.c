#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *nom;
    char *ape;
    unsigned char edad;
    char *id;
    int *notas;
    size_t num_notas;
} Alumno;

typedef struct {
    Alumno **alumnos;
    size_t num_alumnos;
} ListaAlumnos;

// Función para calcular la memoria ocupada por un alumno
size_t calcular_memoria_alumno(const Alumno *alum) {
    size_t memoria = 0;
    
    memoria += sizeof(Alumno);
    memoria += strlen(alum->nom) + 1;
    memoria += strlen(alum->ape) + 1;
    memoria += strlen(alum->id) + 1;
    memoria += alum->num_notas * sizeof(int);
    
    return memoria;
}

Alumno *nuevo_alumno(const char *nom, const char *ape, unsigned char edad, const char *id, int *notas, size_t num_notas) {
    Alumno *alum = (Alumno *)malloc(sizeof(Alumno));
    if (!alum) {
        printf("Error de memoria para el alumno.\n");
        return NULL;
    }

    alum->nom = strdup(nom);
    alum->ape = strdup(ape);
    alum->id = strdup(id);
    alum->edad = edad;

    alum->notas = (int *)malloc(num_notas * sizeof(int));
    if (!alum->notas) {
        free(alum->nom);
        free(alum->ape);
        free(alum->id);
        free(alum);
        return NULL;
    }
    for (size_t i = 0; i < num_notas; i++) {
        alum->notas[i] = notas[i];
    }
    alum->num_notas = num_notas;

    return alum;
}

void agregar_alumno(ListaAlumnos *lista, Alumno *alum) {
    lista->alumnos = realloc(lista->alumnos, (lista->num_alumnos + 1) * sizeof(Alumno *));
    if (!lista->alumnos) {
        printf("Error al redimensionar la lista de alumnos.\n");
        return;
    }
    lista->alumnos[lista->num_alumnos] = alum;
    lista->num_alumnos++;
}

void mostrar_lista(const ListaAlumnos *lista) {
    for (size_t i = 0; i < lista->num_alumnos; i++) {
        Alumno *alum = lista->alumnos[i];
        printf("Nombre: %s %s, Edad: %u, ID: %s\n", alum->nom, alum->ape, alum->edad, alum->id);
        printf("Notas: ");
        for (size_t j = 0; j < alum->num_notas; j++) {
            printf("%d ", alum->notas[j]);
        }
        printf("\nMemoria ocupada por este alumno: %zu bytes\n", calcular_memoria_alumno(alum));
    }
}

int main() {
    ListaAlumnos lista = {NULL, 0};

    int notas1[] = {85, 90, 78};
    Alumno *alum1 = nuevo_alumno("Sam", "Ley", 20, "12345678", notas1, 3);
    agregar_alumno(&lista, alum1);

    int notas2[] = {88, 92, 81};
    Alumno *alum2 = nuevo_alumno("Diom", "edez", 22, "87654321", notas2, 3);
    agregar_alumno(&lista, alum2);

    mostrar_lista(&lista);

    return 0;
}
