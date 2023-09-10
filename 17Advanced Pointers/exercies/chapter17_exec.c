/********************************************************************************
* @author: mason shi
* @date: 2023/9/6 22:14
* @version: 1.0
* @description: 第十七章 指针的高级运用课后练习题
********************************************************************************/
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
#include<string.h>

//课后练习题04
struct point {
    int x, y
};
struct rectangle {
    struct point upper_left, low_right;
};
//课后练习题05:假设f和p的声明如下所示
struct {
    union {
        char a, b;
        int c;
    } d;
    int e[5];
} f, *p = &f;
//课后练习题06
struct Node {
    int data;
    struct Node *next;
};

void *my_malloc(size_t n);

char *duplicate(const char *str);

int *create_array(int n, int initial_value);

struct Node *delete_from_list(struct Node **list, int value);

void print_list(struct Node *head);

void add_to_list(struct Node **list, int n);

void delete_all_list(struct Node **list);

int main(void) {
    //.1课后练习题01
    int *dynamicArray;
    size_t numElements = 10;
    // Now you can use dynamicArray as you would with a regular malloc'd pointer
    // Don't forget to free the allocated memory when you're done
    dynamicArray = (int *) my_malloc(numElements * sizeof(int));
    // Use the allocated memory
    for (int i = 0; i < 10; i++) {
        dynamicArray[i] = i;
        printf("%d", dynamicArray[i]);
    }
    free(dynamicArray);


    //课后练习题02
    const char *originalStr = "Hello, World!";
    char *duplicateStr = duplicate(originalStr);
//    while (*nStr != '\0') {
//        printf("%c", *nStr);
//        nStr++;
//
//    }
    if (duplicateStr == NULL) {
        printf("Memory allocation failed\n");
        return 1; // Exit with an error code.
    }
    //因为是字符串，不需要像数组一样循环打印出来，这个是问题
    printf("Original string: %s\n", originalStr);
    printf("Duplicate string: %s\n", duplicateStr);

    // Don't forget to free the allocated memory when done.
    free(duplicateStr);

    //课后练习题03
    int n = 5, initial_value = 1;
    int *result = create_array(n, initial_value);
    if (result != NULL) {
        // Print the elements of the dynamically created array
        for (int i = 0; i < n; i++)
            printf("result[%d] = %d\n", i, result[i]);


        // Don't forget to free the dynamically allocated memory when done
        free(result);
    } else {
        printf("Memory allocation failed. Returned NULL.\n");
    }

    /*课后练习题04:假设下列声明有效
 * 假设希望p指向一个rectangle结构，此结构的左上角位于(10,25)的位置上，而右下角位于(20,15)的位置上。
 * 请编写一系列语句用来分配这样一个人结构，并且像说明的那样进行初始化。
 * */
    //动态分配内存这里强制转换类型是结构
    struct rectangle *ptr = (struct rectangle *) malloc(sizeof(struct rectangle));
    if (ptr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }
    //开始初始化
    ptr->upper_left.x = 10;
    ptr->upper_left.y = 25;
    ptr->low_right.x = 20;
    ptr->low_right.y = 15;
    // You can access the coordinates like this:
    printf("Upper Left Corner: (%d, %d)\n", ptr->upper_left.x, ptr->upper_left.y);
    printf("Lower Right Corner: (%d, %d)\n", ptr->low_right.x, ptr->low_right.y);
    //释放内存
    free(ptr);

    /*课后练习题05:那么下列哪些语句是合法的？*/
    // p->b='';非法的，应该改为下面的
    p->d.b = ' ';
    p->e[3] = 10; //合法的
    (*p).d.a = '*'; //合法的
    // p->d->c=20;  非法的

    /*课后练习题06：
     * 请修改delete_from_list使它使用一个指针变量而不是两个(即cur和prev)
     * */
    // Create a sample linked list: 1 -> 2 -> 3 -> 4 -> NULL
    struct Node *list = NULL;
    for (int i = 0; i < 4; i++) {
        struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
        new_node->data = i;
        new_node->next = list;
        list = new_node;
    }
    //根据已有的方法往链表插入结点
    struct Node *head = NULL;
    for (int i = 0; i < 5; i++)
        add_to_list(&head, i);
    printf("Linked list after Add.\n");
    print_list(head);
    //课后练习题07删除链表中的所有结点方法
    delete_all_list(&head);
    printf("Linked list after Delete all.\n");
    print_list(head);


    printf("Original Linked list.\n");
    print_list(list);
    // Delete a node (e.g., delete 3)
    delete_from_list(&list, 2);
    printf("Linked list after Delete 3:\n");
    print_list(list);
    // Free the memory of the remaining nodes
    while (list != NULL) {
        struct Node *temp = list;
        list = list->next;
        free(temp);
    }

    /*双指针：指向指针的指针简单使用案例
     * 案例生动说明详细说明：有个人住在401，这个401就是个指针。你把401写在纸上，夹到一本书里，放在第200页。
     * 这个200页就是指针的指针。你把书名及200写在另外一张纸上，拍了个照片，照片文件名是20151209001.jpg
     * ,这个就是指针的指针的指针。你怕这个图片丢失，又保存到某个邮箱中，这个就是指针的指针的指针的指针。
     * 如果你忘记了这个人住在哪个房间，于是你可以打开邮箱，查看照片，找到书，翻到200页，看到401，
     * 于是就去401找到了这个人。
     * */
    int x = 10;
    int *ptr1 = &x;// ptr1 是一个指向整数 (int *) 的指针。
    int **ptr2 = &ptr1; // ptr2 是一个指向整数指针 (int **) 的双指针
    //ptr2 指向 ptr1 的地址，而 ptr1 本身又指向整数 x 的地址。

    printf("Value of x: %d\n", x);
    // printf("address of x : %p\n",&x);
    printf("Value pointed to by ptr1: %d\n", *ptr1); //10
    //printf("value of ptr1: %p\n",ptr1); //10
    // printf("address of  ptr1: %p\n",&ptr1);
    printf("Value pointed to by ptr2: %d\n", **ptr2); //10
    //printf("value of  ptr2: %d\n",*ptr2);
    //printf("address of  ptr2: %p\n",&ptr2);
    //Modifying the value indirectly using double pointer
    //当您使用**ptr2时，它允许您通过双指针间接访问和修改x的值。 当您想要将指针传递给函数并让该函数修改原始指针时，
    //或者当您需要使用动态内存分配并处理指向指针的指针时，这特别有用。双指针通常用于动态内存分配（例如 malloc、free）等场景，
    //以及需要将指针传递给函数并修改这些函数内的原始指针时。
    **ptr2 = 20;
    printf("Modified value of x: %d\n", x);


    return 0;
}

