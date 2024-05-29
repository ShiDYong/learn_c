/********************************************************************************
* @author: mason shi
* @date: 2024/5/29 22:24
* @version: 1.0
* @description: 
********************************************************************************/
#include<stdio.h>
#include <stdbool.h>
// Define constants for date format validation
#define MIN_YEAR 1
#define MAX_YEAR 9999
#define MIN_MONTH 1
#define MAX_MONTH 12
#define MIN_DAY 1
#define MAX_DAY 31
//Struct Organization: Using a struct improves code organization and readability,
// especially if more date-related functionality is added later.
//Constants such as MIN_YEAR, MAX_YEAR, MIN_MONTH, MAX_MONTH, and MIN_DAY are defined to avoid magic numbers in the code.
//This makes it easier to modify these values if needed and improves code clarity.
typedef struct {
    int day;
    int month;
    int year;
} Date;

/**
 *  Project 5.09
    Write a program that prompts the user to enter two dates and then indicates
    which date comes earlier on the calandar:
    Enter first date (mm/dd/yyyy): 3/6/08
    Enter second date (mm/dd/yyyy): 5/17/07
    5/17/07 is earlier than 3/6/08
 */
void exec5_09_01() {
    int d1, d2, m1, m2, y1, y2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d /%d /%d", &m1, &d1, &y1);
    printf("Enter second date (mm/dd/yy): ");
    scanf("%d /%d /%d", &m2, &d2, &y2);
// 1.选择语句：if语句和switch语句允许程序在一组可选项中选择一条特定的执行路径；
    if (y2 > y1)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
    else if (y1 > y2)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m2, d2, y2, m1, d1, y1);
    else if (m2 > m1)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
    else if (m1 > m2)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m2, d2, y2, m1, d1, y1);
    else if (d2 > d1)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
    else if (d1 > d2)
        printf("%d/%d/%.2d is earlier than %d/%d/%.2d\n", m2, d2, y2, m1, d1, y1);
    else
        printf("%d/%d/%.2d is equal to %d/%d/%.2d\n", m1, d1, y1, m2, d2, y2);
}

/*
 * 对上面过多的if-else语句进行优化
 * 通过对结果分析，只有三种结果，大于、小于、等于；
 * 可以分别等于这三种的情况进行整合，减少if-eles语句
 */

void exec05_09_03() {
    int month1, day1, year1;
    int month2, day2, year2;

    //Prompt user to enter the first date
    printf("Enter first date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month1, &day1, &year1);

    //Prompt user to enter the second date
    printf("Enter second date (mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month2, &day2, &year2);

    //Compare the dates
    //The program compares the dates by first checking the year. If the first year is less than the second year, the first date is earlier.
    //If the years are the same, it compares the months. If the first month is less than the second month, the first date is earlier.
    //If both the years and months are the same, it compares the days. If the first day is less than the second day, the first date is earlier.
    //If none of these conditions are true, the second date is earlier. If all parts of the dates are equal, the dates are the same.
    if (year1 < year2 || (year2 == year1 && month1 < month2) || (year1 == year2 && month1 == month2 && day1 < day2)) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month1, day1, year1, month2, day2, year2);
    } else if (year1 > year2 || (year1 == year2 && month1 > month2) ||
               (year1 == year2 && month1 == month2 && day1 > day2)) {
        printf("%d/%d/%d is earlier than %d/%d/%d\n", month2, day2, year2, month1, day1, year1);

    } else {
        printf("Both dates are the same.\n");

    }


}

/**
 * ate Comparison Function: compare_dates takes two Date structs and compares them,
 * returning -1 if the first is earlier, 1 if the second is earlier, and 0 if they are the same.
 */
int compare_dates(Date d1, Date d2) {
    if (d1.year != d2.year) {
        return d1.year < d2.year ? -1 : 1;
    }
    if (d1.month != d2.month) {
        return d1.month < d2.month ? -1 : 1;
    }
    if (d1.day != d2.day) {
        return d1.day < d2.day ? -1 : 1;
    }
}

