/********************************************************************************
* @author: mason shi
* @date: 2023/9/3 11:25
* @version: 1.0
* @description: 第十八章课后练习题
********************************************************************************/
#include<stdio.h>

#define MAX_NAME 100

int test_exec04(int i);

int main(void) {
    for (int i = 0; i < 5; i++)
        printf("调用第%d的值是：%d\n", i, test_exec04(10));
    return 0;
}


/**
 * 课后练习题01:请指出下列声明的存储类型、类型限定符、类型指定符、声明符和初始化器
 */
//a:不能声明在块中
static char **lookup(int level);
/*
    Storage class: `static`
    Type qualifiers: none
    Type specifiers: `char **`
    Declarators: `lookup(int level)`
    Initializers: none
*/


//d
static const char token_buf[] = "";

/*
  Storage class: `static`
  Type qualifiers: `const`
  Type specifiers: `char []`
  Declarators: `token_but`
  Initializers: `""`
*/
void test_exec01() {
    //b.
    volatile unsigned long io_flags;
    /*
    Storage class: none
    Type qualifiers: `volatile`
    Type specifiers: `unsigned long`
    Declarators: `io_flags`
    Initializers: none
     * */

    //c
    extern char *file_name[MAX_NAME], path[];
    /*
    Storage class: `extern`
    Type qualifiers: none
    Type specifiers: `char * []`
    Declarators: `file_name, path`
    Initializers: none
     */

}

/**
 * 列出下列文件中每个变量和形式参数的存储期(静态/自动)、作用域(块/文件)、链接(内部/外部/无)；
 */
extern float a;

void test_exec03(register double b) {
    static int c;
    auto char d;
    /*
    `a`: static duration, file scope, external linkage.
    `b`: automatic duration, block scope, no linkage.
    `c`: static duration, block scope, no linkage.
    `d`: automatic duration, block scope, no linkage.
     * */

}

/**
 * 课后练习04:假设函数test_exec04是下列函数。如果在此之前f从来被调用过，那么test_exec04(10)的值是多少？
 * 如果在此之前f已经被调用过5次，那么f(10)的值又是多少？
 * @param i
 * @return
 */
int test_exec04(int i) {
    static int j = 0;
    return i * j++;
}


/**
 * 课后练习题08:请按下列每个声明指定的那样编写X类型的完整描述
 */
void test_exec08() {
    //a.
    char (*x[10])(int);
    //x is an array of 10 elements.
    //Each element of x is a function pointer that takes an integer argument (int) and returns a character (char).
    //So, x is an array of 10 function pointers, where each function pointer points to a function that takes an
    // integer argument and returns a character.
    //b.
    int (*y(int))[5];
   /*x is a function that takes an integer argument (int).
    The return type of this function is a pointer to an array of 5 integers (int[5]).
    So, x is a function that takes an integer and returns a pointer to an array of 5 integers.
    * */

    //c.
    float *(*z(void))(int);
    /*
    x is a function that takes no arguments (void).
    The return type of this function is a pointer to a function.
    The function pointed to by the returned pointer takes an integer argument (int)
    and returns a pointer to a float (float *).
    So, x is a function that takes no arguments and returns a pointer to a function that
    takes an integer and returns a pointer to a float.
     * */

    //d.
    void (*k(int, void (*y)(int)))(int);
    //`k` is a function with two arguments: an `int` and a pointer to a function with
    //an `int` argument which returns nothing. `k` returns a pointer to a function
    //with an `int` argument and no return value.

}

/*课后练习题09:请利用一系列的类型定义来简化练习题08的每个声明*/

//a.char (*x[10])(int);type definition
typedef char (*FunctionPtr)(int);
FunctionPtr x[10];


//b.    int (*y(int))[5];
typedef int (*IntArrayPtr)[5];
IntArrayPtr y(int);

//c.    float *(*z(void))(int)
typedef float* (*FunctionP)(int);
FunctionP w(void);

//d.    void (*k(int, void (*y)(int)))(int);

typedef void (*InnerFunctionPtr)(int);
typedef void (*OuterFunctionPtr)(int, InnerFunctionPtr);
OuterFunctionPtr v(int, InnerFunctionPtr);



