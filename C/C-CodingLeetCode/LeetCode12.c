// leetcode
// by [alex]
// nivel: Facil

/*

Mas Uno

Se te da un entero grande representado como un array de enteros, donde cada uno es el digito del entero. Los 
digitos estan ordenados de mas significativo a menos significativo de izquierda a derecha. El entero grande no contiene
ningun 's al principio.

incrementa el entero grande en uno y devuelve el array resultante de digitos


*/

#include <stdio.h>
#include <stdlib.h> // esta libreria sirve para: 


int* plusOne(int* digits, int digitsSize, int* returnSize) {
    // paso 1: comenzar desde el final
    for(int i = digitsSize - 1; i >= 0; i --) {
        // paso 2: sumar 1 al digito actual
        if(digits[i] < 9) {
            digits[i]++;
            *returnSize = digitsSize;
            return digits;
        }
        // paso 3: si el digito es 9, se convierte en 0
        digits[i] = 0;

    }

    // paso 4: si llegamos aqui, todos los digitos eran 9
    // ejemplo: [9,9,9] --> [1,0,0,0]
    int* result = (int*)malloc((digitsSize + 1) * sizeof(int));
    result[0] = 1;  // Primer dígito es 1
    for (int i = 1; i <= digitsSize; i++) {
        result[i] = 0;  // Todos los demás son 0
    }
    
    *returnSize = digitsSize + 1;
    return result;
}

