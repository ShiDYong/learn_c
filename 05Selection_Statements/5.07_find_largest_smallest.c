/********************************************************************************
* @author: mason shi
* @date: 2024/5/27 21:25
* @version: 1.0
* @description: 根据课后编程练习题将代码不断优化
********************************************************************************/
/**
 Project 5.07
Write a program that finds the largest and smallest of four integers entered by
the user:
Enter four integers: 21 42 10 35
Largest: 43
Smallest: 10
Use as few `if` statements as possible: *Hint*: Four `if` statements are
sufficient.

 */
#include <stdio.h>
#include <stdlib.h>
// Constants for error messages
#define INVALID_INPUT_MSG "Invalid input. Please enter a valid positive integer.\n"
#define MEMORY_ALLOCATION_FAILED "Memory allocation failed.\n"
#define INVALID_INTEGER_INPUT_MSG "Invalid input. Please enter integers only.\n"

//Function prototypes
int *readNumbers01(int n);

void findExtrema01(const int *nums, int n, int *largest, int *smallest);

void handleInputError01();

// 最终优化后的函数原型
int *readNumbers(int count, int *success);

void findExtrema(const int *numbers, int count, int *largest, int *smallest);

void handleInputError(const char *message);

void exec5_7_0() {
    int n1, n2, n3, n4, max, min, max1, max2, min1, min2;
    printf("Enter four integer: ");
    //读取这里不好控制时几位数的整数进行比较大小,这里取值是2位整数
    scanf("%d %d %d %d", &n1, &n2, &n3, &n4);
    if (n1 < n2) {
        max1 = n2;
        min1 = n1;
    } else {
        max1 = n1;
        min1 = n2;
    }
    if (n3 < n4) {
        max2 = n4;
        min2 = n3;
    } else {
        max2 = n3;
        min2 = n4;
    }

    if (max2 > max1)
        max = max2;
    else
        max = max1;
    if (min2 > min1)
        min = min1;
    else
        min = min2;

    //以上两个if语句可以直接用三元运算符替换,但是可读性不高
//    n1 < n2 ? (max1 = n2, min1 = n1) : (max1 = n1, min1 = n2);
//    n3 < n4 ? (max2 = n4, min2 = n3) : (max2 = n3, min2 = n4);
//    max2 > max1 ? (max = max2) : (max = max1);
//    min2 > min1 ? (min = min1) : (min = min2);

    printf("Largest: %d\nSmallest: %d\n", max, min);

}

/*
 * 对上面方法的优化点：
 * 1.减少变量的使用和重复初始化：初始将‘largest'和'samller'都设为第一个输入的值'num1'。
 * 2.优化比较逻辑：在读取每个数时，直接更新‘largest‘和'smallers'，避免重复的代码和多余的比较；
 * 3.合并比较条件：在每次判断时，用'if-else'结构替代两个独立的'if‘,以减少不必要的比较次数。
 * 不仅使代码更简洁，还提高了运行效率，因为减少了比较操作的次数。
 */

void exec5_7_1() {
    int num1, num2, num3, num4;
    int largest, smallest;

    //Prompt the user to enter four integers

    printf("Enter of four Integers: ");
    scanf("%d %d %d %d", &num1, &num2, &num3, &num4);

    //Initialize the largest and smallest
    largest = smallest = num1;

    //Compare and update largest and smallest values
    if (num2 > largest) largest = num2;
    else if (num2 < smallest) smallest = num2;

    if (num3 > largest) largest = num3;
    else if (num3 < smallest) smallest = num3;

    if (num4 > largest) largest = num4;
    else if (num4 < smallest) smallest = num4;

    //Output the results
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);

}

/*
 * 优化点：
 * 1.使用数组：将输入的整数存储在数组中，便于后续的处理，以为4个变量都是整数，相同的类型
 * 2.使用循环：通过一个循环结构遍历数组，比较并更新最大值和最小值；
 * 3.扩展性：如果需要处理更多的整数，只需调整数组大小和循环次数，而不需要修改主要逻辑
 *  代码更加简洁明了，而且具有更好的可扩展性和可维护性。如果用户需要输入更多的整数，只需修改数组的
 *  大小和循环的范围即可。
 */
