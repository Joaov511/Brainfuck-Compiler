#include "operators.h"

void nextBit(int *actualPosition) {
    (*actualPosition)++;
}

void previousBit(int *actualPosition) {
    (*actualPosition)--;
}

void plusOperator(int *bits, int *actualPosition) {
    bits[*actualPosition]++;
}

void minusOperator(int *bits, int *actualPosition) {
    bits[*actualPosition]--;
}

void doOperation(char operator,int *bits, int *actualPosition) {
    switch (operator)
    {
    case '+':
        plusOperator(bits, actualPosition);
        break;
    case '-':
        minusOperator(bits, actualPosition);
        break;
    case '>':
        nextBit(actualPosition);
        break;
    case '<':
        previousBit(actualPosition);
        break;
    default:
        break;
    }
}