/********************************************************************************
* @author: mason shi
* @date: 2023/8/5 15:46
* @version: 1.0
* @description: 第十四章课后练习题题目
********************************************************************************/
#include<stdio.h>
#include<string.h>

#define N 100

void f(void);

void exec14_11();

void exec14_08();

void exec14_13();

/*课后练习题01编写宏来计算下面的值*/
//a.x的立方
#define CUBE(x) ((x)*(x)*(x))
//b.n除以4的余数
#define MOD4(n) ((n) % 4)
//c.如果x与y的乘积小于100则值为1，否则值为0,一般变量才加上圆括号
#define MULTIPLICATION(x, y) (((x)*(y)) < 100 ?1:0)

/*2.课后练习题目02:编写一个宏NELEMS(a)来计算一纬数组中元素的个数。提示：见8.1节中有关sizeof运算符号的讨论*/
#define NELEMS(a) (int)(sizeof(a) / sizeof(a[0]))
/*3.课后练习题03:假定DOUBLE是如下宏：
 * a.DOUBLE(1+2)的值是多少？ 6
 * b.4/DOUBLE(2)的值是多少？1
 * c.修改DOUBLE的定义。修改如下：
 * */
//#define DOUBLE(x)
#define DOUBLE(x) (2*(x))

/*课后练习题04:针对下面每一个宏，举例说明宏的问题，并提出修改方法*/
//#define AVG(x, y) (x-y)/2
#define AVG(x, y) (((x)+(y))/2)
//b.#define AREA(x,y) (x) * (y)
#define AREA(x, y) ((x) * (y))

/*课后练习题05:假定TOUPPER定义成下面的宏,小写转大写的方法*/
#define TOUPPER(c) ('a'<=(c) && (c)<='z'?(c)-'a'+'A':(c))

/*课后练习题06:编写宏DISP(f,x),使其扩展为printf函数的调用，显示函数f在参数为x时的值，例如：
 * DISP(sqrt, 3.0);
 * 应该扩展为：printf("sprt(%g) = %g\n"),3.0,sqrt(3.0));
 * */
#define DISP(f, x) (printf((#f) "(%g) = %g\n", (x), (f(x))))
//b.编写宏DISP2(f,x,y)，类似DISP但运用于有两个参数的函数
#define DISP2(f, x, y) (printf((#f) "(%g, %g) = %g\n", (x), (y), (f((x),(y)))))

/*课后练习题目07:假定GENERIC_MAX是如下宏：*/
//#define GENERIC_MAX(type)       \
//type type##_max(type x,type y)  \
//{                               \
//  return x>y ? x :y             \
//}                               \
// Step 1: Create a typedef for the basic type (e.g., unsigned long).
typedef unsigned long my_type;
// Step 2: Define the GENERIC_MAX macro (unchanged from the original).
#define GENERIC_MAX(type)       \
type type##_max(type x, type y) \
{                               \
    return x > y ? x : y;       \
}
// Step 3: Use the GENERIC_MAX macro with the new typedef.
GENERIC_MAX(my_type)


//课后练习题09：编写下列带参数的宏：
//a.CHECK(x,y,n)——x和y都落在0~n-1范围内(包括端点)时值为1.
#define CHECK(x, y, n) (((x)>=0&&(x)<=(n)-1&&(y)>=0&&(y)<=(n)-1)?1:0)

//b.MEDIAN(x,y,z)——计算x、y和z的中位数.
#define MEDIAN(x, y, z) (((x)>=(y)&&(x)<=(z))?(x):((y)>=(x)&&(y)<=(z))?(y):(z))

//c.POLYNOMTAL(x)——计算多项式3X5+2x4-5x3-x2+7x-6.
#define POLYNOMIAL(x) (  (3*(x)*(x)*(x)*(x)*(x)) \
                       + (2*(x)*(x)*(x)*(x))     \
                       - (5*(x)*(x)*(x))         \
                       - ((x)*(x))               \
                       + (7*(x))                 \
                       - 6)