/**
 * 课后练习题01:每次调用时都要检查malloc(或其他任何内存分配函数)的返回值是件很烦人的事情。请编写一个名为my_malloc
 * 的函数作为malloc函数的“包装器”。当调用函数my_malloc并且要求分配n字节时，它会调用malloc函数，判断malloc函数确实
 * 没有返回空指针，然后返回来自malloc的指针。如果检查malloc返回空指针，那么函数my_malloc显示出错消息并且终止程序。
 * @return
 */
void *my_malloc(size_t n) {
    void *numPtr;//因为没有指定任何类型指针,所以需要用void*
    //numPtr = (int *) malloc(n);
    if ((numPtr = malloc(n)) == NULL) {
        printf("Memory allocation failed\n");
        //return;直接这样会操作失败
        exit(EXIT_FAILURE);
    }
    return numPtr;


}


/**
 * 课后练习题02:
 * 编写名为duplicated的函数，此函数使用动态存储分配来创建字符串的副本。例如p=duplicated(str);
 * 将为和str长度相同的字符串分配内存空间，并且把字符串str的内容复制到新字符串中，然后返回指向新字符串的指针。
 * 如果分配内存失败，那么函数duplicated返回空指针。
 * @param str
 * @return
 */
char *duplicate(const char *str) {
    //  int count = 0;
    if (str == NULL)
        return NULL;
//    while (*str != '\0') {
//        str++;
//        count++;
//
//    }
    //改为通过strlen函数获取长度
    size_t length = strlen(str);
    char *newStr = (char *) malloc(length + 1);
    if (newStr == NULL) {
        printf("Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    strcpy(newStr, str);
    return newStr;

}

/**
 * 课后练习题03:编写下列函数
 * 函数应返回一个指向动态分配的n元int型数组的指针，数组的每个成员都初始化为initial_value。
 * 如果内存分配失败，返回值为NULL。
 * @param n
 * @param initial_value
 * @return
 */
int *create_array(int n, int initial_value) {
    //下面是方法一：
    /*int *a, *p;
    a = (int *) malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory allocated failed.\n");
        return NULL;
    }
    for (p = a; p < a + n; p++)
        *p = initial_value;
    return a;*/

    //实现方法二：
    if (n <= 0)
        return NULL;
    int *ptrToArray = (int *) malloc(n * sizeof(int));
    if (ptrToArray != NULL)
        for (int i = 0; i < n; i++)
            ptrToArray[i] = initial_value;  // Initialize each element of the array to the initial_value
    return ptrToArray;

}


/**
 * 课后练习题06:请修改函数delete_from_list使它使用一个指针变量而不是两个(即cur和prev)。
 * 在 C 语言中，双指针是一个指向另一个指针的指针。 双指针通常用于间接修改指针的值，
 * 或者通过引用将指针传递给函数，以便函数可以修改原始指针。
 * @param head
 * @param value
 */
struct Node *delete_from_list(struct Node **list, int value) {
    struct Node *item = *list;
    while (item) {
        if (item->data == value) {
            *list = item->next;
            free(item);
            break;
        }
        list = &item->next;
        item = item->next;
    }
    return *list;

}

// Function to print the linked list
void print_list(struct Node *head) {
    struct Node *current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}


/**
 * 指向指针的指针实际运用
 * @param list
 * @param n
 */
void add_to_list(struct Node **list, int n) {
    struct Node *new_node;
    new_node = (struct Node *) malloc(sizeof(struct Node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list.\n");
        exit(EXIT_FAILURE);
    }
    new_node->data = n;
    new_node->next = *list;//list赋予来first的地址，那么可以使用*list作为first的别名。特别是把new_node赋值给*list会修改first的内容。
    *list = new_node;
}

/**
 * 课后练习题07:下列循环希望删除链表中的全部结点，并且释放它们占用的内存。但是，此循环有错误。请解释错误是什么并且
 * 说明如何修改错误。
 * for(p = first, p!=NULL;p=p->next)
 *     free(p);  //只会释放最后一个结点占用的内存空间，其余结点的内存空间不释放
 * @param list
 */
void delete_all_list(struct Node **list) {
//    for (p = list; p != NULL; p = p->next)
//        free(p);
    //这样的写法无法实现,还是要借助双指针间接修改原指针的值,使用指针追踪法
//    struct Node *next_node;
//    while (list != NULL) {
//        next_node = list->next; //借助临时的变量
//        free(list);
//        list = next_node;
//    }
     struct Node *current = *list;
     struct Node *next;
    while (current!=NULL){
        next = current->next; // Save the next node
        free(current);// Free the current node
        current=next;// Move to the next node
    }
    *list =NULL;// Set the head pointer to NULL to indicate an empty list

}



