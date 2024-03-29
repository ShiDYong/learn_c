/********************************************************************************
* @author: mason shi
* @date: 2024/3/23 11:19
* @version: 1.0
* @description: C语言中常见的位操作符
********************************************************************************/
#include<stdio.h>
#include<string.h>
#include <stdbool.h>
#include<stdlib.h>

#define USERNAME "user"
#define PASSWORD "password"

/*
 * 在C语言中，位运算是对二进制数据进行操作的一种技术，可以直接对数据的位进行操作。
 * 主要的位运算包括：按位与（&）、按位或（|）、按位异或（^）、按位取反（~）、左移（<<）、右移（>>）等。
 *  逻辑异或运算符 ^：
    功能：执行逐位的异或操作，对两个操作数的对应位进行比较，如果相应位不同则结果为1，否则为0。
        示例：int result = a ^ b;
    使用：通常用于执行位操作，或在条件语句中进行条件判断时，需要谨慎使用，
    因为 ^ 不同于逻辑运算符 && 和 ||，它不是用于逻辑判断的，然而，我们可以利用异或操作的特性，
    将其用于某些特定的条件判断场景。
 */
void test_logical_XOR() {
    //1.异或运算符在条件语句中使用场景
    /*检测奇偶性：
     异或操作可以用于检测数字的奇偶性。因为偶数的二进制表示的最低位为0，而奇数的最低位为1，
     因此对于一个整数 num，可以通过 (num & 1) == 1 来判断其是否为奇数。然而，
     我们也可以使用异或操作来进行奇偶性判断：(num ^ 1) == 1。这是因为对于奇数，
     其最低位为1，异或1后变为0，而对于偶数，其最低位为0，异或1后变为1。
     因此，这个表达式在 num 为奇数时为真，在 num 为偶数时为假。*/
    int num = 5;
    if (num ^ 1) {
        printf("%d if odd\n", num);
    } else {
        printf("%d is even\n", num);
    }
    int n = 6;
    if (n ^ 1) {
        printf("%d is even\n", n);

    } else {
        printf("%d if odd\n", n);

    }

    /*2.检测两个值是否相等：
    异或操作还可以用于检测两个值是否相等。如果两个值相等，则它们的异或结果为0，
     否则为非0。因此，我们可以使用 (a ^ b) == 0 来检测两个值是否相等。
*/
    int a = 5;
    int b = 6;
    if (a ^ b) {
        printf("Values are different\n");
    } else {
        printf("Values are equal\n");
    }

}
// 函数：验证用户名和密码是否匹配
bool authenticate(char *username, char *password) {
    // 使用异或操作符 ^ 来比较密码
    //return strcmp(username, USERNAME) == 0 && strcmp(password, PASSWORD) == 0;
    return (!(strcmp(username, USERNAME) ^ strcmp(password, PASSWORD)));
    /*安全性考虑：
    在实际应用中，安全性非常重要。但是在示例中，我们使用了简单的字符串比较，
     这不是一个安全的密码验证方法。实际上，我们应该使用安全哈希函数（如SHA-256）将密码哈希化存储，
     并在验证时比较哈希值，以增加安全性。此外，应避免在代码中明文存储敏感信息（如密码），
     应该使用安全的存储和传输方式来保护这些信息。*/
}


/*
 * 假设有一个简单的用户身份验证系统，用户需要提供用户名和密码来登录。
 * 系统中存储了正确的用户名和密码，我们需要检查用户输入的用户名和密码是否与存储的信息匹配，
 * 如果匹配则认为验证通过。
 */
