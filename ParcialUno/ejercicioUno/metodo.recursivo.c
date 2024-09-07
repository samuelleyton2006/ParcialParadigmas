#include <stdio.h>


unsigned long long factorial(int n) {
    if (n < 0) {  // Verifica si el número es negativo
        printf("Error: No funciona con numeros negativos.\n");
        return 0;
    }
    if (n == 0 || n == 1) {  // Caso base: factorial de 0 y 1 es 1
        return 1;
    } else {
        return n * factorial(n - 1);  // Llamada recursiva
    }
}

int main() {
    int numero;

    printf("número a calcular: ");
    if (scanf("%d", &numero) != 1) {
        printf("Error: Entrada inválida.Ingrese un número entero.\n");
        return 1;  // Salida temprana si la entrada no es válida
    }

    if (numero < 0) {
        printf("Error: El factorial no está definido para números negativos.\n");
    } else {
        unsigned long long resultado = factorial(numero);
        printf("El factorial de %d es: %llu\n", numero, resultado);
    }

    return 0;
}