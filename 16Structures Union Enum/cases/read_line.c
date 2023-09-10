/********************************************************************************
* @author: mason shi
* @date: 2023/8/12 22:36
* @version: 1.0
* @description:
********************************************************************************/
#include<ctype.h>
#include<stdio.h>
#include "readline.h"

/**
 * read_line: Skips leading white-space characters, then reads the remainder of the input
 * line and stores it in str. Truncates the line if its length exceeds n. Returns the number of
 * characters stored.
 * @param str
 * @param n
 * @return
 */
int read_line(char str[], int n) {
    int ch,i=0;
    while (isspace(ch = getchar()));//判断ch是否是空白字符。如果不是空白字符，循环停止，ch中包含一个非空白字符
    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}