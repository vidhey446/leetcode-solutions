#pragma GCC optimize("O3")
#include <stdlib.h>
#include <limits.h>

#define INITIAL_CAPACITY 1024

// Structure definition for MinStack
typedef struct {
    int* val_stack; // Holds the actual values
    int* min_stack; // Holds the minimum value at each state
    int top_idx;    // Tracks the top element index
    int capacity;   // Current maximum capacity of the stacks
} MinStack;

// Initializes the stack object
MinStack* minStackCreate() {
    MinStack* obj = (MinStack*)malloc(sizeof(MinStack));
    obj->capacity = INITIAL_CAPACITY;
    obj->val_stack = (int*)malloc(obj->capacity * sizeof(int));
    obj->min_stack = (int*)malloc(obj->capacity * sizeof(int));
    obj->top_idx = -1;
    return obj;
}

// Pushes element val onto the stack
void minStackPush(MinStack* obj, int val) {
    // Dynamically resize arrays if they run out of capacity
    if (obj->top_idx >= obj->capacity - 1) {
        obj->capacity *= 2;
        obj->val_stack = (int*)realloc(obj->val_stack, obj->capacity * sizeof(int));
        obj->min_stack = (int*)realloc(obj->min_stack, obj->capacity * sizeof(int));
    }
    
    obj->top_idx++;
    obj->val_stack[obj->top_idx] = val;
    
    // If it's the first element, it is the minimum.
    // Otherwise, compare val with the current minimum on top of min_stack.
    if (obj->top_idx == 0) {
        obj->min_stack[obj->top_idx] = val;
    } else {
        int current_min = obj->min_stack[obj->top_idx - 1];
        obj->min_stack[obj->top_idx] = (val < current_min) ? val : current_min;
    }
}

// Removes the element on top of the stack
void minStackPop(MinStack* obj) {
    if (obj->top_idx >= 0) {
        obj->top_idx--;
    }
}

// Gets the top element of the stack
int minStackTop(MinStack* obj) {
    return obj->val_stack[obj->top_idx];
}

// Retrieves the minimum element in the stack
int minStackGetMin(MinStack* obj) {
    return obj->min_stack[obj->top_idx];
}

// Frees the memory allocated for the stack
void minStackFree(MinStack* obj) {
    free(obj->val_stack);
    free(obj->min_stack);
    free(obj);
}