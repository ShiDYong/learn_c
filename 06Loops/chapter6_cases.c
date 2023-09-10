/**
Created by mason on 2023/5/13.
 第6章：循环语句
 1.循环语句是重复执行其它语句(循环体)的一种语句。在C语言中，每个循环都有一个控制表达式(controlling expression)。
 每次执行循环体(重复一次)时都要对控制表达式求值。如果表达式不为真(即值不为0)，那么继续执行循环.
 2.C语言提供了3种重复语句，即while、do语句和for语句
   1.while循环是在循环体执行之前测试控制表达式，do循环在循环体执行之后测试控制表达式，for语句则非常适合哪些递增或递减计数的循环
   2.跳出循环的语句:
     break语句：用来跳出循环并把程序控制传递到循环后的下一条语句
     continue语句：用来跳过本次循环的剩余部分
     goto 语句则可以跳到函数内的任何语句上
*/
#include <stdio.h>

/**
 * 案例1:使用while语句计算大于或等于数n的最小的2的幂
 * @param n 传入的n的值
 * @return 返回满足条件的最小的2的幂
 */

int compute_smallest_number(int n) {
    int i = 1;
    while (i < n)      //执行while语句时，首先计算控制表达式的值。如果值不为0(即真值),那么执行循环体，接着再次判定表达式
        i = i * 2;    //这个过程持续进行，直到控制表达式的值变为零才停止。如果单条执行语句，可以不加花括号，多条就要加花括号
    return i;

}

/**
 * 用while语句实现倒计时展示
 * @param n 开始倒计时的数
 *
 */
void display_countdown(int n) {
    while (n > 0) {  //循环体多条语句，就要加上花括号
        printf("T minus %d and counting\n", n);
        n--;
    }
    //通过上面的倒计数可以发现以下问题：
    //1.在while循环停止时，控制表达式的值为假，因此,表达式i > 0的控制的循环终止时，i时一定小于或等于0的
    //2.可能根本不执行while循环体。如果变量n的值是负数或者0，那么不会执行循环
    //3.while语句通常有多种写法，以下就是对倒计数进行优化：
    int i = 10;
    while (i > 0)
        printf("Test minus %d and counting\n", i--);


    //3.无限循环，如果控制表达式的值始终非零，while语句将无法终止。平时可以利用非零常量
    //作为控制表达式来构造无限循环,除非循环体含有跳出循环控制语句
    while (1) {
        printf("This while statement will execute forever...");
        return; //加上return跳出无限循环体
    }
}

/**
 *案例练习：现在编写一个程序来显示平方表。首先程序提示用户输入一个数n，显示出n行的输出，每行包含一个1-n的数及其平方值
 * This program prints a table of square.
 * Enter number of entries in table:5
 *      1       1
 *      2       4
 *      3       9
 *      .......
 * Prints a table of square using a while statement
 */

void prints_square_table() {
    int i, n;
    printf("This program prints a table of square.\n ");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    i = 1;
    while (i <= n) {
        printf("%10d%10d\n", i, i * i);  //注意printf("%10d")这样的写法，是占用10个字符，右对齐
        i++;
    }
}

/**
 * 案例练习：编写一个程序使用while语句，对用户输入的整数数列进行求和运算
 * This program sums a series of integer.
 * Enter integers (0 to terminate):8 23 71 5 0  如何获取到用户输入的这一串数字，同时要区分是多少位，再进行相加呢？
 * The sum is : 107
 */
void sum_integer() {
    int n, sum = 0;  //这里要添加初始化默认值0，
    printf("This program sums a series of integer.\n");
    printf("Enter integers (0 to terminate): ");
    scanf("%d", &n);  //先获取第一个输入的字符，先判断后累加后,不影响最后加的结果
    while (n != 0) {  //因为是数列求和，0可以排除掉
        sum += n;
        scanf("%d", &n); //这里进行累加后再获取输入的第二个字符，非常巧妙，但是有问题，输入只有一个数或者
        //输入多个数最后一个数后就会卡住程序，因为scanf函数获取不到下一个整数就会停止住
        //目前暂时无法相除对应的方法，学到后面字符串相关操作再过来处理
    }
    printf("The sum is %d\n", sum);

}

/**
 * 案例练习：do语句本质是while语句，只不过其控制语句表达式是再每次执行完循环体之后进行判定的
 * do语句的格式如下：do 语句while(表达式);
 * 同处理while语句一样,do语句的循环体也必须是一条语句(当让可以用符合语句)且控制表达式的外面也必须有圆括号.
 * 执行do语句时，先执行循环体，再计算控制表达式的值
 */

void do_while_statement() {
    //使用do语句改写以下倒计数
    int i = 10;
    do { //无论需要与否，最好都需要给所有的do语句都加上花括号，不加花括号的do语句容易被误认为while语句
        printf("Test minus %d and counting\n", i--);
    } while (i > 0);

}

