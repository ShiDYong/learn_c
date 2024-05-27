/**
Created by mason on 2023/5/4.
 第五章：选择语句课后编程题
 */
#include<stdio.h>
#include <stdlib.h>

/**
 Project 5.01
Write a program that calculates how many digits a number contains:
Enter a number: 374
The number 374 has 3 digits
You many assume that the number has no more than four digits. *Hint*: Use `if`
statements to test the number. For example, if the number is between 0 and 9, it
has one digit. If the number is between 10 and 99, it has two digits.

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
    else d = 4;
    printf("The number %d has %d digits\n", n, d);

}

/*
 * 优化以上算法，不限制输入的数字位数，更加通用
 * Function to calculate the number of digits in a number
 */
int countDigits(int number) {
    //Initialize count to 1 for numbers with at least one digit
    int count = 1;
    //Handle negative numbers
    if (number < 0) {
        number = -number;
    }
    //Count digits using a loop
    //use a do-while loop to count the digits by repeatedly dividing the number by 10 until it becomes 0.
    while (number >= 10) {
        number /= 10;
        count++;
    }

    return count;


}

/*
 * 调用上述函数
 */
void callCountDigits() {
    int number;
    int result;
    printf("Enter a number: ");
    result = scanf("%d", &number);
    //Read the input and check if it's a number
    if (result != 1) {// If it's not 1, it means the input was not successfully read as an integer.
        printf("Please enter a valid number.\n");
        //Clear input buffer
        while ((result = getchar()) != '\n' && result != EOF);
        //Exit the program
        exit(EXIT_FAILURE);
    }
    //调用计算位数的函数
    int digits = countDigits(number);
    printf("The number %d has %d digit(s)\n", number, digits);
}

/**
    Project 5.02
    Write a program that asks the user for a 24-hour time, then displays the time in
    12-hour form:
    Enter a 24-hour time: 21:11
    Equivalent 12-hour time: 9:11 PM
    Be careful not to display 12:00 as 0:0
 *
 */
