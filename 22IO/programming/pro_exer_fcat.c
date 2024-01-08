/********************************************************************************
* @author: mason shi
* @date: 2023/10/29 15:12
* @version: 1.0
* @description:
 * Project 22.03
    Write a program named `fcat` that "concatenates" any number of files by writing
    them to standard output, one after the other, with no break between files. For
    example, the following command will display the files `f1.c`, `f2.c` and `f3.c`
    on the screen:
    fcat f1.c f2.c f3.c
    `fcat` should issue an error message if any file can't be opened. Hint: Since
    it has no more than one file open at a time, `fcat` needs only a single file
    pointer variable. Once it's finished with a file `fcat` can use the same
    variable when it opens the next file.
    课后练习题03和练习题01-02相比差不多
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int main(int argc, char *argv[]) {
    /*先需要判断所有文件是否都能打开，如果所有文件均无法打开，则给出提示，否则循环输出所有文件*/
    FILE *fp;
    char ch;
    int count = 0;
    int i;
    int k;


    if (argc < 2) {
        printf("Usage: fcat filename filename...\n");
        exit(EXIT_FAILURE);
    }
    for (i = 2; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("%s can't be opened.\n", argv[i]);
            count++;
            continue;
        }
        printf(" %s can be opened.\n", argv[i]);
        fclose(fp);


    }
    if (count == argc - 1) {
        printf("All file can't be opened.\n");
        exit(EXIT_FAILURE);
    }

    if (count != 0) printf("%d file can't be opened, cat others.\n", count);
    for (k = 2; k < argc; k++) {
        while ((ch = fgetc(fp)) != EOF) fputc(ch, stdout);
        fclose(fp);
    }
    return 0;

}