//Input Function: read_date reads a date from the user input and stores it in a Date struct.
int read_date01(Date *date) {
    return scanf("%d%d%d", date->month, date->day, date->year);
}


// Function to validate if a date is correct
//The is_valid_date function checks if the date entered is valid,
// including leap year consideration for February.
bool is_valid_date(int day, int month, int year) {
    if (year < MIN_YEAR || year > MAX_YEAR || month < MIN_MONTH || month > MAX_MONTH || day < MIN_DAY) {
        return false;
    }
    int days_in_month[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Check for leap year
    if (month == 2) {
        bool is_leap = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
        if (is_leap) {
            days_in_month[1] = 29;
        }
    }

    return day <= days_in_month[month - 1];
}

// Function to prompt the user to enter a date and populate a Date struct
bool read_date(Date *date) {
    if (scanf("%d/%d/%d", &date->month, &date->day, &date->year) != 3) {
        printf("Invalid input format. Please enter the date in mm/dd/yyyy format.\n");
        return false;
    }
    if (!is_valid_date(date->day, date->month, date->year)) {
        printf("Invalid date. Please enter a valid date.\n");
        return false;
    }
    return true;
}

int main() {

    //exec05_09_04的代码优化
//    Date date1, date2;
//    //Prompt user to enter the first date
//    printf("Enter first date (mm/dd/yyyy): ");
//    if (read_date(&date1) != 3) {
//        printf("Invalid input format.\n");
//        return 1;
//    }
//
//    //Prompt user to enter the second date
//    printf("Enter second date (mm/dd/yyyy): ");
//    if (read_date(&date2) != 3) {
//        printf("Invalid input format.\n");
//        return 1;
//    }

    //exec05_09_05的最终优化版本，优化点如下：
    //1.Modularization:
    //The code is divided into smaller functions: compare_dates, is_valid_date, and read_date.
    //This improves readability, makes the code easier to test, and allows reuse of functions.
    //2.Validation:
    //The is_valid_date function checks if the date entered is valid, including leap year consideration for February.
    //The read_date function ensures the input is in the correct format and validates the date.
    //3.Documentation:
    //Comments are added to explain the purpose of each function and important sections of the code.
    //This helps other developers (or future you) understand the code more easily.
    //4.Error Handling:
    //The read_date function handles input errors gracefully, printing meaningful messages and returning false if the input is invalid.
    //The main function checks the return value of read_date and exits early if an error occurs.
    //5.Consistent Naming Conventions:
    //Variable and function names are clear and follow a consistent naming convention, improving code readability.
    //6.Use of Constants:
    //Constants such as MIN_YEAR, MAX_YEAR, MIN_MONTH, MAX_MONTH, and MIN_DAY are defined to avoid magic numbers in the code.
    //This makes it easier to modify these values if needed and improves code clarity.
    //By following these practices, the code becomes more reliable and maintainable, ensuring it is robust, easy to understand, and easy to modify.
    Date date1, date2;

    // Prompt user to enter the first date
    printf("Enter first date (mm/dd/yyyy): ");
    if (!read_date(&date1)) {
        return 1;
    }

    // Prompt user to enter the second date
    printf("Enter second date (mm/dd/yyyy): ");
    if (!read_date(&date2)) {
        return 1;
    }

    // Compare the dates
    int result = compare_dates(date1, date2);

    if (result < 0) {
        printf("%02d/%02d/%04d is earlier than %02d/%02d/%04d\n", date1.month, date1.day, date1.year, date2.month,
               date2.day, date2.year);
    } else if (result > 0) {
        printf("%02d/%02d/%04d is earlier than %02d/%02d/%04d\n", date2.month, date2.day, date2.year, date1.month,
               date1.day, date1.year);
    } else {
        printf("Both dates are the same.\n");
    }
    return 0;

}
