/********************************************************************************
* @author: mason shi
* @date: 2023/7/23 11:51
* @version: 1.0
* @description: 第十二章课后编程题目
********************************************************************************/
#include<stdio.h>
#include<ctype.h>
#include<string.h>

#define ARRAY_SIZE 50

void program12_1();

void program12_2_is_palindrome();

void reverseWords(char *sentence);

void program12_5_pointer();

void program12_5_array();


int main(void) {
    // program12_1();
    // program12_2_is_palindrome();
    // program12_5_pointer();
   // program12_5_array();
    /*  const char *str = "Hello, World!";
      const char *reject = " ,!"; // Characters to reject: space, comma, and exclamation mark
      size_t length = strcspn(str, reject);
      printf("Length of initial segment without rejected characters: %zu\n", length);
      在此示例中，strcspn 函数用于查找字符串 str 中不包含拒绝字符串中的任何字符的初始段的长度。 拒绝字符串包含空格、逗号和感叹号。
      在这种情况下，该函数将返回 5，因为初始段“Hello”包含拒绝字符串中不存在的 5 个字符。
      return 0;
  */
    program12_5_pointer();
}


/**
 * 课后编程题1：编写程序读一条消息，然后逆序打印这条消息：
 * Enter a message: Don't get mad,get even.
 * Reversal is: .neve teg, dam teg t'noD
 * 提示：一次读取消息中的一个字符(用getchar函数)，并且把这些字符存储在数组中，当数组满了或者读到字符'\n'时停止读操作
 */
void program12_1() {
    char temp[ARRAY_SIZE], ch;
    char *p = temp;

    // int i = 0;
//    while ((ch = getchar()) != '\n' && i < ARRAY_SIZE) {
//        temp[i] = ch;
//        i++;
//    }
//    printf("\nReversal is: ");
//    for (; i >= 0; i--)
//        printf("%c", temp[i]);

    /*修改上述程序，用指针代替整数来跟踪数组中当前的位置*/
    printf("Enter a message: ");
    while ((ch = getchar()) != '\n' && p < temp + ARRAY_SIZE)
        *p++ = ch;
    p--; //因为经过上面p已经超过数组实际长度，所以自减少1
    printf("\nReversal is: ");
//    for (; p >= temp; p--)
//        printf("%c", *p);
    //替代写法更符合指针和数组的关系
    while (p >= temp)
        putchar(*p--);
    printf("\n");


}

/**
 * 课后编程题2:
 * 编写程序读一条消息，然后检查这条消息是否是回文(消息中的字面从左到右和从右到左是一样的)；
 * Enter a message: He lived as devil, eh?
 * Palindrome
 * Enter a message: Madam, I am Adam.
 * Not a palindrome
 *备注：忽略所有不是字母的字符。用整型变量来跟踪数组中的位置。
 */
void program12_2_is_palindrome() {
//    char arr_ch[ARRAY_SIZE], ch;
//    int i = 0, m;
//    printf("Enter a message: ");
//    while ((ch = getchar()) != '\n' && i < ARRAY_SIZE) {
//        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
//            arr_ch[i] = tolower(ch); /*统一转换成大写或者小写，不然后面的比较时会出问题,将s字符串内的大写字母转换成小写字母,
// * C语言tolower()函数：将大写字母转换为小写字母,toupper()则是相反*/
//            i++;
//        }
//    }
//    i--;
//    for (m = 0; i != m; m++, i--)
//        if (arr_ch[m] != arr_ch[i]) {
//            printf("Not a palindrome\n");
//            return;
//        }
//    printf("Palindrome\n");
    /*修改上述程序，使用指针代替整数来跟踪数组中的位置，下面的方法更加简洁。*/
    char message[ARRAY_SIZE];
    char c, *p = message, *q;

    printf("Enter a message: ");

    while ((c = toupper(getchar())) != '\n' && p < message + ARRAY_SIZE) {
        if (isalpha(c)) //直接引用这个方法更加简洁
            *p++ = c;
    }
    p--;

    for (q = message; q < p; q++, p--) {
        if (*p != *q) {
            printf("Not a palindrome\n");
            return;
        }
    }
    printf("Palindrome\n");


}

/**
 * 修改第八章的编程题14，用指针而不是整数来跟踪包含该句的数组的当前位置。
 *  Enter a sentence: you can cage a swallow can't you?
 * Reversal of sentence: you can't swallow a cage can you?
 * 提示：用循环逐个读取字符，然后将它们存储在一个一维数组中。当遇到句号、问好或者感叹号(称为“终止字符”)时，终止循环并把终止字符存储
 * 在一个char类型变量中。然后再用一个循环反向搜索数组，找到最后一个单词的起始位置。显示最后一个单词，然后反向搜索倒数第二个单词。
 * 重复这一过程，直至到达数组的起始位置。最后显示终止符号。
 */
