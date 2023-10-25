#生成可执行文件
add_executable(pro_exer pro_exer_04-05.c pro_exer_01-03.c)
#链接公共库
target_link_libraries(pro_exer Scanf_lib)
