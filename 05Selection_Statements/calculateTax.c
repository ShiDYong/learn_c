/********************************************************************************
* @author: mason shi
* @date: 2024/4/27 17:46
* @version: 1.0
* @description: 优化编程练习05
 * Project 5.05
In one state, single residents are subject to the following income tax:
| Income        | Amount of tax |                               |
| ------------- | ------------- | ----------------------------- |
| Not over $750 | 1% of income  |
| $750-$2,250   | $7.50         | plus 2% of amount over $750   |
| $2,250-$3,750 | $37.50        | plus 3% of amount over $2,250 |
| $3,750-$5,250 | $82.50        | plus 4% of amount over $3,750 |
| $5,250-$7,000 | $142.50       | plus 5% of amount over $5,250 |
| Over $7,000   | $230.00       | plus 6% of amount over $7,000 |

Write a program that asks the user to enter the amount of taxable income, then
displays the tax due.
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>

//Enum for clarity in code
enum {
    INVALID_INPUT = -1
};

float getInput() {
    float income;
    printf("Enter the amount of taxable income: ");
    int result = scanf("%f", &income);
    //用于检查输入是否包含非数字字符或1个以上的整数。 如果任一条件
    if (result != 1 || getchar() != '\n') {
        printf("Invalid input format.Enter the amount of taxable income: \n");
        return EXIT_FAILURE;
    }
    if (income <= 0) {
        printf("Invalid input： Income must be a positive value. Enter income: %0.2f\n", income);
        return INVALID_INPUT;
    }

    return income;
}

/*
 1.使用数组来存储阈值、比率和基数，使代码更具可扩展性且更易于维护。
 2.迭代阈值和税率数组，以找到适合给定收入的税级。
 3.使用以下公式计算税额：基本金额 +（收入 - 之前的起征点）* 税率。 这消除了冗余计算并使代码更加高效。
 4.该代码仍然是模块化且可读的，但它现在遵循更有效的税收计算算法。
 关键要找到业务计算公式，然后提取公式
 */
float calculateTax(float income) {
    float tax = 0;
    int i;
    // Define the income thresholds for each tax bracket
    const float thresholds[] = {750, 2250, 3750, 5250, 7000};
    const float rates[] = {0.01, 0.02, 0.03, 0.04, 0.05, 0.06};
    const float baseAmounts[] = {0, 7.50, 37.50, 82.50, 142.50, 230.00};

    // Iterate over thresholds and rates to compute tax
    for (i = 0; i < sizeof(thresholds) / sizeof(thresholds[0]); ++i) {
        if (income <= thresholds[i]) {
            tax = baseAmounts[i] + (income - (i > 0 ? thresholds[i - 1] : 0)) * rates[i];
            break;
        }

    }
    // If income exceeds $7,000, calculate tax separately
    if (i == sizeof(thresholds) / sizeof(thresholds[0])) {
        tax = baseAmounts[i] + (income - thresholds[i - 1]) * rates[i];
    }


    return tax;
}


//int main(int argc, char *argv[]) {
//
//    float income, tax;
//
//    // Get the amount of taxable income from the user
//    income = getInput();
//
//    // Calculate the tax due
//    tax = calculateTax(income);
//
//    // Display the tax due
//    printf("Tax due: $%.2f\n", tax);
//
//    return 0;
//}

