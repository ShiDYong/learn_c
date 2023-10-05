/********************************************************************************
* @author: mason shi
* @date: 2023/9/30 16:37
* @version: 1.0
* @description: 编写程序用来进行文件的复制操作。当程序执行命令时，会在命令行上指定原始文件名和新文件名。
 * 例如，为了把文件f1.c复制给f2.c，可以使用命令：fcopy f1.c f2.c
 * 如果命令行的文件名不是两个，或者至少有一个文件无法打开，那么程序fcopy将产生出错的消息。
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[]) {
    FILE *source_fp, *dest_fp;
    int ch;
    if (argc != 3) {
        fprintf(stderr, "usage: fcopy source dest.\n");
        exit(EXIT_FAILURE);
    }
    //这里采用rb和wb作为文件模式，使fcopy程序既可以复制文本文件也可以复制二进制文件，如果
    //采用r和w来代替，那么程序将无法复制二进制文件。
    if ((source_fp = fopen(argv[1], "rb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }
    if ((dest_fp = fopen(argv[2], "wb")) == NULL) {
        fprintf(stderr, "Can't open %s\n", argv[2]);
        fclose(source_fp);
        exit(EXIT_FAILURE);
    }
    while ((ch = getc(source_fp)) != EOF)
        putc(ch, dest_fp);
    fclose(source_fp);
    fclose(dest_fp);
    return 0;
}


}
