#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "operators.h"

bool checkOperators(char character, char *operators);
void readBrainfuckFile(char *array, char *operators, struct BrainfuckOperator *operator);

int main(int argc, char **argv) {
    clock_t start = clock();

    int fileContent = 1000;
    char *fileContentPointer = malloc(fileContent);
    if (fileContentPointer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    memset(fileContentPointer, 0, fileContent);
    
    int bits = 3000;
    int *bitsPointer = malloc(bits * sizeof(*bitsPointer));
    if (bitsPointer == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    memset(bitsPointer, 0, bits * sizeof(*bitsPointer));

    int currentPosition = 0;
    char operators[] = {'>','<','+','-','[',']',',','.'};
    struct BrainfuckOperator operator;

    operator.bits = bitsPointer;
    operator.currentPosition = &currentPosition;

    FILE *filePtr;
    filePtr = fopen(argv[1], "r");
    fread(fileContentPointer, 1, 1000, filePtr);
    readBrainfuckFile(fileContentPointer,operators, &operator);

    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
    printf("Time elapsed in ms: %f", elapsed);
    printf("%i\n", bitsPointer[0]);
    printf("%i\n", bitsPointer[1]);
    printf("%i\n", bitsPointer[2]);
    printf("%i\n", bitsPointer[3]);
    printf("%i\n", bitsPointer[4]);
    printf("%i\n", bitsPointer[5]);
    

    free(fileContentPointer);
    free(bitsPointer);
    fclose(filePtr);
    return 0;
}

bool checkOperators(char character, char *operators) {
    int len = strlen(operators);
    for(int i = 0; i < len; i++) {           
        if(character == operators[i]) {
            return true;
        }
    }
    return false;
}

void readBrainfuckFile(char *array,char *operators, struct BrainfuckOperator *operator) {
    int arrayLength = strlen(array);
    for(int i = 0; i < arrayLength; i++) {
        if(checkOperators(array[i], operators)){
            operator->brainfuckCode = array;
            operator->operator = array[i];
            operator->filePosition = &i;
            doOperation(operator);
        }
    }
}