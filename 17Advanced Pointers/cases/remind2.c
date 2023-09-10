/********************************************************************************
* @author: mason shi
* @date: 2023/8/20 15:33
* @version: 1.0
* @description: 优化13章案例练习
 * 原始成员remind.c把提醒字符串存储在二维字符数组中，且数组的每行包含一个字符串。程序读入有一天和相关的提醒后，会搜索
 * 数组并使用strcmp函数进行比较，从而确定这一天所处的位置。然后，程序使用函数strcpy把该位置下面的全部字符串向下移动一个
 * 位置。最后程序把这一天复制到数组中，并且调用strcat函数来添加这一天的提醒。
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_REMIND 50 /*maximum number of reminders*/
#define MSG_LEN 60 /*max length of reinder message*/

int read_line(char str[], int n);

int main(void) {
    char *reminders[MAX_REMIND];
    char day_str[3], msg_str[MSG_LEN + 1];
    int day, i, j, num_remind = 0;

    for (;;) {
        if (num_remind == MAX_REMIND) {
            printf("-- No space left --\n");
            break;
        }
        printf("Enter day and reminder: ");
        scanf("%2d", &day);
        if (day == 0)
            break;
        sprintf(day_str, "%2d", day);
        read_line(msg_str, MSG_LEN);

        for (i = 0; i < num_remind; i++)
            if (strcmp(day_str, reminders[i]) < 0)
                break;
        for (j = num_remind; j > i; j--)
            reminders[j] = reminders[j - 1];

        reminders[i] = malloc(2 + strlen(msg_str) + 1);
        if (reminders[i] == NULL) {
            printf("-- No space left --\n");
            break;

        }
        strcpy(reminders[i], day_str);
        strcat(reminders[i], msg_str);

        num_remind++;

    }
    printf("\n Day reminder\b");
    for (i = 0; i < num_remind; i++)
        printf(" %s\n", reminders[i]);
    return 0;


}