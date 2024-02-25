/********************************************************************************
* @author: mason shi
* @date: 2023/7/30 15:47
* @version: 1.0
* @description: 第十三章的课后练习题
********************************************************************************/
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<stdlib.h>
#include <stdbool.h>

void exec13_01();

void exec13_02();

void exec13_03();

void exec13_04_read_line();

int read_lines_a(char *str, int n);

int read_lines_b(char *str, int n);

int read_lines_c(char *str, int n);

int read_lines_d(char *str, int n);

void exec13_05_capitalize(char *str, int n);

void capitalize_optimize_pointer(char *str);

void capitalize_optimize_array(char str[]);

void exec13_06_censor(char *str);

void exec13_07();

void exec13_08();

char *duplicate(const char *p);

void exec13_09();

int strcmp_two(char *s, char *t);

void get_extension(const char *file_name, char *extension);

void build_index_url(const char *domain, char *index_url);

void exec14_puts();

int f(char *s, char *t);

int main(void) {
    //exec13_01();
    //exec13_02();
    // exec13_03();
    //exec13_04_read_line();
//     char str[10]={'a','b','c','1','3','!',' ','d','e','y'};
//    exec13_05_capitalize(str,sizeof(str));
    // char str[] = "Hello, World 123!";
    //capitalize_optimize_array(str);
    // capitalize_optimize_pointer(str);
    // char str[] = "It's food fool hood!";
    // exec13_06_censor(str);
    // printf("You entered: %s\n", str);
    // exec13_07();
    // exec13_08();
    // duplicate(str);
    //exec13_09();
//    char str1[] = "ab";
//    char str2[] = "abc";
    //printf("返回结果%d\n", strcmp_two(str1, str2));
//    char str[] = "memo.txt.html";
//    char extension[256];
//
//    get_extension(str, extension);
//    printf("extension is %s\n", extension);
//    printf("str is %s\n", str);
//    char domain[] = "google.com";
//    char index_url[100];
//    build_index_url(domain, index_url);
//    printf("拼接的域名是 %s\n", index_url);
//  exec14_puts();
//    a.f("abcd","babc")的值是多少？
//    char s[] = "abcd", t[] = "babc";
//    printf("f函数返回的值是%d",f(s, t));
//     b.f("abcd","bcd")的值是多少？
//    char s[] = "abcd", t[] = "bcd";
//    printf("f函数返回的值是%d",f(s, t));
//     c.当传递两个字符串s和t时，函数f的返回值一般是什么？返回值一般是整数
}


/**
 * 课后练习题01:
 * 下面的函数调用应该只输出一个换行符，但是其中有一些是错误的。请指出哪些是错误的，并说明理由。
 */
void exec13_01() {
    //a.
    printf("%c", '\n');
    //b.要求打印的是字符
    //  printf("%c", "\n");//will not work as `%c` expects a `char` and receives a `string`
    //c.
    //  printf("%s", '\n');//will not work as `%s` expects a `string` and receives a `char`.
    //d.
    printf("%s", "\n");
    //e.
    // printf('\n');//will not work as `printf` expects a `string`.
    //f
    printf("\n");
    //g
    putchar('\n');
    //h
    // putchar("\n");// will not work as `putchar` expects a `char`.
    //i
    //  puts('\n');//will not work as `puts` expects a `string`.
    //j
    puts("\n");
    //k
    puts(""); //will write two newline characters.


}

/**
 * 课后练习题02:
 * 假设p的声明如下：
 * char *p = "abc";
 * 下列哪些函数调用是合法的？请说明每个合法的函数的调用输出，并解释为什么其他的是非法的。
 */
void exec13_02() {
    char *p = "abc"; //这个赋值不是复制"abc"中的字符，而是使p指向字符串的第一个字符
    //a.Illegal: `putchar` expects a `char`, receives a pointer to `char`.
    //putchar(p);
    printf("abc");//当调用printf函数时，会传递"abc"的地址(即指向存储字母a的内存单元的指针),输出：abc.

    //b.
    putchar(*p); //输出‘a’

    //c.
    puts(p);//`abc\n`

    //d.Illegal: `puts` expects a `char *` and receives a `char`.
    // puts(*p);
}

