/********************************************************************************
* @author: mason shi
* @date: 2023/9/2 15:22
* @version: 1.0
* @description: 第十八章:声明在C语言编程中起着核心的作用。通过声明变量和函数，可以在两方面为编译器提供至关重要
 *              的信息：检查程序潜在的错误，以及把程序翻译目标代码
********************************************************************************/
#include<stdio.h>

char digit_to_hex_char(int digit);

void test_extern();

int test_register(int a[], int n);

int *func1(void);

int *func2(void);

void test_declarators();

void test_inline();

inline char *dbtest(int a);

int main(void) {
//    int n = 15;
//    printf("返回的数据: %c\n", digit_to_hex_char(n));

    test_declarators();
    return 0;

}


/**
 * 18.1 声明的语法：
 * 一般地，声明具有下列形式：
 * 【声明】声明指定符 声明符；
 * 声明指定符(declaration specifier)描述声明的变量或函数的性质。声明符(declaration)给出了它们的名字，并且提供提供关于其性质的额外信息。
 * 声明指定符分为以下3类：
 * 1.存储类型：存储类型一共有4种：auto、static、extern和register。在声明中最多出现的一种存储类型。如果存储类型存在，则必须把它放置在最前面。
 * 2.类型限定符： C89只有两种类型限定符：const和volatile。从C99开始还有一个包含限定符restrict;从C11开始又新增了一个原子类型限定符_Atomic。
 * 声明可以包含零个或多个限定符。
 * 3.类型指定符： 关键字void、char、short、int、long、float、double、signed和unsigned都是类型指定符。这些单词出现顺序不重要:int unsigned long
 * 和long unsigned int 完全一样。类型指定包括结构、联合和枚举的说明。用typedef创建的类型也是类型指定符。
 *
 * 声明符：可以只是一个标识符(简单变量的名字),也可能是标识符和[]以及*的各种组合，用来表示指针、数组或者函数。声明符之间用逗号分割。表示变量的声明
 * 符号后边可以跟随初始化器。
 *
 */
void declaration_syntax() {
    /*
     * 18.2.1:变量的性质
     * C程序中的每个变量都具下列3个性质：
     * 1.存储期：变量的存储期决定了为变量预留的内存被释放的时间。具有自动存储期的变量在所属块被执行时获得内存单元，并在块终止时释放内存单元，
     *         从而导致变量失去值。具有静态存储期的变量在程序运行期间占有同一个存储单元，也就运行变量无限期地保留它所占用的空间。
     * 2.作用域：变量的作用域其实是变量名字的作用范围，是指可以通过名字引用变量的那部分程序文本。变量可以有块作用域(从变量的名字声明的地方一直到
     *          块的末尾都是可见的)或者文件作用域(变量的名字从声明地方一直到所在文件的末尾都是可见的)。
     * 3.链接：实际上是指变量名字的链接属性，它确定了程序的不同部分可以通过变量名字共享此变量的范围。通过具有外部链接属性的名字，变量可以被程序中
     *       几个(或许全部)文件共享。如果名字具有内部链接属性，变量只能属于单独一个文件，但是此文件中的函数可以共享这个变量。(如果具有相同名字的的
     *       变量出现在另一个文件，那么系统会把它作为不同的变量处理。)名字属于无链接的变量属于单独一个函数，并且根本不能被共享。
     * 默认的存储期、作用域和链接都依赖于变量声明的位置。
     *      在块(包括函数体)内部声明的变量通常具有自动存储期，它的名字具有块作用域，并且无链接。
     *      在程序的最外层(任意块外部)声明的变量具有静态存储期，它的名字具有文件作用域和外部链接。
     * */


    /*18.2.3 auto存储类型：
     *    auto存储类型只对属于块的变量有效。auto变量具有自动存储期，它的名字具有块作用域，并且无链接。auto存储类型几乎从来不用显示地声明，因为
     *    对于在块内部声明的变量，它是默认的。
     * */

}


/**
 * 18.2.3 static存储类型：
 * static存储类型可以用于全部变量，而无须考虑变量声明的位置。但是，作用于块外部声明的变量和块内部声明的变量时会有不同的效果。
 * 当用在外部时，单词static说明变量的名字具有内部链接。当用作在块内部时，static把变量的存储期从自动的编程静态的。
 */
