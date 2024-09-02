/********************************************************************************
* @author: mason shi
* @date: 2023/7/8 11:41
* @version: 1.0
* @description: 第十二章：指针和数组的课后练习题
********************************************************************************/
#include<stdio.h>
#include<stdbool.h>
#include<time.h>
#include<stdlib.h>
#include <stddef.h>
#include <string.h>

#define N 10
#define LEN 24

void exec12_01();

void exec12_02();

void reverseArray(int arr[], int size);

void printArray(const char *label, const int arr[], int size);

void test_reverse_array();

void exec12_05();

bool exec12_07_search(const int a[], int n, int key);

void exec12_08_store_zeros(int a[], int n);

double exec12_09_inner_product(const double *a, const double *b, int n);

int exec12_11_find_largest(int a[], int n);


int exec12_06_sum_array(const int a[], int n);

int *exec12_10_find_middle(int a[], int n);

void exec12_12_find_two_largest(const int *a, int n, int *largest, int *second_largest);

bool exec12_14_search(const int a[], int n, int key);

float temp_number();

void initialize_number_generator(void);

void exec12_15_print_cows(const int a[], int n);

float exec12_16_find_highest_temp(const int a[], int n);

int sum_two_dimensional_array(const int a[][LEN], int n);

int main(void) {

    //测试数组的反转
    test_reverse_array();
    return 0;

    //课后练习14题目
//    int rows = 7, clos = 24, key = 8, n = 7 * 24;
//    int temperatures[rows][clos];
//    int i, j;
//    for (i = 0; i < rows; i++) {
//        for (j = 0; j < clos; j++)
//            temperatures[i][j] = temp_number();/*通过随机数给二维数组赋值*/
//    }
//    int k, count = 0;
//    bool has32 = false;
//    while (k < rows) { //对于二维数组的遍历求值，可将二维数组拆分多个一位数组，然后调用一纬数组的方法
//        int *rowPtr = temperatures[k]; /*Get a pointer to the current row*/
//        // Search for the target value in the current row using the search function
//        k++;
//        if (exec12_14_search(rowPtr, n, key)) {
//            printf("Value 32 found at temperatures.\n");
//            //只要出现一次就停止循环
//            //return;
//            //对应出现多次情况，避免打印混乱
//            count++;
//        }
//
//    }
//    if (!has32 && count == 0) {
//        printf("Value 32 not found in the temperatures array.\n");
//    }

    //课后练习题15-16题目实现;
    /* while (k < rows) {
         int *rowPtr = temperatures[k];
         // exec12_15_print_cows(rowPtr, clos);
         float largest = exec12_16_find_highest_temp(rowPtr, clos);
         k++;
         printf("星期%d当天最高温度是%0.2f.\n", k, largest);
     }*/

    //课后练习题17的使用
//    int sum = sum_two_dimensional_array(temperatures, rows);
//    printf("二维数组的求和方法的结果: %d\n", sum);


}

/**
 * 产生随机数
 */
void initialize_number_generator(void) {
    srand((unsigned) time(NULL));

}

float temp_number() {
    //随机产生一个1～50度范围的数字
    return rand() % 50 + 1;
}


/**
 * Exercise 12.01
Suppose that the following declarations are in effect:
int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
int *p = &a[1], *q = &a[5];
(a) What is the value of `*(p+3)`?
(b) What is the value of `*(q-3)`?
(c) What is the value of `q - p`?
(d) Is the condition `p < q` true or false?
(e) Is the condition `*p < *q` true or false?
 */
