/**
Created by mason on 2023/5/20.
 第6章：循环语句课后编程题
*/
#include <stdio.h>

/**
 * 1.编写程序，找出用户输入的一串数中的最大数。程序需要提示用户输入一个一个地输入数。当用户输入0或负数时，程序必须
 * 显示出已输入的最大非负数：
 * Enter a number: 60
 * Enter a number: 38.3
 * Enter a number: 4.89
 * Enter a number: 100.62
 * Enter a number: 75.2295
 * Enter a number: 0
 * The largest number entered was 100.62
 *
 */
void exec6_1() {
    //这里要使用浮点数，用户输入的是负数时会出现问题:要谨慎处理
    // Enter a number: -1
    //The largest number entered was 536870912
    float n, max = 0.00f;
    do {
        printf("Enter a number: ");
        scanf("%f", &n);
        max > n ? max : (max = n);
    } while (n > 0);
    printf("The largest number entered was %0.2f\n", max);
}

/**
 * 编程练习2:编写程序，要求输入两个整数，然后计算并显示这两个整数的最大公约数(GCD)：
 * Enter two integers: 12 34
 * Greatest common divisor: 4
 * 求最大公约数的经典算法是Euclid算法:分别让变量m和变量n存储两个数的值。如果n为0，那么停止操作，m中的
 * 值是GCD;否则计算m除以n的余数，把n保存到m中，并把余数保存到n中。然后重复上述过程，每次都先判定n是否为0
 */
int exec6_2(int n, int m) {
    int r;
    // printf("Enter two divisor: ");
    //scanf("%d %d", &n, &m);
    while (n != 0) {
        r = m % n;
        m = n;
        n = r;  //需要借助第三个变量进行储存,方便进行交换两个变量的值
    }
    printf("Greatest common divisor: %d", m);
    return m;
}

/**
 * 编程练习3:编写程序，要求用户输入一个分数，然后将其约分为最简分式子
 * Enter a fraction: 6/12
 * In lowest terms: 1/2
 * 提示：为了把分数约分为最简分式，首先计算分子和分母的最大公约数，然后分子和分母都除以最大公约数。
 */
void exec6_3() {
    int a, b, common;
    printf("Enter two divisor: ");
    scanf("%d/%d", &a, &b);
    //充分利用编程二求取最大公约数的方法重复利用
    common = exec6_2(a, b);
    printf("In lowest terms: %d/%d\n", a / common, b / common);

}

/**
 * 课后编程练习04:在5.2节的broker.c的程序中添加循环，以便用户可以输入多笔交易，并且程序可以计算每次的佣金。
 * 程序在用户输入的交易额为0时终止。
 */
void exec6_04() {
    float trade, commission;
    for (;;) {
        printf("Enter value of trade: ");
        scanf("%f", &trade);
        if (trade <= 0)//当用户输入的交易额为0时终止程序,结合实际业务逻辑来看
            break;
            //注意是浮点数要保留2位,同时要注意表中的1.7%、0.66%转化为小数点时不要出错
        else if (trade < 2500.00f)
            commission = 30.00f + trade * 0.017f;
            /* else if(trade >= 2500.00f && trade < 6250.00f)
                 commission = 56.00f + trade * 0.0066f;
                 注意上这种写法是多余的。如果第一个if字句的trade的值小于2500则计算佣金，
                 当到达第二个if测试时，trade不可能小于2500，因此一定大于2500，条件trade>=
                 2500.00f总是为真，因此加上这个条件是没有意义的,
                 if语句和switch语句允许程序在一组可选项中选择一条特定的执行路径；
                 */
        else if (trade < 6250.00f)
            commission = 56.00f + trade * 0.0066f;
        else if (trade < 20000.00f)
            commission = 76.00f + trade * 0.0034f;
        else if (trade < 50000.00f)
            commission = 100.00f + trade * 0.0022f;
        else if (trade < 500000.00f)
            commission = 155.00f + trade * 0.0011f;
        else
            commission = 255.00f + trade * 0.0009f;
        if (commission < 39.00f)
            commission = 39.00f;
        printf("Commission is:$%.2f\n", commission);

    }


}

/**
 *  使用while语句替换，刚开始可能觉得不合适，但是根据题目结合实际生活中的场景来看，输入的交易小于等于0都要停止程序的
 *  实现的方法二：while语句实现
 */
void exec6_04_02() {
    float commission, value;

    printf("Enter value of trade: ");
    scanf("%f", &value);

    while (value > 0) {

        if (value < 2500.00f)
            commission = 30.00f + .017f * value;
        else if (value < 6250.00f)
            commission = 56.00f + .0066f * value;
        else if (value < 20000.00f)
            commission = 76.00f + .0034f * value;
        else if (value < 50000.00f)
            commission = 100.00f + .0022f * value;
        else if (value < 500000.00f)
            commission = 155.00f + .0011f * value;
        else
            commission = 255.00f + .0009f * value;

        if (commission < 39.00f)
            commission = 39.00f;

        printf("Commission: $%.2f\n\nEnter value of trade: ", commission);
        scanf("%f", &value);//确实能实现循环，但是这里却有点疑惑，为什么还要在这里放置获取输入值的函数
    }

}


/**
 * 第四章编程1要求编写程序显示出两位数的逆序。设计一个更具一般性的程序，可以处理一位、两位、三位或者更多位
 * 的数。提示：使用do循环将输入的数重复除以10，直到值达到0为止。
 */
void exec6_05() {
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    do {
        //根据取余获取最后一个数字
        printf("%d", n % 10);
        n /= 10;
    } while (n != 0);
    printf("\n");


}

