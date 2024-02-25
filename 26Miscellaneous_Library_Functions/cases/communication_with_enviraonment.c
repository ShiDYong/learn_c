/********************************************************************************
* @author: mason shi
* @date: 2024/1/9 23:02
* @version: 1.0
* @description: 与环境通信的接口
 *
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include <string.h>

//正数比较升序
int compareIntegers(const void *a, const void *b) {
    return (*(int *) a - *(int *) b); //分别取a、b指针指向的地址的内容,即取值进行相减
}

//城市信息的数据结构
struct city_info {
    char *city;
    int miles;
};

int compare_cities(const void *key_prt, const void *element_ptr);

//const void *element_ptr:该参数是指向常量void的指针(*)。void类型通常用于泛型指针。该参数指向需要比较的元素的指针
int main(int argc, char *argv[]) {
    /*
     * 1.abort函数
     * it is used to terminate the program abnormally. When abort() is called,
     * it causes the program to terminate immediately and generates a core dump
     * (on systems that support core dumps).
     * It's important to note that using abort() should be done cautiously,
     * as it doesn't provide a chance for proper cleanup and can leave resources
     * in an undefined state. Typically, it is recommended to use exit()
     * with an appropriate exit code for a more controlled program termination
     * */
    printf("Before abort()\n");
    //calling about() to terminate the program
    //abort(); //控制台输出：Signal: SIGABRT (signal SIGABRT)

    //The following code will not to be executed after calling abort()
    printf("After abort()\n");

    //C 中的 getenv 函数用于检索环境变量的值。 它在 stdlib.h 头文件中声明
    // Replace "EXAMPLE_ENV_VARIABLE" with the name of the environment variable you want to retrieve
    const char *env_var_name = "JAVA_HOME";
    char *env_var_value = getenv(env_var_name);
    if (env_var_value != NULL)
        printf("The value of %s is: %s\n", env_var_name, env_var_value);
    else
        printf("%s environment variable is not set.\n", env_var_name);

    /*
     * 实用的排序工具
     * void	 qsort(void *__base, size_t __nel, size_t __width,
       int (* _Nonnull __compar)(const void *, const void *));
     */
    int numbers[] = {5, 2, 9, 1, 5, 6};
    int key = 9;
    size_t i;
    size_t numElements = sizeof(numbers) / sizeof(numbers[0]);
    printf("Original array: ");
    for (i = 0; i < numElements; ++i)
        printf("%d ", numbers[i]);
    printf("\n");
    //实用qsort对数组值进行排序
    qsort(numbers, numElements, sizeof(int), compareIntegers);
    printf("Sorted array: ");
    for (i = 0; i < numElements; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    /**搜索工具的实用
     * besearch函数只能用于有序数据，所以在使用besearch函数搜索数组之前先qsort函数对其进行排序
     */
    int *result = (int *) bsearch(&key, numbers, numElements, sizeof(numbers[0]), compareIntegers);

    if (result != NULL) {
        printf("Key %d found at index %ld.\n", key, result - numbers);
    } else {
        printf("Key %d not found in the array.\n", key);
    }


    /*================================案例练习题：确定航空里程==================================*/
    /*下面的程序用来计算从纽约到不同的国际城市之间的航空里程。程序首先要起用户输入城市的名称，然后显示从纽约到这一城市的里程：
     * Enter city name: Shanghai
     * Shanghai is 7371 miles from New York City.
     * 思路：程序将城市/里程数据对存储在数组中。通过使用bsearch函数在数组中搜索城市名，就可以找到对应的里程数
     * */

    char city_name[81];
    struct city_info *ptr;
    const struct city_info mileage[] = {
            {"BerLin",        3965},
            {"Buenos Aires",  5297},
            {"Cairo",         5602},
            {"Calcutta",      7918},
            {"Cape Town",     7764},
            {"Caracas",       2132},
            {"Chicago",       713},
            {"Shanghai",      7371},
            {"Istanbul",      4975},
            {"Lisbon",        3364},
            {"London",        3458},
            {"Moscow",        4665},
            {"Manila",        8498},
            {"Tokyo",         6740},
            {"Pars",          320},
            {"Washington",    205},
            {"Roman",         3624},
            {"San Francisco", 2571}
    };
    printf("Enter city name: ");
    scanf("%80[^\n]", city_name); //这是匹配除换行符 (\n) 之外的任何字符的字符集。 这意味着 scanf 将读取字符直到遇到换行符，并且它不会在输入中包含换行符。 这有助于读取整行输入。
    ptr = bsearch(city_name, mileage, sizeof(mileage) / sizeof(mileage[0]), sizeof(mileage[0]), compare_cities);
    if (ptr != NULL) printf("%s is %d form New York city.\n", city_name, ptr->miles);
    else printf("%s wasn't found.\n", city_name);
    return 0;

}

int compare_cities(const void *key_ptr, const void *element_ptr) {
    return strcmp((char *) key_ptr, ((struct city_info *) element_ptr)->city);
}

