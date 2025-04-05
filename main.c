#include<stdio.h>
#include<stdbool.h>
#include "operators.h"

int main() {
    char text[100];
    int bits[100];
    int actualPosition = 0;
    char operators[] = {'>','<','+','-','[',']',',','.'};

    void printIntArray(int *array) {
        for(int i = 0; i < 10; i++) {  
            printf("%i", array[i]);
        }
    }

    bool checkOperators(char character, char *operators) {
        bool isOperator = true;
        for(int i = 0; i < sizeof operators; i++) {           
            if(character == operators[i]) {
                return true;
            }
            else {
                isOperator = false;
            }
        }
        return isOperator;
    }

    void checkTheArray(char *array) {
        for(int i = 0; i < sizeof array + 1; i++) {
            if(checkOperators(array[i], operators)){
                doOperation(array[i], bits, &actualPosition);
            }
        }
        printf("%i", bits[0]);
        printf("%i", bits[1]);
        printf("%i", bits[2]);
        printf("%i", actualPosition);
    }

    FILE *filePtr;
    filePtr = fopen("text.bfk", "r");
    
    fgets(text, 100, filePtr);
    checkTheArray(text);
    fclose(filePtr);

    return 0;
}