void logical_XOR() {

    char input_username[20];
    char input_password[20];

    printf("Enter username: ");
    scanf("%s", input_username);
    printf("Enter password: ");
    scanf("%s", input_password);

    // 进行用户名和密码的验证
//    if (strcmp(input_username, stored_username) == 0 && strcmp(input_password, stored_password) == 0) {
//        printf("Login successful!\n");
//    }
    /*strcmp() 函数返回值为0表示两个字符串相等，否则表示不相等。通过 ^ 异或操作符，
     * 我们可以将两个不相等的情况合并为真（1），而相等的情况为假（0）。
     * 最后通过 ! 逻辑非操作符，将真假值反转，以符合条件判断的预期逻辑。
     * 这样就能够安全可靠地使用异或操作符在条件语句中进行条件判断。*/
//    if (!(strcmp(input_username, stored_username) ^ strcmp(input_password, stored_password))) {
//        printf("Login successful!\n");
//    } else {
//        printf("Invalid username or password.\n");
//    }

    // 验证用户名和密码是否匹配方法单独提取出来
    if (authenticate(input_username, input_password)) {
        printf("Authentication successful. Welcome, %s!\n", input_username);
    } else {
        printf("Authentication failed. Invalid username or password.\n");
    }

}

/*
 * 移位运算符:
 * 1.左移运算符 << 和右移运算符 >> 是C语言中的位运算符，用于将一个数的所有位向左或向右移动指定的位数
 * =======具体移动位过程可以参考文章：https://zhuanlan.zhihu.com/p/390121317 =================
 * 2.使用场景：
    左移运算符常用于数据倍增，例如将某个数左移n位相当于将其乘以2的n次方。
    右移运算符常用于数据减半，例如将某个数右移n位相当于将其除以2的n次方。
    左移运算符也常用于位操作，例如将特定位移动到正确的位置。
    右移运算符用于获取符号位或者将特定位移动到正确的位置
 */
void test_shift_operator() {
    int n = 5; //原始数字
    int leftShiftAmount = 2;
    int result = n << leftShiftAmount; //左移操作
    //num 被左移了2位，即将二进制数 101 左移2位变成 10100，对应的十进制数为20。因此，输出结果是 20
    /*原始二进制表示：0000 0101
     * 左移2位后：       0001 0100
     * 具体步骤：
     * 移位的数字 5 转换为 8 位二进制数原码
        1.左边（最高位）移出 2 位，剩余位整体向左移 2 个移位量
        2.在右侧（低位）补 2 个移位量的 0
        3.二进制 0001 0100 转换为十进制 20
     * */
    printf("左移%d位的结果是：%d\n", leftShiftAmount, result);
    //同理右移运算符
    int rightShiftAmount = 2;
    int num = -5;

    /*二进制示意图：
     * 原始二进制表示：1111 1011 （补码表示，最高位是符号位）
       右移2位后：       1111 1110
       求出移位的数字 -5 原码
       1.原码求其反码
       2.反码求其补码
       3.对补码低位移出，其他位向右移 2 个偏移量
       4.对左边的空位补符号位 1。
       5.将-号跟在高位 8 后面计算求值
       非常推荐查看文章：https://zhuanlan.zhihu.com/p/390121317

     * */
    int res = num >> rightShiftAmount; //右移运算符将一个数的所有位向右移动指定的位数，左侧空出的位根据操作数的符号位或者填充0。
    printf("右移%d位的结果是：%d\n", rightShiftAmount, res);
    /*知识补充：
     * 二进制的移位操作是在CPU中进行的，因为CPU是负责执行计算机指令的核心部件，包括对数据的加工和处理。
     * 具体来说，CPU内部包含专门的电路和指令集，用于执行位移操作：
     * 示例来说明二进制移位操作在CPU中的运行步骤。假设我们要将整数 5 向左移动2位：
        1.获取操作数：CPU从寄存器或内存中获取整数 5 的二进制表示形式 0000 0101。
        2.执行移位指令：CPU执行移位指令，告诉CPU要进行向左移位的操作。
        3.计算移位量：在指令中指定移位量为2。
        4.移位操作：CPU将整数 5 的二进制表示形式向左移动2位，得到 0001 0100。
        5.更新数据：移位操作完成后，CPU将移位后的结果 0001 0100 写回到相应的寄存器或内存位置中。
          这就是二进制移位操作在CPU中的运行步骤。CPU通过指令集中的特定指令来实现移位操作，从而对数据的二进制表示形式进行移动。
     *
     * */

}
/*详细分析过程；
         * 循环处理过程：
            在每次循环中，我们将整数 num 向右移动 i 位，然后通过与1进行按位与运算，提取出这个位的值（0或1）。
            我们从整数的最高位开始处理，即从位数 bits - 1 开始，逐渐向最低位移动。
            使用二进制表示的过程：
            我们假设整数 num 的二进制表示为 abcdefghijk...，其中 a 是最高位，k 是最低位。
            在第一次循环中，我们将整数 num 向右移动 bits - 1 位，即将第 a 位移到最低位。然后通过与1进行按位与运算，提取出第 a 位的值。
            在第二次循环中，我们将整数 num 向右移动 bits - 2 位，即将第 b 位移到最低位。然后通过与1进行按位与运算，提取出第 b 位的值。
            依此类推，直到第 k 位。
         举例说明：
        假设整数 num 的值为 10，其二进制表示为 00000000000000000000000000001010。
        我们将从最高位开始处理，即第31位到第0位。
        第一次循环中，我们将整数 num 向右移动 31 位，即最高位移到最低位，然后通过与1进行按位与运算，提取出最高位的值为 0。
        第二次循环中，我们将整数 num 向右移动 30 位，即次高位移到最低位，然后通过与1进行按位与运算，提取出次高位的值为 0。
        以此类推，直到最低位。
        这样，我们通过逐步移位和按位与运算，可以逐位提取整数的二进制表示形式，并以逆序的方式打印出来。
         * */
