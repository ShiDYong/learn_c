/********************************************************************************
* @author: mason shi
* @date: 2024/6/24 21:55
* @version: 1.0
* @description: 数组的反方向输出，数组的反转功能
********************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX_SIZE 100 //定义数组的最大大小


/*
 * 1.用户输入一串数，安反方向顺序输出
 * 在C语言中，函数不能直接接受数组作为参数，而是通过指向数组首元素的指针来实现。
 * 不过，我们可以通过声明数组参数并在函数实现时使用指针的方式来处理数组
 *
 */
void reverse_direction_output(int array[], int size) {
    int i;
    for (i = size - 1; i >= 0; i--)
        printf("%d ", array[i]);
}

/*
 * 逆序数组数组函数,主要针对整形
 * 内联交换：reverseArray函数通过内联交换元素实现逆序，
 * 减少了不必要的函数调用和内存操作
 */
void reverse_array(int array[], int size) {
    for (int start = 0, end = size - 1; start < end; start++, end--) {
        int tmp = array[start];
        array[start] = array[end];
        array[end] = tmp;
    }
}

/*
 * 打印逆序数组的函数
 */
void print_array(const int array[], int size) {
    printf("Reverse array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);

    }
    printf("\n");
}

/*
 * 通用工具函数实现
   创建一个通用的反转数组函数：这个函数可以处理任何类型的数组。
   使用指针操作：使得函数可以处理任何数据类型，而不仅仅是整型数组。
   高效的内存操作：通过指针操作减少不必要的内存拷贝
   在C语言中，void* 是一种非常重要的指针类型，具有以下特征和适用场景：
   特征
   通用指针：void* 是一种通用指针类型，可以指向任意类型的数据，但不能直接进行解引用或指针运算。
   无类型指针：
   因为 void* 没有具体类型，所以不能直接使用 *ptr 解引用，也不能直接进行算术运算（例如 ptr + 1）
   需要类型转换：
   使用 void* 指针时，通常需要将其转换为具体类型的指针，然后才能进行解引用或其他操作。
   标准库函数的参数类型：
   许多标准库函数使用 void* 作为参数类型，以实现对任意类型数据的操作。例如 malloc 和 memcpy
   适用场景：
   1.动态内存分配：
   动态内存分配函数如 malloc 和 calloc 返回 void* 类型的指针，因为它们不知道分配的内存将用于存储何种类型的数据
   int *arr = (int *)malloc(10 * sizeof(int));
   2.通用数据结构：需要处理不同类型数据的通用数据结构（如链表、堆栈和队列）通常使用 void* 来实现
   typedef struct Node {
    void *data;
    struct Node *next;
    } Node;
    3.通用接口函数：一些需要处理不同类型数据的通用函数（如排序函数和比较函数）使用 void* 来实现。
     int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
 }


 */
void swap(void *a, void *b, size_t size) {
    //分配一个临时内存块用于存储交换的元素
    void *temp = malloc(size);
    if (temp == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }
    //将第一个元素的数据复制到临时内存块
    memcpy(temp, a, size);
    //将第二个元素的数据复制到第一个元素的位置
    memcpy(a, b, size);
    //将临时内存块中的数据复制到第二个元素的位置
    memcpy(b, temp, size);
    //释放临时内存块
    free(temp);

}

/**
 * 通用的翻转数组函数
 * @param array指向数组首元素的指针
 * @param items 数组的元素个数
 * @param size 每个元素的大小，以字节为单位
 * 反转数组的基本原理
   假设我们有一个数组 arr，它包含 n 个元素。反转数组的目标是将第一个元素与最后一个元素交换，
   第二个元素与倒数第二个元素交换，依此类推，直到整个数组被反转
   交换对称位置的逻辑
   对称位置：对于一个数组 arr，如果我们用 i 表示第一个元素的索引，用 n-1-i 表示对称位置的索引。
    遍历一半：我们只需要遍历数组的一半，因为每次交换两个元素都会使得两个元素到达它们最终的位置。
    遍历到数组的一半时，所有元素都已经被交换到它们的最终位置
    好处：
    这种方法的优点是高效且简单，因为只需要遍历数组的一半，减少了不必要的元素交换操作。
    每次交换两个元素后，这两个元素都会到达它们的最终位置
 */
