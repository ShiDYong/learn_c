/********************************************************************************
* @author: mason shi
* @date: 2023/7/15 15:07
* @version: 1.0
* @description: 第二种实现方法
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define STACK_SIZE 100
/*定义全局变量*/
char contents[STACK_SIZE] = {0}; //不要忘记初始化了
int top = 0;
/*声明函数原型*/
bool is_empty();

void make_empty();

bool is_full();

void push(char c);

char pop();

void stack_underflow();

void stack_overflow();


int main(void) {
    char c;

    printf("Enter parentheses and/or braces: ");

    while ((c = getchar()) != '\n') {
        if (c == '(' || c == '{')
            push(c);
        else if (c == ')' && pop() != '(') {
            printf("Parentheses/braces are not nested properly\n");
            return 0;
        } else if (c == '}' && pop() != '{') {
            printf("Parentheses/braces are not nested properly\n");
            return 0;
        }
    }

    if (!is_empty()) {
        printf("Parentheses/braces are not nested properly\n");
        return 0;
    }

    printf("Parentheses/braces are nested properly\n");
    return 0;
}

bool is_empty() {
    return top == 0;
}

bool is_full() {
    return top == STACK_SIZE;
}

void push(char c) {
    if (is_full())
        stack_overflow();
    else
        contents[top++] = c;

}

char pop(void) {
    if (is_empty())
        stack_underflow();
    else
        return contents[--top];
}

void make_empty() {
    top = 0;
}

void stack_underflow() {
    printf("\nStack Underflow\n");
    exit(EXIT_FAILURE);

}

void stack_overflow() {
    printf("\nStack Overflow\n");
    exit(EXIT_FAILURE);
}