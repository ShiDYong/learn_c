/********************************************************************************
* @author: mason shi
* @date: 2024/5/28 22:17
* @version: 1.0
* @description:
  Project 5.08
        The following table shows the daily flights from one city to another:
        | Departure time | Arrival time |
        | ---: | ---: |
        | 8:00 a.m. | 10:16 a.m. |
        | 9:43 a.m. | 11:52 a.m. |
        | 11:19 a.m. | 1:31 p.m. |
        | 12:47 p.m. | 3:00 p.m. |
        | 2:00 p.m. | 4:08 p.m. |
        | 3:45 p.m. | 5:55 p.m. |
        | 7:00 p.m. | 9:20 p.m. |
        | 9:45 p.m. | 11:58 p.m. |
        Write a program that asks the user to enter a time (expressed in hours and
        minutes, using the 24-hour clock). The program then displays the departure and
        arrival times for the flight whose departure time is closest to that entered by
        the user:
        ```
         Enter a 24-hour time: 13:15
        Closest departure time is 12:47 p.m., arriving at 3:00 p.m.
        ```
        *Hint*: Convert the input into a time expressed in minutes since midnight, and
        compare it to the departure times, also expressed in minutes since midnight. For
        example, 13:15 is 13 * 60 + 15 = 795 minutes since midnight, which is closer to
        12:47 p.m. (767 minutes since midnight) than to any of the other departure
        times.
********************************************************************************/
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//定义常量和数据结构
#define NUM_FLIGHTS 8 //定义了一个常量，表示有8个航班
#define TIME_STR_SIZE 20 // 通过将字符串缓冲区的大小设置为20，可以容纳较长的字符串，同时还留出了一些额外的空间以便于处理字符串操作（例如添加终止符 \0）

//Flight 结构体包含航班的出发时间和到达时间（以分钟计）以及对应的字符串格式（用于输出）
//当初做题不知道如何设计出这个有效的数据结构
typedef struct {
    int departure_time; //以午夜起算的分钟数
    int arrival_time;
    char departure_str[TIME_STR_SIZE];
    char arrival_str[TIME_STR_SIZE];
} Flight;

//将小时和分钟转换为从午夜起算的分钟数
int time_in_minutes(int hours, int minutes) {
    return hours * 60 + minutes;
}

//初始化航班信息，这个当初做题不知道如何组装这些航班信息
//以及如何通过数据结构设置对应的映射关系,所以这里要好好思考下
void initialize_flight01(Flight flights[]) {
    flights[0] = (Flight) {time_in_minutes(8, 0), time_in_minutes(10, 16), "8:00 a.m.", "10:16 a.m."};
    flights[1] = (Flight) {time_in_minutes(9, 43), time_in_minutes(11, 52), "9:43 a.m.", "11:52 a.m."};
    flights[2] = (Flight) {time_in_minutes(11, 19), time_in_minutes(13, 31), "11:19 a.m.", "1:31 p.m."};
    flights[3] = (Flight) {time_in_minutes(12, 47), time_in_minutes(15, 0), "12:47 p.m.", "3:00 p.m."};
    flights[4] = (Flight) {time_in_minutes(14, 0), time_in_minutes(16, 8), "2:00 p.m.", "4:08 p.m."};
    flights[5] = (Flight) {time_in_minutes(15, 45), time_in_minutes(17, 55), "3:45 p.m.", "5:55 p.m."};
    flights[6] = (Flight) {time_in_minutes(19, 0), time_in_minutes(21, 20), "7:00 p.m.", "9:20 p.m."};
    flights[7] = (Flight) {time_in_minutes(21, 45), time_in_minutes(23, 58), "9:45 p.m.", "11:58 p.m."};
}

