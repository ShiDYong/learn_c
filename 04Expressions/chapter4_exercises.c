/**
Created by mason on 2023/5/1.
 第四章：C语言的常用的表达士的课后练习题目
*/
#include<stdio.h>

/**
 * Exercise 4.01
   Show the output produced by each of the following program fragments. Assume that
   `i`, `j`, and `k` are `int` variables.
 */
void exec_01() {
    int i, j, k;
    i = 5, j = 3;
    printf("%d %d\n", i / j, i % j);
    i = 2, j = 3;
    printf("%d\n", (i + 10) % j);
    i = 7, j = 8, k = 9;
    printf("%d\n", (i + 10) % k / j);
    i = 1, j = 2, k = 3;
    printf("%d\n", (i + 5) % (j + 2) / k);
}

/**
 * Exercise 4.02
    If `i` and `j` are positive integers, does `(-i)/j` always have the same value
    as `-(i/j)`? Justify your answer.

 */
void exec_02() {
    //第一种情况是相等的
    int i = 5, j = 3; //在mac上正负数的结果都一样
    printf("(-i) / j的值:%d\n", (-i) / j);  //(-i)/j = (-5)/3 = -1

    printf("-(i/j)的值:%d\n", -(i / j));   //-(i/j) = -(5/3) = -(1) = -1
    //第二种情况
    i = 3, j = 2; //在mac上正负数的结果都一样
    printf("(-i) / j的值:%d\n", (-i) / j);  //(-i)/j = (-2)/3 = 0

    printf("-(i/j)的值:%d\n", -(i / j));   //-(i/j) = -(2/3) = -(0) = 0
    //以上两种情况在macOS系统都是相等的
    /*当除法运算符／和模运算符％用于负操作数时，其结果和 C 语言标准相关。在C89中，如果两个操作数中有一个为负数，
     * 那么除法的结果既可以向上取整也可以向下取整，模运算的结果也是由实现定义的。在C99中，除法的结果总是向0截取，
     * 模运算结果的正负符号与模运算符％左侧操作数的符号相同。 C 语言中的由实现定义是指，最终结果依赖程序在特定平台上编译、
     * 链接和执行所需要的软件，具体实现条件不同，程序的行为可能会稍有差异。程序设计中应当尽量避免由实现定义的行为，
     * 并考虑编译器所支持的 C 语言标准。参考答案表达式（- i )/ j 和﹣( i / j ）求值，如果在C99标准下，
     * 除法的运算结果总是向0截取，因此结果均相同，例如﹣5/3和﹣(5/3）的结果约为﹣1.7和﹣(+1.7)，
     * 向0截取后最终结果为和﹣(+1)。而C89下除法的运算结果既可以向上取整也可以向下取整，
     * 因此可能会不一致。(- i )的结果可能为﹣1或者﹣2,-( i / j ）的结果可确定为﹣1。
     * */


}

/*
 * Exercise 4.03
    What is the value of each of the following expressions in C89? (Give all
    possible values if an expression may have more than one value.)
    (a) 8 / 5
    (b) -8 / 5
    (c) 8 / -5
    (d) -8 / -5
 */
void exec_03() {
    printf("%d\n", 8 / 5);
    printf("%d\n", -8 / 5);
    printf("%d\n", 8 / -5);
    printf("%d\n", -8 / -5);
    /*输出
   （a) 1
    (b) -1 or -2
    (c) -1 or -2
    (d) 1 or 2
     *( a )8/5的结果为1。该表达式的操作数均为正数，因此并不涉及负数的取整问题，均采用向下取整方式，因此结果为1。
     * ( b )-8/5的结果可能为﹣1或者-2，由定义实现。该表达式中负号运算符的优先级高于除法运算符，因此是负数和正数的除法，
     *  结果为负数，C89标准下是由实现定义的。
     * ( c )8/-5的结果可能是﹣1或者﹣2，表达式的具体运算过程和（ b ）类似。
     * ( d )-8/-5的结果是1。该表达式中两个负号运算符的优先级高于除法运算符，因此结果为正数，向下取整结果为1。
     * */

}

/*
 * Exercise 4.04
Repeat Exercise 3 for C99.
 */
void exec_04() {
    /*根据C99标准，除法的结果向0取整，即正数向下取整，负数向上取整；由于不是"由实现定义"的，因此结果是确定的。参考答案( a )8/5的结果为1，向0取整。
     * ( b )-8/5的结果为﹣1，向0取整。
     * ( c )8/-5的结果为﹣1，向0取整。
     * ( d )-8/-5的结果为1，向0取整。*/
    printf("%d\n", 8 / 5);
    printf("%d\n", -8 / 5);
    printf("%d\n", 8 / -5);
    printf("%d\n", -8 / -5);
}

