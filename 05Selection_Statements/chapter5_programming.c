/**
Created by mason on 2023/5/4.
 第五章：选择语句课后编程题
 */
#include<stdio.h>

/**
 * 编程题01:编写一个程序，确定一个数的位数
 * Enter a number: 374
 * The number 384 has 3 digits
 * 假设输入的数最多不超过4位。
 */
void exec5_01() {
    int n;
    //可以新加一个位数的变量，避免重复打印
    int d;
    printf("Enter a number: ");
    scanf("%d", &n);
    //利用if语句进行数的判定，如果数在0-9那么位数为1；如果位数在10和99之间，那么位数位为2；
    if (0 <= n && n <= 9)
        //printf("The number %d has 1 digits\n", n);
        d = 1;
    else if (10 <= n && n <= 99)
        //printf("The number %d has 2 digits\n", n);
        d = 2;
    else if (100 <= n && n <= 999)
        //printf("The number %d has 3 digits\n", n);
        d = 3;
    else if (1000 <= n && n <= 9999)
        // printf("The number %d has 4 digits\n", n);
        d = 4;
    printf("The number %d has %d digits\n", n, d);

//    else
//        printf("The enter number %d is illegal\n", n);


}

/**
 * 编程题目二：编写一个程序，要求用户输入24小时制的时间，然后显示12小时制的格式：
 * Enter a 24-hour time: 21:11
 * Equivalent 12-hour time: 9:11 PM
 *
 */
void exec5_2() {
    int hour, minute;
    printf("Enter a 24-hour time: ");
    scanf("%d :%d", &hour, &minute);
    //判断hour是否大于12点，如果大于12点，hour-12的值加上PM,等于12点就是12:00
    //if (hour <= 12)
    //printf("Equivalent 12-hour time: %d:%d AM", hour, minute);
    if (hour < 12)
        printf("Equivalent 12-hour time: %d:%d AM\n",
               hour, minute); //这种方法是存在如果0:00，反而显示的12：0AM，这是不合理的


    else
        // printf("Equivalent 12-hour time: %d:%d PM", hour - 12, minute);
        printf("Equivalent 12-hour time: %d:%d PM\n",
               hour == 12 ? 12 : hour - 12, minute);
    //打印的方式存在的问题是12:00显示的12：0
}


/**
 * 课后编程题第3题
 * 3。修改5.3节的broker.c程序，做出下面两种改变。
 * a.不再直接输出交易额，而是要求用户输入股票的数量和每股的价格；
 * b.增加语句来计算经纪人竞争对手的佣金(少于2000股时佣金为每股33美元+3美分，2000股或更多股时佣金为每股33美元+2美分).
 在显示原有经纪人佣金的同时，也显示出竞争对手的佣金
 *
 *
 */

void exec5_3() {
    int num;
    float price, trade, commission, commission_competitor;
    printf("Enter stock of number and price: ");
    //避免用户输入时出现异常，可以分别输入两次
    scanf("%d %f", &num, &price);
    trade = num * price;

    if (trade < 2500.00f)
        commission = 30.00f + trade * 0.017f;
        /* else if(trade >= 2500.00f && trade < 6250.00f)
             commission = 56.00f + trade * 0.0066f;
             注意上这种写法是多余的。如果第一个if字句的trade的值小于2500则计算佣金，
             当到达第二个if测试时，trade不可能小于2500，因此一定大于2500，条件trade>=
             2500.00f总是为真，因此加上这个条件是没有意义的
             if语句和switch语句允许程序在一组可选项中选择一条特定的执行路径；
             */
    else if (trade < 6250.00f)
        commission = 56.00f + trade * 0.0066f;
    else if (trade < 20000.00f)
        commission = 76.00f + trade * 0.0034f;
    else if (trade < 50000.00f)
        commission = 100.00f + trade * 0.0022f;
    else if (trade < 500000.00f)
        commission = 155.00f + trade * 0.0011f;
    else
        commission = 255.00f + trade * 0.0009f;
    if (commission < 39.00f)

        commission = 39.00f;
//    if (num < 2000)
//        //commission_competitor = num * 33.03f; 计算方式有问题，调试执行时发现数据相差太大了
//        commission_competitor = 33.00f + 0.03f * num;
//    else
//        commission_competitor = 33.00f + 0.02f * num;
    //竞争对手的计算佣金还可以三元运算符,更加简洁一些,减少不必要的if else等等
    commission_competitor = num < 2000 ? (33.00f + 0.03f * num) : (33.00f + 0.02f * num);

    //变量取名的：shares股票，share_price每股价格
    printf("broker Commission is:$%.2f\n", commission);
    printf("competitor Commission is:$%.2f\n", commission_competitor);

}