void exec12_01() {
    int a[] = {5, 15, 34, 54, 14, 2, 52, 72};
    int *p = &a[1], *q = &a[5];
    //p = &a[1] => p 指向 a[1] (值为 15)
    //q = &a[5] => q 指向 a[5] (值为 2)
    //1.*(p+3)的值是多少？
    printf("%d\n", *(p + 3)); //*(p + 3) = a[4] = 14

    //2.*(q-3)的值是多少？
    printf("%d\n", *(q - 3)); //q 指向 a[5]，q - 3 指向 a[2]=34


    //3.q-p的值是多少？
    printf("%d\n", q - p);//q 指向 a[5]，p 指向 a[1]，所以 q - p 是这两个指针之间的元素差：q - p = (5 - 1) = 4

    //4.p<q的结果是真还是假？ true
    if (p < q) //p 指向 a[1]，q 指向 a[5]，所以 p 小于 q：

        printf("true\n");
    //5.*p<*q的结果是真还是假？false
    if (*p < *q) //*p 的值是 15，*q 的值是 2，所以 *p 不小于 *q：

        printf("true\n");


}

/**
Exercise 12.02
Suppose that `high`, `low` and `middle` are all pointer variables of the same
type, and that `low` and `high` point to elements of an array. What is the
following statement illegal, and how could it be fixed?
```c
middle = (low + high) / 2;
 */
void exec12_02() {
    /*
     * 分析：
     * 1.在C语言中，low 和 high 是指向数组元素的指针。这意味着 low 和 high 不是普通的整数，而是地址值。
       2.指针的加法操作 (low + high) 是不被允许的，因为指针加法仅限于将指针与整数相加，以得到新的指针位置，而不是指针与另一个指针进行加法。
       3.指针与指针之间的除法 ((low + high) / 2) 也是不合法的。你不能直接对两个指针进行数学运算或比较。指针运算主要包括加法、减法和比较（例如 low < high）
       正确计算中间位置：
       两个指针 low 和 high，它们指向同一个数组的不同元素，你可以按照以下步骤计算它们之间的中间位置：
       1.计算距离：使用指针减法（high - low）来计算两个指针之间的元素数量。
       2.计算中间位置：将距离除以 2，得到中间位置的偏移量。
       3.更新中间指针：用 low 指针加上这个偏移量，得到中间位置的指针
     */
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *low = &array[2];   // 指向 array[2]，值为 3
    int *high = &array[7];  // 指向 array[7]，值为 8
    int *middle;
    // 计算中间位置的指针
    ptrdiff_t distance = high - low;      // 计算 low 和 high 之间的元素数量
    middle = low + (distance / 2);        // 计算中间位置

    // 打印结果
    printf("low points to: %d\n", *low);
    printf("high points to: %d\n", *high);
    printf("middle points to: %d\n", *middle);  // 应该输出 array[4] 的值，即 5

}


/**
 *  Exercise 12.03
    What will be the contents of the `a` array after the following statements are
    executed?
    ```c
    #define N 10
    int a[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = &a[0], *q = &a[N-1], temp;
    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;
    }
 */
void reverseArray(int arr[], int size) {
    if (size <= 1) return; //如果数组为空或只有一个元素，则无需反转
    int *p = &arr[0], *q = &arr[N - 1], temp;
    while (p < q) {
        temp = *p;
        *p++ = *q;
        *q-- = temp;  //实现数组逆序
    }
//通过数组下标的方式：当数组长度为奇数时，中间的元素不会被交换。在这个特定的实现中，这不是一个问题，因为反转操作仍然正确
//    for (int i = 0; i < size / 2; i++) {
//      int tmp = arr[i];
//      arr[i] = arr[N-1-i];
//      arr[N-1-i] = temp;
//    }

}

/*
 * 打印数组
 */
void printArray(const char *label, const int arr[], int size) {
    //打印反转后的数组
    printf("%s", label);
    for (int i = 0; i < size; i++)
        printf(" %d", arr[i]);
    printf("\n");
}

/*
 * 测试打印数组的测试用例
 */
void test_reverse_array() {
    //正常情况测试
    int normal[N] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    reverseArray(normal, N);
    printArray("Normal case: ", normal, N);

    //边界值测试-单个元素的数组
    int singleElement[1] = {40};
    reverseArray(singleElement, 1);
    printArray("Single element array: ", singleElement, 1);

    //边界值cesium - 空数组
    int empty[0];
    reverseArray(empty, 0);
    printArray("Empty array: ", empty, 0);
    //特殊值测试-相同元素的数组
    int sameElements[N];
    memset(sameElements, 1, sizeof(sameElements)); //填充数组全为1
    reverseArray(sameElements, N);
    printArray("Same elements array: ", sameElements, N);


}

