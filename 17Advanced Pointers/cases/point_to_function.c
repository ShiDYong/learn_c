/********************************************************************************
* @author: mason shi
* @date: 2023/8/29 22:49
* @version: 1.0
* @description: 17.7指向函数的指针
 *              到目前为止，已经使用指针指向过各种类型的数据，包括变量、数组元素以及动态分配的内存块。但是C语言没有要求指针只能指向数据，
 *              它还允许指针指向函数。指向函数的指针(函数指针)不像人们所想象的那样奇怪。毕竟函数占用内存单元，所以每个函数都有地址，就像
 *              每个变量都有地址一样。
********************************************************************************/
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
#include <dlfcn.h>

typedef int (*OperationFunction)(int, int);

// Plugin definition
typedef int (*PluginFunction)(int);


#define PI 3.1415926

void performOperation(int a, int b, int(*callback)(int));

void func_pointer_as_argument();

double integrate(double (*f)(double), double a, double b);

int customCallback(int value);

int add(int a, int b);

int subtract(int a, int b);

int compareAscending(const void *a, const void *b);

int compareDescending(const void *a, const void *b);

/*1. Dynamic Dispatch
 * Define a Base Structure and Function Pointers:
   Start by defining a base structure that includes function pointers for the methods
   you want to dispatch dynamically. Each method corresponds to an operation or
   behavior associated with the object.*/
// Base structure
typedef struct {
    int (*add)(void *self, int a, int b);

    int (*subtract)(void *self, int a, int b);
} Object;

/*2.Dynamic Dispatch
 * Define Derived Structures and Implement Methods:Create derived structures that inherit
 * from the base structure. Implement the methods associated with each derived structure.
 * */
// Derived structures
typedef struct {
    Object base;
    int value;
} MyObject;

int myObjectAdd(void *self, int a, int b);

int myObjectSubtract(void *self, int a, int b);

/*1.Create a Plugin Interface:
         Define a clear interface that all plugins must adhere to. This includes specifying function
         prototypes and any data structures needed for communication between the application and plugins.
         For example
 */
// Plugin interface header file (plugin.h)
typedef int (*PluginFunction)(int);

// Function to initialize the plugin
void initPlugin();

// Function to perform any cleanup when unloading the plugin
void cleanupPlugin();


int main(void) {
    /*1.函数指针的常见运用之回调机制：
     *函数指针通常用于实现回调机制，其中一个函数接受另一个函数作为参数并在适当的时间调用它。这允许代码的用户自定义行为。
     * Callback Mechanisms:
     *      a callback mechanism refers to a programming technique where a function is passed as an argument to another
     *      function or registered with an event handler to be called at a later point in the program's execution. Callbacks
     *      are used to achieve flexibility and customization in the behavior of functions or to respond to events.This is
     *      commonly seen in libraries and APIs.
     Here's how callback mechanisms work in C:
     1.Function Pointers:
             The core of callback mechanisms in C is the use of function pointers. A function pointer is a variable
             that can store the memory address of a function. By passing a function pointer as an argument to another
             function, you allow that function to call the specified function at a later time.
    2.Callbacks as Arguments:
    In a callback mechanism, you define a function (the callback function) that performs a specific task.
     You then pass a pointer to this function as an argument to another function. When the other function needs to
     perform the task, it calls the callback function through the function pointer.
     * */
    performOperation(3, 4, customCallback); // Calls performOperation with customCallback

    /*2.函数指针之动态调度：
     * 函数指针用于实现函数调度表，允许您根据某些条件动态选择和执行函数
     * Dynamic Dispatch:
     *        Dynamic dispatch, also known as runtime method or function dispatch, is a mechanism in object-oriented
     *        programming that allows you to select and execute methods or functions based on the runtime type of an
     *        object. While C is not an object-oriented language, you can achieve dynamic dispatch through function
     *        pointers and structures. Here's a simplified example of how to implement dynamic dispatch in C:
     *
     * */
//    OperationFunction operations[] = {add, subtract};
//    int choice = 0;
//    int result = operations[choice](5, 3);
//    printf("Result: %d\n", result);

    /*3.Initialize Objects and Set Function Pointers
     * Initialize Objects and Set Function Pointers:Create instances of the derived structures and set
     * the function pointers to the corresponding methods.
     * */
    MyObject obj1 = {{myObjectAdd, myObjectSubtract}, 10};
    MyObject obj2 = {{myObjectAdd, myObjectSubtract}, 20};


    /*4.Perform Dynamic Dispatch:
     * Now, you can perform dynamic dispatch based on the runtime type of the object. Use the function
     * pointers to call the appropriate method.
    */
    int result1 = obj1.base.add(&obj1, 5, 3); // Calls myObjectAdd for obj1
    int result2 = obj2.base.subtract(&obj2, 8, 6); // Calls myObjectSubtract for obj2
    /*总结：
     * 在此示例中，我们使用函数指针和结构实现了动态调度的简化形式。 基本结构定义通用方法的函数指针，而派生结构继承基本
     * 结构并为这些方法提供自己的实现。与 C++ 或 Java 等语言相比，C 中的动态调度通常需要更多手动操作且表达能力较差，
     * 但它允许您实现多态行为并根据运行时信息选择方法。
     * */


    /*3.函数指针之比较函数：
     * 函数指针用于将自定义比较函数传递给排序算法，允许您以不同的方式对各种数据类型进行排序。
     * Sorting and Comparing:Function pointers can be used to customize sorting
     * and comparison algorithms.
     * */
    int numbers[] = {5, 2, 9, 1, 5};
    int n = sizeof(numbers) / sizeof(numbers[0]);

    // Sort the array in ascending order
    qsort(numbers, n, sizeof(int), compareAscending);
    printf("Ascending: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    // Sort the array in descending order
    qsort(numbers, n, sizeof(int), compareDescending);
    printf("Descending: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", numbers[i]);
    }
    printf("\n");

    /*函数指针之插件
     *函数指针可用于实现动态加载外部函数的插件系统。
     * Plugin Systems:
     *      Implementing a plugin system in C allows you to dynamically load and execute external code (plugins)
     *      in your application. This can make your application more extensible and modular. Here's a simplified
     *      example of how to create a basic plugin system in C:
     * 4.Load and Use the Plugin:
     *      In your main application, you can load the plugin dynamically using platform-specific mechanisms
     *      (e.g., dlopen on Unix-like systems). The specifics may vary depending on your platform.
     *      Here's a simplified example for Unix-like systems:
     * */

    // Load the plugin
    void *pluginHandle = dlopen("./sample_plugin.so", RTLD_LAZY);
    if (!pluginHandle) {
        fprintf(stderr, "Failed to load plugin: %s\n", dlerror());
        return 1;
    }

    // Get function pointers
    PluginFunction pluginFunction = dlsym(pluginHandle, "samplePluginFunction");
    void (*init)(void) = dlsym(pluginHandle, "initPlugin");
    void (*cleanup)(void) = dlsym(pluginHandle, "cleanupPlugin");

    // Initialize the plugin
    if (init) {
        init();
    }

    // Use the plugin function
    int result = pluginFunction(42);
    printf("Main Application: Received result from plugin: %d\n", result);

    // Clean up and unload the plugin
    if (cleanup) {
        cleanup();
    }
    dlclose(pluginHandle); // Unload the plugin


    /*总结：
     *
     * In this example, we use dlopen to load the shared library (.so file) containing the plugin. We then retrieve
     * function pointers to the plugin's functions, initialize the plugin, call the plugin function, and finally clean
     * up and unload the plugin.Compile and Run:
    Compile the main application and the sample plugin separately, linking the plugin with the main application
     using -ldl to include the dynamic linking library:
    bash
    Copy code
    gcc -o main main.c -ldl
    gcc -shared -o sample_plugin.so sample_plugin.c
    Run the main application:

    bash
    Copy code
    ./main
    This example demonstrates a simple plugin system in C. In practice, you may need to handle more complex
     scenarios, such as managing multiple plugins, handling errors gracefully, and ensuring compatibility
     between the main application and plugins. Additionally, the plugin loading mechanism may vary depending
     on the platform you're targeting.
     * */

    return 0;

}