void program12_5_pointer() {
//    char ch, sentence[ARRAY_SIZE], *p = sentence, *q,
//            terminating_char;
//    printf("Enter a sentence: ");
//    while ((ch = getchar()) != '\n' && p < sentence + ARRAY_SIZE) {
//        if (ch == '.' || ch == '?' || ch == '!') {
//            terminating_char = ch;//终止符号也要存储起来
//            break;
//        }
//        *p++ = ch;
//
//    }
//    *p = ch;//把终止符号添加到数组的末尾
//    //根据进行反向输出
//    printf("\n Reversal of sentence: ");
//    while (p >= sentence) {
//        while (*--p != ' ' && p != sentence)
//            ;
//        q = p == sentence ? sentence : p + 1;
//        while (*q != ' ' && *q != '\0')
//            putchar(*q++);
//        if (p >= sentence)
//            putchar(' ');
//    }
//
//    printf("\b%c\n", terminating_char);
    char c, *p, *q,
            terminating_char,
            words[ARRAY_SIZE] = {0};

    printf("Enter a sentence: ");
    for (p = words; (c = getchar()) != '\n' && p < words + ARRAY_SIZE; p++) {
        if (c == '.' || c == '!' || c == '?') {
            terminating_char = c;
            break;
        }
      //  printf("赋值前的值是%s\n", *p);
        *p = c;
    }

    printf("Reversal of sentence: ");
    /*以下代码暂时没有理解*/
    while (p >= words) {
        while (*--p != ' ' && p != words);
        q = p == words ? words : p + 1;
        while (*q != ' ' && *q != '\0')
            putchar(*q++);
        if (p >= words)
            putchar(' ');
    }

    printf("\b%c\n", terminating_char);
    printf("是否数组的值发生了变化: %s\n", words);


}

/**
 * 通过一般方式处理方式
 */
void program12_5_array() {
    char sentence[1000];
    printf("Enter a sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Remove the trailing newline character from the input
//    if (sentence[strlen(sentence) - 1] == '\n') {
//        sentence[strlen(sentence) - 1] = '\0';
//    }
    //使用字符串的拼接函数替换上面的写法
    sentence[strcspn(sentence, "\n")] = '\0';

    reverseWords(sentence);

    printf("Reversal of sentence: %s\n", sentence);
}

/**
 * 对比指针实现的方法更加简洁，这种实现方法相对繁琐很多,但是指针的方法只是打印出来,并没有修改存储数组的值
 * @param sentence
 */
void reverseWords(char *sentence) {
    int len = strlen(sentence);
    int start = 0;

    // Reverse the entire sentence first
    for (int i = 0; i < len / 2; i++) {
        char temp = sentence[i];
        sentence[i] = sentence[len - i - 1];
        sentence[len - i - 1] = temp;
    }

    // Reverse individual words in the sentence
    for (int i = 0; i <= len; i++) {
        if (sentence[i] == ' ' || sentence[i] == '\0') {
            int end = i - 1;
            // Reverse the word
            while (start < end) {
                char temp = sentence[start];
                sentence[start] = sentence[end];
                sentence[end] = temp;
                start++;
                end--;
            }

            // Move to the next word
            start = i + 1;
        }
    }
    int i = 0;
    //再加一个方法，把？、！移到末尾
    for (; i < len; i++) {
        if (sentence[i] == '!' || sentence[i] == '.' || sentence[i] == '?') {
            printf("打印下这个末尾的值%s\n", sentence[len]);
            printf("打印下这个末尾的值%c\n", sentence[len - 1]);
            sentence[len] = sentence[i]; //这个只是复制到末尾
            printf("打印下这个末尾的值%c\n", sentence[len]);
            break;
        }
    }
    //再把数据整体向前移动一位，才不会多出现一个空格
    while (i < len) {
        sentence[i] = sentence[i + 1];
        i++;

    }
    //整体向前移动一位后，因为是复制移动，所以最后一个会多一个？，需要把这个设置为空字符
    printf("打印下这个末尾的值%c\n", sentence[len]);
    printf("打印下这个末尾的值%c\n", sentence[len - 1]);
    //you can't swallow a cage can you??
    sentence[len] = '\0';


}
