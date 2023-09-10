/**
Created by mason on 2023/5/1.
 第四章：C语言的常用的表达士的课后练习题目
*/
#include<stdio.h>

/**
 * 给出下列程序片段的输出结果：假设i、j、k都是int型变量
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
 * 练习2:如果i和j都是整数，(-i) / j的值和-(i /j)的值是否一样的？验证你的答案
 */
void exec_02() {
    int i = 2, j = 3; //在mac上正负数的结果都一样
    printf("(-i) / j的值:%d\n", (-i) / j);  //(-i) / j的值:0
    printf("-(i/j)的值:%d\n", -(i / j));   //-(i/j)的值:0
}

/**
 * 练习09:给出下列片段的输出结果。假设i、j和k都是int型整数
 */
void exec_09() {
    int i, j, k;
    //a.
    i = 7, j = 8;
    i *= j + 1;
    printf("%d %d\n", i, j);
    //b.
    i = j = k = 1;
    i += j += k; //根据+=是右结合可以判断出:1.先j=j+k,然后i= i+j;
    printf("%d %d %d \n", i, j, k);
    //c.
    i = 1, j = 2, k = 3;
    i -= j -= k;  //同理也是右结合
    printf("%d %d %d\n", i, j, k);
    //d.
    i = 2, j = 1, k = 0;
    i *= j *= k;
    printf("%d %d %d\n", i, j, k);

}

/**
 * 课后练习题目10：给出下列程序片段的输出结果。假设i和j都是int型变量
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
    printf("%d %d\n", i, j); //i=2,j=8,这里是否涉及类型转换？和Java的基本数据类型转换不一致？待后面确定
    //d.
    i = 2, j = 8;
    j = (i = 6) + (j = 3);
    printf("%d %d\n", i, j);//6,9


}

/**
 * 课后练习11.
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
    i = 2, j = 8, k = 5;
    printf("%d\n", i++ - j++ + --k);//2-8-(5-1)=-10
    printf("%d %d %d\n", i, j, k); //3,9,4
}

/**
 * 课后练习12题
 */
void exec_12() {
    int i, j;
    //a.
    i = 5;
    j = ++i * 3 - 2; //i=6,6*3=18,18-2=16
    printf("%d %d\n", i, j);
    //b.
    i = 5;
    j = 3 - 2 * i++; //3 -2*5=-17,i++=6
    printf("%d %d\n", i, j);
    //c.
    i = 7;
    j = 3 * i-- + 2;
    printf("%d %d\n", i, j);

    //d.
    i = 7;
    j = 3 + --i * 2; //3+(7-1)*2=15
    printf("%d %d\n", i, j);

}

/**
 * 课后练习15题；验证表达式++i和表达式i++与(i+=1)哪个是完全形同的？
 */
void exec_13() {
    int i = 1;
    // ++i;    //2
    // i++;       //i++表达式运行后再打印就变成了2
    i += 1;
    printf("i的结果：%d\n", i); //
  //综上可知道：++i和i+=1是完全相同的

}
/**
 * 课后练习14：添加圆括号，说明c语言编译器如何解释下列表达式
 *    ( a) a * b - c * d + e
      (b) a / b % c / d
      (c) - a - b + c - + d
      (d) a * - b / c - d
 */
void exec_14(){
    /**
    (a) (((a * b) - (c * d)) + e)
    (b) (((a / b) % c) / d)
    (c) ((((- a) - b) + c) - (+ d))
    (d) (((a * (- b)) / c) - d)
    */

}

//int main() {
//    // exec_01();
//    //exec_02();
//    // exec_09();
//    //exec_10();
//    // exec_11();
//    //exec_12();
//    exec_13();
//    return 0;
//}








