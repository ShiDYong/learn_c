#生成可执行文件
add_executable(IO_exerices exerices.c byte_pointer.c)
#链接公共库
target_link_libraries(IO_exerices Scanf_lib)
