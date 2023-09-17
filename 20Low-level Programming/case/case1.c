/********************************************************************************
* @author: mason shi
* @date: 2023/9/17 10:56
* @version: 1.0
* @description: 第二十章：底层程序设计
 *          位操作和其他一些底层运算在编写系统程序(包括编译器和操作系统)、加密程序、图形程序以及其他一些需要高执行速度或高效地利用空间的程序时非常有用。
********************************************************************************/
#include<stdio.h>

void bit_operation();

void printf_bin(int num);

void bitwise_operator();

void access_bits();

void access_bits();

int main(void) {
    // bit_operation();
    //bitwise_operator();
    access_bits();
    return 0;
}


/**
 * 20.1:位运算符
 * C语言提供了6个位运算符。这些运算符可以用于对整数数据进行位运算
 */
void bit_operation() {
    /*1.移位运算符：可以通过将位向左或向右移动来变换整数的二进制表示。
     *          左移位： <<       右移位：>>
     *2.运算符<<和运算符>>的操作数可以是任意整数类型(包括char型)。这两个运算符对两个操作数都会进行整数提升，返回值的类型是
     *  左操作数提升后的类型。
     *3.i<<j的值将i中的位左移j位后的结果。每次从i的最左端溢出一位，在i的最端补一个0位。i>>j的值是将i中的位右移j位后的结果。如果i是无符号数或非负值，
     *  则需要在i的左端补0.如果i是负值，其结果是由实现定义的：一些实现会在左端补0.其他一些实现会保留符号位而补1.
     * */
    unsigned short i, j;
    i = 13;  //binary: 00000000 00000000 00000000 00001101
    j = i << 2; // binary: 00000000 00000000 00000000 00110100
    printf("13<<2的十进制值：%d\n", j);
    //对应的二进制的值
    printf_bin(i);
    printf_bin(j);
    j = i >> 2;  //binary: 00000000 00000000 00000000 00000011
    printf_bin(j);

    //上面的例子，这两个运算符都不会改变它的操作数。如果要通过移位改变变量，需要使用复合赋值运算符 <<=、>>=;
    i <<= 2;
    printf(" i <<= 2的十进制值：%d\n", i);
    printf_bin(i);
    i >>= 2;
    printf(" i <<= 2十进制值：%d\n", i);
    printf_bin(i);
    //3.移位运算符的优先级比算术运算符的优先级低，因此可能产生意料之外的结果。例如，i<<2+1等同于 i<<(2+1),而不是(i << 2) +1;
}

/**
 * 20.1.2:按位取反运算符、按位与运算符、按位异或运算符和按位或运算符
 *      ～ ：按位取反
 *      &  ：按位与
 *      ^  ：按位异或
 *      ｜  ：按位或
 *    运算符~是一元运算符，对其操作数会进行整数提升。其他运算符都是二元运算符，对其操作数进行常用的算术转换
*     运算符~、&、^和｜对操作数的每一位执行布尔运算。~运算符会产生对操作数求反的结果，即将每一个0替换位1，将每一个1替换位0.
 *    运算符&对两个操作数相应的位执行逻辑与运算。运算符^和｜相似(都是对连个操作数执行逻辑或运算),不同的是，当两个操作数的位都是1时，
 *    ^产生0而｜产生1.
 *    对运算符~需要特别注意，因为它们可以帮助我们使底层程序的可移植性更好。假设我们需要一个整数，它的所有位都为1.最好的方式是使用～0
 *    ，因为它不会依赖所包含的位个数。类似地，如果我们需要一个整数，除了最后5位其他的位全都为1，我们可以写成～0x1f.
 *    运算符～、&、^和｜有不同的优先级：
 *    最高    ～
 *            &
 *            ^
 *            ｜
 *     最低
 *     因此，可以在表达式中组合使用这些运算符，而不必加括号。例如，可以写i & ~j|k而不需要写成(i & (~j))|k
 */
void bitwise_operator() {
    unsigned short i, j, k;
    i = 21;
    printf("%d\n", i);
    printf_bin(i);
    j = 56;
    k = ~i;
    printf("~i的值：%d\n", k);
    printf_bin(k);
    k = i & j;
    printf("i&j的值：%d\n", k);
    printf_bin(k);
    k = i ^ j;
    printf("i^j的值：%d\n", k);
    printf_bin(k);
    k = i | j;
    printf("i|j的值：%d\n", k);
    printf_bin(k);
}

/**
 * 20.1.3用位运算符访问位：
 * 在进行底层编程时，经常会需要将信息存储为单个位或一组位。例如，在编写图形程序时，可能会需要将两个或更多个像素挤在一个字节中。
 * 使用位运算符就可以提取或修改存储在少数几个位中的数据。
 */
