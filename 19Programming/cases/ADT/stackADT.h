/********************************************************************************
* @author: mason shi
* @date: 2023/9/16 11:43
* @version: 1.0
* @description: 为栈的抽象数据类型定义的接口
 *              包含头文件stackADT.h的客户可以声明Stack类型的变量，这些变量都可以指向stack_type结构。之后客户就可以调用在stackADT.h中声明的
 *              函数对栈变量进行操作。但是客户不能访问stack_type结构的成员，因为该结构的定义在另一个文件中。
********************************************************************************/
#ifndef STACKADT_H
#define STACKADT_H

#include<stdbool.h>

/*
 * C语言中的不完整类型：描述了对象但缺少定义对象大小所需的信息。
 * 像下面的类型定义声明，类型Stack的变量是指向标记为stack_type的结构的指针。现在可以声明类型Stack的变量
 * ，将其作为函数的参数进行传递，并可以执行其他的合法的指针运算(指针的大小不依赖于它指向的对象)。但我们不能对这些变量
 * 使用->运算符，因为编译器对stack_type结构的成员一无所知。这只是告诉编译器stack_type是一个结构标记，但并没有描述结构的成员。编译器
 * 没有足够的信息来确定该结构的大小。这样做的意图是，不完整类型会在程序的其他地方将信息补充完成。
 * 但是不完整类型的使用是受限的。因为编译器不知道不完整类型的大小，所以不能用它来声明变量：
 * struct stack_type test;
 * 但是可以完全定一个指针类型引用不完整类型，如下所示：
 * */
typedef struct stack_type *Stack;

/*create函数和destroy函数。模块通常不需要这些函数，但抽象数据类型需要。create会自动给栈分配内存(包括stack_type结构需要的内存)
 * 同时把栈初始化为“空”状态。destroy将释放栈的动态分配内存。
 * */
Stack create(void);

void destroy(Stack s);

void make_empty(Stack s);

bool is_empty(Stack s);

bool is_full(Stack s);

/*push和pop等函数，每一个函数都有一个Stack参数或返回一个Stack值。19.3节中的栈函数都具有Stack*类型的参数。导致这种差异的原因是，Stack变量现在是指针
 * ，指向存放着栈内容的stack_type结构。如果函数需要修改栈，则改变的是结构本身，而不是指向结构的指针。
 * */
void push(Stack s, int value);

int pop(Stack s);

int peek(Stack s);


#endif
