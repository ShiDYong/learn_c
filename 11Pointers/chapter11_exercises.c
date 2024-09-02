/**
Created by mason on 2023/7/2
第11章:指针课后练习题
 指针是C语言最重要-也是经常被误解的特性之一。由于指针的重要性，本书将用3章的篇幅进行讨论。
 本章侧重于基础知识。
 */
#include<stdio.h>
#include<limits.h>
#include<stdbool.h>
#include<assert.h>

#define N 5
#define INVALID_INPUT -1

void swap(int *p, int *q);

void split_time(long total_sec, int *hr, int *min, int *sec);

void find_two_largest(const int a[], int n, int *larges, int *second_largest);

void find_two_largest02(int a[], int n, int *larges, int *second_largest);

int split_date(int day_of_year, int year, int *month, int *day);

void exec_01_02();

int *find_larges(int a[], int n);

void test_find_largest();


/*int main() {
    *//*
     * 测试查找数组第一和第二大值测试用例：
     * 1.正常情况：
        测试包含多个不同值的数组。
        测试包含重复值的数组。
        2.边界情况：
        测试空数组。
        测试只含一个元素的数组。
        测试所有元素相同的数组。
        3.特殊情况：
        测试包含负数的数组。
        测试包含极大或极小值的数组。
     *//*
    // Test case 1: Normal array with different values
    int arr1[] = {3, 5, 1, 6, 8, 7, 4, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int largest1, second_largest1;
    find_two_largest(arr1, n1, &largest1, &second_largest1);
    printf("Test Case 1 - Largest: %d, Second Largest: %d\n", largest1, second_largest1);

    // Test case 2: Array with all elements the same
    int arr2[] = {5, 5, 5, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int largest2, second_largest2;
    find_two_largest(arr2, n2, &largest2, &second_largest2);
    printf("Test Case 2 - Largest: %d, Second Largest: %d\n", largest2, second_largest2);

    // Test case 3: Empty array
    int arr3[] = {};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int largest3, second_largest3;
    find_two_largest(arr3, n3, &largest3, &second_largest3);
    printf("Test Case 3 - Largest: %d, Second Largest: %d\n", largest3, second_largest3);

    // Test case 4: Array with one element
    int arr4[] = {10};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int largest4, second_largest4;
    find_two_largest(arr4, n4, &largest4, &second_largest4);
    printf("Test Case 4 - Largest: %d, Second Largest: %d\n", largest4, second_largest4);

    // Test case 5: Array with negative values
    int arr5[] = {-3, -5, -1, -6, -8, -7, -4, -2};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int largest5, second_largest5;
    find_two_largest(arr5, n5, &largest5, &second_largest5);
    printf("Test Case 5 - Largest: %d, Second Largest: %d\n", largest5, second_largest5);

    // Test case 6: Array with very large and very small values
    int arr6[] = {INT_MAX, 1000, INT_MIN, 2000};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    int largest6, second_largest6;
    find_two_largest(arr6, n6, &largest6, &second_largest6);
    printf("Test Case 6 - Largest: %d, Second Largest: %d\n", largest6, second_largest6);
    printf("######################################################################################################");

    int day_of_year = 256;
    int year = 2024;
    int month, day;

    //用于输出一个至少两位数的十进制整数。如果整数不足两位，则在前面补零。
    // 这里的02表示最小宽度为2，不足部分用0填充。第一个%02d对应第二个参数month，第二个%02d对应第三个参数day
    if (split_date(day_of_year, year, &month, &day) == 0) {
        printf("Date: %d-%02d-%02d\n", year, month, day);
    } else {
        printf("Failed to split date due to invalid input.\n");
    }
    printf("####################################查找数组最大值#########################################");
    test_find_largest();



    return 0;
}*/


/*
 * 课后练习题01-02
 */
