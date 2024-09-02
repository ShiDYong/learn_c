/**
Created by mason on 2023/7/4
第11章:指针的课后编程题
 */
#include<stdio.h>
#include <Basic.h>
#include<CUnit.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>
//使用预定义的常量来替代硬编码的数值，提高代码的可维护性
#define TWENTY 20
#define TEN 10
#define FIVE 5
#define ONE 1
#define NUM_ENTRIES 8

//Enum for AM/PM indicators
enum Indicator {
    AM,
    PM
};
// Structure to hold time points and related data
typedef struct {
    int time; // Time in minutes since midnight
    int arrival; // Arrival time in minutes since midnight
} TimePoint;

//Function prototypes
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

int get_positive_integer_input(const char *prompt);

void test_pay_amount(void);

void find_closest_flight(int desired_time, int *departure_time, int *arrival_time);

int convert_to_minutes(int hour, int minute);

void print_time(int minutes_since_midnight);

void test_find_closest_flight(void);

int test_unit();

// Flight schedule defined globally for access by any function
const TimePoint flights[NUM_ENTRIES] = {
        {8 * 60 + 0,   10 * 60 + 16}, // Departure: 08:00, Arrival: 10:16
        {9 * 60 + 43,  11 * 60 + 52}, // Departure: 09:43, Arrival: 11:52
        {11 * 60 + 19, 13 * 60 + 31}, // Departure: 11:19, Arrival: 13:31
        {12 * 60 + 47, 15 * 60 + 0},  // Departure: 12:47, Arrival: 15:00
        {14 * 60 + 0,  16 * 60 + 8},  // Departure: 14:00, Arrival: 16:08
        {15 * 60 + 45, 17 * 60 + 55}, // Departure: 15:45, Arrival: 17:55
        {19 * 60 + 0,  21 * 60 + 20}, // Departure: 19:00, Arrival: 21:20
        {21 * 60 + 45, 23 * 60 + 58} // Departure: 21:45, Arrival: 23:58
};

/*int main(void) {
    int dollars;

    int twenties, tens, fives, ones;
    dollars = get_positive_integer_input("Enter a dollar amount: ");
    //Call the function to calculate the number of bills
    pay_amount(dollars, &twenties, &tens, &fives, &ones);
    printf("$%d bills: %d\n", TWENTY, twenties);
    printf("$%d bills: %d\n", TEN, tens);
    printf("$%d bills: %d\n", FIVE, fives);
    printf("$%d bills: %d\n", ONE, ones);

    //初始化 CUnit 的注册表。这是启动 CUnit 测试框架的第一步，它会准备测试环境，确保所有测试都能正确运行
    if (CU_initialize_registry() != CUE_SUCCESS) {
        return CU_get_error();
    }    //创建一个测试套件（suite）。测试套件是用来组织一组相关的测试用例的容器。
    CU_pSuite suite = CU_add_suite("Calculate Bills Suite", NULL, NULL);
    if (suite == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    //向测试套件中添加一个测试用例
    // suite: 在上一步创建的测试套件。
    //"Test Calculate Bills": 测试用例的名字。
    //test_pay_amount: 测试用例的函数指针。这是实际执行测试逻辑的函数
    // Add the test to the suite
    if (CU_add_test(suite, "Test Calculate Bills", test_pay_amount) == NULL) {
        CU_cleanup_registry();
        return CU_get_error();
    }
    //运行所有已添加到注册表中的测试套件和测试用例
    CU_basic_run_tests();
    //清理 CUnit 注册表。这是 CUnit 测试结束后必须执行的步骤
    CU_cleanup_registry();


    *//*
     运行后控制台输出：
     Run Summary:      Type   Total   Ran  Passed   Failed Inactive
              suites      1      1    n/a      0        0
               tests      1      1      0      1        0
             asserts     43     43     40      3       n/a
Elapsed time =    0.000 seconds
     Type: 表示测试的类型，包括测试套件（suites）和测试用例（tests）。
     Total: 表示测试套件或测试用例的总数。
     Ran: 表示已执行的测试套件或测试用例的数量。
     Passed: 表示通过的测试用例数量。
     Failed: 表示失败的测试用例数量。
     Inactive: 表示未激活（未执行）的测试用例数量
     分析
    Suites: 有一个测试套件被定义，并且这个测试套件被运行了。
    Tests: 有一个测试用例被定义，并且这个测试用例被运行了。
    Asserts: 有 43 个断言被定义，并且所有 43 个断言都被执行了。
    Passed: 共有 40 个断言通过了测试。
    Failed: 有 3 个断言失败了测试
     *//*
    printf("################################查找最近出发的航班############################################");
    int hour, minute;
    printf("Enter a 24-hour time (HH MM): ");
    if (scanf("%d:%d", &hour, &minute) != 2 || hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        fprintf(stderr, "Invalid time format. Please use HH MM(24-hour format).\n");
        return EXIT_FAILURE;
    }
    int desired_time = convert_to_minutes(hour, minute);
    int departure_time, arrival_time;
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    // Display the closest departure and arrival time
    printf("Closest departure time is ");
    print_time(departure_time);
    printf(", arriving at ");
    print_time(arrival_time);
    printf(".\n");

    test_unit();


    return 0;

}*/