/**
 * 编程练习题4:表5-6中展示了测量风力的莆福风级的简化版本
 * 编写一个程序，要求用户输入风速(海里/小时),然后显示相应的描述
 */
void exec5_4() {
    int speed;
    printf("Enter wind of speed: ");
    scanf("%d", &speed);
    printf("Wind description: ");

    if (speed < 1)
        printf("Calm\n");
    else if (speed <= 3)
        printf("Light air\n");
    else if (speed <= 27)
        printf("Breeze\n");
    else if (speed <= 47)
        printf("Gale\n");
    else if (speed <= 63)
        printf("Storm\n");
    else
        printf("Hurricane\n");
}

/**
 * 编程题5：在美国的某个州，单身居民的需要缴纳表5-7中列出的所得税
 * 编写一个程序，要求用户输入应缴纳的所得税，然后显示税金
 */
void exec5_5() {
    float income, person_income_tax;
    printf("Enter individual income: ");
    scanf("%f", &income);
    if (income <= 750.00f)
        person_income_tax = income * 0.01f;
    else if (income <= 2250.00f)
        person_income_tax = 7.50f + (income - 750.00f) * 0.02f;
    else if (income <= 3750.00f)
        person_income_tax = 37.50f + (income - 2250.00f) * 0.03f;
    else if (income <= 5250.00f)
        person_income_tax = 82.50f + (income - 3750.00f) * 0.04f;
    else if (income <= 7000.00f)
        person_income_tax = 142.50f + (income - 5350.00f) * 0.05f;
    else
        person_income_tax = 230.00f + (income - 7000.00f) * 0.06f;
    printf("You should pay personal income tax: $%0.2f\n", person_income_tax);
}

/**
 * 编程题6:修改4.1节的upc.c程序，使其可以检测CPC的有效性。在用户输入UPC后，程序将显示VALID或者NOT VALID.
 */
void exec5_6() {
    int i0, i1, i2, i3, i4, i5, i6, i7, i8, i9, i10, i11, first_sum, second_sum, total;
    printf("Enter the complete digit of a UPC: ");
    scanf("%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d%1d", &i0, &i1, &i2, &i3, &i4, &i5, &i6, &i7, &i8, &i9, &i10, &i11);
    first_sum = i0 + i2 + i4 + i6 + i8 + i10;
    second_sum = i1 + i3 + i5 + i7 + i9;
    total = (first_sum * 3) + second_sum - 1;
    9 - (total % 10) == i11 ? printf("UPC is VALID\n") : printf("UPC is NOT VALID\n");


}

/**
 * 编程练习题7:编写一个程序，从用户输入的4个整数中找出最大值和最小值
 * Enter four integer: 21 43 10 35
 * Largest: 43
 * Smallest:10
 * 要求尽可能少用if语句。提示：4条if语句就足够了
 */
void exec5_7() {
    int n1, n2, n3, n4, max, min, max1, max2, min1, min2;
    printf("Enter four integer: ");
    //读取这里不好控制时几位数的整数进行比较大小,这里取值是2位整数
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
    if (n1 < n2) {
        max1 = n2;
        min1 = n1;
    } else {
        max1 = n1;
        min1 = n2;
    }
    if (n3 < n4) {
        max2 = n4;
        min2 = n3;
    } else {
        max2 = n3;
        min2 = n4;
    }

    if (max2 > max1)
        max = max2;
    else
        max = max1;
    if (min2 > min1)
        min = min1;
    else
        min = min2;

    //以上两个if语句可以直接用三元运算符替换,但是可读性不高
//    n1 < n2 ? (max1 = n2, min1 = n1) : (max1 = n1, min1 = n2);
//    n3 < n4 ? (max2 = n4, min2 = n3) : (max2 = n3, min2 = n4);
//    max2 > max1 ? (max = max2) : (max = max1);
//    min2 > min1 ? (min = min1) : (min = min2);

    printf("Largest: %d\nSmallest: %d\n", max, min);

}

