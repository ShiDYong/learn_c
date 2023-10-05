/********************************************************************************
* @author: mason shi
* @date: 2023/10/1 11:03
* @version: 1.0
* @description: 课本案例题目：修改零件的记录文件
 * 编写程序打开包含part结构的二进制文件，把结构读到数组中，把每个结构的成员on_hand设置为0，然后再把此结构写回到文件中。
 * 注意，程序用"rb+"模式打开文件，因此既可以读也可以写。
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>

#define MAX_LEN 25
#define MAX_PARTS 100

struct part {
    int number;
    char name[MAX_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];
int num_parts;

int main(void) {
    FILE *file;
    int i;
    if ((file = fopen("22 IO/cases/inventory.dat", "rb+")) == NULL) {
        sprintf(stderr, "Can't open inventory file.");
        exit(EXIT_FAILURE);
    }
    //批量读入二进制文件
    num_parts = fread(inventory, sizeof(struct part), MAX_PARTS, file);
    for (i = 0; i < num_parts; i++)
        inventory[i].on_hand = 0;
    //在调用完fread函数之后，文件位置是在文件的末尾。如果没有先调用rewind函数，就调用fwrite函数，那么fwrite函数将在文件末尾添加数据，而不会覆盖旧数据
    rewind(file);
    //把结构写回到文件中
    fwrite(inventory, sizeof(struct part), num_parts, file);
    fclose(file);
    return 0;
}
