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


    bool checkOperators(char character, char *operators) {
        int len = strlen(operators);
        for(int i = 0; i < len; i++) {           
            if(character == operators[i]) {
                return true;
            }
        }
        return false;
    }

    void loopOperator(char *array,int *bits, int *actualPosition) {
        int positionLoopCloser = 0;
        for(int i = *actualPosition; i < 1000; i++) {
            if(text[i] == ']') {
                positionLoopCloser = i;
            }
        }
        (*actualPosition)++;
        while(bits[*actualPosition] > 0) {
            int currPosition = *actualPosition;
            for(int i=currPosition; i < positionLoopCloser + 1; i++) {
                if(checkOperators(array[i], operators)){
                    doOperation(array[i], bits, actualPosition);
                }
            }
            *actualPosition = currPosition;
        }
    }
    

    void checkTheArray(char *array) {
        int arrayLength = strlen(array);
        for(int i = 0; i < arrayLength; i++) {
            if(array[i] == '[') {
                actualPosition = i;
                loopOperator(array,bits, &actualPosition);
                i = actualPosition;
            }
            else if(checkOperators(array[i], operators)){
                doOperation(array[i], bits, &actualPosition);
            }
        }
/*         printf("%i\n", bits[0]);
        printf("%i\n", bits[1]);
        printf("%i\n", bits[2]); */
    }

    FILE *filePtr;
    filePtr = fopen("text.bfk", "r");
    
    fgets(text, 1000, filePtr);
    checkTheArray(text);
    fclose(filePtr);

    return 0;
}