/**
 * 课后练习题13:
 * 假设按照如下方式调用scanf函数：
 * scanf("%d%s%d",&i,s,&j);
 * 如果用户输入12abc34 56def78,那么调用后i、s和j的值分别是多少？(假设i和j是int类型变量，s是字符数组)
 */
void exec13_03() {
    int i, j;
    char s[10]; //不能声明为指针数组形式，char *p,非报空指针
    printf("Enter a message: ");
    scanf("%d%s%d\n", &i, s, &j);
    printf("%d%s%d\n", i, s, j);
    /*
     * i = 12
       s = "abc34"  // Note that s is a string (char array) and will store the value as a string
       j = 56
*/
    /*
    %d: This format specifier reads an integer. The input begins with 12,
    so i will be assigned the value 12.
    %s: This format specifier reads a string (sequence of characters). It reads
    characters until a whitespace is encountered. In this case, it will read abc34.
    As s is an array of characters, it will store the string "abc34" in the array.
    %d: This format specifier reads another integer. The input after the first %s was
    abc34, which means the next available integer is 56, so j will be assigned the value 56.
*/

}

/**
 * 课后练习题04:按照下述要求分别修改read_line函数:
 * a.在开始存储输入字符前跳过空白字符。
 * b.在遇到第一额空白字符时停止读入。提示：调用isspace函数来检查字符是否为空白字符。
 * c.在遇到第一个换行符时停止读入，然后把换行符存储到字符串中。
 * d.把没有空间存储的字符留下以备后用。
 */
void exec13_04_read_line() {
    char input[100];
    // read_lines_a(input, sizeof(input));
    // read_lines_b(input, sizeof(input));
    // read_lines_c(input, sizeof(input));
    read_lines_d(input, sizeof(input));

    printf("You entered: %s\n", input);

}

/**
 * 实现：a.在开始存储输入字符前跳过空白字符。
 * (a) Skip whitespace before beginning to store input characters:
 * @param str
 * @param n
 * @return
 */
int read_lines_a(char *str, int n) {
    int ch, i = 0;
    // Skip leading whitespace characters
    while ((ch = getchar()) != EOF && isspace(ch));
    while (ch != EOF && ch != '\n' && i < n - 1) {
        str[i++] = ch;
        ch = getchar();
    }
    // Null-terminate the string
    str[i] = '\0';
    return i;


}


/**
 *
 * b.在遇到第一个空白字符时停止读入。提示：调用isspace函数来检查字符是否为空白字符
 * @param str
 * @param n
 * @return
 */
int read_lines_b(char *str, int n) {
    int ch, i = 0;
    //Skip whitespace before beginning to store input characters
    while ((ch = getchar()) != EOF && isspace(ch));
    // Store input characters until whitespace or buffer capacity
    while (ch != EOF && ch != '\n' && i < n - 1) {
        if (isspace(ch))
            break;
        else {
            str[i++] = ch;
            ch = getchar(); //一定不要忘记这里ch=getchar()，不然不能循环
        }

    }
    str[i] = '\0';
    return i;


}

/**
 * c.在遇到第一个换行符时停止读入，然后把换行符存储到字符串中。
 * @param str
 * @param n
 * @return
 */
int read_lines_c(char *str, int n) {
    int ch, i = 0;
    while ((ch = getchar()) != EOF && isspace(ch));
    while (ch != EOF && i < n - 1) {
        if (ch == '\n') {
            str[i++] = ch;
            break;
        } else {
            str[i++] = ch;
            ch = getchar();
        }
    }
    str[i] = '\0';
    return i;


}

/*
 *  * d.把没有空间存储的字符留下以备后用
 */
int read_lines_d(char *str, int n) {
    int ch, i = 0;

    // Skip leading whitespace characters
    while ((ch = getchar()) != EOF && isspace(ch));

    // Store input characters until buffer capacity
    while (ch != EOF && i < n - 1) {
        str[i++] = ch;
        ch = getchar();
    }

    // Null-terminate the string
    str[i] = '\0';

    // Consume any remaining characters in the input buffer
    while (ch != EOF && ch != '\n') {
        ch = getchar();
    }

    return i;
}

/**
 * 课后练习题05
 */
