/**
Created by mason on 2023/5/27
 第七章：基本类型
 *
*/
#include<stdio.h>

/**
 * 读写无符号整数、短整数和长整数需要一些新的转换指定符：
 * C语言整型变量有四种修饰符：
 * signed:有符号的，可以表示整数和负数
 * unsigned:无符号的，只能表示整数、例如数组的下标、人的身高等
 * short: 短的，现在主流的64位操作系统下，整数占用内存4个字节，使用 4
 *个字节保存较小的整数绰绰有余，会空闲出两个字节来，这些字节就白白浪费掉了。在C语言被发明的早期，或者在单片机和嵌入式系统中，内存都是非常稀缺的资源，所有的程序都在尽可能节省内存
 * long：长的，更长的整数。
 * 请记住：八进制和十六进制指示书写数的方式，它们不会对数的实际存储方式发生影响。整数都是以二进制形式存储的，跟表示方式无关
 */
void read_write_integer() {
    /*1.二进制由1和0组成，使用时必须以0b或0B(不区分大小写)开头*/
    //合法的二进制:
    int a = 0b101;
    printf("%u\n", a);
    int c = 0B100001;
    printf("%u\n", c);

    /*以下是非法的二进制
     * 请注意：
     * 标准的C语言并不支持上面的二进制写法，只是有些编译器自己进行了扩展，
     * 才支持二进制数字。换句话说，并不是所有的编译器都支持二进制数字，
     * 只有一部分编译器支持，并且跟编译器的版本
     * */
    // int m = 101010; //无前缀0B,相当于十进制
    //int n = 0B410; 编译不通过的，4不是有效的的二进制数

    /*2.八进制由0~7八个数字组成，使用时必须以0开头(注意是数字0，不是字母o)
     * 注意的坑：
     * 在现实生活和工作中，我们在写十进制数的时候，为了对齐或其它原因，在数值前面加0是无关紧要的，
     * 但是，在C语言中，不要在十进制数前加0，会被计算机误认为是八进制数。
     * */
    //八进制合法的写法
    int i = 015;
    printf("%o\n", i);  //以八进制输出
    printf("%u\n", i); //以十进制输出对应的值
    /*int j = -0101; 负数的输出有问题后续到对应的章节再处理
    printf("%u\n", j);*/
    int h = 0177777;
    printf("%u\n", h);
    //以下是非法八进制：
    // int w1 = 256; 无前缀，相当于十进制
    // int w2 = 02A2; A不是有效的八进制数字

    /*3.十六进制由数字0～9、字母A~F或a~f(不区分大小写)组成，使用时必须以0x或则0X(不区分大小写)开头
     *
     * */
    //合法的十六进制
    int k1 = 0x2A;
    printf("%x\n", k1); //以十六进制方式输出
    printf("%u\n", k1);//以十进制方式输出
    int k2 = 0Xffff;
    printf("%u\n", k2);//以十进制方式输出
    //非法的十六进制
    //int k3 = 5A;没有前缀0X,是一个无效数字
    //int k4 = 0X3H; H不是有效的十六进制数字
    /******************************************************************************************************************
     * 下表时各种进制整数的输出格式：
     * %hd、%d、%ld:以十进制、有符号的形式输出short、int、long类型的整数；
     * %hu、%u、%lu:以十进制、无符号的形式输出short、int、long类型的整数；
     * %ho、%o、%lo:以八进制、不带前缀、无符号的形式输出short、int、long类型的整数;
     * %#ho、%#o、%#lo:以八进制、带前缀、无符号的形式输出short、int、long类型的整数;
     * %hx、%x、%lx:以十六进制、不带前缀、无符号的形式输出short、int、long类型的整数;如果x小写，那么输出的十六进制数字也小写；如果X大写，那么
     *             输出的十六进制数字也大写。
     *%#hx、%#x、%#lx:以十六进制、带前缀、无符号的形式输出short、int、long类型的整数;如果x小写，那么输出的十六进制数字也小写；如果X大写，那么
     *             输出的十六进制数字也大写。                                                                                                                                                                                        *
     * ****************************************************************************************************************/

    /*上表中没有二进制的输出格式，虽然部分编译器支持二进制的数字的编写，但是却不能用printf()函数输出二进制。但是可以编写函数把其它进制
     * 数字转换成二进制数字，并保存在字符串中，然后在printf函数中使用%s输出*/

    /*具体案例如下*/
    int ii = 100;  // 定义变量ii，赋值十进制的100。

    printf("十进制输出结果：%d\n", ii);  // 十进制输出结果：100

    printf("八进制、无前缀输出结果：%o\n", ii);  // 八进制、无前缀输出结果：144
    printf("八进制、有前缀输出结果：%#o\n", ii); // 八进制、有前缀输出结果：0144

    printf("十六进制、无前缀输出结果：%x\n", ii);  // 十六进制、无前缀输出结果：64
    printf("十六进制、有前缀（小写）输出结果：%#x\n", ii); // 十六进制、有前缀（小写）输出结果：0x64

    printf("十六进制、无前缀输出结果：%X\n", ii);  // 十六进制、无前缀输出结果：64
    printf("十六进制、有前缀（大写）输出结果：%#X\n", ii); // 十六进制、有前缀（大写）输出结果：0X64

}

