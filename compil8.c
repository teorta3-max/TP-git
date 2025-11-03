#include <stdio.h>

int main() {
    int x = 10;
    int y = 10;
    printf("x = %d\n", y);
    return 0;
}

//compil8.c: In function 'main':
//compil8.c:5:24: error: 'y' undeclared (first use in this function)
//     printf("x = %d\n", y);
//                        ^
//La variable 'y' n'a pas été déclarée avant son utilisation dans la fonction printf.