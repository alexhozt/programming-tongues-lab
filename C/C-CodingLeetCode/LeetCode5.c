// leetcode
// by [alex]
// nivel: Facil

/*

problem: parentesis validos 

Dada una cadena de caracteres que contiene solo caracteres '(', ')', '{', '}', '['  ']'.

una cadena es valida si:
1. los corchetes abiertos deben estar cerrados por el mismo tipo de corchete.
2. los corchetes abiertos deben cerrarse en el orden correcto.
3. Cada corchete de cierre tiene un corchete de apertura correspondiente al mismmo tipo.

Para resolver el problema podemos utilizar una pila, esto me permitira llevar seguimiento 
de los parentesis abiertos y asegurarme de que se cierren en orden correcto.


*/

#include <stdio.h>

int isValid(char * s) {
    char stack[100]; // pila para almacenar los caracteres
    int top = -1; // indice del tope de la pila

    for(int i = 0; s[i] != '\0' ; i++) { // recorrer la cadena. s[i] != '\0' significa hasta el final de la cadena, s[i] es el caracter en la posicion i
        char c = s[i];

        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c; // push a la pila
        } else {
            if (top == -1) return 0; // pila vacia, no hay corchete de apertura

            char topChar = stack[top--]; // pop de la pila

            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                return 0; // corchetes no coinciden
            }
        }

    }
}

int main() {
    char *s = "{[()]}"; // cadena de prueba
    if (isValid(s)) {
        printf("La cadena es valida.\n");
    } else {
        printf("La cadena no es valida.\n");
    }
    return 0;
}