/*
 * 为了方便查找最近的航班，需要优化
 */
int test_unit() {
// Initialize the CUnit test registry
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    // Add a suite to the registry
    CU_pSuite pSuite = CU_add_suite("find_closest_flight_test_suite", 0, 0);
    if (NULL == pSuite) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Add the test to the suite
    if ((NULL == CU_add_test(pSuite, "test of find_closest_flight", test_find_closest_flight))) {
        CU_cleanup_registry();
        return CU_get_error();
    }

    // Run all tests using the basic interface
    CU_basic_set_mode(CU_BRM_VERBOSE);
    CU_basic_run_tests();
    CU_cleanup_registry();
    return CU_get_error();
}

/*
 * 测试查找最近航班的单元测试用例代码
    1.边界条件:
    输入时间正好等于最后一个航班的起飞时间。
    输入时间正好等于第一个航班的起飞时间。
    输入时间正好位于两个航班之间。
    2.异常情况:
    输入时间早于所有航班的起飞时间。
    输入时间晚于所有航班的起飞时间。
    输入时间在最后一个航班之后的第二天。
    3.极端情况:
    输入时间为午夜 00:00。
    输入时间为午夜 23:59。
    4.特殊时间点:
    输入时间为中午 12:00。
    输入时间为凌晨 00:01。
    输入时间为晚上 23:59。
 */
