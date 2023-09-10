/**
 Created by mason on 2023/4/30.
 第二章C语言基本概念的课后编程练习题目1-8
*/
#include <stdio.h>

#define SPHERE_VOLUME (4.0f / 3.0f * 3.1415926f)
#define TOTAL_TAX_RATE (1.05f)

/**
 编程练习01：编写一个程序，使用printf在屏幕上现实下面的图形
       *
      *
     *
*   *
 * *
  *

*/
void exec_1(void) {
    printf("       *\n");
    printf("      *\n");
    printf("     *\n");
    printf("*   *\n");
    printf(" * *\n");
    printf("  *\n");
}

/**
 Created by mason on 2023/4/30.
 编写一个程序计算球体体积的程序2-3
*/
void exec_2_3(void) {
    float radius, volume;
    printf("Please enter sphere radius: ");
    scanf("%f", &radius);
    volume = SPHERE_VOLUME * radius * radius * radius;
    printf("Sphere volume: %.3f cubic meters\n", volume);

}

/**
 Created by mason on 2023/4/30.
 案例4:编写一个程序，要求用户输入一个美元数额，然后显示出增加%5税率后的相应金额
*/
int exec_4(void) {
    float price = 0.0f;
    float total_money;
    printf("Please enter an account: ");
    scanf("%f", &price);
    total_money = TOTAL_TAX_RATE * price;
    printf("With tax added: $%.2f\n", total_money);
}


/**
 Created by mason on 2023/4/30.
 案例5:编程要求用户输入x的值，然后显示如下多项士的值
*/

void exec_05(void) {
    int x, result;
    printf("Please enter x value: ");
    scanf("%d", &x);
    result = (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6;
    printf("result:%d\n", result);
}


/**
 *多项式求值Homer法则
 * 优化案例的写法，减少乘法次数
 */
void exec_06(void) {

    int x, result;
    printf("Please enter x value: ");
    scanf("%d", &x);
    result = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("Homer rule result:%d\n", result);

}


/**
 * 案例7:编写一个程序，要求用户输入一个美元数额，然后显示出如何用最少张数的20美元、10美元、5美元和1美元钞票来付款：
 * 确保在程序中始终使用整数值，而不是浮点数
 */

void exec_7_1(void) {
    int money;
    int num_20 = 0;
    int num_10 = 0;
    int num_5 = 0;
    int num_1 = 0;
    printf("Please enter a dollar amount: ");
    scanf("%d", &money);
    if (money >= 20) {
        num_20 = money / 20;
        money -= 20;
    }
    if (money >= 10) {
        num_10 = money / 10;
        money -= 10;
    }
    if (money >= 5) {
        num_5 = money / 5;
        money -= 5;
    }
    if (money >= 1) {
        num_1 = money / 1;
        money -= 1;
    }
    printf("$20 bills: %d\n", num_20);
    printf("$10 bills: %d\n", num_10);
    printf("$5 bills: %d\n", num_5);
    printf("$1 bills: %d\n", num_1);

}

/**
 * 对exec_7_1进行优化
 */
void exec_7_2(void) {
    int money;
    printf("Please enter a dollar amount: ");
    scanf("%d", &money);
    printf("$20 bills: %d\n", money / 20);
    money -= 20 * (money / 20);
    printf("$10 bills: %d\n", money / 10);
    money -= 10 * (money / 10);
    printf(" $5 bills: %d\n", money / 5);
    money -= 5 * (money / 5);
    printf(" $1 bills: %d\n", money);

}

/**
 * 案例8:编程计算第一、第二、第三个月还贷后剩余的贷款总额
 * 在显示每次还款后的余额时保留两位小时.提示：每个月的贷款余额减去还款金额后，
 * 还需要加上贷款余额与月利率的乘积。月利率的计算方法是把用户输入的利率转换成百分数再处以12.
 * @return
 */
void exec_8(void) {
    float loan = 0.0f, interest_rate = 0.0f, monthly_payment = 0.0f;
    printf("Please enter amount of load: ");
    scanf("%f", &loan);
    printf("Please enter interest_rate: ");
    scanf("%f", &interest_rate);
    printf("Please enter monthly_payment: ");
    scanf("%f", &monthly_payment);

    loan = loan - monthly_payment + (loan * interest_rate / 100.0 / 12.0);
    printf("Balance remaining after first payment: $%.2f\n", loan);


    loan = loan - monthly_payment + (loan * interest_rate / 100.0 / 12.0);
    printf("Balance remaining after second payment: $%.2f\n", loan);

    loan = loan - monthly_payment + (loan * interest_rate / 100.0 / 12.0);
    printf("Balance remaining after third payment: $%.2f\n", loan);


}


//int main(void) {
//    // exec_7_1();
//    //exec_7_2();
//    exec_8();
//}


