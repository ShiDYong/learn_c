/**
Created by mason on 2023/6/4
 第八章：数组对应的课后编程题
*/
#include<stdbool.h>
#include<stdio.h>
#include<ctype.h>
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

#define SIZE (int)(sizeof(a)/sizeof(a[0]))
#define NUM_RATES ((int) (sizeof(value) / sizeof(value[0])))
#define DEPARTURE_SIZE (int) (sizeof(departure_time) / sizeof(departure_time[0]))
#define INITIAL_BALANCE 100.0
#define MAX_SIZE 100
#define NUM_DEPARTURE 8
#define NUM_ARRIVAL 8
#define MAX_VALUE 80


#define NUM_ROW 10
#define NUM_COL 10

/**
 * 编程题01：修改8.1节的程序repeated.c，使其可以显示出哪些数字有重复(如果有的话)；
 * Enter a number: 939577
 * Repeated digit(s)： 7 9
 * 这个题目的处理方式非常巧妙值得好好学习，举一反三
 */
void exec8_01() {
    bool digit_seen[10] = {false}; //数组下标索引为0～9，对应于10个可能的数字。最初每个数组元素值都为假
    int digit;
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);
    //实现方法一：是根据案例练习来的
    /* printf("Repeated digit(s): ");
     while (n > 0) {
         digit = n % 10; //将n从右至左的数据逐个提取出来
         if (digit_seen[digit])   //如果digit_seen[digit]为真，那么表示digit至少在n中出现了两次。
             printf("%d ", digit);
         digit_seen[digit] = true;
         //从右至左继续获取剩下下一位数的值
         n /= 10;
     }*/
    //实现方法二：另外增加一个数组将有重复值的数组添加进去，循环遍历这个数组值为true的数据
    int i;
    bool repeated[10] = {false};
    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit])
            repeated[digit] = true;
        digit_seen[digit] = true;
        n /= 10;
    }
    printf("Repeated digit(s): ");
    for (i = 0; i < 10; i++) {
        if (repeated[i])
            printf("%d ", i);
    }
    printf("\n");

}

/**
 * 课后编程练习02:修改8.1节中的程序repeated.c,使其打印出一份列表，显示出每个数字在数中出现的次数：
 * Enter a number: 41271092
 * Digit:       0 1 2 3 4 5 6 7 8 9
 * Occurrences: 1 2 2 0 1 0 0 1 0 1
 */
void exec8_02() {
    int digit, i, occurrences[10] = {0};
    long n;
    printf("Enter a number: ");
    scanf("%ld", &n);
    while (n > 0) {
        digit = n % 10;
        occurrences[digit]++; //这里取得非常巧妙，相当于每次会自增1，如果是相同的数据就会自增1
        n /= 10;
    }
    printf("Digit:\t\t 0  1  2  3  4  5  6  7  8  9\n"); //注意输出格式要符合需求
    printf("Occurrences:\t");
    for (i = 0; i < 10; i++) {
        printf("%2d ", occurrences[i]);
    }
    printf("\n");

}

/**
 * 课后编程练习03:修改8.1的程序repeated.c，使得用户可以输入多个数进行重复数字的判断。当用户输入的数小于或等于0时，程序
 * 终止。就是可以让用户重复输入，然后有退出,这四道题非常值得推敲和理解
 */
void exec8_03() {
    int digit, i, occurrences[10] = {0};
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);

    if (n <= 0) {
        printf("Digit:\t\t 0  1  2  3  4  5  6  7  8  9\n");
        printf("Occurrences:\t 0  0  0  0  0  0  0  0  0  0\n");
    }

    while (n > 0) {
        while (n > 0) {
            digit = n % 10;
            occurrences[digit]++;
            n /= 10;
        }

        printf("Digit:\t\t 0  1  2  3  4  5  6  7  8  9\n");
        printf("Occurrences:\t");

        for (i = 0; i < 10; i++) {
            printf("%2d ", occurrences[i]);
            occurrences[i] = 0;  //自动将数据进行清空
        }
        printf("\nEnter a number: ");
        scanf("%ld", &n);
    }
}

/**
 * 修改8.1节的程序reverse.c，利用表达式(int)(sizeof(a)/sizeof(a[0]))或者具有相同值的宏来计算数组的长度
 */