void exec5_7_2() {
    int nums[4];
    int largest, smallest;

    //Prompt the user to enter four integers
    printf("Enter four integers: ");
    for (int i = 0; i < 4; i++) {
        scanf("%d", &nums[i]);
    }

    //Initialize largest and smallest
    largest = smallest = nums[0];

    //Loop through the array to find the largest and smallest numbers
    for (int n = 0; n < 4; n++) {
        if (nums[n] > largest) {
            largest = nums[n];
        }
        if (nums[n] < smallest) {
            smallest = nums[n];
        }
    }
    //Output the results
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);
}

/*
 * 优化点：
 * 1.动态内存分配：使用'alloc'动态分配内存，使程序能够处理任意数量的整数输入，而不仅限于固定的四个整数；
 * 2.通用性：程序能够使用不同的输入规模，用户可以在运行时指定要输入的整数数量；
 * 3.内存管理：在使用动态分配的内存后，使用'free‘释放内存，避免内存泄露
 * 这样使程序更加灵活和通用，适用于不同的运用场景，可以根据用户的输入大小自动调整处理能力
 */
void exec5_7_3() {
    int n;
    int *nums;
    int largest, smallest;

    //Prompt the user to enter the number of integers
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    //Allocate memory dynamically for the integers
    nums = (int *) malloc(n * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    //Prompt the user of enter the integers
    printf("Enter %d integers: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    //Initialize largest and smallest
    largest = smallest = nums[0];

    //Loop through array to find the largest and smallest numbers
    for (int m = 0; m < n; m++) {
        if (nums[m] > largest) {
            largest = nums[m];
        }
        if (nums[m] < smallest) {
            smallest = nums[m];
        }
    }
    //Output the results
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);
    //Free the allocated memory
    free(nums);
}


/*
 * 优化点：
 * 1.模块化和函数分解：
 *      1.1 'readNumbers'函数负责从用户获取输入，并进行输入验证和错误处理；
 *      1.2 'findExtrema'函数负责计算最大值和最小值；
 *  2.输入验证处理和错误处理：
 *      1.1 在读取整数数量时，检查输入的有效性；
 *      1.2 在读取每个整数时，检查输入的有效性。如果输入无效，释放内存并返回错误。
 *   3.内聚性：每个函数只负责一个任务，使代码更清晰，易维护和调试；
 *   4.低耦合性：各个函数独立运作，减少了相互依赖，增强了代码的灵活性和可重用性。
 *   5.完善错误处理：
 *      5.1增加handleInputError函数，统一处理输入错误。
        5.2在内存分配失败或输入无效时提供明确的错误信息。
     6.更好的编程实践：
        6.1将常量和错误处理分开，使代码更清晰；
        6.2 增加适当的注释，帮助理解代码的功能。
 *   代码的结构更加清晰，模块化程度更高，错误处理更加完善，增强了代码的可读性和可维护性。
 */
void exec5_7_4() {
    int n;
    int largest, smallest;
    int *nums;

    //Prompt the user to enter the number of integers
    printf("Enter the number of integers: ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        handleInputError01();
        return;
    }

    //Get the numbers from the user
    nums = readNumbers01(n);
    if (nums == NULL) {
        return;
    }

    //Find the largest and smallest numbers
    findExtrema01(nums, n, &largest, &smallest);
    //Output the results
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);

    //Free the allocated memory
    free(nums);


}

//Function to handle input errors
void handleInputError01() {
    printf("Invalid input. Please enter a valid positive integer.\n");
}

/**
 * Function to handle input errors
 * @param message The error message to be displayed
 */
void handleInputError(const char *message) {
    printf("%s", message);
}

