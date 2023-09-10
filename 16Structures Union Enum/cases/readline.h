/********************************************************************************
* @author: mason shi
* @date: 2023/8/12 22:33
* @version: 1.0
* @description: read_line函数与inventory.c文件中的其他函数无关，而且它在其他程序中有复用的可能
 * 所以决定把此函数从inventory.c中独立出来。read_line函数的原型将放在头文件read_line.h中
********************************************************************************/
#ifndef READLINE_H
#define READLINE_H


int read_line(char str[], int n);

#endif