void exec8_04() {
    int a[10], i;
    printf("Enter %d numbers: ", SIZE);
    for (i = 0; i < SIZE; i++)
        scanf("%d", &a[i]);
    for (i = SIZE - 1; i >= 0; i--)
        printf(" %d", a[i]);
    printf("\n");


}

/**
 * 课后编程练习题目05:修改8.1节的程序interest.c，使得修改的程序可以每月整合一次利息，而不是每年整合一次利息。不要改变程序的输出格式，余额
 * 仍然按照每年一次的时间间隔显示。
 * */
void exec8_05() {
    int i, low_rate, num_years, month, year;
    double value[5];

    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);

    printf("\n Years");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
    }
    printf("\n");

    for (year = 1; year <= num_years; year++) {
        printf("%3d    ", year);
        for (i = 0; i < NUM_RATES; i++) {
            for (month = 1; month <= 12; month++)
                value[i] *= (double) ((low_rate + i) / 12.0 / 100.0 + 1.0);
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

}

/**
 * 课后编程练习06:有一个名叫BIFF的人，是典型的网络新手，他有一种独特的编写消息的方式。下面是一条常见的BIFF公告：
 * H3Y DUD3,C 15 RILLY COOL!!!!!!!!!!
 * 编写一个"BIFF过滤器"，它可以读取用户输入的消息并把此消息翻译成BIFF的表达风格：
 * Enter message: Hey dude, C is rilly cool
 * In B1FF-speak: H3Y DUD3,C 15 RILLY COOL!!!!!!!!!!
 * 程序需要把消息转换成大写，用数字替代特定的字母(A->4,B->8,E->3,I->1,O->0,S->5)，然后
 * 添加10个左右的感叹号。提示：原始消息存储在一个字符数组中，然后从数组头开始逐个翻译并显示字符。
 */
void exec8_06() {
    int i = 0;
    char c, message[MAX_SIZE];
    printf("Enter message: ");
    while ((c = getchar()) != '\n' && i < MAX_SIZE)  //这里没有想到要用字符的getchar函数和putchar函数
        message[i++] = c;    //这道题值得细细思考和总结
    printf("In B1FF-speak: ");
    for (i = 0; i < MAX_SIZE; i++) {
        switch (c = toupper(message[i])) {  //这里用toupper函数将小写改成大写
            case 'A':
                putchar('4');
                break;
            case 'B':
                putchar('8');
                break;
            case 'E':
                putchar('3');
                break;
            case 'I':
                putchar('1');
                break;
            case 'O':
                putchar('0');
                break;
            case 'S':
                putchar('5');
                break;
            default:
                putchar(c);
                break;
        }
    }
    printf("!!!!!!!!!!\n");


};

/**
 * 编写一个程序读取一个5*5的整数数组，然后显示出每行与每列的和
 * Enter a row 1: 8 3  9  0 10
 * Enter a row 2: 3 5  17 1  1
 * Enter a row 3: 2 8  6  23 1
 * Enter a row 4: 15 7 3  2  9
 * Enter a row 5: 6 14 2  6  9
 *
 * Row totals: 30 27 40 36 28
 * Column totals: 34 37 37 32 21
 *
 */
void exec8_07() {
    int i, j, row_sum, column_sum, rom_column[5][5];
    for (i = 0; i < 5; i++) {
        printf("Enter a row %d: ", i + 1);
        for (j = 0; j < 5; j++) {
            scanf("%d", &rom_column[i][j]);  //当时思路就想直接在这里对行的和进行累加，但是发现很大打符合需求的格式
        }
    }
    //每行和每列的值分别求和
    printf("Row totals: ");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            row_sum += rom_column[i][j];
        }
        printf(" %d", row_sum);
    }
    printf("\nColumn totals: ");
    for (i = 0; i < 5; i++) {
        for (j = 0; j < 5; j++) {
            column_sum += rom_column[j][i]; //求出每列的和这里也是比较一下子难想出来
        }
        printf(" %d", column_sum);
    }

}

/**
 * 课后编程练习08:修改编程7，使其提示用户输入每个学生5门测验成绩，一共5个学生。然后计算每个学生的的总分和平均分
 * ，以及每门测验的平均分、高分和低分
 */