// 函数：将整数转换为二进制字符串
const char *printBinary(int num) {
    // 计算整数 num 的位数。因为每个字节有8位，所以我们将整数的字节数乘以8，即可得到整数的位数
    int bits = sizeof(num) * 8;

    // 分配足够大的内存来存储二进制字符串。我们需要的内存大小为位数加上1，
    // 因为还需要一个额外的字符存储字符串的结束符 \0。
    // 函数 malloc 分配了一块内存，并返回了指向该内存的指针，即 binaryString
    char *binaryString = (char *) malloc(bits + 1);

    //检查内存分配是否成功。如果内存分配失败，malloc 函数将返回 NULL。
    // 在这种情况下，函数返回 NULL，表示转换失败。
    if (binaryString == NULL) { // 内存分配失败
        return NULL;
    }
    // 逐位构建整数的二进制字符串
    //循环遍历整数的每一位，从最高位到最低位。我们从 bits - 1 开始，即最高位，逐步向最低位遍历。
    for (int i = bits - 1; i >= 0; i--) {
        // 使用位运算将整数的每一位添加到字符串中
        binaryString[bits - 1 - i] = ((num >> i) & 1) + '0';
        //在每次循环中，我们使用位运算将整数的每一位添加到字符串中。num >> i 将整数 num 向右移动 i 位，
        // 然后通过与1进行按位与运算，提取出这一位的值（0或1）。最后，我们将提取出的值加上字符 '0'，
        // 将其转换为字符形式，并将其存储到 binaryString 中适当的位置。
    }

    // 在字符串末尾添加结束符 \0，以确保字符串正确终止
    binaryString[bits] = '\0';

    // 返回二进制字符串
    return binaryString;
}


int complement(int num) {
    //使用按位取反运算符对整数进行取反操作
    return ~num + 1;
}

