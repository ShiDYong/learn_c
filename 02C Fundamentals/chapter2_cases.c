#include <stdio.h>

#define INCHES_PER_POUND 166
#define FREEZING_PT 32.0f
#define SCALE_FACTOR (5.0f / 9.0f)

/*
 Created by mason on 2023/4/29.
 实例01:计算箱子的空间重量的案例：在C语言中，如果两个整数相除，那么结果会被“截短“：
 小数点后的所有数字都会丢失。12英寸*10英寸*8英寸的箱子体积是960立方英寸，960立方英尺处以166
 的结果是5而不是5.783，这样使得重量向下取舍，运输公司则希望是向上向上舍入。一种解决方案是在除以166之前把
 体积数加上165
*/

void dwight_1(void) {
    int weight, length, width, height, volume;
    height = 8;
    width = 10;
    length = 12;
    volume = height * length * width;
    weight = (volume + 165) / 166;
    printf("Dimensions: %dx%dx%d\n", length, width, height);
    printf("Volume (cubic inches): %d\n", volume);
    printf("Dimensions: weight (pounds):%d\n", weight);
}

/*
 案例1的优化：在计算计算箱子的空间重量的基础增加支持用户手动输入和
 使用宏定义的特性给常量命名：方便提升代码的可读性
 但是该程序存在的问题如果用户输入的不是数值，程序就会报错
*/

void dwight_2(void) {
    int weight, height, width, length, volume;
    //支持用户手动输入箱子的长、宽、高
    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter width of box: ");
    scanf("%d", &width);
    printf("Enter length of box: ");
    scanf("%d", &length);
    volume = height * width * length;

    weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
    printf("Volume (cubic inches):%d\n", volume);
    printf("Dimensional weight (pounds):%d\n", weight);

}

/*
 Created by mason on 2023/4/29.
 华氏温度转换摄氏度案例:变量使用浮点数
*/
void celsius(void) {
    float fahrenheit, celsius;
    printf("Please Enter fahrenheit temperature: ");
    scanf("%f", &fahrenheit);
    celsius = (fahrenheit - FREEZING_PT) * SCALE_FACTOR;
    printf("Celsius equivalent: %.1f\n", celsius);

}


int main() {
    printf("To C,or not to C: that the question\n");
    dwight_1();
    dwight_2();
    celsius();
    return 0;
}
