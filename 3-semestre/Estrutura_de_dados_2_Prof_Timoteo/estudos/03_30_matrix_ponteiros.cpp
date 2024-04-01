#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

int main(){
	int matrix[ROWS][COLS];
	int *ptr = &matrix[0][0];
	for (int i = 0; i < ROWS * COLS; i++) {
        *(ptr + i) = 0;
    }   
    
    int num = 1;
    for (int i = 0; i < ROWS * COLS; i++) {
        *(ptr + i) = num;
        num++;
    }
    
    printf("Alguns elementos da matriz:\n");
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d\t", matrix[i][j]);
        }
        printf("\n");
    }
    
    printf("Alguns elementos da matriz:\n");
    int *newPtr = &matrix[0][0];
    for (int i = 0; i < ROWS * COLS; i++) {
        printf("%d\t", *newPtr);
        if ((i + 1) % COLS == 0) {
            printf("\n");
        }
        newPtr++;
    }
    
    printf("\n%d", matrix[4][0]);
    printf("\n%d", *(matrix + 4));

    return 0;
}
