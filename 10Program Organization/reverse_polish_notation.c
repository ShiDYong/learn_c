/********************************************************************************
* @author: mason shi
* @date: 2023/7/15 17:04
* @version: 1.0
* @description: 课后编程练习题目6.
 * 有些计算器(尤其是惠普的计算器)使用逆波兰表示法来书写数学表达式。在这一表示法中，运算符放在操作数的后面而不是放在操作
 * 数中间。例如，在逆波兰表示法中1+2*3将表示1 2 3 * +。逆波兰表达式可以很方便地用栈求值。算法从左到右读取运算符
 * 和操作数，并执行下列步骤：
 * 1.当遇到操作数时，将其压入栈中。
 * 2.当遇到运算符时，从栈中弹出它的操作数，执行运算并把结果压入栈中。
 * 编写逆波兰表达式求值。操作数都是个位的整数，运算符为+、-、*、/和=。遇到运算符=时，将显示栈顶项，随后清空栈并提示用户
 * 计算新的表达式。这一过程持续进行，直到用户输入一个既不是运算符也不是操作数的字符为止；
 * Enter an PRN expression: 1 2 3 * + =
 * Value of expression: 7
 * Enter an PRN expression: 5 8 * 4 9 - / =
 * Value of expression: -8
 * Enter an PRN expression: q
 * 如果出现栈上溢，程序将显示消息Expression is too complex并终止。如果出现下溢(例如遇到表达式1 2 + +)，程序将显示
 * 消息 Not enough operands in expression并终止。提示：把10.2节栈代码整合到你的程序中。使用scanf(" %c",&ch)读取运算符和操作数。
********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include <ctype.h>   /* isdigit */


#define STACK_SIZE 100
/*定义全局变量*/
char contents[STACK_SIZE] = {0}; //不要忘记初始化了
int top = -1;

/*声明函数原型*/
bool is_empty();

void make_empty();

bool is_full();

void push(char c);

char pop();

void stack_underflow();

void stack_overflow();


int main(void) {
    char ch, operand1, operand2;
    printf("Enter an PRN expression: ");
    while (scanf(" %c", &ch) == 1) {
        /*scanf 是一个用于输入扫描的函数，允许您读取用户的格式化输入。“%c”是用于从输入读取单个字符的格式说明符。
         * &ch 是存储字符的内存地址。表达式 scanf(" %c", &ch) == 1 检查 scanf 的返回值。如果用户输入被成功
         * 读取并存储在变量ch 中，则其值为 1。用户输入多个字符，该表达式将计算结果为 0 (false)，表示输入格式不匹配。
         * 通过检查 scanf 的返回值，您可以处理用户输入与预期格式不匹配或遇到输入错误的情况。*/
        if (ch >= '0' && ch <= '9') {
            /*在 C 语言中，表达式 char >= '0' 用于根据字符 ASCII 值与字符 '0' 进行比较。
           * 在 ASCII 字符集中，字符由整数值表示。 字符“0”的 ASCII 值为 48。当您使用 >= 运算符将字符与“0”进行比较时，
             * 它会根据字符的 ASCII 值执行比较。 如果字符的 ASCII 值大于或等于 ASCII 值“0”，则比较结果为 true（非零）。
             * 在此示例中，将字符“5”与“0”进行比较。 由于“5”的 ASCII 值大于“0”，因此条件 ch >=“0”为真，并打印相应的消息。
             * 当您需要根据字符的 ASCII 值检查字符是否代表数字或属于特定字符范围时，此比较非常有用。*/
            push(ch - '0');
            /*在C语言中，表达式char - '0'用于将字符数字转换为其相应的整数值。在 ASCII 字符集中，
             * 十进制数字“0”到“9”由连续的整数值表示。 字符“0”的 ASCII 值为 48，“1”的值为 49，“2”的值为 50，
             * 依此类推。当您从另一个字符数字中减去字符“0”时，结果是该字符代表的整数值。
             * 例如，'5' - '0' 计算结果为整数 5，'9' - '0' 计算结果为 9，依此类推。
             * */
        } else {
            switch (ch) {
                case '+':
                    operand2 = pop();
                    operand1 = pop();
                    push(operand1 + operand2); //计算顺序是从左到右的
                    break;
                case '-':
                    operand2 = pop();
                    operand1 = pop();
                    push(operand1 - operand2);
                    break;
                case '*':
                    operand2 = pop();
                    operand1 = pop();
                    push(operand1 * operand2);
                    break;
                case '/':
                    operand2 = pop();
                    operand1 = pop();
                    if (operand2 == 0) {
                        printf("Division by zero is not allowed.\n");
                        exit(1);
                    }
                    push(operand1 / operand2);
                    break;
                case '=':
                    printf("Value of expression: %d\n", pop());
                    make_empty(); //清空栈
                    printf("Enter another RPN expression: ");
                    break;
                default:
                    printf("Invalid operator or operand: %c\n", ch);
                    exit(1);

            }
        }
    }
    return 0;


}


bool is_empty() {
    return top == -1;
}

bool is_full() {
    return top == STACK_SIZE;
}

void push(char c) {
    if (is_full())
        stack_overflow();
    else
        contents[++top] = c;

}

char pop(void) {
    if (is_empty())
        stack_underflow();
    else
        return contents[top--]; //这里不能是top--,因为push的时候top++了，此时的top的值为0,所以pop时要先--p才能拿到值
}

void make_empty() {
    top = -1;
}

void stack_underflow() {
    printf("\nStack Underflow\n");
    exit(EXIT_FAILURE);

}

void stack_overflow() {
    printf("\nStack Overflow\n");
    exit(EXIT_FAILURE);
}

