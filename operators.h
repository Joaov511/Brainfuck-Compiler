#ifndef operators_h
#define operators_h

/* struct Operator {
    int *bits;
    int *actualPosition;
    char operator;
    char *text;
} */

void nextMemoryPtr(int *actualPosition);
void previousMemoryPtr(int *actualPosition);
void plusOperator(int *bits, int *actualPosition);
void minusOperator(int *bits, int *actualPosition);
void doOperation(char operator,int *bits, int *actualPosition);
int printOperator(int *bits, int *actualPosition);

#endif