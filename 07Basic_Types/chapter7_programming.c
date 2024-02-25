/**
Created by mason on 2023/5/29
 第七章课后编程题目
 *
*/
#include<stdio.h>

/**
 * 课后编程题目01:如果i*i超过了int类型的最大取值，那么6.3节中的程序square2.c将会失败(通常会显示奇怪的答案)。运行该程序
 * ，并确定导致失败的n的最小值。尝试把变量i的类型改成short并再次运行该程序。(不要忘记更新printf函数调用中的转换说明！)然后
 * 尝试将其改成long。从这些实验中，你能总结出在你的机器上用于存储整数类型的位数时多少吗？
 * */
void exec7_1() {
    /*在64位机器上面对应的有符号的值范围：
     * short: -32758~72767
     * int :  -2147483648~2147483647
     * long: 9223372036854775807
     * */
    //int i, n;
    short i, n;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    /*当i为int时，导致失败的n最小值时999290*/
    for (i = 1; i <= n; i++) {
        if (i * i >= 2147483647)
            break;
        printf("%20hd%20hd\n", i, i * i);
    }
    printf("导致失败的n最小值n是：%hd\n", n);


}

/**
 * 课后编程练习02:修改6.3节的程序square2.c，每24次平方运算后暂停，并显示下列信息：
 * Press Enter to continue...
 * 显示完上述信息后，程序应该使用getchar函数读入一个字符。getchar函数读到用户输入的回车键才允许程序继续。
 */
void exec7_02() {
    int i, n;
    printf("This program prints a table of squares.\n");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    getchar(); /* ungets '\n' from buffer */

    for (i = 1; i <= n; i++) {

        printf("%10d%10d\n", i, i * i);
        if (i % 24 == 0) {
            printf("Press Enter to continue...");
            while (getchar() != '\n');
        }
    }
}


//int main() {
//    //exec7_1();
//    exec7_02();
//    return 0;
//}