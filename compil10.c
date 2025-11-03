#include <stdio.h>

int main() {
    int _1abc = 5;
    printf("%d\n", _1abc);
    return 0;
}

//compil10.c: In function 'main':
//compil10.c:4:9: error: invalid suffix "abc" on integer constant
//     int 1abc = 5;
//         ^~~~
//compil10.c:4:9: error: expected identifier or '(' before numeric constant
//compil10.c:5:20: error: invalid suffix "abc" on integer constant
//     printf("%d\n", 1abc);
//                    ^~~~
//La variable '1abc' commence par un chiffre, ce qui n'est pas autorisé en C. Les noms de variables doivent commencer par une lettre ou un underscore (_).