//使用strcpy确保字符串正确复制到结构体的字符数组中
// 初始化航班数据
// 初始化航班数据
void initialize_flights(Flight *flights) {
    //数组越界访问：代码中使用了flights数组的索引0到7进行赋值操作，但未检查数组是否足够大。
    //解决方案：确保flights数组至少有8个元素，以便能够容纳所有的航班信息。
//    if (size < MAX_FLIGHTS) {
//        printf("Error: Array size is not sufficient.\n");
//        return;
//    }

    //赋值字符串可能导致缓冲区溢出：代码中通过strcpy函数将字符串复制到departure_str和arrival_str成员变量中，但未检查目标缓冲区是否足够大，可能导致缓冲区溢出。
    //解决方案：可以使用strncpy函数代替strcpy函数，并指定目标缓冲区的大小，以避免溢出。例如，使用strncpy(flights[0].departure_str, "8:00 a.m.",
    // sizeof(flights[0].departure_str));来复制字符串。
    strncpy(flights[0].departure_str, "8:00 a.m.", sizeof(flights[0].departure_str) - 1);
    strncpy(flights[0].arrival_str, "10:16 a.m.", sizeof(flights[0].arrival_str) - 1);
    flights[0].departure_time = time_in_minutes(8, 0);
    flights[0].arrival_time = time_in_minutes(10, 16);

    //flights[7].departure_str 是 Flight 结构体数组中第 8 个元素（索引为 7）的 departure_str 成员变量，它表示航班的起飞时间。
    //strncpy 函数用于将源字符串（"9:45 p.m."）复制到目标字符数组（flights[7].departure_str）中。它通过指定目标缓冲区大小来避免缓冲区溢出。
    //sizeof(flights[7].departure_str) 返回目标字符数组的大小（以字节为单位），即 flights[7].departure_str 的长度。
    //- 1 是为了留出一个额外的字节用于存储字符串的终止符 \0。
    //最终，strncpy 函数会将源字符串复制到目标字符数组中，但不会自动添加终止符 \0。因此，需要保证目标缓冲区足够大，才能确保复制后的字符串以及正确的终止符。
    //总而言之，这行代码的作用是将字符串 "9:45 p.m." 复制到 flights[7].departure_str 字符数组中，并且确保不会发生缓冲区溢出问题。
    strncpy(flights[1].departure_str, "9:43 a.m.", sizeof(flights[1].departure_str) - 1);
    strncpy(flights[1].arrival_str, "11:52 a.m.", sizeof(flights[1].arrival_str) - 1);
    flights[1].departure_time = time_in_minutes(9, 43);
    flights[1].arrival_time = time_in_minutes(11, 52);

    strncpy(flights[2].departure_str, "11:19 a.m.", sizeof(flights[2].departure_str) - 1);
    strncpy(flights[2].arrival_str, "1:31 p.m.", sizeof(flights[2].arrival_str) - 1);
    flights[2].departure_time = time_in_minutes(11, 19);
    flights[2].arrival_time = time_in_minutes(13, 31);

    strncpy(flights[3].departure_str, "12:47 p.m.", sizeof(flights[3].departure_str) - 1);
    strncpy(flights[3].arrival_str, "3:00 p.m.", sizeof(flights[3].arrival_str) - 1);
    flights[3].departure_time = time_in_minutes(12, 47);
    flights[3].arrival_time = time_in_minutes(15, 0);

    strncpy(flights[4].departure_str, "2:00 p.m.", sizeof(flights[4].departure_str) - 1);
    strncpy(flights[4].arrival_str, "4:08 p.m.", sizeof(flights[4].arrival_str) - 1);
    flights[4].departure_time = time_in_minutes(14, 0);
    flights[4].arrival_time = time_in_minutes(16, 8);

    strncpy(flights[5].departure_str, "3:45 p.m.", sizeof(flights[5].departure_str) - 1);
    strncpy(flights[5].arrival_str, "5:55 p.m.", sizeof(flights[5].arrival_str) - 1);
    flights[5].departure_time = time_in_minutes(15, 45);
    flights[5].arrival_time = time_in_minutes(17, 55);

    strncpy(flights[6].departure_str, "7:00 p.m.", sizeof(flights[6].departure_str) - 1);
    strncpy(flights[6].arrival_str, "9:20 p.m.", sizeof(flights[6].arrival_str) - 1);
    flights[6].departure_time = time_in_minutes(19, 0);
    flights[6].arrival_time = time_in_minutes(21, 20);

    strncpy(flights[7].departure_str, "9:45 p.m.", sizeof(flights[7].departure_str) - 1);
    strncpy(flights[7].arrival_str, "11:58 p.m.", sizeof(flights[7].arrival_str) - 1);
    flights[7].departure_time = time_in_minutes(21, 45);
    flights[7].arrival_time = time_in_minutes(23, 58);
}



