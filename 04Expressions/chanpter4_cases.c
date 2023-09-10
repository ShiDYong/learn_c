/**
Created by mason on 2023/5/1.
 第四章：C语言的常用的表达式
*/
#include<stdio.h>

/**
 * 4.1常用的算术运算符：
 *      一元运算符                                 二元运算符
 *                                  加法类                       乘法类
 * + 一元正号运算符                + 加法运算符                 * 乘法运算符
 * - 一元负号运算符                - 减法运算符                 / 除法运算符
 *                                                          % 求余运算符
 */
void arithmetic_operators() {
    int i = 10, j = 3, h = -2, k = 0;
    float g = 2.3f;
    //除了%运算外，上面表中的二元运算符既是允许操作数整数也允许操作数是浮点数
    //两者混合也是可以的,当int型操作数和float型操作数混合一起时，运算结果是float，类型提升
    printf("当int型操作数和float型操作数混合一起时，运算结果是float：%f\n", g + j);
    //当两个操作数都是整数时，运算符/会丢失分数部分来截取结果
    printf("10/3的结果会进行四舍五入取值：%d\n", 10 / 3);
    //运算符%当中一个不是整数时，程序将无法编译通过,

    // printf("运算符%当中一个不是整数结果：%d\n",i%g);
    //当运算符/和运算符%用于负操作数时，其结果时难以确定的,像C89、C99的结果时不一样的
    printf("操作符/用于负数操作的结果：%d\n", i / g);  //操作符/用于负数操作的结果：-2147483648
    printf("操作符%用于负数操作的结果：%d\n", i % h);  //操作符用于负数操作的结果：0
    printf("i%j的值是i除以j后的余数是：%d\n", i % j);
    //把0当作/或%的右操作数会导致未定义的行为
    printf("把0当作%的右操作数导致的结果:%d\n", i % k);//把0当作%的右操作数导致的结果:10
}

/**
 * 案例：Computing a GPC check Digit
 * 计算校验puc的校验位的方法:首先把第1位、第3位、第5位、第7位、第九位和第11位的数字相加；
 * 然后把第2位、第4位、第6位、第8位和第10位的数字相加；接着把第一次加法的结果乘以3，再和第二次的加法结果
 * 相加；随后再把上述结果减去1；相减后的结果除以10取余数；最后用9减去上一步骤中得到的余数。
 * 案例：0 51500 241128 ？
 */
void upc_check_digit() {
    int d, i1, i2, i3, i4, i5, j1, j2, j3, j4, j5, first_sum, second_sum, total;
    printf("Enter the first (Single) digit: ");
    scanf("%d", &d);
    printf("Enter first group of five digits:");
    //只能取一个所以要限制获取%1d
    //scanf("%d%d%d%d%d", &i1, &i2, &i3, &i4, &i5);这种方式无法单独获取输入的5个数字存储到指定5个变量中
    scanf("%1d%1d%1d%1d%1d", &i1, &i2, &i3, &i4, &i5);
    printf("Enter second group of five digits: ");
    scanf("%1d%1d%1d%1d%1d", &j1, &j2, &j3, &j4, &j5);
    first_sum = i2 + i4 + j1 + j3 + j5;
    second_sum = i1 + i3 + i5 + j2 + j4;
    total = first_sum * 3 + second_sum;
    printf("Check digit: %d\n", 9 - (total - 1) % 10);
    printf("Check digit: %d\n",(10-(total % 10)) %10);

}

/**
 * 赋值运算符：求出表达式的值后通常需要将其存储到变量中，以便将来使用，可以使用简单赋值表达式：
 * v =e：该表达式的效果就是求出e的值，并把此值赋值到v中
 * 符合赋值：利用变量的原有值计算出新值并重新赋值给这个变量，常见的有：+=,-=,*=,/=,%=
 * v+=e :表示把v加上e,然后将结果存储到v中;
 * v-=e :表示把v减去e,然后将结果存储到v中;
 * v*=e :表示把v加上e,然后将结果存储到v中;
 * v/=e :表示把v乘以e,然后将结果存储到v中;
 * v%=e :表示把v除以e取余数,然后将结果存储到v中;

 *
 */
