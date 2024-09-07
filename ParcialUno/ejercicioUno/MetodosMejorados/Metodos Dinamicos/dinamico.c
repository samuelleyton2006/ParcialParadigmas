#include <stdio.h>

// Función para calcular el factorial utilizando programación dinámica
unsigned long long factorial(int n) {
    if (n < 0) {  // Verifica si el número es negativo
        printf("Error: El factorial no está definido para números negativos.\n");
        return 0;
    }

    // Arreglo para almacenar los resultados de los factoriales desde 0 hasta n
    unsigned long long tabla[n + 1];
    tabla[0] = 1;  // Factorial de 0 es 1

    // Calcular el factorial de 1 a n y almacenar en el arreglo
    for (int i = 1; i <= n; i++) {
        tabla[i] = i * tabla[i - 1];  // Utiliza el resultado del subproblema anterior
    }

    return tabla[n];  // Retorna el factorial de n
}

int main() {
    int numero;

    printf("Ingrese un número : ");
    if (scanf("%d", &numero) != 1) {
        printf("Error: Entrada inválida. Por favor, ingrese un número entero.\n");
        return 1;  
    }

    if (numero < 0) {
        printf("factorial no definido para negativos.\n");
    } else {
        unsigned long long resultado = factorial(numero);
        printf("factorial del numero %d es: %llu\n", numero, resultado);
    }

    return 0;
}