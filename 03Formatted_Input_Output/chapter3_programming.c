/**
Created by mason on 2023/4/31.
 第三章：C语言的格式化输入/输出课后编程题
*/

#include <stdio.h>
#include <stdbool.h>
#include<ctype.h>
#include<string.h>

/**
 * 练习1:编写一个程序，以月/日/年(mm/dd/yy)的格式接受用户输入的日志信息，并以年月日(yyyymmdd)的格式展示出来
 */
void exec3_1() {
    int year, month, day;
    printf("Please enter a date(mm/dd/yyyy): ");
    //获取用户的输入，如何处理格式是mm/dd/yy
    // scanf("%d%d%d", &month, &day, &year);获取不到/后面的数据了
    // scanf("%d/%d/%d", &month, &day, &year);//和下面的效果是一样的，因为scanf函数自动去除空白字符
    scanf("%d /%d /%d", &month, &day, &year); //添加空格是为来提高用户输入的容错性
    //这里如何让输出格式是：20221231呢，最开始方式是有问题的
    printf("Your enter the date is:%4d%02d%02d\n", year, month, day);
    //第二种写法更准确：以十进制形式显示变量i，并至少有4位数字符合年的写法，同理月、日写法也是一样的
    printf("Your enter the date is: %0.4d%0.2d%0.2d\n", year, month, day);

}
/*
 * 检查这年是平年还是闰年
 */
bool isLeapYear(int year) {
    return ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0));
}

/*
 * 检查输入的日期是否合法，计算是闰年还是平年
 */
bool isValidDate(int month, int day, int year) {
    //检查月份
    if (month < 1 || month > 12) return false;
    //每年中除了二月份天数不确定，其它时间都是确定的
    int daysInMonth[] = {31, 28 + isLeapYear(year), 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    //检查输入的天数
    if (day < 1 || day > daysInMonth[month - 1]) return false;
    return true;


}

//Function to convert to date to yyyymmdd formant
void convertToDate(int month, int day, int year) {
    printf("You enter the date %4d%02d%02d\n", year, month, day);
}

/**
 * 对上面的题目进一步优化，提高程序的可靠性和安全性
 */
bool exec3_1_optimization() {
    int year, month, day;
    char slash;
    printf("Enter a date (mm/dd/yyyy): ");
    //Read input date
    /*scanf("%d %d %d", &month, &day, &year) != 3：
      这一部分使用scanf函数尝试从标准输入中读取三个整数，即月份、日期和年份。如果scanf函数成功读取了三个整数，
      则表达式的结果为假（0），否则为真（非0）。因此，如果用户输入的是有效的日期格式，即正确地输入了三个整数（月、日、年），
      这部分条件将为假，代码不会执行下面的语句。
      || scanf("%c", &slash) != 0：如果上述scanf函数读取失败，即用户没有输入三个整数，则会尝试再次使用scanf函数来读取一个字符。
      这个字符应该是日期中的斜杠 /。如果读取成功，则表达式的结果为真，否则为假。如果用户输入的是非数字字符，
      或者缺少斜杠 /，这部分条件将为真，代码会执行下面的语句。
      || slash != '/'：这一部分检查在第二步中读取的字符是否为斜杠 /。如果不是斜杠 /，则表达式的结果为真，否则为假。如果输入的字符不是斜杠 /，则表示日期格式不正确，代码会执行下面的语句。
|| getchar() != '\n'：
       最后一部分检查输入流中是否还有其他字符。getchar()函数尝试从输入流中读取一个字符，并将其与换行符 \n 进行比较。
       如果输入流中还有其他字符（换行符之后），或者用户在输入完日期后没有按下 Enter 键，那么这部分条件将为真，代码会执行下面的语句。
*/
    //|| scanf("%c", &slash) != 0 || slash != '/' || getchar() != '\n'
    if (scanf("%d /%d /%d", &month, &day, &year) != 3) {
        printf("Invalid input format.\n");
        return false;
    }
    //Validate input date
    if (!isValidDate(month, day, year)) {
        printf("Invalid date.\n");
        return false;
    }
    //Convert and print the date
    convertToDate(month, day, year);
    return true;

}

/**
 * Project 3.02
  Write a program that formats product information entered by the user. A session
  with the program should look like this:
    Enter item number: 583
    Enter unit price: 13.5
    Enter purchase date (mm/dd/yyyy): 10/24/2010
    Item            Unit            Purchase
                    Price           Date
    583             $  13.50        10/24/2010
    The item number and date should be left justified; the unit price should be
    right justified. Allow dollar amounts up to $9999.99. *Hint* Use tabs to line up
    the columns.
 */
void exec3_2() {
    int item, year, month, day;
    float unit_price;
    printf("Enter number: ");
    scanf("%d", &item);
    printf("Enter unit price: ");
    scanf("%f", &unit_price);
    printf("Enter purchase date(mm/dd/yyyy): ");
    scanf("%d /%d /%d", &month, &day, &year);
    //如何输出来？思路应该是要打印成2行数据，第一行展示字段，第二行展示字段内容，第一次处理方式是错误的
    //printf("Item\tUnit\nPrice\tPurchase\nDate\t",item,unit_price,month,day,year);
    // Displaying formatted product information
    printf("Item\t\tUnit\t\tPurchase\n");
    printf("\t\tPrice\t\tDate\n");
    printf("%-d\t\t$%7.2f\t%-02d/-%02d/-%4d\n", item, unit_price, month, day, year);


}

/**
 *  Project 3.03
    Books are identified by an International Standard Book Number (ISBN). ISBNs
    assigned after January 1, 2007 contain 13 digits, arranged in five groups, such
    as 978-0-393-97950-3. (Older ISBNs use 10 digits.) The first group (the *GSI
    prefix*) is currently either 978 or 979. The *group identifier* specifies the
    language or country of origin (for example, 0 and 1 are used in English-speaking
    countries). The *publisher code* identifies the publisher (393 is the code for
    W. W. Norton). The *item number* is assigned by the publisher to identify a
    specific book (97950 is the code for this book). An ISBN ends with a *check
    digit* that's used to verify the accuracy of the preceding digits. Write a
    program that breas down an ISBN entered by the user:
        Enter ISBN: 978-0-393-97950-3
        GSI prefix: 978
        Group identifier: 0
        Publisher code: 393
        Item number: 97950
        Check digit: 3
    *Note*: The number of digits in each group may very: you can't assume that
    groups have the lengths shown in this example. Test your program with actual
    ISBN values (usually found on the back cover of a book and on the copyright
    page).
 */
void exec3_3() {
    int GSI_prefix, group_identifier, publisher_code, item_number, check_digit;
    printf("Enter ISBN: ");
    scanf("%d -%d -%d -%d -%d", &GSI_prefix, &group_identifier, &publisher_code, &item_number, &check_digit);
    //按照要求进行格式输出
    printf("GSI prefix:%d\nGroup identifier:%d\n", GSI_prefix, group_identifier);
    printf("Publisher code:%d\nItem number:%d\nCheck digit:%d\n", publisher_code, item_number, check_digit);

}

/**
 * 练习4:编写一个程序，提示用户以(xxx)xxx-xxxx的格式输入电话号码，并以xxx.xxx.xxxx的格式显示该号码
 *
 */
void exec3_4() {
    int first, second, last;
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &first, &second, &last);
    printf("Your enter is:%0.3d.%0.3d.%0.4d\n", first, second, last);
}