/**
 * 编写程序，提示用户输入一个数n，然后显示出1～n的所有偶数平方值。例如，如果用户输入100，那么程序应该显示出下列内容：
 * 4
 * 16
 * 36
 * 64
 * 100
 */
void exec06_06() {
    int n, d;
    printf("Enter a integer: ");
    scanf("%d", &n);
    for (d = 1; d * d <= n; ++d) {
        if (d % 2 == 0)
            printf("%d\n", d * d);
        //另外一个写法
//        if((d*d) % 2 !=0)
//            continue;
//        printf("%d\n", d * d);

    }
}

/**
 * 课后编程练习07:重新安排程序square3.c，在for循环中对变量i进行初始化、判定以及自增操作。不需要重写程序，特别是不要使用任何乘法
 */
void exec06_07() {
    int i, n, odd, square;

    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);

    odd = 3;
    for (i = 1, square = 1; i <= n; odd += 2, ++i) {
        printf("%10d%10d\n", i, square);
        square += odd;
    }
}

/**
 * 课后编程练习题8:编写程序显示单月的日历。用户指定这个月的天数和该月的起始日时星期几：
 * Enter number of in month: 31
 * Enter starting day of the week (1=Sum,7=Sat):3
 * 提示：此程序不像看上去那么难。最重要的部分是一个使用变量i从1到n的for语句(这里n是次月的天数),for语句中需要显示i的每个值。
 * 在循环中，用if语句判定i是否是一个星期的最后一天，如果是，就显示换一个换行符.
 */
void exec06_08() {
    int n, day, weekday, i;
    printf("Enter number of in month(1-31): ");
    scanf("%d", &n);
    printf("Enter starting day of the week(1=Sum,=Sat): ");
    scanf("%d", &weekday);
    printf("\n Mo Tu We Th Fr Sa Su\n");
    for (i = 1, day = 1; i <= n + weekday - 1; ++i) {
        if (i < weekday)
            printf("   ");
        else
            printf("%3d", day++);
        if (i % 7 == 0)
            printf("\n");
    }
    printf("\n");

}

/**
 * 课后编程练习09:第二章的编程题8要求编程第一、第二、第三个月还贷后剩余的贷款金额。修改该程序，要求用户输入还贷的次数并显示每次还贷后剩余
 * 的贷款金额.
 */

void exec06_09() {
    float loan = 0.0f, interest_rate = 0.0f, monthly_payment = 0.0f;
    int number;
    printf("Please enter amount of load: ");
    scanf("%f", &loan);
    printf("Please enter interest_rate: ");
    scanf("%f", &interest_rate);
    printf("Please enter monthly_payment: ");
    scanf("%f", &monthly_payment);
    printf("Please enter number of payload: ");
    scanf("%d", &number);
    for (int i = 1; i <= number; ++i) {
        loan = loan - monthly_payment + (loan * interest_rate / 100.0 / 12.0);
        printf("Balance remaining after %d payment: $%.2f\n", i, loan);
    }


}

/**
 * 第五章的编程题9要求编写程序判断哪个日期更早。泛化该程序，使用户可以输入任意个日期。用0/0/0指示输入结束，不再输入日期
 * Enter a date(mm/dd/yy):3/6/08
 * Enter a date(mm/dd/yy):5/17/07
 * Enter a date(mm/dd/yy):0/0/0
 * 5/17/07 is the earliest date.
 */
void exec6_10() {
    //这个题目处理的很巧妙
    int d1, d2, m1, m2, y1, y2;
    printf("Enter a date(mm/dd/yy): ");
    scanf("%d /%d /%d", &m1, &d1, &y1);
    while (1) {
        printf("Enter a date(mm/dd/yy): ");
        scanf("%d/%d/%d", &m2, &d2, &y2);
        if (m2 == 0 && d2 == 0 && y2 == 0)
            break;
        if (y2 < y1 || (y2 = y1 && m2 < m1) || (y2 == y1 && m2 == m1 && d2 < d1)) {
            d1 = d2;
            m1 = m2;
            y1 = y2;
        }

    }
    printf("%d/%d/%.2d is the earliest date\n", m1, d1, y1);

}

/**
 * 课后编程练习11题：数学常量e的值可以用一个无穷数表示：
 * e = 1 + 1/1! + 1/2! + 1/3!+...
 * 编写程序，用下列的公示计算e的近似值：
 * 1+1/1!+1/2!+1/3!+...+1/n!
 * 这里n是用户输入的整数.
 */
void exec6_11() {
    int i, n, denom;
    float e;

    printf("Enter integer n: ");
    scanf("%d", &n);

    for (i = 1, denom = 1, e = 1.0f; i <= n; i++) {
        e += 1.0f / (denom *= i);
    }
    printf("Approximation of e: %f\n", e);

}

/**
 * 课后编程练习12:修改编程题目11，使得程序继续执行加法运算，直到当前项小于$为止，其中$是用户输入的较小的(浮点数)
 */
void exec6_12() {

    int i, denom;
    float e, epsilon, term;

    printf("Enter epsilon: ");
    scanf("%f", &epsilon);
    for (i = 1, denom = 1, e = 1.0f, term = 1.0f; term > epsilon; i++) {
        term = (1.0f / (denom *= i));
        e += term;
    }
    printf("Approximation of e: %f\n", e);
}

//int main() {
    //exec6_1();
    // exec6_2(13,39);
    //exec6_3();
    // exec6_04_02();
    //exec6_05();
    // exec06_06();
    //exec06_07();
    // exec06_08();
    //exec06_09();
    //exec6_10();
//    exec6_11();
//    return 0;
//}