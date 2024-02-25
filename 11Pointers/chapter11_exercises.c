/**
Created by mason on 2023/7/2
第11章:指针课后练习题
 指针是C语言最重要-也是经常被误解的特性之一。由于指针的重要性，本书将用3章的篇幅进行讨论。
 本章侧重于基础知识。
 */
#include<stdio.h>
#include<stdbool.h>

#define N 5

void swap(int *p, int *q);

void split_time(long total_sec, int *hr, int *min, int *sec);

void find_two_largest(int a[], int n, int *larges, int *second_largest);

void split_date(int day_of_year, int year, int *month, int *day);

void exec_01_02();

int *find_larges(int a[], int n);

int main() {
    exec_01_02();
    //课后练习题题目04:
    //    int i = 3, j = 4;
    //    swap(&i, &j);
    //    printf("i = %d\n", i);
    //    printf("j = %d\n", j);
    //课后编程练习题06:
    //    int b[N], k, larges, second_largest;
    //    printf("Enter %d numbers: ", N);
    //    for (k = 0; k < N; k++) {
    //        scanf("%d", &b[k]);
    //    }
    //    find_two_largest(b, N, &larges, &second_largest);
    //    printf("Largest is %d\n", larges);
    //    printf("second_largest is %d\n", second_largest);

    //    printf("Max pointer %d\n", *find_larges(b, N));
    return 0;
}


/*
 * 课后练习题01-02
 */
void exec_01_02() {

    /*课后练习01：如果i是变量，且p指向i，那么下列哪些表达式是i的别名?*/
    int i = 1, *p = &i;
    *p; //表示指针变量p的间接引用，即i

    &p; //表示指针变量p的地址
    printf(" i的内存地址: %p\n", &i); // i的内存地址 0x16d79acdc

    printf(" 指针变量p的值: %p\n", p); // 指针变量p的值 0x16d79acdc

    printf(" 指针变量p的n内存地址: %p\n", &p); // 指针变量p的n内存地址 0x16d79acd0

    *&p; //表示指针变量p取地址后再间接引用，仍表示指针变量p
    printf(" *&p的内存地址: %p\n", *&p);// *&p的内存地址: 0x16da2acdc
    printf(" *&p的值: %d\n", *&p); // *&p的值: 1827106012

    &*p; //表示先对指针变量p间接引用，再取地址，仍表示指针变量p
    printf("  &*p的内存地址: %p\n", &*p);//   &*p的内存地址: 0x16f75acdc
    printf("  &*p的值: %d\n", &*p); //   &*p的值: 1869982940


    //*i; 编译器检查不通过，表示对变量i的间接引用，如果变量i不能保证是指针变量，则该运算存在一定风险

    &i; //表示对变量i取地址，该值等于指针变量p的值
    printf(" i的内存地址: %p\n", &i); // i的内存地址 0x16d79acdc

    *&i; //表示对变量i先取地址，再做间接引用运算，仍表示表示i
    printf(" *&i的内存地址: %d\n", *&i);


    // &*i; 编译器不通过，表示对变量i先做间接运算，再取地址，由于变量i不能保证是指针变量，因此该表达式存在一定风险，不能用来表示表示i.



    /*课后练习题02:
     * 如果i是int类型变量，且p和q是指向int的指针，那么下列哪些赋值是合法的？
     *
     *   p=i;  *p= &i;  &p = q;
     *   p = &q; p = *&p; p =q;
     *   p = *q; *p = q; *p = *q;
     * */
    int j, *ptr, *qtr;

    //综合考虑赋值表达式，其中i表示int类型变量，&i表示int类型变量的地址，*p、*q表示int类型变量，&q,&q表示int类型指针变量的地址。
    //合法表达式如下
    ptr = *&ptr;
    ptr = qtr;
    *ptr = *qtr;
    //其余都是错误的




}


/**
 * 课后练习题04:编写下列函数
 * 当传递两个变量的地址时，swap函数应该交换两个变量的值：
 * swap(&i,&j)//exchange values of i and j;
 * @param p
 * @param q
 */
void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

/**
 * 课后练习题05:编写下列函数
 * total_sec是以午夜开始计算的秒数所表示的时间。hr、min和sec都是指向变量的指针，这些变量在函数中将分别存储以小时(0~23)、分钟
 * (0~59)和秒(0~59)为单位的等价时间.
 * @param total_sec
 * @param hr
 * @param min
 * @param sec
 */
void split_time(long total_sec, int *hr, int *min, int *sec) {
//    *hr = total_sec / 3600;
//    total_sec -= *hr * 3600;
//    *min = total_sec / 60;
//    total_sec -= *min * 60;
//    *sec = total_sec;
    *hr = total_sec / 60 / 60;
    *min = total_sec / 60 - (*hr) * 60;
    *sec = total_sec % 60;


}


/**
 * 课后练习题06:编写下列函数
 * 当传递长度为n的数组a时，函数将在数组a中搜寻最大元素和第二大元素，把它们分别存储在由largest和second_larges指向的变量中
 * @param a
 * @param n
 * @param larges
 * @param second_largest
 */
void find_two_largest(int a[], int n, int *larges, int *second_largest) {
    int i;
    *larges = a[0];
    *second_largest = a[1];
    for (i = 0; i < n; i++) {
        if (a[i] > *larges) {
            *second_largest = *larges;
            *larges = a[i];
        }
        if (a[i] > *second_largest && a[i] != *larges)
            *second_largest = a[i];

    }

}


/**
 * 课后练习题7:编写下列函数：
 * day_of_year是1~366范围内的整数，表示year指定的那一年中的特定一天。month和day是指向变量的指针，相应的变量在函数中分别存储等价的月份
 * (1~12)和改月的日期(1~31)。
 * @param day_of_year
 * @param year
 * @param month
 * @param day
 */

void split_date(int day_of_year, int year, int *month, int *day) {
    int i;
    bool found = false;

    for (i = 1; i <= 12 && !found; i++) {
        switch (i) {
            case 1:
            case 3:
            case 5:
            case 7:
            case 8:
            case 10:
            case 12:
                if (day_of_year <= 31)
                    found = true;
                else
                    day_of_year -= 31;
                break;
            case 4:
            case 6:
            case 9:
            case 11:
                if (day_of_year <= 30)
                    found = true;
                else
                    day_of_year -= 30;
                break;
            case 2:
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                    if (day_of_year <= 29)
                        found = true;
                    else
                        day_of_year -= 29;
                } else {
                    if (day_of_year <= 28)
                        found = true;
                    else
                        day_of_year -= 28;
                }
                break;
        }
    }
    *month = i - 1;
    *day = day_of_year;
}


/**
 * 课后练习题目第八题：编写下列函数
 * 当传入长度为n的数组a时，函数将返回指向数组最大元素的指针。
 * @param a
 * @param n
 * @return
 */
int *find_larges(int a[], int n) {
    /* int i, max = a[0];
     int *p = &max;
     for (i = 0; i < n; i++) {
         if (a[i] > *p)
             *p = a[i];

     }
     return p;*/
    //仔细比较这两种方式的不同点
    int i, *largest = &a[0];
    for (i = 0; i < n; i++) {
        if (a[i] > *largest)
            largest = &a[i];
    }
    return largest;


}