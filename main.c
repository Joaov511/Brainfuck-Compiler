#include<stdio.h>
#include<stdbool.h>
#include <string.h>
#include "operators.h"

int main() {
    char text[1000];
    int bits[30000] = {0};
    int bitsLength = 100;
    int actualPosition = 0;
    char operators[] = {'>','<','+','-','[',']',',','.'};
    struct BrainfuckOperator operator;

    bool checkOperators(char character, char *operators) {
        int len = strlen(operators);
        for(int i = 0; i < len; i++) {           
            if(character == operators[i]) {
                return true;
            }
        }
        return false;
    }


    void checkTheArray(char *array, struct BrainfuckOperator *operator) {
        int arrayLength = strlen(array);
        for(int i = 0; i < arrayLength; i++) {
            if(checkOperators(array[i], operators)){
                operator->bits = bits;
                operator->actualPosition = &actualPosition;
                operator->text = array;
                operator->operator = array[i];
                doOperation(operator);
            }
        }
/*      printf("%i\n", bits[0]);
        printf("%i\n", bits[1]);
        printf("%i\n", bits[2]); */
    }

    FILE *filePtr;
    filePtr = fopen("text.bfk", "r");
    
    fgets(text, 1000, filePtr);
    checkTheArray(text, &operator);
    fclose(filePtr);

    return 0;
}