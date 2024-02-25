/********************************************************************************
* @author: mason shi
* @date: 2023/7/9 17:11
* @version: 1.0
* @description: 对guess.c程序对改进，虽然guess.c正常运行，但是它依赖一个外部变量。把变量secret_number
 * 外部化以便choose_secret_number函数和read_guess函数访问它。如果对choose_secret_number函数和read_guess
 * 函数稍做改变，把变量移入到guess函数中。让choose_secret_number函数返回secret_number,再把这个变量传入
 * 到read_guess函数中。
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_NUMBER 100

/*函数原型*/
void guess(void);

void initialize_number_generator(void);

int choose_new_secret_number();

void read_guesses(int secret_number);

//int main(void) {
//    guess();
//    return 0;
//}

void guess(void) {
    char command;
    int secret_number;/*将全局变量改为局部变量*/
    printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
    initialize_number_generator();
    do {
        secret_number = choose_new_secret_number();
        printf("A new number has been chosen.\n");
        read_guesses(secret_number);
        printf("Enter again? (Y/N)  ");
        scanf(" %c", &command);
        printf("\n");

    } while (command == 'Y' || command == 'y');
}

/**
 * 初始化随机数生成器
 */
void initialize_number_generator() {
    srand((unsigned) time(NULL));
}


/**
 * 生成神秘数字
 * @return
 */
int choose_new_secret_number() {
    return rand() % MAX_NUMBER + 1;
}

/**
 * 对用户输入的数进行判断并询问是否要重试
 * @param secret_number
 */
void read_guesses(int secret_number) {
    int guess, num_guesses = 0;

    for (;;) {
        num_guesses++;
        printf("Enter guess: ");
        scanf("%d", &guess);
        if (guess == secret_number) {
            printf("You won %d guesses!\n\n", num_guesses);
            return;
        } else if (guess < secret_number)
            printf("Too low; try again.\n");

        else
            printf("Too high; try again.\n");
    }
}