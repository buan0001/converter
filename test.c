#include <stdio.h>

int main(){
    int myArray[10];
    myArray[0] = 5;
    myArray[3] = 10;
    myArray[9] = 15;

    size_t n = sizeof(myArray) / sizeof(myArray[0]);

    printf("Number of elements in myArray: %zu\n", n);

    for (size_t i = 0; i < n; i++) {
        printf("myArray[%zu] = %d\n", i, myArray[i]);
    }

    return 0;
}