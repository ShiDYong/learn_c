/********************************************************************************
* @author: mason shi
* @date: 2023/7/9 16:05
* @version: 1.0
* @description: 编写一个简单的游戏程序。这个程序产生一个1～100的随机数，用户尝试用尽可能少的次数猜出这个数。
 * Guess the secret number between 1 and 100
 *  A new number has been chosen.
 *  Enter guess: 55
 *  Too low; try again.
 *  Enter guess: 65
 *  Too high;try again.
 *  Enter guess: 60
 *  Too high;try again.
 *  Enter guess: 58
 *  You won in 4 guesses!.
 *  A new number has been chose.
 *  Play again?(Y/N) y
 *  Enter guess: 78
 *  Too high;try again.
 *  Enter guess: 34
 *  You won in 2 guesses!
 *  Play again?(Y/N) n
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX_NUMBER 100
/*external variable*/
int secret_number;

/*prototypes*/
void initialize_number_generator(void);

void choose_new_secret_number(void);

void read_guesses(void);

void guess(void);


/*
int main(void) {
    guess();
    return 0;
}
*/


void guess(void) {
    char command;
    printf("Guess the secret number between 1 and %d.\n\n", MAX_NUMBER);
    initialize_number_generator();
    do {
        choose_new_secret_number();
        printf("A new number has been chosen.\n");
        read_guesses();
        printf("Play guess? (Y/N) ");
        scanf(" %c", &command);
        printf("\n");

    } while (command == 'Y' || command == 'y');


}


/**
 * initialize the random number generator
 * using the time of day.
 */
void initialize_number_generator(void) {
    srand((unsigned) time(NULL));
}

/**
 * Randomly selects a number between 1 and MAX_NUMBER
 * and stores it in secret_number.
 */
void choose_new_secret_number(void) {
    secret_number = rand() % MAX_NUMBER + 1;

}


/**
 * Repeatedly reads user guesses and tells the user whether each guess is too low,
 * too high,too low,or correct.When the guess is correct ,prints the total number of
 * guesses and returns.
 */
void read_guesses(void) {
    int guess, num_guesses = 0;
    for (;;) {
        num_guesses++;
        printf("Enter guess: ");
        scanf("%d", &guess);
        if (guess == secret_number) {
            printf("You won in %d guesses!\n\n", num_guesses);
            return;
        } else if (guess < secret_number)
            printf("Too low; try again.\n");
        else
            printf("Too high; try again.\n");
    }
}