#ifndef operators_h
#define operators_h

struct BrainfuckOperator {
    int *bits;
    int *actualPosition;
    char operator;
    char *text;
};

/* void nextMemoryPtr(int *actualPosition);
void previousMemoryPtr(int *actualPosition);
void plusOperator(int *bits, int *actualPosition);
void minusOperator(int *bits, int *actualPosition);
void doOperation(char operator,int *bits, int *actualPosition);
int printOperator(int *bits, int *actualPosition); */

void nextMemoryPtr(struct BrainfuckOperator *operator);
void previousMemoryPtr(struct BrainfuckOperator *operator);
void plusOperator(struct BrainfuckOperator *operator);
void minusOperator(struct BrainfuckOperator *operator);
void doOperation(struct BrainfuckOperator *operator);
int printOperator(struct BrainfuckOperator *operator);

#endif