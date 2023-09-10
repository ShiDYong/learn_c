/**
Created by mason on 2023/5/2.
 第五章：选择语句
 根据对语句的执行顺序的影响,C语言的语句基本属于一下三类：
 1.选择语句：if语句和switch语句允许程序在一组可选项中选择一条特定的执行路径；
 2.重复语句：while语句、do语句和for语句支持重复(循环)操作；
 3.跳转语句：break语句、continue语句和goto语句导致无条件的跳转到程序中的某个位置(return语句也属于此类)
*/
#include<stdio.h>

/**
 * 计算股票经纪人的佣金案例如表5.4所示
 * 最低收费是39美元，下面的程序要求用户输入交易额，然后显示出佣金的数额：
 * Enter value of trade: 30000
 * Commission: $166.00
 */
void calculate_broker_commission() {
    float trade, commission;
    printf("Enter value of trade: ");
    scanf("%f", &trade);
    //注意是浮点数要保留2位,同时要注意表中的1.7%、0.66%转化为小数点时不要出错
    if (trade < 2500.00f)
        commission = 30.00f + trade * 0.017f;
        /* else if(trade >= 2500.00f && trade < 6250.00f)
             commission = 56.00f + trade * 0.0066f;
             注意上这种写法是多余的。如果第一个if字句的trade的值小于2500则计算佣金，
             当到达第二个if测试时，trade不可能小于2500，因此一定大于2500，条件trade>=
             2500.00f总是为真，因此加上这个条件是没有意义的,
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
    printf("Commission is:$%.2f\n", commission);

}

/**
 * 显示法定格式的日期：应为合同和其他法律文档中经常使用下列日期格式：
 * Dated this_day of_,20.
 * 下面编写程序，用这种格式来显示英文日期。用户以月/日/年的格式输入日期，然后计算机
 * 显示出“法定”格式的日期：
 * Enter date (mm/dd/yy):7/19/14
 * Dated this 19th of July,2014
 */
void converter_date() {
    int month, day, year;
    printf("Enter date (mm/dd/yy): ");
    scanf("%d /%d /%d", &month, &day, &year);
    //注意如何通过多个printf函数把结果拼接起来的
    printf("Dated of this %d", day);
    /**
     * 如何为日添加"th"或者"st"、”nd“、"rd",以及如何用单词而不是数字显示月份呢？
     * 我们通过一个switch语句显示日期的后缀，再用另一个switch语句显示月份名。
     */
    switch (day) {
        //控制表达式：switch后边必须跟着由圆括号括起来的整型表达式。C语言把字符当成整数来处理
        //因此在switch语句中对字符进行判定，但是这不适用于浮点数和字符串。
        case 1:case 21:case 31:  //分枝标号：case 常量表达式：不能包含变量和函数调用,5是常量，但是n+5就不是常量
            printf("st");        //分枝标号中常量表达式的值必须是整数(字符也可以的)
            break;
        case 2:case 22:   //C语言不允许有重复的分支标号，但对分支的顺序没有要求，特别是default分支不一定要放在最后
            printf("nd");
            break;
        case 3:case 33:  //case后边只可以跟随一个常量表达式，但是多个分支标号可以放置在同一组语句的前面，方便节省空间
            printf("rd");
            break;
        default:  //switch分支不要求一定有default分支，如果default不存在，而且表达式的值和任何一个分支标号都不匹配的话
            printf("th");  //控制会直接传给switch语句后面的语句
            break;
    }
    printf(" day of ");
    switch (month) {
        case 1:
            printf("January");
            break;
        case 2:
            printf("February");
            break;
        case 3:
            printf("March");
            break;
        case 4:
            printf("April");
            break;
        case 5:
            printf("May");
            break;
        case 6:
            printf("June");
            break;
        case 7:
            printf("July");
            break;
        case 8:
            printf("August");
            break;
        case 9:
            printf("September");
            break;
        case 10:
            printf("October");
            break;
        case 11:
            printf("November");
            break;
        case 12:
            printf("December");
            break;

    }
    //%.2d用于显示年份的最后两位数字。如果用%d代替的化，那么倒数第二位为零的年份会显示不正确.
    printf(", 20%.2d.\n",year);
}

//int main() {
//    //calculate_broker_commission();
//    converter_date();
//    return 0;
//}
