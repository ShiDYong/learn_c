/********************************************************************************
* @author: mason shi
* @date: 2023/10/25 21:38
* @version: 1.0
* @description: 
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

/*
Project 22.01
    Extend the `canopen.c` program of Section 22.2 so that the user may put any
    number of file names on the command line:
    canopen foo bar baz
    The program should print a separate `can be opened` or `can't be opened` message
    for each file. Have the program terminate withe status `EXIT_FAILURE` if one or
    more of the files can't be opened.
 */
int main(int argc, char *argv[]) {
    FILE *fp;
    char ch;
    int i;
    //根据要求输入的参数值不能少于2
    if (argc < 1) {
        printf("usage: canopen filename.\n");
        exit(EXIT_FAILURE);
    }
    //这里唯一相关两个变量是argc,argv，所以要从这里面找关系
    //并使用循环的方式一次判断参数中的命令行是否存在
    for (i = 1; i < argc; i++) {
        if ((fp = fopen(argv[i], "r")) == NULL) {
            printf("%s can't be opened\n", argv[i]);
            exit(EXIT_FAILURE);
        }

        printf("%s can be opened\n", argv[i]);
        printf("The content is as follows: \n");
        /*
        * 22.02:编写程序，把文件中的所有字母转换成大写形式(非字母字符不变)。程序应从命令行获取文件名并把输出写到stdout中
        */
        //在C语言中，可以使用feof函数来检查一个文件是否已经到达了末尾。feof函数用于检查文件流的结束标志
        while ((ch = fgetc(fp)) != EOF && !feof(fp)) {
            if (isalpha(ch)) fputc(toupper(ch), stdout);
            else fputc(ch, stdout);
        }
        printf("\n");

    }
    fclose(fp);
    return 0;

}