/**
 * 课后练习题05:假设a是一维数组而p是指针变量。如果刚执行了赋值操作p=a,下列哪些表达式会因为类型不匹配而不合法？其他的表达式中哪些为真？(有非零值)
 */
void exec12_05() {
    int a[0], *p;
    p = a;
    //1.p==a[0] false
    if (p == a[0]) //非法的
        printf("p == a[0] istrue\n");
    printf("p = %p\n", p); //是内存地址
    printf("a[0] = %d\n", a[0]); //元素
    //2.p==&a[0] true
    if (p == &a[0])
        printf("p == &a[0] is true\n");


    //3.*p==a[0] true
    if (*p == a[0])
        printf("*p == a[0] is true\n");

    //4.p[0]==a[0] 用指针也可以作为数组名,所以是true
    if (p[0] == a[0])
        printf("p[0] == a[0] true\n");


}


/**
 * 课后练习题06:用指针算术运算符代替数组下标来重写下面的函数。(换句话说，消除变量i和所有用[]运算符的地方。)
 * 要求改动尽可能减少。
 */
int exec12_06_sum_array(const int a[], int n) {
//    int i, sum = 0;
//    for (i = 0; i < n; i++)
//        sum += a[i];
//    return sum;

    //下面使用指针算术运算符进行改造
    int sum = 0, *p;
    for (p = a; p < a + N - 1; p++)
        sum += *p;
    //第二种写法
    for (p = &a[0]; p < &a[n]; p++)
        sum += *p;

    return sum;

}

/**
 Exercise 12.07
Write the following function:
```c
bool search(const int a[], int n, int key);
`a` is an array to be searched, `n` is the number of elements in the array, and
`key` is the search key. `search` should return `true` if `key` matches some
element of `a`, and `false` if it doesn't. Use pointer arithmetic -- not
subscripting -- to visit array elements.
 */
bool exec12_07_search(const int a[], int n, int key) {
    bool flag = false;
    const int *p;
    for (p = a; p < a + n; p++)
        if (*p == key)
            flag = true;
    return flag;


    //使用while进行实现
//    const int *q = a;
// This means q is a pointer to a const int. You can change the pointer
//  q itself to point to different addresses, but you cannot change the value of the int that p points to
//    const int *end = a + n;
//    while (q < end){
//        if(*q == key) return true;
//        q++;
//    }
//    return false;
}


/**
 Exercise 12.08
Rewrite the following function to use pointer arithmetic instead of array
subscripting. (In other words, eliminate the variable `i` and all uses of the
`[]` operator.) Make as few changes as possible.
```c
void store_zeros(int a[], int n)
{
    int i;

    for (i = 0; i < n; i++)
        a[i] = 0;
}
 */
void exec12_08_store_zeros(int a[], int n) {
//    int i;
//    for (i = 0; i < n; i++)
//        a[i] = 0;
    //使用指针实现
//    int *p;
//    for (p = a; p < a + n; p++)
//        *p = 0;
    //使用while循环语句实现
    int *q = a;// 初始化指针p为数组a的开始位置
    /*
     * 指针与整数：指针 p 用于访问数组中的元素，它指向数组中的具体地址。而 n 是一个整数，表示数组的长度。
     * 比较指针与整数是不正确的用法。也就是：指针和整数是不同类型，直接比较会导致逻辑错误
       指针算术：a + n 表示从数组 a 开始向后偏移 n 个元素的位置，即数组的结束位置（超出数组最后一个元素的下一个位置）。
       所以，比较 p 和 a + n 是有意义的，确保指针在数组范围内移动
     */
    int const *end = a + n;
    while (q < end) { //当指针p小于数组a的结束位置时继续循环
        *q = 0;
        q++;
    }

}

