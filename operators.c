#include "operators.h"
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void nextMemoryPtr(struct BrainfuckOperator *operator) {
    (*operator->actualPosition)++;
}

void previousMemoryPtr(struct BrainfuckOperator *operator) {
    (*operator->actualPosition)--;
}

void plusOperator(struct BrainfuckOperator *operator) {
    operator->bits[*operator->actualPosition]++;
}

void minusOperator(struct BrainfuckOperator *operator) {
   operator->bits[*operator->actualPosition]--;
}

void printOperator(struct BrainfuckOperator *operator) {
    printf("%c\n", (char)operator->bits[*operator->actualPosition]);
    fflush(stdout);
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