void exec13_05_capitalize(char *str, int n) {
    /*a.编写名为capitalize的函数，把参数中的字母都改成大写字母。参数是空字符结尾的字符串，且此字符串可以包含任意字符而不仅是字母
     * 。使用数组取下标的操作访问字符串中的字符。提示：使用toupper函数把每个字符转换成大写*/
    for (int i = 0; i < n; i++)
        if (isalpha(str[i]))
            str[i] = toupper(str[i]);



    /*b.重写capitalize函数，这次使用指针算术元素符访问字符串中的内容。*/
    char *p = str;
    for (; p < str + n; p++)
        if (isalpha(*p))
            *p = toupper(*p);


}

/**
 * 对上面的方法进一步优化使用算术指针的方式
 * @param str
 */
void capitalize_optimize_pointer(char *str) {
    //方式一：
    if (str == NULL)
        return;// Handle null pointer gracefully
//    for (int i = 0; str[i] != '\0'; i++)
//        if (isalpha(str[i]))
//            str[i] = toupper(str[i]);
//


    //方式二：使用算术指针运算符
    // Use a pointer to traverse the string
    char *p = str;
    while (*p != '\0') {
        if (isalpha(*p))
            *p = toupper(*p);
        p++;// Move the pointer to the next character
    }


}


/**
 * 使用数组访问下标的方式
 * @param str
 */
void capitalize_optimize_array(char str[]) {
    //方式一：
    int i = 0;
    while (str[i] != '\0') {
        if (isalpha(str[i]))
            str[i] = toupper(str[i]);
        i++;
    }
}

/**
 * 课后练习题06:
 * 编写名为censor的函数，把字符串中出现的每一处foo替换为xxx。例如，字符串"food fool"会变为
 * "xxxd xxxl"。在不失去清晰性的前提下程序越短越好。
 * @param str
 */
void exec13_06_censor(char *str) {
    char *p = str;
    if (str == NULL)
        return;
    while (*(p + 2) != '\0') {
        if (*p == 'f' && *(p + 1) == 'o' && *(p + 2) == 'o')
            *p = *(p + 1) = *(p + 2) = 'x';
        p++;

    }


}

/**
 * 课后练习07:
 * 假设str是字符数组，下面那条语句与其他3条语句不等价。
 */
void exec13_07() {
    char str[] = "abc";
    //a.
    *str = 0;    //(a) *str = 0;这将数组 str 的第一个字符设置为空终止符“\0”，从而有效地创建一个空字符串。
    printf("%s\n", str);//没有打印出任何
    //b.
    str[0] = '\0';
    printf("%s\n", str); //(b) str[0] = '\0';这与 (a) 相同，将数组 str 的第一个字符设置为空终止符，创建一个空字符串。

    //c.
    strcpy(str, "");
    printf("%s\n", str);//(c) strcpy(str, "");这会将空字符串 "" 复制到数组 str 中，从而有效地使 str 成为空字符串。


    //d.单独会打印出abc
    strcat(str, "");
    printf("%s\n", str); //(d) strcat(str, "");：这与其他语句不同。 strcat 用于连接（追加）两个字符串。
    // 但是，在这种情况下，第二个参数是空字符串“”，因此 strcat 将不执行任何操作，并且 str 将保持不变。
    //关键区别在于 (d) 尝试将空字符串连接到原始字符串，这不会更改原始字符串。
    // 其他三个选项直接使数组str成为空字符串。



}

/**
 * 课后练习题08:
 * 在执行下列语句后，字符串中str的值是什么？
 */
void exec13_08() {
    //关键点要注意使用的字符串的容量是否足够，不然容易出现意想不到的错误.
    char str[] = "abc123212323389";
    strcpy(str, "tire-bouchon"); //This statement copies the string "tire-bouchon" into the character array str.
    // After this statement the value of str will be "tire-bouchon"
    strcpy(&str[4], "d-or-wi");//This statement copies the string  "d-or-wi" into the character array str
    // starting from the 5th position (index 4). After this statement the value
    // of str will be "tire-d-or-wi".
    strcat(str,
           "red?");      //This statement appends the string "red?" to the end of the character array str. After this statement,
    // the value of str will be "tire-d-or-wired?".
    printf("%s\n", str);


}

