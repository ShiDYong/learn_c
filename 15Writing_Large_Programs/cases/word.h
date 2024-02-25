/********************************************************************************
* @author: mason shi
* @date: 2023/8/6 14:18
* @version: 1.0
* @description: 第十五章 编写大型程序的案例:头文件的函数原型
********************************************************************************/
#ifndef WORD_H  //防止多次包含word.h文件，这是保护所有头文件的一个好习惯。
#define WORD_H

/**
 * read_word: Reads the next word from the input and stores it in word. Marks word empty if
 *            no word could be read because of end-of-file,Truncates the word if its length
 *            exceeds len.
 * @param word
 * @param len
 */
void read_word(char *word, int len);

#endif