/**
Created by mason on 2023/6/24
第九章课后编程练习题：
 */
#include<stdio.h>

#define MAX_SIZE 100

void selection_sort(int a[], int n);

//int main(void) {
//    //课后练习题目01:
//    int i, c, n, temp[MAX_SIZE];
//    printf("Enter list of integers to be sorted: ");
//    for (i = 0, n = 0; i < MAX_SIZE; i++) {
//        scanf(" %d", &temp[i]);
//        n++;
//        if ((c = getchar()) == '\n')
//            break;
//        ungetc(c, stdin);
//        /*
//         * C 库函数 int ungetc(int char, FILE *stream) 把字符 char（一个无符号字符）推入到指定的流 stream 中，以便它是下一个被读取到的字符。声明
//            下面是 ungetc() 函数的声明。
//            int ungetc(int char, FILE *stream)
//            参数
//            char -- 这是要被推入的字符。该字符以其对应的 int 值进行传递。
//            stream -- 这是指向 FILE 对象的指针，该 FILE 对象标识了输入流。
//            返回值
//            如果成功，则返回被推入的字符，否则返回 EOF，且流 stream 保持不变。*/
//    }
//    selection_sort(temp, n);
//
//    printf("Sort list: ");
//    for (i = 0; i < n; i++) {
//        printf(" %d", temp[i]);
//    }
//    printf("\n");
//
//    return 0;
//}

/**
 * 课后编程练习题01:
 * 编写程序，要求用户输入一串整数(把这串整数存储在数组中)，然后通过调用selection_sort函数来排序这些整数。
 * 在给定n个元素的数组后，selection_sort函数必须做下列工作：
 * a.搜索数组找出最大的元素，然后把它移到数组的最后；
 * b.递归地调用函数本身来对前n-1个数组元素进行排序。
 * @param a
 * @param n
 * @return
 */
void selection_sort(int a[], int n) {
    // a.搜索数组找出最大的元素，然后把它移到数组的最后；
    //b.递归地调用函数本身来对前n-1个数组元素进行排序
    if (n == 0) return;
    int i, temp, largest = 0;
    for (i = 0; i < n; i++) {
        if (a[i] > a[largest])
            largest = i;
    }
    temp = a[largest];
    a[largest] = a[n - 1];
    a[n - 1] = temp;
    selection_sort(a, n - 1);
}