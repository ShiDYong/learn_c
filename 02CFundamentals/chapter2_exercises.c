/********************************************************************************
* @author: mason shi
* @date: 2024/2/25 11:10
* @version: 1.0
* @description: 课后练习题
********************************************************************************/
#include<stdio.h>

/*
 * 课后练习题02:编写一个程序来声明几个int类型和float类型变量，不对这些变量进行初始化，然后显示它们的值
 * 。这些值是否有规律(通常情况下没有)
 *
 * */
void test_uninitialized_variable() {
    float f;
    int x, y;
    int z = x*y;
    printf("Uninitialized X =%d, Y=%d and Z=%d \n",x,y,z);
    printf("Uninitialized float f =%f \n",f);
    /*
     * 运行结果输出,可以看出Clang编译自动会将float赋值为0，int类型第一个赋值比较大，第二个int类型变量默认赋值1
     * 在Clion下，重复运行程序，发现x的值会出现固定的无规则的数据，这并不表示该为初始化变量是一个固定值，而是由于操作
     * 系统在优化程序加载时产生的副作用。编写程序时一定要注意变量先初始化再使用的原则。
     Uninitialized X =1839672304, Y=1 and Z=1839672304
     Uninitialized float f =0.000000
     * */
}


/*
 * 1.建立并运行由Kerninghan和Ritchie编写的著名的“hello, world”程序：
 * #include <stdio.h>
 * int main(void){
 * printf("hello,world\n");
 * }
 * 在编译时是否有告警信息？如果有，需要如何修改呢？
 * */
//int main(void) { //函数运行完成后应当返回一个int类型的数值，即在程序终止时向操作系统返回一个状态吗
//    printf("hello,world\n");
//    //没有使用return语句返回整型数据，部分编译器会发出警告，提示要使用return语句返回数值，但是macOS
//    //编译器是Clang运行也没有发现问题，可以成功运行，没有提示;在Centos7上，gcc 4.8.5版本也没有发出告警信息
//    /*=======================关于GCC和LLVM编译器相关知识========================================
//        1.在 macOS 上，默认的编译器是 Clang，它是 LLVM 编译器套件的一部分，兼容 C、C++ 和 Objective-C。Clang 在
//         macOS 上作为默认的 C 和 C++ 编译器提供；
//        2.LLVM（Low Level Virtual Machine）和 GCC（GNU Compiler Collection）都是流行的编译器套件，用于编译和优化程序。
//        它们之间有一些区别，包括以下几点：
//        1.架构：
//            LLVM：LLVM 是一个 modulized、可重用的编译器和工具链架构，它设计得更加灵活，允许构建各种编译器和工具。
//            LLVM 包含一组通用的编译器工具，如前端、优化器和后端。
//            GCC：GCC 是 GNU Compiler Collection 的缩写，是一个完整的编译器套件，由前端、优化器和后端组成。
//        3.语言支持：
//            LLVM：LLVM 的前端可以支持多种编程语言，包括 C、C++、Objective-C、Swift、Rust 等。这使得 LLVM 可以被广泛用于不同语言的编译器开发。
//            GCC：GCC 最初是为 C 编写的，但后来扩展到支持多种语言，包括 C、C++、Objective-C、Fortran、Ada、Go 等。
//        4.性能：
//            LLVM：LLVM 在某些情况下可能会比 GCC 更快，因为它的优化策略和算法不同。LLVM 的优化器被认为在某些方面更先进，可以产生更好的代码。
//            GCC：GCC 已经存在了很长一段时间，有许多成熟的优化技术。在某些情况下，GCC 的性能可能比 LLVM 更好。
//        5.许可证：
//            LLVM：LLVM 使用 LLVM 许可证，这是一种自由软件许可证，允许修改、分发和商业使用。
//            GCC：GCC 使用 GNU 通用公共许可证（GPL），这是一种 copyleft 许可证，要求修改后的软件也必须开源。
//        6.发展和社区：
//            LLVM：LLVM 项目由 LLVM 社区开发和维护，有一个活跃的开发社区，得到了工业界和学术界的广泛支持。
//            GCC：GCC 由自由软件基金会（FSF）主导开发，也有一个庞大的社区。不过，近年来 GCC 的发展相对缓慢一些，部分原因是 LLVM 的出现和发展
//     * */
//    //添加上
//
//    /*课后练习题04*/
//    test_uninitialized_variable();
//
//
//
//    return 0;
//}