// 比较函数用于排序
int compare_flights(const void *a, const void *b) {
    Flight *flight_a = (Flight *)a;
    Flight *flight_b = (Flight *)b;
    return flight_a->departure_time - flight_b->departure_time;
}
// 二分查找最近的航班
Flight* find_closest_flight(Flight *flights, int num_flights, int user_time) {
    int low = 0;
    int high = num_flights - 1;

    if (user_time > flights[high].departure_time) {
        return NULL; // No flight available if user_time is later than the last flight's departure time
    }

    while (low < high) {
        int mid = (low + high) / 2;
        if (flights[mid].departure_time < user_time) {
            low = mid + 1;
        } else {
            high = mid;
        }
    }

    return &flights[low];
}
//查找最近的航班对应的索引
int find_closest_flight01(const Flight flights[], int user_time) {
    int closest_index = -1; //初始化为无效索引
    int min_diff = 1440; //初始化为最大值(24小时)，用于比较差值
    //在 for 循环中，程序将计算用户输入时间与每个航班出发时间之间的差值
    for (int i = 0; i < NUM_FLIGHTS; i++) {
        //确保只考虑出发时间晚于或等于用户输入时间的航班
        if (flights[i].departure_time >= user_time) {
            int diff = flights[i].departure_time - user_time;
            //如果输入的大于24小时的，就是错误数据不需要处理
            if (diff < min_diff) {
                min_diff = diff;
                closest_index = i;
            }
        }

    }
    return closest_index;

}
// 打印航班信息
void print_flight_info(const Flight *flight) {
    if (flight) {
        printf("Closest departure time is %s, arriving at %s.\n",
               flight->departure_str, flight->arrival_str);
    } else {
        printf("No available flights.\n");
    }
}
//打印航班信息
void print_flight_info01(const Flight flight) {
    printf("Closest departure time is %s, arriving at %s.\n", flight.departure_str, flight.arrival_str);
}
// 输入时间并验证格式
int input_time(int *hours, int *minutes) {
    //以下代码存在的问题：
    //输入错误时的处理不够清晰。
    //当用户提供无效的时间格式时，代码只打印了一个简单的错误消息，并返回 0。但是，没有提供更具体的信息来指示实际发生了什么错误，也没有给用户提供重新输入的机会。
    //对于输入缓冲区的读取和解析，没有正确处理可能的溢出。
    //fgets 函数用于从标准输入读取用户输入的字符串，但它并没有限制输入的长度。这可能导致输入溢出。同样地，sscanf 函数也没有检查解析结果是否成功，从而可能导致未初始化的指针被访问
    //优化方案：
    // 添加了适当的错误处理和错误消息，以提供更详细的信息和重新输入的机会。
    //在 fgets 函数中指定了输入缓冲区的大小，以避免溢出问题。
    //检查 sscanf 函数的返回值，确保成功解析了两个整数。
    //添加了对小时和分钟的范围进行验证的条件检查。
//    char input[6];
//    printf("Enter a 24-hour time (HH:MM): ");
//    if (!fgets(input, sizeof(input), stdin) || sscanf(input, "%d:%d", hours, minutes) != 2 || *hours < 0 || *hours > 23 || *minutes < 0 || *minutes > 59) {
//        printf("Invalid time format.\n");
//        return 0;
//    }
//    return 1;
    char input[10];
    printf("Enter a 24-hour time (HH:MM): ");
    //fgets(input, sizeof(input), stdin) 用于从标准输入读取一行字符串，并将其存储在 input 数组中。
    //input 是一个字符数组，用于存储输入的字符串。
    //sizeof(input) 返回 input 数组的大小，即可以容纳的最大字符数。
    //stdin 是标准输入流。
    //!fgets(input, sizeof(input), stdin) 检查 fgets 的返回值是否为假（即读取失败）。
    //如果读取失败，表示发生了错误或到达了文件末尾。
    //在这种情况下，代码打印出错误消息 "Error reading input."，并返回 0。
    //如果 fgets 成功读取了输入行，则继续执行后续的代码。
    //这段代码的目的是读取用户输入的字符串，并存储在 input 数组中。通过检查 fgets 的返回值，
    // 可以判断是否成功读取了输入。如果读取失败，代码会打印错误消息并返回 0，以指示出现了错误。
    if (!fgets(input, sizeof(input), stdin)) {
        printf("Error reading input.\n");
        return 0;
    }

    // 替换全角冒号字符为标准冒号字符
    //在 C 语言中，无法直接使用全角字符进行比较或替换.所以只能使用了对应于全角冒号字符的 Unicode 编码 \xEF\xBC\x9A 进行了比较。当检测到该编码时，
    // 我们将其替换为标准冒号字符，并相应地调整字符串的长度和内容。
    //请注意，这种方法仍然是一种特定于编码的解决方案，依赖于全角冒号字符的 Unicode 编码。
    // 因此，在不同的环境或使用不同的输入方式时，可能需要针对相应的编码进行适当的调整
    size_t len = strlen(input);
    for (size_t i = 0; i < len; i++) {
        if (input[i] == '\xEF' && input[i+1] == '\xBC' && input[i+2] == '\x9A') {
            input[i] = ':';
            strcpy(&input[i+1], &input[i+3]);
            len -= 2;
        }
    }

    if (sscanf(input, "%d:%d", hours, minutes) != 2) {
        printf("Invalid time format.\n");
        return 0;
    }

    if (*hours < 0 || *hours > 23 || *minutes < 0 || *minutes > 59) {
        printf("Invalid time range.\n");
        return 0;
    }

    return 1;
}

