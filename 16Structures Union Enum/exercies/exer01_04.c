/********************************************************************************
* @author: mason shi
* @date: 2023/8/13 22:00
* @version: 1.0
* @description: 课后练习题01-02
********************************************************************************/
#include<stdio.h>

void exec_01();
void exec_02();
void exec_03();
struct complex{
    double real,imaginary;
};

typedef struct {
    double real;
    double imaginary;
} Complex;

struct complex make_complex(double real,double imaginary);
struct complex add_complex(struct complex a,struct complex b);
Complex make_complex02(double real, double imaginary);
Complex add_complex02(Complex a, Complex b);
int main(void) {
    //exec_01();
    //exec_02();

    return 0;
}

/**
 * 课后练习题01:在下列声明中，结构x和结构y都拥有名为x和y的成员
 */
void exec_01() {
    struct {
        int x, y;
    } x;
    struct {
        int x, y;
    } y;
    //单独出现时，这两个声明是否合法？两个声明是否可以同时出现在程序中呢？验证你的答案。
    /*
     * 1.匿名结构声明： struct { int x, y; } 部分声明一个具有两个成员的匿名结构类型：x 和 y。
       2.变量的定义：x和y变量是根据匿名结构类型定义的。 每个变量都有自己的内存空间来存储 x 和 y 成员的值。
       3.范围和生命周期：这些结构变量的范围仅限于定义它们的块。 这意味着它们是局部变量，仅存在于声明它们的块中。
       但是，有一些重要的要点需要考虑：成员名称：虽然两个结构中的结构成员具有相同的名称（x 和 y），但它们是独立的
       并且不会引起任何冲突。 每个结构都有其自己独特的成员集。
       4.内存布局：虽然成员具有相同的名称，但它们属于匿名结构类型的不同实例。 这意味着在每个结构中为 x 和 y 单独分配内存。
       这些变量之间没有共享内存或链接。
       5.访问成员：访问成员时，可以使用点符号，例如 x.x 访问 x 结构的 x 成员，y.y 访问 y 结构的 y 成员。
       6.可读性和可维护性：使用具有相同成员名称的匿名结构可能会导致代码混乱。 如果需要定义具有相似成员的结构，
       通常最好使用命名结构类型。
       总之，这两种声明就个人而言都是合法的。 每个声明都定义了自己的结构变量及其自己的内存布局和范围。
       但是，使用此类具有相同成员名称的匿名结构可能会降低代码的可读性且难以维护，因此建议在实践中使用命名结构。
     * */

}

/**
 * 课后练习02
 */
void exec_02() {
    //a.声明名为c1、c2和c3的结构变量，每个结构变量都拥有double类型的成员real和imaginary.
    /* struct {
         double real,imaginary;
     }c1,c2,c3;*/

    //b.修改(a)中的声明，使c1的成员初始值为0.0和1.0，c2的初始值1.0和0.00（c3不初始化）
    struct {
        double real, imaginary;
    } c1 = {0.0, 1.0}, c2 = {1.0, 0.0}, c3;

    //c.编写语句把c2的成员复制给c1。这项操作可以在一条语句中完成，还是必须要两条语句？
    c1 = c2;
    printf("c1成员值：%f %f\n", c1.real, c1.imaginary);
    printf("c2成员值：%f %f\n", c2.real, c2.imaginary);
    //d.编写语句把c1和c2的对应成员相加，并且把结果存储到c3中。
    c3.real = c1.real + c2.real;
    c3.imaginary = c1.imaginary + c2.imaginary;
    printf("c3成员值：%f %f\n", c3.real, c3.imaginary);
}

/**
 * 课后练习题03——04
 */
void exec_03(){
    //a.说明如何为具有double类型的成员real和imaginary的结构声明名为complex的标记
    struct complex{
        double real,imaginary;
    };
    //b.利用标记complex来声明名为c1、c2和c3的变量。
    struct complex c1,c2,c3;
    //c.编写名为make_complex的函数，此函数用来把两个实际参数(类型都是double类型)存储在complex的结构中，然后返回
    //此结构,如下图函数所示
    //d.编写名为add_complex的函数，此函数用来把两个实际参数(都是complex结构)的对应的成员相加，然后返回结果(另一个complex结构)
    //使用结构类型的定义;
    typedef struct {
        double real;
        double imaginary;
    } Complex;
    Complex b1,b2,b3;

}
/**
 * 课后练习03:c题目
 * @param real
 * @param imaginary
 * @return
 */
struct complex make_complex(double real,double imaginary){
//    struct complex p;
//    p.real=real;
//    p.imaginary=imaginary;
//    return p;
    return (struct complex) {real, imaginary};//直接返回初始化的结果

}
Complex make_complex02(double real, double imaginary) {
    return (Complex) {real, imaginary};
}
/**
 *练习题03:d.编写名为add_complex的函数，此函数用来把两个实际参数(都是complex结构)的对应的成员相加，
 * 然后返回结果(另一个complex结构)
 * @return
 */
struct complex add_complex(struct complex a,struct complex b){
    return (struct complex){a.real+b.real,a.imaginary+b.imaginary};
}

Complex add_complex02(Complex a, Complex b) {
    return (Complex) {a.real + b.real, a.imaginary + b.imaginary};
}