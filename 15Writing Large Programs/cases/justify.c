/********************************************************************************
* @author: mason shi
* @date: 2023/8/6 14:37
* @version: 1.0
* @description: 小型文本格式化的主程序
********************************************************************************/
#include<string.h>
#include "line.h"
#include "word.h"

#define MAX_WORD_LEN 20

int main(void) {
    char word[MAX_WORD_LEN + 2];
    int word_len;
    clear_line();//引入justify函数方法
    for (;;) {
        read_word(word, MAX_WORD_LEN + 1);
        word_len = strlen(word);
        //缓冲区不能读单词,输出缓冲区的内容，不进行调整，终止程序
        if (word_len == 0) {
            flush_line();
            return 0;
        }
        //将单词长度超过20的单词后面值设置为“*”
        if (word_len > MAX_WORD_LEN)
            word[MAX_WORD_LEN] = '*';
        //行缓冲区已经填满，输出缓冲区的内容，进行调整，清除缓冲区
        if (word_len + 1 > space_remaining()) {
            write_line();
            clear_line();
        }
        //继续添加单词
        add_word(word);
    }

}
