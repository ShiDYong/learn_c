/********************************************************************************
* @author: mason shi
* @date: 2023/7/16 09:37
* @version: 1.0
* @description: 第十三章：字符串
 * 前面虽然使用过char类型变量和char类型数组，但始终没有使用处理字符序列(C语言的术语是字符串)便捷方法。本章将详细介绍上面的用法
 * 并将介绍字符串常量(在C语言的术语字面串)和字符串变量，其中字符串变量可以在程序运行过程中发生改变。
********************************************************************************/
#include<stdio.h>
#include <string.h>
#include<assert.h>

#define MAX_REMIND 50 /*maximum number of reminders*/
#define MSG_LEN 60 /*maximum length of reminder message*/
#define NUM_PLANETS 9

void cases_13_1();

void cases_13_2();

void cases_13_3();

void cases_13_4();

int read_line(char str[], int n);

int count_spaces(const char s[]);

int count_space(const char *s);

char *my_str_cpy(char *dest, const char *src);

void remind();

void cases_13_5();

int strcmp_02(char *s, char *t);

char *test_str_cat_01(char *s1, const char *s2);

void cases_13_7();

int main(int argc, char *argv[]) {
    // cases_13_1();
    // cases_13_3();
    // cases_13_5();
    // remind();
    // cases_13_7();
    //命令行参数的实现
//    char *planets[] = {"Mercury", "Venus", "Earth", "Mars",
//                       "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
//    int i, j;
//    for (i = 1; i < argc; i++) {
//        for (j = 0; j < NUM_PLANETS; j++)
//            if (strcmp(argv[i], planets[j]) == 0) {
//                printf("%s is plant %d\n", argv[i], j + 1);
//                break;
//            }
//        if (j == NUM_PLANETS)
//            printf("%s is not a plant\n", argv[i]);
//    }
    remind();
    return 0;
}


/**
 * 13.1节：介绍字面串的规则，包括如何在字面串中嵌入转移序列，以及如何分割较长的字面串
 *  13.1.1:字面串
 */
void cases_13_1() {
    /*13.1.1
     * 定义：字面串(string literal)是用一对双引号括起来的字符序列,如下所示：
     * 字面串常常作为格式串出现在printf函数和scanf函数的调用中。在标准中，字面串和字符串是彼此紧密相关但又不同
     * 字面串是源文件的组成部分，是程序中一串引号围起来的文本，仅仅是一个字面意义上的字符串，所以叫字面串。
     * 字面串经程序编译后生成字符串，而字符串是指位于系统存储器里的，以空字符终止的字符序列。
     * */
    printf("When you come to a fork in the road, take it\n"); //字面串可以像常量字符一样包含字符转义序列

    /*13.1.2:延续字符串：
     * 如果发现字面串太长而无法放置在单独一行，只要把第一行用字符\结尾，那么C语言就允许在下一行延续字面串.除了
     * 看不到末尾的换行符，在同一行中不可以有其他字符跟在\后面；
     * 使用\有一个缺陷：字面串必须从下一行的起始位置继续，因此破坏来陈旭的缩进结构，
     * 处理字面串更好的方法是：当两条或更多条字面串相领时(仅用空白字符串分割)，编译器会把它们合并称一条字符串。
     *
     * */
    printf("When you come to a fork in the road, take it.   \
           --yogi Berra");
    printf("When you come to a fork in the road, take it."
           "yogi Berra");

    /*13.1.3:如何存储字面串
     * 就本质而言，C语言把字面串作为字符数组来处理。当C语言编译器在程序中遇到长度为n的字面串时，它会为字面串分配长度为n+1的内存空间。
     * 这块内存空降将用来存储字面串的字符，以及用来标志字符结尾的额外字符(空字符)。空字符时一个所有位都为0的字节，因此用战役序列\0来表示
     * 不要混淆空字符('\0')和零字符('0')。空字符的码值为0，而零字符则有不同的码值(ASCII中为48)。
     * 字面窜"abc"作为有4个字符的数组来存储的(a、b、c和\0);
     * 字面串可以为空。字符串“”作为单独一个空字符来存储：\0
     * */
    printf("abc");
    /*既然字面串是作为数组来存储的，那么编译器会把它看作char * 类型的指针，例如printf函数和scanf函数都接受char *类型的值作为它们的
     * 第一个参数，像上面调用printf函数时，会传递"abc"的地址(即指向存储字母a的内存单元的指针)*/

    /*13.1.4字面串的操作：
     *
     * */
    //通常情况下可以在C语言允许使用char *指针的地方使用字面串。如：字面串可以出现在赋值运算符的右边
    char *p;
    p = "abc";//这个赋值运算符不是复制"abc"的字符，而是使p指向字符串的第一个字符。
    //C语言允许对指针取下标，因此可以对字面串取下标
    char ch;
    ch = "abc"[1]; //ch的新值将是字面b。其他可能的下标是0(这将选择字母a)、2(字母c)和3(空字符).字面串的这种特性并不常用，但有时并不常用
    //试图改变字面串会导致未定义的行为：
    char *q = "abc";
    *q = 'd'; //改变字面串可能会导致程序崩溃或运行不稳定。
    /*13.1.4字面串与字符常量：
     * 只包含一个字符的字面串不同于字符常量。字面串"a”是用指针来表示的，这个指针指向存放字符"a"(后面紧跟空字符)的内存单元
     * 字符常量'a'是用整数(字符集的数码值)来表示的。
     * */

}