/**
 Exercise 12.09
Write the following function:
```c
double inner_product(const double *a, const double *b, int n);
`a` and `b` both point to arrays of length `n`. The function should return
`a[0] * b[0] + a[1] * b[1] +` ... `+ a[n-1] * b[n-1]`. Use pointer arithmetic --
not subscripting -- to visit array elements.
 * @param a
 * @param b
 * @return
 */
/*double exec12_09_inner_product(const double *a, const double *b, int n) {
    double result = 0.0;
//    const double *pa = a; // 指针 pa 遍历数组 a
//    const double *pb = b; // 指针 pb 遍历数组 b
//
//    for (int i = 0; i < n; i++) {
//        result += (*pa) * (*pb);
//        pa++; // 移动到下一个元素
//        pb++; // 移动到下一个元素
//    }

    //for循环还可以这样写

    // 使用 for 循环遍历数组
    for (const double *pa = a, *pb = b; pa < a + n; pa++, pb++) {
        result += (*pa) * (*pb); // 计算当前元素的乘积并加到结果中
    }


    //这种写法是正确的，但略显简洁且有些风险，因为在循环中 i 从 0 开始，
    // 在 i++ < n 中 i 增加到 n 之后退出。
    // 可能会导致不必要的循环步骤，但在这个特定场景下，代码逻辑是可以接受的
//    int e = 0;
//    while (e++ < n)
//        sum += *a++ * *b++;
//    return sum;
    //while循环语句更加简单实现：
    while (n--) {
        sum += *a++ * *b++;
    }

    return sum;

}*/


/**
 * 课后练习题10:
 * 修改11.5节的find_middle函数，用指针算术运算符计算返回值
 * @param a
 * @param n
 * @return
 */
int *exec12_10_find_middle(int a[], int n) {
    //原来处理方式：return &a[n/2];
    return a + n / 2;
}


/**
 * 修改find_largest函数，用指针算术运算(而不是取下标)来访问数组元素.
 * @param a
 * @param n
 */
int exec12_11_find_largest(int a[], int n) {
    int *p = a;
    int largest = *p++;
    while (p++ < a + n) {
        if (*p > largest) {
            largest = *p;
        }
    }
}

/**
 * 课后练习题12:编写下面函数
 * a指向长度为n的数组。函数从数组中找出最大和第二大的元素，并把它们分别存储到由largest和second_largest指向的
 * 变量中。要求使用指针算术运算而不是取下标来访问数组元素。
 * @param a
 * @param n
 * @param largest
 * @param second_largest
 */
void exec12_12_find_two_largest(const int *a, int n, int *largest, int *second_largest) {
//     int *p;
//    *largest = *p;
//    *second_largest = *p++;
//    for (p = a; p < a + n; p++) {
//        if (*p > *largest) {
//            *second_largest = *largest;
//            *largest = *p;
//        }
//        if (*p > *second_largest && *p != *largest)
//            *second_largest = *p;
//    }
    //第二种写法
    const int *p = a;
    *largest = *second_largest = *a;
    while (p++ > a++) {
        if (*p > *largest) {
            *second_largest = *largest;
            *largest = *p;
        } else if (*p > *second_largest)
            *second_largest = *p;
    }
}

/**
 * 课后练习题13:
 * 8.2节有一个代码用两个嵌套的for循环初始化用作单位矩阵的数组ident。请重写编写这段代码，采用一个指针来逐个访问数组中的元素
 * ，且每次迭代一个元素。提示：因为不能用row和col来索引变量，所以不会很容易直到应该在哪里存储1.但是，可以利用数组的下列的事实：第一个
 * 元素必须是1，接着的N个元素必须是0，再接着来的元素是1，以此类推。用变量来记录已经存储的连续的0的数量。当计数大到N时，就是存储1的时候了。
 */
void exec12_13_two_dimensional_array(int n, double ident[n][n]) {
    double *p = ident[0];
    int zeros = 0;
    while (p++ < ident[0] + n * n) {
        if (zeros == n) {
            *p = 1;
            zeros = 0;
        } else {
            *p = 0;
            zeros++;
        }
    }
}