void exec_01_02() {

    /*
     * Exercise 11.01
    If `i` is a variable and `p` points to `i`, which of the following expressions
    are aliases for `i`?
    (a) `*p`        (c) `*&p`       (e) `*i`        (g) `*&i`
    (b) `&p`        (d) `&*p`       (f) `&i`        (h) `&*i`
     */

    int i = 42; //局部变量通常运行时加载在栈中
    int *p = &i;
/* 结合汇编语言会更好理解
 * # 初始化变量 i 和指针 p
    movl $42, -4(%rbp)         # 将立即数（immediate value）42移动到基指针寄存器 %rbp 的地址减去4字节的位置。在x86-64架构中，%rbp 通常用于指向当前栈帧的底部
                               # 在X86-64位中栈向低地址方向增长，所以压栈是减小栈指针(寄存器%rsp)的值，并将数据存到内存中，而出栈是从内存中读取数据并增加栈指针的值
                               #-4(%rbp) 表示从 %rbp 的地址开始，向上数4个字节的位置。这里，movl 指令用于移动32位长的数据，并将42存储在这个位置。
                               #这个位置通常被看作是局部变量 i 的存储位置
    leaq -4(%rbp), %rax        # 获取 i 的地址，注意：-4(%rbp) 是 i 的完整地址，而不是它的“第一个字节”。在处理这种类型的数据时，我们通常不会单独操作一个字节，而是操作整个数据类型所占用的内存空间
                               #rax 这条指令的目的是获取 i 的地址，并将这个地址加载到 %rax 寄存器中。这里的 -4(%rbp) 表示相对于 %rbp 的偏移量，
                               #它并不是直接获取 -4(%rbp) 地址上的值，而是计算这个地址的值，并将这个地址本身加载到 %rax 中，lea 指令（Load Effective Address）用于计算一个内存地址并将其加载到寄存器中。
                               #当使用 lea 指令时，它计算的是内存偏移量，而不是内存中存储的值。
    movq %rax, -8(%rbp)        # movq 指令用于移动64位长的数据。这条指令将 %rax 寄存器的内容（即 i 的地址）移动到 %rbp 地址减去8字节的位置。这个位置通常被看作是局部变量 p 的存储位置。
                               #p 现在存储了 i 的地址，意味着 p 是指向 i 的指针
   （a）*p 解引用指针 p，也就是访问指针 p 所指向的变量。因此，*p 是变量 i 的别名
     表达式*p的汇编语言：
     movq -8(%rbp), %rax        # 这条指令将 %rbp 地址减去8字节的位置处的值移动到 %rax 寄存器，从上面可知：这个位置存储的是指针 p 的值，即变量 i 的地址
     movl (%rax), %eax          #  首先，%rax 寄存器中的值（p 的值）被用作内存地址，然后，movl 指令将该地址处的32位数据（i 的值）加载到 %eax 寄存器中
     (b)表达式 (b) &p汇编语言：
     leaq -8(%rbp), %rax        # 获取 p 的地址
     表达式 (c) *&p：*&p 先获取 p 的地址，然后解引用 p，结果等价于 p
     movq -8(%rbp), %rax        # 获取 p 的值（即 i 的地址）
     表达式 (d) &*p：&*p 解引用 p，然后获取解引用结果的地址，即 i 的地址
     movq -8(%rbp), %rax        # 获取 p 的值（即 i 的地址）
     表达式 (e) *i：这是非法操作，因为 i 是整数而不是指针。不会生成汇编代码
     表达式 (f) &i：&i 获取 i 的地址
     leaq -4(%rbp), %rax        # 获取 i 的地址
     表达式 (g) *&i：*&i 先获取 i 的地址，然后解引用，结果是 i 的值
     movl -4(%rbp), %eax        # 获取 i 的值
     表达式 (h) &*i：这是非法操作，因为 i 是整数而不是指针。不会生成汇编代码
*/



    /*课后练习题02:
     If `i` is an `int` variable and `p` and `q` are pointers to `int`, which of the
    following assignments are legal?
    (a) `p = i;`    (d) `p = &q;`   (g) `p = *q;`
    (b) `*p = &i;`  (e) `p = *&q;`  (h) `*p = q;`
    (c) `&p = q;`   (f) `p = q;`    (i) `*p = *q;`
     * */
    /*
      int i;
      int *p;
      int *q;
     (a) p = i;
     分析: i 是 int 类型，而 p 是 int* 类型。这种赋值是不合法的，因为无法将一个整型值赋给指针变量。
     结论: 非法。
     (b) *p = &i;
     分析: *p 解引用指针 p，它期望一个 int 类型的值，而 &i 是 int*（即指向 int 的指针）。这也是不合法的，因为 int* 类型不能赋给 int 类型。
     结论: 非法。
     (c) &p = q;
     分析: &p 是 p 的地址，它是 int** 类型的临时值，不能作为赋值的左值。因此这种赋值是非法的。
     结论: 非法。
     (d) p = &q;
     分析: &q 是指向 q 的指针，它的类型是 int**，而 p 是 int* 类型。这种赋值是不合法的，因为 int** 类型不能赋给 int* 类型。
     结论: 非法。
     (e) p = *&q;
     分析: *&q 先获取 q 的地址，然后解引用，最终结果是 q 的值，也就是 int* 类型。由于 p 也是 int* 类型，因此这种赋值是合法的。
     结论: 合法。
     (f) p = q;
     分析: p 和 q 都是 int* 类型，因此这种赋值是合法的。
     结论: 合法。
     (g) p = *q;
     分析: *q 解引用指针 q，得到的是 int 类型的值，而 p 是 int* 类型。这种赋值是不合法的，因为 int 类型不能赋给 int* 类型。
     结论: 非法。
     (h) *p = q;
     分析: *p 解引用 p，期望一个 int 类型的值，而 q 是 int* 类型。这种赋值是不合法的，因为 int* 类型不能赋给 int 类型。
     结论: 非法。
     (i) *p = *q;
     分析: *p 和 *q 分别解引用 p 和 q，它们都是 int 类型。因此这种赋值是合法的
     结论: 合法
     */

}


