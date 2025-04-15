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

    const int fileContentSize = 1000;
    char *fileContent = malloc(fileContentSize);
    if (fileContent == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    memset(fileContent, 0, fileContentSize);
    
    const int memoryTapeSize = 3000;
    int *memoryTape = malloc(memoryTapeSize * sizeof(*memoryTape));
    if (memoryTape == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    memset(memoryTape, 0, memoryTapeSize * sizeof(*memoryTape));

    int currentPosition = 0;
    char operators[] = {'>','<','+','-','[',']',',','.'};
    struct BrainfuckOperator operator;

    operator.memoryTape = memoryTape;
    operator.currentPosition = &currentPosition;

    FILE *filePtr;
    filePtr = fopen(argv[1], "r");
    fread(fileContent, 1, fileContentSize, filePtr);
    readBrainfuckFile(fileContent,operators, &operator);

    clock_t stop = clock();
    double elapsed = (double)(stop - start) * 1000.0 / CLOCKS_PER_SEC;
/*     printf("Time elapsed in ms: %f", elapsed);
    printf("%i\n", memoryTape[0]);
    printf("%i\n", memoryTape[1]);
    printf("%i\n", memoryTape[2]);
    printf("%i\n", memoryTape[3]);
    printf("%i\n", memoryTape[4]);
    printf("%i\n", memoryTape[5]); */
    

    free(fileContent);
    free(memoryTape);
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