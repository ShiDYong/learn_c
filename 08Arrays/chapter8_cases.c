/**
Created by mason on 2023/5/31
 第八章：到目前为止，所见的都是标量(scalar)：标量具有保存单一数据项的能力。C语言也支持聚合(aggregate)变量，
 这类变量可以存储组的数值。在C语言中一共有两种聚合，数组(array)和结构(structure)
 *
*/
#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <time.h>

#define NUM_SUITS 4
#define NUM_RANKS 13
#define SIZE ((int) sizeof(a) / sizeof(a[0]))
#define NUM_RATES ((int) sizeof(value) / sizeof(value[0]))
#define N 10
#define INITIAL_BALANCE 100.00

/**
 * 8.1一维数组常见的用法
 */
void one_dimensional_arrays() {
    /*1.数组是含有多个数据值的数据结构，并且每个数据值具有相同的数据类型，这些数据值称为元素(element)，为了声明数组
     * 需要指明数组元素的类型和数量，数组的元素可以是任何类型，数组的长度可以用任何(整型)常量表达式指定
     * 因为程序以后改变时需要调整数组的长度，所以较友好的方法是用宏来定义数组的长度
     * */
    //1.声明数组a有10个int类型的元素
    int a[N];
    //2.用宏来定义数组的长度
    int b[N];
    int i, j, sum;

    /*2.数组的下标：为了存取特定的数组元素，可以在写数组名的同时在后边加上一个用方括号围绕的整数值(这被称为对数组取下标(subscripting)或进行索引(index))
     * 数组元素始终从0开始因此长度位n的数组元素的索引是0～n-1。一般来说，如果数组包含了T类型的元素，那么数组中的每个元素均被视为T类型的变量
     * 数组和for循环结合在一起使用。许多程序所包含的for循环是为了对数组中的每个元素执行一些操作
     * */
//    a[0] = 1;
//    printf("%d\n", a[5]);
//    ++a[i];
    /*C语言不要求检查下标的范围。当下标超出范围时，程序可能执行不可预知的行为，下标超出范围的原因之一是忘记了
     * n元数组是0~n-1,，而不是1~n
     * 下面的案例示范
     * */
    for (i = 0; i <= 10; i++)
        a[i] = 0;  /*对于某些编译器来说，这个表面上正确的for语句却产生了一个无限循环！当变量i的值变为10时，
 * 程序将数值0存储在a[10]中。但是a[10]这个元素并存在，因此在元素a[9]后数值0立刻进入内存，如果内存中变量放置在a[9]
 * 的后边(有可能),那么变量i将被重置为0,进而导致循环重新开始。*/


    //*****数组的下标也可以时表达式*****//
    // a[i + j * 10] = 0;
    //**但是表达式甚至可能有副作用****//
    while (i < N)
        a[i] = b[i++];
    /**/
    //3.清空数组的惯用操作
    for (i = 0; i < N; i++)
        a[i] = 0;
    //4.将数据读取到a中
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);//调用scanf函数读取数组元素时，就像对待普通变量一样，必须使用取地址符号&

    //5.对数组的元素进行求和
    for (i = 0; i < N; ++i)
        sum += a[i];


}

void test() {
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int b[N];
    int i = 0, j, sum;

    /*当数组下标有副作用时一定要注意。例如额，下面这个循环想把数组b中的元素复制到数组a中，但它可能无法独立正常工作
     * 表达式a[i]= b[i++]访问并修改i的值，如4.4节所表示，这样会导致未定义的行为，当然，通过从下标中移走自增操作
     * 可以很容易地避免此类问题的发生：
     * */
    // while (i < N)
    //     a[i] = b[i++];
    //进行修改
//    for (i = 0; i < N; i++)
//        a[i] = b[i];
//    for (i = 0; i <= 9; i++)
//        a[i] = 0;
//    for(i =1;i < N; i++)
//        sum+= a[i];
    for (i = 0; i < N; i++)
        scanf("%d", &a[i]);
}

