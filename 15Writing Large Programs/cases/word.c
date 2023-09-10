/********************************************************************************
* @author: mason shi
* @date: 2023/8/6 14:48
* @version: 1.0
* @description: word.c对应的程序
********************************************************************************/
#include<stdio.h>
#include "word.h"

int read_char(void) {
    //  printf("Enter a words: ");
    int ch = getchar();
    if (ch == '\n' || ch == '\t')
        return ' ';
    return ch;
}

void read_word(char *word, int len) {
    int ch, pos = 0;
    while ((ch = read_char()) == ' ');
    while (ch != ' ' && ch != EOF) {
        if (pos < len)
            word[pos++] = ch;
        ch = read_char();
    }
    word[pos] = '\0';

}