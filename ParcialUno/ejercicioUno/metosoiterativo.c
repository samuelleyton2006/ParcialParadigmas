#include <stdio.h>  // Incluye la biblioteca estándar de entrada/salida para usar printf y scanf.

long factorial(int n) {  // Define una función que calcula el factorial de un número de manera iterativa.
    long resultado = 1;  // Declara una variable de tipo 'long' para almacenar el resultado del factorial y la inicializa en 1.
    
    for (int i = 1; i <= n; i++) {  // Bucle 'for' que se ejecuta desde 1 hasta 'n' inclusive.
        resultado *= i;  // Multiplica 'resultado' por 'i' en cada iteración y lo almacena de nuevo en 'resultado'.
    }

    return resultado;  // Devuelve el valor de 'resultado', que contiene el factorial de 'n'.
}

int main() {  // Función principal del programa.
    int numero;  // Declara una variable 'numero' de tipo entero para almacenar la entrada del usuario.
    
    printf("Ingrese un número entero: ");  // Imprime un mensaje pidiendo al usuario que ingrese un número.
    scanf("%d", &numero);  // Lee  un número entero desde la entrada estándar (teclado) y lo almacena en 'numero'.

    if (numero < 0) {  // Verifica si el número ingresado es negativo.
        printf("Error: El factorial no está definido para números negativos.\n");  // Si es negativo, imprime un mensaje de error.
    } else {  // Si el número es no negativo...
        long factorial = factorial(numero);  // Llama a la función 'factorialIterativo' con el número ingresado y guarda el resultado en 'factorial'.
        printf("El factorial de %d es: %ld\n", numero, factorial);  // Imprime el resultado del factorial.
    }

    return 0;  // Indica que el programa terminó con éxito.
}