/**
 * 课后编程题8:编写一个程序，要求用户输入一个时间(用24小时制的时分表示)。程序选择起飞时间与用户输入最接近的航班，
 * 显示出相应的起飞时间和抵达时间。
 * Enter a 24-hour time : 13:14
 * Closest departure time is 12:47 p.m,arriving time at 3:00 p.m
 */
//以下是处理的方式一:是自己想的最开始思路
void exec5_8_1() {
    int hour, min, total_min, middle_time;
    printf("Enter a 24-hour time: ");
    //注意输入的时间格式取h和min时中间的冒号；scanf("%d%d",&hour,&min)写法能准确拿到小时，但是分钟取256,明显和时间不符合
    scanf("%d:%d", &hour, &min);
    total_min = hour * 60 + min;
    //计算输入日期处于21.45到8.00之间的中间时间进行对比
    middle_time = (2 * 60 + 15 + 8 * 60) / 2;
    if (total_min <= 8 * 60)
        total_min < middle_time ? printf(
                "Closest departure time is 9.45 p.m,arriving time at 11.58 p.m") : printf(
                "Closest departure time is 8.00 a.m,arriving time at 10.16 a.m");

    else if (total_min <= (9 * 60 + 43))
        (total_min - (8 * 60)) < ((9 * 60 + 43) - total_min) ? printf(
                "Closest departure time is 8.00 a.m,arriving time at 10.16 a.m")
                                                             : printf(
                "Closest departure time is 9.43 a.m,arriving time at 11.52 a.m");
    else if (total_min <= (11 * 60 + 19))
        (total_min - (9 * 60 + 43)) < ((11 * 60 + 19) - total_min) ? printf(
                "Closest departure time is 9.43 a.m,arriving time at 11.52 a.m")
                                                                   : printf(
                "Closest departure time is 11.19 a.m,arriving time at 1.31 p.m");
    else if (total_min <= (12 * 60 + 47))
        (total_min - (11 * 60 + 19)) < ((12 * 60 + 47) - total_min) ? printf(
                "Closest departure time is 11.19 a.m,arriving time at 1.31 p.m")
                                                                    : printf(
                "Closest departure time is 12.47 p.m,arriving time at 3.00 p.m");
    else if (total_min <= (14 * 60))
        (total_min - (12 * 60 + 47)) < ((14 * 60) - total_min) ? printf(
                "Closest departure time is 12.47 p.m,arriving time at 3.00 p.m")
                                                               : printf(
                "Closest departure time is 2.00 p.m,arriving time at 4.08 p.m");
    else if (total_min <= (15 * 60 + 45))
        (total_min - (14 * 60)) < ((15 * 60 + 45) - total_min) ? printf(
                "Closest departure time is 2.00 p.m,arriving time at 4.08 p.m")
                                                               : printf(
                "Closest departure time is 3.45 p.m,arriving time at 5.55 p.m");
    else if (total_min <= (19 * 60))
        (total_min - (15 * 60 + 45)) < ((19 * 60) - total_min) ? printf(
                "Closest departure time is 3.45 p.m,arriving time at 5.55 p.m")
                                                               : printf(
                "Closest departure time is 7.00 p.m,arriving time at 9.20 p.m");
        //这里的处理方式要注意：最开始是：21:45但是要结合第一if判断进行综合来看
    else if (total_min <= (23 * 60 + 60))
        (total_min - (19 * 60)) < ((23 * 60 + 60) - total_min) ? printf(
                "Closest departure time is 7.00 p.m,arriving time at 9.20 p.m")
                                                               : printf(
                "Closest departure time is 9.45 p.m,arriving time at 11.58 p.m");


}

/**
 * 编程练习8的第二种处理方式：此种写法更加有效，但是对于1:30,按理应该21.45的距离起飞最近的，但是这里却选择了早上8.00的
 * 要考虑时间过了半夜12点之后变为1点，但是程序选择要起飞时间与用户输入时间最接近的航班,已经进行优化了
 */
