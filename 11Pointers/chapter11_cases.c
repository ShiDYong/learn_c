/**
Created by mason on 2023/7/2
第11章:指针
 指针是C语言最重要-也是经常被误解的特性之一。由于指针的重要性，本书将用3章的篇幅进行讨论。
 本章侧重于基础知识。
 */
#include<stdio.h>

#define N 10

void case01_Pointer_variables();

void case03_pointer_assignment();

void case04_pointer_as_argument();

void decompose(double x, long *int_part, double *frac_part);

void max_min(int a[], int n, int *max, int *min);
int *max(int *a, int *b);

//int main(void) {
//    //case01_Pointer_variables();
//    // case03_pointer_assignment();
//    // case04_pointer_as_argument();
//    //指针作为参数传递的运用案例
//    int b[N], i, big, small;
//    printf("Enter %d number: ", N);
//    for (i = 0; i < N; i++)
//        scanf("%d", &b[i]);
//    max_min(b, N, &big, &small);
//    printf("Largest: %d\n", big);
//    printf("Smallest: %d\n", small);
//
//    //指针作为返回的案例练习;调用max函数时，用指向两个int类型变量的指针作为参数，并且把结果存储在一个指针变量中
//    //
//    int *p,n=23,m=45;
//    p= max(&n,&m);
//    return 0;
//}

/**
 * 11.1节：内存地址及其指针变量的关系：
 *  1.指针变量：
 *      理解指针的第一步是在机器级上观察指针表示的内容。大多数现代计算机将内存分割为字节(byte)，每个字节可以存储8位的信息；
 *      每个字节都有唯一的地址(address)，用来和内存中的其它字节相区别。如果内存中有n个字节，那么可以把地址看作0～n-1的数
 *      可执行程序由代码(原始c程序中与语句对应的机器指令)和数据(原始程序中的变量)两部分构成。程序中的每个变量占有一个或多个字节
 *      内存，把第一个字节的地址称为变量的地址。下图中，变量i地址为2000和2001的两个字节，所以变量i的地址是2000；这就是指针的
 *      出处。虽然用数表示地址，但是地址的取值范围可能不同于整数的范围，所以一定不能用普通整型变量存储地址。但是可以用特殊的指针
 *      变量(pointer variable)存储地址。在用指针变量p存储变量i的地址时，我们说p指向i。换句话说，指针就是地址，而指针变量就是
 *      存储地址的变量。
 */
void case01_Pointer_variables() {
    //1.指针变量的声明：指针变量名字前放置星号；
//    int *p;  //说明p是指向int类型对象的指针变量。C语言要求每个指针变量只能指向一种特定类型(引用类型)的对象,至于引用类型
    //是什么类型则没有限制，事实上，指针变量甚至可以指向另一个指针，即是指向指针的指针。

    /*2.取地址运算符和间接寻址运算符：
     * 为使用指针，C语言提供了一对特殊设计的运算符。为了找到变量的地址，可以使用&(取地址)运算符。如果x是变量，那么&x就是x
     * 在内存中的地址。为了获得对指针所指向对象的访问，可以使用*(间接寻址)运算符。如果p是指针，那么*p表示p当前指向的对象。
     * */
    //2.1取地址运算符：在使用前初始化p是至关重要的。一种初始化指针变量的方法是使用&运算符把某个变量的地址赋给它或者更长采用左值
//    int i, *q;
//    q = &i;
    //可以进一步合并，把i的声明和q的声明合并，但是需要首先声明i
    // int i, *p = &i;

    //2.2间接寻址运算符:一旦指针变量指向了对象，就可以使用*运算符访问存储在对象中的内容。如下：
    // printf("%d\n", *p); //⚠️这里打印出来显示的i的值，而不是i的地址
    //2.2.1:对变量使用&运算符产生指向变量的指针，而对指针使用*运算符则可以返回到原始变量：
//    int j;
//    j = *&i;/*same as j =i;*/
    //只要p指向i，*p就是i的别名。*p不仅拥有和i相同的值，而且对*p的改变也会改变i的值.(*p是坐值，所以对它赋值是合法的)
    int i, *p = &i;
    i = 1;
    printf("%d\n", i);
    printf("%d\n", *p);
    *p = 2;
    printf("%d\n", i);
    printf("%d\n", *p);
    //2.3:⚠️不要把间接寻址运算符用于未初始化的指针变量。如果指针变量p没有初始化，那么试图使用p的值会导致未定义的行为：
    int *q;
    printf("%d", *q);   /*WRONG*/
    //多次执行有以下输出：12648448、70418432、69648384、48168960
    // ⚠️：给*q赋值尤其危险。如果q恰好具有有效的内存地址，下面的赋值会试图修改存储在该地方的数据:
    // *q = 1; /*WRONG，运行出现：EXC_BAD_ACCESS (code=2, address=0x1027ec100)*/
    //如果上述赋值改变的内存单元属于该程序，那么可能会导致出乎意料的行为；如果改变的内存单元属于操作系统，那么
    //很可能会导致系统崩溃。编译器可能会给出警告信息，告知q为初始化。



}

