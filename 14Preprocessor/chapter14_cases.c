/********************************************************************************
* @author: mason shi
* @date: 2023/8/5 09:58
* @version: 1.0
* @description: 第十四章：预处理器C程序。C语言因为依赖预处理器而不同与其他的编程语言
 *          预处理器是一种强大的工具，但它同时也可能是许多难以发现的错误的根源；适度使用它。
********************************************************************************/

#include<string.h>
#include<stdio.h>

#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f/9.0f)

void cases14_1();

int main(void) {
    return 0;
}


/**
 * 14.1节：预处理器的工作原理
 *  预处理器的行为是由预处理指令(由#字符开头的一些命令)控制的。
 *  其中#define命令定义来一个宏——用来代表其他东西的一个名字，例如常量或常用的表达式。预处理器会通过将宏的名字和它的
 *  定义存储在一起来响应#define指令。当这个宏后面的程序中使用到时，预处理器扩展宏，将宏替换为其定义内容。
 *  #include指令告诉预处理器打开一个特定的文件，将它的内容作正在编译的文件的一部分包含进来。
 *  例如：#include<stdio.h>
 *  指示预处理器将打开一个名为stdio.h的文件，并将它的内容加到当前的程序
 *
 */
void cases14_1() {
    /**预处理器在编译过程中的作用：
     * C程序——>预处理器——>修改后的C程序——>编译器——>目标代码
     * 说明：
     * 预处理器的输入是一个C语言程序，程序可能包含指令。预处理器会执行这些命令，并在处理过程中删除这些命令。预处理器的输出
     * 是另一个C程序：原程序编辑后的版本，不再包含指令。预处理器的输出被直接交给编译器，编译器检查程序是否有误，并将程序翻译目标代码
     * (机器指令)
     * */
    //原程序如下：
    float fahrenheit, celsius;
    printf("Enter Fahrenheit temperature: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;
    printf("Celsius equivalent is :%.1f\n", celsius);
    //在Linux系统内执行:gcc -E celsius.c -o test.log 命令后，查看
    //test.log会长达800行的程序，引入大量的库内容，以下是截取的部分内容
/*
    extern char *ctermid (char *__s) __attribute__ ((__nothrow__ , __leaf__));
    # 913 "/usr/include/stdio.h" 3 4
    extern void flockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
    extern int ftrylockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__)) ;
    extern void funlockfile (FILE *__stream) __attribute__ ((__nothrow__ , __leaf__));
# 943 "/usr/include/stdio.h" 3 4
# 2 "celsius.c" 2
    int main(void){

        float fahrenheit, celsius;
        printf("Enter Fahrenheit temperature: ");
        scanf("%f", &fahrenheit);
        celsius = (fahrenheit - 32.0f) * (5.0f/9.0f);
        printf("Celsius equivalent is :%.1f\n", celsius);
    }*/
/**
 * 预处理器通过引入stdio.h的内容来响应#include指令。预处理器也删除了#define命令，并且替换了该文件中稍后
 * 出现在任何位置上的FREEZING_PT和SCALE_FACTOR。请注意预处理器并没有删除包含指令的行，而是简单地将它们替换
 * 为空。预处理器不仅仅执行了指令，还做了其他的事情。特别值得注意的是，它将每一处都替换为一个空格字符。有一些预处理器
 * 还会进一步删除不必要的空白字符，包括每一行开始用于缩进的空格符和制表符。
 * */

}

/**
 * 14.2 常见的预处理指令
 *  1.宏定义。 #define命令定义一个宏，#undef指令删除一个宏定义。
 *  2.文件包含。#inlcude指令导致一个被指定文件的内容被包含到程序中。
 *  3.条件编译。#if,#ifdef,#ifndef,#elif,#else和#endif指令能根据预处理器可以测试的条件来确定，是将
 *  一段文本块包含到程序中，还是将其排除在程序之外。
 *  剩余的#error、#line和#pragma指令是更特殊的指令，很少用到。
 *  适用所有指令的规则：
 *  1.指令都以#开始。#符号不需要出现在一行的行首，只要在它之前只有空白字符就行。在#后是指令名，接着就是指令所需要的其他信息。
 *  2.在指令的符号之间可以插入任意数量的空格或水平制表符。例如，下面的指令是合法的。
 *  #   define      N       100
 *  3.指令总是第一个换行符处结束，除非明确地指明要延续。如果想在下一行延续指令，我们必须在当前行的末尾使用\字符。
 *  #define DISK_CAPACITY(SIDES *             \
 *                        TRACKS_PER_SIDE *   \
 *                        SECTORS_PER_TRACK * \
 *                        BYTES_PER_SECTOR)
*  4.指令可以出现在程序中的任何地方。但我们通常将#define和#include指令放在文件的开始，其他指令则放在后面，甚至
 *  可以放在函数定义的中间。
 * 5.注释可以与指令放在同一行。实际上，在宏定义的后面加一个注释来解释宏的定义是一种比较好的习惯；
 * #define FREEZING_PT 32.0f /*freezing point of water*/
void cases14_3() {
    /*14.3.1:简单的宏：
     * 简单的宏(C标准中称为对象式宏)的定义如下格式：
     * [#define 指令(简单的宏)] #define 标识符替换列表
     * 替换列表是一系列的预处理极好。这里的记号是指“预处理记号”.
     * 宏的替换列表可以包括标识符、关键字、数值常量、字符常量、字面串、运算符和标点符号。
     * 当预处理器遇到一个宏定义时，会做一个“标识符”代表“替换列表”的记录。在文件后面的内容中，不管标识符在哪里出现，
     * 预处理器都会用替换列表代替它，案例如下：
     * #define STR_Len 10
     * #define TRUE 1
     * #define FALSE 0
     * #define PI 3.1415926
     * #define CR '\r'
     * #define EOS '\0'
     * #define MEM_ERR "Error: not enough memory"
     * 使用#define的好处有很多，这里省略
     * */

    /**
     * 14.3.2 带参数的宏(也称为函数式宏)的定义如下格式：
     * [#define指令(带参数的宏)] #define标识符(x1,x2,x3...,xn)替换列表
     * 其中x1,x2,x3,...,xn是标识符(宏的参数).这些参数可以在替换列表中根据需要出现任意次。
     * ⚠️：在宏的名字和左括号之间必须没有空格。如果有空格，预处理器会认为在定义一个简单的宏
     * 当预处理器遇到带参数的宏时，会将定义存储起来以便后面使用。
     * 案例定义如下：
     */
#define MAX(x, y) ((x)>(y)?(x):(y))
#define IS_EVEN(n) ((n) %2==0)
    //带参数的优势和弊端省略


}