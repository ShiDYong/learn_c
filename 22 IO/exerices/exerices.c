/********************************************************************************
* @author: mason shi
* @date: 2023/10/1 17:06
* @version: 1.0
* @description: 第22章课后练习题
********************************************************************************/
#include<stdio.h>
#include <stdlib.h>

void test_exec01_03();


void test_exec04_05() {
    //课后练习04:如果printf函数用%#012.5g作为转换函数说明来执行显示操作，请指出下列数字显示的形式
    printf("%#012.5g\n", 83.7361);
    /*
    # 标志用于指示即使没有小数位，输出也应包含小数点。
    012 指定 12 个字符的字段宽度，其中包括数字空格、小数点和填充（如果需要）。
    .5 指定精度应为小数点后 5 位。
    g 格式用于选择 %e 或 %f 表示形式中较短的一个，且不带尾随零。*/
    printf("%#012.5g\n", 29748.6607);
    printf("%#012.5g\n", 1054932234.0);
    printf("%#012.5g\n", 0.0000235218);

    /*
     * Exercise 22.05
     * Is there any difference between the 'printf' conversion specifications '%.4d
     * and '%04d'? If so,explain what it is.
     */
    /*
     * 解析：对于整数的转换说明，例如%d，%i等，精度表示最小的整数位数，且如果位数不够，则添加前导0.因此
     *      %.4d和%04d对于整数的转换说明%d来说没有区别，显示效果是当位数不够时，添加前导0.
     */

}

/*
 * 课后练习06:
 *    编写printf函数的调用，要求如果变量widget(int 类型)的值为1，则表示1 widget;如果值为n，则显示n widgets.不允许使用if语句
 *    或任何其他语句，答案必须是单独的一个printf调用。
 */
void test_exec06_08() {
    int widget = 1;
    printf("%d widget%s", widget, widget != 1 ? "s\n" : "\n");

    /*
     * Exercise 22.08:
     *       In previous chapters, we've use the 'scanf' format string "%c" when we wanted to skip white-sapce
     *       characters and read a nonblank character.Some programmers use "%1s" instead. Are the two techniques
     *       equivalent ? If not ,what are the differences?
     *
     */

    /*
     * 解析scnaf函数的转换说明符%1s,表示以字符串的形式读取数据，且字符串的最小宽度为1，因此可以使用%1s来读取字符串。但是scanf函数中
     * 使用" %c"格式串和"%1s"格式串并不完全等价，这主要是由字符串结尾的空字符引起的。因此，如果只是读取一个非空白字符，建议使用" %c".
     */

}


int main(int argc, char *argv[]) {
    //test_exec01_03();
    //test_exec06_08();
    /*
     *  Exercise 22.10
   The `fcopy.c` program has one minor flaw: it doesn't check for errors as it's
    writing to the destination file. Errors during writing are rare, but do
    occasionally occur (the disk might become full, for example). Show how to add
    the missing error check to the program, assuming that we want it to display a
    message and terminate immediately if an error occurs.
    */
    FILE *source_fp, *dest_fp;
    int ch;
    if (argc != 3) {
        fprintf(stderr, "usage: fcopy source dest.\n");
        exit(EXIT_FAILURE);
    }
    //这里采用rb和wb作为文件模式，使fcopy程序既可以复制文本文件也可以复制二进制文件，如果
    //采用r和w来代替，那么程序将无法复制二进制文件。
    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }
    /*
     * Exercise 22.11:
     *  下面出现了这个循环：
       while ((ch = getc(source_fp)) != EOF)
            putc(ch, dest_fp)
       假设省略表达式ch=getc(source_fp)两边的圆括号：
       while (ch = getc(source_fp) != EOF)
            putc(ch,dest_fp);
       这个程序可以无错通过编译吗？如果可以，那么运行程序会做什么呢？


     */

    while ((ch = getc(source_fp)) != EOF) {
        //判断写入的过程中是否出现异常，比如磁盘可能会满
        if (putc(ch, dest_fp) == EOF) {
            printf(stderr, "Error: writing to file failed.\n");
            exit(EXIT_FAILURE);
        }

    }
    fclose(source_fp);
    fclose(dest_fp);


    return 0;
}
