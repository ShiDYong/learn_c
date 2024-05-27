
# 查找log4c库
#include_directories(/opt/homebrew/opt/log4c/include)
#link_directories(/opt/homebrew/opt/log4c/lib)

# 设置源文件


# 添加可执行文件并链接log4c库
#add_executable(chapter5 ${SOURCE_FILES})
add_executable(chapter5    chapter5_cases.c
        chapter5_programming.c
        chapter5_exercises.c
        broker.c
        calculateTax.c
        5.07_find_largest_smallest.c)
#target_link_libraries(chapter5 log4c)
