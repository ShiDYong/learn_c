/********************************************************************************
* @author: mason shi
* @date: 2024/2/25 17:14
* @version: 1.0
* @description: 
********************************************************************************/
#include<stdio.h>

/*
 * Exercises 3.01
 * What output do the following calls of 'printf' product?
 */
void exec_test01() {
    printf("%6d, %4d\n", 86, 1040);
    printf("%12.5e\n", 30.253);
    printf("%.4f\n", 83.162);
    printf("%-6.2g\n", .0000009979);
    /*%：格式化字符串的起始标记。
        -：表示左对齐输出，即输出的字符串左对齐，右边用空格填充。
        6：表示输出的最小字符宽度为6，即至少输出6个字符宽度，如果输出的字符不足6个，则在左边用空格填充。
        .2：表示精度为2，即小数点后保留2位有效数字。
        g：表示浮点数格式，根据值的大小自动选择使用%e或%f的输出格式，以较短的形式输出。
        接下来，我们将0.0000009979按照给定的格式化字符串进行输出：
        小数点后保留2位有效数字，而0.0000009979有7位有效数字，因此它会被四舍五入为0.000001。
        输出的宽度为6，但小数点和数字共占据了7个字符的位置，所以输出的结果是7个字符，即"0.000001"。
        因为使用了左对齐（-），所以在输出的数字后面会用空格填充到6个字符的宽度。*/
    //输出：
    /*    86, 1040
 3.02530e+01
83.1620
1e-06 */
}

/*
 * Exercise 3.02
    Write calls of `printf` that display a `float` variable `x` in the following
    formats.
    (a) Exponential notation; left-justified in a field of size 8: one digit after
    the decimal point.
    (b) Exponential notation: right-justified in a field of size 10; six digits
    after the decimal point.
    (c) Fixed decimal notation; left-justified in a field of size 8; three digits
    after the decimal point.
    (d) Fixed decimal notation; right-justified in a field of size 6; no digits
    after the decimal point.
 */
void exec_test02() {
    float x;
    printf("%-8.1e\n", x);
    printf("%10.6e\n", x);
    printf("%-8.3f\n", x);
    printf("%6.0f\n", x);

}

/*
 * Exercise 3.03
    For each of the following pairs of `scanf` format strings, indicate whether
    the two strings are equivalent. If they're not, show how they can be
    distinguished.
    scanf函数读取数据时，只忽略数据前的空白字符，其它无效的输入字符都会导致读取失败。因此
    一般除了转换说明，格式串一般不包含其他形式的字符，例如逗号、冒号等。如果添加来这些字符，用户
    在输入数据时必须严格按照scanf函数中的格式串形式输入.
 */
void exec_test03() {
    int i;
    float f;
    printf("Enter a number: ");
    //scanf("%d", &i);//虽然缺少空格符，但是函数会忽略数据之前的空白，因此最终结果和第二个格式串一样的
    //scanf(" %d", &i);
    //scanf(" % d", &i); 这种输入方式是无效的
    // scanf("%d ", &i);
    /*在这种情况下，格式串以%d结束，并且在%d之后有一个空格字符。这意味着scanf会尝试读取一个整数，
     * 并且在读取整数后期望找到一个额外的空格字符。如果用户在输入整数后输入了空格字符，
     则scanf将会略过它们。但是，如果用户输入数字后直接按下回车键，而不添加额外的空格字符，
     scanf将会等待用户输入更多字符，直到用户输入一个非空格字符或按下Enter键。
     因此，这种方式可能导致程序在用户没有预期的情况下暂停等待输入。
     * */
    scanf("%d-%d-%d\n", &i, &i, &i);
    scanf("%d -%d -%d\n", &i, &i, &i); //推荐使用
    //假设输入以下数据：
    /*
     * a: 45-56-67
     * b: 45.-56.-67
     * c: 45-.56-.67
     * d: 45.-.56.-.67
     * 上面四种输入只有第二种格式化都成功读取到，第一种格式化只有a这种能成功读取到。
     * */
    scanf("%f", &f);
    scanf("%f ", &f);//两者时等价的
    scanf("%f,%f", &f, &f);
    scanf("%f, %f", &f, &f);//两者是等价的
    printf("%d\n", i);
}

/*
 * Exercise 3.04
Suppose that we call `scanf` as follows:
 */
void exec_test04() {
    int x, z;
    float y;
    printf("Enter three numbers: ");
    scanf("%d%f%d", &x, &y, &z);
    //如果输入：10.3 5 6
    //那么输出是多少？:10 0.300000 5
    printf("%d %f %d\n", x, y, z);
    /*
     * scanf函数在处理格式串和用户实际输入字符时的基本方式是依次读取并与格式串中的字符和转换进行对比
     * 如果匹配则进行转换，否则会把不同的数据返回原处，并留给下一次scanf函数调用：
     * 数据输入的完整过程是这样的：用户输入的10可以完整匹配第一个%d转换说明，当读取到小数点时，
     * scanf 将小数点和第一个% d 进行匹配，确认第一个整型数据输入完成，
     * 即x的值为10；然后 scanf 会将小数点和第二个转换说明% f 进行匹配，
     * 匹配成功后继续读取，直到遇到下一个空格，因此将．3作为变量 x 的值。
     * 输入数据5之前的空白被忽略，因此第三个转换说明将5作为变量 j 的值，
     * 最后剩余的字符会被 scanf 放回原处，等待下一次scanf 函数调用。
     * 参考答案最终变量 i 的值为10；变量 x 的值为．3，即0.3；变量 j 的值为5
     * */

}
/*
 *  Exercise 3.05
Suppose that we call `scanf` as follows:
 scanf("%f%d%f", &x, &i, &y);
 If the user enters
 12.3 45.6 789
what will be the values of `x`, `i` and `y` after the call? (Assume that `x` and
`y` are `float` variables and `i` is an `int` variable.)
 */
void exec_test05(){
    //同上一题目
    //输出：
    // x = 12.3
    //i = 45
    //y = 0.6
}

//int main(void) {
//    int i, j;
//    printf("Enter two numbers: "); //输入4,28
//    scanf("%d%d", &i, &j);
//    printf("%d%d\n",i,j); //输出结果却是4,1
    /*分析原因：
     * 为什么在输入4和28后，输出的结果是 "4 1" 呢？
     * 这是因为代码中并没有检查 scanf 函数的返回值。scanf 函数返回成功读取并赋值的参数个数。
     * 在这种情况下，它返回值为1，因为只有第一个输入成功了（也就是4被成功地存储在了变量 i 中），
     * 而第二个输入由于缺少一个逗号而导致失败，因此没有被赋值给 j。
     * 而在C语言中，未初始化的变量会被默认赋值为0，因此变量 j 的值是0，而不是28
     * */
    //针对上面问题的解决方式
//    printf("Enter two numbers: ");
//    scanf("%d,%d", &i, &j);//数与数之间加上逗号来分割
//    printf("%d %d\n", i, j);
    // exec_test01();
    //exec_test02();
    //exec_test03();
//    exec_test04();
//
//    return 0;
//}