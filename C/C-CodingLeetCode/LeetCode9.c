// leetcode
// by [alex]
// nivel: Facil


/*

Encontrar el indice de la primera aparicion en una cadena

Problema: Dadas dos cadenas needle y haystack, debes encontrar la primera aparición de needle dentro de haystack y
devolver su índice inicial. Si needle no está en haystack, devuelves -1.


*/


#include <stdio.h>


int strStr(char* haystack, char* needle) {
    if (*needle == '\0') { // *needle es el primer caracter de needle
        return 0;
    }
    
    int h_len = 0;
    int n_len = 0;
    
    // Calcular longitudes primero
    while (haystack[h_len] != '\0') h_len++;
    while (needle[n_len] != '\0') n_len++;
    
    // Si needle es más largo, no puede estar contenido
    if (n_len > h_len) {
        return -1;
    }
    
    // Solo buscar hasta donde needle puede caber
    for (int i = 0; i <= h_len - n_len; i++) {
        int j = 0;
        while (j < n_len && haystack[i + j] == needle[j]) {
            j++;
        }
        if (j == n_len) {
            return i;
        }
    }
    
    return -1;
}

int main() {
    char haystack[] = "hello";
    char needle[] = "ll";
    
    int index = strStr(haystack, needle);
    
    if (index != -1) {
        printf("La primera aparición de '%s' en '%s' está en el índice: %d\n", needle, haystack, index);
    } else {
        printf("'%s' no se encuentra en '%s'\n", needle, haystack);
    }
    
    return 0;
}