/**
 * 13.2节：字符串变量
 * 讲解声明字符串变量的方法，字符串变量其实就是字符数组，不过末尾要加上一个特殊的空字符来表示字符串的结尾。
 */
void cases_13_2() {
    /**
     * 13.2.1:初始化字符串变量
     * 一些编程语言为声明为字符串变量提供了专门的string类型。C语言采取了不同的方式：只要保证字符串是以空字符串结尾的，任何一维
     * 的字符数组都可以用来存储字符串。这种方法简单，但是使用起来有很大的难度。有时很难辨别是否把字符数组作为字符串来使用。
     * 假设需要用一个变量来存储最多有80个字符的字符串。由于字符串在末尾处需要有空字符，我们把变量声明为含有81个字符的数组：
     * #define STR_LEN 80
     * ...
     * char str[STR_LEN+1];
     * 这是C程序员常用的方式。要始终保证数组的长度比字符串的长度多一个字符。如果没有给空字符预留位置，可能会导致
     * 程序运行时出现不可预知的结果，因此C函数库中的函数假设字符串都是以空字符结束的。
     * 声明长度为STR_LEN+1的字符数组并不意味着它总是用于存放长度为STR_LEN的字符串，字符串的长度取决于空字符的位置，而不是
     * 取决于存放字符串的字符数组的长度，有STR_LEN+1字符的数组可以存放多种长度的字符串，范围是从空字符串到长度为STR_LEN的
     * 字符串。
     */
    //字符串变量可以在声明时进行初始化：
    char date1[8] = "June 14";//编译器将把字符串"June 14"中的字符复制到数组date1中，然后追加一个空字符从而使date1可以
    //作为字符串使用。
    //"June 14"是一个字面初始化器，用来初始化数组。实际上，我们可以写成
    char date2[8] = {'J', 'u', 'n', 'e', ' ', '1', '4', '\0'};//该方式不方便阅读
    //当数组的初始化器比数组本身短时，余下的数组元素会被初始化为0.在把字符数组初始化为\0这点上，编译器对字符串和数组遵循相同的规则
    //如果初始化器比字符串变量长，这对字符串而言是非法的，如同数组一样是非法的。然后，C语言允许初始化器械(不包括空字符)与变量有完全
    //相同的长度
    //字符串变量的声明中可以省略它的长度，这种情况下，编译器会自动计算长度
    char date3[] = "June 14";//不指定长度意味着可以改变数组的擦和高难度，一旦编译来程序，date3的长度就固定了。该方法比较有效
    //尤其是在不确定字符串变量长度的情况下


    /**
     * 13.2.2 字符数组与字符指针
     *
     */
    char date[] = "Hello 14";
    //char *date = "Hello 14";
    /*前者声明date是一个数组，后者声明date是一个指针。正因为有了数组和指针之间的紧密关系，才使上面这两个声明中的date都可以用作字符串。
     * 具体来说，任何期望传递字符数组或字符指针的函数都能够接收这两种声明的date作为参数。
     * 但是，上面这两种写法不能互换，两者之间有很大的差异：
     * 1.在声明为数组时，就像任意的数组元素一样，可以修改存储在date中的字符。在声明为指针时，date指向字面串，字面串是不可以修改的；
     * 2.在声明为数组时，date是数组名。在声明为指针时，date是变量，这个变量可以在程序执行期间指向其他字符串。
     * 3.如果希望可以修改字符串，那么就要建立数组来存储字符串，仅仅声明指针变量是不够的，必须把指针指向字符数组
     * char str[STR_LEN+1], *p;
     * p=str;
     * 现在p指向了str的第一个字符，可以把p作为字符串使用了。另一种可能是让p指向一个动态分配的字符串。
     * ⚠️使用未初始化的指针变量作为字符串是非常严重的错误；
     * char *p;
     * p[0]='a';
     * 上面同时声明会报错：
     * 错误消息“Redefinition of 'date' with a different type: 'char *' vs 'char[8]'”意味着您在代码中多次声明了名为 'date' 的变量，
     * 但每次声明都有不同的类型 分配给它。在错误消息中，它表明一个声明将类型“char *”分配给“date”，
     * 而另一个声明将类型“char[8]”分配给“date”。 C 中不允许这种类型不一致。要解决此错误，
     * 您需要确保“date”的所有声明都具有相同的类型。 确定是否要使用指向字符 (char *) 的指针或字符数组 (char[8])，
     * 并更新“date”的所有实例，以便在整个代码中具有一致的类型。
     *
     * */

    char *p;
    p[0] = 'a'; /*WRONG*/
}