void test_find_closest_flight(void) {
    int departure_time, arrival_time;
    //Boundary conditions
    //Test case 1: Exact match with the first flight(8:00 a.m.)
    find_closest_flight(8 * 60, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 8 * 60);
    CU_ASSERT_EQUAL(arrival_time, 10 * 60 + 16);
    // Test case 2: Exact match with the last flight (9:45 p.m.)
    find_closest_flight(21 * 60 + 45, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 21 * 60 + 45);
    CU_ASSERT_EQUAL(arrival_time, 23 * 60 + 58);

    // Test case 3: Desired time matches the first flight's arrival time (10:16 a.m.)
    find_closest_flight(10 * 60 + 16, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 8 * 60);
    CU_ASSERT_EQUAL(arrival_time, 10 * 60 + 16);

    // Test case 4: Desired time matches the last flight's arrival time (11:58 p.m.)
    find_closest_flight(23 * 60 + 58, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 21 * 60 + 45);
    CU_ASSERT_EQUAL(arrival_time, 23 * 60 + 58);

    // Test case 5: Input time is exactly between two flights (10:00 a.m. closer to 9:43 a.m.)
    find_closest_flight(10 * 60, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 9 * 60 + 43);
    CU_ASSERT_EQUAL(arrival_time, 11 * 60 + 52);

    // Exceptional cases
    // Test case 6: Desired time before all departures (6:00 a.m.)
    find_closest_flight(6 * 60, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 8 * 60);
    CU_ASSERT_EQUAL(arrival_time, 10 * 60 + 16);

    // Test case 7: Desired time after all departures (11:00 p.m.)
    find_closest_flight(23 * 60, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 21 * 60 + 45);
    CU_ASSERT_EQUAL(arrival_time, 23 * 60 + 58);

    // Test case 8: Desired time is after the last flight and into the next day (1:00 a.m. next day)
    find_closest_flight(25 * 60, &departure_time, &arrival_time);  // 25:00 (next day)
    CU_ASSERT_EQUAL(departure_time, 8 * 60);
    CU_ASSERT_EQUAL(arrival_time, 10 * 60 + 16);

    // Extreme cases

    // Test case 9: Input time is midnight (00:00)
    find_closest_flight(0, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 8 * 60);
    CU_ASSERT_EQUAL(arrival_time, 10 * 60 + 16);

    // Test case 10: Input time is the last minute of the day (23:59)
    find_closest_flight(23 * 60 + 59, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 21 * 60 + 45);
    CU_ASSERT_EQUAL(arrival_time, 23 * 60 + 58);

    // Special time points

    // Test case 11: Input time is noon (12:00)
    find_closest_flight(12 * 60, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 11 * 60 + 19);
    CU_ASSERT_EQUAL(arrival_time, 13 * 60 + 31);

    // Test case 12: Input time is just after midnight (00:01)
    find_closest_flight(0 * 60 + 1, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 8 * 60);
    CU_ASSERT_EQUAL(arrival_time, 10 * 60 + 16);

    // Test case 13: Input time is just before midnight (23:59)
    find_closest_flight(23 * 60 + 59, &departure_time, &arrival_time);
    CU_ASSERT_EQUAL(departure_time, 21 * 60 + 45);
    CU_ASSERT_EQUAL(arrival_time, 23 * 60 + 58);
}

/*
 * 使用 CUnit 框架来实现单元测试
 */
