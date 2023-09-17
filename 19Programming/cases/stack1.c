/********************************************************************************
* @author: mason shi
* @date: 2023/9/16 10:34
* @version: 1.0
* @description: 简单的栈通过数组实现
********************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include "stack.h"

#define STACK_SIZE 100
/*处于风格的考虑，一些程序员使用宏来指明哪些函数和变量是共有的(在程序的任何地方访问)，哪些程序是私有的(只能在一个文件内访问)*/
#define PUBLIC
#define PRIVATE  static
/*组成栈的变量contents和top都被声明为static了，因为没有理由让程序的其他部分直接访问它们。terminate函数也声明为static。这个
 * 函数不属于模块的接口；相反，它只能在模块的实现内使用*/
//static int contents[STACK_SIZE];
//static int top = 0;

//上面两种声明替换为以下
PRIVATE int contents[STACK_SIZE];
PRIVATE int top = 0;


static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void) {
    top = 0;
}

bool is_empty(void) {
    return top == 0;
}

bool is_full(void) {
    return top == STACK_SIZE;
}

void push(int i) {
    if (is_full())
        terminate("Enter in push: stack is full.");
    contents[top++] = i;
}

int pop(void) {
    if (is_empty())
        terminate("Error in pop: stack if empty.");
    contents[--top];
}

int peek(void) {
    return contents[top];
}