/*
 *  Exercise 4.05
    What is the value of each of the following expressions in C89? (Give all
    possible values if an expression may have more than one value.)
    (a) 8 % 5
    (b) -8 % 5
    (c) 8 % -5
    (d) -8 % -5
 */
void exec_05() {
    printf("8 %% 5 = %d\n", 8 % 5);
    printf("-8 %%5 = %d\n", -8 % 5);
    printf("8 %% -5 = %d\n", 8 % -5);
    printf("-8 %%-5 = %d\n", (-8) % (-5));
    /*在C89标准中，操作数是负数时的除法运算比较容易理解，而操作数是负数时的模运算容易混淆，
     * 对此我们可以通过除法进行转换计算。由于C89和C99都要确保（ a / b )* b + a % b 的结果总是等于 a ，
     * 因此我们可以通过除法运算推算出模运算的结果，这样更加易于理解。
     * 例如，C89标准下﹣9/7的结果可能为﹣1或者﹣2，因此﹣9%7的值可能是﹣2或者5。
     * ( a )8%5的运算结果为3，操作数为整数，结果为余数。
     * ( b ）由于C89下﹣8/5的运算结果为﹣1或者﹣2，因此﹣8%5的运算结果为﹣3或者2。
     * ( c ）由于C89下8/-5的运算结果为﹣1或者﹣2，因此8%-5的运算结果为3或者﹣2。
     * ( d ）由于C89下﹣8/-5的运算结果为1，因此﹣8%-5的运算结果为﹣3。*/
}

/*
 * Exercise 4.06
Repeat Exercise 5 for C99.
 */
void exec_06() {
    printf("8 %% 5 = %d\n", 8 % 5);
    printf("-8 %%5 = %d\n", -8 % 5);
    printf("8 %% -5 = %d\n", 8 % -5);
    printf("-8 %%-5 = %d\n", (-8) % (-5));
/*( a )8%5( b )-8%5( c )8%-5( d )-8%-5习题解析在C99标准中，操作数是负数时的除法运算比较容易理解，均是向0取整。
 * 此时模运算％的运算结果和运算符左侧操作数符号相同，可以沿用（ a / b )* b + a % b 的结果总是等于 a 的定义，推测出模运算的结果。
 * ( a )8%5的运算结果为3，操作数为整数，结果为余数。( b ）由于C99下﹣8/5的运算结果为﹣1，
 * 因此﹣8%5的运算结果为﹣3。( c ）由于C99下8/-5的运算结果为﹣1，因此88-5的运算结果为3。
 * ( d ）由于C99下﹣8/-5的运算结果为1，因此﹣8%-5的运算结果为﹣3。三几步景，把总的结果减去1，相减后的结果除以10取余数，用该月向余法为正*/
}

/**
 * Exercise 4.09
Show the output produced by the following program fragments. Assume that `i`,
`j`, and `k` are `int` variables.
    (a) i = 7; j = 8;
        i *= j + 1;
        printf("%d %d", i, j);
    (b) i = j = k = 1;
        i += j += k;
        printf("%d %d %d", i, j, k);
    (c) i = 1; j = 2; k = 3;
        i -= j -= k;
        printf("%d %d %d", i, j, k);
    (d) i = 2; j = 1; k = 0;
        i *= j *= k;
        printf("%d %d %d", i, j, k);
 */
void exec_09() {
    /*+++++++++++++++++==============运算符列表如下，按照优先级从高到低，即最前面，数字越小的优先级越高，越优先算。
     * 文章连接：https://www.dotcpp.com/course/638
*/
    int i, j, k;
    //  (a)
    i = 7;
    j = 8;
    i *= j + 1;
    printf("a的结果值：%d %d\n", i, j); //63,9
    /*该表达式中算数运算符＋先计算，得到结果9，复合运算符再计算，最终操作数 i 被赋值为63(7*9的运算结果）；
     * 操作数 j 参与的加法运算并未产生赋值的副作用。最终打印结果为6 38*/
    // (b)
    i = j = k = 1;
    i += j += k;
    printf("b的结果值：%d %d %d\n", i, j, k); //3,2,1
    /*复合赋值运算符是右结合的，因此在表达式内需要从右向左运算，操作数 k 并未产生副作用，
     * 因此为1；操作数 j 由于＋＝运算符的副作用得到结果2(1+1的运算结果）；
     * 操作数 i 由于＋＝运算符的副作用得到结果3(1+2的运算结果，2为 j 的值）。最终打印结果为3 2 1
     * */
    //(c)
    i = 1;
    j = 2;
    k = 3;
    i -= j -= k;
    printf("c的结果值：%d %d %d\n", i, j, k);//2,-1,3
    /*操作数 k 的值未产生副作用，始终为3；操作数 j 由于﹣=赋值运算符的副作用被修改为﹣1(2-3的运算结果）；
     * 操作数 i 由于﹣=赋值运算符的副作用被修改为2(1-(-1）的运算结果）。最终打印结果为2-1 3*/
    // (d)
    i = 2;
    j = 1;
    k = 0;
    i *= j *= k;
    printf("d的结果值：%d %d %d\n", i, j, k); //0,0,0
    /*操作数 k 的值未产生副作用，始终为0；操作数 j 由于＊=赋值运算符的副作用被修改为0(1*0的运算结果）；操作数 i 由于＊＝赋值运算符的副作用*/

}

