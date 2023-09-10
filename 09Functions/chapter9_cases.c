/**
Created by mason on 2023/6/11
 第九章：函数
 函数简单来说就是一连串语句，这些语句被组合在一起，并被指定了一个名字。虽然“函数”这个术语来自数学，但是C语言的函数不完全等同于数学函数。
 在C语言中，函数不一定有参数，也不一定计算函数值。
 函数是C程序的构建块。每个函数本质上是一个自带声明和语句的小程序，可以利用函数把程序划分成小块，这样便于人们理解和修改程序。由于不必重复编写要多次使用
 的代码，函数可以使编程不那么单调乏味。此外，函数可以复用，一个函数最初可能是某个程序的一部分，但可以将其用于其它程序。
 */

#include<stdio.h>
#include<stdbool.h>

#define N 10

/**
 * 函数声明：为了避免定义前调用的问题，C语言提供了一种更好的解决办法：在调用前声明每个函数。函数声明使得编译器
 * 可以先对函数进行概要浏览，而函数的完整定义以后再出结论。函数声明类似于函数定义的第一行，不同之处是在结尾处有分号：
 * 【函数声明】返回类型 函数名(形式参数);
 * 函数的声明必须与函数的定义一致，函数原型为如何调用函数提供了完整的描述：提供了多少实际参数，这些参数是什么类型，以及
 * 返回的结果是什么类型。
 *
 * */
double get_average(double a, double b);

void print_countdown(int n);

void print_pun(void);

bool is_prime(int n);

int square(int n);

int sum_array(int a[], int n);

int fact(int n);

int power(int x, int n);

void divide_conquer();

void quicksort(int a[], int low, int high);

int split(int a[], int low, int high);

//int main(void) {
//    double x, y, z;
//    printf("Enter three numbers: ");
//    scanf("%1f%1f%1f", &x, &y, &z);
    //函数的多次调用
    //g,G,以%f或%e中较短的输出宽度输出单、双精度实数
//    printf("Average of %g and %g: %g\n", x, y, get_average(x, y));
//    printf("Average of %g and %g: %g\n", y, z, get_average(y, z));
//    printf("Average of %g and %g: %g\n", x, z, get_average(x, z));

    //调用无返回参数函数
//    int i;
//    for (i = 10; i > 0; i--) {
//        print_countdown(i);
//
//    }

    //调用不带实际参数的函数时，只需要写出函数名,
//    print_pun();

    //案例练习三：判定一个数是否为素数
//    int n;
//    printf("Enter a number: ");
//    scanf("%d", &n);
//    if (is_prime(n))
//        printf("Prime\n");
//    else
//        printf("Not prime\n");
    /*
     * 9.3.1实际参数的转换：C语言允许在实际参数的类型与形式参数的类型不匹配的情况下进行函数调用。管理如何转换实际参数的规则与
     * 编译器是否在调用前遇到函数的原型有关。
     * 1.编译器在调用前遇到原型。就像使用赋值一样，每个实际参数的值被隐式第转换成相应形式参数的类型。例如把int类型的实际参数传递
     *    期望得到double类型数据的函数，那么实际参数会被自动转换成double类型。
  *    2.编译器在调用前没有遇到原型。编译执行默认实参提升：
     *    a.把float类型的实际参数转换成double类型；
     *    b.执行整值提升，即把char类型和short类型的实际参数转换成int类型.
     * */
    //默认实参提升可能无法产生期望的结果：
    //默认实参提升可能无法产生期望的结果：
//    double x = 3.0;
//    printf("Square: %d\n", square(x));
//    //可以强制转换
//    printf("Square: %d\n", (int) square(x));

    /*9.3.2数组型实际参数：C语言没有为函数提供任何简便的方法来确定传递给它的数组的长度；
     * 如果函数需要，必须把长度作为额外的参数提供出来。
     * */


    /**
     * 9.5退出函数：
     * main函数返回的值时状态码，在某些操作系统中程序终止时可以检测到状态码。如果程序正常终止，main函数应该返回0；
     * 为了表示异常终止，main函数应该返回非0的值。作为终止程序的方法，return语句和exit函数关系紧密，main
     * 函数中的 return 表达式；等价于：exit(表达式);
     * 二者之间的差异：不管哪个函数调用exit函数都会导致程序终止，return语句仅当main函数调用时才会导致程序终止。
     */


    /**
     * 9.6递归：函数调用它本身了，那么此函数就是递归的，
     * 要深入递归的工作原理：
     * */

//    int n = 10;
//    printf("%d", fact(n));
//    int x = 5, y = 3;
//    printf("\n%d", power(x, y));
//    divide_conquer();
//    return 0;
//}