/**
 *13.3 字符串的读和写
 */
void cases_13_3() {
    //13.3.1:用printf函数和puts函数写字符串
    //转换说明%s允许printf函数写字符串
    char str[] = "Are we having fun yet?";
    printf("%s\n", str);//printf函数会逐个写字符串中的字符，直到遇到空字符才停止
    //转换说明%.ps，可以显示字符串的一部分，这里p是要显示的字符数量
    printf("%.6s\n", str);
    //字符串跟数一样，可以在指定的栏内显示。转换说明%ms会在大小为m的栏内显示字符串。(对于超过m个字符的字符串，printf函数会显示处整个字符串
    // ，而不会截断)如果字符串少了m个字符，则会在栏内右对齐输出。如果要强制对齐，可以在m前加一个减号。m值和p值可以组合使用：
    //转换说明%m.ps会使字符串的前p个字符在大小为m的栏内显示。
    printf("%-4.4s\n", str);
    //puts函数只有一个参数，即需要显示的字符串，在写完字符串后，puts函数总会添加一个额外的换行符，从而前进到下一个输出行的开始处
    puts(str);

    //13.3.2 用scanf函数读写字符串：转换说明%s允许scanf函数把字符串读入字符说明
    scanf("%s", str);//不需要在str添加运算符&,因为str是数组名，编译器在把它传递给函数时会把它当作指针来处理
    //用scanf函数读入字符串不会包含空白字符。因此，scanf函数通常不会读入一整行输入。换行符使scanf函数停止读入，空哥符或制表符也会产生
    //同样的结果。为了一次性读入一整行的输入，曾经使用gets函数，后面考虑到安全的原因，废弃掉了。

    /*
     * 13.3.3 逐个字符读字符串：
     * 如果决定设计自己的输入函数，那么就需要考虑下面的这些问题：
     * 1.在开始存储字符串之前，函数应该跳过空白字符吗？
     * 2.什么字符会导致函数停止读取：换行符、任意空白字符还是其他某种字符？需要存储这类字符还是忽略？
     * 3.如果输入的字符串太长以致无法存储，那么函数应该做什么：忽略额外的字符还是把它们留给下一次输入操作？
     * 现在设计如下：int read_line(char str[],int n)函数
     * */



}

/**
 * 不跳过空白字符，在第一个换行符(不会存储到字符串中)处停止读取，并且忽略额外的字符
 * @param str:表示用来存储输入的数组
 * @param n :读入字符的最大数量,如果输入行包含多于n的字符，该函数将忽略多余的字符
 * @return :返回实际存储在str中的字符数量
 */
int read_line(char str[], int n) {
    int ch, i = 0;  //注意，ch的类型为int,而不是char,因为getchar把它读取的字符作为int类型的值返回
    while ((ch = getchar()) != '\n')
        if (i < n)
            str[i++] = ch;
    str[i] = '\0'; /*terminates string*///返回之前，在字符串的末尾放置一个空字符。scanf和gets函数等标准函数都会自动在输入字符串的
    // 末尾放置一个空字符；然后，如果要自己写的函数，必须人工加上空字符。
    return i;  /*number of characters stored*/


}