/**
 * Exercise 11.03
The following function supposedly computes the sum and average of the numbers in
the array `a`, which has length `n`. `avg` and `sum` point to variables that the
function should modify. Unfortunately, the function contains several errors;
find and correct them.
 c
 void avg_sum(double a[], int n, double *avg, double *sum)
{
    int i;

    sum = 0.0;
    for (i = 0; i < n; i++)
        sum += a[i];
    avg = sum / n;
}
 */

void avg_sum(double a[], int n, double *avg, double *sum) {
    //错误 1: sum = 0.0;
    //问题: sum 是一个指向 double 类型的指针，而 sum = 0.0; 试图将一个 double 值赋给一个指针。这是非法的。
    //修复: 需要解引用指针 sum，并将 0.0 赋值给它指向的内存地址。修复后的代码为 *sum = 0.0;

    //错误 2: avg = sum / n;
    //问题: 同样，avg 是一个指向 double 类型的指针，而 avg = sum / n; 试图将计算结果直接赋给指针 avg。这也是非法的。
    //修复: 需要解引用指针 avg，并将计算结果赋值给它指向的内存地址。修复后的代码为 *avg = *sum / n;。注意，sum 也需要解引用以获取它指向的值
    int i;
    *sum = 0.0;
    for (i = 0; i < n; i++)
        *sum += a[i];
    if (n != 0) *avg = *sum / n;
    else *avg = 0;
}


/**
 *
 Exercise 11.04
Write the following function:
```c
void swap(int *p, int *q);
When passed the addresses of two variables, `swap` should exchange the values of
the variables:
```c
swap(&i, &j);    exchanges values of i and j
 * @param p
 * @param q
 */
void swap(int *p, int *q) {
    int temp = *p;
    *p = *q;
    *q = temp;
}

/**
Exercise 11.05
Write the following function
```c
void split_time(long total_sec, int *hr, int *min, int *sec);
```
`total_sec` is a time represented as the number of seconds since midnight. `hr`,
`min` and `sec` are pointers to variables in which the function will store the
equivalent time in hours (0-23), minutes (0-59) and seconds (0-59),
respectively.
 */
