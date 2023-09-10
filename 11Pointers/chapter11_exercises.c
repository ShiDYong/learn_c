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

int *find_larges(int a[], int n);

//int main() {
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
//    return 0;
//}

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
    *hr = total_sec / 3600;
    total_sec -= *hr * 3600;
    *min = total_sec / 60;
    total_sec -= *min * 60;
    *sec = total_sec;
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