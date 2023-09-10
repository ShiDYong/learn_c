/********************************************************************************
* @author: mason shi
* @date: 2023/8/27 15:56
* @version: 1.0
* @description: 补充指示，之前学习有用到指针和函数相关知识，但是是比较零散地，这里系统介绍指针
 * 和函数结合使用。
********************************************************************************/
#include<stdlib.h>
#include<stdio.h>

void program_stack_and_heap();

void swapWithPointers(int *num1, int *num2);

void swap(int n1, int n2);

void passAddressOfConstants(const int *num1, int *num2);

int *allocateArray(int size, int value);

void modifyPointer(int **ptrPtr);

int main(void) {
    //通过指针传递
//    int n1 = 5;
//    int n2 = 10;
    // swapWithPointers(&n1,&n2);
//    printf("n1交换的值是：%d\n",n1);
//    printf("n2交换的值是：%d\n",n2);
    //n1交换的值是：10
    //n2交换的值是：5
    //指针num1和指针num2在交换中被解引，结果是修改来n1和n1的值
    //下面是使用值传递打印是否实现交换
//    swap(n1,n2);
//    printf("main函数n1交换的值是：%d\n",n1);
//    printf("main函数n2交换的值是：%d\n",n2);

    //3.演示传递指向常量的指针
//    const int limit = 100;
//    int result = 5;
//    passAddressOfConstants(&limit, &result);
//    printf("main函数limit的值是：%d\n", limit);
//    printf("main函数result的值是：%d\n", result);

    //4.返回指针
//    int *vector = allocateArray(5, 45);
//    for (int i = 0; i < 5; i++)
//        printf("%d\n", vector[i]);
//    //释放内存
//    free(vector);

    //5.传递指针的指针
    int *myPtr = NULL; // Declare a pointer to an integer and initialize it to NULL.

    modifyPointer(&myPtr); // Pass a pointer to the pointer.

    if (myPtr != NULL) {
        printf("Value: %d\n", *myPtr); // Output: Value: 42
        free(myPtr); // Remember to free the allocated memory when done using it.
    }


}


/**
 * 深入理解C指针第三章3.1:程序的堆和栈
 * 程序的堆和栈是C重要的运行时元素，下面主要介绍程序栈和堆的结构以及用法，以及看下栈帧的结构，它用于保存局部变量
 */
void program_stack_and_heap() {

}

/*
 * 用指针传递数据：用指针来传递一个数据的一个主要原因是函数可以修改数据
 * 下面的函数实现了一个交换函数，可以交换其参数所引用的值。我们这里在这里用整数
 * 指针，通过解引用它们来实现交换.
 * */
void swapWithPointers(int *num1, int *num2) {
    int tmp;
    tmp = *num1;
    *num1 = *num2;
    *num2 = tmp;

}

/**
 * 用值传递数据，演示不通过指针传递参数，交换值就不会发生。
 * @param n1
 * @param n2
 */
void swap(int num1, int num2) {
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
    printf("swap函数内的n1交换的值是：%d\n", num1);
    printf("swap函数内的n2交换的值是：%d\n", num2);
    /*这样并没有实现真正的交换，因为整数是通过值而不是指针来传递的。num1和num2中保存的只是实际参数的副本。
     * 修改num1,实参n1不会发生变化。修改形参不会影响实参。
     * */

}


/**
 *3.2.3:传递指向常量的指针：
 * 传递指向常量的指针是C中常用的技术，效率很高，因为我们只传递来数据地址，能避免某些情况下复制大量内存。
 * 不过，如果只是传递指针，数据就能被修改。如果不希望数据被修改，就要传递指向常量的指针。
 * @param num1
 * @param num2
 */
void passAddressOfConstants(const int *num1, int *num2) {
    // *num2 = *num1; //不会产生语法错误，函数会把100赋给result变量
    //下面试图修改两个被引用的整数
    // *num1 = 100; 产生语法错误
    *num2 = 200;
}


/**
 * 3.2.4:返回指针
 * 返回指针很容易，只要返回的类型是某种数据类型的指针即可。从函数返回对象经常用到以下两种技术：
 * 1.使用malloc在函数内部分配内存并返回其地址。调用者负责释放返回的内存；
 * 2.传递一个对象给函数并让函数修改它。这样分配和释放对象的内存都是调用者的责任。
 * 这里推荐第一种方式，不推荐第二种
 * @param size
 * @param value
 * @return 返回数组地址.
 */
int *allocateArray(int size, int value) {
    //以下是使用数组动态分配内存
//    int *arr = (int *) malloc(size * sizeof(int));
    //    if(arr == NULL)
//         return ;
//    for (int i = 0; i < size; i++) {
//        arr[i] = value;
//    }
//    return arr; //

    /*局部数据的错误,使用局部数组*/
    int arr[size];
    for (int i = 0; i < size; i++) {
        arr[i] = value;

    }
    return arr;  /*这种写法一旦函数返回，返回的数组地址也就无效了，因为函数的栈帧从栈中弹出了，尽管每个数组元素仍然可能包含45
                 但如果调用另一个函数，就可能覆写这些值。*/
}

/**
 * 传递指针的指针：将指针传递给函数时，传递的是值。如果我们想修改愿指针而不是指针的副本，是需要传递指针的指针。
 * @param ptrPtr
 */
void modifyPointer(int **ptrPtr) {
    // Allocate memory for an integer and store its address in the pointer pointed to by ptrPtr.
    *ptrPtr = (int *) malloc(sizeof(int));
    if (*ptrPtr != NULL) {
        **ptrPtr = 42; // Set the value of the allocated integer.
    }
}


