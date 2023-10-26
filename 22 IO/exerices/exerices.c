/********************************************************************************
* @author: mason shi
* @date: 2023/10/1 17:06
* @version: 1.0
* @description: 第22章课后练习题
********************************************************************************/
#include<stdio.h>
#include <stdlib.h>

static FILE *get_position(FILE *fp, fpos_t *position);

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


/*
 * Exercises 22.14
 * (a) Write your own version of the `fgets` function. Make it behave as much like
    the real `fgets` function as possible; in particular, make sure that it has the
    proper return value. To avoid conflicts with the standard library, don't name
    your function `fgets`.
    “restrict”关键字主要用在函数参数中，指示在该函数内的受限指针的生命周期内，
    不能通过任何其他指针访问所指向的内存（通过受限指针）。
    这允许编译器进行某些优化并假设不存在别名问题，从而可能产生更高效的代码。
 */
char *myFgets(char *restrict str, int n, FILE *restrict file) {
    FILE *fp;
    int c, len = 0;
    if ((fp = fopen(file, "r")) != NULL) {
        while (len < n - 1) {
            c = fgetc(fp);
            if (c == EOF || c == NULL) {
                if (len == 0 || ferror(stderr))
                    return NULL;
                break;
            }
            str[len++] = c;
            if (c == '\n') //是换行符\n
                break;
        }
    }

    str[len] = '\0'; //字符串是以空字符结尾的'\0';
    fclose(fp);
    return str;

}

/*
 * 实现的方法二:按照行读取数据，每行读取多少个字符
 * fgets函数的主要功能是从任意的流中逐个读取字符，并且把它们存储在s所指向的字符数组中，
 * 直到它读到换行符或者第n个字符时停止。因此可以使用fgetc函数对其封装，封装过程中需要注意
 * 判断换行符和读取字符数量为n两个限制条件
 */
char *myfgets(char *restrict str, int n, FILE *restrict stream) {
    char ch;
    if (str == NULL || stream == NULL) return NULL;
    for (int i = 0; i < n; i++) {
        ch = fgetc(stream);
        if (ch != '\n') *(str + i) = ch; //充分利用指针特性
        else break;

    }
    return str;


}

/*
 * fputs其主要功能向输出流写入字符串s，因此可以使用fputc函数进行封装
 */
int myfputs(char *restrict s, FILE *restrict stream) {
    int i = 0;
    if (s == NULL || stream == NULL) return EOF;
    while (*(s + i) != '\0') fputc(*(s + (i++)), stream); //要理解这种简洁的写法
    return i;
}


/*
 * Exercises: 22.15:
 * 编写记录fseek函数来在二进制文件中执行下列文件中定位操作，其中，二进制文件的数据以64字节“记录”的形式进行排列。
 * 采用fp作为下列每种情况中的文件指示。
 * a.移动到记录n的开始处(假设文件中的首记录为记录0)。
 * b.移动到文件中最后一条记录的开始处。
 * c.向前移动一条记录。
 * d.向后移动一条记录.
 */
void test_fseek_fcn(FILE *fp) {
    /*
     * 通常情况下在C语言程序中使用fopen函数打开文件时，系统会自动将文件位置设置为在文件的起始处，在执行读或写的操作时，文件位置会自动
     * 推进，并且允许按照顺序贯穿整个文件。当需要在文件中跳过某些数据直接寻找目标位置时，则需要使用fseek函数；
     * int fseek(FILE * stream, long int offset, int whence);
     * fseek函数用于改变与第一个参数(即文件指针)相关的文件位置。第二个参数说明新位置时根据文件的起始处、当前位置还是文件末尾来计算。第三个
     * 参数表示文件位置。例如：SEEK_SET表示文件的起始处，SEEK_CUR表示文件的当前位置，SEEK_END表示文件的末尾处。
     * fseek ( fp, 0L,SEEK_SET); 定位到文件开始处。
       fseek ( fp,+10L,SEEK_CUR);定位在当前位置的后10个字节处。
     　fseek (fp,-10L,SEEK_END);定位在文件末尾，然后向前移动10个字节处。
     */
    fpos_t position;

    int record_size = 64L;
    int n = 3;//移动到记录为3的开始处
    get_position(fp, &position);
    printf("没有开始移动前文件的位置：%11lld\n", position);

    //a.移动到记录n的开始处(假设文件中的首记录为记录0)。
    fseek(fp, n * record_size, SEEK_SET);
    get_position(fp, &position);
    printf("移动到记录n的开始处后的位置：%11lld\n", position);
    //b.移动到文件中最后一条记录的开始处
    fseek(fp, record_size, SEEK_END);
    get_position(fp, &position);
    printf("移动到文件中最后一条记录的开始处：%11lld\n", position);
    //c.向前移动一条记录。
    fseek(fp, -record_size, SEEK_CUR);
    get_position(fp, &position);
    printf("向前移动一条记录后的位置：%11lld\n", position);
    //d.向后移动两条记录.
    fseek(fp, 2 * record_size, SEEK_CUR);
    get_position(fp, &position);
    printf("向后移动一条记录后的位置：%11lld\n", position);


}


