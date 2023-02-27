#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i;
    // srand(time(NULL)); // seed the random number generator with the current time
    for (i = 0; i < 10; i++) {
        printf("%d\n", rand() % 32); // generate and print a random number
    }
    return 0;
}