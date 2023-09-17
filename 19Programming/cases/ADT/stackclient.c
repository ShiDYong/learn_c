/********************************************************************************
* @author: mason shi
* @date: 2023/9/16 15:30
* @version: 1.0
* @description: 模拟客户文件用于测试栈抽象数据了行。这里创建了两个栈，并对它们执行各种操作；
********************************************************************************/
#include<stdio.h>
#include "stackADT.h"

int main(void) {
    Stack s1, s2;
    int n;
    s1 = create();
    s2 = create();
    push(s1, 1);
    push(s2, 2);
    n = pop(s1);
    printf("Popped %d from s1\n", n);
    push(s2, n);
    printf("Popped %d from s1\n", n);
    push(s2, n);
    destroy(s1);
    while (!is_empty(s2))
        printf("Popped %d from s2\n", pop(s2));
    push(s2, 3);
    make_empty(s2);
    if (is_empty(s2))
        printf("s2 is empty\n");
    else
        printf("s2 is not empty.\n");
    destroy(s2);
    return 0;


}