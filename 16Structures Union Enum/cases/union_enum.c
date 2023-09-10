/********************************************************************************
* @author: mason shi
* @date: 2023/8/13 16:54
* @version: 1.0
* @description: 主要介绍联合和枚举的课本使用案例
********************************************************************************/
#include<stdio.h>
#include<string.h>

#define INT_KIND 0
#define DOUBLE_KIND 1
#define TITLE_LEN 100
#define AUTHOR_LEN 20
#define DESIGN_LEN 30
//typedef union {
//    int i;
//    double d;
//} Number;
//4.3为联合添加标记字段：
/*联合所面临的主要问题是不容易确定联合最后改变的成员，因此所包含的值可能无意义的。例如下面的函数：
 * 通过标记字段可以就可以解决这个问题*/
typedef struct {
    int kind;/*tag field*/
    union {
        int i;
        double d;
    } u;
} Number;

void print_number(Number n);

void cases_union();

int main(void) {
    cases_union();
    //为联合添加“标记字段”的使用案例

}

/**
 * 16.4 联合
 * 像结构一样，联合(union)也是由一个或多个成员构成的，而且这些成员可能具有不同的类型。但是编译器只为联合中最大的成员分配
 * 足够的内存空间。联合的成员在这个空间内彼此覆盖。这样的一个结果是，给一个成员赋予新值也会改变其他成员的值。
 */
void cases_union() {
    //1.联合的声明
    union {
        int i;
        double d;
    } u;

    struct {
        int i;
        double d;
    } s;
    /*结构变量s和联合变量u只有一处不同：s的成员存储在不同的内存地址中，而u的成员存在同一内存地址中*/
    //2.访问联合的成员方法和访问结构的方法相同
    u.i = 89;
    printf("u.i的值:%d\n", u.i);
    u.d = 78.89; //可以输出：u.i的值:89
    printf("u.i的值:%d\n", u.i); //被覆盖掉，输出：u.i的值:-1030792151
    printf("u.d的值:%f\n", u.d); //正常输出：u.d的值:78.890000
    //对于上面的赋值，因为编译器把联合成员重叠存储，所以改变一个成员就会使之前存储在任何其他成员中的值发生改变。
    //因此，如果把一个值存储到u.d中，那么先前存在u.i中的值会丢失

    /*
     * 16.4.1:联合的运用：
     * 1.用联合来节省空间；
     * 2.用联合来构造混合的数据结构；
     * 3.用联合添加标记字段
     * 4.匿名联合
     * */
    //4.1:用联合来节省空间
    /*案例：打算设计的结构包含通过礼品册售出的商品的信息。礼品册上只有三种商品：图书、杯子和衬衫。
     * 每种商品都含有库存量、价格以及与商品类型相关的其他信息。
     * 图书：书名、作者、页数
     * 杯子：设计。
     * 衬衫：设计、可选颜色、可选尺寸
     * */
    //下面先用结构的方式来存储
    struct catalog_item {
        int stock_number;
        double price;
        int item_type;
        char title[TITLE_LEN + 1];
        char author[AUTHOR_LEN + 1];
        int num_pages;
        char design[DESIGN_LEN + 1];
        int colors;
        int sizes;

    };
    //上述结构虽然好用，但是浪费空间。因为对礼品册中的所有商品来说只有结构中的部分信息是常用的。比如，如果商品是图书，那么就不
    //需要存储design、colors和sizes。通过结构在catalog_item内部放置一些联合，可以减少结构所需要的内存空间。联合的成员将是一些
    //特殊的结构，每种结构都包含特定类型的商品所需要的数据：
    struct catalog_item02 {
        int stock_number;
        double price;
        int item_type;
        union {
            struct {
                char title[TITLE_LEN + 1];
                char author[AUTHOR_LEN + 1];
                int num_pages;
            } book;
            struct {
                char design[DESIGN_LEN + 1];
            } mug;
            struct {
                char design[DESIGN_LEN + 1];
                int colors;
                int sizes;
            } shirt;
        } item;

    } c;
/*注意：联合(item)是结构catalog_item的成员，而结构book、mug和shirt则是联合item的成员。如果c是图书的结构catalog_item，那么可以用
 * 下列的方法显示图书的名称*/
    printf("%s", c.item.book.title);
    //给design成员赋值
    strcpy(c.item.mug.design, "Cats");
    printf("design成员的值: %s\n", c.item.mug.design);
    //那么另一个结构中的design成员也会被定义，并具有相同的值
    printf("%s", c.item.shirt.design);


    //4.2：用联合来构造混合的数据结构
    /*创建包含不同类型混合数据的数据结构。假设需要数组的元素是int值和double值的混合。
     * 因为数组的元素必须是相同的类型，所以好像不可能如此类型的数组。但是利用联合就可以实现。
     * */
    //1. 首先定义一种联合类型，它所包含的成员分别表示要存储在数组中的不同数据类型：
    typedef union {
        int i;
        double d;
    } Number;
    //接下来，创建一个数组，使数组的元素是Number类型的值
    Number number_array[1000];
    //数组number_array的每个元素都是Number联合。Number联合既可以存储int类型的值又可以存储double类型的值
    //所以可以在数组number_array中存储int和double的混合值。
    //具体使用：需要使用数组number_array的0号元素来存储5，用1号元素来存储8.789。实现如下
    number_array[0].i = 5;
    printf("联合构造的混合结构:%d\n", number_array[0].i);
    number_array[1].d = 8.789;
    printf("联合构造的混合结构:%d\n", number_array[0].i);
    printf("联合构造的混合结构:%f\n", number_array[0].d);

    /*16.5枚举的类型使用:比使用#define预处理器方便多了
     * */
    //定义方式一：
    enum {
        CLUBS, DIAMONDS, HEARTS, SPADES
    } s1, s2;
    //定义方式二：
    enum suit {
        SUCCESS, FAIL, ERROR, COMPLETE
    };
    enum suit s3, s4;
    //定义方式三：
    typedef enum {
        RED, BLUE, BLACK, YELLOW
    } color;
    color c1, c2;
    //枚举声明“标记字段”
    typedef struct {
        enum {
            INT_CATE, DOUBLE_CATE
        } kind;
        union {
            int i;
            double b;
        } u;
    } number;


}

void print_number(Number n) {

    if (n.kind = INT_KIND)
        printf("%d", n.u.i);
    else
        printf("%g", n.u.d);
}


