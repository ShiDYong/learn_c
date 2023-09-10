/********************************************************************************
* @author: mason shi
* @date: 2023/9/10 11:46
* @version: 1.0
* @description: 课后练习题08
 * 15.2节描述的文件stack.c提供了在栈中存储整数。在那一节中，栈是用数组实现的。请修改程序stack.c从而使栈现在作为
 * 链表来存储。使用单独一个指向链表首节点的指针变量(栈顶)来替换变量contents和变量top。在stack.c中编写的函数使用
 * 此指针。删除函数is_full，用返回true(如果创建的结点可以获得内存)或false(如果创建的结点无法获得内存)的函数push来
 * 代替。
********************************************************************************/
#include <stdio.h>
#include<stdlib.h>
#include<ctype.h>

//#define bool int
//#define true 1
//#define false 0
//自定义bool
//typedef enum {
//    false = 0, true = 1
//} bool;

#include<stdbool.h>

struct node {
    int data;
    struct node *next;
};
struct node *top = NULL;


void make_empty(void);

bool is_empty();

bool push(int n);

int pop(void);

void print_stack(struct node *list);

int main(void) {

    //验证入栈的操作
    for (int i = 0; i < 5; ++i)
        push(i);
    //打印栈中的元素
    printf("Print element of stack after push.\n");
    print_stack(top);
    //出栈操作
    for (int k = 0; k < 3; k++)
        printf("弹出栈的元素是：%d\n", pop());
    printf("Print element of stack after pop.\n");
    print_stack(top);
    //判断栈是否为空的操作
    printf("清空前栈是否为空的结果：%d\n", is_empty());
    //清空栈的操作
    make_empty();
    printf("清空后栈是否为空的结果：%d\n", is_empty());


    return 0;
}

/**
 * 清空链表
 */
void make_empty(void) {
    struct node *temp;
    if (top != NULL) {
        temp = top;
        top = top->next;
        free(temp);
    }

}

/**
 * 判断当前链表是否为空
 * @return
 */
bool is_empty(void) {
    return top == NULL;
}

/**
 * 方法的参数不需要传入链表的指针,只需要传入要插入的值就可以了
 * @param n
 * @return
 */
bool push(int n) {
    struct node *new_node;
    new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL)
        return false;
    new_node->data = n;
    new_node->next = top;
    top = new_node;
    return true;

}

/**
 * 出栈的操作
 * @param list
 */
int pop(void) {
    struct node *temp;
    int i;
    if (is_empty()) {
        printf("Error: stack underflow\n");
        exit(EXIT_FAILURE);
    }
    //注意理解下面的处理方式
    i = top->data;
    temp = top;
    top = top->next;
    free(temp);
    return i;

}

/**
 * 实现对栈的打印，也就是打印链表的数据
 * @param list
 */
void print_stack(struct node *list) {
    while (list != NULL) {
        printf("%d->", list->data);
        list = list->next;
    }
    printf("NULL\n");
}