/**
 * Project 3.05
Write a program that asks the user to enter the numbers from 1 to 16 (in any
order) and then displays the numbers in a 4 by 4 arrangement, followed by the
sums of the rows, columns, and diagonals:
    Enter the numbers from 1 to 16 in any order:
    16 3 2 13 5 10 11 8 9 6 7 12 4 15 14 1
    16  3  2 13
     5 10 11  8
     9  6  7 12
     4 15 14  1
    Row sums: 34 34 34 34
    Column sums: 34 34 34 34
    Diagonal sums: 34 34
    If the row, column, and diagonal sums are all the same (as they are in this
    example), the numbers are said to form a *magic square*. The magic square shown
    here appears in a 1514 engraving by artist and mathematician Albrecht Dürer.
(Note that the middle numbers in the last row give the date of engraving.)
 */
void exec3_5() {
    int n1, n2, n3, n4, n5, n6, n7, n8, n9, n10, n11, n12, n13, n14, n15, n16;

    printf("Enter the numbers from 1 to 16 in any order:\n");
    scanf("%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d%d",
          &n1, &n2, &n3, &n4, &n5, &n6, &n7, &n8,
          &n9, &n10, &n11, &n12, &n13, &n14, &n15, &n16);

    printf("\n%3d%3d%3d%3d\n%3d%3d%3d%3d\n",
           n1, n2, n3, n4, n5, n6, n7, n8);

    printf("%3d%3d%3d%3d\n%3d%3d%3d%3d\n\n",
           n9, n10, n11, n12, n13, n14, n15, n16);

    printf("Row sums: %d %d %d %d\n", (n1 + n2 + n3 + n4), (n5 + n6 + n7 + n8),
           (n9 + n10 + n11 + n12), (n13 + n14 + n15 + n16));

    printf("Column sums: %d %d %d %d\n",
           (n1 + n5 + n9 + n13), (n2 + n6 + n10 + n14),
           (n3 + n7 + n11 + n15), (n4 + n8 + n12 + n16));

    printf("Diagonal sums: %d %d\n",
           (n1 + n6 + n11 + n16), (n4 + n7 + n10 + n13));

}

/**
 * 编程练习6:修改3.2节的addfrac.c程序，使使用可以同时输入两个分数，中间用加号隔开；
 */
void exec3_6() {
    int num1, demon1, num2, demon2, result_num, result_demon;
    printf("Enter two fractions separated by a plus sign: ");
    //这里加不加+都是可以的
    scanf("%d /%d+%d /%d", &num1, &demon1, &num2, &demon2);
    result_num = num1 * demon2 + num2 * demon1;
    result_demon = demon1 * demon2;
    printf("The sum is: %d/%d", result_num, result_demon);
}

int main() {
    //exec3_1();
    //exec3_2();
    // exec3_3();
    // exec3_4();
    //exec3_6();
    //exec3_1_optimization();
    char str[] = "Hello, world,how, are, you";
    char *token;
    /*str 是要分割的字符串，第一次调用时传入原始字符串，在后续调用中传入NULL。
     * delim 是分隔符的字符串，用来指定分隔符集合。
     * strtok函数返回被分割的子字符串，如果没有可分割的子字符串，返回NULL。*/
    token = strtok(str, ",");
    while (token != NULL) {
        printf("%s\n", token);
        token = strtok(NULL, ","); //进行下一次分割
    }

    return 0;
}
