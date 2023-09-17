/********************************************************************************
* @author: mason shi
* @date: 2023/9/16 11:00
* @version: 1.0
* @description: 通过链表实现简单的栈
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "stack.h"

/*作为抽象对象的模块有一个严重的缺点：无法拥有该对象的多个实例(本例中指多个栈)。为了达到这个目的，需要创建一个新的类型。*/
struct node {
    int value;
    struct node *next;
};
static struct node *top = NULL;

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

void make_empty(void) {
    while (!is_empty())
        pop();
}

bool is_empty(void) {
    return top == NULL;
}

bool is_full(void) {
    return false;//链表对大小没有限制，所以栈永远不会满。程序运行时仍然可能出现内存不够的问题，从而导致push函数失败，但实现很难预测这种情况
}

void push(int value) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error in push: stack is full.");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->next = top;
    top = new_node;
}

int pop(void) {
    struct node *old_top;
    int i;
    if (is_empty())
        terminate("Error in pop: stack is empty.");
    old_top = top;
    i = top->value;
    top = top->next;
    free(old_top);
    return i;
}

int peek(void) {
    return top->value;
}
