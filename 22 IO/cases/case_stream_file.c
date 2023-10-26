/********************************************************************************
* @author: mason shi
* @date: 2023/9/24 15:51
* @version: 1.0
* @description: 第22章输入和输出
 *          在C语言中，术语流(流)表示任意输入的源或任意输出的目的地。流提供了一种方便且统一的
 *          方式来执行C中的输入和输出操作。这些流常常表示存储在不同介质(如硬盘驱动器，CD、DVD和闪存)
 *          上的文件，但也很容易和不存储文件的设备(如网络端口、打印机等)相关联。
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define N 300

void file_operation();

void test_freopen();

void single_character_output();

void single_character_input();

void test_buffering();

void line_output_input();

void block_output_input();

void block_output_input();

/**
 * 通过定义带有两个形式参数的main函数来访问命令行参数：
 * @param argc
 * @param argv
 * @return
 */
int main(int argc, char *argv[]) {
    // file_operation();
    test_freopen();
    //  FILE *fp;
    // argc is the count of command-line arguments
    // argv is an array of strings containing the arguments
//    printf("The number of command-line arguments is: %d\n", argc);
//    for (int i = 0; i < argc; i++)
//        printf("Argument %d: %s\n", i, argv[i]);
//
//
//    if (argc != 2) {
//        printf("usage: canopen filename.\n");
//        exit(EXIT_FAILURE);
//
//    }
//    if ((fp = fopen(argv[1], "r")) == NULL) {
//        printf("%s can't be opened\n", argv[1]);
//        exit(EXIT_FAILURE);
//    }
//    printf("%s can be opened\n", argv[1]);
//    fclose(fp);
    //test_buffering();
    //single_character_output();
    //single_character_input();
    // line_output_input();
    //block_output_input();
    return 0;
}


/**
 * 22.1:
 * 1.C程序中对流的访问是通过文件指针(file pointer)实现的。此指针的类型FILE*（FILE类型在<stdio.h>中声明)。它代表
 *   一个文件流，是一种用于对文件和其他数据源输入和输出操作的数据结构。FILE结构包含有关文件或流的信息，包括它的文件定位符、
 *   指向相关缓冲(如果有的话)的指针、记录是否发生流读/写错误的错误指示和记录文件是否结束的文件结束符。
 * 2.<stdio.h>提供了3个标准流。这3个标准流可以直接使用，不需要进行声明,也不用打开或关闭它们。
 *    文件指针              流                       默认的含义
 *    stdin                标准输入                  键盘
 *    stdout               标准输出                  屏幕
 *    stderr               标准误差                  屏幕
 * 3.重定向
 */
void test_direction() {
    /*
     * text file和binary file的区别：
     * 文本文件：
        1.人类可读：文本文件以人类可读的格式存储数据。 数据通常使用字符表示，它可以包括字母、数字、符号和空格。
        2.行尾字符：文本文件通常使用特殊的行尾字符（例如，换行符，如 Unix/Linux 中的 \n 或 Windows 中的 \r\n）来指示每行的结尾。 这些字符有助于格式化文本以供显示和编辑。
        3.无二进制数据：文本文件不适合存储二进制数据，例如图像、音频或可执行代码，因为由于存在文本特定字符（例如换行符和空终止符），数据可能会被误解。
        示例：源代码文件（例如，C 源代码文件）、配置文件、CSV 文件、JSON 文件、纯文本文档和 HTML 文件是文本文件的示例。
        当您在 C 中读取或写入文本文件时，通常使用 fscanf、fprintf、fgets 和 fputs 等函数来处理文本数据。
      二进制文件：
        1.二进制表示：二进制文件以其原始二进制形式存储数据。 它们不使用任何特殊格式或行尾字符。 数据以字节序列的形式存储，与内存中的情况完全相同。
        2.无字符编码：二进制文件不应用字符编码，因此可以存储任何类型的数据，包括图像、音频、视频和编译的程序代码等非文本数据。
        3.没有人类可读性：二进制文件不是人类可读的。 当您使用文本编辑器打开二进制文件时，您可能会看到一串难以理解的字符。
        4.示例：图像文件（例如 JPG、PNG）、音频文件（例如 MP3、WAV）、视频文件（例如 MP4、AVI）、数据库文件和编译的可执行文件（例如 .exe）都是二进制文件的示例 。
        在 C 中处理二进制文件时，通常使用 fread 和 fwrite 等函数来读取和写入二进制数据。 这些函数允许您读取/写入原始字节，而无需对数据进行任何解释。
       总之，C 语言中的文本文件和二进制文件之间的主要区别在于数据的存储和表示方式。 文本文件使用人类可读的基于字符的表示形式和行尾字符，而二进制文件以其原始二进制形式存储数据，
       无需任何特殊格式。 文本文件和二进制文件之间的选择取决于您正在使用的数据类型和应用程序的要求.
     * */

}

