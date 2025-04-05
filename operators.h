#ifndef operators_h
#define operators_h

void nextBit(int *actualPosition);
void previousBit(int *actualPosition);
void plusOperator(int *bits, int *actualPosition);
void minusOperator(int *bits, int *actualPosition);
void doOperation(char operator,int *bits, int *actualPosition);

#endif