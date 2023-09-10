/********************************************************************************
* @author: mason shi
* @date: 2023/8/12 14:26
* @version: 1.0
* @description: 第十六章结构、联合和枚举课堂练习
********************************************************************************/
#include<stdio.h>
#include <string.h>

#define NAME_LEN 25
//声明为结构为外部变量
struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
};

struct part build_part(int number, const char *name, int on_hand);

void struct_case1();

void struct_case2();

void struct_array_struct();

void print_part(struct part p);

/**
 * 本章介绍新的类型：结构、联合和枚举。结构是肯能具有不同类型的值(成员的集合),联合和结构很类似，不同之处在于联合的成员共享统一
 *          存储空间。联合可以每次存储一个成员，但是无法同时存储全部成员。枚举是一种整数类型，它的值由程序员来命名。
 * @return
 */
int main(void) {
    //struct_case1();
    struct part part3 = {528, "Disk drive", 100};
    print_part(part3);
    struct part part1 = build_part(119, "Hello World!", 120);
    print_part(part1);
    return 0;

}

/**
 * 结构变量的声明以及基本操作
 * 结构与数组这两种数据结构的区别：
 * 1.数组的所有的元素具有相同的类型；为了选择数组元素需要指明元素的位置(作为整数的下标);
 * 2.结构的元素(在C语言中的说法是结构的成员)可能具有不同的类型。而且，每个结构成员都有名字，因为为了选择特定的结构成员需要指明
 *   结构成员的名字而不是它的位置
 */
void struct_case1() {
    /*16.1.1结构变量的声明
     * 以下记录存储在仓库中的零件使用的声明的结构
     * 结构的成员在内存中是按照声明的顺序存储的。为了声明part1在内存中存储的形式。现在假设：
     * 1.part1存储地址在2000的内存单元中；
     * 2.每个整数在内存中占4字节；
     * 3.NAME_LEN的值为25；
     * 4.成员之间没有间隙
     * */
    struct {
        int number;  //零件的编号
        char name[NAME_LEN + 1];//零件的名称
        int on_hand; //现有数量
    } part1, part2;  //具有这种类型的变量

    /*每个结构代表新的作用域。任何声明在此作用域内的名字都不会和其他程序中的其他名字冲突。每个结构都为它的成员设置了独立的名字空间
     * 所有part1、part2中的成员的number和name不会与结构employee1和employee2中的成员number和成员name冲突.
     * */
    struct {
        char name[NAME_LEN + 1];
        int number;
        char sex;
    } employee1, employee2;


    /*
     * 16.1.2结构变量的初始化
     * 和数组一样，结构变量也可以在声明的同时进行初始化。为了对结构进行初始化，要把待存储到结构中的值的列表准备好，并
     * 用花括号把它括起来；初始化器的值必须按照结构成员的顺序来显示；
     * 初始化器的表达式必须是常量。初始化器的成员数可以少于它所初始化的结构，就像数组那样，任何剩余的成员都用0作为他的初始值。
     * 特别地，剩余的字符数组中的字节数为0，标识空字符串。
     * */
    struct {
        int number;
        char name[NAME_LEN + 1];
        int on_hand;
    } part3 = {525, "Disk drive", 10},
            part4 = {545, "Disk drive", 18},
            part5 = {543, "Disk drive"};//任何剩余的成员都用0作为他的初始值
    /*16.1.3指示器
     * 指示器与之类似，但是在初始化时需要按成员的名字来指定初值
     * 优点：
     * 1.易读且容易进行验证，这是因为读者可以清楚地看出结构中的成员和初始化器中的值之间的对应关系。
     * 2.初始化器中的值顺序不需要与结构中成员的顺序一致。
     * */
    struct {
        int number;
        char name[NAME_LEN + 1];
        int on_hand;
    } part6 = {.on_hand=10, .name="Disk drive", .number=123};//点号和成员名称的组合也是指示器(数组元素的指示器在形式上有所不同)

    /*16.1.4:对结构的操作
     * 数组操作是取下标(根据位置选择数组元素),那么结构操作是选择成员，但是结构是通过名字而不是通过位置访问的。
     *
     * */
    // 1.为了访问结构内的成员，首先写出结构的名字，然后写一个句点，再写出成员的名字；
    printf("Part number: %d\n", part3.number);
    printf("Part name: %s\n", part3.name);
    printf("Quantity on hand: %d\n", part3.on_hand);

    //2.结构的成员是左值，所以它们可以出现在赋值运算的左侧，也可以作为自增或自减表达式的操作符
    part1.number = 258;/*changes part1's part number */
    part1.on_hand++;/*increments part1's quantity on hand*/

    //3.用于访问结构成员的句点实际上就是一个C语言的运算符。它的运算优先级与后缀++和后缀--运算符一样，所以
    //句点运算符的优先级几乎高于所有其他运算符
    scanf("%d", &part3.on_hand);//.运算符的优先级高于&运算符，所以&计算的是part1.on_hand的地址

    //4.结构的另一种赋值运算，整个结构的值赋值
    part4 = part3;//就是把part3.number复制到part4.number,把part3.name复制到part4.name，以此类推
    // part1=part3;这样会报错，虽然结构都是一样的，但是在程序中的不同位置声明变量根据c语言的规则part1和part3不具有兼容性
    //因此不能part3的值赋给part1。
    //数组是不能用=运算符进行复制，但是结构可用运算符复制；除此之外，对结构进行复制时，嵌套在结构内的数组也被复制。
    //可以利用这种特性来产生空结构，以封装稍后将进行复制的数组,但是不能使用==和!=来判定两个结构相关还时不等。
    struct {
        int a[10];
    } a1, a2;
    a1 = a2;/*legal, since a1 and a2 are structures*/


}