/**
 * 6.1节编写了一个程序，对用户输入的整数数列求和。该程序的一个问题就是所求出的和(或其中输入某个数)可能会超高int型变量允许的最大值。
 * 如果求和的结果为60000。但这个值不在int型变量表示的范围内，所以出现了溢出。有符号的整数发生溢出时，结果时未定义的，
 * 在例子中我们得到了一个毫无意义的结果。为了改变这个程序我们可以将变量换成long型
 */
void outOfMemory_sum2_case() {
    long n, sum = 0;
    printf("This program sums a series of integer.\n");
    printf("Enter integers (0 to terminate): ");
    scanf("%d", &n);
    while (n != 0) {
        sum += n;
        scanf("%ld", &n);
    }
    printf("The sum is : %ld\n", sum);

}

/**
 * 有符号和无符号的区别，以及要注意的点
 */
void signed_unsigned() {
    int a = -1;  //a是有符号是4个byte,是32位，负数最高位是1：1111 1111 1111 1111 1111 1111 1111 1111
    //但是对应无符号的a的值是2的32次方减去1，即4294967295
    unsigned int b = 0;
    if (a < b)  //C语言中隐式的将有符号a用无符号的a来解释,所以:4294967295 > 0,所以C语言有符号和无符号不能混用，容易出问题
        printf("-1 < 0");  //底层的二进制位没有发生变化，变化的是解析这些二进制的方式发生了变化
    else
        printf("-1 > 0");
    //运行结果：-1 > 0

}

/**
 * 整数的运算case1:
 */
void integer_arithmetic() {
    unsigned char a = 255;  //无符号char表示范围最大范围：0～255，一个字节byte
    unsigned char b = 1;
    unsigned char c = a + b;
    printf("c =%d\n", c);
    //运行结果：c =0； c = a + b -2的w次方，w=8bit
    //                =256-256=0
    char x = 127; //有符号的char 表示范围：-128～127
    char y = 1;
    char z = a + b;
    printf("z=%d\n", z); //-128  这是正溢出
    //以下是负溢出
    char h = -128;
    char k = -1;
    char w = h + k;
    printf("w=%d\n", w);//127

}