int main(void) {
    //a.#define AVG(x, y) (x-y)/2定义可能出现的弊端
    //AVG(1+1, 2+2)` 将错误地遵循标准操作顺序：
    //`(1+1-2+2)/2`，计算结果为 2，而不是预测的 -2。 放置括号
    //围绕参数可以解决这个问题：
//    printf("%d\n", AVG(6, 2));
//    printf("%d\n", AREA(5, 5));
/*在宏定义中缺少圆括号会导致C语言中最让人讨厌的错误。程序通常仍然可以编译通过，而且宏似乎也可以工作，仅在少数情况下会出错*/

    //课后练习题05:假设s是一个字符串，i是一个int类型变量。给出下面每个代码段产生的输出
    //a.
//    char s[10];
//    int i = 0;
//   strcpy(s, "abcd");
//   putchar(TOUPPER(s[i++]));//注意这里并没有循环，输出大写C
    //putchar(TOUPPER(s[++i]));//注意这里并没有循环，输出大写D
    //b.
//    strcpy(s,"0123");
//    putchar(TOUPPER(s[++i]));//同理可得

    /*课后练习题06.a题目：*/
    //   DISP(sqrt, 3.0);


    /*课后练习题目07:
     * a.写出GENERIC_MAX(x)被预处理器扩展后的形式
     * b.解释为什么GENERIC_MAX不能运用于unsigned long 这样的基本类型
     * c.如何使GENERIC_MAX可以用于unsigned long 这样的基本类型？提示：不要改变GENERIC_MAX的定义
     * */
    //a.主要考察##运算符：可以将两个记号(如标识符)"粘合"在一起，成为一个记号。
/*    long long_max(long x, long) {
        return x > y ? x : y;
    }*/
    //b.宏 GENERIC_MAX 设计用于处理类型，而不是像 unsigned 这样的类型限定符。
    // 当与 unsigned long 一起使用时，宏会将 unsigned 视为类型名称的一部分，
    // 并将其附加到函数名称中，从而导致函数声明无效。 例如，如果使用 GENERIC_MAX(unsigned long)，将导致以下无效函数声明：
    // unsigned long unsigned long_max(unsigned long x, unsigned long y)
    // {
    //return x > y ? x : y;
    // }
    //正如您所看到的，函数名称中出现两次 unsigned 是不正确的，并且会导致编译错误。

    //c.要使 GENERIC_MAX 使用 unsigned long 等基本类型，您可以使用 typedef 创建表示所需基本类型的新类型。
    // 然后，您可以将这个新类型与 GENERIC_MAX 一起使用
    my_type a = 10;
    my_type b = 20;
    printf("Max value: %lu\n", my_type_max(a, b));
    /*By using a typedef for the basic type, we can then use the GENERIC_MAX macro with my_type,
     * which is essentially unsigned long in this example. The macro will expand correctly with
     * the typedef name, allowing us to compare and find the maximum value of two variables of
     * type my_type (which is unsigned long in this case).*/
    //exec14_11();
    exec14_13();
}

/**
 * 课后练习题目08：如果需要一个宏，使它扩展后包含当前行号和文件名。换言之，我们想把
 * const char *str = *LINE_FILE;
 * 扩展为
 * const char *str = "Line 10 of file foo.c";
 *  其中，foo.c是包含程序的文件，10是调用LINE_FILE的行号。警告：这个练习针对高级程序员。尝试编写前请认真阅读“问
 *  与答”部分的内容！
 */
void exec14_08() {
//#define STRINGIZE(x) #x
//#define EXPAND_MACRO(x) STRINGIZE(x)
//#define LINE_FILE ("Line " EXPAND_MACRO(__LINE__) " of file " __FILE__)
//
}

/**
 * 课后练习10:
 * 函数常常(但不总是)可以写成带参数的宏。讨论函数的哪些特性会使其不适合写为宏的形式。
 *
 */

