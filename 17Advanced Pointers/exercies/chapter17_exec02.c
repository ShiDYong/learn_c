/********************************************************************************
* @author: mason shi
* @date: 2023/9/10 21:08
* @version: 1.0
* @description:第十七章指针的高级运用课后练习题
********************************************************************************/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

void exec09(void);

#define NAME_LEN 25
#define MAX_PARTS 100
//定义存储零件的结构的数组
struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

struct node {
    int data;
    struct node *next;
};

int count_occurrences(struct node *list, int n);

void insert_to_beginning(struct node **head, int data);

void insert_to_end(struct node **head, int data);

void print_list(struct node *head);

void free_list(struct node *head);

void delete_from_list(struct node **head, int value);

int num_parts = 0;/*number of parts currently stored*/
int find_part(struct part *p);


struct X {
    int a;
};


/**
 * 课后练习题09:
 * 判断：如果x是一个结构而a是该结构的成员，那么(&x)->a与x.a是一样的。验证你的答案。
 */

void exec09(void) {
    struct X x = {10};
    printf("(&x)->a的结果是：%d\n", (&x)->a);
    printf("&X内存地址是：%p\n", &x);
    printf("x.a的结果是：%d\n", x.a);

    /*(&x)->a 和 x.a 都访问结构 x 的成员 a。 -> 运算符用于通过指向结构的指针来访问结构成员，而 . 运算符用于直接访问结构体成员。
    因此，(&x)->a 和 x.a 本质上通过访问结构 x 的相同成员 a 来实现相同的结果。*/

}


/**
 * 课后练习题10:修改16.2节的print_part函数，使得它的形式参数是一个指向part结构的指针。请使用->运算法
 * @param p
 * @return
 */
int find_part(struct part *ptr) {
    printf("Part number: %d\n", ptr->number);
    printf("Part name: %s\n", ptr->name);
    printf("Part on hand: %d\n", ptr->on_hand);


}


/**
 * 课后练习题目11.编写下列函数：
 *  其中形式参数list指向一个链表。函数应返回n在链表中出现的次数。node结构的定义见17.5节.
 * @param list
 * @param n
 * @return
 */
int count_occurrences(struct node *list, int n) {

    int count = 0;
    while (list != NULL) {
        if (list->data == n)
            count++;
        list = list->next;
    }
    return count;

}


/**
 * 创建一个新结点的方法
 * @param data
 * @return
 */
struct node *create_node(int data) {
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Memory allocation failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = data;
    new_node->next = NULL;
    return new_node;

}

/**
 * 将数据插入的链表的首结点中
 * @param head
 * @param data
 */
void insert_to_beginning(struct node **head, int data) {
    struct node *new_node = create_node(data);
    new_node->next = *head;
    *head = new_node;

}

/**
 * 将数据插入到链表尾结点
 * @param head
 * @param data
 */
void insert_to_end(struct node **head, int data) {
    struct node *new_node = create_node(data);
    //判断是否尾结点
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node *current = *head;
    while (current->next != NULL)
        current = current->next;
    current->next = new_node;//尾结点的next指针指向NULL

}


/**
 * 课后练习题14:修改函数delete_from_list。使函数的第一个形式参数是struct node **类型(即指向链表首结点的指针的指针)。并且
 * 返回类型是void。在删除了期望的结点后，函数delete_from_list必须修改第一个实际参数，使其指向该链表。
 * @param head
 * @param value
 */
void delete_from_list(struct node **head, int value) {
    //使用指针追踪法
    struct node *cur = *head;
    struct node *prev = NULL;
    //1.要删除是第一个结点
    if (cur != NULL && cur->data == value) {
        *head = cur->next;
        free(cur);
        return;
    }
    //2.排除没有找到的数据
    while (cur != NULL && cur->data != value) {
        prev = cur;
        cur = cur->next;
    }
    //3.要删除的数据不在链表中
    if (cur == NULL) {
        printf("Element %d not fond in the list.\n", value);
        return;
    }

    //剩下就是要删除的结点
    prev->next = cur->next;
    free(cur);


}


/**
 * 课后练习题目12:编写下列函数
 * 其中形式参数head指向一个链表。函数返回一个指针，该指针指向最后一个包含n的结点，如果n不存在则返回NULL。node的结构定义见17.5节
 * @param head
 * @param n
 * @return
 */
struct node *find_last(struct node *head, int n) {
    struct node *last = NULL;
    struct node *p = head;
    while (p != NULL) {
        if (p->data == n)
            last = p; //有多个值，就取最后一个
        p = p->next;

    }
    return last;


}

/**
 * 课后练习题13:下面的函数希望在有序链表的适当位置插入一个新结点，并返回指向新链表结点的指针。但是，函数无法做到在所有的情况下都正确。
 * 解释问题所在，并说明如何修正。node结构的定义如上.
 * @param head
 * @param new_node
 * @return
 */
struct node *insert_into_ordered_list(struct node *list, struct node *new_node) {
//    struct node *cur = head, *prev = NULL;
//    while (cur->data <= new_node->data) {
//        prev = cur;
//        cur = cur->next;
//    }
//    prev->next = new_node;
//    new_node->next = cur;
//    return head;
    /*存在的问题：
     * 提供的 insert_into_ordered_list 函数旨在将新节点插入到有序列表中的适当位置。 然而，
     * 这个函数有一个问题：它不能处理新节点应该正确插入到列表开头的情况。 此外，它不处理列表最初为空的情况。
     * 1.当应将 new_node 插入链表的开头时，不会检查是否更新链表指针。 在这种情况下，列表指针应该指向new_node，但原始代码保持不变。
       2.该代码在开始插入过程时假定列表不为空。 如果列表最初为空，尝试访问 cur->value 将导致未定义的行为。
     * */

    struct node *cur = list, *prev = NULL;

    // Handle the case when the list is empty or new_node should be inserted at the beginning
    if (list == NULL || new_node->data <= list->data) {
        new_node->next = list;
        return new_node; // Update the list pointer to point to new_node
    }

    while (cur != NULL && cur->data <= new_node->data) {
        prev = cur;
        cur = cur->next;
    }

    prev->next = new_node;
    new_node->next = cur;

    return list; // Return the updated list

}

/**
 * 打印链表中所有的结点的数据
 * @param head
 */
void print_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        printf("%d-> ", current->data);
        current = current->next;
    }
    printf("NULL\n");

}

/**
 * 释放链表申请的内存
 * @param head
 */
void free_list(struct node *head) {
    struct node *current = head;
    while (current != NULL) {
        struct node *next = current->next;
        free(current);
        current = next;

    }
}

int main(void) {
    // exec09();
    struct node *head = NULL;
    insert_to_beginning(&head, 1);
    insert_to_beginning(&head, 4);
    insert_to_end(&head, 2);
    insert_to_end(&head, 5);
    insert_to_end(&head, 2);
    printf("3在链表中出现的次数：%d\n", count_occurrences(head, 3));
    printf("Linked list: ");
    print_list(head);
    //插入链表使链表是有序的
    int n = 4;
    struct node *new_node = create_node(n);
    insert_into_ordered_list(head,new_node);


    //释放链表占用的内存空间
    free_list(head);


    return 0;
}