void reverseArray(void *array, size_t items, size_t size) {
    //将void *类型的指针转换为char *类型，以便进行指针运算
    char *ptr = array;
    //遍历数组的一半，交换对称位置的元素
    for (size_t i = 0; i < items / 2; ++i) {
        //我们交换第i个元素和第items-1-i个元素的位置
        swap(ptr + i * size, ptr + (items - 1 - i) * size, size);
    }
}
// 打印整型数组的函数
void printIntArray(int *array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// 打印浮点型数组的函数
void printFloatArray(float *array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%.1f ", array[i]);
    }
    printf("\n");
}

// 打印字符数组的函数
void printCharArray(char *array, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        printf("%c ", array[i]);
    }
    printf("\n");
}
//int main(void) {
//    int array[MAX_SIZE];
//    int size, i;
//    //提示用户输入数组的大小
//    // 提示用户输入数组的大小
//    printf("Enter the number of elements in the array (max %d): ", MAX_SIZE);
//    if (scanf("%d", &size) != 1 || size <= 0 || size > MAX_SIZE) {
//        printf("Invalid size!\n");
//        return 1;
//    }
//
//    //提示用户输入数组的元素
//    printf("Enter %d integers: ", size);
//    for (i = 0; i < size; i++) {
//        while (scanf("%d", &array[i]) != 1) {
//            printf("Invalid input! Please enter an integer: ");
//            //清除输入缓冲区中的无效输入
//            while (getchar() != '\n');
//        }
//    }
//    //调用反向打印数组方法
//    printf("Array in reverse order: ");
//    reverse_direction_output(array, size);
//    printf("\n");
//    //逆序数组
//    reverse_array(array, size);
//    //打印逆序后的数组
//    print_array(array, size);
//
//    // 反转整型数组
//    int intArray[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
//    /*
//     * size_t 是 C 语言标准库中定义的一种类型，通常用于表示内存大小或数组索引等非负整数。它是一个无符号整数类型，定义在 <stddef.h> 头文件中。下面是详细分析：
//       size_t 的定义和特点
//       无符号类型：
//       size_t 是一个无符号整数类型，这意味着它只能表示非负整数。这非常适合用于表示大小、长度和索引等永远不会为负的数值。
//       与平台相关：
//       size_t 的具体大小和范围是与平台相关的。通常在32位系统上，size_t 是32位无符号整数（unsigned int）；在64位系统上，size_t 是64位无符号整数（unsigned long long）。
//       用于表示对象的大小：
//       size_t 常用于标准库函数中，如malloc、calloc、sizeof，以及表示数组的大小或长度。它能够确保在不同平台上的兼容性和正确性。
//       适用场景
//       内存分配和数组大小：
//       在动态内存分配时使用size_t确保能够正确地表示和处理内存块的大小。
//       在计算数组的长度、索引或偏移量时使用size_t，避免负数索引带来的错误。
//       标准库函数：
//       大量标准库函数使用size_t作为参数和返回类型，如strlen、malloc、memcpy等，遵循这一规范有助于保持一致性和兼容性。
//     */
//    size_t intSize = sizeof(intArray) / sizeof(intArray[0]);
//
//    printf("Original int array: ");
//    printIntArray(intArray, intSize);
//
//    reverseArray(intArray, intSize, sizeof(intArray[0]));
//
//    printf("Reversed int array: ");
//    printIntArray(intArray, intSize);
//
//    // 反转浮点型数组
//    float floatArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
//    size_t floatSize = sizeof(floatArray) / sizeof(floatArray[0]);
//
//    printf("Original float array: ");
//    printFloatArray(floatArray, floatSize);
//
//    reverseArray(floatArray, floatSize, sizeof(floatArray[0]));
//
//    printf("Reversed float array: ");
//    printFloatArray(floatArray, floatSize);
//
//    // 反转字符数组
//    char charArray[] = {'a', 'b', 'c', 'd', 'e'};
//    size_t charSize = sizeof(charArray) / sizeof(charArray[0]);
//
//    printf("Original char array: ");
//    printCharArray(charArray, charSize);
//
//    reverseArray(charArray, charSize, sizeof(charArray[0]));
//
//    printf("Reversed char array: ");
//    printCharArray(charArray, charSize);
//
//
//    return 0;
//
//}