/*
     在计算机科学中，掩码是一种用来选择性地启用或禁用某些位的技术。在位操作中，掩码通常是一个二进制数，
     其中的每一位都用于指示相应位置上的操作是否应该被执行。当位掩码的某一位为1时，表示对应位置的操作被启用；
     当位掩码的某一位为0时，表示对应位置的操作被禁用。
     在这个上下文中，我们创建的掩码用于反转特定位，即将某一位的值从0变为1，或者从1变为0。
     具体来说，我们将掩码中需要反转的位置设为1，其余位置设为0。
     然后，通过按位异或运算符（XOR）将原始数值和掩码进行异或操作，从而实现反转特定位的目的。
     假设我们有一个8位的二进制数 10101010，现在我们想要将第4位（从右边开始计数）反转，即将它从0变为1或从1变为0。
     为了实现这个目的，我们可以创建一个掩码，其中第4位为1，其余位为0，如下所示：
    掩码： 00001000
    然后，我们将原始数值和掩码进行按位异或运算，即对应位相同则结果为0，否则结果为1。这将导致原始数值的第4位被反转，如下所示：
    原始数值： 10101010
    掩码：   00001000
    ------------------
    结果：   10100010
    通过这种方式，我们可以使用掩码来实现对特定位的反转操作。
    反转特定位函数，通过C语言实现
 * */
int reverseBit(int num, int pos) {
    //创建一个掩码，将要反转的位置对应的位设为1
    int mask = 1 << pos;
    //mask = 1*2^4=16;
    //对应的二进制
    //0000 0001
//0001 0000  向左移4位
//0101 0101  进行异或操作
//0100 0101
    //使用按位异或运算符号进行反转
    return num ^ mask;
}

/*
 4. 按位取反运算符 ~：
功能：对操作数的每一位进行取反操作，即将0变为1，将1变为0。
使用场景：
        求补码：在计算机中，负数的补码表示就是原数按位取反后再加1。
        反转特定位：可以用按位取反操作实现对特定位的反转。
 */
void test_bitwise_negation() {
    int num = 85; //原始数值 85 的二进制表示为 10101010
    // 求补码
    printf("85 的补码是：%d\n", complement(num)); // -85
    //调用函数获取二进制字符串
    const char *binary = printBinary(complement(num));
    if (binary != NULL) {
        printf("补码 的二进制表示为：%s\n", binary);
        free((void *) binary); // 释放动态分配的内存
    } else
        printf("内存分配失败\n");
    printf("\n");
    // 反转第 4 位
    printf("反转第 4 位后的结果：%d\n", reverseBit(num, 4)); // 93
    const char *binary02 = printBinary(reverseBit(num, 4));
    if (binary02 != NULL) {
        printf("反转第 4 位后的结果二进制表示为：%s\n", binary02);
        free((void *) binary02); // 释放动态分配的内存
    } else
        printf("内存分配失败\n");
}

// 函数：将整数打印为二进制形式
void printBinary_01(int num) {
    // 获取整数的位数
    int bits = sizeof(num) * 8;

    // 逐位打印整数的二进制形式
    for (int i = bits - 1; i >= 0; i--) {
        printf("%d", (num >> i) & 1);
    }
}

/*
 * 当移动的位数过大时可能出现的问题:
 *  1.数据丢失：当向左移动的位数超过了数据类型的位数时，会导致溢出，最高位被丢弃，结果可能不准确。
    2,符号位填充：对于有符号整数，向右移动的位数过大时，左侧空出的位将被符号位填充，这可能改变原来的数值的符号。
    3.得到0：对于无符号整数，当向右移动的位数大于等于数据类型的位数时，结果将始终为0。
    4.未定义行为：C标准对于超出数据类型位数的移位行为没有定义，因此结果取决于编译器的实现。
 */
