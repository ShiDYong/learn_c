///********************************************************************************
//* @author: mason shi
//* @date: 2024/4/27 11:35
//* @version: 1.0
//* @description: 通过使用日志优化输出
//********************************************************************************/
//#include <stdio.h>
//#include <log4c.h>
//#include <stdarg.h>
//#include <stdlib.h> // 添加头文件以使用 exit 函数
//
//
//
////日志结构体，包含日志记录器和初始化状态
//typedef struct {
//    log4c_category_t *logger;
//    int initialized;
//} Logger;
//
//// 初始化日志系统
//int initialize_logger(Logger *logger) {
//    // 初始化log4c，加载配置文件
//    if (log4c_init()) {
//        fprintf(stderr, "Failed to initialize log4c.\n");
//        return -1; // 初始化失败
//    }
//
//    // 加载配置文件
//    if (log4c_load("/Users/yongshi/Downloads/MyCode/C_Programming/05Selection_Statements/log4crc.properties")) {
//        fprintf(stderr, "Failed to load log4c configuration file.\n");
//        log4c_fini(); // 清理log4c
//        return -1; // 加载配置文件失败
//    }
//
//    // 获取日志记录器
//    logger->logger = log4c_category_get("mylogger");
//    if (logger->logger == NULL) {
//        fprintf(stderr, "Failed to get logger.\n");
//        log4c_fini(); // 清理log4c
//        return -1; // 获取日志记录器失败
//    }
//
//    logger->initialized = 1; // 标记为已初始化
//    return 0;
//}
///*
// * 记录日志的函数
// */
//// 记录日志的函数，可以指定日志级别和打印异常时的错误参数
//void log_message(Logger *logger, log4c_priority_level_t level, const char *format, ...) {
//    // 确保日志系统已初始化
//    if (!logger->initialized) {
//        return; // 日志系统未初始化，直接返回
//    }
//
//    va_list args;
//    va_start(args, format);
//
//    // 将格式化的字符串写入缓冲区
//    char message[1024];
//    vsprintf(message, format, args);
//
//    va_end(args);
//
//    // 记录日志
//    switch (level) {
//        case LOG4C_PRIORITY_DEBUG:
//            log4c_category_debug(logger->logger, "%s", message);
//            break;
//        case LOG4C_PRIORITY_INFO:
//            log4c_category_info(logger->logger, "%s", message);
//            break;
//        case LOG4C_PRIORITY_WARN:
//            log4c_category_warn(logger->logger, "%s", message);
//            break;
//        case LOG4C_PRIORITY_ERROR:
//            log4c_category_error(logger->logger, "%s", message);
//            break;
//        default:
//            log4c_category_debug(logger->logger, "%s", message);
//            break;
//    }
//}
//
////关闭日志系统
//void finalize_logger(Logger *logger) {
//    //确保日志系统已经初始化
//    if (!logger->initialized) {
//        return;
//    }
//    //关闭
//    log4c_fini();
//    logger->initialized = 0;
//}
//
//// 结构体，包含委托信息
//typedef struct {
//    float commission;
//    const char *key_date;
//} CommissionInfo;
//
//// 计算原始经纪人的佣金
//CommissionInfo calculate_original_broker_commission(float value_of_trade) {
//    float commission;
//    const char *key_date;
//
//    if (value_of_trade < 2500.00f) {
//        commission = 30.00f + value_of_trade * 0.017f;
//        key_date = "First key date";
//    } else if (value_of_trade < 6250.00f) {
//        commission = 56.00f + value_of_trade * 0.0066f;
//        key_date = "Second key date";
//    } else if (value_of_trade < 20000.00f) {
//        commission = 76.00f + value_of_trade * 0.0034f;
//        key_date = "Third key date";
//    } else if (value_of_trade < 50000.00f) {
//        commission = 100.00f + value_of_trade * 0.0022f;
//        key_date = "Fourth key date";
//    } else if (value_of_trade < 500000.00f) {
//        commission = 155.00f + value_of_trade * 0.0011f;
//        key_date = "Fifth key date";
//    } else {
//        commission = 255.00f + value_of_trade * 0.0009f;
//        key_date = "Sixth key date";
//    }
//
//    if (commission < 39.00f)
//        commission = 39.00f;
//
//    CommissionInfo info = {commission, key_date};
//    return info;
//}
//
//
//// Function to validate user input for number of shares and price per share
//int validate_input(int *num_shares, float *price_per_share, Logger *logger) {
//
//    printf("Enter price per number shares: ");
//    if (scanf("%d", num_shares) != 1 || *num_shares <= 0) {
//        log_message(logger, LOG4C_PRIORITY_ERROR, "Input Enter price per number shares ERROR: %d", *num_shares);
//        return 0;
//    }
//
//    printf("Enter price per share: ");
//    if (scanf("%f", price_per_share) != 1 || *price_per_share <= 0.0f) {
//        log_message(logger, LOG4C_PRIORITY_ERROR, "Input Enter price per number shares ERROR: %02.f", *price_per_share);
//        return 0;
//    }
//    log_message(logger, LOG4C_PRIORITY_INFO, "Number shares and price per share: %d %02.f", *num_shares,
//                *price_per_share);
//    return 1;
//}
//
///*
//int main(int argc, char *argv[]) {
//
//    //初始化日志系统
//    Logger logger;
//    logger.initialized = 0;
//    if (initialize_logger(&logger)) {
//        fprintf(stderr, "Failed to initialize logger.\n");
//        return -1;
//    }
//
//    int num_shares;
//    float price_per_share, value_of_trade;
//    CommissionInfo original_broker_commission;
//
//    // 验证用户输入
//    if (!validate_input(&num_shares, &price_per_share, &logger)) {
//        finalize_logger(&logger);
//        return 1;
//    }
//
//    // 计算交易额
//    value_of_trade = num_shares * price_per_share;
//
//    // 计算原始经纪人的佣金
//    original_broker_commission = calculate_original_broker_commission(value_of_trade);
//
//    // 记录佣金和关键日期信息
//    log_message(&logger, LOG4C_PRIORITY_INFO, "Original Broker's Commission: $%.2f",
//                original_broker_commission.commission);
//    log_message(&logger, LOG4C_PRIORITY_INFO, "Key Date: %s", original_broker_commission.key_date);
//
//    // 结束日志系统
//    finalize_logger(&logger);
//
//}
//*/