void access_bits() {
    //1.位的设置：要设置（打开）整数中的特定位，可以将按位 OR (|) 运算符与位掩码一起使用。 以下是如何设置整数中的单个或多个位：
    //关于什么是掩码：https://www.jianshu.com/p/9268ac2c8e5f
    unsigned int i = 0;  // Initialize i to 0 (binary: 00000000)
    printf_bin(i);
    printf_bin(1);
    // Set the 3rd bit (counting from the right, starting with 0)
    i |= 1 << 3;  // After this operation, i becomes binary: 00001000,执行此操作后，i 变量的第 j 位将设置为 1，而所有其他位保持不变。
    printf_bin(i);
    //十六进制：
    unsigned char bytes = 0x00;  // Initialize a byte to 0x00 (binary: 00000000)
    // Set the 2nd and 4th bits using hexadecimal values
    bytes |= 0x04;  // 0x04 is equivalent to binary 00000100
    bytes |= 0x10;  // 0x10 is equivalent to binary 00010000
    printf_bin(bytes);
    /*
    * 1 << j：这部分表达式将二进制数字 1 向左移动 j 个位置。 换句话说，它将第 j 位（从右数起，从 0 开始）设置为 1，而所有其他位保持为 0。
    *          例如，如果 j 为 3，则 1 << 3 会产生二进制 00001000。
      |= ...:这是按位或赋值运算 (|=)。 它使用按位或运算符 (|) 将 i 的值与右侧表达式的结果组合起来。
            | 的 | 如果相应位中的一个或两个为 1，则运算符将某个位设置为 1。
            因此，当您计算 i |= 1 << j 时，您实际上打开了 i 的第 j 位，而不影响其他位。 这是操作整数中各个位的简洁而常见的方法。
    * */
    //位的清除：要清除（关闭）整数中的特定位，您可以使用按位 AND (&) 运算符以及位掩码，该位掩码将要清除的位设置为 0，而所有其他位设置为 1。
    // 如何清除整数中的单个或多个位:
    /*
     * 1.Clearing a Single Bit:
     * 要清除特定位置的单个位，您可以创建一个位掩码，仅将该位设置为 0，然后与原始数字执行按位 AND 运算。
     * 此操作可确保您要清除的位设置为 0，同时保持所有其他位不变。示例如下：
     * */
    unsigned int number = 255;//Binary:00000000 00000000 00000000 11111111
    printf_bin(number);
    //Clear the 3rd bit (counting from the right, starting with 0)
    number &= ~(1 << 3);//binary:00000000 00000000 00000000 11110111
    printf_bin(1);
    printf_bin(1 << 3);//clears bit 3
    printf_bin(number);

    /*2.Clearing Multiple Bits:
     * 要清除不同位置的多个位，您可以为要清除的每个位创建单独的位掩码，并使用按位 AND 运算将它们组合起来。
     * */
    //clear the 2nd and 4th bits
    unsigned int num = 255;
    num &= ~(1 << 2);  //Binary: 00000000 00000000 00000000 11111011
    printf_bin(num);
    num &= ~(1 << 4);  // Binary: 00000000 00000000 00000000 11101011
    printf_bin(num);
    /*3.Clearing Bits Using Hexadecimal Values:
     * 与设置位一样，您还可以使用十六进制值清除位，以提高清晰度和易用性。
     * */
    unsigned char byte = 0xFF;  // Binary: 11111111
    printf_bin(byte);
// Clear the 3rd and 5th bits using hexadecimal values
    byte &= 0xF7;  // 0xF7 is equivalent to binary 11110111
    printf_bin(byte);
    byte &= 0xDF;  // 0xDF is equivalent to binary 11011111
    printf_bin(byte);

    //位的测试：要测试（检查）整数中的特定位，可以将按位 AND (&) 运算符与位掩码一起使用。 以下是测试整数中的单个或多个位的方法
    unsigned int ber = 12;  // Binary: 1100
    // Test the 3rd bit (counting from the right, starting with 0)
    int isSet = (ber & (1 << 3)) != 0;  // isSet will be 1 (true)
    unsigned char test = 0x0A;  // Binary: 1010

// Test the 1st and 3rd bits using hexadecimal values
    int isBit1Set = (test & 0x01) != 0;  // isBit1Set will be 0 (false)
    int isBit3Set = (test & 0x04) != 0;  // isBit3Set will be 1 (true)



}

/**
 * 修改位域和获取方法
 */
void update_and_get_bits() {
    //1.修改位域：要更新（修改）C 中整数或变量中的特定位，可以结合使用按位 AND (&) 和按位 OR (|) 运算以及位掩码。
    unsigned int number = 0x0A;  // Binary: 00001010
    // Clear the 3rd bit (counting from the right, starting with 0)
    number &= ~(1 << 3);  // Binary: 00001000
    // Set the 2nd bit to 1
    number |= (1 << 2);   // Binary: 00001004
    /*2.获取位域：
     * 要从 C 中的整数或变量检索（获取）特定位，可以使用按位 AND (&) 以及位掩码来提取所需的位
     * */
    unsigned int num = 12;  // Binary: 1100
    // Get the value of the 3rd bit (counting from the right, starting with 0)
    int bitValue = (num >> 3) & 1;  // bitValue will be 1 (true)
    unsigned char byte = 0x0A;  // Binary: 00001010

// Get the value of the 1st and 4th bits using hexadecimal values
    int bit1Value = (byte >> 0) & 1;   // bit1Value will be 0 (false)
    int bit4Value = (byte >> 3) & 1;   // bit4Value will be 1 (true)



}

/**
 * 方法来源：https://zhuanlan.zhihu.com/p/150820820
 *  @param num
 */
void printf_bin(int num) {
    int i, j, k;
    unsigned char *p = (unsigned char *) &num + 3;//p先指向num后面第3个字节的地址，即num的最高位字节地址

    for (i = 0; i < 4; i++) //依次处理4个字节(32位）
    {
        j = *(p - i); //取每个字节的首地址，从高位字节到低位字节，即p p-1 p-2 p-3地址处
        for (int k = 7; k >= 0; k--) //处理每个字节的8个位，注意字节内部的二进制数是按照人的习惯存储！
        {
            if (j & (1 << k))//1左移k位，与单前的字节内容j进行或运算，如k=7时，00000000&10000000=0 ->该字节的最高位为0
                printf("1");
            else
                printf("0");
        }
        printf(" ");//每8位加个空格，方便查看
    }
    printf("\r\n");
}






