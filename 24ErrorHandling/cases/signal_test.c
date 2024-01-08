/********************************************************************************
* @author: mason shi
* @date: 2024/1/6 17:00
* @version: 1.0
* @description:
 *  <signal.h>提供了处理异常情况(称为信号)的工具。信号有两种类型：运行时错误和发生在程序以外的事件。许多操作系统
 *  都允许用户中断或终止正在运行的程序，C语言把这些事件视为信号。当有错误或外部事件发生时，我们称为产生了一个信号，大多数
 *  信号是异步的；它们可以在程序执行过程中的任意时刻发生，而不仅是在程序员所知道的特定时发生。由于信号可能会在任何意想不到
 *  的时刻发生，因此必须用一种独特的方式来处理它们。
********************************************************************************/
#include <signal.h>
#include <stdio.h>

//Test signals
void handler(int sig);

void raise_sig(void);

/*<signal.h>中的定义的宏，用于表示不同的信号
 *          宏名                   含义
 *          SIGABRT                异常终止(可能由于调用abort导致)
 *          SIGFPE                 在算术运算中发生错误(可能是除以0或溢出)
 *          SIGILL                 无效指令
 *          SIGINT                 中断
 *          SIGSEGV                无效存储访问
 *          SIGTERM                终止请求

 * */

int main(int argc, char *argv[]) {
    //声明一个指向函数的指针，该函数采用整数参数 (int) 并返回 void（即不返回任何值）。
    // 该声明通常用在 C 信号处理的上下文中。
    void (*orig_handler)(int);
   // printf("Installing handler for signal %d\n", SIGINT);
    printf("Installing handler for signal %d\n", SIGUSR1);

    // Registering a custom signal handler for SIGUSR1
  //  orig_handler = signal(SIGINT, handler);
    orig_handler = signal(SIGUSR1, handler);

    raise_sig();

    printf("Changing original handler\n");
    signal(SIGINT,SIG_IGN);
    raise_sig();

    printf("Restoring original handlers\n");
    // Later, you might want to restore the original handler
    //signal(SIGINT, orig_handler);
    signal(SIGUSR1, orig_handler);

    //the raise function in C is used to send a signal to the current
    // process or to a specific process identified by its process ID
    // Raise SIGUSR1 signal to the current process
    raise_sig();
    printf("Program terminates normally\n");
    return 0;


}

void handler(int sig) {
    printf("Handler called for signal %d\n", sig);
    // You can add your own logic or cleanup code here
}

void raise_sig(void) {
    // Raise SIGUSR1 signal to the current process
    raise(SIGINT);

}