/**
 * 22.2文件操作：
 */
void file_operation() {
    //1.打开文件：函数原型：FILE *fopen(const char *filename, const char *mode);
    FILE *file_ptr;
    char str[N + 1];
    // Open a file named "example.txt" for writing
    //file_ptr = fopen("22 IO/cases/fopen_test.txt", "w");
    file_ptr = fopen("22 IO/cases/fopen_test.txt", "rt");
    /*
     filename: A string containing the name of the file you want to open, including the path if necessary.
      mode: A string specifying the mode in which you want to open the file. The mode can be one of the following:
      在调用 fopen() 函数时，这些信息都必须提供，称为“文件打开方式”。最基本的文件打开方式有以下几种：
                            控制读写权限的字符串（必须指明）
    打开方式        	说明
    "r"	            以“只读”方式打开文件。只允许读取，不允许写入。文件必须存在，否则打开失败。
    "w" 	        以“写入”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
    "a"	            以“追加”方式打开文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
    "r+"	        以“读写”方式打开文件。既可以读取也可以写入，也就是随意更新文件。文件必须存在，否则打开失败。
    "w+"	        以“写入/更新”方式打开文件，相当于w和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么清空文件内容（相当于删除原文件，再创建一个新文件）。
    "a+"	        以“追加/更新”方式打开文件，相当于a和r+叠加的效果。既可以读取也可以写入，也就是随意更新文件。如果文件不存在，那么创建一个新文件；如果文件存在，那么将写入的数据追加到文件的末尾（文件原有的内容保留）。
                    控制读写方式的字符串（可以不写）
    打开方式	说明
    "t"	文本文件。如果不写，默认为"t"。
    "b"	二进制文件。
    调用 fopen() 函数时必须指明读写权限，但是可以不指明读写方式（此时默认为"t"）。
    读写权限和读写方式可以组合使用，但是必须将读写方式放在读写权限的中间或者尾部（换句话说，不能将读写方式放在读写权限的开头）。例如：
    将读写方式放在读写权限的末尾："rb"、"wt"、"ab"、"r+b"、"w+t"、"a+t"
    将读写方式放在读写权限的中间："rb+"、"wt+"、"ab+"
    整体来说，文件打开方式由 r、w、a、t、b、+ 六个字符拼成，各字符的含义是：
    r(read)：读
    w(write)：写
    a(append)：追加
    t(text)：文本文件
    b(binary)：二进制文件
    +：读和写*/
    if (file_ptr == NULL) {
        printf("Error opening file!\n");
        exit(EXIT_FAILURE);

    }
    // Write data to the file using fprintf
    // fprintf(file_ptr, "This is test message.\n");
    //循环读取文件的每一行数据
    while (fgets(str, N, file_ptr) != NULL)
        printf("%s", str);
    // Close the file when done
    //成功关闭了文件，fclose函数会返回零；否则，它会返回错误代码(在<stdio.h>中定义的宏)
    fclose(file_ptr);
}

/**
 * 为打开的文件添加流：
 *  the freopen function is used to redirect file streams, allowing you to change where the standard input,
 *  standard output, or standard error are directed. This can be useful for redirecting input or output to
 *  files instead of the console, or for switching between different input or output sources during program
 *  execution.The freopen function is part of the standard C library and is typically used with three arguments:
 *  FILE *freopen(const char *filename, const char *mode, FILE *stream);
 */
void test_freopen() {
    FILE *file = freopen("22 IO/cases/fopen_test.txt", "a+", stdout);
    if (file == NULL) {
        perror("Failed to open file.");
        exit(EXIT_FAILURE);
    }
    printf("This will be written to the file instead fo the console.\n");
    fclose(file);
}


/**
 * 文件缓冲流
 */