/**
 * 在执行下列语句后，字符串s1的值是什么？
 */
void exec13_09() {
    char s1[] = "hello World C language";
    char s2[] = "to c or not to c";
    strcpy(s1, "computer");
    strcpy(s2, "science");
    if (strcmp(s1, s2) < 0)
        strcat(s1, s2);
    else
        strcat(s2, s1);
    s1[strlen(s1) - 6] = '\0';
    printf("s1 now is %s\n", s1);
}


/**
 * 课后练习题10:下面的函数用于创建字符串的相同副本。请指出这个函数中的错误。
 * @param p
 * @return
 */
char *duplicate(const char *p) {
    /*char *q;: The variable q is declared as a pointer to char, but it doesn't point to any allocated memory.
     * It's just an uninitialized pointer.
     strcpy(q, p);: The function attempts to copy the string p to the memory location pointed to by q.
     However, since q is not pointing to any valid memory, strcpy will try to write to an unknown memory location,
     resulting in undefined behavior.*/
    //使用未初始化的指针变量作为字符串是非常严重的错误，会出现意想不到的错误。因为p没有被初始化，所以我们不知道它指向哪里

    /*错误的示例如下：
    char *q;
    strcpy(q, p);
    return q;
     *
     * */

    //下面是进行的优化可以实现这样方法
    // Allocate memory for the new string, including space for the null-terminator
    char *q = (char *) malloc(strlen(p) + 1);
    // Check if memory allocation was successful
    if (q == NULL) {
        // Handle memory allocation error
        return NULL;
    }
    strcpy(q, p);
    return q;
}

/**
 * 课后练习题11:
 * 分别使用数组取下标操作和指针算术运算来实现strcmp
 * @param s
 * @param t
 */
int strcmp_two(char *s, char *t) {
    //.方法一：通过数组取下标操作来显示字符串比较大小的方法
//    int i;
//    for (i = 0; s[i] == t[i]; i++)
//        if (s[i] == '\0')
//            return 0;
//    return s[i] - t[i];

    //方法通过指针算术运算
    while (*s == *t) {
        if (*s == '\0')
            return 0;
        s++;
        t++;
    }

    return *s - *t;
}

/**
 * 课后练习题目12:编写下面的函数：
 * file_name指向包含文件名的字符串。函数把文件名的扩展存储在extension指向的字符串中，例如，如果
 * 文件名是"memo.txt",函数将把"txt"存储到extension指向的字符串中。如果文件名没有扩展名，函数将在extension指向的字符串中存储
 * 一个空字符串(仅由一个空字符构成)。在函数中使用strlen函数和strcpy函数，使其尽可能简单。
 * @param file_name
 * @param extension
 */
void get_extension(const char *file_name, char *extension) {
    //这里使用方法非常简洁，但是对于这种demo.txt.html格式可能要注意
    //下面的写法值得好好理解
//    while (*file_name) {
//        if (*file_name++ == '.') {
//            strcpy(extension, file_name); //尤其是这里要理解strcpy底层如何实现的
//            return;
//        }
//    }
//    strcpy(extension, "");


    //实现方法二：通过访问数组下标的方式,可以很好避免第一种方法处理不了demo.txt.html这种格式
    int file_name_length = strlen(file_name);
    int dot_index = -1;
    //判断是否为空指针
    if (file_name == NULL || extension == NULL)
        return;
    // Find the index of the last dot in the file name
    for (int i = file_name_length - 1; i > 0; i--) {
        if (file_name[i] == '.') {
            dot_index = i;
            break;
        }
    }
    // If a dot is found, copy the extension after the dot
    if (dot_index != -1)
        strcpy(extension, &file_name[dot_index + 1]);
    else
        extension[0] = '\0';// If no dot is found, store an empty string

    //实现方法三，进一步优化方法的写法，借助现在已有的封装函数使用
    // Find the last occurrence of '.' in the file name
    const char *dot = strrchr(file_name, '.');
    /*
     * 在C语言中，strrchr函数用于查找字符串中特定字符最后一次出现的位置，注意strrchr的返回类型是char*，
     * 但它实际上返回的是一个指向原字符串str中位置的指针。 因此，我们使用const char*来声明last_occurrence变量，
     * 以表明它指向一个不应该被修改的常量字符串。请记住处理 strrchr 函数返回 NULL 的情况，
     * 因为它可能表明在字符串中找不到该字符。*/
    // If there's no dot or if the dot is the first character (e.g., ".htaccess"),
    // then there is no extension
    if (dot == NULL || dot == file_name)
        *extension = '\0'; // Store an empty string (null character)
    else
        strcpy(extension, dot + 1); // Copy the extension (excluding the dot) into the 'extension' string



}