static FILE *get_position(FILE *fp, fpos_t *ptr) {
    if (fp == NULL) return NULL;
    if (fgetpos(fp, ptr) != 0) {
        perror("Error getting file position");
        fclose(fp);
        exit(EXIT_FAILURE);
    }
    return fp;

}

/*
 * 获取文件最后一行的内容并返回来
 * 1.打开文件并将其指针移动到文件的末尾。
 * 2.向前遍历文件内容，直到找到最后一个换行符('\n').
 * 3.从最后一个换行符的位置开始，读取直到文件末尾，即最后一行
 */
char *find_last_line(FILE *restrict file) {
    FILE *fp;
    char ch;
    long file_size;
    //另外加的获取位置，方便进行调试
    fpos_t position;

    //打开文件
    if ((fp = fopen(file, "r")) == NULL) {
        perror("Open file failed.\n");
        return NULL;
    }
    //将文件指针移动到文件的末尾，并获取文件大小
    fseek(fp, 0, SEEK_END);
    get_position(fp, &position);
    printf("获取文件文件指针挪动到文件末尾的时文件的位置：%11lld\n", position);
    if ((file_size = ftell(fp)) == -1) {
        perror("ftell");
        fclose(fp);
        return NULL;
    }
    //开始从文件末尾向前查最后一个换行符
    long pos = file_size - 1;
    while (pos >= 0) {
        fseek(fp, pos, SEEK_SET);
        get_position(fp, &position);
        printf("查找最后一个换行符的时文件指针的变化：%11lld\n", position);
        ch = fgetc(fp);//每调用一次，文件位置就自增1
        get_position(fp, &position);
        printf("fgetc方法之后完后文件位置：%11lld\n", position);
        if (ch == '\n')
            break;//找到最后一个换行符
        pos--;
    }
    //读取最后一行
//    fseek(fp, pos + 1, SEEK_SET);
//    while (1) {
//        ch = fgetc(fp);
//        if (ch == EOF)
//            break;
//        *(str++) = ch;//保存返回的
//        putchar(ch);//直接输出来的
//
//    }
    if (pos >= 0) {
        long line_size = file_size - pos - 1;
        //利用动态分配内存
        char *last_line = (char *) malloc(line_size + 1);
        if (last_line == NULL) {
            perror("Allocation memory failed.\n");
            fclose(fp);
            return NULL;
        }
        fseek(fp, pos + 1, SEEK_SET);
        //利用块读取，提高效率
        fread(last_line, 1, line_size, fp);
        last_line[line_size] = '\0';
        return last_line;
    } else
        printf("文件为空或没有换行符号.\n");
    fclose(fp);


}

/*
 * 通过行读取，提高性能
 */
char *get_last_line(FILE *restrict file) {
    FILE *fp;
    char *last_line = NULL;
    char *current_line = NULL;
    size_t len = 0;//len is the length of the allocated buffer.
    ssize_t read; //read stores the return value of getline.

    //打开文件
    if ((fp = fopen(file, "r")) == NULL) {
        perror("Open file failed.\n");
        return NULL;
    }
    // 逐行读取文件
    //C 中的 getline 函数用于从文件流或标准输入中读取文本行。 它动态分配内存来存储行并根据需要调整缓冲区大小。
    // 当您事先不知道行的长度时，这尤其有用。
    while ((read = getline(&current_line, &len, fp)) != -1) {
        if (last_line != NULL) {
            free(last_line);  // 释放之前的行
        }
        last_line = current_line;
        current_line = NULL;
    }
    // 如果成功读取了最后一行，将其输出
    if (last_line != NULL) {
        printf("最后一行: %s", last_line);
        return last_line;
    } else {
        printf("文件为空或读取失败\n");
    }
    free(last_line);
    free(current_line);
    // 关闭文件
    fclose(fp);
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
    //int lineNumber = 3;
    //int length = line_length(filename, lineNumber);
//    if (length > 0)
//        printf("Length of line %d: %d\n", lineNumber, length);
//    else
//        printf("Line %d doesn't exist or there was an error.\n", lineNumber);

    //获取文件最后一行
    //char *str[1024];使用动态分配内存
    char *str;
    if ((str = get_last_line(filename)) != NULL)
        printf("Last line content: %s\n", str);
    else
        printf("Operation failed.\n");

    //课后练习题14
//    FILE *fp;
//    char *str[1024];
//    int n = 64;
//    if ((fp = fopen("22 IO/exerices/open.txt", "r")) != NULL) {
//        myfgets(str, n, fp);
//        printf("read data is: %s\n", str);
//    } else
//        printf("Open file failed.\n");
//    char *str = "Hello world today!";
//    if ((fp = fopen("22 IO/exerices/open.txt", "r")) != NULL) {
//        // printf("Read number of characters are : %d\n", myfputs(str, fp));
//        test_fseek_fcn(fp);
//    } else
//        printf("Open file failed.\n");

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
    if ((dest_fp = fopen(argv[2], "w+")) == NULL) {
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