void exec14_10() {
/**  1.副作用：具有副作用的函数，例如修改全局变量或执行输入/输出操作，不适合作为宏。
      宏是内联扩展的，并且多个宏调用可能会由于重复执行副作用代码而导致意外行为。

     2.多次求值：宏可能会导致对参数进行多次求值，如果参数有副作用或者求值成本昂贵，则可能会出现问题。 另一方面，函数保证参数被评估一次。
       类型安全：函数通过函数原型和参数类型检查来强制类型安全。 另一方面，宏不执行类型检查，如果参数的类型与预期不同，则可能会导致意外行为。

     3.作用域问题：函数有自己的作用域，而宏在调用者的作用域中扩展。 这可能会导致变量名称冲突或与局部变量的意外交互。
      大型代码扩展：如果宏很大或在整个代码库中广泛使用，则宏可能会导致代码膨胀。 这会对代码的可读性和可维护性产生负面影响。

     4.缺乏错误处理：函数可以使用返回语句或异常来优雅地处理错误。 宏缺乏这种功能，使得错误处理更具挑战性且更容易出错。

     5.函数指针：宏不能与函数指针一起使用，因为它们仅在文本级别上运行。 可以使用函数指针将函数作为参数传递给其他函数，从而实现更高级的编程技术。

     6.类似函数的参数：函数可以接受其他函数作为参数，从而允许高阶函数和函数式编程范例。 宏由于其基于文本的扩展，无法处理类似函数的参数。

    代码可重用性：函数在设计上是模块化和可重用的，使其更易于维护并提高代码的可重用性。 宏不太灵活，并且有效重构或重用可能具有挑战性。
    总之，虽然宏可以方便地进行简单高效的代码扩展，但函数在类型安全、作用域、错误处理和代码可维护性方面提供了多种优势。
    通常不鼓励对复杂或有副作用的代码使用宏，以避免潜在的陷阱并提高代码的整体质量。*/
}

/**
 * 课后练习题11:
 * C程序员常用fprintf函数来输出错误消息：
 * fprintf(stderr,"Range error: index =%d\n",index);
 * 其中stdeer流是C的“标准误差”流。其他参数与printf阐述的参数一样，以格式串开始。
 * 编写名为ERROR的宏来生成上面的fprintf调用，宏的参数是格式串和需要显示的项：
 * ERROR("Range error: index=%d\n",index);
 */
void exec14_11() {
#define ERROR(format, ...) fprintf(stderr, format, __VA_ARGS__)
    //调用的方式
    int index = 42;
    ERROR("Range error: index = %d\n", index);

}

/**
 * 课后练习题13:执行下列程序在预处理后的形似；这个程序的输出是什么？
 */
void exec14_13() {
    f();
#ifdef N
#undef N
#endif
    /*预处理后的格式：
     * void f(void);

int main(void)
    {
    f();
    return 0;
    }

void f(void)
     {
    printf("N is undefined\n");

    }* */

}

void f(void) {
    /*当程序在 void f(void) 函数中遇到 #ifdef N 时，#define N 100 行将被删除。 这是因为#ifdef指令检查N是否已定义，
     * 并且它是在此时定义的，因此包含#ifdef块中的代码，其中包含#undef N。#undef N 指令删除宏 N 的定义。void f(void) 函数
     * 中的 #if Defined(N) 检查 N 是否已定义，但由于它只是使用 #undef 未定义，因此包含 #else 块中的代码。#else 块内的
     * printf 语句保留在程*/
#if defined(N)
    printf("N is %d\n", N);
#else
    printf("N is undefined\n");
#endif
}


/**
 * 假定程序需要使用英语、法语或西班牙语显示消息。使用条件编译编写程序片段，根据指定的宏是否定义来显示
 * 处下列3条消息中的一条：
 * Insert Disk 1      (如果定义来ENGLISH)
 * Inserez Le Disque 1 (如果定义了FRENCH)
 * Insert E1 Disco 1  (如果定义了SPANISH)
 */
void exec14_15() {
// Define one of the macros to specify the language
//#define ENGLISH
//#define FRENCH
#define SPANISH

#ifdef ENGLISH
    printf("Insert Disk 1\n");
#elif defined(FRENCH)
    printf("Inserez Le Disque 1\n");
#elif defined(SPANISH)
    printf("Inserte El Disco 1\n");
#else
    printf("Language not specified\n");
#endif
}

