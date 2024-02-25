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
    Project 1.02
    Write a program that computes the volume of a sphere with a 10-meter radius,
    using the formula v = 4/3πr³. Write the fraction 4/3 as `4.0f/3.0f`. (Try
    writing it as `4/3`. What happens?) Hint: C doesn't have an exponentiation
    operator, so you'll need to multiply r by itself twice to compute r³.
    Project 2.03
    Modify the program of Programming Project 2 so that it prompts the user to enter
    the radius of the sphere.
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
Project 2.04
Write a program that asks the user to enter a dollars-and-cents amount, then
displays the amount with a 5% tax added:
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
Project 2.05
Write a program that asks the user to enter a value for x and then displays the
value of the following polynomial:
3x<sup>5</sup> + 2x<sup>4</sup> - 5x<sup>3</sup> - x<sup>2</sup> + 7x - 6
*Hint*: C doesn't have an exponentiation operator, so you'll need to multiply x
by itself repeatedly in order to compute the powers of x. (For example, `x * x *
x` is `x` cubed.)
 */

void exec_05(void) {
    int x, result;
    printf("Please enter x value: ");
    scanf("%d", &x);
    result = (3 * x * x * x * x * x) + (2 * x * x * x * x) - (5 * x * x * x) - (x * x) + (7 * x) - 6;
    printf("result:%d\n", result);
}


/**
 Project 2.06
 Modify the program of Programming Project 5 so that the polynomial is evaluated
 using the following formula:
 ((((3x + 2)x-5)x-1)x+7)x-6
 Note that the modified program performs fewer multiplications. This technique
 for evaluating polynomials is known as ***Horner's Rule***.
 */
void exec_06(void) {

    int x, result;
    printf("Please enter x value: ");
    scanf("%d", &x);
    result = ((((3 * x + 2) * x - 5) * x - 1) * x + 7) * x - 6;
    printf("Homer rule result:%d\n", result);

}


/**
      Project 2.07
    Write a program that asks the user to enter a U.S. dollar amount and then shows
    how to pay that amount using the smallest number of $20, $10, $5 and $1 bills:
    Enter a dollar amount: 93
    $20 bills: 4
    $10 bills: 1
     $5 bills: 0
     $1 bills: 3
    *Hint*: Divide the amount by 20 to determine the number of $20 bills needed, and
    then reduce the amount by the total value of the $20 bills. Repeat for the
    other bill sizes. Be sure to use integer values throughout, not floating-point
    numbers.
 */
void exec_7_1(void) {
    int amount, twenties, tens, fives, ones;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);
    twenties = amount / 20;
    amount -= twenties * 20;
    tens = amount / 10;
    amount -= tens * 10;
    fives = amount / 5;
    amount -= fives * 5;
    ones = amount;
    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf("$5 bills: %d\n", fives);
    printf("$1 bills: %d\n", ones);
}

/**
 * 对exec_7_1进行优化
 */
void exec_7_2(void) {
    int amount, twenties, tens, fives, ones;
    printf("Enter a dollar amount: ");
    scanf("%d", &amount);
    twenties = amount / 20;
    amount %= 20;
    tens = amount / 10;
    amount %= 10;
    fives = amount / 5;
    amount %= 5;
    ones = amount;
    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf("$5 bills: %d\n", fives);
    printf("$1 bills: %d\n", ones);
}

/**
 Project 2.08
    Write a program that calculates the remaining balance on a loan after the first,
    second, and third monthly payments:
    ```
    Enter amount of loan: 20000.00
    Enter interest rate: 6.0
    Enter monthly payment: 386.66

    Balance remaining after first payment: $19713.34
    Balance remaining after second payment: $19425.25
    Balance remaining after third payment: $19135.71
    ```
    Display each balance with two digits after the decimal point. *Hint*: Each
    month, the balance is decreased by the amount of the payment, but increased by
    the balance times the monthly interest rate. To find the monthly interest rate,
    convert the interest rate entered by the user to a percentage and divide it by
 */
void exec_8_1(void) {
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

/**
 * 优化写法一：把利率提取出来，避免代码的重复
 */
void exec8_2() {
    double loan_amount, interest_rate, monthly_payment, balance;
    printf("Enter amount of loan: ");
    scanf("%lf", &loan_amount);
    printf("Enter interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%lf", &monthly_payment);

    //将利率转换为月利率
    interest_rate /= 100.0;
    double monthly_rate = interest_rate / 12.0;
    balance = loan_amount;
    balance = balance - monthly_payment + (balance * monthly_rate);
    printf("Balance remaining after first payment: $%.2lf\n", balance);
    balance = balance - monthly_payment + (balance * monthly_rate);
    printf("Balance remaining after second payment: $%.2lf\n", balance);
    balance = balance - monthly_payment + (balance * monthly_rate);
    printf("Balance remaining after third payment: $%.2lf\n", balance);


}

/**
 * 针对上面写法再进一步优化
 */
void exec8_3() {
    double loan_amount, interest_rate, monthly_payment;
    int months = 3;
    printf("Enter amount of loan: ");
    scanf("%lf", &loan_amount);
    printf("Enter interest rate: ");
    scanf("%lf", &interest_rate);
    printf("Enter monthly payment: ");
    scanf("%lf", &monthly_payment);

    double monthly_interest_rate = (interest_rate / 100) / 12.0;
    for (int i = 0; i < months; ++i) {
        loan_amount = loan_amount - monthly_payment + (loan_amount * monthly_interest_rate);
        printf("Balance remaining after %d payment: $%.2lf\n", i + 1, loan_amount);
    }


}

int main(void) {
    // exec_1();
    //exec_7_1();
    //exec_7_2();
    // exec8_2();
    exec8_3();
}


