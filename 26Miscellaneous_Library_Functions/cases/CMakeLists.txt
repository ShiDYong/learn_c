#编译器链接OpenSSL库
find_package(OpenSSL REQUIRED)
include_directories(${OPENSSL_INCLUDE_DIR})

#生成可执行文件
add_executable(libray_function rand_test.c)
target_link_libraries(libray_function ${OPENSSL_LIBRARIES})
