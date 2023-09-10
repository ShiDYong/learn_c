///**
//Created by mason on 2023/6/18
// 第九章：函数练习题
// */
//#include <stdio.h>
//#include <stdbool.h>
//
//int check(int x, int y, int n);
//
//int gcd(int m, int n);
//
//int day_of_year(int month, int day, int year);
//
//int is_leap_year(int year);
//
//int day_of_year_optimize(int month, int day, int year);
//
//int num_digits(int n);
//
//int digit_01(int n, int k);
//
//int digit_02(int n, int k);
//
//int digit_03(int n, int k);
//
//int test_exec10(int a[], int n);
//
//float compute_GPA(char grades[], int n);
//
//double inner_product(double a[], double b[], int n);
//
//int evaluate_position(char board[8][8]);
//
//bool has_zero(int a[], int n);
//
//double median(double x, double y, double z);
//
//int fact_rewrite(int n);
//
//int recursion_gcd(int m, int n);
//
//void pb(int n);
//
//
//int main(void) {
//    //2.练习题2
////    int x, y, n;
////    printf("Enter three numbers: x, y, z: ");
////    scanf("%d%d%d", &x, &y, &n);
////    printf("check function return value: %d", check(x, y, n));
//    //3.求最大公约数的欧几里得算法
////    int n = 12, m = 8;
////    printf("%d和%d最大公约数是:%d ", n, m, gcd(n, m));
//
//    //4.练习题4:
////    int month, day, year;
////    printf("Enter month,day,year: ");
////    scanf("%d%d%d", &month, &day, &year);
////    printf("day of year is: %d", day_of_year(month, day, year));
////    printf("\nday of year is: %d", day_of_year_optimize(month, day, year));
//
//    //课后练习题5:
////    int n = 999;
////    printf("\nnumber of digits: %d", num_digits(n));
//    //课后练习题6:
////    printf("%d\n", digit_03(829, 0)); // Output:0
////    printf("%d\n", digit_03(829, 1)); // Output: 9
////    printf("%d\n", digit_03(829, 2)); // Output: 2
////    printf("%d\n", digit_03(829, 3)); // Output: 8
////    printf("%d\n", digit_03(829, 4)); // Output: 0 (k is greater than the number of digits in n)
//
//    //课后练习题目10:
//    //int a[] = {2, 10, 1, 4, 25};
////    int a[] = {2, 10, -1, 0, 25};
////    int n = 5;
////    printf("\n return value: %d", test_exec10(a, n));
//
//    //课后练习题目11
////    char grades[] = {'A', 'b', 'd', 'f', 'C'};
////    int n = 6;
////    printf("\n等级的平均值: %0.2f", compute_GPA(grades, 5));
//    //课后练习题12:
////    double a[] = {1, 2, 3, 4, 5};
////    double b[] = {5, 4, 3, 2, 1};
////    int n = 5;
////    printf("\na[0] * b[0] + a[1]*b[1]+...+a[n-1]*b[n-1]的结果：%0.2f", inner_product(a, b, n));
//
//    //课后练习题13:
//    //课后练习题14:
////    int a[] = {1, 2, 0, 3};
////    int n = 4;
////    printf("\n return value is: %d", has_zero(a, 4))
//    //课后练习题17:将fact函数改为不递归
//    //int n = 10;
////    printf("\n return value is: %d", fact_rewrite(10));
//    //课后练习题19:思考神秘的函数：
//    int n;
//    printf("Enter an integer to be translated to binary: ");
//    scanf("%d", &n);
//    pb(n);
//    printf("\n");
//
//
//return 0;
//}
//
//
///**
// * 课后练习题02:
// * 编写函数check(x,y,n):如果x和y都落在0~n-1的闭区间，那么函数返回1；否则函数返回0.假设x、y和n都是int类型.
// * @param x
// * @param y
// * @param n
// * @return
// */
//int check(int x, int y, int n) {
//    return (0 <= x && x <= n) && (0 <= y && y <= n) ? 1 : 0;
//
//}
//
//
///**
// * 课后练习题3:
// * 编写程序，要求输入两个整数，然后计算并显示这两个整数的最大公约数(GCD)：
// * Enter two integers: 12 34
// * Greatest common divisor: 4
// * 求最大公约数的经典算法是Euclid算法:分别让变量m和变量n存储两个数的值。如果n为0，那么停止操作，m中的
// * 值是GCD;否则计算m除以n的余数，把n保存到m中，并把余数保存到n中。然后重复上述过程，每次都先判定n是否为0
// * @param m
// * @param n
// * @return
// */
//
//int gcd(int m, int n) {
//    int r;
//    while (n != 0) {
//        r = m % n;
//        m = n;
//        n = r;
//    }
//    return m;
//}
//
///**
// * 课后练习题编程04:编写函数day_of_year(month,day,year),使得函数返回由这三个参数确定的那一天
// * 是一年中的第几天(1~366范围内的整数).
// * @param month
// * @param day
// * @param year
// * @return
// */
//
//int day_of_year(int month, int day, int year) {
//    int day_of_year;
//    int february_day = is_leap_year(year);
//
//    switch (month) {
//        case 1:
//            day_of_year = day;
//            break;
//        case 2:
//            day_of_year = 31 + day;
//            break;
//        case 3:
//            day_of_year = 31 + february_day + day;
//            break;
//        case 4:
//            day_of_year = 31 * 2 + february_day + day;
//            break;
//        case 5:
//            day_of_year = 31 * 2 + february_day + 30 + day;
//            break;
//        case 6:
//            day_of_year = 31 * 3 + february_day + 30 + day;
//            break;
//        case 7:
//            day_of_year = 31 * 3 + february_day + 30 * 2 + day;
//            break;
//
//        case 8:
//            day_of_year = 31 * 4 + february_day + 30 * 2 + day;
//            break;
//        case 9:
//            day_of_year = 31 * 5 + february_day + 30 * 2 + day;
//            break;
//        case 10:
//            day_of_year = 31 * 5 + february_day + 30 * 3 + day;
//            break;
//        case 11:
//            day_of_year = 31 * 6 + february_day + 30 * 3 + day;
//            break;
//        case 12:
//            day_of_year = 31 * 6 + february_day + 30 * 4 + day;
//            break;
//
//    }
//    return day_of_year;
//
//}
//
//int is_leap_year(int year) {
//    int february_day;
//    if (year % 400 == 0 || year % 4 == 0)
//        february_day = 29;
//    else
//        february_day = 28;
//    return february_day;
//}
//
///**
// * 对day_of_year方法的优化
// * 注意学习理解这些处理技巧,可以让代码更简洁，更高效
// * @return
// */
//int day_of_year_optimize(int month, int day, int year) {
//    int i;
//
//    for (i = 1; i < month; i++) {
//
//        switch (i) {
//            case 1:
//            case 3:
//            case 5:
//            case 7:
//            case 8:
//            case 10:
//            case 12:
//                day += 31;
//                break;  //注意这里的处理技巧
//            case 4:
//            case 6:
//            case 9:
//            case 11:
//                day += 30;
//                break;
//            case 2:
//                if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) //自己写的方法少了一个判断条件
//                    day += 29;
//                else
//                    day += 28;  //注意使用了for循环语句，switch语句最后不用使用break
//        }
//    }
//    return day;
//
//}
//
///**
// * 课后练习题5:编写函数num_digits(n),使得函数返回正整数n中数字的个数：
// * 提示：为了确定n中数字的个数，把这个数反复除以10，当n达到0时，出发运算的次数表明了n最初拥有的数字的个数。
// * @param n
// * @return
// */
//
//int num_digits(int n) {
//    int count = 0;
//    if (n == 0)
//        count = 1;
//    while (n > 0) {
//        n /= 10;
//        count++;
//    }
//    return count;
//}
//
///**
// * 课后练习题06:编写函数digit(n,k);使得函数返回正整数n中的第k位数字(从右边算起)。例如，
// * digit(829,1)返回9，digit(829,2)返回2.如果k大于n所含有的数字的个数，那么函数返回0.
// * @param n
// * @param k
// * @return
// */
//int digit_01(int n, int k) {
//
//    /**
//     * 实现方法一：该方法实现起来比较繁琐
//     */
//    //这里是从右开始向左取
//    int count = 0;
//    int temp = n; //这里要用把n的值给temp，不能直接在while循环语句中直接使用n，否则n的值就重新赋值为0了
//    //统计整数n有几位数
//    while (temp > 0) {
//        temp /= 10; //这里要用temp不能使用n
//        //if (count == k)
//        //   return n % 10;
//        count++;
//
//    }
//    // Check if k is greater than the number of digits in n
//    if (count < k)
//        return 0;
//
//    //提取n中的第k个数字
//    for (int i = 1; i <= k; i++) {
//        int digit = n % 10; //提取n中第几位的数字可以使用取余数
//        n /= 10;  //统计n中有多少位可以除以统计被初次数，只要商不等于0
//
//        if (i == k) {
//            return digit;
//        }
//    }
//
//}
//
///**
// * 实现方法二：借助ChatGPT
// * @param n
// * @param k
// * @return
// */
//int digit_02(int n, int k) {
//    int count = 0;
//    // Loop until kth digit or n becomes 0
//    while (count < k && n > 0) { //方法比较灵活只根据要获取第k位的数据，很多时候不需要全部循环遍历完整
//        int lastDigit = n % 10; // Extract the last digit
//        count++;   // Increment the count
//        if (count == k)
//            return lastDigit;  // Return the kth digit
//        n /= 10;  // Remove the last digit
//    }
//    return 0;  // k is greater than the number of digits in n
//
//}
//
///**
// * 实现方法三：借助ChatGPT,该方法最简洁
// * @param n
// * @param k
// * @return
// */
//int digit_03(int n, int k) {
//    int count = 0;
//    while (n > 0) {
//        count++;
//        if (count == k)
//            return n % 10;
//        n /= 10; // Remove the last digit
//    }
//    return 0; // k is greater than the number of digits in n
//}
//
///**
// * 课后编程练习10:编写函数，使得函数返回下列值(假设a和n是形式参数，其中a是int类型数组，n是数组的长度)
// * 1.数组a中最大的元素；
// * 2.数组a中所有元素的平均值；
// * 3.数组a中正数元素的数量.
// * @param a
// * @param n
// * @return
// */
//int test_exec10(int a[], int n) {
//    //1.求数组a中最大的元素
////    int max;
////    for (int i = 0; i < n; ++i) {
////        if (a[i] > a[i + 1]) {
////            max = a[i];
////            a[i] = a[i + 1];
////            a[i + 1] = max;
////        }
////
////    }
////    return max;
//
//    //2.数组a中所有元素的平均值
////    int sum;
////    for (int i = 0; i < n; ++i) {
////        sum += a[i];
////    }
////    return (float) sum / n;
//    //3.数组a中正数元素的数量.
//    int count = 0;
//    for (int i = 0; i < n; ++i)
//        if (a[i] > 0)
//            count++;
//    return count;
//
//
//}
//
///**
// * 课后练习题11:编写下面的函数：
// * float compute_GPA(char grades[],int n)
// * 其中grades数组包含字母等级(A、B、C、D或F,大小写皆可)，n是数组的长度。函数应返回等级平均值(A=4,B=3,C=2,D=1,F=0)
// * @param grades
// * @param n
// * @return
// */
//float compute_GPA(char grades[], int n) {
//    float sum = 0;
//    for (int i = 0; i < n; ++i) {
//        switch (grades[i]) {
//            case 'A':
//            case 'a':
//                sum += 4;
//                break;
//            case 'B':
//            case 'b':
//                sum += 3;
//                break;
//            case 'C':
//            case 'c':
//                sum += 2;
//                break;
//            case 'D':
//            case 'd':
//                sum += 1;
//                break;
//            case 'F':
//            case 'f':
//                sum += 0;
//                break;
//
//        }
//
//    }
//    return sum / n;
//
//
//}
//
//
///**
// * 课后练习题12：编写下面的函数
// * double inner_product(double a[],double b[],int n)
// * 返回a[0] * b[0] + a[1]*b[1]+...+a[n-1]*b[n-1].
// *
// * @param a
// * @param b
// * @param n
// * @return
// */
//double inner_product(double a[], double b[], int n) {
//    double sum;
//    for (int i = 0; i < n; ++i) {
//        sum += a[i] * b[i];
//
//    }
//    return sum;
//
//}
//
//
///**
// * 课后练习题13:编写下面的函数，对棋盘位置求值
// * board表示棋盘上方格的位置，其中字母K、Q、R、B、N、P表示白色的方格，字母k、q、r、b、n、p表示黑色的方格.
// * evaluate_position应计算出白色方格的和(Q=9,R=5,B=3,N=3,P=1),并按类似的方法计算出黑色的方格的和，然后返回
// * 这两个数的差。如果白子占优则返回值为正数，如果黑子占优则返回值为负数。
// * @param board
// * @return
// */
//int evaluate_position(char board[8][8]) {
//    int withe_sum, black_sum;
//    for (int i = 0; i < 8; ++i) {
//        for (int j = 0; j < 8; ++j) {
//            switch (board[i][j]) {
//                case 'Q':
//                    withe_sum += 9;
//                    break;
//                case 'q':
//                    black_sum += 9;
//                    break;
//                case 'R':
//                    withe_sum += 5;
//                    break;
//                case 'r':
//                    black_sum += 5;
//                    break;
//                case 'B':
//                    withe_sum += 3;
//                    break;
//                case 'b':
//                    black_sum += 3;
//                    break;
//                case 'N':
//                    withe_sum += 3;
//                    break;
//                case 'n':
//                    black_sum += 3;
//                    break;
//                case 'P':
//                    withe_sum++;
//                    break;
//                case 'p':
//                    black_sum++;
//                    break;
//                default:
//                    break;
//
//            }
//        }
//    }
//
//    return withe_sum - black_sum;
//
//
//}
//
///**
// * 课后练习题14:如果数组a任一元素的值为0，那么下列函数返回true;如果数组a的所有元素都是非零的，则函数
// * 返回false。可惜的是，次函数有误。请找出错误并且说明修改它的方法。
// * @param a
// * @param n
// * @return
// */
//bool has_zero(int a[], int n) {
//    /*  int i;
//      bool flag = false; //加一个符号位置
//      for (i = 0; i < n; i++) {
//          if (a[i] == 0)
//              return flag = true;
//  //        else
//  //            return false;   这个地方写法有误
//
//      }
//      return flag;*/
//    //上面写法代码重复不够简洁
//    int i;
//    for (i = 0; i < n; i++) {
//        if (a[i] == 0)
//            return true;
//    }
//    return false;
//
//}
//
///**
// * 课后练习题15:下面这个(相当混乱的)函数找出三个数的中间数。重新编写函数，使得它只有一条return语句。
// * @param x
// * @param y
// * @param z
// * @return
// */
//double median(double x, double y, double z) {
//    //1.题目最初的代码：
//    /* if (x <= y)
//         if (y <= z) return y;
//         else if (x <= z) return z;
//         else return x;
//     if (z <= y) return y;
//     if (x <= z) return x;
//     return z;*/
//
//    //2.修改后的代码
//    double middle = x;
//    if ((x >= y && z <= y) || (z >= y && x <= y))
//        middle = y;
//    else if ((x >= z && y <= z) || (y >= z && x <= z))
//        middle = z;
//    return middle;
//}
//
//
///**
// * 课后练习题17.请重写fact函数，使得编写后的函数不再有递归
// * */
//int fact_rewrite(int n) {
//    int result = 1;
//    while (n-- > 1)
//        result *= n;
//    return result;
//}
//
//
///**
// * 课后练习题18:编写递归版本的gcd函数。下面是用于计算gcd(m,n)的策略：如果n为0，那么返回m；否则，递归地调用gcd函数，
// * 把n作为第一个实际参数进行传递，而把m%n作为第二个实际参数进行传递.
// * @param m
// * @param n
// * @return
// */
//
//int recursion_gcd(int m, int n) {
//    return n == 0 ? m : gcd(n, m % n);
//
//}
//
///**
// * 课后练习题19:思考下面这个“神秘”的函数：
// * 手动跟踪函数的执行，然后编写程序调用此函数，把用户输入的数传递给次函数。函数做了什么？
// * @param n
// */
//void pb(int n) {
//    if (n != 0) {
//        pb(n / 2);
//        putchar('0' + n % 2);
//
//    }
//}
//
//
