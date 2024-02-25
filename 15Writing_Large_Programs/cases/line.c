/********************************************************************************
* @author: mason shi
* @date: 2023/8/6 14:54
* @version: 1.0
* @description: 文件line.c的实现
********************************************************************************/
#include<stdio.h>
#include<string.h>
#include "line.h"

#define MAX_LINE_LEN 60
char line[MAX_LINE_LEN + 1];
int line_len = 0;
int num_words = 0;

/**
 * 清空行缓冲区
 */
void clear_line(void) {
    line[0] = '\0'; //将第一位的值设置空字符，变成空的字符串
    line_len = 0;
    num_words = 0;
}

/**
 * 往缓冲区中添加单词
 * @param word
 */
void add_word(const char *word) {
    if (num_words > 0) {
        line[line_len] = ' ';
        line[line_len + 1] = '\0';
        line_len++;
    }
    strcat(line, word);
    line_len += strlen(word);
    num_words++;
}

/**
 * 查看缓冲区剩余的长度
 * @return
 */
int space_remaining(void) {
    return MAX_LINE_LEN - line_len;
}

/**
 * 对缓冲区的内容进行输出并做处理
 */
void write_line(void) {
    //额外空格的数量
    int extra_spaces, spaces_to_inset, i, j;
    extra_spaces = MAX_LINE_LEN - line_len;
    for (i = 0; i < line_len; i++) {
        if (line[i] != ' ')
            putchar(line[i]);
        else {
            spaces_to_inset = extra_spaces / (num_words - 1);
            for (j = 1; j <= spaces_to_inset+1; j++)
                putchar(' ');
            extra_spaces -= spaces_to_inset;
            num_words--;


        }


    }
    putchar('\n');
}

void flush_line(void) {
    if (line_len > 0)
        puts(line);
}