void assignment_operators() {
    int v = 1, e = 2, j = 3;
    printf("v=v+e的值是：%d\n", v = v + e);  //v=v+e的值是：3
    printf("v+=e的值是：%d\n", v += e);  //注意此时的v值为3，上一步骤已经把值增为3了
    printf("i=i*j+k的值是：%d\n", v = e * j + 3); //i=i*j+k的值是：9
    printf("i*=j+k的值是：%d\n", v *= j + 3); //i*=j+k的值是：54
//注意：v+=e不等价于v= v+e。问题在于运算符的优先级：表达式i*=j+k和表达式i = i*j +k是不一样的
//因为计算v+=e只会求一次v的值，而计算v=v+e会求两次的值，在后一种情况下，对v求值可能引起的的任何副作用也都会出现
//两次,下面的例子查看
    int a[v];
    //v只会自增一次
    a[v++] += 2;
    //如果用=替代+=,语句变成
    a[v++] = a[v++] + 2;
    //v的值在别处被修改和使用了，因此上述语句的结果是未定义的,v的值可能自增两次,但我们无法确定会发生什么;
}

/**
 * 自增运算符和自减运算符
 *
 */
void increment_decrement_operators() {
    int i = 1;
    //++和--是有副作用的，它们会改变操作数的值
    printf("i is %d\n", ++i); //i is 2
    //通过前缀自增++的结果是i+1,副作用的效果是自增i,既i变成了2
    printf("i is %d\n", i);  // i is 2
    //后缀自增i++的结果是i,既打印显示的是i自增前的原始值，但是会引发i随后进行自增
    printf("i is %d\n", i++); //i is 2
    //打印显示的i变化后的新值，总结：++i意味着：立即自增i，i++意味着现在先用i的原始值，
    //稍后再自增i，至于这个稍后要多久？C语言标准没有明确说明，但是一定会再下一条语句执行前进行自增
    printf("i is %d\n", i); //i is 3
}

/**
 * 当两个或多个运算符出现在同一个表达式中时，可以按运算符优先级从高到低的次序给子表达式添加圆括号，由此确定编译器解释表达式的方法
 * 比如：i+j*k等价于i + (i*j),-i * -j等价于:（-i)*（-j）
 * 当表达式中包含两个或更多个相同优先级的运算符时，仅有运算符优先级规则是不够的，这种情况下，运算符的结合性开始发挥作用。如果运算符
 * 从左到右结合那么称为是左结合型，二元运算符(*、/、%、+、-)都是左结合的，例如：i -j -k 等价于：(i-j)-k
 * 如果运算符从右向左结合的，那么这种是有结合的，例如下表具体所示：
 * 部分C语言运算符表
 *        优先级              类型名称                符号                          综合性
 *        1                 (后缀)自增                ++                           左结合
 *                          (后缀)自减                --                           ...
 *        2                 (前缀)自增              ++                             右结合
 *                          (前缀)自减              --                              ...
 *                          一元正号                  +                             ...
 *                          一元负号                  -                             ...
 *        3                 乘法类                  * / %                           左结合
 *        4                 加法类                   + -                            左结合
 *        5                 赋值                   *= /= %= += -=                   右结合
 *        7                 关系运算符             < > <= >=                         左结合
 *        8                 判等                   ==  !=                           左结合性
 */
void expression_evaluation() {
    //当子表达式改变了某个操作数的值时，产生的值可能就不一致了，下面例子
    int a = 5, b, c;
    c = (b = a + 2) - (a = 1);
    //通过打印出来的值看到不同编译器的值可能是不一样的
    //这里是先计算子表达式(b=a+2),如果先计算子表达式(a=1),那么b的值为3，c的值为2
    //避免出现这种问题尽量不要在子表达式中使用赋值运算符
    printf("c的值什么是呢？%d\n",c);  //6
    printf("a的值什么是呢？%d\n",a);   //1
    printf("b的值什么是呢？%d\n",b);  //7
    //依赖特定的顺序也会出问题
    int i =2,j;
    j = i * i++;
    printf("i的值是多少呢？%d\n",i); //3
    printf("j的值是多少呢？%d\n",j);  //4
}


//int main(void) {
//    // arithmetic_operators();
//    upc_check_digit();
//    // assignment_operators();
//   // increment_decrement_operators();
//   //expression_evaluation();
//    return 0;
//}