void test_shift_overflow() {
// 数据丢失示例
    printf("数据丢失示例：\n");
    int num1 = 5; // 初始值为5
    printf("初始值：%d 的二进制表示为：", num1);
    printBinary_01(num1);
    printf("\n");

    // 向左移动超出数据类型的位数
    int left_shifted_num1 = num1 << 33;

    printf("向左移动33位后的结果：%d 的二进制表示为：", left_shifted_num1);
    printBinary_01(left_shifted_num1);
    printf("\n\n");

    // 符号位填充示例
    printf("符号位填充示例：\n");
    int num2 = -5; // 初始值为-5
    printf("初始值：%d 的二进制表示为：", num2);
    printBinary_01(num2);
    printf("\n");

    // 向右移动超出数据类型的位数
    int right_shifted_num2 = num2 >> 33;

    printf("向右移动33位后的结果：%d 的二进制表示为：", right_shifted_num2);
    printBinary_01(right_shifted_num2);
    printf("\n\n");

    // 得到0示例
    printf("得到0示例：\n");
    unsigned int num3 = 5; // 无符号整数初始值为5
    printf("初始值：%u 的二进制表示为：", num3);
    printBinary_01(num3);
    printf("\n");

    // 向右移动超出数据类型的位数
    unsigned int right_shifted_num3 = num3 >> 5;

    printf("向右移动5位后的结果：%u 的二进制表示为：", right_shifted_num3);
    printBinary_01(right_shifted_num3);
    printf("\n\n");

    // 未定义行为示例
    printf("未定义行为示例：\n");
    int num4 = -5; // 初始值为-5
    printf("初始值：%d 的二进制表示为：", num4);
    printBinary_01(num4);
    printf("\n");

    // 向右移动超出数据类型的位数（未定义行为）
    int right_shifted_num4 = num4 >> 33;

    printf("向右移动33位后的结果：%d 的二进制表示为：", right_shifted_num4);
    printBinary_01(right_shifted_num4);
    printf("\n\n");

}

/*
 * 按位与运算符 &：
   功能：执行逐位的与操作，对两个操作数的对应位进行逻辑与操作，只有在两个操作数的相应位都为1时，结果才为1，否则为0。
   按位与运算符 & 在C语言中具有多种实际使用场景，其中包括：
   1.清除特定位：通过与一个特定的位模式进行按位与操作，可以将某些特定位清零，实现对变量的部分位清零操作。
   2.提取特定位：通过与一个特定的位模式进行按位与操作，可以提取出感兴趣的位，例如提取一个字中的某些位。
   3.判断奇偶性：通过与1进行按位与操作，可以判断一个数的最低位是0还是1，进而判断奇偶性。
   4.掩码操作：通过与一个掩码进行按位与操作，可以过滤出需要的信息，或者保留/改变特定的位。
 */
void test_bitwise_AND() {
    //1.清除特定位
    unsigned int num = 0b11011011; //待操作数
    unsigned int mask = 0b11110000;//需要清零的位模式
    //使用按位与操作清零特定位
    unsigned int result = num & ~mask;//使用按位与操作清零特定位
    /*  num:      11011011
        mask:     11110000
        ~mask:    00001111
        num & ~mask:
                  11011011
        &         00001111
        ---------------------
        result:   00001011
        执行逐位的与操作，对两个操作数的对应位进行逻辑与操作，只有在两个操作数的相应位都为1时，结果才为1，否则为0
        通过上述操作：我们可以保留 num 中对应于 mask 的低4位，并将其他位清零
        这段代码的主要作用是清零 num 中与 mask 对应的位,需要注意的是：
        变量 num 的值没有被修改。虽然我们在按位与操作中使用了 num 和 ~mask 来生成 result，
        但是这不会改变 num 的值。按位与操作只会生成一个新的值，而不会修改操作数的值。
*/
    printf("清零后的结果：%u\n", result);
    printf("清零后的结果：%u\n", num);
    //2.提取特定位：按位与操作的结果就是将 num 中 mas 中对应位为1的位保留下来，而其他位清零
    unsigned int mas = 0b00001111;//需要提取的位模式
    unsigned int res = num & mas; // 使用按位与操作提取特定位
    /*  num:      11011011
        mask:     00001111
        num & mask:
                  11011011
        &         00001111
        ----------------
        result:   00001011
*/
    printf("提取后的结果: %u\n", res);

    //3.判断奇偶性
    int n = 7; // 待判断的数字
    //通过与1进行按位与操作，判断 num 的最低位是否为1，从而判断其奇偶性，然后输出结果。
    if (n & 1) {
        printf("%d 是奇数\n", n);
    } else {
        printf("%d 是偶数\n", n);
    }
    //4.掩码操作:使用按位与操作，将 mas 中为1的位保留在 num 中，其他位清零，然后输出结果。
    unsigned int data = num & mas; // 使用按位与操作掩码
    printf("操作后的结果: %u\n", data);


}