static int i; //静态存储期、文件作用域、内部链接
//在用于块外部的声明时，static本质上使变量只在声明它的文件内可见。只有出现在同一个文件中的函数可以看到此变量
//在下面的示例中，函数test_static和v2都可以访问到变量i，但是其他文件中的函数是不可以
void test_static() {
    static int j; //静态存储期、块作用域、无链接
    //has access to i
    /*块内的声明的static变量在程序执行期间驻留在同一存储单元内。和每次程序离开所在块就会丢失值的自动变量，static变量会无限期地保留
     * 值。static变量具有以下一些有趣的性质：
     * 1.块内的static变量只在程序执行前进行一次初始化，而auto变量则会在每次出现时进行初始化;
     * 2.每次函数被递归调用时，它都会获得一组新的auto变量。但是，如果函数含有static变量，那么此函数的全部调用都可以共享这个static变量。
     * 3.虽然函数不应该返回指向auto变量的指针，但是函数返回指向static变量的指针时没有错误的。
     * */

}

void v2() {
    /*has access to i*/
}


/**
 * 声明函数中的一个变量为static，这样做允许函数在“隐藏”区域内的调用之间保留信息。
 * 隐藏区域时程序其他部分无法访问到地方。然后，通通常的做法是用static来使程序更加有效。
 * @param digit
 * @return
 */
char digit_to_hex_char(int digit) {

    const char hex_chars[16] = "0123456789ABCDEF";
    return hex_chars[digit % 15];
}

/*每次调用digit_to_hex_char函数时，都会把字符0123456789ABCDEF复制给数组hex_chars来对其进行初始化。现在，把数组设为static的*/
char digit_to_hex_char_static(int digit) {
    static const char hex_chars[16] = "0123456789ABCDEF";
    //由于static型变量只进行一次初始化，这样做就提升来digit_to_hex_char函数的速度
    return hex_chars[digit];

}

/**
 * 18.2.4:extern存储类型
 * extern存储类型使几个源文件可以共享同一个变量
 *
 */
extern int k; //这样不会导致编译器为变量i分配存储单元。用C语言的术语说，上述声明不是i的定义，它只是提示编译器需要访问定义在别处的变量。
//变量在程序中可以有多次声明，但只能有一次定义
//变量的extern声明不是定义，这一规则有一个例外。对变量进行初始化的extern声明是变量的定义
extern int j = 10;//等价于int j =10，具有文件作用域

void test_extern() {

    /*extern 声明中的变量始终是具有静态存储期。变量的作用域依赖于声明的位置。如果声明在块内部，那么它的名字具有块作用域；否则
     * 具有文件作用域。确定extern型变量的链接有一定的难度。如果变量在文件中较早的位置(任何函数定义的外部)声明为static，那么它的
     * 名字具有内部链接；否则(通常情况下)，具有外部链接*/
    extern int f;//块作用域
}


/**
 * 18.2.5:register存储类型
 * 声明变量register存储类型就要求编译器把变量存储在寄存器中，而不是像其他变量一样保留在内存中(寄存器是驻留在计算机CPC中的存储单元。存储在
 * 存储器中的数据会比存储在普通内存中的数据数据访问和更新的速度更块。)指明变量的存储类型是register是一种请求，而不是命令。编译器
 * 可以选择把register型变量存储在内宽中。
 */
int test_register(int a[], int n) {
    /*
     * register存储类型只针对声明在块内的变量有效。register变量具有和auto变量一样的存储期、名字的作用域和链接
     * 但是register变量缺少auto变量所具有的一种性质：因为寄存器没有地址，所以对register变量使用取地址运算符&是非法的。
     * 即使编译器选择把变量存储在内存中，这一限制仍然适用。
     * register存储类型最好用在频繁进行访问或更新的变量汇总给你，如下所示，不过现在register存储类型已经不像以前那样在C程序员中
     * 流行了，C编译器复杂多了，许多编译器可以自动确定哪些变量保留在寄存器中可以获得最大的好处。
     * */
    register int i;
    int sum = 0;
    for (int l = 0; l < n; ++l)
        sum += a[i];
    return sum;

}

/**
 * 18.3类型限定符
 * 最开始C语言中一共有两种类型限定符：const和volatile。C99引入了第三种类型限定符，即restrict，它只用于受限指针；C11又引入了第四种
 * 类型限定符，即_Atomic，可用于除数组和函数之外的类型。因为volatile只用在底层编程中，后面会详细介绍。const用来声明有一些类似变量的
 * 对象。但这些变量是“只读”的。程序可以访问const型对象的值，但是无法改变它的值。
 */