void test_pay_amount(void) {
    int twenties, tens, fives, ones;
    // Test case 1: Normal situation
    pay_amount(93, &twenties, &tens, &fives, &ones);
    CU_ASSERT_EQUAL(twenties, 4);
    CU_ASSERT_EQUAL(tens, 1);
    CU_ASSERT_EQUAL(fives, 0);
    CU_ASSERT_EQUAL(ones, 3);

    // Test case 2: Boundary condition (zero)
    pay_amount(0, &twenties, &tens, &fives, &ones);
    CU_ASSERT_EQUAL(twenties, 0);
    CU_ASSERT_EQUAL(tens, 0);
    CU_ASSERT_EQUAL(fives, 0);
    CU_ASSERT_EQUAL(ones, 0);

    // Test case 3: Boundary condition (minimum positive amount)
    pay_amount(1, &twenties, &tens, &fives, &ones);
    CU_ASSERT_EQUAL(twenties, 0);
    CU_ASSERT_EQUAL(tens, 0);
    CU_ASSERT_EQUAL(fives, 0);
    CU_ASSERT_EQUAL(ones, 1);

    // Test case 4: Amount just below a multiple of 20
    pay_amount(19, &twenties, &tens, &fives, &ones);
    CU_ASSERT_EQUAL(twenties, 0);
    CU_ASSERT_EQUAL(tens, 1);
    CU_ASSERT_EQUAL(fives, 1);
    CU_ASSERT_EQUAL(ones, 4);

    // Test case 5: Exact multiple of 20
    pay_amount(20, &twenties, &tens, &fives, &ones);
    CU_ASSERT_EQUAL(twenties, 1);
    CU_ASSERT_EQUAL(tens, 0);
    CU_ASSERT_EQUAL(fives, 0);
    CU_ASSERT_EQUAL(ones, 0);

    // Test case 6: Amount just above a multiple of 20
    pay_amount(21, &twenties, &tens, &fives, &ones);
    CU_ASSERT_EQUAL(twenties, 1);
    CU_ASSERT_EQUAL(tens, 0);
    CU_ASSERT_EQUAL(fives, 0);
    CU_ASSERT_EQUAL(ones, 1);

    // Test case 7: Negative input (edge case)
    pay_amount(-10, &twenties, &tens, &fives, &ones);
    CU_ASSERT_EQUAL(twenties, 0);
    CU_ASSERT_EQUAL(tens, 0);
    CU_ASSERT_EQUAL(fives, 0);
    CU_ASSERT_EQUAL(ones, 0);

    // Test case 8: Null pointers (edge case)
    pay_amount(50, NULL, &tens, &fives, &ones);
    CU_ASSERT_EQUAL(tens, 0);  // Tens should remain unchanged
    CU_ASSERT_EQUAL(fives, 0);  // Fives should remain unchanged
    CU_ASSERT_EQUAL(ones, 0);  // Ones should remain unchanged

    // Test case 9: Very large input (edge case)
    pay_amount(1000000, &twenties, &tens, &fives, &ones);
    CU_ASSERT_EQUAL(twenties, 50000);
    CU_ASSERT_EQUAL(tens, 0);
    CU_ASSERT_EQUAL(fives, 0);
    CU_ASSERT_EQUAL(ones, 0);

    // Since C does not natively support passing strings or floats to an int function,
    // we simulate these cases by verifying the function doesn't accept these types directly.
    // We won't be able to run these without causing compilation errors.

    // Test case 10: Simulate string input (in reality, this would cause a compilation error)
    // int dollars = "123";  // Compilation error: incompatible types
    // pay_amount(dollars, &twenties, &tens, &fives, &ones);
    // CU_FAIL("Function should not accept string input.");

    // Test case 11: Simulate floating-point input
    float float_dollars = 45.67f;  // Assuming you want to handle floats
    pay_amount((int) float_dollars, &twenties, &tens, &fives, &ones);  // Cast to int
    CU_ASSERT_EQUAL(twenties, 2);
    CU_ASSERT_EQUAL(tens, 0);
    CU_ASSERT_EQUAL(fives, 1);
    CU_ASSERT_EQUAL(ones, 0);

    // Test case 12: Zero input again to validate edge boundaries (repetition for clarity)
    pay_amount(0, &twenties, &tens, &fives, &ones);
    CU_ASSERT_EQUAL(twenties, 0);
    CU_ASSERT_EQUAL(tens, 0);
    CU_ASSERT_EQUAL(fives, 0);
    CU_ASSERT_EQUAL(ones, 0);

}


/**
 *
  Project 11.01
    Write a program that asks the user to enter a U.S. dollar amount and then shows
    how to pay that amount using the smallest number of $20, $10, $5 and $1 bills:
    ```
    Enter a dollar amount: 93
    $20 bills: 4
    $10 bills: 1
     $5 bills: 0
     $1 bills: 3
    function:
    ```c
    void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);
     ```
    The function determines the smallest number of $20, $10, $5 and $1 bills
    necessary to pay the amount represented by the `dollars` parameter. The
    `twenties` parameter points to a variable in which the function will store the
    number of $20 bills required. The `tens`, `fives` and `ones` parameters are
    similar.
 */