void split_time(long total_sec, int *hr, int *min, int *sec) {

    *hr = total_sec / 3600; // 直接计算总小时数（包括超过24小时的部分）
    *min = (total_sec % 3600) / 60;  // 计算分钟数，每小时有 3600 秒，因此 total_sec % 3600 可以得到在过去的整小时之外还剩下多少秒
    *sec = total_sec % 60;// 计算剩余秒数

    /*
     如果需要一天内的小时表示(0~23):
     long days = total_sec / 86400; // 每天有86400秒
    *hr = (total_sec / 3600) % 24;  // 计算小时数，并确保在0-23范围内
    *min = (total_sec % 3600) / 60;  // 计算分钟数
    *sec = total_sec % 60;           // 计算剩余秒数

    if (days > 0) {
        *hr += days * 24; // 如果超过一天，将天数转化为小时数加在 *hr 上
    }
     */

}


/**
  Exercise 11.06
Write the following function:
c
void find_two_largest(int a[], int n, int *largest, int *second_largest);

When passed an array `a` of length `n`, the function will search `a` for its
largest and second-largest elements, storing them in the variables pointed to by
`largest` and `second-largest` respectively.
 */
void find_two_largest(const int a[], int n, int *largest, int *second_largest) {
    int i;
    if (n <= 1) {
        //1.在数组中只有一个元素的情况下，不能找到两个不同的值。应该在函数开始时检查这种情况并处理
        *largest = *second_largest = INT_MIN; // 设置为最小值
        return;
    }
    /**
     2.下面方法存在的弊端是方法假设数组中至少有两个元素，并且所有元素都大于 a[0]。如果数组中所有元素都相同，
     这种初始化会导致 second_largest 仍然等于 largest，从而不符合要求
     largest = *second_largest = a[0]; //初始化为最小值
    for (i = 1; i < n; i++) {
        if (a[i] > *largest) {
            *second_largest = *largest; //更新为第二大值
            *largest = a[i]; //更新为最大值
        }
        //为什么需要下面的处理：如果数组中出现了与最大值相等的元素，这个元素不应该被认为是第二大值。a[i] != *largest 确保只有严格小于当前最大值的元素才能被认为是第二大值。
        // 避免重复: 如果数组中有多个相同的最大值（例如 [3, 3, 3, 2]），这段代码确保只有最大值以外的值可以成为第二大值
        else if (a[i] > *second_largest && a[i] != *largest) {
            *second_largest = a[i]; //更新第二大值
        }
    }*/

    //初始化 *largest 和 *second_largest 为 INT_MIN。这样可以确保在所有情况下都能正确处理边界条件
    *largest = *second_largest = INT_MIN;//初始化最小值
    for (i = 0; i < n; i++) {
        if (a[i] > *largest) {
            *second_largest = *largest; //更新第二大值
            *largest = a[i]; //更新最大值
        } else if (a[i] > *second_largest && a[i] != *largest) {
            *second_largest = a[i]; //更新第二大值
        }
    }
    // 2.在找不到第二大值的情况下（即 *second_largest 仍然为 INT_MIN），通过打印消息进行提示
    //即处理所有元素相同的情况
    if (*second_largest == INT_MIN) {
        printf("No distinct second largest value found.\n");

    }

}


void find_two_largest02(int a[], int n, int *largest, int *second_largest) {
    if (n < 2) {
        *largest = *second_largest = a[0];
        return;
    }
//    *largest = a[0];
//    int i;
//    for (i = 0; i < n; i++)
//        if (*largest < a[i]) *largest = a[i];
//    if (*largest != a[0]) *second_largest = a[0];
//    else *second_largest = a[1];
//    for (i = 0; i < n; i++)
//        if (*largest != a[i] && *second_largest < a[i]) *second_largest = a[i];
    //初始化
    //对数组进行初步判断并初始化最大值和第二大值
    if (a[0] > a[1]) {
        *largest = a[0];
        *second_largest = a[1];
    } else {
        *largest = a[1];
        *second_largest = a[0];
    }
    int i;
    //遍历数组
    for (i = 2; i < n; ++i) {
        if (a[i] > *largest) {
            *second_largest = *largest;
            *largest = a[i];
        } else if (*largest != a[i] && a[i] > *second_largest) {
            *second_largest = a[i];
        }
    }

}

