/********************************************************************************
* @author: mason shi
* @date: 2023/9/10 16:59
* @version: 1.0
* @description: 通过单链表实现栈的操作
********************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

//使用单链表结构
struct Node {
    int data;
    struct Node *next;
};
//注意和chapter17_stack.c程序的结构的对比
struct Stack {
    struct Node *top;
};

struct Stack *create_stack();

int is_empty(struct Stack *stack);


void push(struct Stack *stack, int item);

int pop(struct Stack *stack);

int peek(struct Stack *stack);

void clear_stack(struct Stack *stack);

void print_stack(struct Stack *stack);


/**
 * 栈的构造器
 * @return
 */
struct Stack *create_stack() {
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    //因为Stack包含了Node，不像动态数组的结构,所以不需要单独分配内存
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->top = NULL;
    return stack;
}

/**
 * 判断栈是否为空
 * @param stack
 * @return
 */
int is_empty(struct Stack *stack) {
    return (stack->top == NULL);
}


/**
 * 入栈操作
 * @param stack
 * @param n
 */
void push(struct Stack *stack, int item) {
    //注意这里的结构是struct Node而不是struct Stack
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = item;
    new_node->next = stack->top; //注意这里操作
    stack->top = new_node;

}

/**
 * 出栈的操作
 * @param stack
 * @return
 */
int pop(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow\n");
        return -1;
    }
    struct Node *temp = stack->top; //这里链表的处理方式已经是很常见了
    int item = temp->data;
    stack->top = stack->top->next;
    free(temp);
    return item;

}

int peek(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->top->data;
}


void clear_stack(struct Stack *stack) {
    if (!is_empty(stack))
        stack->top = NULL;

}

/**
 * 打印栈中的所有的元素
 * @param stack
 */
void print_stack(struct Stack *stack) {
    while (!is_empty(stack)) {
        printf("->%d", stack->top->data);
        stack->top = stack->top->next;
    }

}

int main(void) {
    struct Stack *stack = create_stack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    printf("Top element: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack));
    printf("Top element after pop: %d\n", peek(stack));
    print_stack(stack);
    //clear_stack(stack);
    printf("Top element: %d\n", peek(stack));

    free(stack);
}