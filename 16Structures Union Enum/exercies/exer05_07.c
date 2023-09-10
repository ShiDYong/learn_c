/********************************************************************************
* @author: mason shi
* @date: 2023/8/15 22:09
* @version: 1.0
* @description: 课后练习题05——07
********************************************************************************/
#include<stdio.h>

#define TRUE 1
#define FALSE 0
//课后练习题05的结构变量
struct date {
    int month, day, year;
};
//课后练习题06的结构变量
struct time{
    int hours,minutes,seconds;
};

//课后练习题07的结构变量
struct fraction{
    int numerator,denominator;
};
struct fraction reduce_fraction(struct fraction f);

void exec_05();
int day_of_year(struct date d);
int compare_dates(struct date d1,struct date d2);
int day_of_year_02(struct date d);
int is_leap_year(int year);
struct time split_time(long total_seconds);
void exec_07();
struct fraction reduce_fraction(struct fraction f);
struct fraction add_fractions(struct fraction f1, struct fraction f2);
struct fraction subtract_fractions(struct fraction f1, struct fraction f2);
struct fraction multiply_fractions(struct fraction f1, struct fraction f2);
struct fraction divide_fractions(struct fraction f1, struct fraction f2);

        int main(void) {
// struct date d={d.month=3,d.day=3,d.year=2021};
// struct date d2={d2.month=3,d2.day=5,d2.year=2020};
//    printf("输出的天数是一年中的%d天\n", day_of_year_02(d));
  //  printf("两个日期的比较大小结果：%d\n", compare_dates(d,d2));
//  int seconds = 56900;
//  struct time t= split_time(seconds);
//    printf("返回换算后的时间是：%d时%d分%d秒\n",t.hours,t.minutes,t.minutes);
    //注意下面的方法测试方法可读性
    long total_seconds;
    printf("Enter total seconds since midnight: ");
    scanf("%ld", &total_seconds);
    struct time t = split_time(total_seconds);
    printf("Equivalent time: %02d:%02d:%02d\n", t.hours, t.minutes, t.seconds);

    return 0;
}


/**
 * 课后练习题05:
 *
 */
void exec_05() {
    //5.编写下列函数，假定date结构包含三个成员：month,day和year(都是int类型).

}

/**
 * 5题目a：返回d是一年中的第多少天？(1~366范围内的整数)
 * @param d
 * @return
 */
int day_of_year(struct date d) {
    //以下是自己写的方法比较冗余
   int flag = d.year % 100 && d.year % 400 == 0 ? TRUE : FALSE;
    int day_of_year=-1;
   if(d.day<1 || d.day>31)
       return day_of_year;
    switch (d.month) {
        //要学会思考下面是有很多是重复的，可以进行优化的,不然就是纯硬编码的
        case 1: day_of_year=d.day;break;
        case 2: day_of_year=31+d.day;break;
        case 3: day_of_year=31+28+d.day;break;
        case 4: day_of_year=31*2+28+d.day;break;
        case 5: day_of_year=31*2+28+30+d.day;break;
        case 6: day_of_year=31*3+30+28+d.day;break;
        case 7: day_of_year=31*3+30*2+28+d.day;break;
        case 8: day_of_year=31*4+30*2+28*d.day;break;
        case 9: day_of_year=31*5+30*2+28+d.day;break;
        case 10: day_of_year=31*5+30*3+28+d.day;break;
        case 11: day_of_year=31*6+30*3+28+d.day;break;
        case 12: day_of_year=31*6+30*4+28+d.day;break;
        default:
                return day_of_year;
    }
        //判断是否为平年还是闰年
        if(flag || d.year % 4)
           return day_of_year+=1;
        else
            return day_of_year;

}

