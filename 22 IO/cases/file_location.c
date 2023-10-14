/********************************************************************************
* @author: mason shi
* @date: 2023/9/30 23:22
* @version: 1.0
* @description:文件定位常用的函数
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>

void test_get_position();

int main(void) {
    test_get_position();
    return 0;
}


/**
 * 获取当前文件的位置函数：
 * 每个流都有相关联的文件位置(file position)。打开文件时，会将文件位置设置在文件的起始处。但如果文件按追加模式
 * 打开，初始的文件位置可以在文件起始处，也可以在文件末尾，这依赖于具体的实现。然后，在执行读或写操作时，文件位置会
 * 自动推进，并且允许按照顺序贯穿整个文件。
 */
void test_get_position() {
    FILE *file;
    //In C, the fgetpos function is a standard library function used to get the current file position indicator
    // in a stream and store it in a fpos_t object. This function is used for file positioning and is particularly
    // useful when you need to record and later restore the file position within a stream
    //Here is the syntax of the fgetpos function:
    //int fgetpos(FILE *stream, fpos_t *position);
    //Parameters:
    //stream: A pointer to the file stream.
    //position: A pointer to a fpos_t object where the current file position will be stored.
    //Return Value:
    //If successful, fgetpos returns zero (0).
    //If an error occurs, it returns a non-zero value.
    if ((file = fopen("22 IO/cases/fopen.txt", "r")) == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fpos_t position;
    // Get the current file position and store it in 'position'
    if (fgetpos(file, &position) != 0) {
        perror("Error getting file position");
        fclose(file);
        exit(EXIT_FAILURE);
    }
    // Get the current file position
    printf("Current file position: %11lld\n",  position);
    fclose(file); // Close the file
    // Perform some operations here that may change the file position
    /*
     2.In the C programming language, the fseek function is a standard library function used to move the file position
     indicator to a specified position within a file. It allows you to seek to a specific byte location within the
     file, enabling you to read from or write to different parts of the file. The basic syntax of the fseek function is as follows:
    int fseek(FILE *stream, long int offset, int origin);
    Parameters:
    stream: A pointer to the file stream for which you want to set the file position indicator.
            offset: A long int value representing the offset (number of bytes) from the reference point specified by origin. A positive offset moves the position forward, and a negative offset moves it backward.
            origin: An integer that specifies the reference point for the offset. It can take one of the following values:
    SEEK_SET (or 0): The offset is relative to the beginning of the file.
    SEEK_CUR (or 1): The offset is relative to the current file position.
    SEEK_END (or 2): The offset is relative to the end of the file.
    Return Value:
    fseek returns 0 on success. If an error occurs, it returns a non-zero value.
*/
    FILE *fp = fopen("22 IO/cases/fopen_test.txt", "r"); // Open file for reading
    if (fp != NULL) {
        int offset = 2L; // Number of bytes to seek forward
        int origin = SEEK_SET; // Seek from the beginning of the file，为了移动到文件起始处，搜索的方向将为SEEK_SET
        if (fgetpos(fp, &position) == 0)
            printf("Current file position: %11lld\n", (long long) position);
        if (fseek(fp, offset, origin) == 0) {
            // Successfully moved the file position indicator
            char buffer[100];
            //获取当前文件位置
            if (fgetpos(fp, &position) == 0)
                printf("Current file position: %11lld\n", (long long) position);

            if (fgets(buffer, sizeof(buffer), fp) != NULL) {
                printf("Read from the new position: %s\n", buffer);
                //Rewind the file to the beginning
                fseek(fp, 0, SEEK_SET);
                if (fgetpos(fp, &position) == 0)
                    printf("Current file position: %11lld\n", (long long) position);
            } else {
                perror("Error reading from the new position");
            }
        } else {
            perror("Error seeking in the file");
        }
        fclose(fp); // Close the file
    } else {
        perror("Error opening file");
    }
    //3.rewind函数：把文件位置设置在起始处。调用rewind(fp)几乎等价于fseek(fp,0L,SEEK_SET),两者的差异是rewind函数不返回值
    //但会为fp清除错误指示器.
    //4.ftell函数以长整数返回当前文件位置。如果发生错误，ftell函数会返回-1L，并且把错误吗存储到errno中。ftell可能会存储返回的值
    //并且稍后将其提供给fseek函数调用，这也使返回前面的文件位置成为可能。如果fp是二进制流，那么ftell(fp)会以字节计数来返回当前位置，其中0表示文件的起始处。
    //fseek函数和ftell函数都有一个问题：它们只能用于文件位置可以存储在长整数中的文件，为了用于非常大的文件，C语言提供了另外两个函数：fgetpos函数和fsetpos函数
    //用于处理大型文件，fpos_t类型值不一定就是整数，比如，它可以是结构。

}