/**
 * 案例练习：do语句的使用案例，虽然C程序中的while语句出现的次数远多于do语句，但是后者对于至少需要执行一次的循环
 * 来说是非常方便的。现在要起写一个程序计算用户输入的整数的位数：
 * Enter a nonnegative integer: 60
 * The number of has 2 digit(s)。
 * 方法是把输入的整数反复的除以10，直到结果变为0时停止，除法的次数就是所求的位数。因为不知道到底需要多少次除法运算次
 * 才能到达0，所以很明显程序需要某种循环。但是应该要用while语句还是do语句呢？do语句显然更合适，因为每个整数(包括0)都
 * 至少有一位数字.
 */
void calculate_number_digits() {
    int digit = 0, n;
    printf("Enter a nonnegative integer:");
    scanf("%d", &n);
//    do {
//        n = n / 10;
//        digit++;
//    } while (n > 0);
//    printf("The number of has %d digit(s)\n", digit);

    //下面使用while语句实现，进行对比,当初始值为0时根本不会执行
    //所以需要多加一个判断
    if (n == 0)
        n = 1; //把n赋值给任意1-9的整数
    while (n > 0) {
        n = n / 10;
        digit++;
    }
    printf("The number of has %d digit(s)\n", digit);


}

/**
 * 案例练习for语句：是功能最强大的一种循环，通常是编写多循环的最佳方法。for语句非常适合运用再“计数"变量的循环中，
 * 当然它也可以灵活地用于许多其他类型的循环中。for语句的格式如下所示：
 * for(声明或者表达式1:表达式2:表达式3)语句
 * for语句和while语句关系紧密。事实上除了一些极少数的情况除外，for循环可以用等价的while循环替换
 * 表达式1；
 * while(表达式2){
 *  语句
 *  表达式3;
 *  }
 *  for(int i =10; i> 0; i--){
 *      printf("Test minus %d and counting\n", i);

 *  }
 *  等同于while语句：
 *  int i = 10;
    while (i > 0)
        printf("Test minus %d and counting\n", i);
        i--;
    }
 *
 */
void test_for_statement() {
    int i, n;
    //for语句的惯用法：对于向上加(变量自增)或向下减(变量自减)的循环来说，for语句通常是最好的选择.
    //1.从0向上加到n-1：
    for (i = 0; i < n; i++) {};
    //2.从1向上加到n
    for (i = 1; i <= n; i++) {};
    //3.从n-1向下减到0:
    for (i = n - 1; i >= 0; i--) {};
    //4.从n向下减到1;
    for (i = n; i > 0; i--) {};
    //在C99中的for语句，可以将第一个表达式替换为一个声明
    for (int j = 0; j < n; j++) {};

    //在for循环语句中省略的表达式:通常for语句用三个表达式控制循环，但是有一些for循环可能不需要这么多的，因此
    //C语言允许省略任意或者全部的表达式：
    //1.省略第一个表达式，那么在执行循环前没有初始化的操作,变量i由一条单独的赋值语句实现了初始化，但是表达式中间的;不可省略
    i = 10;
    for (; i > 0; i--)
        printf("Test minus %d and counting\n", i);
    //2.省略第三个表达式，循环体需要确保第二个表达式的值最终变为假，为了弥补省略第三个表达式产生的后果，我们使变量i在循环体自减
    //此时for语句和while语句没有任何分别
    for (; i > 0;)
        printf("Test minus %d and counting\n", i--);
    //3.省略第二个表达式，那么它默认为真值，因此for循环语句不会终止(除非以某种形式停止)
    for (;;) {}; //进入无限循环相当于while(1){}
}

/**
 * C语言对控制循环行为的三个表达式没有加任何限制，虽然这些表达式通常对同一个变量进行初始化、判定和更新，
 * 但是没有要求它们之间以任何方式进行相互关联。查看下面的程序
 */
void prints_square_table_2() {
    int i, n, odd, square;
    printf("This program prints a table of square.\n ");
    printf("Enter number of entries in table: ");
    scanf("%d", &n);
    i = 1;
    odd = 3;
    for (square = 1; i <= n; odd += 2) {
        printf("%10d%10d\n", i, square);
        i++;
        square += odd;
        //for语句初始化一个变量(square),对另一个变量(i)进行判定，并且对第三变量
        //(odd)进行自增操作。变量i是要计算平方值的数，变量square是变量i的平方值
        //而变量odd是一个奇数，需要用它来和当前的平方值相加以获得下一个平方值
        //for语句这种极大的灵活性有时是非常有用的。
    }


}

/**
 * 退出循环：break语句可以把程序控制从switch语句中转移出来的方法。break语句还可以
 * 用于跳出while、do或for循环，就是跳出整个循环,通过break设置退出点；
 * 案例：假设要编写一个程序来测试数n是否为素数。这里是先编写一个for语句用n除以2-n-1的所有数。一旦
 * 发现有约数就跳出来，而不需要继续尝试下去。在循环终止后，可以用一个if语句来确定循环是否提前终止(因此n不是素数)
 * 还是正常终止(n是素数)
 */