void exec8_08() {
    int i, j, n[5][5], temp[5][5];
    float total_score, high_score, low_score;
    //1.先获取二维数组n元素值，即5个学生5门课程的成绩填写到数组中
    for (i = 0; i < 5; i++) {
        printf("Enter quiz grade for student %d: ", i + 1);
        for (j = 0; j < 5; j++)
            scanf("%d", &n[i][j]);


    }
    printf("\n");
    //2.计算每个学生的总分和平均分
    for (i = 0; i < 5; i++) {
        printf("\n Total  and average score for student %d: ", i + 1);
        total_score = 0.0f;
        for (j = 0; j < 5; j++) {
            total_score += n[i][j];
        }
        printf("%.2f %.2f", total_score, (float) total_score / 5);


    }
    printf("\n");
    //3.计算每门课的平均分,最高分和最低分
    for (i = 0; i < 5; i++) {
        printf("\nAverage,high and low scores for quiz %d: ", i + 1);
        total_score = 0.0f;
        high_score = low_score = n[0][j];
        for (j = 0; j < 5; j++) {
            total_score += n[j][i];
            if (n[j][i] > high_score)
                high_score = n[j][i];
            if (n[j][i] < high_score)
                low_score = n[j][i];
        }
        printf("%.2f %.2fd %.2f", (float) total_score / 5, high_score, low_score);

    }
    printf("\n");

}

/**
 * 课后编程练习09:编写程序，生成一种贯穿10*10字符数组(初始时全为字符'.')的“随机步法”。程序必须随机地从一个元素走到另一个元素，
 * 每次向上、向下、向左或向右移动一个元素位子。已经访问过的元素按照访问顺序用字母A~Z进行标记。下面是一个输出示例：
 * 提示：利用strand函数和rand函数产生随机素，然后查看此数除以4的余数。余数一共有4种可能的值(0、1、2和3),指示下一次移动的4种可能
 * 方向。在执行移动操作之前，需要检查连个条件：一是不是能走到数组外面，二是不是走到已有字母标记的位置。只要有一个条件不满足，就得尝试
 * 一个方向移动。如果4个方向都堵住了，程序必须终止了。下面是提前结束的一个示例：
 *
 */