/**
 * Exercise 4.10
Show the output produced by each of the following program fragments. Assume that
`i` and `j` are `int` variables.
    (a) i = 6;
        j = i += i;
        printf("%d %d", i, j);
    (b) i = 5;
        j = (i -= 2) + 1;
        printf("%d %d", i, j);
    (c) i = 7;
        j = 6 + (i = 2.5);
        printf("%d %d", i, j);
    (d) i = 2; j = 8;
        j = (i = 6) + (j = 3);
        printf("%d %d", i, j);
 */
void exec_10() {
    int i, j;
    //a.
    i = 6;
    j = i += i;
    printf("%d %d\n", i, j);
    //b.
    i = 5;
    j = (i -= 2) + 1;
    printf("%d %d\n", i, j);
    //c.
    i = 7;
    j = 6 + (i = 2.5);
    printf("%d %d\n", i, j); //i=2,j=8
    /*首先给变量i赋值为7，然后给变量j赋值为6加上(i=2.5)的结果。在C语言中，赋值表达式的值是被赋的值，因此(i=2.5)的结果是2，
     * 而不是2.5，因为在赋值操作中会将右侧的表达式计算结果转换为左侧变量的类型。
     * 所以，j的值将是6加上2，即8。然后，使用printf函数打印i和j的值。*/
    //d.
    i = 2, j = 8;
    j = (i = 6) + (j = 3);
    printf("%d %d\n", i, j);//6,9
    /*首先将变量i赋值为6，然后将变量j赋值为3。接着，表达式 (i = 6) + (j = 3) 中的两个赋值表达式会先执行，
     * 将i赋值为6，将j赋值为3。然后，这两个赋值表达式的结果分别为6和3，
     * 因此表达式的值为6+3=9。最后，printf函数打印出变量i和j的值。
    */

}

/**
 * Exercise 4.11
Show the output produced by each of the following program fragments. Assume that
`i`, `j`, and `k` are `int` variables.
    (a) i = 1;
        printf("%d ", i++ - 1);
        printf("%d", i);
    (b) i = 10; j = 5;
        printf("%d ", i++ - ++j);
        printf("%d %d", i, j);
    (c) i = 7; j = 8;
        printf("%d ", i++ - --j);
        printf("%d %d", i, j);
    (d) i = 3; j = 4; k = 5;
        printf("%d ", i++ - j++ + --k);
        printf("%d %d %d", i, j, k);
 */
void exec_11() {
    int i, j, k;
    //a.
    i = 1;
    printf("%d\n", i++ - 1);//0
    printf("%d\n", i);//2
    //b.
    i = 10, j = 5;
    printf("%d\n", i++ - ++j);//4
    printf("%d %d\n", i, j); //11,6
    //c.
    i = 7, j = 8;
    printf("%d\n", i++ - --j);//7-7=0，然后i=i+1=8
    printf("%d %d\n", i, j); //8,7
    //d.
    i = 3;
    j = 4;
    k = 5;
    printf("%d ", i++ - j++ + --k);
    printf("%d %d %d", i, j, k);
    /*首先，将 i 赋值为 3，j 赋值为 4，k 赋值为 5。
    在第一个 printf 语句中，表达式 i++ - j++ + --k 会按照运算符优先级和结合性计算。
    --k 先执行，k 变为 4，表达式变为 i++ - j++ + 4。
    i++ 和 j++ 是后缀自增运算符，所以它们的值在整个表达式计算完成后才会自增。
    因此，现在表达式的值是 3 - 4 + 4，结果为 3 - 4 + 4 = 3。
    第一个 printf 输出 3。
    第二个 printf 输出 i, j, k 的值。
    由于 i 和 j 是后缀自增运算符，它们的值在前一个表达式求值之后才会增加，因此 i 变成了 4，j 变成了 5。
    k 已经在前一个表达式中执行了 --k 操作，所以 k 的值为 4。
    因此，第二个 printf 输出的结果是 4 5 4。*/
}