/*按位或运算符 |：
功能：执行逐位的或操作，对两个操作数的对应位进行逻辑或操作，只要两个操作数的相应位中有一个为1，结果就为1。
*/
void test_bitwise_OR() {
    //1.设置特定位：通过将一个或多个特定位设置为1，可以在无需修改其他位的情况下修改一个整数的特定位。
    // 这在处理标志位或配置寄存器时非常有用
    unsigned int flags = 0b00000000; // unsigned int flags = 0b00000000;：这一行初始化了一个名为 flags 的无符号整数变量，
    // 并将其值设置为二进制表示的 00000000，即十进制的0。这是一个常见的用法，用于初始化标志位变量。
    // 设置第0位和第2位
    flags |= (1 << 0); // 设置第0位
    /*(1 << 0) 表示将数字1左移0位，结果还是1。这样，我们得到了一个二进制表示为 00000001 的数值，
     * 表示第0位为1，其他位为0。flags |= (1 << 0); 将 flags 和 (1 << 0) 进行按位或操作，
     * 并将结果存储回 flags 变量中。因为 flags 中的其他位都是0，所以按位或操作后，
     * 只有第0位被设置为1，其他位保持不变。最终，flags 的值变为 00000001。*/
    flags |= (1 << 2); // 设置第2位
    /*(1 << 2) 表示将数字1左移2位，结果为 00000100，表示第2位为1，其他位为0。
     flags |= (1 << 2); 将 flags 和 (1 << 2) 进行按位或操作，并将结果存储回 flags 变量中。
     因为 flags 中的其他位仍然是 00000001，所以按位或操作后，第0位仍然是1，而第2位变为1，
     其他位保持不变。最终，flags 的值变为 00000101*/
    //综上：通过这样的操作，我们可以灵活地设置和修改整数的特定位，而不影响其他位的值。在实际编程中，这种技巧经常用于管理标志位、配置寄存器等场景

    //2.合并位模式：通过将两个整数进行按位或操作，可以将它们的对应位进行合并。这在某些算法和数据结构中很常见。
    unsigned int num1 = 0b11001010;
    unsigned int num2 = 0b00110101;
    // 合并两个整数的对应位
    unsigned int merged = num1 | num2;

    //4.权限设置：在一些系统或应用程序中，可以使用按位或操作来设置用户或资源的权限。
    // 设置用户权限
    int userPermission = 0b00000000;
    userPermission |= (1 << 0); // 设置第0位表示读权限
    userPermission |= (1 << 1); // 设置第1位表示写权限

}


//int main(int argc, char *argv[]) {
    // test_logical_XOR();
    //logical_XOR();
    // 按位取反操作
//    int result = 0;
//    unsigned int data = ~result;
//    printf("原始数：%u\n", result);
//    printf("取反后：%u\n", data);
//    test_shift_operator();
//    int num = 10;

    //取反的运用
//    int num = 85; // 原始数值 85 的二进制表示为 1010101
//    printf("二进制表示为：");
//    printBinary(num);
//    printf("\n");
//    test_bitwise_negation();
//    test_bitwise_AND();
//    test_shift_overflow();
//
//}