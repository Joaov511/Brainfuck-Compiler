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

int printOperator(struct BrainfuckOperator *operator) {
    for(int i = 0; i < 1000; i++) {
        if(operator->bits[i] == 0) {
            return 0;
        }
        printf("%c", (char)operator->bits[i]);
        fflush(stdout);
        return 0;
    }
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