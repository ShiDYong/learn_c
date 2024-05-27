/**
Created by mason on 2023/5/2.
 第五章：选择语句课后练习题
 */
#include<stdio.h>

/**
 Exercise 5.01
The following program fragments illustrate the relational and equality
operators. Show the output produced by each, assuming that `i`, `j`, and `k` are
`int` variables.
 */
void exec05_01() {
    int i, j, k;
    //a.
    i = 2, j = 3;
    //查看书本附录A可知:判等运算符:== !=和乘法运算符：/ * % 都是左结合性，但是
    //优先级，判等运算符排第8而乘法运算符排第3。判等运算符产生0(假)或1(真)作为结果
    //因此算术运算符优先级最高，因此先计算i*j,得到结果6，第二步进行判等运算，结果为真，最后
    //执行赋值运算，修改k的值为1
    k = i * j == 6;
    printf("%d\n", k);

    //b.
    i = 5, j = 10, k = 1;
    //关系运算符：< > <= >= 也是左结合型，优先级排7，高于判等运算符
    //下面这个表达式在C语言中是合法的，但效果可能并不是所期望的，跟俊关系运算符的左结合性

    printf("%d\n", k > i > j);//在C语言中，表达式k > i > j将会被解释为(k > i) > j。首先比较k和i，
    // 即1是否大于5，这是一个假的比较，结果为0；然后将0与j进行比较，即0是否大于10，这同样是一个假的比较，结果为0。
    printf("%d\n", k > i < j);//表达式求值：首先比较k和i，即1是否大于5，这是一个假的比较，结果为0；然后将0与j进行比较，即0是否小于10，这是一个真的比较，结果为1。
    //c.
    i = 3, j = 2, k = 2;
    printf("%d\n", i < j == j < k); //< > <= >= 也是左结合型，优先级排7，高于判等运算符
    //i<j为false（0）,j<也为false(0),所以i<j == j < k等价于：0==0?值是true(1)
    //d.
    i = 3, j = 4, k = 5;
    printf("%d\n", i % j + i < k); //注意各种运算符的优先级
    //表达式运算符的优先级高于关系运算符，关系运算符的优先级高于判等运算符
    //首先i%j =3,3+i=6,6/5值为0，注意i<k关系运算符的优先级低于加法类
}

/**
 * Exercise 5.02
The following program fragments illustrate the logical operators. Show the
output produced by each, assuming that `i`, `j`, and `k` are `int` variables.
 关系运算符和逻辑运算符的综合运用中，需要注意运算符!和一元正负号的优先级相同，运算符&&和｜｜的优先级低于关系运算符和
 判等运算符。
 */
void exec05_02() {
    int i, j, k;
    //a.
    i = 10, j = 5;

    printf("%d\n", !i < j); //关系运算符的优先级低于逻辑非，逻辑非优先级排2且是右结合性
    //首先!i的值0(false),0<5的结果是1(true);
    //b.
    i = 2, j = 1;
    printf("%d\n", !!i + !j);// !!i的值是1，!j的值是0，所以和为：1
    //c.
    i = 5, j = 0, k = -5;
    /**
     * 逻辑运算符：
     * 1.逻辑非!：如果表达式的值为0，那么!表达式的结果为1；
     * 2.逻辑与&&:如果表达式1和表达式2的值都是非零值，那么表达式1&&表达式2的结果为1；
     * 3.逻辑或||:如果表达式1或表达式2的值一个是(或者两个都是)非零值，那么表达式1||表达式2的结果为1
     * 逻辑非!的优先级排2是右结合性，逻辑与&&排12且是左结合性，逻辑或||优先级排13也是左结合性
     */
    printf("%d\n", i && j || k);//根据上面的定义可知:i,j,k都是大于0，所以结果为1
    /**
     * 运算符&&和运算符||都对操作数进行“短路”计算。也就说运算符首先计算左操作数的值，然后计算右操作数的值。
     * 如果表达式的值可以仅由左操作数的值推导出来，那么将不需要计算右操作数的值
     */

    //d.
    i = 1, j = 2, k = 3;
    printf("%d\n", i < j || k); //1

}

