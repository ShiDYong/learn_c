#生成可执行文件
add_executable(IO_cases case_stream_file.c fcopy.c file_location.c invclear.c test.c)
#链接公共库
target_link_libraries(IO_cases Scanf_lib)
