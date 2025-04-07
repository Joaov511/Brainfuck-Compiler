#include "operators.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void nextMemoryPtr(struct BrainfuckOperator *operator) {
    (*operator->currentPosition)++;
}

void previousMemoryPtr(struct BrainfuckOperator *operator) {
    (*operator->currentPosition)--;
}

void plusOperator(struct BrainfuckOperator *operator) {
    operator->bits[*operator->currentPosition]++;
}

void minusOperator(struct BrainfuckOperator *operator) {
   operator->bits[*operator->currentPosition]--;
}

void printOperator(struct BrainfuckOperator *operator) {
    printf("%c", (char)operator->bits[*operator->currentPosition]);
}

void doOperation(struct BrainfuckOperator *operator) {
    switch (operator->operator)
    {
    case '+':
        plusOperator(operator);
        break;
    case '-':
        minusOperator(operator);
        break;
    case '>':
        nextMemoryPtr(operator);
        break;
    case '<':
        previousMemoryPtr(operator);
        break;
    case '.':
        printOperator(operator);
        break;
    default:
        break;
    }
}