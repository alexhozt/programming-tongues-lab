// leetcode
// by [alex]
// nivel: Facil


/*
problem: Eliminar duplicados de la matriz ordenada

Dada una matriz de enteros ordenada en orden no decreciente, elimine los duplicados
de modo que cada elemento aparezca solo una vez. El orden relativo de los elementos
debe mantenerse igual. Luego devuelve el número de elementos unicos.

Considere la cantidad de elementos unicos de ser, para ser aceptado, debe hacer las siguientes cosas:

1. Cambie la matriz de modo que los primeros elementos contengan los elementos unicos 
en el orden en que estaban presentes inicialmente. Los elementos restantes no son importantes.

2. Devuelva el número de elementos unicos.

*/


#include <stdio.h>


int RemoveDuplicates(int* array, int size) {
    if (size == 0) {
        return 0;
    }

    int i, j = 0; 

    for (i = 1; i < size; i++) {
        if (array[i] != array[j]) {
            j++; // incrementar el indice de los elementos unicos
            array[j] = array[i]; // actualizar el elemento unico
        }
    }

    return j + 1; // actualizar el tamaño de la matriz


}

int main() {
    int array[] = {0,0,1,1,1,2,2,3,3,4};
    int size = sizeof(array) / sizeof(array[0]);

    int newSize = RemoveDuplicates(array, size);

    printf("matriz sin elementos duplicados: ");
    for (int i = 0; i < newSize; i++) {
        printf("%d ", array[i]);
    }
    printf("\nNumero de elementos unicos: %d\n", newSize);

    return 0;
}