/**
 *结构类型：为了解决结构在程序中的不同呢位置声明变量，导致part1和part3不具有兼容性，
 * 所以需要定义结构类型(而不是特定的结构变量)的名字。对此C语言提供了两种命名方式：可以声明“结构标记”,
 * 也可以使用typedef来定义类型名(类型定义)
 */
void struct_case2() {
    /*16.2.1:结构标记的声明
     *
     * 结构标记：是用于标识某种特定结构的名字,如下创建的标记：part*/
    struct part {
        int number;
        char name[NAME_LEN + 1];
        int on_hand;
    }; //右花括号后的分号是必不可少的，它表示声明的结束，如果忽略结构结尾的分号，会导致奇怪的错误。
    //1.一旦创建了标记part，就可以用它来声明变量了：
    struct part part1, part2;
    //但是不能省略单词struct来缩写这个声明,part不是类型名，如果前面没有struct的话就没有意义了
    //part part3,part4;
    //2.结构标记的声明可以和结构变量的声明合并在一起
    struct inventory {
        int number;
        char name[NAME_LEN + 1];
        int on_hand;
    } inventory1, inventory2;
    //所有声明为struct part类型的结构彼此之间是兼容的
    struct part part3 = {528, "Disk drive", 100};
    part2 = part3;

    /*f16.2.2:结构类型的定义
     * 除了声明结构标记，还可用typedef来定义真实的类型名。
     *
     * */
    typedef struct {
        int number;
        char name[NAME_LEN + 1];
        int on_hand;
    } Part;//类型Part的名字必须出现在定义的末尾，而不是单词struct的后边
    //因为类型Part是typedef的名字，所以不允许书写struct Part。无论在哪里声明，所有的Part类型的变量都是兼容的
    Part part4, part5;
    //需要命名结构时，即可以选择声明结构标记，也可以使用typedef。但是，结构使用链表时，强制使用声明结构标记

    /*16.2.3:结构作为参数和返回值
     * 如下：
     * print_part()和build_part()函数
     * 给函数传递结构和从函数返回结构都要求生成结构中所有成员的副本。这些操作对程序加强了一定数量的系统开销，
     * 特别是结构很大的时候。为了避免这类系统开销，有时用传递指向结构的指针代替传递结构本生是很明智的做法。类似
     * 可以使函数返回指向结构的指针来代替返回实际的结构；
     * 除了效率方面的考虑之外，避免创建结构的副本还有其他原因。
     *
     * */

    /*16.2.5：匿名结构
     * 从C11开始，结构或联合的成员也可以是另一个没有名字的结构，如果一个结构或者联合包含了这样的成员：
     * 1.没有名称；
     * 2.被声明为结构类型，但是只有成员列表而没有标记。
     * 那这个成员就是一个匿名结构
     * */
    struct t {
        int i;
        struct {
            char c;
            float f
        };
    };
    union u {
        int i;
        struct {
            char c;
            float f;
        };
    };
    //初始化
    struct t t = {1, {'X', 1.23}};//初始化器里面的花括号不能省略
    //下面的案例 struct p 包含了一个没有标记、没有名称的结构成员，这个结构成员的成员c和f被认为属于struct p
    struct p {
        int i;
        struct s {
            int j, k: 3;
        }; //有标记的成员
        struct {
            char c;
            float f
        };//无须标记且未命名的成员
        struct {
            double d;
        } s;//命名的成员
    } p;
    p.i = 2006;
    // p.j=5; 非法
    // p.k=6;非法
    p.c = 'X'; //合法
    p.f = 2.0;//合法
    p.s.d = 22.0;

}

