#include "operators.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void nextMemoryPtr(int *actualPosition) {
    (*actualPosition)++;
}

void previousMemoryPtr(int *actualPosition) {
    (*actualPosition)--;
}

void plusOperator(int *bits, int *actualPosition) {
    bits[*actualPosition]++;
}

void minusOperator(int *bits, int *actualPosition) {
    bits[*actualPosition]--;
}

int printOperator(int *bits, int *actualPosition) {
    for(int i = 0; i < 1000; i++) {
        if(bits[i] == 0) {
            return 0;
        }
        printf("%c", (char)bits[i]);
        fflush(stdout);
        return 0;
    }
}

void doOperation(char operator,int *bits, int *actualPosition) {
    //printf("%c", operator);
    switch (operator)
    {
    case '+':
        plusOperator(bits, actualPosition);
        break;
    case '-':
        minusOperator(bits, actualPosition);
        break;
    case '>':
        nextMemoryPtr(actualPosition);
        break;
    case '<':
        previousMemoryPtr(actualPosition);
        break;
    case '.':
        printOperator(bits, actualPosition);
        break;
    default:
        break;
    }
}