/**
 * 课后练习题13:编写下面函数
 * domain指向包含因特网域名的字符串，例如"knking.com".函数应在该字符串的前面加上"http://www.",在后面加上"/index.html",并把结果存储到
 * index_url指向的字符串中.(在这个例子中，结果为"http://www.knking.com/index.html"。)可以假定index_url所指向的变量长度足以装下整个字符串
 * 。在函数中使用strcat函数和strcpy函数。使其尽可能简单。
 *
 * @param domain
 * @param index_url
 */
void build_index_url(const char *domain, char *index_url) {
    char prefix_domain[] = "http://www.";
    char suffix_domain[] = "/index.html";
    if (domain == NULL || index_url == NULL)
        return;
    strcpy(index_url, prefix_domain);
    // strcat(index_url,domain);
    //strcat(index_url,suffix_domain);
    strcat(strcat(index_url, domain), suffix_domain);
}

/**
 * 课后练习题14:
 * 下面的程序的输出是什么？
 */
void exec14_puts() {
    char s[] = "Hsjodi", *p;
    /*for 循环使用字符指针 p 迭代字符串 s 的字符。 循环条件 *p 检查 p 指向的字符是否不是空终止符 ('\0')。
     * 在 C 中，字符串以 null 终止，因此循环将一直运行，直到在字符串末尾遇到 null 终止*/
    for (p = s; *p; p++)
        --*p; /*在for循环中，有以下语句：--*p;。 这会减少 p 所指向的字符的值。 由于字符在 C 中表示为整数，
                * 因此此操作会递减字符串中每个字符的 ASCII 值。
                * 我们来分析一下for循环对字符串“Hsjodi”的影响：
                “H”(ASCII 72) 将递减为“G”(ASCII 71)。
                's' (ASCII 115) 将递减为 'r' (ASCII 114)。
                'j' (ASCII 106) 将递减为 'i' (ASCII 105)。
                'o' (ASCII 111) 将递减为 'n' (ASCII 110)。
                'd' (ASCII 100) 将递减为 'c' (ASCII 99)。
                'i' (ASCII 105) 将递减为 'h' (ASCII 104)。
                所以，这个程序的输出将是：“Grinch”
                请记住，原始字符串 s 在此过程中会被修改。 如果需要保留原始字符串，则应在应用任何转换之前制作一个副本。*/
    puts(s);  /*循环结束后，使用 put(s) 函数打印修改后的字符串 s。 put() 函数用于将字符串打印到控制台，打印后会自动添加换行符。*/

}

/**
 * 课后编程练习15：
 * 函数f如下所示：
 * a.f("abcd","babc")的值是多少？
 * b.f("abcd","bcd")的值是多少？
 * c.当传递两个字符串s和t时，函数f的返回值一般是什么？
 * @param s
 * @param t
 * @return
 */
int f(char *s, char *t) {
    char *p1, *p2;
    for (p1 = s; *p1; p1++) {
        for (p2 = t; *p2; p2++)
            if (*p1 == *p2) break;
        if (*p2 == '\0') break;
    }
    return p1 - s;
}

/**
 * 课后练习题16:
 * count_space函数的优化
 * @param s
 * @return
 */
int count_space(const char *s) {
    //课本案例的写法
    int count = 0;
    for (int i = 0; s[i] != '\0'; i++)
        if (s[i] == ' ')
            count++;
    return count;

    //指针用法二
    for (; *s != '\0'; s++)
        if (*s == ' ')
            count++;
    return count;

    //指针用法三，更加精简,用while语句代替
    while (*s++)
        if (*s == ' ')
            count++;
    return count;

}

