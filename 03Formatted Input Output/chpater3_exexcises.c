/**
Created by mason on 2023/4/31.
 第三章：C语言的格式化输入/输出课后编程题
*/

#include <stdio.h>

/**
 * 练习1:编写一个程序，以月/日/年(mm/dd/yy)的格式接受用户输入的日志信息，并以年月日(yyyymmdd)的格式展示出来
 */
void exec3_1() {
    int year, month, day;
    printf("Please enter a date(mm/dd/yyyy): ");
    //获取用户的输入，如何处理格式是mm/dd/yy
    // scanf("%d%d%d", &month, &day, &year);获取不到/后面的数据了
    scanf("%d/%d/%d", &month, &day, &year);//和下面的效果是一样的，因为scanf函数自动去除空白字符
    //scanf("%d /%d /%d", &month, &day, &year);
    //这里如何让输出格式是：20221231呢，最开始方式是有问题的
    printf("Your enter the date is:%d%d%d\n", year, month, day);
    //第二种写法更准确：以十进制形式显示变量i，并至少有4位数字符合年的写法，同理月、日写法也是一样的
    printf("Your enter the date is: %0.4d%0.2d%0.2d\n", year, month, day);

}

/**
 * 练习2:编写一个程序，对用户输入的产品信息进行格式化，其中产品编号和日期项采用左对齐方式，单位价格
 * 采用右对齐方式，允许美元金额最大取值9999.99。提示：各个列使用制表符控制
 */
void exec3_2() {
    int item, year, month, day;
    float unit_price;
    printf("Enter number: ");
    scanf("%d", &item);
    printf("Enter unit price: ");
    scanf("%f", &unit_price);
    printf("Enter purchase date(mm/dd/yyyy): ");
    scanf("%d/%d/%d", &month, &day, &year);
    //如何输出来？思路应该是要打印成2行数据，第一行展示字段，第二行展示字段内容，第一次处理方式是错误的
    //printf("Item\tUnit\nPrice\tPurchase\nDate\t",item,unit_price,month,day,year);
    printf("Item\t\tUnit\t\tPurchase\n\t\tPrice\t\tDate\n");
    printf("%d\t\t$%8.2f\t%.2d/%.2d/%.4d\n", item, unit_price, month, day, year);


}

/**
 * 练习3:输入一个国际图书标准编号(ISBN)进行识别并输出来
 */
void exec3_3() {
    int GSI_prefix, group_identifier, publisher_code, item_number, check_digit;
    printf("Enter ISBN: ");
    scanf("%d-%d-%d-%d-%d", &GSI_prefix, &group_identifier, &publisher_code, &item_number, &check_digit);
    //按照要求进行格式输出
    printf("GSI prefix:%d\nGroup identifier:%d\n", GSI_prefix, group_identifier);
    printf("Publisher code:%d\nItem number:%d\nCheck digit:%d\n", publisher_code, item_number, check_digit);

}

/**
 * 练习4:编写一个程序，提示用户以(xxx)xxx-xxxx的格式输入电话号码，并以xxx.xxx.xxxx的格式显示该号码
 *
 */
void exec3_4() {
    int first, second, last;
    printf("Enter phone number [(xxx) xxx-xxxx]: ");
    scanf("(%d) %d-%d", &first, &second, &last);
    printf("Your enter is:%0.3d.%0.3d.%0.4d\n",first,second,last);
}

/**
 * 编程练习5:编写一个程序，要求用户输入(按照任意次序)输入1～16的所有整数，然后用4*4的矩阵的形式将它们显示出来
 * ，再计算出每行、每列和每条对角线上的和
 */
void exec3_5(){
    //此题目后面再写

}

/**
 * 编程练习6:修改3.2节的addfrac.c程序，使使用可以同时输入两个分数，中间用加号隔开；
 */
void exec3_6(){
    int num1,demon1,num2,demon2,result_num,result_demon;
    printf("Enter two fractions separated by a plus sign: ");
    //这里加不加+都是可以的
    scanf("%d/%d+%d/%d",&num1,&demon1,&num2,&demon2);
    result_num = num1 * demon2+ num2*demon1;
    result_demon = demon1 * demon2;
    printf("The sum is: %d/%d",result_num,result_demon);
}

//int main() {
//    //exec3_1();
//    //exec3_2();
//   // exec3_3();
//  // exec3_4();
//  exec3_6();
//    return 0;
//}
