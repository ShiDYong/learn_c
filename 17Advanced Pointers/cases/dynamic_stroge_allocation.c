/********************************************************************************
* @author: mason shi
* @date: 2023/8/19 16:21
* @version: 1.0
* @description:第十七章：指针的高级运用
 * 已学过的指针运用：第11章说明了如何利用指向变量的指针作为函数的参数，从而允许函数修改该变量；第12章说明了如何对
 * 指向数组元素的指针进行算术运算来处理数组；本章主要介绍指针的另外重要运用：动态存储分配和指向函数的指针
 *
 *
********************************************************************************/
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

void dynamic_storage_allocation();

void dynamically_allocated_strings();

char *concat(const char *s1, const char *s2);

int main(void) {
    //  dynamic_storage_allocation();
    //  dynamically_allocated_strings();
    //char str1[]="Hello",str2[]="World!";
    //printf("拼接成功的新字符串：%s.\n", concat(str1,str2));
    //更简单的方式
    concat("abc", "def");
    printf("拼接成功的新字符串：%s.\n",  concat("abc","def"));



}

/**
 * 17.1 动态分配存储
 *   C语言支持动态存储分配，即在程序运行期间分配内存单元的能力。利用动态存储分配，可以设计出能根据需要扩大或
 *   缩小的数据结构。虽然动态存储分配适用于所有类型的数据，但主要是用于字符串、数组和结构。动态存储分配的结构
 *   是特别有趣的，因为可以把它们链接形成表、树或其他数据结构。
 */
void dynamic_storage_allocation() {
    /*17.1.1: 内存分配的函数：
     * 为了动态地分配存储空间，需要调用三种内存分配函数的一种，这些函数声明在<stdlib.h>头中的。
     * 1.malloc函数——分配内存块，但是不对内存进行初始化。
     * 2.calloc函数——分配内存块，并且对内存块进行清零。
     * 3.realloc函数——调整先前分配的内存块大小
     * 在三种函数中，malloc函数是最常用的一种。因为malloc不需要对分配的内存块进行清零，所以它比calloc函数更高效.
         * malloc函数的原型：
         * void *malloc(size_t size);
         * 关键点1:  size是要分配的字节数，函数返回一个void *类型的指针，指向分配的内存块的开头。
         * 需要注意的是，malloc分配的内存没有初始化，这意味着内存块的内容是未指定的，并且可能包含垃圾值。
         * 关键点2:  当为申请内存块而调用分配函数时，因为函数无法知道计划存储在内存块中的数据是什么类型的，所以它
         * 不能返回int类型、char类型等普通类型的指针。因此会返回void*类型的值。void * 类型的值总是“通用”指针，它
         * 在本质上都只是内存地址。
     * */
    //malloc函数的示例
    int *numPtr; //Declare a pointer to an integer
    numPtr = (int *) malloc(sizeof(int)); // Allocate memory for one integer
    if (numPtr == NULL) {
        printf("Memory allocation failed\n");
        return;
    }
    *numPtr = 24;// Store a value in the allocated memory
    printf("Value: %d\n", *numPtr);
    free(numPtr); // Release the allocated memory

    /*17.1.2 空指针
     * 当调用内存时，出现找不到我们需要的足够大的内存块，函数会返回空指针(null pointer)。空指针是“不指向任何地方
     * 的指针”，这是一个区别于所有有效指针的特殊值。在把函数的返回值存储到指针变量中后，需要判断该指针变量是否为空指针
     * */
    //在C语言中，指针测试真假的方法和数的测试一样，所有非空指针都为真，而只有空指针为假，因此可以用下列方式：
    // if(p == NULL)...
    //if(!p)...
    //而语句：if(p!=NULL)...
    //则可以写成：if(p)...,不过在书写风格上，一般倾向与NULL进行显示比较


    /*17.4 释放存储空间
     * malloc函数和其他内存分配函数所获得的内存块都来自一个叫做堆(heap)的存储池。过于频繁地调用这些函数(或者让这些函数申请大内存块)可能
     * 会耗尽堆，这会导致函数返回空指针。更糟糕的是，程序可能分配了内存块，然后又丢失了对这些块的记录，因而浪费了空间。
     * 对程序而言，不可再访问到的内存块被称作垃圾(garbage)。留有垃圾袋的程序存在内存泄漏(memory leak)现象。
     * 一些语言提供了垃圾收集器(garbage collector)用于垃圾的自动定位和回收，但是C语言不提供。相反，每个C程序负责回收各自
     * 的垃圾，方法是调用free函数来释放不需要的内存。
     * free函数的原型如下：
     * void free(void *ptr);
     * 使用free函数会释放p所指向的内存块。然后此内存块可以被后续的malloc函数或其他内存分配函数的调用重试使用。
     * free函数的实际参数必须是先前由内存分配函数返回的指针。如果参数是指向其他对象(比如变量或者数组元素)的指针，
     * 可能会导致未定义的行为。
     *
     *======悬空指针问题：======
     * 虽然free函数允许收回不再需要的内存，但是使用此函数会导致一个新的问题：悬空指针。调用free(p)函数会释放p指向的
     * 内存块，但是不会改变p本身。如果忘记了p不再指向有效的内存块，试图修改释放的内存块可能引起程序奔溃等损失惨重的后果。
     * */
    char *p = malloc(4);
    free(p);
    // strcpy(p,"abc");//试图修改释放的内存块可能引起程序奔溃等损失惨重的后果
    // printf("试图修改释放的内存块可能引起程序奔溃等损失惨重的后果 %s.\n",*p);//EXC_BAD_ACCESS (code=1, address=0x60)



    /*
     * calloc函数的原型如下：
     * void *calloc(size_t num_elements, size_t element_size);
     *      1. num_elements: The number of elements you want to allocate memory for.
            2. element_size: The size (in bytes) of each element.
            3. The calloc function allocates a block of memory large enough to hold num_elements elements,
            each of size element_size, and initializes all the bytes to zero. It returns a pointer to the
            first byte of the allocated memory block. If the allocation fails, it returns NULL.
     * */
    //calloc函数的使用示例
    int num_element = 5;
    int element_size = sizeof(int);
    // 为5个元素的数组分配内存空间，其中每个元素的长度都是4个字节(int类型),如果要求的空间无效，那么此函数返回空指针。
    int *array = (int *) calloc(num_element, element_size);
    if (array != NULL) {
        // 分配了内存后，会把所有位设置为0的方式进行初始化。
        for (int i = 0; i < num_element; i++)
            printf("%d", array[i]);// This will print "0 0 0 0 0 "
        // Don't forget to free the allocated memory when done using it
        free(array);
    } else
        printf("Memory allocation failed.\n");

    /*
     * realloc函数原型如下：可以调整数组的大小使它更合适需要。
     * void *realloc(void *ptr, size_t new_size);
          1.ptr is a pointer to the previously allocated memory block;
          2.and new_size is the new size you want to allocate;
          当调用realloc函数时，ptr必须指向先前通过malloc、calloc或realloc的调用获得的内存块。size表示内存块的新尺寸。
          新尺寸可能会大于或小于原有尺寸。
          C标准列出了几条关于realloc函数的规则：
          1.当扩展内存块时，realloc函数不会对添加进的内存块的字节进行初始化。
          2.如果realloc函数不能按照要求扩大内存块，要么它会返回空指针，并且在原有的内存块中的数据不会发生改变。
          3.如果realloc函数被调用时以空指针作为第一个实际参数，那么它的行为就像malloc函数一样。
          4.如果realloc函数被调用时以0作为第二个实际参数，那么它会被释放内存块。
          具体：
          1.当要求减少内存块大小时，realloc函数应该“在原先的内存块上”直接进行缩减，而不需要移动存储在内存块中的数据。
          2.同理，扩大内存时也不应该对其进行移动。如果无法扩大内存块(因为内存块后边的字节已经用于其他的目的)，realloc函数会在
          别处分配新的内存块，然后把就旧块中的内容复制到新块中。
     * */
    //下面是realloc函数的使用示例：
    int *arr;
    int old_size = 5;
    int new_size = 6;
    // Allocate memory for an array of 5 integers
    arr = (int *) malloc(old_size * sizeof(int));

    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return;
    }

    // Initialize the array
    for (int i = 0; i < old_size; i++) {
        arr[i] = i;
    }

    // Reallocate memory for an array of 10 integers
    arr = (int *) realloc(arr, new_size * sizeof(int));

    if (arr == NULL) {
        printf("Memory reallocation failed.\n");
        return;
    }

    // Print the contents of the expanded array
    for (int i = 0; i < new_size; i++) {
        printf("%d ", arr[i]);
    }
    // Don't forget to free the allocated memory when done using it
    free(arr);

}