int main() {
//    Flight flights[NUM_FLIGHTS];
//    initialize_flight01(flights);
//
//    int hours, minutes;
//    printf("Enter a 24-hour time: ");
//    scanf("%d:%d", &hours, &minutes);
//
//    int user_time = time_in_minutes(hours, minutes);
//    int closest_index = find_closest_flight01(flights, user_time);
//    if (closest_index != -1) {
//        print_flight_info01(flights[closest_index]);
//    } else {
//        printf("No available flights.\n");
//    }

    //使用方法进一步优化的案例
    //灵活性：使用动态内存分配，可以根据需要动态调整航班数量。
    //内存效率：使用指针操作内存，更加高效。
    //模块化设计：代码结构清晰，各个功能模块分离，提高了可维护性和复用性。
    //错误处理：处理各种可能的异常情况，增强了代码的鲁棒性
    Flight *flights = malloc(NUM_FLIGHTS * sizeof(Flight));
    if (flights == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    initialize_flights(flights);
    //qsort 函数具有以下特点、优势和不足：
    //特点：
    //快速排序算法：qsort 函数使用快速排序算法来对数组进行排序。快速排序算法通常被认为是一种高效的排序算法，其平均时间复杂度为 O(nlogn)。
    //通用性：qsort 函数是一个通用的排序函数，可以用于对各种类型的数组进行排序，只需通过比较函数来适配不同的数据类型。
    //原地排序：qsort 函数对原始数组进行排序，不需要额外的内存空间。这意味着它可以节省存储空间，并且在排序大型数组时表现良好。
    //优势：
    //
    //高效性能：由于 qsort 函数采用快速排序算法，它具有较好的平均时间复杂度。在大多数情况下，它能够提供高效的排序结果。
    //灵活性：qsort 函数允许用户定义自己的比较函数，因此可以根据实际需求对元素进行自定义排序。这使得 qsort 在处理不同类型的数据和排序规则时非常灵活。
    //不足：
    //
    //不稳定性：快速排序算法本身是不稳定的，这也导致 qsort 函数是不稳定的。在排序过程中，相等的元素可能会交换位置，导致它们的相对顺序发生变化。
    //对大型数组的性能影响：虽然 qsort 是一个高效的排序算法，但在处理非常大的数组时，可能会受到内存访问模式的限制。由于快速排序算法在最坏情况下的时间复杂度为 O(n^2)，可能会导致性能下降。
    //综上所述，qsort 函数是一个通用、高效的排序函数，适用于各种类型的数组。它采用快速排序算法，具有较好的性能和灵活性。但需要注意的是，它是一个不稳定的排序算法，并且在处理大型数组时可能会受到性能影响。
    qsort(flights, NUM_FLIGHTS, sizeof(Flight), compare_flights);

    int hours, minutes;
    if (!input_time(&hours, &minutes)) {
        free(flights);
        return 1;
    }

    int user_time = time_in_minutes(hours, minutes);
    Flight *closest_flight = find_closest_flight(flights, NUM_FLIGHTS, user_time);

    print_flight_info(closest_flight);

    free(flights);
    return 0;

}