void break_test() {
    int n, d;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (d = 2; d < n; ++d) {
        if (n % d == 0)
            break;//对于退出点在循环体中间而不是循环体之前或之后的情况，break语句特别有用
        //读入用户输入并且在遇到特殊输入值时终止的循环通常属于这种类型：
        //break语句刚好把程序控制转移到循环体末尾之后；
        //break语句把程序控制从包含该语句的的最内存while、do、for或switch语句中转移出来
        //因此，当这些语句出现嵌套时，break语句只能跳出一层嵌套。思考下面这些情况
        //break语句可以从把控制程序从switch语句中转移出来，但是不能跳出while循环。可以使用goto完全跳出
/*        while (...){
            switch (...) {
                ...
                break;
                ....
            }
        }*/

    }
    if (d < n)
        printf("%d is divisible by %d\n", n, d);
    else
        printf("%d is prime\n", n);

}

/**
 * 退出循环之continue:
 * 1.break语句刚好把程序控制转移到循环体末尾之后，而continue语句刚好把程序控制转移
 * 到循环体末尾之前；
 * 2.break语句会使程序控制跳出循环，而continue语句会把程序控制留在循环内；
 * 3.break语句可以用于switch语句和循环(while、do、for)，而continue语句只能用于循环。
 * 案例：通过读入一串数字求和的操作说明continue语句的简答运用。
 * 循环在读入第10个非零数后终止。
 */
void test_continue() {
    int n, sum, i;
    printf("Enter a number: ");
    scanf("%d", &i);
    while (n < 10) {
        if (i == 0)
            continue;
        sum += i;
        //scanf("%d", &i); //这里只是演示continue的用法，有很多不足的地方
        n++;
        //continue jumps to here
    }
}

/**
 * goto语句的使用：break和continue语句都是跳转语句：它们把控制从程序的一个位置转移到另一个位置。这两者都是受限的:break语句目标
 * 时包含该语句的循环结束之后的那一点，而continue语句的目标是循环结束之前的那一点。
 * goto语句则剋跳转到函数中任何有标号的语句出[C99增加了一条限制：goto语句不可以用于绕过变长数组的声明]
 */
void test_goto() {
    int n, d;
    printf("Enter a number: ");
    scanf("%d", &n);
    for (d = 2; d < n; ++d) {
        if (n % d == 0)
            goto done;//done这里是标识符，执行goto done之后，控制会转移到done后面的语句上，而
        //且该语句必须和goto语句在同一个函数中
        //goto不能使用过多，容易编程垃圾代码，因为可以随意地跳来跳去，垃圾代码是非常难于理解和修改的

    }
    done: //跳转到这里执行后面的if和else语句
    if (d < n)
        printf("%d is divisible by %d\n", n, d);
    else
        printf("%d is prime\n", n);

}

/**
 * 案例分析：许多简单的程序是基于菜单的：它们向用户显示可选择的的命令列表。一旦用户选择了某条命令，
 * 程序就执行相应的操作，然后提示用户输入下一条命令：这个过程一直会持续到用户选择“退出”或“停止”命令
 * 这类程序的核心显然是循环。循环内将有语句提示用户输入命令、读命令，然后确定执行的操作
 * 具体案例说明：开发一个维护账户的余额。该程序将为用户提供选择菜单：清空账户余额、往账户打钱、从账户取钱、
 * 显示当前余额、退出程序、选项分别是用整数0、1、2、3和4表示。
 */
void balance_check() {
    int cmd;
    float balance = 0.0f, credit, debit;
    printf("***ACME checkbook-balancing program***\n");
    printf("Command: 0 = clear, 1=credit,2=debit, ");
    printf("3=balance, 4= exit\n\n");
    for (;;) {
        printf("Enter command: ");
        scanf("%d", &cmd);
        switch (cmd) {
            case 0:
                balance = 0.0f;
                break;
            case 1:
                printf("Enter amount of credit: ");
                scanf("%f", &credit);
                balance += credit;
                break;
            case 2:
                printf("Enter amount of debit: ");
                scanf("%f", &debit);
                balance -= debit;
                break;
            case 3:
                printf("Current balance: $%.2f\n", balance);
                break;
            case 4:
                return;
            default:
                printf("Command: 0=clear,1=credit,2=debit, ");
                printf("3=balance,4=exit\n\n");
                break;
        }
    }

}

//int main() {
    // printf("compute_smallest_number方法返回的值: %d\n", compute_smallest_number(8));
    //display_countdown(10);
    // prints_square_table_2();
    //sum_integer();
    //do_while_statement();
    // calculate_number_digits();
    //  break_test();
    //test_continue();
//    balance_check();
//    return 0;
//}