void exec5_8_2() {
    int user_time,
            hour,
            minute,
            d1 = 480,
            d2 = 583,
            d3 = 679,
            d4 = 767,
            d5 = 840,
            d6 = 945,
            d7 = 1140,
            d8 = 1305,
            middle_time = (2 * 60 + 15 + 8 * 60) / 2;

    printf("Enter a 24-hour: ");
    scanf("%d:%d", &hour, &minute);
    user_time = hour * 60 + minute;
    printf("Closest departure time is");
    //获取两个时间间隔中间数,多加一个判断条件，如果时间是1:30应该是选9.45起飞的水岸,如果3:00后时间就选择8:00起飞时间
    //也就是考虑从21:45到8：00之间相隔的时间是多少，取中间值，大于这个中间值的就要取8：00，小于的就要取21:45的
    //但是下面这种写法毕竟繁琐，具体优化方法还没有想到
    if (d1 - middle_time < user_time && user_time <= d1 + (d2 - d1) / 2)
        printf("8:00 a.m., arriving at 10:16 a.m.\n");
    else if (d1 - middle_time < user_time && user_time < d2 + (d3 - d2) / 2)
        printf("9:43 a.m., arriving at 11:52 a.m.\n");
    else if (d1 - middle_time < user_time && user_time < d3 + (d4 - d3) / 2)
        printf("11:19 a.m., arriving at 1:31 p.m.\n");
    else if (d1 - middle_time < user_time && user_time < d4 + (d5 - d4) / 2)
        printf("12:47 p.m., arriving at 3:00 p.m.\n");
    else if (d1 - middle_time < user_time && user_time < d5 + (d6 - d5) / 2)
        printf("2:00 p.m., arriving at 4:08 p.m.\n");
    else if (d1 - middle_time < user_time && user_time < d6 + (d7 - d6) / 2)
        printf("3:45 p.m., arriving at 5:55 p.m.\n");
    else if (d1 - middle_time < user_time && user_time < d7 + (d8 - d7) / 2)
        printf("7:00 p.m., arriving at 9:20 p.m.\n");
    else
        printf("9:45 p.m., arriving at 11:58 p.m.\n");


}

/**
 * 编写一个程序，提示用户输入两个日期，然后显示哪一个日期更早
 * Enter first date (mm/dd/yy):3/6/08
 * Enter second date (mm/dd/yy):/5/7/07
 * 5/17/07 is earlier than 3/6/07
 * 方法一：看错输入的日期格式：以为日/月/年
 */
void exec5_09() {
    int day_1, month_1, year_1, day_2, month_2, year_2;
    printf("Enter first date(mm/dd/yy): ");
    scanf("%d/%d/%d", &day_1, &month_1, &year_1);
    printf("Enter second date(mm/dd/yy): ");
    scanf("%d/%d/%d", &day_2, &month_2, &year_2);

    //先比较年、年相等表月，月相等再比较日
    if (year_1 < year_2)
        printf("%d/%d/%d  is earlier than %d/%d/%d\n", day_1, month_1, year_1, day_2, month_2, year_2);

    else if (year_1 == year_2) {
        if (month_1 < month_2)
            printf("%d/%d/%d  is earlier than %d/%d/%d\n", day_1, month_1, year_1, day_2, month_2, year_2);
        else if (month_1 == month_2) {
            if (day_1 < day_2)
                printf("%d/%d/%d  is earlier than %d/%d/%d\n", day_1, month_1, year_1, day_2, month_2, year_2);
            else if (day_2 == day_1)
                printf("%d/%d/%d  is equality %d/%d/%d\n", day_1, month_1, year_1, day_2, month_2, year_2);
            else
                printf("%d/%d/%d  is earlier than %d/%d/%d\n", day_2, month_2, year_2, day_1, month_1, year_1);

        } else
            printf("%d/%d/%d  is earlier than %d/%d/%d\n", day_2, month_2, year_2, day_1, month_1, year_1);

    } else
        printf("%d/%d/%d  is earlier than %d/%d/%d\n", day_2, month_2, year_2, day_1, month_1, year_1);
}

/**
 * 编写一个程序，提示用户输入两个日期，然后显示哪一个日期更早
 * Enter first date (mm/dd/yy):3/6/08
 * Enter second date (mm/dd/yy):/5/7/07
 * 5/17/07 is earlier than 3/6/07
 * 第二种实现方式:更加简介,要学会这样思考问题，深刻理解如何使用if选择语句
 */
