/**
Created by mason on 2023/5/2.
 第五章：选择语句课后练习题
 */
#include<stdio.h>

/**
 * 练习01:下列代码片段给出了关系运算符和判等运算符的示例。假设i、j和k都是int型变量。请给出
 * 每道题的结果
 */
void exec05_01() {
    int i, j, k;
    //a.
    i = 2, j = 3;
    //查看书本附录A可知:判等运算符:== !=和乘法运算符：/ * % 都是左结合性，但是
    //优先级，判等运算符排第8而乘法运算符排第3。判等运算符产生0(假)或1(真)作为结果
    k = i * j == 6; // k= 2*3=6,然后6==6
    printf("%d\n", k);

    //b.
    i = 5, j = 10, k = 1;
    //关系运算符：< > <= >= 也是左结合型，优先级排7，高于判等运算符
    //下面这个表达式在C语言中是合法的，但效果可能并不是所期望的，跟俊关系运算符的左结合性
    //下面这个表达式等价于：(i < j) < k,表达式首先要检测i是否小于j,然后用比较后产生的结果(1或0)来和k进行比较
    //这个表达式并不是测试j是否位于i和k之间，如果真要实现这种效果：i < j && j<k
    printf("%d\n", k > i > j);
    //c.
    i = 3, j = 2, k = 2;
    printf("%d\n", i < j == j < k); //< > <= >= 也是左结合型，优先级排7，高于判等运算符
    //i<j为false（0）,j<也为false(0),所以i<j == j < k等价于：0==0?值是true(1)
    //d.
    i = 3, j = 4, k = 5;
    printf("%d\n", i % j + i < k); //注意各种运算符的优先级
    //首先i%j =3,3+i=6,6/5值为0，注意i<k关系运算符的优先级低于加法类
}

/**
 * 练习02:下列代码片段给出了关系运算符和判等运算符的示例。假设i、j和k都是int型变量。请给出
 * 每道题的输出结果
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
 * 下列代码片段给出了逻辑表达式的短路行为的示例。假设i、j、和k都是int型变量。请给出每道题的输出结果
 */
void exec05_03() {
    int i, j, k;
    //a.
    i = 3, j = 4, k = 5;
    printf("%d\n", i < j || ++j < k); //1
    printf("%d\n", ++j < k || i < j); //1
    // printf("%d%d%d\n", i, j, k);
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
 * 编写一个表达式，要求这个表达式根据i小于、等于、大于j这3种情况，分别取值-1、0、+1.
 * 问题：一个表达式？如何取值？
 */
void exec05_04() {


}

/**
 *下面的if语句在C语言中是否合法
 */

void exec05_05() {
    int n = 0;
    if (n >= 1 <= 10) {
        printf("n is between a and 10\n"); //执行后编译通过的,但是让人疑惑
    }
    //如果是合法的，那么当n等于0时会发生什么？
    //依然可以编译运行，因为这个根据的左结合性，n>=1结果是false(0),但是1<=10返回结果是true(1)
}

/**
 * 下面的if语句在c语言中是否合法?
 */
void exec05_06() {
    int n = 5;
    if (n == 1 - 10)  //根据优先级：加法类高于判等运算符==》1-10=-9,n==-9?,因为n没有初始化值，所以无法比较
        printf("n is between a and 10\n");//n的值为-9才会执行这个操作，所以这个编译通过可以运行，但是让人疑惑的
    //如果合法，那么当n等于5时会发生什么？
    //显然不满足条件，不执行相关操作
}

/**
 * 如果i的值为17，下面的语句显示的结果是什么？如果i的值为-17，下面的语句显示的结果又是什么？
 */
void exec05_07() {
    int i;
    i = 17;
    printf("%d\n", i >= 0 ? i : -i);//17
    i = -17;
    printf("%d\n", i >= 0 ? i : -i);
}

/**
 * 下面的语句不需要这么复杂，请尽可能地加以简化
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
 * 下面两个if语句是否等价？如果不等价，为什么？
 */
void exec05_09(){
    int score;
//    if (score >= 90)       if (score < 60)
//            printf("A");           printf("F");
//    else if (score >= 80)  else if (score < 70)
//        printf("B");           printf("D");
//    else if (score >= 70)  else if (score < 80)
//        printf("C");           printf("C");
//    else if (score >= 60)  else if (score < 90)
//        printf("D")            printf("B");
//    else                   else
//    printf("F");           printf("A");
//以上两个表达式是等价的
}
/**
 * 下面的代码片段的输出结果是什么？(假设i是整型变量)
 */
void exec05_10(){
   int i =1;
    switch (i%3) {
        case 0:
            printf("zero");
        case 1:
            printf("one");
        case 2:
            printf("two");
      //  default:
        //    printf("four");
    }
    //因为i%3的值是1，所以会打印one,但是因为没有brake所以会继续打印two,所以会打印two
    //最终打印的结果是onetwo,switch语句没有brake就出出现倒穿情况出现
}

/**
 * 练习10:编写一个switch语句，其控制表达式是变量area_code.如果area_code的值在表中，switch语句打印
 * 出相应的城市名；否则switch语句显示的消息："Area code not recognized".使用5.3节讨论的方法，使
 * switch语句尽可能地简单
 *
 */
 void exec05_11(){
     int area_code;
    printf("Please enter one area code: ");
    scanf("%d",&area_code);
    switch (area_code) {
        case 229:
            printf("Albany");
            break;
        case 404:  case 470: case 678:  case 770:
            printf("Atlanta");
            break;
        case 578:
            printf("Macon");
            break;
        case 706: case 762:
            printf("Columbus");
            break;
        case 912:
            printf("Savannah");
            break;
        default:
            printf("Area code not recognized");
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