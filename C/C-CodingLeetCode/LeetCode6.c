// leetcode
// by [alex]
// nivel: Facil

/*

Se el dan los encabezados de dos listas enlazadas ordenadas, combine las dos listas
ordenadas en una lista ordenada. La lista debe hacerse empalmando los nodos de las dos primeras listas.

empalmar: significa que el nodo de la primera lista se coloca antes del nodo de la segunda lista.

ejemplo: 

1 2 4
1 3 4
--------
1 1 2 3 4 4

*/

#include <stdio.h>

int UnionSortedArrays(int* arr1, int size1, int* arr2, int size2, int* result) {
    int i = 0, j = 0, k = 0;

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            result[k++] = arr1[i++];
        } else {
            result[k++] = arr2[j++];
        }
    }

    while (i < size1) {
        result[k++] = arr1[i++];
    }

    while (j < size2) {
        result[k++] = arr2[j++];
    }

    return k; // return the size of the merged array
}

int main() {
    int arr1[] = {1, 2, 4};
    int arr2[] = {1, 3, 4};
    int size1 = sizeof(arr1) / sizeof(arr1[0]);
    int size2 = sizeof(arr2) / sizeof(arr2[0]);
    int result[size1 + size2];

    int mergedSize = UnionSortedArrays(arr1, size1, arr2, size2, result);

    printf("Merged array: ");
    for (int i = 0; i < mergedSize; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");

    return 0;
}

// sizeof(arr1[0] ) es para obtener el tamaño del tipo de dato del arreglo, en este caso int. --> ejemplo: sizeof(int) = 4 bytes.