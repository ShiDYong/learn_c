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


/*
 * 课后练习题12:
 * 找出下列函数中的错误，并说明如何修正：
 *
 */
int count_periods(const char *fileName) {

    FILE *fp;
    int n = 0;
    char ch;
    // if ((fp = fopen(fileName, "r")) != NULL) {
    //    c = fgetc(fp);
    //  while (fgetc(fp) != EOF)
    //   if (getc(fp) == '.')
    // 错误所在：给定函数的错误在于，它在 while 循环的每次迭代中从文件中读取两个字符，但仅检查第二个字符是否为句点 ('.')，
    // 如果第二个字符是句点，则递增 n。 这会导致函数错过计算文件中的某些周期。
    //要修复此错误，您应该读取一个字符一次并在循环条件中检查它，然后如果该字符是句点则递增 n
    //     n++;
    //fclose(fp);
    // }
    if ((fp = fopen(fileName, "r")) != NULL) {
        while ((ch = fgetc(fp)) != EOF) {
            if (ch == '.')
                n++;
        }
        fclose(fp);


    }
    return n;
}

/*
 * 练习13题目：
 * 编写下列函数：函数应返回名为filename的文本文件中第n行的长度(假定文件的第一行是行1)。如果该行不存在，函数返回0
 */
int line_length(const char *filename, int n) {
    //方法一：通过一次读取一行的函数计算
    FILE *fp;
   /*  char buffer[1024];
     int currentLine = 1;
     if ((fp = fopen(filename, "r")) != NULL) {
         //先把小于指定的行的行号跳过
         while (currentLine < n) {
             //要找到该行不存在
             if (fgets(buffer, sizeof(buffer), fp) == NULL) {
                 //Reached the end of the line before reaching the desired line
                 fclose(fp);
                 return 0;
             }
             currentLine++;
         }
         if (fgets(buffer, sizeof(buffer), fp) != NULL) {//指定行数读取
             //Calculate the length of the line
             int length = 0;
             for (int i = 0; buffer[i] != '\0' && buffer[i] != '\n'; i++)
                 length++;
             fclose(fp);
             return length;
         }
         //If fgets returns NULL,it means we reached the end of the file
         fclose(fp);
         return 0;
     } else
         return 0;//打开文件失败*/

    //方法二：通过单个字符读取,写法更加简洁
    int length = 0;

    /*if ((fp = fopen(filename, "r")) != NULL) {
        int lineNumber = 1;
        int c;

        // Traverse through the file until the desired line or EOF is reached
        while (lineNumber < n && (c = fgetc(fp)) != EOF) {
            if (c == '\n') {
                lineNumber++;
            }
        }

        // If the desired line is found, calculate its length
        if (lineNumber == n) {
            while ((c = fgetc(fp)) != '\n' && c != EOF) {
                length++;
            }
        }

        fclose(fp);
    }

    return length;*/

    //实现方法三：文本文件的行通常是以换行符标识的，因此程序里只需要统计第n-1个换行符到n个换行符之间的字符数量即可
    char ch;
    if ((fp = fopen(filename, "r")) != NULL) {
        while ((ch = fgetc(fp)) != EOF && n > 1)
            if (ch == '\n') n--;
        while ((ch = fgetc(fp)) != EOF && ch != '\n') length++;
        fclose(fp);
    }
    return length;


}


int main(int argc, char *argv[]) {
    //课后练习题目12:
    //FILE *fp = fopen("/Users/yongshi/Downloads/MyCode/C_Programming/22 IO/cases/fopen.txt", "rb");
    //这样的调用方式是错误的
    // count_periods(fp);
    //具体调用方式如下：使用绝对路径
    /* const char *filename = "22 IO/exerices/open.txt";
     int periodCont = count_periods(filename);
     printf("Number of periods in %s: %d\n", filename, periodCont);
 */

    //课后练习题13:
    const char *filename = "22 IO/exerices/open.txt";
    int lineNumber = 3;
    int length = line_length(filename, lineNumber);
    if (length > 0)
        printf("Length of line %d: %d\n", lineNumber, length);
    else
        printf("Line %d doesn't exist or there was an error.\n", lineNumber);



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
       此时可以通过编译，但是这时判等运算符的优先级高于赋值运算符，因此先计算表达式getc(source_fp) != EOF
       ，得到的布尔值，在将布尔值赋值给ch。因此目的文件将只会写入真，直到文件读取结束时写入假，会错误地写入文件内容


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
