#include <stdio.h>  // Incluye la biblioteca estándar de entrada/salida para usar las funciones printf y scanf.
#include <stdlib.h>  // Incluye la biblioteca estándar para funciones de asignación dinámica de memoria como malloc y free.

long factorial(int n) {  // Define una función que calcula el factorial de un número utilizando programación dinámica.
    long* factoriales = (long*) malloc((n + 1) * sizeof(long));  // Asigna memoria dinámica para un arreglo de 'long' que almacenará los factoriales de 0 a 'n'.
    if (factoriales == NULL) {  // Verifica si la asignación de memoria fue exitosa.
        printf("Error al asignar memoria.\n");  // Si no se pudo asignar memoria, imprime un mensaje de error.
        return -1;  // Retorna -1 para indicar un error.
    }
    
    factoriales[0] = 1;  // Inicializa el factorial de 0 en 1, ya que 0! es 1.
    
    for (int i = 1; i <= n; i++) {  // Bucle 'for' que recorre desde 1 hasta 'n'.
        factoriales[i] = i * factoriales[i - 1];  // Calcula el factorial de 'i' multiplicando 'i' por el factorial de 'i-1' y lo guarda en el arreglo.
    }
    
    long resultado = factoriales[n];  // Guarda el resultado del factorial de 'n' que se encuentra en 'factoriales[n]'.
    free(factoriales);  // Libera la memoria asignada dinámicamente para evitar fugas de memoria.
    return resultado;  // Devuelve el resultado del factorial calculado.
}

int main() {  // Función principal del programa.
    int numero;  // Declara una variable 'numero' de tipo entero para almacenar la entrada del usuario.
    
    printf("Ingrese un número entero: ");  // Imprime un mensaje pidiendo al usuario que ingrese un número.
    scanf("%d", &numero);  // Lee un número entero desde la entrada estándar (teclado) y lo almacena en 'numero'.

    if (numero < 0) {  // Verifica si el número ingresado es negativo.
        printf("Error: El factorial no está definido para números negativos.\n");  // Si es negativo, imprime un mensaje de error.
    } else {  // Si el número es no negativo...
        long factorial = factorial(numero);  // Llama a la función 'factorialDinamico' con el número ingresado y guarda el resultado en 'factorial'.
        if (factorial != -1) {  // Verifica que el resultado sea válido (es decir, que no hubo un error de memoria).
            printf("El factorial de %d es: %ld\n", numero, factorial);  // Imprime el resultado del factorial.
        }
    }

    return 0;  // Indica que el programa terminó con éxito.
}