void test_buffering() {
    //1.void setbuf(FILE *stream, char *buffer);
    //用于指定用于文件流上的输入或输出操作的缓冲区。 它允许您控制流是完全缓冲、行缓冲还是无缓冲。 缓冲可以提高文件 I/O 操作的效率
    FILE *fp;
    if ((fp = fopen("22 IO/cases/fopen_test.txt", "a+")) == NULL) {
        perror("Failed to open file.");
        exit(EXIT_FAILURE);
    }
    //Define a buffer
    char buffer[1024];
    // Set the file to fully buffered mode with the provided buffer
    setbuf(fp, buffer);
    // Write data to the file
    fprintf(fp, "This is some text.\n");
    fprintf(fp, "This is another line.\n");

    //int setvbuf(FILE *stream, char *buffer, int mode, size_t size);
    //用于设置文件流的缓冲模式和大小。 与 setbuf 函数相比，它提供了更多对缓冲的控制，允许您指定缓冲区大小和缓冲类型（完全缓冲、行缓冲或无缓冲
    //stream: A pointer to the FILE stream for which you want to set the buffer and mode.
    //buffer: A pointer to the character array (buffer) that you want to use for buffering. If buffer is NULL,
    // the function will allocate an automatic buffer.
    //mode: An integer indicating the buffering mode. It can take one of the following values:
    //_IOFBF: Full buffering (buffered mode).当缓冲区为空时，从流读入数据；当缓冲区满时，向流写入数据
    //_IOLBF: Line buffering.每次从流读入一行数据或向流写入一行数据
    //_IONBF: No buffering (unbuffered mode).直接从流读入数据或者直接向流写入数据，而没有缓冲区
    //size: The size of the buffer in bytes. This argument is ignored in unbuffered mode or if buffer is not NULL.
    int result = setvbuf(fp, buffer, _IOFBF, sizeof(buffer));// Set the file to full buffering with the provided buffer
    if (result != 0) {
        perror("Failed to set buffering mode");
        exit(EXIT_FAILURE);
    }
    fprintf(fp, "This is some text by mason.\n");
    fprintf(fp, "This is another line by mason.\n");
    // Flush the buffer, ensuring the data is written immediately to the file
    fflush(fp);
    fprintf(fp, "This is line 3.\n");

    fclose(fp);

    //删除文件
    const char *filename = "example.txt";

    // Attempt to delete the file
    if (remove(filename) == 0) {
        printf("File '%s' deleted successfully.\n", filename);
    } else {
        perror("Error deleting file");
    }

}

/**
 * 单个字符的输出:
 * 这里的函数把字符作为int类型而非char类型的值来处理。这样做的原因之一就是，输入函数是通过返回EOF来说明文件末尾(或错误)情况的，
 * 而EOF又是一个负的整型常量。
 */
void single_character_output() {
    //1.fputc (File Put Character):
    //int fputc(int character, FILE *stream) is a library function used to write a single character (specified by the character
    // argument)to the file pointed to by the stream.It returns the character written if successful, or EOF (an integer constant
    // representing end-of-file) if an error occurs.
    FILE *file = fopen("22 IO/cases/fopen_test.txt", "a+");
    if (file != NULL) {
        int ch = 'A'; //把A写入到文件fopen_test.txt
        if (fputc(ch, file) != EOF)
            printf("Character written successful.\n");
        else
            printf("Error writing character to the file.\n");
        // fclose(file);
    }

    //2.putc (Put Character):
    //int putc(int character, FILE *stream) is essentially the same as fputc. It writes a single
    // character to the file specified by the stream.
    //Like fputc, it returns the character written if successful, or EOF if an error occurs.
    //The putc function is often used interchangeably with fputc and is typically a macro defined in
    // the C standard library
    // as #define putc(c, stream) fputc(c, stream).
    if (file != NULL) {
        int ch = 'B'; //把A写入到文件fopen_test.txt
        if (putc(ch, file) != EOF)
            printf("Character written successful.\n");
        else
            printf("Error writing character to the file.\n");
        fclose(file);
    }
    //3.putchar (Put Character to Standard Output):
    //int putchar(int character) is used to write a single character (specified by the character argument) to the standard
    //output (typically the console).
    //It returns the character written if successful or EOF if an error occurs.
    //putchar is often used for simple character output to the console.
    int ch = 'D';
    if (putchar(ch) != EOF) {
        printf("\n没有指定就是标准流，即输出到屏幕.\n");
        printf("Character written to standard output successfully.\n");
    } else {
        printf("Error writing character to standard output.\n");
    }
}

