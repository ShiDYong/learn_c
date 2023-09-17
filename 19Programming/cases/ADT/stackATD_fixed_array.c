/********************************************************************************
* @author: mason shi
* @date: 2023/9/16 12:18
* @version: 1.0
* @description: 用定长数组实现栈抽象数据类型
********************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include "stackADT.h"

#define STACK_SIZE 100
struct stack_type {
    int contents[STACK_SIZE];
    int top;
};

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

/**
 * 构造器
 * @return
 */
Stack create(void) {
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: stack could not to be created.");
    s->top = 0;
    return s;
}

/**
 * 释放内存
 * @param s
 */
void destroy(Stack s) {
    free(s);
}

/*这里函数使用的是->运算符而不是.运算符来访问stack_type结构的contents和top成员。参数s是指向stack_type结构的指针，而不是结构本身
 * 所以使用.运算符是非法的。
 * */
void make_empty(Stack s) {
    s->top = 0;
}

bool is_empty(Stack s) {
    return s->top == 0;
}

bool is_full(Stack s) {
    return s->top == STACK_SIZE;
}

void push(Stack s, int i) {
    if (is_full(s))
        terminate("Error in push: stack is full.");
    s->contents[s->top++] = i;
}

int pop(Stack s) {
    if (is_empty(s))
        terminate("Error in pop: stack is empty");
    return s->contents[--s->top];
}

int peek(Stack s) {
    return s->contents[s->top];
}
