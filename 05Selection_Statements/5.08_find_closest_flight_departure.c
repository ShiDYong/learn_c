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
#define TIME_STR_SIZE 10 // 使字符串足够长以避免溢出，会出现打印乱码的情况

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
    strcpy(flights[0].departure_str, "8:00 a.m.");
    strcpy(flights[0].arrival_str, "10:16 a.m.");
    flights[0].departure_time = time_in_minutes(8, 0);
    flights[0].arrival_time = time_in_minutes(10, 16);

    strcpy(flights[1].departure_str, "9:43 a.m.");
    strcpy(flights[1].arrival_str, "11:52 a.m.");
    flights[1].departure_time = time_in_minutes(9, 43);
    flights[1].arrival_time = time_in_minutes(11, 52);

    strcpy(flights[2].departure_str, "11:19 a.m."); // 修正索引
    strcpy(flights[2].arrival_str, "1:31 p.m.");
    flights[2].departure_time = time_in_minutes(11, 19);
    flights[2].arrival_time = time_in_minutes(13, 31);

    strcpy(flights[3].departure_str, "12:47 p.m.");
    strcpy(flights[3].arrival_str, "3:00 p.m.");
    flights[3].departure_time = time_in_minutes(12, 47);
    flights[3].arrival_time = time_in_minutes(15, 0);

    strcpy(flights[4].departure_str, "2:00 p.m.");
    strcpy(flights[4].arrival_str, "4:08 p.m.");
    flights[4].departure_time = time_in_minutes(14, 0);
    flights[4].arrival_time = time_in_minutes(16, 8);

    strcpy(flights[5].departure_str, "3:45 p.m.");
    strcpy(flights[5].arrival_str, "5:55 p.m.");
    flights[5].departure_time = time_in_minutes(15, 45);
    flights[5].arrival_time = time_in_minutes(17, 55);

    strcpy(flights[6].departure_str, "7:00 p.m.");
    strcpy(flights[6].arrival_str, "9:20 p.m.");
    flights[6].departure_time = time_in_minutes(19, 0);
    flights[6].arrival_time = time_in_minutes(21, 20);

    strcpy(flights[7].departure_str, "9:45 p.m.");
    strcpy(flights[7].arrival_str, "11:58 p.m.");
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
//查找最近的航班
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
    char input[6];
    printf("Enter a 24-hour time (HH:MM): ");
    if (!fgets(input, sizeof(input), stdin) || sscanf(input, "%d:%d", hours, minutes) != 2 || *hours < 0 || *hours > 23 || *minutes < 0 || *minutes > 59) {
        printf("Invalid time format.\n");
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