void exec8_09() {
    //需要多调试几次看下
    char letter = 'A',
            grid[10][10] = {0};
    int i = 0, j = 0, up = 0,   /* directions are essentially bools, written as ints to */
    down = 0,                   /* conform with C89 standard.                           */
    left = 0, right = 0, move = 0;

    srand((unsigned) time(NULL));

    grid[i][j] = letter++;

    while (letter <= 'Z') {
        up = down = left = right = move = 0;

        if (j + 1 < 10 && grid[i][j + 1] == 0)
            up = 1;
        if (j - 1 >= 0 && grid[i][j - 1] == 0)
            down = 1;
        if (i + 1 < 10 && grid[i + 1][j] == 0)
            right = 1;
        if (i - 1 >= 0 && grid[i - 1][j] == 0)
            left = 1;

        if (up + down + left + right == 0)
            break;

        move = rand() % 4;


        /* Intentional fallthrough if direction fails */
        switch (move) {
            case 0:
                if (up) {
                    grid[i][++j] = letter++;
                    break;
                }
            case 1:
                if (down) {
                    grid[i][--j] = letter++;
                    break;
                }
            case 2:
                if (right) {
                    grid[++i][j] = letter++;
                    break;
                }
            case 3:
                if (left) {
                    grid[--i][j] = letter++;
                    break;
                }
            default:
                break;
        }
    }

    for (i = 0; i < 10; i++) {
        for (j = 0; j < 10; j++) {
            if (grid[i][j] == 0)
                grid[i][j] = '.';
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }


}

/**
 * 课后编程第10题：修改第五章的编程题8，用一个数组存储航班起飞的时间，另一个数组存储航班抵达时间。(时间用整数表示，表示从午夜开始的分钟数。)
 * 程序用一个循环搜索起飞时间数组，以找到与用户输入的时间最接近的起飞时间。
 */
void exec8_10() {
    int departure_time[NUM_DEPARTURE] = {480, 583, 679, 767, 840, 945, 1140, 1305};
    int arrival_time[NUM_ARRIVAL] = {616, 712, 811, 900, 968, 1075, 1280, 1438};
    int hour, minute, i, user_time, d_hour,
            d_minute,
            a_hour,
            a_minute;
    printf("Enter a 24-hour time: ");
    scanf("%d %d ", &hour, &minute);
    user_time = 60 * hour + minute;

    printf("\n Closet departure time is ");
    for (i = 0; i + 1 < DEPARTURE_SIZE; i++) {
        int compare_time = (departure_time[i] + (departure_time[i + 1] - departure_time[i]) / 2);
        if (user_time <= compare_time) {
            /* printf("Closest departure time is %0.2d:%0.2d, arriving at %0.2d:%0.2d", departure_time[i] / 60, departure_time[i] % 60,
                    arrival_time[i] / 60, arrival_time[i] % 60);*/
            //输出这里重新处理下,处理方式值得学习的
            d_hour = departure_time[i] / 60 > 12 ? departure_time[i] / 60 - 12 : departure_time[i] / 60;
            d_minute = departure_time[i] % 60;
            a_hour = arrival_time[i] / 60 > 12 ? arrival_time[i] / 60 - 12 : arrival_time[i] / 60;
            a_minute = arrival_time[i] % 60;
            printf("%d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
                   d_hour, d_minute, departure_time[i] / 60 > 11 ? 'p' : 'a',
                   a_hour, a_minute, arrival_time[i] / 60 > 11 ? 'p' : 'a');

        }


    }
    //漏掉了最后一种情况，那就是arrival_time[7]无法与[7+1]进行比较，需要单独拿出来用
    d_hour = arrival_time[7] / 60 > 12 ? departure_time[7] / 60 - 12 : departure_time[7] / 60;
    d_minute = departure_time[7] % 60;
    a_hour = arrival_time[7] / 60 > 12 ? arrival_time[7] / 60 - 12 : arrival_time[7] / 60;
    a_minute = arrival_time[7] % 60;

    printf("%d:%.2d %c.m., arriving at %d:%.2d %c.m.\n",
           d_hour, d_minute, arrival_time[7] / 60 > 11 ? 'p' : 'a',
           a_hour, a_minute, arrival_time[7] / 60 > 11 ? 'p' : 'a');


}

/**
 * 课后编程练习11:修改第七章的编程题4，给输出加上标签：
 * Enter phone number: 1-800-COL-LECT
 * In number form: 1-800-265-5328
 * 在显示电话号码之前，程序需要将其(以原始格式或数值格式)存储在一个字符数组中。可以假定电话号码的长度不超过15个字符。
 * 如果电话么有在身边，参考这里给出的字母在键盘上的对应关系：2=ABC,2=DEF,3=GHI,4=GHI,5=JKL,6=MNO,7=PQRS,8=TUV,9=WXYZ
 * 原始电话号码中的非字母字符(例如数字和标点符号)保持不变.
 *
 */
void exec8_11() {
    char phone[15] = {0};
    int i;
    printf("Enter phone number: ");
    //通过将输入的字符输入到数组当中，这是常用写法，要熟练使用
    while ((phone[i++] = getchar()) != '\n');
    printf("In number form: ");
    //通过循环将数组中的元素值进行转换
    for (i = 0; i < 15; i++) {
        //使用switch语句进行分类判断
        switch (phone[i]) {
            case 'A':
            case 'B':
            case 'C':
                putchar('2');
                break;
            case 'D':
            case 'E':
            case 'F':
                putchar('3');
                break;
            case 'G':
            case 'H':
            case 'I':
                putchar('4');
                break;
            case 'J':
            case 'K':
            case 'L':
                putchar('5');
                break;
            case 'M':
            case 'N':
            case 'O':
                putchar('6');
                break;
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
                putchar('7');
                break;
            case 'T':
            case 'U':
            case 'V':
                putchar('8');
                break;
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
                putchar('9');
                break;
            default:
                putchar(phone[i]);
                break;

        }

    }
    printf("\n");

}

/**
 * 课后编程练习12:修改第七章的编程题5，用数组存储字母的面值。数组有26个元素，对应字母表中的26个字母。例如，数组元素0存储1(因为字母A的面值为1)，
 * 数组元素1存储3(因为字母B的面值为3)，等等。每读取输入单词的一个字母，程序都会利用该数组确定字符的拼字值。使用数组初始化器来建立数组。
 */
void exec8_12() {
    char c;
    int sum, scrabble_array[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8,
                                   5, 1, 3, 1, 1, 3, 10, 1, 1, 1,
                                   1, 4, 4, 8, 4, 10};
    printf("Enter a word: pitfall: ");
    while ((c = getchar()) != '\n') { //这里处理的非常巧妙，要熟练a-z和A-Z字符对应的ASCII值对照,需要仔细观察toupper(c) - 'A'
        //差对应的刚好时数组scrabble_array的下标值
        //这里可以查看链接：https://tool.oschina.net/commons?type=4
        //编写程序中允许出现大小写混合，使用toupper库函数全部转为大写字母
        sum += scrabble_array[toupper(c) - 'A'];
    }
    printf("\n Scrabble value: %d", sum);
}

/**
 * 课后编程练习13:修改第7章的编程题目11，给输出加上标签：
 * Enter a first and last name: Lloyd Fosdick
 * You enered the name: Fosdick,L.
 * 在显示姓(不是名)之前，程序需要将其存储在一个字符数组中。假定姓的长度不超过20个字符.用户的输入中可能包含空格(名之前、名和姓之间、
 * 姓氏之后)
 */
void exec8_13() {
    int i;
    char c, initial, last[20] = {0};

    printf("Enter a first and last name: ");
    //找到第一个非空格字符串的位置,将其赋值给名第一个字母
    while ((c = getchar()) == ' ');
    initial = c;
    while ((getchar() != ' '));
    for (i = 0; (c = getchar()) != '\n'; i++)
        last[i] = c;

    printf("You entered the name: ");
    for (i = 0; last[i] != '\0'; i++)  //C语言中\0 代表什么呢？ '\0' 是字符串的结束符，任何字符串之后都会自动加上'\0'。
        putchar(last[i]);              // 如果字符串末尾少了'\0'字符，则其在输出时可能会出现乱码问题

    printf(", %c.\n", initial);

}

/**
 * 课后编程练习14:编写程序颠倒句子中单词的顺序：
 * Enter a sentence: you can cage a swallow can't you?
 * Reversal of sentence: you can't swallow a cage can you?
 * 提示：用循环逐个读取字符，然后将它们存储在一个一维数组中。当遇到句号、问好或者感叹号(称为“终止字符”)时，终止循环并把终止字符存储
 * 在一个char类型变量中。然后再用一个循环反向搜索数组，找到最后一个单词的起始位置。显示最后一个单词，然后反向搜索倒数第二个单词。
 * 重复这一过程，直至到达数组的起始位置。最后显示终止符号。
 */
void exec8_14() {
    /*
     * 第一次做题的思路：
     * int i = 0; //难题如何拿到数组的长度是不确定的，动态的
     char ch, sentence_arr[39] = {0};
     printf("Enter a sentence: ");
     while ((sentence_arr[i++] = getchar()) != '\n'){
         if (sentence_arr[i] == '.' || sentence_arr[i] == '?' || sentence_arr[i] == ' ')
             ch = sentence_arr[i];
     }

         printf("\nReversal of sentence: ");
     for (i = 29; i > 0; i--) {
         if (sentence_arr[i] == '.' || sentence_arr[i] == '?' || sentence_arr[i] == ' ') {
             printf(" ",sentence_arr[i]);
             continue;
         }
     }
 */
    int i = 0, j;
    char c, terminating_char, words[MAX_SIZE] = {0}; //处理数组长度问题设置最大长度
    printf("Enter a sentence: ");
    for (i = 0; (c = getchar()) != '\n' && i < MAX_SIZE; i++) {
        if (c == '.' || c == '!' || c == '?') {
            terminating_char = c;   //去掉空格、!、？判断是否为空单词，如果是将单词存储起来到数组里面，这个方法常用要熟悉
            break;
        }
        words[i] = c;
    }

    printf("Reversal of sentence: ");
    while (i >= 0) {
        while (words[--i] != ' ' && i != 0);
        j = i == 0 ? 0 : i + 1;
        while (words[j] != ' ' && words[j] != '\0')
            putchar(words[j++]);
        if (i >= 0)
            putchar(' ');
    }

    printf("\b%c\n", terminating_char);

}

/**
 * 课后编程练习题15:目前已经知道的最古老加密技术是凯撒加密。该方法把一条消息中的每个字母用字母表中固定距离之后的那个字母来替代。(如果越过了
 * 字母Z，则会绕回到字母表的起始位置。例如，如果每个字母都用字母表中两个位置替代，那么Y就会替代为A,Z就会被替换为B.)
 * 编写程序用凯撒加密方法进行加密。用户输入待加密的消息和移位计数(字母一定的位置数目)：
 * Enter message to be encrypted: Go ahead, make my day.
 * Enter shift amount:（1-25）：3
 * Encrypted message: Jr dkhdg, pdnh pb gdb.
 * 注意当用户输入26与移位计数的差值时，程序可以对消息进行解密：
 * Enter message to be encrypted: : Jr dkhdg, pdnh pb gdb.
 * Enter shift amount:(1-25): 23
 * Encrypted message: Go ahead, make my day.
 */
void exec8_15() {
    char c, sentence[MAX_VALUE] = {0};
    int i, n, length;
    printf("Enter message to be encrypted: ");
    for (i = 0, length = 0; (c = getchar()) != '\n' && i < MAX_VALUE; i++) {
        length++;
        sentence[i] = c;
    }
    printf("\nEnter shift amount:(1-25): ");
    scanf("%d", &n);
    for (i = 0; i < length; i++) {
        if (sentence[i] >= 'A' && sentence[i] <= 'Z') //下面处理方法非常经典实现在26字母范围内循环
            sentence[i] = ((sentence[i] - 'A') + n) % 26 + 'A'; //结合字符对应的ASCII表对照起来看
        else if (sentence[i] >= 'a' && sentence[i] <= 'z')
            sentence[i] = ((sentence[i] - 'a') + n) % 26 + 'a'; //大小写保持不变的
        putchar((sentence[i]));
    }
    printf("\n");

}

/**
 * 课后编程练习16:编程测试两个单词是否为变位词(相同字母重新排序)：
 * Enter first word: smartest
 * Enter second word: mattress
 * The words are anagrams.
 * Enter first word: dumbest
 * Enter second word: stumble
 * The word are not anagrams.
 * 用一个循环逐个字符地读取第一个单词，用一个26元的整数数组记录每个字母的出现次数。（例如：读取单词smartest之后，
 * 数组包含的值为1 0 0 0 1 0 0 0 0 0 0 0 1 0 0 0 0 1 2 2 0 0 0 0 0 0,表明smartest包含一个a、一个e、一个m、一个r、两个s
 * 和两个t。）用另一个循环读取第二个单词，这次每读取一个字母就把相应数组元素的值减去1.两个循环都应该忽略不是字母的哪些字符，并且不区分大小写。
 * 第二个单词读取完毕后，再用一个循环来检查数组元素是否全为0.如果是全0.那么这两个单词就是变位词。提示：可以使用<ctype.h>的函数，如果isalpha和
 * tolower.
 */
void exec8_16() {
    int i, same = 1, letters[26] = {0};
    char c;

    printf("Enter first word: ");
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) //C语言 isalpha() 函数用来检测一个字符是否是字母，包括大写字母和小写字母。参数 c 表示要检测字符或者 ASCII 码。
            //返回值：返回非 0（真）表示 c 是字母，返回 0（假）表示 c 不是字母
            letters[toupper(c) -'A']++;//C库函数int toupper(int c)将小写字母转换为大写。该函数等效返回大写字母C，如果存在这样的值，否则c保持不变。返回值可以隐式转换为char的int值。

    }
    printf("Enter second word: ");
    while ((c = getchar()) != '\n') {
        if (isalpha(c))
            letters[toupper(c) - 'A']--;
    }

    for (i = 0; i < 26; i++) {
        if (letters[i] != 0) {
            same = 0;
            break;
        }
    }
    if (same) {
        printf("The words are anagrams.\n");
    }
    printf("The words are not anagrams.\n");
}

/**
 * 课后编程练习17:
 * 编写程序打印n*n的幻方(1,2,...,n^2的方阵排列，且每行、每列和每条对角线上的和相等)。由用户指定n的值：
 *   This program creates a magic square of a specified size.
    The size must be an odd number between 1 and 99.
    Enter size of magic square: 5
   17   24    1    8   15
   23    5    7   14   16
    4    6   13   20   22
   10   12   19   21    3
   11   18   25    2    9
 */
void exec8_17() {

}


//int main() {
// exec8_01();
//exec8_02();
// exec8_03();
// exec8_04();
//exec8_05();
// exec8_06();
//exec8_07();
//exec8_08();
//exec8_09();
//exec8_10();
//exec8_11();
//exec8_12();
//exec8_13();
//exec8_14();
//exec8_15();
//    exec8_16();
//
//
//    return 0;
//}
