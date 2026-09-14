#include <stdlib.h>
#include <string.h>

int calPoints(char** operations, int operationsSize) {
    // A stack to store scores; its size will never exceed operationsSize
    int* stack = (int*)malloc(sizeof(int) * operationsSize);
    int top = 0;

    for (int i = 0; i < operationsSize; i++) {
        if (strcmp(operations[i], "+") == 0) {
            stack[top] = stack[top - 1] + stack[top - 2];
            top++;
        } else if (strcmp(operations[i], "D") == 0) {
            stack[top] = 2 * stack[top - 1];
            top++;
        } else if (strcmp(operations[i], "C") == 0) {
            top--;
        } else {
            // Integer value
            stack[top] = atoi(operations[i]);
            top++;
        }
    }

    // Sum all valid scores remaining in the stack
    int totalSum = 0;
    for (int i = 0; i < top; i++) {
        totalSum += stack[i];
    }

    free(stack);
    return totalSum;
}