/**
 * 单字符的输入函数
 */
void single_character_input() {
    FILE *file;
    //1.fgetc (File Get Character):
    //int fgetc(FILE *stream) is a library function used to read a single character from the file pointed to by the stream.
    //It returns the character read as an integer if successful, or EOF (an integer constant representing end-of-file)
    // if an error occurs or if the end of the file is reached.
    if ((file = fopen("22 IO/cases/fopen_test.txt", "r+")) != NULL) {
        int ch = fgetc(file);
        if (ch != EOF)
            printf("Character read: %c\n", ch);
        else
            printf("Error reading character from the file.\n");
        // fclose(file);
    }
    //2.getc (Get Character):
    //int getc(FILE *stream) is essentially the same as fgetc. It reads a single character from the file specified by the stream.
    //Like fgetc, it returns the character read as an integer if successful, or EOF if an error occurs or if the end of the file is reached.
    //The getc function is often used interchangeably with fgetc and is typically a macro defined in the C standard library as
    // #define getc(stream) fgetc(stream).
    if ((file = fopen("22 IO/cases/fopen_test.txt", "r+")) != NULL) {
        int ch;
        if ((ch = getc(file)) != EOF)
            printf("Character read: %c\n", ch);
        else
            printf("Error reading character from the file.\n");
        //fclose(file);
    }
    //3.getchar (Get Character from Standard Input):
    //int getchar(void) is used to read a single character from the standard input (typically the console).
    //It returns the character read as an integer if successful, or EOF if an error occurs or if the end of the input is reached.
    //getchar is often used for simple character input from the console.
//    int ch = getchar();
//    if (ch != EOF)
//        printf("Character read: %c\n", (char) ch);
//    else {
//        printf("Error reading character from standard input.\n");
//
//    }

    //4.ungetc (Unget Character):
    //int ungetc(int character, FILE *stream) is a function used to push a character back into the input stream pointed to by stream.
    // This allows you to "unread" a character, making it available to be read again.
    //It returns the character pushed back if successful, or EOF if an error occurs or if there is no room in the input buffer.
    //ungetc is typically used for implementing simple tokenizers or parsers that need to temporarily put characters back into the input stream.
    int ch;
    if (file != NULL) {
        ch = fgetc(file); // Read a character
        if (ch != EOF) {
            printf("Character read: %c\n", (char) ch);
            ungetc(ch, file); // Push the character back into the stream
            ch = fgetc(file); // Read the character again
            if (ch != EOF) {
                printf("Character read again: %c\n", (char) ch);
            } else {
                printf("Error reading character from the file.\n");
            }
        } else {
            printf("Error reading character from the file.\n");
        }
        fclose(file);
    }

}

/**
 * 行的输入和输出:
 * 读和写行的库函数，虽然这些函数也可有效第用于二进制的流，但是它们多数用于文本流
 */