/**
 * 17.2.1 动态分配字符串
 * 动态内存分配对字符串操作非常有用。字符串存储在字符数组中，而且可能很难预测浙西数组需要的长度。通过动态分配字符串，可以推迟到
 * 程序运行时才做决定。
 */
void dynamically_allocated_strings() {
    /*用malloc函数为字符串分配内存是很容易的，因为C保证char类型值恰好需要1字节的内存(换句话说，sizeof(char)的值是1)。
     * 为个n个字符的字符串分配内存空间，可以写成下面方式：
     * */
    char *p;
    int n = 5;
    // p = malloc(n+1);//实际参数是n+1而不是n，这就给了空字符串留出了空间。在执行赋值操作时会把malloc函数返回的通用指针转换为char*类型
    //，而不需要强制类型转换，然而处于书写的习惯会对函数返回值进行强制类型转换
    p = (char *) malloc(n + 1);//⚠️：当使用malloc函数为字符串分配内存空间时，不要忘记包含字符的空间

    //对上述数组进行初始化的一种方法时调用strcpy函数：因为malloc函数分配的内存不需要清零或任何方式进行初始化
    strcpy(p, "abc");
    printf("动态分配字符串初始化的内容: %s.\n", p);

}

/**
 * 字符串函数中使用动态分配存储：
 * 动态存储分配使编写返回指向“新“字符串的指针的函数成为可能，所谓新字符串时指在调用此函数之前字符串并不存在。
 * 也就是把两个字符串链接起来而不改变其中任何一个字符串。这样在C标准库是没有包含此类函数，下面是自行编写的案例
 * @param s1
 * @param s2
 * @return
 */
char *concat(const char *s1, const char *s2) {
    char *result;
    //使用malloc函数为结果分配适当大小的内存空间
    result = malloc(strlen(s1) + strlen(s2) + 1);
    //判断是否成功分配内存
    if (result == NULL) {
        printf("Error: malloc failed in concat\n");
        exit(EXIT_FAILURE);
    }
    //第一个字符串复制到新的内存空间中
    strcpy(result, s1);
    //调用strcat函数来拼接第二个字符串
    strcat(strcat(result, " "), s2); //加上 Hello World! 的中间空格
    //这里好像无法释放内存
    return result;


}