/**
 * 17.7.1函数指针作为参数：
 * 可以以数据指针相同的方式使用函数指针。在C语言中把函数作为参数进行传递是十分普遍的。
 *
 */
void func_pointer_as_argument() {
    //调用下方函数integrate时，将把一个函数名作为第一个时间参数。例如，下列调用将计算sin函数从0到∏的积分
    integrate(sin, 0.0, PI / 2);
    /*注意，sin的后边没圆括号。当函数名后边没有跟着圆括号时，C语言编译器会产生指向函数的指针，而不会产生函数调用的代码。
     * 此例中不是在调用函数sin，而是给函数integrate传递了一个指向函数sin的指针。如果这样看上去很混乱的话，想想C语言处理
     * 数组的过程。如果a是数组的名字，那么a[j]就表示数组的一个元素，而a本身则作为指向数组的指针。类似地，如果f是函数，那么C
     * 语言把f(x)当作函数的调用来处理，而f本身则被视为指向函数的指针。
     * */

}

/**
 * 函数指针的案例：
 * 我们要编写一个名为integrate的函数来求函数f在a点和b点之间的积分。我们希望函数integrate尽可能具有一般性，因此把f作为实际参数
 * 传入。为了在C语言达到这种效果，我们把f声明为指向函数的指针。假设希望对具有double型形式参数并且返回double型结果的函数求积分，
 * 函数integrate的原型如下：
 * *f两边的圆括号说明f是个指向函数的指针，而不是返回值为指针的函数。把f当作函数声明也是合法的。把f当作函数声明也是合法的如下：
 * double integrate(double f(double),double a, double b);
 * 从编译器的角度来看，这种原型和前一种形式是完全一样的。
 * @param f
 * @param a
 * @param b
 * @return
 */
double integrate(double (*f)(double), double a, double b) {
    //在integrate函数体内，可以调用f所指向的函数：
    //y = (*f)(x);
    return 0.0f;

}


// A function that performs an operation and calls a user-defined callback function
void performOperation(int a, int b, int(*callback)(int)) {
    int result = callback(a + b);
    printf("Result: %d\n", result);
}

// User-defined callback function
int customCallback(int value) {
    return value * 2;
}


int add(int a, int b) {
    return a + b;
}

int subtract(int a, int b) {
    return a - b;

}

int compareAscending(const void *a, const void *b) {
    return (*(int *) a - *(int *) b);
}

int compareDescending(const void *a, const void *b) {
    return (*(int *) b - *(int *) a);
}


// Implement methods for MyObject
int myObjectAdd(void *self, int a, int b) {
    MyObject *obj = (MyObject *) self;
    return obj->value + a + b;
}

int myObjectSubtract(void *self, int a, int b) {
    MyObject *obj = (MyObject *) self;
    return obj->value - a - b;
}

/*2.Create a Sample Plugin:
        Write a sample plugin that adheres to the defined interface. This plugin can be compiled
        separately from the main application:
*/
int samplePluginFunction(int value) {
    printf("Sample Plugin: Received value: %d\n", value);
    return value * 2;
}

void initPlugin() {
    // Perform any plugin initialization here
}

void cleanupPlugin() {
    // Perform any cleanup before unloading the plugin
}