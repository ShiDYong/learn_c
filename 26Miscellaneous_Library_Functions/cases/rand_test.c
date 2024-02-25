/********************************************************************************
* @author: mason shi
* @date: 2024/1/8 21:59
* @version: 1.0
* @description: C语言生成伪随机函数常用方法
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include <openssl/rand.h>


/*
 * 生成的随机数是不相同的
 */
void test_rand_time() {
    int i;
    //Seed the random number generator with current time
    //调用srand函数可以为rand函数提供种子值。使种子值随机化的最简单方法就是调用time函数，它会
    //返回一个对当前日期和时间进行编码的数。把time函数的返回值传递给srand函数，这样可以使rand函数每次运行
    //时的行为都不相同。
    srand(time(NULL));
    //Generate and print 5 random numbers between 1 and 100
    printf("Random Number between 1 to 100: \n");
    for (i = 0; i < 5; i++) {
        //Generate a random number between 1 and 100
        int random_number = rand() % 100 + 1;
        printf("Random Number %d: %d\n", i + 1, random_number);

    }
}

/*
 * 如果你想要确保每次运行程序时都产生相同的随机数序列，
 * 你应该在调用 rand() 之前使用 srand() 显式地设置相同的种子。
 * 通过设置相同的种子，你可以确保每次运行程序时都获得相同的随机数序列
 * 记住，使用相同的种子值确保了伪随机数生成器的状态相同，从而确保了相同的输出序列。
 */
void test_rand_sran() {
    int i, seed;
    printf("This program displays the first five values of rand.\n");
    for (;;) {
        for (i = 0; i < 5; i++)
            printf("%d ", rand()),//不指定固定值
                    //如果在srand函数之前调用rand函数，那么会把种子值设定为1.始终使用同一个种子值的程序总会从rand函数得到相同
                    //的数值序列。这个性质有时是非常有用的：程序每次运行时按照相同的方式运行。这样会使测试更加容易
                    printf("\n\n");
        printf("Enter new seed value (0 to terminate):  ");
        scanf("%d", &seed);
        if (seed == 0) break;
        srand(seed);


    }

}

/*显式设置种子，这里设置为固定值 42
*/
void test_rand_fix_value() {
// 显式设置种子，这里设置为固定值 42
    srand(42);
    // 生成并打印 5 个伪随机数
    printf("固定随机数序列:\n");
    for (int i = 0; i < 5; ++i) {
        int random_number = rand();
        printf("随机数 %d: %d\n", i + 1, random_number);
    }
}

/*
 * C语言生成加密：加密级别的随机数
 */
void generate_secure_random(){
    unsigned char random_buffer[16];//设置16字节的随机数
    //生成安全的随机数;
    if(RAND_bytes(random_buffer,sizeof(random_buffer))==1){
        int i;
        printf("Secure Random Number: \n");
        for (i = 0; i< sizeof(random_buffer); i++) {
            printf("%02X",random_buffer[i]);//此示例使用 OpenSSL 中的 RAND_bytes 函数生成安全随机数。 生成的随机数以十六进制格式打印。
        }
        printf("\n");

    } else{
        fprintf(stderr,"Error generating random number \n");
    }

}


//int main(int argc, char *argv[]) {
//    /*
//     *rand函数和srand函数结合的方法适用于许多运用程序，但它可能无法为加密目的提供最佳质量的随机性。
//     * 如果您需要加密级别的随机性，则应使用编程环境提供的专用加密库或设施。
//     * */
//    // test_rand_time();
//    //test_rand_sran();
//    //test_rand_fix_value();
//    generate_secure_random();
//
//    return 0;
//
//
//}