void exec5_09_02() {
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

/**
 * 编程练习10:利用switch语句编写一个程序，把用数字表示的成绩转换为字母表示的等级
 * Enter numerical grade: 84
 * Letter grade: B
 *  Use the following grading scale: A = 90-100, B = 80-89, C = 70-79, D = 60-69,
    F = 0-59. Print an error message if the grade is larger than 100 or less than 0.
* Hint*: Break the grade into two digits, then use a `switch` statement to test
    the ten's digit.
    第一种写法是不严谨的，尤其default如果前面的条件都不符合的话，默认使用default的，会输出F
    尤其是输入的是超过100或者1的情况下
 */
void exec5_10() {
    int grade;
    printf("Enter numerical grade: ");
    scanf("%d", &grade);
    //判断是否大于100或者小于0，抛出错误异常提示
    if (grade < 0 || grade > 100)
        printf("Enter numerical grade  is error,Please enter number is 0-100\n");
    //要使用switch语句，把成绩拆分为两部分，然后使用switch语句判定十位上的数字
    printf("Letter grade: ");
    switch (grade / 10) {
        case 9:case 10:printf("A");break;
        case 8:printf("B");break;
        case 7:printf("C");break;
        case 6:printf("D");break;
        default:printf("F");break;
            //这种写法会出现如下输出

//            Enter numerical grade: 110
//            Enter numerical grade  is error,Please enter number is 0-100
//            Letter grade: F
//            Process finished with exit code 0


    }


}

/**
 *
 */
void exec5_10_2() {
    int grade;
    printf("Enter numerical grade: ");
    scanf("%d", &grade);
    if (grade > 100 || grade < 0)
        grade = -11;
    switch (grade / 10) {
        case 0: case 1:case 2:case 3: case 4: case 5:
            printf("Letter grade: F\n");break;
        case 6:
            printf("Letter grade: D\n");break;
        case 7:
            printf("Letter grade: C\n");break;
        case 8:
            printf("Letter grade: B\n");break;
        case 9:case 10:
            printf("Letter grade: A\n");break;
        default:
            printf("Enter numerical grade  is error,Please enter number is 0-100\n");
            break;

    }

}

/**
 * 编写一个程序，要求用户输入一个两位数，然后显示该数的英文单词:
 * Enter a two-digit number: 45
 * You entered the number forty-five.
 * 提示：把数分解位两个数字。用一个switch语句显示第一位数字对应的单词，用
 * 第二个switch语句显示第二位数字对应的单词，不要11-19需要特殊处理.
 */
void exec5_11(){
    int n;
    printf("Enter a two-digit number: ");
    scanf("%d", &n);

    switch (n / 10) {
        case 1:
            switch (n % 10) {
                case 0:
                    printf("You entered the number ten\n");
                    break;
                case 1:
                    printf("You entered the number eleven\n");
                    break;
                case 2:
                    printf("You entered the number twelve\n");
                    break;
                case 3:
                    printf("You entered the number thirteen\n");
                    break;
                case 4:
                    printf("You entered the number fourteen\n");
                    break;
                case 5:
                    printf("You entered the number fifteen\n");
                    break;
                case 6:
                    printf("You entered the number sixteen\n");
                    break;
                case 7:
                    printf("You entered the number seventeen\n");
                    break;
                case 8:
                    printf("You entered the number eighteen\n");
                    break;
                case 9:
                    printf("You entered the number nineteen\n");
                    break;
                default:
                    break;
            }
            break;
        case 2:
            printf("You entered the number twenty");
            break;
        case 3:
            printf("You entered the number thirty");
            break;
        case 4:
            printf("You entered the number forty");
            break;
        case 5:
            printf("You entered the number fifty");
            break;
        case 6:
            printf("You entered the number sixty");
            break;
        case 7:
            printf("You entered the number seventy");
            break;
        case 8:
            printf("You entered the number eighty");
            break;
        case 9:
            printf("You entered the number ninety");
            break;
        default:
            printf("Your number is out of range 10-99\n");
    }

    if (n / 10 != 1) {
        switch (n % 10) {
            case 0:
                printf("\n");
                break;
            case 1:
                printf("-one\n");
                break;
            case 2:
                printf("-two\n");
                break;
            case 3:
                printf("-three\n");
                break;
            case 4:
                printf("-four\n");
                break;
            case 5:
                printf("-five\n");
                break;
            case 6:
                printf("-six\n");
                break;
            case 7:
                printf("-seven\n");
                break;
            case 8:
                printf("-eight\n");
                break;
            case 9:
                printf("-nine\n");
                break;
            default:
                break;
        }
    }

}

//int main() {
//    // exec5_01();
//    //exec5_2();
//    // exec5_3();
//    //exec5_4();
//    //exec5_5();
//    //exec5_6();
//    // exec5_7();
//    // exec5_8_2();
//    //exec5_09_02();
//    //exec5_10();
//    //exec5_10_2();
////    exec5_11();
////    return 0;
//}