void line_output_input() {
    //1.fputs (File Put String):
    //int fputs(const char *str, FILE *stream) is a library function used to write a string
    // (specified by the str argument)to the file pointed to by the stream.
    //It does not automatically append a newline character ('\n') to the output,
    // so if you want to start a new line, you need to include the newline character in the string explicitly.
    //It returns a non-negative value (typically 0) if successful, or EOF (an integer constant representing end-of-file) if an error occurs.
    FILE *file = fopen("../cases/fopen.txt", "wb");
    if (file != NULL) {
        const char *str = "Hello World1";
        if (fputs(str, file) != NULL)
            printf("String written successfully.\n");
        else
            printf("Error writing string to the file.\n");
        fclose(file);
    }
    //2.puts (Put String):
    //int puts(const char *str) is used to write a string (specified by the str argument)
    // to the standard output (typically the console).
    //Unlike fputs, puts automatically appends a newline character ('\n') to the output,
    // so it effectively starts a new line after writing the string.
    //It returns a non-negative value if successful, or EOF if an error occurs.
    const char *Str = "Optimum is an American telecommunications brand owned and operated by Altice USA.[1]"
                      " It is the fourth largest cable provider in the United States and a Fortune 500 company. "
                      "Optimum offers Internet, television, mobile and home phone serving in Arizona, Arkansas, "
                      "California, Connecticut, Idaho, Kentucky, Louisiana, Mississippi, Missouri, "
                      "New Jersey, New York, North Carolina, Oklahoma, Pennsylvania, Texas, and West Virginia.";
    if (puts(Str) != EOF)
        printf("String written to standard output successfully.\n");
    else
        printf("Error writing string to standard output.\n");
    //3.fgets is a C library function used for reading a line of text (a string) from a file or from the standard input.
    // It's commonly used for reading input from users when writing command-line programs or for reading lines from text files.
    //Here's the basic syntax for using fgets:
    //char *fgets(char *str, int size, FILE *stream);
    //str: A pointer to a character array where the read string will be stored.
    //size: The maximum number of characters to read, including the null-terminating '\0' character.
    //stream: A pointer to a FILE object (e.g., stdin for standard input or a file pointer).

    //Here's how you can use fgets to read a line of text from the standard input (keyboard) and store it in a character array:
    char buffer[1024];  // A character array to store the input string
    printf("Enter a line of text: ");
    // Usage 1: Reading from standard input (keyboard)
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
        printf("You entered: %s", buffer);
    } else {
        printf("Error reading input.\n");
    }

    // Usage 2: Reading from a file
    FILE *fp = fopen("22 IO/cases/fopen.txt", "r");
    if (fp != NULL) {
        if (fgets(buffer, sizeof(buffer), file) != NULL) {
            printf("Line read from file: %s", buffer);
        } else {
            printf("Error reading line from file.\n");
        }
        fclose(fp);
    } else {
        printf("Error opening the file.\n");
    }


}

/**
 * 块的输入/输出
 */
void block_output_input() {
    //1.the fread function is a standard library function used for reading binary data from a file.
    // It is primarily used for reading a specified number of bytes from a file into a buffer.
    // Here's the basic syntax of the fread function:
    // size_t fread(void *ptr, size_t size, size_t count, FILE *stream);
    //Parameters:
    //ptr: A pointer to the memory buffer where the data will be stored.
    //size: The size (in bytes) of each element to be read.
    //count: The number of elements to be read.
    //stream: A pointer to the file stream from which the data will be read.
    //Return Value:
    //fread returns the number of full elements successfully read, which may be less than count if the end of the
    // file is encountered or an error occurs. If an error occurs, fread returns a value less than count,
    // and you can use functions like feof and ferror to determine the nature of the error.
    FILE *file = fopen("22 IO/cases/fopen.txt", "rb");
    if (file != NULL) {
        char buffer[100];// Create a buffer to store the read data
        size_t elements_to_read = sizeof(buffer) / sizeof(buffer[0]);
        // Read data from the file into the buffer
        size_t elements_read = fread(buffer, sizeof(buffer[0]), elements_to_read, file);
        if (elements_read > 0)
            // Data was successfully read
            printf("Read %zu elements from the file.\n", elements_read);
            // Process the data in the buffer here
        else if (feof(file))
            // End of file reached
            printf("End of file reached.\n");
            // An error occurred while reading
        else if (ferror(file))
            perror("Error reading file.");
        fclose(file); //close the file

    } else
        perror("Error opening file");


    //2. the fwrite function is a standard library function used for writing binary data to a file.
    // It is primarily used for writing a specified number of bytes from a buffer to a file.
    // Here's the basic syntax of the fwrite function:
    //size_t fwrite(const void *ptr, size_t size, size_t count, FILE *stream);
    //Parameters:
    //ptr: A pointer to the memory buffer containing the data to be written.
    //size: The size (in bytes) of each element to be written.
    //count: The number of elements to be written.
    //stream: A pointer to the file stream to which the data will be written.
    //Return Value:
    //fwrite returns the number of full elements successfully written, which may be less than count if an error occurs while writing.
    FILE *fp = fopen("22 IO/cases/fopen.txt", "wb");// Open binary file for writing
    if (fp != NULL) {
        char buffer[] = "To C or not to C, That's a question."; // Data to be written
        size_t elements_to_write = sizeof(buffer) / sizeof(buffer[0]);
        // Write data from the buffer to the file
        size_t elements_written = fwrite(buffer, sizeof(buffer[0]), elements_to_write, fp);

        if (elements_written == elements_to_write) {
            // Data was successfully written
            printf("Wrote %zu elements to the file.\n", elements_written);
        } else {
            // An error occurred while writing
            perror("Error writing file");
        }
        fclose(fp); // Close the file
    } else {
        perror("Error opening file");
    }

}

