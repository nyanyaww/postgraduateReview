#include <stdio.h>

#define LEN 3
#define STACK_NULL -65532
typedef int DataType;

#define PRINT_TOP_ELEMENT(top_element)                     \
    {                                                      \
        if (top_element != STACK_NULL)                     \
            printf("Top element is %d\n", top_element);    \
        else                                               \
            printf("The stack is empty, we can\'t get\n"); \
    }

typedef struct Stack
{
    DataType data[LEN];
    int top;
} Stack;

typedef enum Boolen
{
    False = 0,
    True = 1,
} Boolen;

Stack init()
{
    Stack stack;
    stack.top = -1;
    return stack;
}

Boolen isFull(Stack stack)
{
    return stack.top == LEN - 1 ? True : False;
}

Boolen isEmpty(Stack stack)
{
    return stack.top == -1 ? True : False;
}

Stack push(Stack stack, DataType data)
{
    if (isFull(stack) == False)
    {
        stack.top++;
        stack.data[stack.top] = data;
        printf("push data = %d\n", data);
    }
    else
    {
        printf("The stack is full, we can\'t push\n");
    }
    return stack;
}

Stack pop(Stack stack)
{
    if (isEmpty(stack) == False)
    {
        printf("pop data\n");
        stack.top--;
    }
    else
    {
        printf("The stack is empty, we can\'t pop\n");
    }
    return stack;
}

DataType getTop(Stack stack)
{
    if (stack.top != -1)
        return stack.data[stack.top];
    return STACK_NULL;
}

int main()
{
    Stack stack_test = init();
    stack_test = push(stack_test, 1);
    PRINT_TOP_ELEMENT(getTop(stack_test));
    stack_test = push(stack_test, 2);
    stack_test = push(stack_test, 3);
    stack_test = push(stack_test, 4);
    stack_test = push(stack_test, 5);
    PRINT_TOP_ELEMENT(getTop(stack_test));

    stack_test = pop(stack_test);
    PRINT_TOP_ELEMENT(getTop(stack_test));
    stack_test = pop(stack_test);
    PRINT_TOP_ELEMENT(getTop(stack_test));
    stack_test = pop(stack_test);
    PRINT_TOP_ELEMENT(getTop(stack_test));
    stack_test = pop(stack_test);
    PRINT_TOP_ELEMENT(getTop(stack_test));
    return 0;
}