/**
 * Exercise 5.03
    The following program fragments illustrate the short-circuit behavior of logical
    expressions. Show the output produced by each, assuming that `i`, `j`, and `k`
    are `int` variables.

 */
void exec05_03() {
    int i, j, k;
    //a.
    i = 3, j = 4, k = 5;
    printf("%d\n", i < j || ++j < k); //1
    printf("%d\n", ++j < k || i < j); //1
    printf("%d%d%d\n", i, j, k);
    //b.
    i = 7, k = 8, j = 9;
    printf("%d\n", i - 7 && j++ < k); //0
    printf("%d%d%d\n", i, j, k);
    //c.
    i = 7, j = 8, k = 9;
    printf("%d\n", (i = j) || (j = k));
    printf("%d%d%d\n", i, j, k); //889  主要考虑短路的计算
    //d.
    i = 1, j = 1, k = 1;
    printf("%d\n", ++i || ++j && ++k);
    printf("%d%d%d\n", i, j, k); //211

}

/**
 Exercise 5.04
Write a single expression whose value is either -1, 0 or +1, depending on
whether `i` is less than, equal to, or greater than `j`, respectively.
 */
void exec05_04() {

    int i, j;
    //int result = i > j ? 1 : (i < j ? -1 : 0);
    //为了提高可读性，使用条件表达式来实现
    int result = (i > j) ? 1 : ((i < j) ? -1 : 0);


}

/**
 Exercise 5.05
Is the following `if` statement legal?
c
if (n >= 1 <= 10)
    printf("n is between 1 and 10\n");
If so, what does it do when `n` is equal to 0?
 */

void exec05_05() {
    /*The if statement you provided is legal in C, but it doesn't work as intended to
     * check if n is between 1 and 10. The problem lies in the expression (n >= 1 <= 10).
     * In C, relational operators like >= and <= have left-to-right associativity. So,
     * the expression is evaluated from left to right. Here's how it's evaluated:n >= 1 is
     * evaluated first. If n is greater than or equal to 1, this expression evaluates to 1 (true).
     * If n is less than 1, this expression evaluates to 0 (false).Then, the result of the first
     * comparison is compared to 10. So, if n is greater than or equal to 1, the second comparison
     * becomes 1 <= 10, which is always true. If n is less than 1, the second comparison becomes 0 <= 10,
     * which is also true.Therefore, regardless of the value of n, the printf statement will
     * always execute when this if statement is encountered.To fix this and make the if statement
     * correctly check if n is between 1 and 10, you should use logical AND (&&) to combine the two conditions:
    if (n >= 1 && n <= 10)
    printf("n is between 1 and 10\n");

*/
    int n = 0;
    if (n >= 1 <= 10) {
        printf("n is between a and 10\n"); //执行后编译通过的,但是让人疑惑
    }
    //如果是合法的，那么当n等于0时会发生什么？
    //依然可以编译运行，因为这个根据的左结合性，n>=1结果是false(0),但是1<=10返回结果是true(1)
}

/**
 * Exercise 5.06
Is the following `if` statement legal?
```c
if (n == 1-10)
    printf("n is between 1 and 10\n");
```
If so, what does it do when `n` is equal to 5?

 */
void exec05_06() {
    int n = 5;
    if (n == 1 - 10)  //根据优先级：加法类高于判等运算符==》1-10=-9,n==-9?,因为n没有初始化值，所以无法比较
        printf("n is between a and 10\n");//n的值为-9才会执行这个操作，所以这个编译通过可以运行，但是让人疑惑的
    //如果合法，那么当n等于5时会发生什么？
    //if语句的逻辑表达式为假，因此不会执行紧接着的printf语句
}

/**
 * Exercise 5.07
What does the following statement print if `i` has the value 17? What does it
print if `i` has the value -17?
```c
printf("%d\n", i >= 0 ? i : -i);
 */
