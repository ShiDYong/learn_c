#include <stdio.h>
#include <math.h>
#include<stdarg.h>

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

int dwight_1(void) {
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

int dwight_2(void) {
    int weight, height, width, length, volume;
    //支持用户手动输入箱子的长、宽、高
    printf("Enter height of box: ");
    scanf("%d", &height);
    printf("Enter width of box: ");
    scanf("%d", &width);
    printf("Enter length of box: ");
    scanf("%d", &length);
    volume = height * width * length;

    //通过宏定义方便进行修改
    weight = (volume + INCHES_PER_POUND - 1) / INCHES_PER_POUND;
    printf("Volume (cubic inches):%d\n", volume);
    printf("Dimensional weight (pounds):%d\n", weight);

}

/**
 * 通过C标准库库<math.h>中的float()和ceil()函数来实现
 */
int dwight_3() {
    double weight, height, width, length, volume, constant;
    //支持用户手动输入箱子的长、宽、高
    printf("Enter height of box: ");

    // scanf("%f", &height);
    //scanf函数中使用了错误的格式说明符。scanf函数中用于读取double类型变量的格式说明符应该是%lf而不是%f，
    // 因为%f用于float类型，所以上面的写法是错误的！！！
    scanf("%lf", &height);
    printf("Enter width of box: ");
    scanf("%lf", &width);
    printf("Enter length of box: ");
    scanf("%lf", &length);
    printf("Enter length of constant: ");
    scanf("%lf", &constant);

    volume = height * width * length;
    weight = ceil(volume / constant);
    double floor_weight = floor(volume / constant);//在C语言中，如果两个整数相除，那么结果会被“截短“
    //上面使用向上取整的函数，还是无法实现，因为height、width、length都是int类型
    //因此要使用标准库中的向上和向下取整需要改变变量的类型为double，但是在C语言中
    //由于volume和constant都是double类型，而且在C语言中整数相除的结果不会被截断，
    // 因此不需要对volume / constant进行向上取整操作,除非结果要求为整数
    // 此外，将double类型赋值给int类型会导致精度丢失，应该使用double类型来存储重量。
    weight = volume / constant; //结果不要求为整数
    /*
     * 声明的类型是double而打印的写成的类型是int:
     printf("Dimensions: %dx%dx%d\n", length, width, length);
     printf("Volume (cubic inches): %d\n", volume);
     printf("Dimensions weight (pounds): %d\n", weight);
     造成的结果输出如下：
     * Dimensions: 0x0x0
      (cubic inches): 0
      Dimensions weight (pounds): 0
      所以：在打印体积和重量时，使用了%d作为格式说明符，但是volume和weight是double类型的变量，应该使用%lf作为格式说明符
     * */
    printf("Dimensions: %.2lfx%lfx%lf\n", length, width, length);
    printf("Volume (cubic inches): %.2lf\n", volume);
    printf("Dimensions weight (pounds): %.2lf\n", weight);
    printf("Dimensions floor_weight (pounds): %.2lf\n", floor_weight);
    return weight;


}

/*
 * 定制向下取整函数
 */
static int floor_custom(double x) {
    if (x >= 0) {
        return (int) x; // 正数的向下取整就是舍去小数部分
    } else {
        return (int) (x - 0.9999999999); // 这里使用一个很接近1的小数来确保向下取整
    }

}

/*
 * 定制向上取整函数
 */
static int ceil_custom(double x) {
    if (x >= 0) {
        //在C语言中，如果两个整数相除，结果会被截断为整数部分，即舍弃小数部分。
        // 这种行为被称为整数除法。例如，如果你执行 5 / 2，结果将会是 2 而不是 2.5。
        //这种行为符合C语言标准中的整数除法规则。要想获得精确的浮点数除法结果，
        // 你需要将操作数转换为浮点数类型再进行除法运算。例如，5.0 / 2.0 的结果将会是 2.5。
        return (int) (x + 0.9999999999); // 这里使用一个很接近1的小数来确保向上取整
    } else {
        //需要注意的是，由于浮点数在计算机中的表示方式和处理方法，直接将浮点数转换为整数可能会导致一些精度问题。
        // 在这个示例中，我们为了尽可能减少这种精度问题，对正数和负数情况分别做了处理。
        return (int) x; //负数的向上取整就是舍弃小数部分
    }

}


/*
 * 重新编写一个向上和向下取整的函数
 * 将传入的长宽高类型为double这样比较符合实际
 */
int dwight_4(int num, ...) {

    //double volume = 0.00f;
    // 初始化为1.0，而不是0.00f
    if (num <= 0) {
        //参数num必须大于0
        return -1;//返回一个特殊值表示错误
    }
    va_list args; // 定义一个va_list类型的变量，用于访问可变参数列表
    double volume = 1.0;
    va_start(args, num); //初始化args, 将args指向可变参数列表的第一个参数
    for (int i = 0; i < num; ++i) {
        double value = va_arg(args, double); // 从args中依次读取参数，并将参数累相乘放到volume中
        volume *= value;
    }
    va_end(args);//结束对args的使用;
    //直接调用自写的向上取整函数
    return ceil_custom(volume / INCHES_PER_POUND);


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

/**
 * C语言中的可变参数
 * @param num
 * @param ...
 * @return
 */
double product(int num, ...) {
    double result = 1.0;
    va_list args;
    va_start(args, num);

    for (int i = 0; i < num; ++i) {
        double value = va_arg(args, double);
        result *= value;
    }

    va_end(args);
    return result;
}

//int main() {
//    printf("To C,or not to C: that the question\n");
//   dwight_1();
//    dwight_2();
//   dwight_3();
// celsius();
    //调用dwight_4计算箱子的实际体积
   // printf("Dimensional weight (pounds): %d\n", );
//    dwight_4(3, 2.0, 3.5, 4.5);
//    printf("Product: %.2lf\n", product(3, 2.0, 3.5, 4.5)); // 2.0 * 3.5 * 4.5 = 31.50
//    printf("Product: %.2lf\n", product(5, 1.0, 2.0, 3.0, 4.0, 5.0)); // 1.0 *
//    return 0;
//}