/**
 * 课后练习题14:
 * 假设下面的数组含有一周7天24小时的温度读数，数组的每一行是某一天的读数：
 * int temperatures[7][24];
 * 编写一条语句，使用search函数(见练习7)在整个temperatures数组中寻找值32.
 * @param a
 * @param n
 * @param key
 * @return
 */
bool exec12_14_search(const int a[], int n, int key) {
    bool flag = false;
    const int *p;
    int count = 0;
    for (p = a; p < a + N; p++) {
        count++;
        if (*p == key)
            flag = true;
    }
    return flag;


}

/**
 * 课后练习题15:
 * 编写一个循环来显示(练习题14中的)temperatures数组中第i行的存储的温度读数。利用指针来访问该行中的每个元素.
 * @param a
 * @param n
 * @param key
 * @return
 */
void exec12_15_print_cows(const int a[], int n) {
    const int *p;
    int count = 0;
    for (p = a; p < a + n; p++) {
        printf(" %d", *p);
        count++;
    }


}


/**
 * 课后练习题16:
 * 编写一个循环来显示(练习14中)temperatures数组一星期中每一天的最高温度。循环体应该调用find_largest函数。且
 * 一次传递数组的一行。
 * @param a
 * @param n
 */
float exec12_16_find_highest_temp(const int a[], int n) {
    const int *p;
    float largest = a[0];
    for (p = a; p < a + n; p++)
        if (*p > largest)
            largest = *p;
    return largest;
}

/**
 * 课后练习题17:用指针算术运算代替数组取下标来重写下面的函数(
 * 换句话说，消除变量i、j和所有用到[]运算符的地方。)要求使用单层循环而不是嵌套循环。
 * @return
 */
int sum_two_dimensional_array(const int a[][LEN], int n) {
    int i, j, sum = 0;
//    for (i = 0; i < n; i++)
//        for (j = 0; j < LEN; j++)
//            sum += a[i][j];//r求二维数组的所有和
    //下面使用指针算术运算符进行优化:非常巧妙
    const int *p = *a;
    while (p < *a + n * LEN)
        sum += *p++;

    //下面是对二维数组求和的第三种方式,比方法二来说多了变量i，但是可读性高同时可以多加其他操作
    const int *ptr = &a[0][0];// Pointer to the first element of the 2D array
    for (int h = 0; h < n * LEN; h++) {
        sum += *ptr; //Access the current element using the pointer
        ptr++;  // Move the pointer to the next element
    }

    return sum;


}

/**
 * 课后练习题17:
 * 编写第九章练习题13中的evaluate_position函数，使用指针算术运算符而不是取下标来访问数组元素。要求使用单层循环而不是嵌套循环.
 * @param board
 * @return
 */
int exec12_17_evaluate_position(char board[8][6]) {
    int sum_white = 0, sum_black = 0, i, len = 8 * 6;
    const int *p = &board[0][0];
    for (i = 0; i < len; i++) {
        /*
         * 这里的另外一种写法更加充分利用数组与指针的密切关系，更加简洁
         * char *ptr;
         * for(p=board; p<board+len;p++){
         * }
         *
         *
         * */
        switch (*p) {
            case 'Q':
                sum_white += 9;
                break;
            case 'R':
                sum_white += 5;
                break;
            case 'B':
                sum_white += 3;
                break;
            case 'N':
                sum_white += 3;
                break;
            case 'P':
                sum_white += 1;
                break;
            case 'q':
                sum_black += 9;
                break;
            case 'r':
                sum_black += 5;
                break;
            case 'b':
                sum_black += 3;
                break;
            case 'n':
                sum_black += 3;
                break;
            case 'p':
                sum_black += 1;
                break;
            default:
                break;

        }
    }
    // int result = sum_white - sum_black;
    //return result > 0 ? result : -result; 这里是多此一举
    return sum_white - sum_black;

}