void exec05_07() {
    int i;
    i = 17;
    printf("%d\n", i >= 0 ? i : -i);//17
    i = -17;
    printf("%d\n", i >= 0 ? i : -i);
}

/**
 * Exercise 5.08
The following `if` statement is unnecessarily complicated. Simplify it as much
as possible. (*Hint*: The entire statement can be replaced by a single
assignment.)
```c
if (age >= 13)
    if (age <= 19)
        teenager = true;
    else
        teenager = false;
else if (age < 13)
    teenager = false;
 */
void exec05_08() {
    int age;
    _Bool teenager;
    if (age >= 13 && age <= 19)
        teenager = 1;
    else
        teenager = 0;

    //更加简介方式使用三元运算符,条件表达式使程序更短小但也难以阅读，因此最好避免使用，然后，在少数地方
    //任会使用条件表达式，其中一个就是return语句
    teenager = age >= 13 && age <= 19;
}

/**
 * Exercise 5.09
Are the following `if` statements equivalent? If not, why not?
```c
if (score >= 90)       if (score < 60)
    printf("A");           printf("F");
else if (score >= 80)  else if (score < 70)
    printf("B");           printf("D");
else if (score >= 70)  else if (score < 80)
    printf("C");           printf("C");
else if (score >= 60)  else if (score < 90)
    printf("D")            printf("B");
else                   else
    printf("F");           printf("A");
```
 */
void exec05_09() {
    //两条if级联语句的输出结果相同，但是不能认为它们是相等的。
    //因为两者的逻辑判断顺序和结构不同，只是一种算法的两种实现
}

/**
 *  Exercise 5.10
What output does the following program fragment produce? (Assume that `i` is an
integer variable.)
```c
i = 1;
switch (i % 3) {
    case 0: printf("zero");
    case 1: printf("one");
    case 2: printf("two");
}
```
 */
void exec05_10() {
    int i = 1;
    switch (i % 3) {
        case 0:
            printf("zero");
        case 1:
            printf("one");
        case 2:
            printf("two");
            //  default:
            //    printf("four");
    }
    /*
     * 首先，我们需要计算 i % 3 的值。当 i = 1 时，i % 3 的结果是 1。
     * 然后，根据 switch 语句中的 case 语句进行匹配。在这个 switch 语句中，没有 break 语句，
     * 因此匹配成功的 case 之后的所有代码都会被执行，直到遇到 break 或者 switch 语句结束。
     * 因此，当 i = 1 时，程序的输出将是，这是因为 case 1 匹配成功，打印出 "one"，然后继续执行下一个 case 2，打印出 "two"。
     */
}

/**
 Exercise 5.11
    The following table shows telephone area codes in the state of Georgia along
    with the largest city in each area:

    | *Area code* | *Major city* |
    | :---: | :---: |
    | 229 | Albany |
    | 404 | Atlanta |
    | 470 | Atlanta |
    | 478 | Macon |
    | 678 | Atlanta |
    | 706 | Columbus |
    | 762 | Columbus |
    | 770 | Atlanta |
    | 912 | Savannah |

    Write a `switch` statement whose controlling expression is the variable
    `area_code`. If the value of `area_code` is in the table, the `switch` statement
    will print the corresponding city name. Otherwise, the `switch` statement will
    display the message `"Area code not recognized"`. Use the techniques discussed
    in Section 5.3 to make the `switch` statement as simple as possible.
 *
 */
void exec05_11() {
    int area_code;
    printf("Please enter one area code: ");
    scanf("%d", &area_code);
    switch (area_code) {
        case 229:
            printf("Albany");
            break;
        case 404:
        case 470:
        case 678:
        case 770:
            printf("Atlanta");
            break;
        case 478:
            printf("Macon");
            break;
        case 706:
        case 762:
            printf("Columbus");
            break;
        case 912:
            printf("Savannah");
            break;
        default:
            printf("Area code not recognized");
            break;
    }


}


//int main() {
//    // exec05_01();
//    //exec05_02();
//    // exec05_03();
//    // exec05_05();
//   // exec05_07();
//  // exec05_10();
//  exec05_11();
//    return 0;
//}