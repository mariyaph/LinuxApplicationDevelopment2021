#include <stdio.h>
#include<stdlib.h>
int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf ("No arguments");
        return 0;
    }
    int N = 0;
    int M = 0;
    int S = 1;
    if (argc == 2) {
        N = atoi(argv[1]);
    }
    else if (argc == 3) {
        M = atoi(argv[1]);
        N = atoi(argv[2]);
    }
    else if (argc == 4) {
        M = atoi(argv[1]);
        N = atoi(argv[2]);
        S = atoi(argv[3]);
    }
    for (int i = M; i < N-1; i+=S)
        printf ("%d\n", i);
    printf("%d\n", N-1);
return 0;
}