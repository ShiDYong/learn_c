/********************************************************************************
* @author: mason shi
* @date: 2023/9/10 15:32
* @version: 1.0
* @description: 通过动态数组实现栈，包含栈容量的动态扩容
********************************************************************************/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

#define INITIAL_CAPACITY 10 // Initial capacity of the dynamic array

struct Stack *create_stack(void);

int is_empty(struct Stack *stack);

int is_full(struct Stack *stack);

void resize_array(struct Stack *stack);

void push(struct Stack *stack, int item);

int pop(struct Stack *stack);

int peek(struct Stack *stack);

void clean_stack(struct Stack *stack);

void print_stack(struct Stack *stack);

//栈的结构类型，注意这里和前面的不一样的地方
struct Stack {
    int *array; //数组
    int top;    //栈顶
    int capacity; //栈的容量
};

/**
 * 栈的创建，或者叫做构造器
 * @return 返回栈的实例
 */
struct Stack *create_stack(void) {
    //动态分配Stack的内存空间
    struct Stack *stack = (struct Stack *) malloc(sizeof(struct Stack));
    if (stack == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    //分配结构元素数组的内存
    stack->capacity = INITIAL_CAPACITY;
    stack->array = (int *) malloc(stack->capacity * sizeof(int));
    if (stack->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    stack->top = -1;
    return stack;

}

/**
 * 判断栈是否为空
 * @param stack
 * @return
 */
int is_empty(struct Stack *stack) {
    return (stack->top == -1);
}

/**
 * 判断栈是否已经满了
 * @param stack
 * @return
 */
int is_full(struct Stack *stack) {
    return (stack->top == stack->capacity - 1);//注意是capacity-1，因为数组下标从0开始
}

/**
 * 实现对数组的容量动态扩容
 * @param stack
 */
void resize_array(struct Stack *stack) {
    stack->capacity *= 2; //扩容2倍
    stack->array = (int *) realloc(stack->array, stack->capacity * sizeof(int));
    if (stack->array == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
}

/**
 * 入栈操作
 * @param stack
 * @param item
 */
void push(struct Stack *stack, int item) {
    if (is_full(stack))
        resize_array(stack);
    stack->array[++stack->top] = item;//注意理解这里的操作

}

/**
 * 出栈的操作
 * @param stack
 * @return
 */
int pop(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack Underflow.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

/**
 * 获取栈顶的元素
 * @param stack
 * @return
 */
int peek(struct Stack *stack) {
    if (is_empty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->array[stack->top];
}

/**
 * 清空栈
 * @param stack
 */
void clean_stack(struct Stack *stack) {
//    stack->array = 0;
//    stack->top = -1;
//    stack->capacity = INITIAL_CAPACITY;
    while (!is_empty(stack))
        pop(stack);
}


/**
 * 打印栈所有元素
 * @param stack
 */
void print_stack(struct Stack *stack) {
    for (int i = 0; i <= stack->top; i++)
        printf("->%d", stack->array[i]);

    printf("\n");

}

/**
 * 测试栈的常见操作
 * @return
 */
int main(void) {
    struct Stack *stack = create_stack();
    struct Stack *stack2 = create_stack();
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    for (int i = 0; i < 8; ++i)
        push(stack2, i);
    printf("Element of stack after pushed.\n");
    print_stack(stack2);
    print_stack(stack);
    printf("Top element: %d\n", peek(stack));
    printf("Popped element: %d\n", pop(stack2));
    printf("Top element after pop: %d\n", peek(stack2));
    clean_stack(stack);
    printf("Top element after clear stack: %d\n", peek(stack));

    //释放内存
    free(stack->array);
    free(stack);

}