/**
 * 16.2.3 当part结构用作实际参数时，第一个函数显示出结构的成员
 * @param p
 */
void print_part(struct part p) {
    printf("Part number: %d\n", p.number);
    printf("Part name: %s\n", p.name);
    printf("Quantity on hand: %d\n", p.on_hand);

}

/**
 * 16.2.3:返回part结构，此结构由实际参数构成
 * 注意，函数build_part的形式参数和结构part的成员名相同是合法的，因为结构拥有自己的命名空间
 *
 * */
struct part build_part(int number, const char *name, int on_hand) {
    struct part p;
    p.number = number;
    strcpy(p.name, name);
    p.on_hand = on_hand;
    return p;

}


/**
 * 16.3 嵌套的数组和结构
 * 结构和数组的组合没有限制。数组可以将结构作为元素，结构也可以包含数组和结构作为成员。
 * 这里着重介绍成员是结构的结构和元素是结构的数组。
 */
void struct_array_struct() {
    //16.3.1 嵌套的结构：把一种结构嵌套在另一种结构中经常是非常有用的
    //下面的结构是用来存储一个人的姓名、中间名和姓
    struct person_name {
        char first[NAME_LEN + 1];
        char middle_initial;
        char last[NAME_LEN + 1];
    };
    //可以用结构person_name作为更大结构的一部分内容
    struct student {
        struct person_name name;
        int id, age;
        char sex;
    } student1, student2;
    //访问student1的名、中间名或姓需要运用两次.运算
    strcpy(student1.name.first, "Fred");
    //使name成为结构的好处之一就是可以把名字作为数据单元来处理，这样操作起来更容易
    //例如如果打算编写函数来显示名字，那么只需要传递一个实际参数(person_name结构)而不是三个实际参数
    //display(student1.name);
    //同样把信息从结构person_name复制给结构student的成员name将只需要一次而不是三次赋值:
    struct person_name new_name;
    student1.name = new_name;

    /*16.3.2: 数组的嵌套
     * 数组和结构最常见的组合之一就是其元素为结构的数组。这类数组可以用作简单的数据库。
     * 案例如下：
     * */
    //下列结构part的数组能够存储100种零件的信息
    struct part inventory[100];
    //为了访问数组中的某种零件，可以使用取下标的方式，例如为了显示存储在位置i的零件，可以写成
    int i;
    print_part(inventory[i]);
    //访问结构part内的成员妖气结合使用取下标和成员选择。为了给inventory[i]中的成员number赋值883，可以写成
    inventory[i].number = 883;
    //访问零件名中的单个字符要求先取下标(选择特定的零件),然后选择成员(选择成员name),再取下标(选择零件名称中的字符).为了使存储在
    //inventory[i]中的名字变为空字符串，可以写成
    inventory[i].name[0] = '\0';

    /* 16.3.3 结构数组的初始化
     * 初始化结构数组与初始化多维数组的方法非常相似。每个结构都用有自己的带有花括号的初始化器，数组的
     * 初始化器简单地在结构初始化器的外围括上另一对花括号。
     * 初始化结构数组的原因之一是，我们打算把它作为程序执行期间不改变的信息的数据库。
     * 案例如下：
     * */
    //假设程序在打国际长途电话时需要访问国家(地区)代码。首先，设置结构用来存储国家(地区)名和响应代码:
    struct dialing_code {
        char *country;//注意，这里是指针而不是字符数组。当初始化dialing_code结构时，country会指向字面串
        int code;
    };
    //接下里，声明这类结构的数组并对其进行初始化，从而使此数组包含一些世界上人口最多的国家(地区)的代码
    const struct dialing_code country_codes[]={
            {"China", 55},{"France",33},
            {"Germany",49},{"Italy",39},
            {"Spain",34},{"Korea",82}};

}
