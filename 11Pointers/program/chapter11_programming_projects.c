/**
Created by mason on 2023/7/4
第11章:指针的课后编程题
 指针是C语言最重要-也是经常被误解的特性之一。由于指针的重要性，本书将用3章的篇幅进行讨论。
 本章侧重于基础知识。
 */
#include<stdio.h>

void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones);

void find_closest_flight(int desired_time,
                         int *departure_time,
                         int *arrival_time);

void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator);

int d1 = 480, a1 = 616,
        d2 = 583, a2 = 712,
        d3 = 679, a3 = 811,
        d4 = 767, a4 = 900,
        d5 = 840, a5 = 968,
        d6 = 945, a6 = 1075,
        d7 = 1140, a7 = 1280,
        d8 = 1305, a8 = 1438;

int main(void) {
    //课后编程练习题01
    int money = 0, twenties, tens, fives, ones;

    printf("Enter a dollar amount: ");
    scanf("%d", &money);
    pay_amount(money, &twenties, &tens, &fives, &ones);

    printf("$20 bills: %d\n", twenties);
    printf("$10 bills: %d\n", tens);
    printf(" $5 bills: %d\n", fives);
    printf(" $1 bills: %d\n", ones);
    //课后编程练习02
    int desired_time,
            departure_time,
            arrival_time,
            hour,
            minute;

    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);
    desired_time = hour * 60 + minute;
    find_closest_flight(desired_time, &departure_time, &arrival_time);

    printf("Closest departure time is %.2d:%.2d, arriving at %.2d:%.2d\n",
           departure_time / 60, departure_time % 60,
           arrival_time / 60, arrival_time % 60);
    //课后编程练习题03
    int num, denom, r_num, r_denom;

    printf("Enter a fraction: ");
    scanf("%d /%d", &num, &denom);

    reduce(num, denom, &r_num, &r_denom);


    return 0;
}



/**
 * 课后编程练习01:修改第二章的题7，使其包含下列函数：
 * 函数需要确定：为支付参数dollars表示的付款金额，所需20美元、10美元、5美元和1美元钞票的最小数目。twenties参数指向的
 * 变量存储所需20美元钞票的数目，tens、fives和ones参数类型类似.
 * @param dollars
 * @param twenties
 * @param tens
 * @param fives
 * @param ones
 */
void pay_amount(int dollars, int *twenties, int *tens, int *fives, int *ones) {
    *twenties = dollars / 20;
    dollars -= *twenties * 20;
    *tens = dollars / 10;
    dollars -= *tens * 10;
    *fives = dollars / 5;
    dollars -= *fives * 5;
    *ones = dollars;


}


/**
 * 课后编程练习02:修改第五章的编程题8，使其包含下列函数：
 * 函数需查出起飞时间与desired_time(用从午夜开始的分钟表示)最接近的航班。该航班的起飞时间和抵达时间(也都用从
 * 午夜开始的分钟数表示)将分别存储在departure_time和arrival_time所指向的变量中。
 * @param desired_time
 * @param departure_time
 * @param arrival_time
 */
void find_closest_flight(int desired_time, int *departure_time, int *arrival_time) {
    if (desired_time <= d1 + (d2 - d1) / 2) {
        *departure_time = d1;
        *arrival_time = a1;
    } else if (desired_time < d2 + (d3 - d2) / 2) {
        *departure_time = d2;
        *arrival_time = a2;
    } else if (desired_time < d3 + (d4 - d3) / 2) {
        *departure_time = d3;
        *arrival_time = a3;
    } else if (desired_time < d4 + (d5 - d4) / 2) {
        *departure_time = d4;
        *arrival_time = a4;
    } else if (desired_time < d5 + (d6 - d5) / 2) {
        *departure_time = d5;
        *arrival_time = a5;
    } else if (desired_time < d6 + (d7 - d6) / 2) {
        *departure_time = d6;
        *arrival_time = a6;
    } else if (desired_time < d7 + (d8 - d7) / 2) {
        *departure_time = d7;
        *arrival_time = a7;
    } else {
        *departure_time = d8;
        *arrival_time = a8;
    }
}

/**
 * 课后编程练习题03:修改第六章的编程题3，使其包含下列函数
 *
 * @param numerator
 * @param denominator
 * @param reduced_numerator
 * @param reduced_denominator
 */
void reduce(int numerator, int denominator, int *reduced_numerator, int *reduced_denominator) {
    int m = numerator, n = denominator, r;

    while (n != 0) {
        r = m % n;
        m = n;
        n = r;
    }

    *reduced_numerator = numerator / m;
    *reduced_denominator = denominator / m;
}