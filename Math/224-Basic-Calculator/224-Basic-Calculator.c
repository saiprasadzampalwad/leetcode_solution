#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

struct Stack {
    int* data;
    int top;
    int capacity;
};

// Function to create a stack
struct Stack* createStack(int capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->data = (int*)malloc(capacity * sizeof(int));
    return stack;
}

// Function to resize the stack if needed
void resizeStack(struct Stack* stack) {
    if (stack->top >= stack->capacity - 1) {
        stack->capacity *= 2;
        stack->data = (int*)realloc(stack->data, stack->capacity * sizeof(int));
    }
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value) {
    // Check if the stack needs resizing
    resizeStack(stack);
    stack->data[++stack->top] = value;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (stack->top == -1) {
        fprintf(stderr, "Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->data[stack->top--];
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to evaluate the string expression
int calculate(char* s) {
    struct Stack* stack = createStack(100);
    int current_number = 0;
    int result = 0;
    int sign = 1;
    int len = strlen(s);

    for (int i = 0; i < len; i++) {
        char ch = s[i];

        if (isdigit(ch)) {
            current_number = current_number * 10 + (ch - '0');
        } else if (ch == '+') {
            result += sign * current_number;
            current_number = 0;
            sign = 1;
        } else if (ch == '-') {
            result += sign * current_number;
            current_number = 0;
            sign = -1;
        } else if (ch == '(') {
            push(stack, result);
            push(stack, sign);
            result = 0;
            sign = 1;
        } else if (ch == ')') {
            result += sign * current_number;
            current_number = 0;
            result *= pop(stack);  // pop sign
            result += pop(stack);  // pop result
        }
    }

    result += sign * current_number;

    // Free the allocated memory for the stack
    free(stack->data);
    free(stack);

    return result;
}