/**
 * 11.3指针赋值：
 * C语言允许使用赋值运算符进行指针的复制，前提是两个指针具有相同的类型。
 *
 */
void case03_pointer_assignment() {
    int i, j, *p, *q;
    p = &i;
    q = p; //把p的内容(即i的地址)复制给q,效果是把q指向了p所指向的地方即现在p和q都指向了i，
    //可以使用*p或*q赋新值的方法来改变i；
    *p = 1;
    printf("i = %d\n", i);
    printf("p = %p\n", p); //打印p的内容，即i的内存地址
    printf("q = %p\n", q);

    //修改变量i的值
    *q = 2;
    printf("i = %d\n", i);
    printf("p = %p\n", p); //打印p的内容，即i的内存地址
    printf("q = %p\n", q);
    //任意数量的指针变量都可以指向同一个对象,注意区分q=p和*q=*p
    //q=q是指针赋值，而赋值语句*q=*p是把p指向的值(i的值)复制到q指向的对象(变量j)中
    int n, m;
    p = &n;
    q = &m;
    n = 1;
    //  p= q;指针赋值
    *q = *p;
}

/**
 * 11.4指针作为参数：
 * 通过修改9.3节的decompose函数来作为案例
 */
void case04_pointer_as_argument() {
    double x = 3.1415;
    long i;
    double d;
    //调用decompose函数
    decompose(x, &i, &d);
    printf("直接打印变量i的值= %lld\n", i);
    printf("直接打印变量d的值= %lf\n", d);

}

/**
 *
 * @param x
 * @param int_part
 * @param frac_part
 */
void decompose(double x, long *int_part, double *frac_part) {
    *int_part = (long) x;
    *frac_part = x - *int_part;
    printf("通过间接寻址运算符*获取变量i值= %lld\n", *int_part);
    printf("通过间接寻址运算符*获取变量d值= %lf\n", *frac_part);

}

/**
 * 课堂练习：找出数组中的最大和最小元素：
 * 为了说明如何在函数中传递指针，编写函数用于查找数组中的最大元素和最小元素。调用max_min函数时，将传递两个指向变量的指针；然后
 * max_min函数把答案存储在这些变量中。
 * @param a
 * @param n
 * @param max
 * @param min
 */
void max_min(int a[], int n, int *max, int *min) {
    int i;
    *max = *min = a[0];
    for (i = 0; i < n; ++i) {
        if (a[i] > *max)
            *max = a[i];
        else if (a[i] < *min)
            *min = a[i];
    }

    /*可以使用单词const来表明函数不会改变指针参数所指向的对象。const应放置在形式参数的声明中，后面紧跟着形式参数的类型说明：*/
    //void f(const int *p)
}

/**
 * 11.5:指针作为返回值
 * 我们不仅可以为函数传递指针，而且还可以编写返回指针的函数。返回指针的函数是相对普遍的
 * 下面案例给定指向两个整数的指针时，下列函数返回指向两个整数中较大数的指针
 * @param a
 * @param b
 * @return
 */
int *max(int *a, int *b) {
    if (*a > *b)
        return a;
    else
        return b;
}