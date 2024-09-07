#include <stdio.h>
#include <omp.h>

//Este programa necesita una API para funcionar , se llama open multiprogrsing . Si no se aplica la app no funcionara 
//si no se aplica , entonces marcara ERROR


unsigned long long factorial(int n) {
    unsigned long long resultado = 1;

    #pragma omp parallel for reduction(*:resultado)
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }

    return resultado;
}

int main() {
    int numero;

    printf("Ingrese un número entero: ");
    if (scanf("%d", &numero) != 1) {
        printf("Error: Entrada inválida. Por favor, ingrese un número entero.\n");
        return 1;
    }

    if (numero < 0) {
        printf("Error: El factorial no está definido para números negativos.\n");
    } else {
        unsigned long long factorial = factorial(numero);
        printf("El factorial de %d es: %llu\n", numero, factorial);
    }

    return 0;
}