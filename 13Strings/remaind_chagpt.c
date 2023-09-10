/********************************************************************************
* @author: mason shi
* @date: 2023/8/20 15:16
* @version: 1.0
* @description: 
********************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_REMINDERS 30
#define MAX_DAY_LEN 3
#define MAX_REMINDER_LEN 50

int compare_dates(const void *a, const void *b) {
    return strncmp((const char *)a, (const char *)b, MAX_DAY_LEN);
}

int main() {
    char reminders[MAX_REMINDERS][MAX_REMINDER_LEN + MAX_DAY_LEN + 1];
    int num_reminders = 0;

    while (num_reminders < MAX_REMINDERS) {
        char day[MAX_DAY_LEN + 1];
        char reminder[MAX_REMINDER_LEN + 1];

        printf("Enter day and reminder (or 'O' to finish): ");
        scanf("%2s", day);

        if (strcmp(day, "O") == 0 || strcmp(day, "o") == 0)
            break;
        fgets(reminder, sizeof(reminder), stdin);
        reminder[strcspn(reminder, "\n")] = '\0'; // Remove the newline character

        if (strlen(day) > 0 && strlen(reminder) > 0) {
            snprintf(reminders[num_reminders], sizeof(reminders[num_reminders]), "%2s %s", day, reminder);
            num_reminders++;
        }
    }

    qsort(reminders, num_reminders, sizeof(reminders[0]), compare_dates);

    printf("\nDay Reminder\n");
    for (int i = 0; i < num_reminders; i++) {
        char day[MAX_DAY_LEN + 1];
        char reminder[MAX_REMINDER_LEN + 1];
        sscanf(reminders[i], "%2s %[^\n]", day, reminder);
        printf("%3s %s\n", day, reminder);
    }

    return 0;
}