/**
Exercise 11.07
Write the following function:
```c
void split_date(int day_of_year, int year, int *month, int *day);
`day_of_year` is an integer between 1 and 366, specifying a particular day
within the year designated by `year`. `month` and `day` point to variables in
which the function will store the equivalent month (1-12) and day within that
month (1-31).
 */
//年份能被 4 整除并且不能被 100 整除，或者年份能被 400 整除，则该年为闰年
bool is_leap_year(int year) {
    return (year % 4 && year % 100 != 0) || (year % 400 == 0);
}

//需要根据给定的年份和一年中的某一天（day_of_year），将其拆分为对应的月份和日期。我们需要考虑闰年和平年，因为不同的年份可能有不同的天数
int split_date(int day_of_year, int year, int *month, int *day) {
    //参数检查
    if (year < 1) {
        printf("Error: Invalid year value.\n");
        return INVALID_INPUT;
    }
    //判断天数
    int max_days = is_leap_year(year) ? 366 : 365;
    if (day_of_year < 1 || day_of_year > max_days) {
        printf("Error: day_of_year out of valid range (1-%d).\n", max_days);
        return INVALID_INPUT;
    }

    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //如果是闰年，2月份是29天
    if (is_leap_year(year)) days_in_month[1] = 29;
    *month = 1;
    while (day_of_year > days_in_month[*month - 1]) {
        day_of_year -= days_in_month[*month - 1];
        (*month)++;

    }
    *day = day_of_year;
    return 0;//正常执行返回0

}


void split_date01(int day_of_year, int year, int *month, int *day) {
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
int *find_largest(int a[], int n) {
    /* int i, max = a[0];
     int *p = &max;
     for (i = 0; i < n; i++) {
         if (a[i] > *p)
             *p = a[i];

     }
     return p;*/
    if (n <= 0) {
        return NULL;
    }
    //仔细比较这两种方式的不同点
    int i, *largest = &a[0]; // Initialize largest as the first element
    for (i = 1; i < n; i++) {
        if (a[i] > *largest)
            largest = &a[i];
    }
    return largest;


}

void test_find_largest() {
    // Test case 1: Normal array
    int arr1[] = {3, 5, 1, 6, 8, 7, 4, 2};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int *largest1 = find_largest(arr1, n1);
    assert(largest1 != NULL && *largest1 == 8);

    // Test case 2: All elements are the same
    int arr2[] = {5, 5, 5, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    int *largest2 = find_largest(arr2, n2);
    assert(largest2 != NULL && *largest2 == 5);

    // Test case 3: Array with negative numbers
    int arr3[] = {-3, -5, -1, -6, -8, -7, -4, -2};
    int n3 = sizeof(arr3) / sizeof(arr3[0]);
    int *largest3 = find_largest(arr3, n3);
    assert(largest3 != NULL && *largest3 == -1);

    // Test case 4: Single element array
    int arr4[] = {10};
    int n4 = sizeof(arr4) / sizeof(arr4[0]);
    int *largest4 = find_largest(arr4, n4);
    assert(largest4 != NULL && *largest4 == 10);

    // Test case 5: Empty array
    int arr5[] = {};
    int n5 = sizeof(arr5) / sizeof(arr5[0]);
    int *largest5 = find_largest(arr5, n5);
    assert(largest5 == NULL);

    // Test case 6: Array with very large and very small values
    int arr6[] = {INT_MAX, 1000, INT_MIN, 2000};
    int n6 = sizeof(arr6) / sizeof(arr6[0]);
    int *largest6 = find_largest(arr6, n6);
    assert(largest6 != NULL && *largest6 == INT_MAX);

    printf("All tests passed successfully.\n");
}