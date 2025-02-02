#include <stdio.h>
#include <stdlib.h> // For atoi

int main() {
    char numStr[] = {'1','2','3','4'};
    int num = atoi(numStr);
    printf("The integer is %d\n", num);
    return 0;
}