/**
 * 1.函数的定义和调用：
 * 返回类型 函数名(形式参数)
 *        复合语句
 *   返回类型是指函数返回值的类型。下列规则来管理返回类型：
 *   1.函数不能返回数组，但关于返回类型没有其他限制。
 *   2.指定返回类型时void类型，说明函数没有返回值
 *   3.如果省略返回类型，C89会假定函数返回值的类型时int类型，但在C99中这是不合法的.
 * 案例练习01:计算平均值
 * @param a 传入参数a
 * @param b ：传入参数b
 * @return
 */

double get_average(double a, double b) {
    return (a + b) / 2;

}

/**
 * 案例练习二：演示不带返回值的函数，需要指明这类函数的返回类型是void
 *  显示倒计时的演示
 * @param n
 */

void print_countdown(int n) {

    printf("T minus %d and counting\n", n);

}

/**
 * 案例练习三：有些函数根本没有形式参数：
 * 圆括号中的单词void表明print_pun函数没有实际参数，调用不带实际参数时，只需要写出函数名，并且在后面
 * 加上一对圆括号，即使没有实际参数也必须给出圆括号。
*/

void print_pun(void) {
    printf("To C, or not to C: that is the question.\n");

}

/**
 * 案例练习四：判定素数，给定数n后，函数把n除以从2到n的平方根之间的每一个数，只要有一个余数为0，则不是余数
 */

bool is_prime(int n) {
    int divisor;
    if (n <= 1)
        return false;
    for (divisor = 2; divisor * divisor <= n; divisor++)
        if (n % divisor == 0)
            return false;
    return true;

}

/*
 * 实际参数转换的案例：默认实参提升可能无法产生期望的结果
 * */

int square(int n) {
    return n * n;

}

/*
 * 数组型实际参数案例：一维数组型实际参数的用法。当给出具有int类型值的数组a时，
 * sum_array函数返回数中a中元素和.因为sum_array函数需要直到数组a的长度，所以必须
 * 把长度作为第二个参数提供出来.
 * */
int sum_array(int a[], int n) {
    int i, sum = 0;
    for (i = 0; i < n; ++i)
        sum += a[i];

    return sum;


}

/*
 * 递归案例学习；斐波那契数是以递归的方法来定义
 *用文字来说，就是斐波那契数列由0和1开始，之后的斐波那契数就是由之前的两数相加而得出。首几个斐波那契数是：
1、 1、 2、 3、 5、 8、 13、 21、 34、 55、 89、 144、 233、 377、 610、 987……（OEIS数列A000045）
特别指出：0不是第一项，而是第零项。
一旦被调用，fact函数就会仔细地测试“终止条件”。调用fact函数它会立刻检查参数是否小于或等于2;为了防止无限递归，所有递归函数
 都需要某些条件的终止条件。
 注意：在fact函数最终传小于或等于2时，未完成的fact函数的调用时如何堆积的。在最终传递到2时的那一点上，fact函数的先前调用开始
 逐个解开。直到fact(10)最终返回结果34
 * */
int fact(int n) {
    if (n <= 2)
        return n <= 1 ? 0 : 1;
    else
        return fact(n - 2) + fact(n - 1);

}

/**
 * 递归案例练习02:
 * @param x
 * @param n
 * @return
 */
int power(int x, int n) {
//    if (n == 0)
//        return n = 1;
//    else
//        return x * power(x, n - 1);
    /*调用power(5,3)将按照如下方式进行：
     *  1.power(5,3)发现不等于0，所以power(5,3)调用
     *     2.power(5,2),此函数发现2不等于0，所以power(5,2)继续调用
     *      3.power(5,1),此函数发现1不等于0，所以power(5,1)调用
     *          4.power(5,0),此函数发现0是等于0，所以返回1，从而导致
 *          5.power(5,1)返回5*1=5,从而导致
 *        6.power(5,2)返回5*5=25,从而导致
*        7.power(5,3)返回25*5=125
     *
     * */

    //通过条件表达式放入return语句中的方法可以精简power函数：
    return n == 0 ? 1 : x * power(x, n - 1);

}

void divide_conquer() {
    int a[N], i;
    printf("Enter %d numbers to be sorted: ", N);
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
    quicksort(a, 0, N - 1);
    printf("In sorted order: ");
    for (i = 0; i < N; i++)
        printf("%d ", a[i]);
    printf("\n");
}

/**
 *
 * @param a
 * @param low
 * @param high
 */
void quicksort(int a[], int low, int high) {
    int middle;
    if(low >= high) return;
    middle = split(a, low, high);
    quicksort(a, low, middle - 1);
    quicksort(a, middle + 1, high);
}

/**
 * 分割数组的代码比较长，提取出来放置在名为split的独立函数中
 * @param a
 * @param low
 * @param high
 * @return
 */
int split(int a[], int low, int high) {
    int part_element = a[low];
    for (;;) {
        while (low < high && part_element <= a[high])
            high--;
        if (low >= high) break;
        a[low++] = a[high];

        while (low < high && a[low] <= part_element)
            low++;
        if (low >= high) break;
        a[high--] = a[low];

    }
    a[high] = part_element;
    return high;

}