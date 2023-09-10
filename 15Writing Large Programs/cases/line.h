/********************************************************************************
* @author: mason shi
* @date: 2023/8/6 14:24
* @version: 1.0
* @description: 处理所有和缓冲区相关的函数头文件
********************************************************************************/
#ifndef LINE_H
#define LINE_H
//以下是函数原型


/**
 * clear_line:Clears the current line.
 * 即清除行缓冲区
 */
void clear_line(void);

/**
 * add_word: Adds word to the end of the current the line. If this if not the first word on
 *          the line, puts one space before word.
 *          即往行缓冲区中添加单词
 * @param word
 */
void add_word(const char *word);


/**
 * space_remaining: Return the number of character left in the current line.
 * 即检查缓冲区还剩多少字符
 * @return
 */
int space_remaining(void);


/**
 * write_line: Write the current line with justification.
 * 即输出缓冲区的内容，进行调整
 */
void write_line(void);


/**
 * flush_line: Writes the current line without justification. If the line is empty,does nothing.
 */
void flush_line(void);

#endif
