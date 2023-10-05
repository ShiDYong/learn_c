/********************************************************************************
* @author: mason shi
* @date: 2023/9/16 17:01
* @version: 1.0
* @description: 使用动态数组实现栈抽象数据类型
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include "stackADT2.h"

/*使用动态数组实现的关键是修改stack_type结构，使contents成员为指向数据项所在的数组的指针，而不是数组本身*/
struct stack_type {
    Item *contents;
    int top;
    int size;//来存储栈的最大容量(contents直线的数组长度)
};

static void terminate(const char *message) {
    printf("%s\n", message);
    exit(EXIT_FAILURE);
}

Stack create(int size) {
    //1.为struct stack_type分配内空间
    Stack s = malloc(sizeof(struct stack_type));
    if (s == NULL)
        terminate("Error in create: Memory allocation failed");
    //2.为包含栈的数据项的数组分配内存空间
    s->contents = malloc(size * sizeof(Item));
    if (s->contents == NULL) {
        free(s);
        terminate("Error in create: stack could not to be created.");
    }
    s->top = 0;
    s->size = size;
    return s;

}

/**
 * 实现数组的动态扩容
 * @return
 */
void resize_array(Stack s) {
    s->size *= 2;
    s->contents = realloc(s->contents, s->size * sizeof(Item));
    if (s->contents == NULL) {
        free(s);
        terminate("Error in create: stack could not to be created.");
    }


}

void make_empty(Stack s) {
    s->top = 0;
}

bool is_emtpy(Stack s) {
    return s->top == 0;
}

bool is_full(Stack s) {
    return s->top == s->size;
}

void destroy(Stack s) {
    s->top = 0;
}

void push(Stack s, Item i) {
    if (is_full(s))
        resize_array(s);
    s->contents[s->top++] = i;
}

Item pop(Stack s) {
    if (is_emtpy(s))
        terminate("Error in pop: stack is empty.");
    return s->contents[--s->top];
}

Item peek(Stack s) {
    return s->contents[s->top];
}