int day_of_year_02(struct date d){
    int dayOfYear =0,i;
    const int days_month[12]={31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    //判断是否平年还是闰年的方法可以再进行优化,下面最终展示的是非常简洁
    for(i=0;i< d.month-1;i++)
        dayOfYear+= days_month[i];
    if(is_leap_year(d.year))
        dayOfYear++;
      //上面这种方法可以替换成下面的方式
   /* for ( i = 0; i < d.month-1; i++) {
        dayOfYear += days_month[i];
        if (i == 1 && is_leap_year(d.year)) {
            dayOfYear++; // Adding one extra day for February in leap years
        }
    }*/
    return dayOfYear;
}

int is_leap_year(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}
/**
 * 课后练习题05(b):如果日期d1在d2之前，返回-1；如果d1在d2之后返回+1；如果
 * d1和d2相等，返回0；
 * @param d1
 * @param d2
 * @return
 */
int compare_dates(struct date d1,struct date d2){
    //方法一：是没有借助前一个方法纯编码实现
//    if(d1.year < d2.year)
//        return -1;
//    else if(d1.year==d2.year)
//        if(d1.month < d2.month)
//            return -1;
//        else if(d1.month == d2.month && d1.day < d2.day)
//            return -1;
//        else if(d1.month == d2.month && d1.day ==d2.day)
//            return 0;
//        else
//            return 1;
//    else
//        return 1;
    //对上面的方法进一步优化
    if (d1.year < d2.year) {
        return -1;
    } else if (d1.year > d2.year) {
        return 1;
    } else {
        if (d1.month < d2.month) {
            return -1;
        } else if (d1.month > d2.month) {
            return 1;
        } else {
            if (d1.day < d2.day) {
                return -1;
            } else if (d1.day > d2.day) {
                return 1;
            } else {
                return 0;
            }
        }
    }
    //方法二的实现是前面的方法实现：
    int d1day = day_of_year(d1);
    int d2day = day_of_year(d2);
    if (d1day > d2day)
        return -1;
    else if (d1day < d2day)
        return 1;
    else
        return 0;


}

/**
 * 课后练习06:编写下列函数，假定time结构包含三个成员:hours、minutes和seconds(都是int类型)
 * struct time split_time(long total_seconds);
 * total_seconds是从午夜开始的秒数。函数返回一个包含等价时间的结构，等价的时间用小时(0~23)、分钟(0～59)和秒(0~59)表示.
 * @param total_seconds
 * @return
 */
struct time split_time(long total_seconds){
    //如果秒数转换成hour超过24小时,是不是要进一步做出判断
    struct time t={0,0,0};
    if(total_seconds <=0)
        return t;
//    t.hours=(int)total_seconds/3600;
//    t.minutes =(int)(total_seconds - t.hours*3600)/60;
//    t.seconds =(int)total_seconds-t.hours*3600-t.minutes*60;
//    return t;
    t.hours = total_seconds / 3600;
    total_seconds %= 3600; //这里利用取余方法更加简洁，平时要注意使用这些技巧，提高效率
    t.minutes = total_seconds / 60;
    t.seconds =total_seconds %60;
    return t;

}

/**
 * 课后练习题07
 */
void exec_07(){

    /*假定fraction结构包含两个成员：numerator和denominator(都是int类型)。编写函数完成下列分数运算。
 * a.把分数f化为最简形式。提示：为了把分数化为最简单形式，首先计算分子和分母的最大公约数(GCD)，然后把分子和分母都除以
 *      该最大公约数。
 * b.把分数f1和f2相加。
 * c.从分数f1中减去分数f2.
 * d.用分数f1和f2相乘。
 * e.用分数f1除以分数f2.
 * 分数f、f1和f2都是struct fraction类型的参数。每个函数返回一个struct fraction类型的值。
 * (b)～(e)中函数返回的分式应为最简形式。提示：可以使用(a)中的函数辅助编写(b)~(c)中的函数。
 * */



}

/**
 * 课后练习07 a题目：
 * @param f
 * @return
 */
struct fraction reduce_fraction(struct fraction f) {
    int temp;
    int n = f.numerator, d = f.denominator;

    while (n % d != 0) {
        temp = d;
        d = n % d;
        n = temp;
    }
    f.numerator /= d;
    f.denominator /= d;
    return f;
}

/**
 * 课后练习题07.b题目
 * @param f1
 * @param f2
 * @return
 */
struct fraction add_fractions(struct fraction f1, struct fraction f2) {
    return reduce_fraction((struct fraction) {f1.numerator * f2.denominator +
                                              f2.numerator * f1.denominator, f1.denominator * f2.denominator});
}

/**
 * 课后练习07.c
 * @param f1
 * @param f2
 * @return
 */
struct fraction subtract_fractions(struct fraction f1, struct fraction f2) {
    return reduce_fraction((struct fraction) {f1.numerator * f2.denominator -
                                              f2.numerator * f1.denominator, f1.denominator * f2.denominator});
}

/**
 * 课后练习07.d
 * @param f1
 * @param f2
 * @return
 */
struct fraction multiply_fractions(struct fraction f1, struct fraction f2) {
    return reduce_fraction((struct fraction) {f1.numerator * f2.numerator,
                                              f1.denominator * f2.denominator});
}

/**
 * 课后练习07.e
 * @param f1
 * @param f2
 * @return
 */

struct fraction divide_fractions(struct fraction f1, struct fraction f2) {
    return reduce_fraction((struct fraction) {f1.numerator * f2.denominator,
                                              f1.denominator * f2.numerator});
}