/**
 * 13.4访问字符串中的字符
 * 字符串是以数组的方式存储的，因此可以使用下标来访问字符串的字符。
 *
 */
void cases_13_4() {
    /*下面的count_space函数示例引出了一些关于如何编写字符串函数的问题：
     * 1.用数组操作或指针操作访问字符串中的字符，哪种方法更好一些呢？只要使用方便，可以使用任意一种方法，
     *  也可以混合使用两种方法。在count_space函数的第2种写法中，不再需要变量i，而是把s作为指针来对函数进行一些简化。
     *  从传统意义上来说，C程序员更倾向于使用指针操作来处理字符串。
     * 2.字符串的形式参数应该声明为数组还是指针呢？count_space函数的两种写法说明了这两种选择；第1种写法把s声明为数组，第二种写法把s声明为指针。
     * 实际上这两种声明之间没有任何差异。
     * */

}

/**
 * 编写一个函数来统计字符串中空格的数量，利用数组取下标的方式写入如下
 * @param s 加上const表明count_spaces函数不会改变数组.
 * @return
 */
int count_spaces(const char s[]) {
    int count = 0, i;
    for (i = 0; s[i] != '\0'; i++) //通过空字符定位字符串的末尾
        if (s[i] == ' ')
            count++;
    return count;
}

/**
 * 通过指针算术运算来简化操作，不再需要变量i，而是利用s自身来跟踪字符串中的位置
 * 通过对s反复进行自增操作，count_space函数可以逐个访问字符串中的字符
 * @param s
 * @return
 */
int count_space(const char *s) {
    int count = 0;   /*注意：const没有阻止count_space函数对s的修改，它的作用是阻止函数改变s所指向的字符。而且，因为s是传递给
     count_space函数的指针的副本，所以对s进行自增操作不会影响原始的指针。*/
    for (; *s != '\0'; s++)
        if (*s == ' ')
            count++;
    return count;

}

/**
 * 使用C语言的字符串库:
 * 一些编程语言提供的运算符可以对字符窜进行复制、比较、拼接、选择子串等操作，但C语言的运算符根本无法操作字符串。
 * C语言中把字符串当作数组来处理，因此对字符串的限制方式和对数组的一样，特别是它们都不能用C语言的运算符进行复制和比较操作
 * 幸运的是，字符串的所有操作功能都没有丢失；C语言的函数库完成对字符串的操作提供了丰富的函数集。这些函数的原型驻留在<string.h>头，所以
 * 需要操作的程序应该包含下列的内容：
 */
