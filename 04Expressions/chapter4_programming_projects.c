/**
Created by mason on 2023/5/1.
 第四章：C语言的常用的表达式章节编程题
*/
#include<stdio.h>

/**
 * 1.0:编写一个程序，要求用户输入一个两位数，然后按数位的逆序打印出这个数。
 * 程序会话类似这样的：
 * Enter a two-digit number: 28
 * The reversal is: 82
 * 2.第二题扩展到处理3位数
 *
 */
void project_01_02_03() {
    //1.第一种实现方式把输入的两个数字分别提取出来，然后打印输出的时候顺序相反
    int i, j;
    printf("Enter a two-digit number: ");
    scanf("%1d%1d", &i, &j);
    printf("The reversal is:%d%d\n", j, i);
    //第二种实现方式：算术分割输入的数据
    int n;
    printf("Enter a two-digit number: ");
    //用%d读取两位数
    scanf("%d", &n);
    //输入的时候对两位数进行分解：如果n是整数，那么n%10是个位数，而n/10则是移除个位数后剩下的数
    printf("The reversal is:%d%d\n", n % 10, n / 10);
    //2.扩展上述：使其可以处理3位数
    int k;
    printf("Enter a three-digit number: ");
    scanf("%d", &k);
    //同理输入的时候对3位数进行分解：如果n是整数，那么n%100%10是个数，n%100/10则是中间的十位数，n/100则是百位的数值
    printf("%d%d%d\n", k % 100 % 10, k % 100 / 10, k / 100);
    //化简下,效果是一样的
    printf("%d%d%d\n", k % 10, k / 10 % 10, k / 100);
    //3.编写编写编程2中的程序，使新程序不需要利用算术分割就可以显示出3位数的逆序：参考：4.1节的upc.c
    //同理使用方法一，通过scanf函数在获取输入参数的分别进行获取，打印输出时把顺序倒过来就可以
    int m1, m2, m3;
    printf("Enter a three-digit number: ");
    scanf("%1d%1d%1d", &m1, &m2, &m3);
    printf("The reversal is:%d%d%d\n", m3, m2, m1);

}

/**
 *编写一个程序，读入用户输入的整数并按八进制(基数为8)显示出来
 * Enter a number between 0 adn 32767: 1953
 * In octal, your number is : 03641
 * 输出应为5位数，即使不需要那么多位数也要如此
 */
void project_04() {
    int n;
    printf("Enter a number between 0 and 32767: ");
    scanf("%d", &n);
    printf("In octal, your number is: %d%d%d%d%d\n",
           (n / 4096) % 8,
           (n / 512) % 8,
           (n / 64) % 8,
           (n / 8) % 8,
           n % 8);
}

/**
 * 重写4.1节中的upc.c程序，使用户可以一次性输入11位数字，而不用先输入1位，再输入5位，最后再输入5位
 * 计算校验puc的校验位的方法:首先把第1位、第3位、第5位、第7位、第九位和第11位的数字相加；
 * 然后把第2位、第4位、第6位、第8位和第10位的数字相加；接着把第一次加法的结果乘以3，再和第二次的加法结果
 * 相加；随后再把上述结果减去1；相减后的结果除以10取余数；最后用9减去上一步骤中得到的余数。
 * 案例：0 51500 241128 ？
 */
void project_05() {
    int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, first_sum, second_sum, total;
    printf("Enter the first 11 digit of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i0, &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10);
    first_sum = i0 + i2 + i4 + i6 + i8 + i10;
    second_sum = i1 + i3 + i5 + i7 + i9;
    total = (first_sum * 3) + second_sum - 1;
    printf("Check digit: %d\n", 9 - (total % 10));
}

/**
 * 编程练习06:欧洲国家及地区不实用北美的12位同样产品代码(upc),而使用13位的欧洲商品编码(EAN)....
 * 计算校验规则是：首先把第二位、第四位、第六位、第八位、第十位、第十二位数字相加；然后把第一位、第三位、
 * 第五位、第七位、第九位和第十一位数字相加；接着把第一次相加的结果乘以3，再和第二次加法的结果相加；随后把上述结果减去1；
 * 相减后的结果除以10取余数；最后用9减去上一步骤中得到结果。
 */
void project_06() {
    int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, first_sum, second_sum, total;
    printf("Enter the first 12 digit of a EAN: ");
    //scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d\n", &i0, &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11);
    //上述写法导致输入后无法获取输入的数字，因为多加了换行符号\n
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i0, &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11);

    second_sum = i0 + i2 + i4 + i6 + i8 + i10;
    first_sum = i1 + i3 + i5 + i7 + i9 + i11;
    total = (first_sum * 3) + second_sum - 1;
    printf("Check digit: %d\n", 9 - (total % 10));
}

//int main() {
//    //  project_01_02_03();
//    // project_04();
//    //project_05();
//    project_06();
//}