/**
 *  Calculates the minimum number of $20, $10, $5, and $1 bills
 *   needed to make up the specified amount.
 * @param dollars  dollars The total amount in dollars.
 * @param twenties twenties Pointer to an integer to store the number of $20 bills.
 * @param tens tens Pointer to an integer to store the number of $10 bills.
 * @param fives fives Pointer to an integer to store the number of $5 bills.
 * @param ones ones Pointer to an integer to store the number of $1 bills.
 */
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    // Check for valid input (dollars should be non-negative)
    if (dollars < 0 || twenties == NULL || tens == NULL || fives == NULL || ones == NULL) {
        fprintf(stderr, "Invalid input provided to pay_amount function.\n");
        return;
    }
    //Calculate the number of each bill type
    *twenties = dollars / TWENTY;
    dollars %= TWENTY;
    *tens = dollars / TEN;
    dollars %= TEN;
    *fives = dollars / FIVE;
    *ones = dollars % FIVE;


}


/**
 * Prompts the user for a positive integer and returns it
 * @param prompt A String to display as a prompt
 * @return A positive integer entered by the user
 */
int get_positive_integer_input(const char *prompt) {
    int value;
    while (1) {
        printf("%s", prompt);
        if (scanf("%d", &value) == 1 && value >= 0) {
            //Clear the input buffer
            //下面的循环主要用于读取并丢弃输入缓冲区中的字符，直到遇到换行符 ('\n') 为止
            // 这个循环通常用于清理输入缓冲区中的多余字符，防止这些字符影响后续的输入
            while (getchar() != '\n');
            return value;
        } else {
            //Clear the input buffer
            while (getchar() != '\n');
            fprintf(stderr, "Invalid input. Please enter a non-negative integer.\n");

        }
    }
}

/** Project 11.02
 * 综合题目：会使用到非常多的C语言基础知识
    The following table shows the daily flights from one city to another:
    | Departure time | Arrival time |
    | ---: | ---: |
    | 8:00 a.m. | 10:16 a.m. |
    | 9:43 a.m. | 11:52 a.m. |
    | 11:19 a.m. | 1:31 p.m. |
    | 12:47 p.m. | 3:00 p.m. |
    | 2:00 p.m. | 4:08 p.m. |
    | 3:45 p.m. | 5:55 p.m. |
    | 7:00 p.m. | 9:20 p.m. |
    | 9:45 p.m. | 11:58 p.m. |
    Write a program that asks the user to enter a time (expressed in hours and
    minutes, using the 24-hour clock). The program then displays the departure and
    arrival times for the flight whose departure time is closest to that entered by
    the user:
    ```
    Enter a 24-hour time: 13:15
    Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
    ```
    his function wil find the flight whose departure time is closest to
    `desired_time` (expressed in minutes since midnight). It will store the
    departure and arrival times of this flight (also expressed in minutes since
    midnight) in the variables pointed to by `departure_time` and `arrival_time`,
    respectively.
    *Hint*: Convert the input into a time expressed in minutes since midnight, and
    compare it to the departure times, also expressed in minutes since midnight. For
    example, 13:15 is 13 * 60 + 15 = 795 minutes since midnight, which is closer to
    12:47 p.m. (767 minutes since midnight) than to any of the other departure
    times
 */
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {
    //计算整数的绝对值
    int min_diff = abs(flights[0].time - desired_time);
    int closest_index = 0;
    for (int i = 1; i < NUM_ENTRIES; i++) {
        int diff = abs(flights[i].time - desired_time);
        if (diff < min_diff) {
            min_diff = diff;
            closest_index = i;
        }

    }
    *departure_time = flights[closest_index].time;
    *arrival_time = flights[closest_index].arrival;
}

int convert_to_minutes(int hour, int minute) {
    return hour * 60 + minute;
}


void print_time(int minute_since_midnight) {
    int hour = minute_since_midnight / 60;
    int minute = minute_since_midnight % 60;
    const char *indicator = (hour >= 12) ? "p.m." : "a.m.";
    if (hour == 0) hour = 12;
    else if (hour > 12) hour -= 12;
    printf("%d:%.2d %s", hour, minute, indicator);

}