void cases_13_5() {

    /**
     * 13.5.1:字符串的复制：strcpy函数
     * char *strcpy(char *s1,const char *s2);
     * strcpy函数把s2指向的字符串复制到s1指向的数组中，直到s2遇到第一个空字符为空(该空字符也需要复制)。strcpy函数返回s1(即指向目标
     * 字符串的指针)。这一个过程不会改变s2的指向的字符串，因此将其声明为const。
     */
    char str2[10];
    char str1[] = "test";
    strcpy(str2, "abed");//
    //打印查看下复制后的
    puts(str2);
    //不能把str2赋值给str1，但是可以使用strcpy函数
    strcpy(str1, str2);
    puts(str1);
    //大多数情况下我们会忽略strcpy函数返回值，但有时strcpy函数调用是一个更大的表达式部分，这时其返回值就比较有用了。
    //例如把一系列strcpy函数调用连接起来:
    char str3[20];
    char str4[20];
    strcpy(str3, strcpy(str4, "hello"));
    puts(str3);
    puts(str4);
    //⚠️存在安全问题，因为strcpy函数无法检查str4指向的字符串的大小是否真的适合str3指向的数组，如果str4字符串长度
    //超高str3数组的长度，strcpy函数会一直复制到第一个空字符为止，所以它会超过str3指向的数组的边界继续复制，出现数组越界
    //为了更安全的复制字符串的方法，推荐使用strncpy函数，它有第三个参数可以用来限制所复制的字符数

    // strncpy(str3,str4,sizeof(str3));只要str3足够装下存在str4的字符串(包括空串)复制就能正确完成。当然本身也不是没有风险。如果
    //str4中存储的字符串的长度大于str3数组的长度，strncpy会导致str3中的字符串没有终止运算符。下面是一种更安全的的用法；
    strncpy(str3, str4, sizeof(str3) - 1);
    str3[sizeof(str3) - 1] = '\0';
    //第二条语句确保str3总是以空字符结尾，即使strncpy没能从str4中复制到空字符

    /*13.5.2 求字符串的长度:strlen函数
     * 函数原型：
     * size_t strlen(const char *s);
     * */
    //strlen函数返回字符串s的长度，s中第一额空字符之前的字符个数(不包括空字符)
    int len;
    len = strlen("abc"); /*len is now 3*/
    printf("%d\n", len);
    len = strlen(""); /*len is 0*/
    len = strlen(str4);
    printf("%d\n", len); //当用数组作为实际参数时，strlen不会测量数组本身的长度，而是返回存储在数组中的字符串的长度。

    /*
     * 13.5.3 字符串的拼接：strcat函数原型如下
     * char *strcat(char *s1,const char *s2);
     * strcat函数把字符串s2的内容追加到字符串的s1的末尾，并且返回字符串s1的(指向结果字符串的指针).
     * */
    strcat(str4, "def");
    puts(str4);
    //同使用strcpy函数一样，通常忽略strcat函数的返回值
    strcat(str3, strcat(str4, "ghi"));//如果str3指向的数组没有大到足以容纳str4指向的字符串的字符，那么 strcat(str3, strcat(str4,"ghi"))
    //的结果将时不可预测的
    puts(str3);
    //同理，strncat函数更安全，但是速度也会慢一些
    strncat(str3, str4, sizeof(str3) - strlen(str3) - 1);//第三个参数，计算str3的剩余空间，然后减去1，确保为空字符留下空间

    /*13.5.4 字符串的比较：strcmp函数原型
     * int strcmp(const char *s1,const char *s2);
     * strcmp函数比较字符串s1和字符串s2，然后根据s1是小于、等于或大于s2。函数返回一个小于、等于、大于0的值。
     * 为了检查str1是否小于等于str2，可以写：
     * if(strcmp(str1,str2) <=0 )
     * 意思是: str1 <= str2?
     * 可以选择适当的关系运算符(<、<=、>、>=)或判等运算符(==、!=)，可以测试str1和str2之间的任何可能的关系
     * 只要满足下列两个条件之一，那么strcmp函数就认为s1是小于s2的：
     * 1.s1与s2的前i个字符一致，但是s1的第i+1个字符小于s2的第i+1个字符。例如，"abc"小于"bcd","abd"小于"abe"
     * 2.s1的所有字符与s2的字符一致，但是s1比s2短。例如，"abc"小于"abcd";
     * ⚠️
     * 当比较两个字符时，strcmp函数会查看字符对应的的数值码，一些底层字符集的知识可以帮助预测strcmp函数的结果：
     * ASCII字符集一些重要的性质：
     * 1.A~Z、a~z和0~9这几组字符的数值码是连续的。
     * 2.所有的大写字母都小于小写字母(在ASCII码中,65~90的编码表示大写字母，97～122编码表示的小写字母).
     * 3.数字小于字母(48~57的编码表示数字).
     * 4.空格符小于所有打印字符(ASCII码中空格符的值是32).
     * */


}

/**
 * 课堂经典案例remind.c的实现:题目需要多调试几次，多去理解，然后自己写出来,处理的比较巧妙
 */
void remind() {
    //把字符串存储在二维的字符数组中，数组的每一行包含一个字符串
    char reminders[MAX_REMIND][MSG_LEN + 3];//为什么是MSG_LEN+3?
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;
    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }
        printf("Enter day and reminder: ");
        scanf("%2d", &day); //确保用户输入两位数字以上，这样确保读入两个数字后停止
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        /*在C语言中，sprintf函数用于格式化并存储字符串缓冲区中的一系列字符。它与 printf 函数类似，
         * 但不是将格式化输出打印到控制台，而是将输出存储在字符数组，printf("format string", argument1, argument2, ...);
         * 除了前两个参数固定外，可选参数可以是任意个。buffer是字符数组名；format是格式化字符串（像："%3d%6.2f%#x%o",%与#合用时，
         * 自动在十六进制数前面加上0x）。只要在printf中可以使用的格式化字符串，在sprintf都可以使用。其中的格式化字符串是此函数的精华。
         * 作用非常多，这里是将day的值写到day_str中，该函数会自动添加一个空字符，
         * 其他作用可查看：https://www.jianshu.com/p/f2603444fee6*/
        read_line(msg_str, MSG_LEN);
        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            strcpy(reminders[j], reminders[j - 1]);
        strcmp(reminders[i], day_str);
        strcat(reminders[i], msg_str);
        num_remind++;

    }
    printf("\nDay reminder\n");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n",reminders[i]);


}