/**
 * Exercise 4.12
Show the output produced by each of the following program fragments. Assume that
`i` and `j` are `int` variables.
    (a) i = 5;
        j = ++i * 3 - 2;
        printf("%d %d", i, j);
    (b) i = 5;
        j = 3 - 2 * i++;
        printf("%d %d", i, j);
    (c) i = 7;
        j = 3 * i-- + 2;
        printf("%d %d", i, j);
    (d) i = 7;
        j = 3 + --i * 2;
        printf("%d %d", i, j);
 */
void exec_12() {
    int i, j;
    //a.
    i = 5;
    j = ++i * 3 - 2; //i=6,6*3=18,18-2=16
    printf("%d %d\n", i, j);
    //b.
    i = 5;
    j = 3 - 2 * i++; //3 -2*5=-7,i++=6
    printf("%d %d\n", i, j);
    //c.
    i = 7;
    j = 3 * i-- + 2;
    printf("%d %d\n", i, j);
    /*i 被赋值为 7。然后，j 被计算为 3 * i-- + 2。这里需要注意的是 i-- 表示先使用 i 的当前值进行计算，然后再将 i 减1。
     * 所以，j 的计算过程是 3 * 7 + 2，得到 j 的值为 23。
     * 但是由于 i-- 中的后缀自减操作，i 的值在使用之后被减1，所以 i 的值变成了 6。*/
    //d.
    i = 7;
    j = 3 + --i * 2; //3+(7-1)*2=15
    printf("%d %d\n", i, j);

}

/**
 * Exercise 4.13
  Only one of the expressions `++i` and `i++` is exactly the same as `(i += 1)`;
  which is it? Justify your answer.
 */
void exec_13() {
    /*In C code, the expression ++i is exactly the same as (i += 1).
Here's why:
++i: This is the pre-increment operator. It increments the value of i and then returns
     the updated value. So, ++i increments the value of i by 1, and then the updated value is returned.
(i += 1): This is the compound assignment operator combined with the addition operator.
     It adds 1 to the value of i and stores the result back into i. Then, it returns the updated value of i.
    Both expressions ++i and (i += 1) directly increment the value of i by 1,
     and they both evaluate to the updated value of i. Therefore, they are exactly the same.
*/
    int i = 1;
    // ++i;    //2
    // i++;       //i++表达式运行后再打印就变成了2
    i += 1;
    printf("i的结果：%d\n", i); //
    /*习题解析 C 语言中的自增运算符、自减运算符和赋值运算符都会产生副作用，但是产生副作用的时间点不同。
     * 通常 C 语言用"顺序点"来界定副作用时间点，指出"应该在上一个顺序点和下一个顺序点之间对存储的操作数的值进行更新"。
     * 因此表达式＋+ i 和 i ++中前缀运算符产生副作用先于后缀运算符。虽然最终都会产生赋值效果，
     * 但是两个表达式的值并不相同；只有＋+ i 与表达式（ i +=1）相，
     * 表达式的值为（ i +1)，而 i +＋表达式的值为 i 。表达式＋+ i 与表达式（ i +=1）含义相同*/

}

/**
 Exercise 4.14
Supply parentheses to show how a C compiler would interpret each of the
    following expressions.
    (a) a * b - c * d + e
    (b) a / b % c / d
    (c) - a - b + c - + d
    (d) a * - b / c - d
 */
void exec_14() {
    /**
    (a) (((a * b) - (c * d)) + e)
    (b) (((a / b) % c) / d)
    (c) ((((- a) - b) + c) - (+ d))
    (d) (((a * (- b)) / c) - d)
    */

}

/*
 * Exercise 4.15
Give the values of `i` and `j` after each of the following expression statements
has been executed. (Assume that `i` has the value 1 initially and `j` has the
value 2.)
    (a) `i += j;`
    (b) `i--;`
    (c) `i * j / i;`
    (d) `i % ++j;`
 */
void exec_test15() {
    //(a) `i += j;`

    // (b) `i--;`
    // (c) `i * j / i;`
    // (d) `i % ++j;`
}

int main() {
    // exec_01();
    //exec_02();
    //exec_03();
    //exec_05();
    // exec_09();
    //exec_10();
    // exec_11();
    //exec_12();
    //exec_13();
    return 0;
}








