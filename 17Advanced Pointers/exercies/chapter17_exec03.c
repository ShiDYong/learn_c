/********************************************************************************
* @author: mason shi
* @date: 2023/9/11 22:03
* @version: 1.0
* @description: 第十七章课后练习题
********************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<ctype.h>

/**
 * 课后练习题15:请说明下列程序的输出结果，并解释程序的功能。
 * @param f
 * @return
 */
int f1(int(*f)(int));

int sum(int (*f)(int), int start, int end);

int f2(int i);


int main(void) {
    //课后练习题15
    printf("Answer: %d\n", f1(f2));
    return 0;

    /*函数调用时的流程；
     * 1.f1(f2) calls f1 with f2 as an argument. This means that f1 will use f2 as the function it repeatedly calls within its while loop.
       2.f1 initializes n to 0.
       3.Inside the while loop:
            It calculates the result of f2(n) which is n * n + n - 12.
            If this result is nonzero (i.e., not equal to 0), it increments n by 1.
       4.The loop continues until f2(n) returns 0.
       5.The value of n when the loop exits is the result of f1(f2).
         Now, let's calculate the value of f1(f2) step by step:
         When n is 0, f2(0) is -12, which is nonzero.
         So, n is incremented to 1.
         When n is 1, f2(1) is 1 * 1 + 1 - 12, which is also nonzero.
         n is incremented to 2.
         When n is 2, f2(2) is 2 * 2 + 2 - 12, which is 0.
         Since f2(2) returns 0, the loop in f1 exits. Therefore, the value of n when the loop exits is 2.
        Finally, in the main function, the program prints "Answer: 2\n" because f1(f2) returned 2.
    */

}


/**
 * 该函数采用指向函数的指针作为参数。函数f是一个指向函数的指针，该该函数接收整数
 * 作为参数并返回整数。在函数内部，它将整数n初始化为0.
 * @param f
 * @return
 */
int f1(int (*f)(int)) {
    int n = 0;
    while ((*f)(n)) n++; //while循环使用n的当前值调用f指向的函数，并检查结果是否为零。如果结果非零(true),则增加n并继续循环。该循环有效地不断递增n直到f(n)返回零
    return n;
}

int f2(int i) {
    return i * i + i - 12;
}


/**
 * 编写下列函数。调用sum(g,i,j)应该返回g(i)+...+g(j).
 * @param f
 * @param start
 * @param end
 * @return
 */
int sum(int (*f)(int), int start, int end) {
    int result = 0;
    while (start <= end) {
        result += (*f)(start);
        start++;
    }
    return result;
}




