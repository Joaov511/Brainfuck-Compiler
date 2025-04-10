#include "operators.h"
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

int getEndOfLoopPosition(struct BrainfuckOperator *operator) {
    for(int i = *operator->filePosition; i < 1000; i++) {
        if(operator->brainfuckCode[i] == ']') {
            return i;
        }
    }
    return -1;
}

void loopOperator(struct BrainfuckOperator *operator) {

    int initialLoopPosition = (*operator->filePosition);
    int loopEndPosition = getEndOfLoopPosition(operator);

    if(loopEndPosition == -1) {
        fprintf(stderr, "Error: No matching closing bracket\n");
        return;
    }

    if(operator->bits[*operator->currentPosition] == 0) {
        *operator->filePosition = loopEndPosition;
    }
    else {
        while(operator->bits[*operator->currentPosition] != 0) {
            int tempFilePosition = *operator->filePosition;
            *operator->filePosition = initialLoopPosition + 1; 
            
            while (*operator->filePosition != loopEndPosition) {
                operator->operator = operator->brainfuckCode[*operator->filePosition];
                doOperation(operator);
                (*operator->filePosition)++; 
            }
            *operator->filePosition = tempFilePosition;
        }
        
        *operator->filePosition = loopEndPosition;
    }
    (*operator->filePosition)++;
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
    case '[':
        loopOperator(operator);
        break;
    default:
        break;
    }
}