/**
 * 搜索字符串的结尾,即获取字符串的长度实现
 * @param s
 * @return
 */
size_t strlen(const char *s) {
    //方法一：
//    size_t n;
//    for (n = 0; *s != '\0'; s++)
//        n++;/*指针s从左到右扫描整个字符串，变量n记录当前已经扫描过的字符数量。当s最终指向一个空字符串时，n所包含的值就是字符串的长度*/
//    return n;
    //方法二:把n的初始化移到它的声明中
//    size_t n = 0;
//    for (; *s != '\0'; s++)
//        n++;
//    return n;
    //方法三:继续优化，条件*s!='\0'与*s=0是一样的，因为空字符的整数值就是0，而测试*s!=0与测试*s是一样的，两个都在*s不为0时结果为真
//    size_t n = 0;
//    for (; *s; s++) /*字符'\0'： ASCII 码为0，表示一个字符串结束的标志。 这是转义字符（整体视为一个字符）。
//                    * 由于内存中存储字符，依然是存储的是对应字符集的字符编码，所以内存中的表现形式为00000000*/
//        n++;
//    return n;

    //方法四：继续优化，如果在同一个表达式中对s进行自增操作并且测试*s是可行的；
//    size_t n = 0;
//    for (; *s++;)
//        n++;
//    return n;
    //方法五：用while语句替换for语句
//    size_t n=0;
//    while (*s++)
//        n++;
//    return n;
    /*方法六：虽然上面的五种对strlen函数进行了相当大精简，但是可能仍没有提高它的运行速度。至少对于一些编译器来说下面的版本
     * 确实会运行的更快一些,该版本通过定位空字符的位置来计算字符串的长度，然后利用空字符的地址减去字符串中第一个字符的地址。
     * 运行速度的提升得益于不需要在while循环内部对n进行自增操作。请注意，在p的声明中出现了单词const,如果没有它，编译器
     * 会注意到s赋值给p会给s指向的字符串造成一定的风险。
     * 惯用方法：
     * while(*s)
     *  s++;
     * 和相关的
     * while(*s++)
     *  ;
     * */
    assert(s);///断言源字符串和目标空间都不能为空指针
    const char *p = 0;
    while (*s)
        s++;
    return s - p;
}

/**
 * 字符窜的复制实现：
 * 在这里需要注意：
1、源字符串必须以 '\0' 结束。
2、会将源字符串中的 '\0' 拷贝到目标空间。
3、目标空间必须足够大，以确保能存放源字符串。
4、目标空间必须可变。
 * @return
 */
char *my_str_cpy(char *dest, const char *src) { //这里用const修饰所指向的源字符串，因为源字符串是常量字符串，不能被修改
    char *ret = dest;
    assert(dest);//断言源字符串和目标空间都不能为空指针
    assert(src);
    while (*dest++ = *src++)//一个字符串一个字符串的拷贝，遇到'\0'结束
    { ;
    }
    return dest;//返回目标空间的起始地址
}

/**
 * 只拷贝字符串里面的几个字符实现
 * @param dest
 * @param src
 * @return
 */
char *my_str_cpy_02(char *dest, const char *src, size_t n) {
    char *ret = dest;
    assert(dest);
    assert(src);
    int i = 0;
    for (i = 0; i < n; i++)//要拷贝几个字符，循环几次
    {
        *dest++ = *src++;
    }
    return ret;
}

/**
 * 字符串的拼接的多种实现:
 * 1、源字符串必须以 '\0' 结束，目的地也必须以 '\0' 结束
   2、目标空间必须有足够的大，能容纳下源字符串的内容。
   3、目标空间必须可修改
 * @param s1
 * @param s2
 * @return
 */