/**
 * C语言中常用的字符处理函数
 * 读写字符除了使用scanf和printf函数外，C语言还提供了另外一些读/写单个字符的方法
 * 惯用方法：
 * while (getchar() != '\n')
 * ;
 * 这个循环读入一个字符串。把它存储在变量中，然后测试变量ch是否不是换行符。如果测试结果为真，那么执行循环体(循环体实际为空),接着再测试循环条件
 * ，从而读入新的字符。实际上我们并不需要变量ch，可以把getchar函数的返回值与换行符进行比较；
 * 惯用方法2:
 * while((ch = getchar()) == '')
 * ;
 * getchar()函数对搜索字符的循环和跳过字符的循环都很有用。以上当循环终止时，变量ch将包含getchar函数遇到的的哥非空白字符。
 *
 */
void character_handle_function() {
    /*为了说明字符的读取方式，下面编写一个程序来计算消息的长度，在用户输入消息后，程序显示长度：
     * Enter a message: Bravity is the soul of wit.
     * Your message was 27 character(s) long.
     * 消息的长度包括空白和标点符号，但是不包括换行符
     * */
    int len = 0;
    printf("Enter a message: ");
//    ch = getchar();
//    while (ch != '\n'){
//        len++;
//        ch = getchar();
//    }
//    printf("Your message was %d character(s) long\n",len);

    //更加简洁写法
    while (getchar() != '\n')
        len++;
    printf("Your message was %d character(s) long\n", len);


}

/**
 * 常规算术转换的策略时把操作数转换成可以安全地适用于两个数值的"最狭小的"数据类型。为了统一操作数的类型，通常可以将相对狭小类型的操作数
 * 转换成另一个操作数的类型来实现(这就是所谓的类型提升)
 * 浮点类型的：
 *              long  double
 *                  double
 *                  float
 * 整数类型
 *             unsigned long int
 *                  long int
 *               unsigned int
 *                      int
 *
 * 下面是一些实际的案例：
 * 当符号数和无符号操作数结合起来时，有符号操作数会被“转换”为无符号的值。转换过程中需要加上或者减去n+1的倍数，
 * 其中n时无符号类型能表示的最大值。这条规则可能会导致某些隐蔽的编程错误。
 *
 */
void type_conversation() {
    char c;
    short int s;
    int i;
    unsigned int u;
    long int l;
    unsigned long int ul;
    float f;
    double d;
    long double ld;
    i = i + c;/*c is converted to int */
    i = i + s;/* s is converted to int */
    u = u + i; /* i is converted to unsigned int */
    l = l + u; /*u is converted to long int*/
    ul = ul + l; /* l is converted to unsigned long int*/
    f = f + ul; /* ul is converted to float*/
    d = d + f; /*f is converted to double*/
    ld = ld + d; /*d is converted to long double */


    /*类型定义：5.2节中，我们使用#define指令创建了一个宏，可以用来定义布尔型数据
     * #defined BOOL int
     * 但是，一个更好的设置布尔类型的方法是利用所谓的类型定义(type definition)特性：
     * typedef int Bool;
     * */
    //类型定义使程序更加易于理解。例如，假设变量cash_in 和变量cash_out将用于存储美元数量。把Dollars声明成
    typedef float Dollars;
    //并且随后写出
    Dollars cash_in,cash_out; //这样的写法比下面的写法更有实际意义
  //  float cash_in,cash_out;
  //类型定义还可以使程序更容易修改。如果稍后决定Dollars实际应该定义为double类型，
  //那么只需要改变类型定义就足够了：
 // typedef double Dollars;Dollars变量的声明不需要改变。如果不适用类型定义，则需要找到所有用于存储美元数量的
 //float类型变量,并且改变它们的声明的，这比较麻烦



    //使用sizeof 表达式获取允许程序获取存储指定类型的值所需要的内存空间
    //其中(unsigned long)强制转换类型
    printf("Size of int : %lu\n",(unsigned long )sizeof(int));

}

//int main() {
    //read_write_integer();
    //outOfMemory_sum2_case();
    // signed_unsigned();
    //integer_arithmetic();
    //character_handle_function();
//    type_conversation();
//    return 0;
//}