void exec5_2() {
    int hour = 0, minute = 0;
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

/*
 * 跟上面相反的方式进行判断，其效果一样的
 */
void exec5_2_02() {
    int hour, min;
    printf("Enter a 24-hour time: ");
    scanf("%d:%d", &hour, &min);
    if (hour > 12 && hour <= 48)
        printf("Equivalent 12-hour time: %d:%02d PM", hour % 12, min);
    else
        printf("Equivalent 12-hour time: %d02%d AM", hour, min);

}

/*
 * 进一步优化上面的方法，使其更具有通用性
 * 以及充分考虑各种异常情况的出现
 * Function to convert 24-hour time to 12-hour time
 * Returns the equivalent 12-hour time as a String
 * If an error occur, return NULL
 */
char *convertTo12HourFormat(int hour, int minute) {
    //Validate hour and minute value
    if (hour < 0 || hour > 23 || minute < 0 || minute > 59) {
        return NULL;
    }
    //Allocate memory for result String
    char *result = (char *) malloc(sizeof(char) * 9);
    //至于为什么上面为何如此处理：
    //结果字符串的格式： 等效的 12 小时时间字符串的格式为“00:00 AM\0”。 它由 8 个字符组成，表示时间部分 (hh:mm) 和 AM/PM 名称，以及一个用于表示字符串结尾的空终止符 (\0) 的附加字符。
    //内存分配：当使用malloc动态分配内存时，我们需要指定要分配的总字节数。 C 字符串中的每个字符占用一个字节的内存。 因此，为了容纳时间字符串和空终止符的 8 个字符，我们需要 8 + 1 = 9 字节的内存。
    //动态分配：行 char* result = (char*)malloc(sizeof(char) * 9); 在堆上动态分配内存来存储结果字符串。 malloc 函数将要分配的总字节数作为其参数，
    // 计算公式为 sizeof(char) * 9。强制转换 (char*) 用于指示 malloc 返回的内存指针应解释为指向 一个人物。
    //sizeof(char) 的用法：在 C 语言中，语言规范保证 sizeof(char) 为 1。 但是，在分配语句中显式包含 sizeof(char)
    // 有助于使代码更加明确和可维护，特别是在数据类型将来发生变化的情况下。
    //因此， char* 结果 = (char*)malloc(sizeof(char) * 9); 为可保存等效 12 小时时间的字符串分配内存，格式为“00:00 AM\0”。
    if (result == NULL) {
        return NULL; //Memory allocation failed
    }

    //Convert to 12-hour format,这里需要特别注意下：
    //约定：在 12 小时时间约定中，午夜通常表示为 12:00 AM。 这一惯例被熟悉 12 小时格式阅读时间的人们广泛接受和理解。
    //一致性：当小时为 0 时，通过将 conversionHour 设置为 12 并将后缀设置为“AM”，代码可确保与午夜的常规表示形式保持一致。 这使得输出更加直观并且更容易为用户所理解。
    //可读性：代码明确指出将午夜表示为 12:00 AM，让阅读代码的任何人都清楚预期的行为是什么。
    //因此，通过在小时为 0 时将 conversionHour 设置为 12 并将后缀设置为“AM”，代码可以正确遵循以 12 小时时间格式表示午夜的约定。
    int convertedHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
    char *suffix = (hour >= 12) ? "PM" : "AM";
    //Format the result string
    sprintf(result, "%02d:%02d %s", convertedHour, minute, suffix);
    //为什么这里使用sprintf函数的原因：
    //字符串格式化：sprintf 函数允许我们使用各种占位符（格式说明符）（例如 %d、%s、%f 等）格式化字符串，并用相应的值填充这些占位符。
    // 在本例中，格式字符串“%02d:%02d %s”指定时间字符串的格式，其中两位数字表示小时和分钟（如有必要，用前导零填充），后跟空格和 AM/PM 后缀。
    //动态字符串创建：使用 sprintf，我们可以根据提供的格式和值动态创建字符串。 当我们需要以编程方式构造字符串时，例如生成用于显示或存储的格式化输出时，这特别有用。
    //用前导零填充：%02d 格式说明符可确保小时和分钟值小于 10 时使用前导零进行格式化。这可确保格式一致并提高结果时间字符串的可读性。
    //连接不同类型：sprintf 允许我们将不同类型的数据（整数、字符串等）连接成单个字符串。 在本例中，我们将整数（convertedHour 和 分钟）和字符串（后缀）组合到结果字符串中。
    //避免缓冲区溢出：sprintf 自动处理目标缓冲区（结果数组）的大小，并确保格式化字符串适合缓冲区的边界。 这有助于防止使用 strcpy 或 strcat 等不安全的字符串操作函数时可能发生的缓冲区溢出漏洞。
    //总体而言，在此上下文中使用 sprintf 提供了一种方便且安全的方法，可以通过适当的填充和连接来格式化等效的 12 小时时间字符串，从而生成更清晰、更易读的代码。
    return result;

}

char callConvertTo12HourFormat() {
    int hour, minute;
    int result;
    printf("Enter a 24-hour time (hh:mm): ");
    //Read the input
    result = scanf("%d:%d", &hour, &minute);
    //用于检查输入是否包含非数字字符或两个以上的整数。 如果任一条件
    if (result != 2 || getchar() != '\n') {
        printf("Invalid input format. Please enter time in format hh:mm.\n");
        return EXIT_FAILURE;
    }
    //Convert to 12-hour format
    char *convertedTime = convertTo12HourFormat(hour, minute);
    if (convertedTime == NULL) {
        printf("Invalid time. Hour must be between 0 and 23, and minute must be between 0 and 59.\n");
        return EXIT_FAILURE;
    }

    printf("Equivalent 12-hour time: %s\n", convertedTime);

    //Free memory allocated for result
    free(convertedTime);
    return EXIT_SUCCESS;

}


/**
 Project 5.03
Modify the `broker.c` program of Section 5.2 by making both of the following
changes:
    (a) Ask the user to enter the number of shares and the price per share, instead
    of the value of the trade.
    (b) Add statements that compute the commission charged by a rival broker ($33
    plus 3 cents per share fewer than 2000 shares; $33 plus 2 cents per share for
    2000 shares or more). Display the rival's commission as well as the commission
    charged by the original broker.
 *
 *
 */

void exec5_3() {
    int num_shares;
    float price_per_share, value_of_trade, commission, rival_commission;

    // Ask the user to enter the number of shares and the price per share
    printf("Enter number of shares: ");
    scanf("%d", &num_shares);
    printf("Enter price per share: ");
    scanf("%f", &price_per_share);

    // Calculate the value of the trade
    value_of_trade = num_shares * price_per_share;

    // Calculate commission charged by the original broker
    if (value_of_trade < 2500.00f)
        commission = 30.00f + value_of_trade * 0.017f;
    else if (value_of_trade < 6250.00f)
        commission = 56.00f + value_of_trade * 0.0066f;
    else if (value_of_trade < 20000.00f)
        commission = 76.00f + value_of_trade * 0.0034f;
    else if (value_of_trade < 50000.00f)
        commission = 100.00f + value_of_trade * 0.0022f;
    else if (value_of_trade < 500000.00f)
        commission = 155.00f + value_of_trade * 0.0011f;
    else
        commission = 255.00f + value_of_trade * 0.0009f;

    if (commission < 39.00f)
        commission = 39.00f;

    // Calculate commission charged by a rival broker
    if (num_shares < 2000)
        rival_commission = 33.00f + num_shares * 0.03f;
    else
        rival_commission = 33.00f + num_shares * 0.02f;

    printf("Original Broker's Commission: $%.2f\n", commission);
    printf("Rival Broker's Commission: $%.2f\n", rival_commission);


}

/**
 Project 5.04
Here's a simplified version of the Beaufort scale, which is used to estimate
    wind force:
        | Speed (knots) | Description
        | --- | --- |
        | Less than 1 | Calm |
        | 1-3 | Light air |
        | 4-27 | Breeze |
        | 28-47 | Gale |
        | 48-63 | Storm |
        | Above 63 | Hurricane |
Write a program that asks the user to enter a wind speed (in knots), then
displays the corresponding description.
 */
void exec5_4() {
    float speed;
    printf("Enter wind of speed (n mile/hour): ");
    scanf("%f", &speed);
    printf("Wind description: ");

    if (speed < 1.0f)
        printf("Calm\n");
    else if (speed <= 3.0f)
        printf("Light air\n");
    else if (speed <= 27.0f)
        printf("Breeze\n");
    else if (speed <= 47.0f)
        printf("Gale\n");
    else if (speed <= 63.0f)
        printf("Storm\n");
    else
        printf("Hurricane\n");
}

/**
Project 5.05
In one state, single residents are subject to the following income tax:

| Income        | Amount of tax |                               |
| ------------- | ------------- | ----------------------------- |
| Not over $750 | 1% of income  |
| $750-$2,250   | $7.50         | plus 2% of amount over $750   |
| $2,250-$3,750 | $37.50        | plus 3% of amount over $2,250 |
| $3,750-$5,250 | $82.50        | plus 4% of amount over $3,750 |
| $5,250-$7,000 | $142.50       | plus 5% of amount over $5,250 |
| Over $7,000   | $230.00       | plus 6% of amount over $7,000 |

Write a program that asks the user to enter the amount of taxable income, then
displays the tax due.

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
 * 编程题5.06:修改4.1节的upc.c程序，使其可以检测CPC的有效性。在用户输入UPC后，程序将显示VALID或者NOT VALID.
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
 Project 5.07
Write a program that finds the largest and smallest of four integers entered by
the user:
Enter four integers: 21 42 10 35
Largest: 43
Smallest: 10
Use as few `if` statements as possible: *Hint*: Four `if` statements are
sufficient.

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
        case 9:
        case 10:
            printf("A");
            break;
        case 8:
            printf("B");
            break;
        case 7:
            printf("C");
            break;
        case 6:
            printf("D");
            break;
        default:
            printf("F");
            break;
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
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
            printf("Letter grade: F\n");
            break;
        case 6:
            printf("Letter grade: D\n");
            break;
        case 7:
            printf("Letter grade: C\n");
            break;
        case 8:
            printf("Letter grade: B\n");
            break;
        case 9:
        case 10:
            printf("Letter grade: A\n");
            break;
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
void exec5_11() {
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
//    exec5_01();
//    课后编程练习05_01的优化
//     callCountDigits();
//     exec5_2();
//    callConvertTo12HourFormat();
//
//    exec5_2();
//     exec5_3();
//    exec5_4();
//    exec5_5();
//    exec5_6();
//     exec5_7();
//     exec5_8_2();
//    exec5_09_02();
//    exec5_10();
//    exec5_10_2();
//    exec5_11();
//    return 0;
//}