char *test_str_cat_01(char *s1, const char *s2) {
    assert(s1);
    assert(s2);//断言源字符串和目标空间都不能为空指针
    //第一种版本是比较冗余的
    char *p = s1; //把p设定为指向s1的第一个字符
    //第一步：确定字符串s1末尾空字符的位置，并且使指针p指向它
    while (*p != '\0')
        p++;
    //第二步：把字符串s2中的字符逐个复制到p所指向的位置
    while (*s1 != '\0') {
        *p = *s2;
        p++;
        s2++;
    }
    *p = '\0';
    return s1;

}

/**
 * 字符串的拼接实现的方法二：类似strlen函数，可以简化strcat函数的定义
 * @param s1
 * @param s2
 * @return
 */
char *test_str_cat_02(char *s1, const char *s2) {
    char *p = s1;
    while (*p)
        p++;
    while (*p++ = *s2++); //这是惯用方法
    return s1;//返回的目标空间的起始地址
}

/**
 * 有长度限制的字符串的拼接
 * @param dest
 * @param src
 * @param n
 * @return
 */
char *test_str_cat_03(char *dest, const char *src, size_t n) {
    char *ret = dest;
    assert(dest);
    assert(src);
    int i = 0;
    while (*dest != '\0')//找到目标空间的结束标志处，然后开始连接
        dest++;

    for (i = 0; i < n; i++)//要连接几个字符，循环几次
        *dest++ = *src++;

    return ret;//返回目标空间的起始地址
}


/**
 * 字符串比较大小的方法实现
 * @param str1
 * @param str2
 * @return
 */

int strcmp_01(const char *str1, const char *str2) {
    assert(str1);
    assert(str2);
    while (*str1 == *str2)//先看首字符如果这两个字符是否相等，如果相等继续往下比，不相等跳出去比较大小
    {
        if (*str1 == '\0')//判断是否已经比完了所有字符，如果已经比完了返回0，说明这两个字符串相等
            return 0;

        else//如果没有比完，继续往下一个比
        {
            str1++;
            str2++;
        }
    }
    //如果两个字符不相等，那就比大小，返回大于0的数则说明str1>str2，反之小于。
    return *str1 - *str2;
}

/**
 * 两个字符串比较大小的实现方法
 * @param s
 * @param t
 * @return
 */
int strcmp_02(char *s, char *t) {
    int i = 0;
    for (; s[i] == t[i]; i++)
        if (s[i] == '\0')
            return 0;
    return s[i] - t[i];/*函数的返回值是字符产s和字符串t中第一个"不匹配"字符的差。如果s指向的字符串
 * 小于t所指向的，那么结果为负数。如果s指向的字符串"大于"t指向的，则结果为整数。*/
}

/**
 * 字符串指定长度范围内比较大小
 * @param str1
 * @param str2
 * @param n
 * @return
 */
int strcmp_03(const char *str1, const char *str2, int n) {
    int i = 0;
    for (i = 0; i < n; i++)//需要比较几个字符循环几次
    {
        if (*(str1 + i) == *(str2 + i))//先看首字符如果这两个字符是否相等，如果相等继续往下比，不相等跳出去比较大小
        {
            if (*str1 == '\0')//判断是否已经比完了所有字符，如果已经比完了返回0，说明这两个字符串相等
            {
                return 0;
            } else {//如果没有比完，继续往下一个比
                str1++;
                str2++;
            }
        }
//如果两个字符不相等，那就比大小，返回大于0的数则说明str1>str2，反之小于。
        return *str1 - *str2;
    }
}

/**
 * 字符串数组的实现
 */
void cases_13_7() {
    // char planets[][8]={"Mercury","Venus","Earth",
    //                   "Mars","Jupiter","Saturn","Uranus","Neptune","Pluto"};
    //C语言的二维数组要求指明列数，这样声明方式弊端是浪费空间
    //使用下面的方式:把plants看作是元素是指向字符串的指针的数组
    char *planets[] = {"Mercury", "Venus", "Earth", "Mars",
                       "Jupiter", "Saturn", "Uranus", "Neptune", "Pluto"};
    //这样存储方式上面的声明方式是极大不同的，这样不浪费空间，而且操作灵活方便
    //获取搜寻以字母M开头的字符串的实现
    for (int i = 0; i < 9; i++) {
        if (planets[i][0] == 'M')
            printf("%s begins with M\n", planets[i]);

    }
}