//Function to get numbers form the user
int *readNumbers01(int n) {
    int *nums = (int *) alloca(n * sizeof(int));
    if (nums == NULL) {
        printf("Memory allocation failed\n");
        return NULL;
    }
    //Prompt the user to enter the integers
    printf("Enter %d integers: ");
    for (int i; i < n; i++) {
        if (scanf("%d", &nums[i]) != 1) {
            printf("Invalid input. Please enter integers only.\n");
            free(nums);
            return NULL;
        }
    }
    return nums;
}

/**
 * Function to get numbers from the user
 * @param count The number of integers to read
 * @param success Pointer to an integer that indicates success (1) or failure (0)
 * @return Pointer to the dynamically allocated array of integers, or NULL if an error occurs
 */
int *readNumbers(int count, int *success) {
    int *numbers = (int *) malloc(count * sizeof(int));
    if (numbers == NULL) {
        handleInputError(MEMORY_ALLOCATION_FAILED);
        *success = 0;
        return NULL;
    }

    // Prompt the user to enter the integers
    printf("Enter %d integers: ", count);
    for (int i = 0; i < count; i++) {
        if (scanf("%d", &numbers[i]) != 1) {
            handleInputError(INVALID_INTEGER_INPUT_MSG);
            free(numbers);
            *success = 0;
            return NULL;
        }
    }

    *success = 1;
    return numbers;
}

//Function to find the largest and smallest numbers in an array
void findExtrema01(const int *nums, int n, int *largest, int *smallest) {
    *largest = *smallest = nums[0];
    for (int i = 0; i < n; i++) {
        if (nums[i] > *largest) {
            *largest = nums[i];
        }
        if (nums[i] > *smallest) {
            *smallest = nums[i];
        }

    }
}

/**
 * Function to find the largest and smallest numbers in an array
 * @param numbers The array of integers
 * @param count The number of integers in the array
 * @param largest Pointer to store the largest integer
 * @param smallest Pointer to store the smallest integer
 */
void findExtrema(const int *numbers, int count, int *largest, int *smallest) {
    *largest = *smallest = numbers[0];

    for (int i = 1; i < count; i++) {
        if (numbers[i] > *largest) {
            *largest = numbers[i];
        }
        if (numbers[i] < *smallest) {
            *smallest = numbers[i];
        }
    }
}

int main() {
    // exec5_7_1();
    // exec5_7_2();
    //exec5_7_3();
    // exec5_7_4();
    /**下面演示是exec5_7_5处理方式
     * 优化点：
     * 1.函数职责单一化：每个函数只做一件事，例如readNumbers负责读取数字，findExtrema负责找到最大和最小值，handleInputError负责处理错误信息。
       2.命名清晰：使用了更清晰和描述性的变量和函数名称，如count、numbers、success等。
       3.防御性编程：在读取输入时增加了更多的验证，确保输入有效。
       4.适当的注释：为每个函数添加了注释，解释其作用。
       5.使用常量：使用了宏定义来表示错误信息，避免魔法数字，提高了代码的可读性。
       6.减少代码重复：通过handleInputError函数来统一处理错误信息，减少了重复代码。
       7.状态返回：在读取数字函数中使用success参数来指示操作是否成功，增强了错误处理的灵活性。
     */
    int count;
    int largest, smallest;
    int *numbers;
    int success;

    // Prompt the user to enter the number of integers
    printf("Enter the number of integers: ");
    if (scanf("%d", &count) != 1 || count <= 0) {
        handleInputError(INVALID_INPUT_MSG);
        return 1;
    }

    // Get the numbers from the user
    numbers = readNumbers(count, &success);
    if (!success) {
        return 1;
    }

    // Find the largest and smallest numbers
    findExtrema(numbers, count, &largest, &smallest);

    // Output the results
    printf("Largest: %d\n", largest);
    printf("Smallest: %d\n", smallest);

    // Free the allocated memory
    free(numbers);

    return 0;
}