void test_const() {
    const int n = 10;/*这个值可读，但是无法改变*/
    /*把对象声明为const有以下几个好处：
     * 1.const是文档格式：声明对象是const类可以提示任何阅读程序的人，该对象的值不会改变；
     * 2.编译器可以检查程序没有特意地试图改变该对象的值；
     * 3.为特定类型的运用(特别是嵌入式系统)编写程序时，编译器可以用单词const来识别需要存储到ROM(只读存储器)中的数据。
     * */
}


/**
 * 18.4 声明符
 * 声明符包含识别符(声明的变量或函数的名字)，标识符的前边可能有符号*,后边可能有[]或()。通过把*、[]和()组合在一起，可以创建
 * 复杂声明符。
 */
void test_declarators() {
    /*识别声明符的规则
     * 1.始终从内往外读声明符。换句话说，定位声明的识别符，并且从此处开始解释声明。
     * 2.在做选择时，始终使[]和()优于*。如果*在标识符的前面，而标识符后边跟着[],那么标识符表示数组而不是指针。同样地，如果*在标识符的
     * 前面，而标识符在后边跟着(),那么表示表示函数而非指针。
     * */
    //上面的声明表示：首先，定位声明的标识符(x)。在x前有*,而后边又跟着[]。因为[]优先级高于*,所以取右侧(x是数组)。
    //              接下来，从左侧找到数组中元素的类型(指针)。再接下来，到右侧找到指针所指向的数据类型(不带实际参数的函数)。
    //             最后，回到左侧看每个函数返回的内容(指向int型的指针)
/*
 *
 *  Let's break down this declarator step by step:
    1.x[10]: This declares an array named x with 10 elements. Each element is capable of storing a function pointer.
    2.(*x[10]): The * operator is applied to each element of the x array, making each element a pointer to a function.
    This means that x is an array of function pointers.
    3.(*x[10])(void): This indicates that the functions pointed to by elements of the x array take no arguments (void).
    So, (*x[10]) represents an array of function pointers that point to functions taking no arguments.
    4.int *(*x[10])(void);: Finally, this declares x as an array of 10 function pointers, where each function
    returns a pointer to an integer (int *).
    So, int *(*x[10])(void); declares an array named x of 10 pointers to functions that return pointers to integers.
    You can use x to store references to such functions, and you would invoke them like this:
 * */
    //下面是常见的较为复杂的声明符
    int *(*x[10])(void); // Declare an array of 10 function pointers
    // Assign functions to the array elements
    x[0] = func1;
    x[1] = func2;

    // Call the functions and print their results
    printf("%d\n", *x[0]()); // Should print 42
    printf("%d\n", *x[1]()); // Should print 100

    //C语言中函数不能返回函数
    //int g(int)(int);
    //返回函数型的数组也是不可能的
    //int a[10](int);

}

int *func1(void) {
    static int value = 42; // A static int variable to return its address
    return &value;
}

int *func2(void) {
    static int value = 100; // Another static int variable to return its address
    return &value;
}


/**
 * 18.6内联函数
 * inline关键字是C99标准的型关键字，其作用是将函数展开，把函数的代码复制到每一个调用处。这样调用函数的过程就可以直接执行函数代码，
 * 而不发生跳转、压栈等一般性函数操作。可以节省时间，也会提高程序的执行速度。
 * 在C语言中，如果一些函数被频繁的调用，不断地用函数入栈，即函数栈，则会造成栈空间或者栈内存的大量消耗，为了解决这个问题，
 * 特别的引入了inline关键字，表示为内联函数。栈空间指的是函数内数据的内存空间，在一个系统下，栈空间的资源是有限的，
 * 假如频繁大量的使用就会因栈空间的不足而导致出错，函数的死循坏递归调用的最终结果就是导致栈内存空间的枯竭。
 *具体可以参考链接：https://zhuanlan.zhihu.com/p/448262183
 *
 *
 */
void test_inline() {
   // 下面的例子就是标准的内联函数的用法，使用inline修饰带来的好处我们表面看不出来，其实，
   // 在内部的工作就是在每个for循环的内部任何调用dbtest(i)的地方都换成了(i%2>0)?”奇”:”偶”，
   // 这样就避免了频繁调用函数对栈内存重复开辟所带来的消耗。

    int i = 0;
    for (i = 1; i < 100; i++) {
        printf("i:%d    奇偶性:%s /n", i, dbtest(i));
    }

}

//函数定义为inline即:内联函数
inline char *dbtest(int a) {
    return (i % 2 > 0) ? "奇" : "偶";
}