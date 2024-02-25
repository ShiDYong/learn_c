/********************************************************************************
* @author: mason shi
* @date: 2023/7/12 21:33
* @version: 1.0
* @description: 第十章课后编程题01
 * 修改10.2节的栈示例使它们存储的是字符而不是整数。接下来，增加main函数，用来要求用户输入一串圆括号或
 * 花括号，然后指出它们之间的嵌套是否正确：
 * Enter parenteses and/or braces: ({}{}{})
 * Parenteses/braces are nested properly.
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

int checkNestedParenthesesBraces(char input[]);


int main(void) {
    /*提示：读入左圆括号或花括号时，把它们像字符串一样压入栈中。当读入右圆括号或右花括号时，把栈顶的项弹出，并且检查弹出项
     * 是否是匹配的花括号或圆括号。(如果不是，那么圆括号或花括号嵌套不正确)当程序读入换行符时，检查栈是否为空。如果为空，那么圆括号
     * 或花括号不匹配。如果调用stack_overflow函数，程序显示信息Stack Overflow,并且立刻终止.*/
    char input[STACK_SIZE];
    printf("Enter parentheses and/or braces: ");
    scanf("%s", input);
    if (checkNestedParenthesesBraces(input))
        printf("Parentheses/braces are nested properly\n");
    else
        printf("Parentheses/braces are not nested properly\n");
    return 0;

}

/**
 * 判断是否花括号或者括号是否嵌套的方法
 * @param input
 * @return
 */
int checkNestedParenthesesBraces(char input[]) {
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '(' || input[i] == '{')
            push(input[i]);
        else if (input[i] == ')' || input == '}') {
            if (top == 0)
                return 0; //没有匹配匹配到的数据
            if ((input[i] == ')' && contents[--top] == '(') || (input[i] == '}' && contents[--top] == '{')) {
                top--;
            } else
                return 0;//没有匹配到数据
        }

    }
    return top == 0;  // True if all opening braces are matched and closed


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
        return contents[--top]; //这里不能是top--,因为push的时候top++了，此时的top的值为0,所以pop时要先--p才能拿到值
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