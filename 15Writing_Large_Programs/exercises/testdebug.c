/********************************************************************************
* @author: mason shi
* @date: 2023/8/8 22:10
* @version: 1.0
* @description: 课后练习题04
********************************************************************************/
#include<stdio.h>

#define DEBUG

#include "debug.h"


int main(void) {
    int i = 1, j = 2, k = 3;
#ifdef DEBUG
    printf("Output if DEBUG is defined: \n");
#elif
    printf("Output if DEBUG is not defined: \n");
#endif
    PRINT_DEBUG(i);
    PRINT_DEBUG(j);
    PRINT_DEBUG(k);
    PRINT_DEBUG(i + j);
    PRINT_DEBUG(2 * i + j - k);
    return 0;

    /*a.程序执行时的输出是什么？*/
    /*b.如果从testdebug.c中删除#define指令，输出又是什么？*/
    /*c.解释(a)和(b)的输出为什么不同。*/
    /*d.为了使PRINT_DEBUG能起到预期的效果，把DEBUG宏的定义放在包含debug.h的指令之前是否又必要？验证的你的结论*/
}