/**
 * 数组的初始化
 */
void array_initialisation() {
/*1.数组初始化器(array initializer) 最长见的格式是一个用花括号括起来的的常量表达式列表，
 * 常量表达式之间的逗号进行分隔*/
    int a[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    //1.1如果初始化器比较短，那么数组中剩余的元素赋值为0；
    int b[10] = {1, 2, 3, 4, 5, 6}; //
    //1.2初始化器完全为空是非法的，所以要在花括号内放上一个0.初始化器比要初始化的数组长也是非法的。
    // int c[10] = {};但是编译器没有显示有问题
    // int d[3] = {1, 2, 3, 4, 5, 6};//编译器没有显示报红
    //1.3如果给定了初始化器，可以省略数组的长度
    int e[] = {1, 2, 3, 4};
    /*2.C99中的指示器：数组中只有相对较少的元素需要进行显示的初始化，而其他元素进行默认赋值,而且赋值的顺序不再是一个问题*/
    int f[15] = {[2] = 29, [9] = 7, [14] =28};
    int g[6] = {[5] = 2, [1] =3}; //没有指定值的元素均赋予默认值0
    //2.1组成指示器的方括号里必须是整型常量表达式。如果待初始化的数组长度为n，则每个表达式的值都必须在0～n-1之间。但是，如果数组
    //的长度是省略的，指示器可以指定任意非负整数；对于后一种情况，编译器将根据最大的值推断出数组的长度。如下面的
    //例子指示符最大值为23，因此数组的长度为24；
    int h[] = {[5] =10, [23] = 13, [11] = 36, [15] = 29};
    //2.2初始化器可以同时使用老方法(逐个元素初始化)和新方法(指示器)
    int i[10] = {5, 3, 7, 8, [4] = 23, 7, 8, [7]=45};


}

/**
 * 数列的反向:要求用户输入一串数，然后按反向顺序输出这些数
 */
void revers_number_order() {
    int a[N], b[N], i, j;
    printf("Enter %d numbers: ", N);
    for (i = 0; i < N; i++)  //将输入的数据读取到数组a中
        scanf("%d", &a[i]);  //在读入数时将其存储在一个数组中，然后反向遍历数组，一个接一个地显示出数组元素
    printf("In reverse order:");
    for (i = N - 1; i >= 0; i--)//该程序不会真的对数组的元素进行反向输出，只是使用户这样认为
        printf(" %d", a[i]);   //从数组的最后一个元素开始遍历
    printf("\n");
    /*上面的方法只是在打印的时候反向输，下面就是新增一个数组，把数组a的元素反向后存储到数组b,这样封装就可以成一个方法供别人调用*/
    for (i = N - 1, j = 0; i >= 0, j < N; i--, j++) {
        b[j] = a[i];
        printf(" %d", b[j]);

    }

    /*2.使用C99中的变长数组,变长数组常见于除了main函数外的其它函数。对于函数f而言，变长数组的最大优势就是每次调用f时长度可以不同
     * */


}

/**
 * 编写一个程序用来检查数中是否有出现多于一次的数字。用户输入数后，程序显示信息Repeated digit或No Repeated digit;
 * Enter a number: 28212
 * Repeated digit
 *
 */
void check_repeated_digit() {
    /*实现方法1:方便到时改写成一个方法让别人调用*/
//    int a[6] = {1, 3, 8, 4, 1, 9};
//    int i, j;
//    for (i = 0; i < 6; ++i) {
//        for (j = i + 1; j <= 5; j++) {
//            if (a[i] == a[j]) {
//                printf("Repeated digit %d\n", a[i]);
//                break;
//            }
//        }
//
//    }

    /*方法实现二：实现的方式很巧妙*/
    bool digit_seen[N] = {false};
    int digit;
    long n;

    printf("Enter a number: ");
    scanf("%ld", &n);
    while (n > 0) {
        digit = n % 10;
        if (digit_seen[digit]) {
            printf("%d\n", digit_seen[digit]); //打印的是索引即下标，但是不能无法打印出重复的数字是什么，实际可用范围比较小
            break;
        }
        digit_seen[digit] = true;
        n /= 10;
    }
    if (n > 0)
        printf("Repeated digit\n");
    else
        printf("No repeated digit\n");


}

/**
 * 运算符sizeof可以确定数组的大小(字节数).如果数组a有10个整数，那么sizeof(a)通常为40(假定每个整数占4个字节)
 * 还可以用sizeof来计算数组元素(a[0])的大小。用数组的大小除以数组元素的大小可以得到数组的长度：
 */
void test_sizeof_function() {
    int a[] = {1, 2, 3, 4, 5, 6};
    //1.用sizeof来计算数组元素和数组长度
    int Bytes = sizeof(a);
    //2.还可以用sizeof来计算数组元素(a[0])的大小
    int len = sizeof(a) / sizeof(a[0]);
    //3.当需要数组的长度时，可以采用上述表达式,对数组进行清零操作
    for (int i = 0; i < sizeof(a) / sizeof(a[0]); ++i)
        a[i] = 0;
    //4.如果使用上述方法，即使数组长度在日后需要改变，也不需要改变循环。当然，利用宏来表示数组的长度也有同样的好处，但是
    //sizeof方法稍微好些，因为不需要记忆宏的名字

    /*5.有些编译器会对表达式 sizeof(a) / sizeof(a[0])给出一条警告信息，这稍微有点烦人，变量i的类型可能是int(有符号类型),而
     * sizeof返回的值类型为size_t(无符号).由7.4节可知，把有符号和无符号整数相比较是很危险的，尽管在本例子中没有出现这样的问题。为了
     * 避免出现这一警告，可以将i的类型改成t，或者像下面这样，将 sizeof(a) / sizeof(a[0])强制转换成有符号整数*/
    for (int i = 0; i < (int) sizeof(a) / sizeof(a[0]); ++i);
    //但是表达式(int) sizeof(a) / sizeof(a[0])写起来不太方便，可以定义一个宏来表示它很有帮助
    for (int i = 0; i < SIZE; i++);


}

/**
 * 计算利息：下面这个程序显示一个表格，显示来在几年时间内100美元投资在不同利率下的价值。用户输入利率和要投资的年数。投资总价值每年计算一次
 * ，表格将显示成输入利率和紧随其后的4个更高的利率下投资的总价值：程序会话如下：
 * Enter interest rete:6
 * Enter number of years: 5
 *
 Years    6%     7%     8%     9%    10%
  1    106.00 107.00 108.00 109.00 110.00
  2    112.36 114.49 116.64 118.81 121.00
  3    119.10 122.50 125.97 129.50 133.10
  4    126.25 131.08 136.05 141.16 146.41
  5    133.82 140.26 146.93 153.86 161.05

 */
void computing_interest() {
    int i, low_rate, num_years, year;
    double value[5];
    printf("Enter interest rate: ");
    scanf("%d", &low_rate);
    printf("Enter number of years: ");
    scanf("%d", &num_years);
    /*1.先打印第一行的数据；
     * Years     6%     7%     8%     9%    10%
     * */
    printf("\nYears");
    for (i = 0; i < NUM_RATES; i++) {
        printf("%6d%%", low_rate + i);
        value[i] = INITIAL_BALANCE;
        /*要输出%d只需在前面再加上一个%，要输出\只需在前面再加上一个\，* 要输出双引号也只需在前面加上一个\即可。
         * *  printf("%%d\n");*  printf("\\\n");*  printf("\"\"\n");*/
    }
    printf("\n");
    for (year = 1; year <= num_years; year++) {
        printf("%3d   ", year);  //2.第一个循环外层循环将从1计数到用户要求的年数
        for (i = 0; i < NUM_RATES; ++i) { //3.内层循环将从利率的最低值递增到最高值，第二行的值依赖于第一行的数
            value[i] += (low_rate + i) / 100.0 * value[i];
            printf("%7.2f", value[i]);
        }
        printf("\n");
    }

    /* printf("输出控制符1 输出控制符2…", 输出参数1, 输出参数2, …);
     *  int i = 10;
    int j = 3;
    printf("%d %d\n", i, j);
*/

}

/**
 * 多维数组：数组可以有任意维数，一般常用的有二维数组，数学上称为矩阵
 */
void test_multidimensional_array() {
    //1.二维数组的定义
    int m[5][9]; //表示数组m有5行9列，数组的行和列下标都是从0开始索引：
    //为了访问i行j列的元素，表达式需要写成m[i][j].表达式表明列数组m的第i行，而m[i][j]则选行中的第j个元素
    //不要把m[i][j]写成[i,j]。如果这样写，C语言会把逗号看作运算符，因此m[i,j]就等同于m[j]
    //2.嵌套的for循环是处理多维数组的理想选择，一个循环处理遍历每一行，另一个循环遍历每一列
    double ident[N][N];
    int row, col;
    for (row = 0; row < N; row++) {
        if (row == col)
            ident[row][col] = 1.0;
        else
            ident[row][col] = 0.0;
    }
    //C语言中使用多维数组的较少，因为指针数组提供了存储多维数组更加灵活的方法
    //3.多维数组的初始化:如果初始化器没有大到足以填满整个多维数组，那么把数组中剩余的元素赋值为0
    int n[5][9] = {
            {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
            {1, 2, 3, 4, 5, 5, 6, 7, 8},
            {0, 9, 8, 7, 4, 3, 2, 1, 8, 9},
            {0, 0, 0},
            {0}
    };

    /*4.常量数组：无论一维数组还是多维数组，都可以通过在声明的最开始处加上单词const而称为常量
     * 把数组声明为const有两个好处。它表明程序不会改变数组，还对以后阅读程序的人可能是有价值的信息；
     * 它还有助于编译器发现错误-const会告诉编译器，我们不打算修改数组
     * */
    const char hex_chars[] = {
            '0', '1', '2', '3', 'A', 'B', 'C', 'D'};


}

/**
 * 二维数组和常量数组的用法综合案例：程序负责发一副标准纸牌。每张标准纸牌都有一种花色(梅花、方块、红桃或黑桃)和一个点数
 * (2、3、4、5、6、7、8、9、10、J、Q、K或A)。程序需要用户指明手里应该握有几张牌：
 * Enter number of cards in hand:5
 * Your hand: 7c 2s 5d as 2h
 * 如何编写一个程序从一副牌中随机抽取纸牌呢？如何避免两次抽到同一张牌呢？
 */
void test_play_cards() {
    bool in_hand[NUM_SUITS][NUM_RANKS] = {false};
    int num_cards, rank, suit;
    const char rank_code[] = {'2', '3', '4', '5', '6', '7', '8', '9',
                              '10', 't', 'j', 'q', 'k', 'a'};
    const char suit_code[] = {'c', 'd', 'h', 's'};
    srand((unsigned) time(NULL));
    printf("Enter number of cards in hand: ");
    scanf("%d", &num_cards);
    printf("Your hand: ");
    while (num_cards > 0) {
        suit = rand() % NUM_SUITS; /*picks a random suit */
        rank = rand() % NUM_RANKS; /*picks a random rank*/
        if (!in_hand[suit][rank]) {
            in_hand[suit][rank] = true;
            num_cards--;
            printf(" %c%c", rank_code[rank], suit_code[suit]);
        }
    }
    printf("\n");
}

//int main() {
    //one_dimensional_arrays();
    //test();
    // revers_number_order();
    //check_repeated_digit();
    // test_sizeof_function();
    //computing_interest();
//    test_play_cards();

//    return 0;
//
//}

