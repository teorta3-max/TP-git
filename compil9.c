#include <stdio.h>

int main() {
    char s[5] = "Hello";
    printf("%s\n", s);
    return 0;
}

//compil9.c: In function 'main':
//compil9.c:4:17: warning: initializer-string for array of chars is too long
//     char s[3] = "Hello";
//                 ^~~~~~~
//La chaîne de caractères "Hello" est trop longue pour le tableau 's' qui ne peut contenir que 3 caractères (y compris le caractère nul de fin de chaîne).