/********************************************************************************
* @author: mason shi
* @date: 2023/9/16 16:45
* @version: 1.0
* @description: 改变栈抽象数据类型中数据项的类型
 * 上面版本的有很大局限：首先，注意到栈里面的项都是整数，太具有局限性了。事实上，栈中的数据项是无关紧要的，可以是其他基本类型(float,double,long等)
 * ，也可以是结构、联合或指针。为了使栈数据类型更易于针对不同的数据项类型进行修改，我们在stackATD02.h中增加了一行类型定义。现在用类型名Item表示待存储
 * 到栈中的数据的类型。
********************************************************************************/
#ifndef STACKATD2_H
#define STACKATD2_H

#include<stdbool.h>

typedef int Item;
typedef struct stack_type *Stack;

Stack create(int size);

void destroy(Stack s);

void make_empty(Stack s);

bool is_empty(Stack s);

bool is_full(Stack s);

void push(Stack s, Item i);

Item pop(Stack s);

Item peek(Stack s);


#endif