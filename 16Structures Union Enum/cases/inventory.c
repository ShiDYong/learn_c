/********************************************************************************
* @author: mason shi
* @date: 2023/8/12 22:42
* @version: 1.0
* @description: Maintains s parts database(array version)
 * 编写程序用来维护仓库存储的零件信息数据库。程序围绕一个结构数组构建，且每个结构包含以下信息：
 * 零件的编号、名称以及数量。程序将支持以下操作。
 * 1.添加新零件的编号、名称和初始的现货数量。如果零件已经在数据库中，或者数据库已经满了，那么程序必须显示出错误信息；
 * 2.给定零件编号，显示出零件的名称和当前的现货数量。如果零件的编号不在数据库中，那么程序必须显示出错的信息；
 * 3.给定零件编号，改变现有的零件数量。如果零件编号不再数据库中，那么程序必须显示出错消息；
 * 4.显示出数据库中全部信息的表格。零件必须按照输入的顺序显示出来。
 * 5.终止程序程序的操作。
 * 使用i(插入)、s(搜索)、u(更新)、p(显示)和q(退出)分别表示这些操作
********************************************************************************/
#include<stdio.h>
#include "readline.h"
#define NAME_LEN 25
#define MAX_PARTS 100
//定义存储零件的结构的数组
struct part {
    int number;
    char name[NAME_LEN + 1];
    int on_hand;
} inventory[MAX_PARTS];

int num_parts = 0;/*number of parts currently stored*/
/*对应的函数原型*/
int find_part(int number);

void insert(void);

void search(void);

void update(void);

void print(void);
//int read_line(char str[], int n);
/************************************************************************8
 * cmake的具体用法参考链接：https://www.hahack.com/codes/cmake/             *
linux的GDB调试参考书籍：《C/C++代码调试的艺术》第三章Linux系统gdb调试基本功能     *
**************************************************************************
 */
int main(void) {
    char code;//输入编码
    //主循环提示用户输入，读取操作码
    for (;;) {
        printf("Enter operation code: ");
        scanf(" %c",&code);
        while (getchar() !='\n'); /*skips to end of line*/
        switch (code) {
            case 'i': insert();
                break;
            case 's': search();
                break;
            case 'u': update();
                break;
            case 'p': print();
                break;
            case 'q': return 0;//退出程序
            default: printf("Illegal code\n");
        }
        printf("\n");
    }
}

/**
 * find_part:Looks up a part number in the inventory array.Returns the array index if
 * the part number if found; otherwise,return -1.
 * @param number
 * @return
 */
int find_part(int number){
    int i;
    for (i = 0;  i<num_parts ;i++)
        if(inventory[i].number==number)
            return i;
    return -1;
}

/**
 * insert: Prompts the user for information about a new part an then inserts the part into the
 *         database. Prints an error message and returns prematurely if the part already exists or
 *         the database if full.
 */
void insert(void){
    int part_number;
    //判断当前的database的容量是否已经满了
    if(num_parts ==MAX_PARTS){
        printf("Database if full; can't add more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d",&part_number);
    //判断是否已经在数据库中存在了
    if(find_part(part_number) >=0){
        printf("Part already exists.\n");
        return;
    }
    //开始插入数据库中
    inventory[num_parts].number=part_number;//注意要当前数据库下标的后面继续插入
    printf("Enter part name: ");
    read_line(inventory[num_parts].name,NAME_LEN);//读取输入的字符
    printf("Enter quantity on hand: ");
    scanf("%d",&inventory[num_parts].on_hand);
    num_parts++;
}


/**
 * search:Prompts the user to enter a part number, then looks up the part in the database.If the part exist
 *        ,prints the name and quantity on hand; if not, prints an error message.
 *
 */
void search(void){
    int i,number;
    printf("Enter part number: ");
    scanf("%d",&number);
    i = find_part(number);//查询是否在数据库中
    if(i>=0){
        printf("Part name : %s\n",inventory[i].name);
        printf("Quantity on hand: %d\n",inventory[i].on_hand);
    } else
        printf("Part not fond.\n");
}

/**
 * update: Prompts the user to enter a part number.
 *         Prints an error message if the part doesn't
 *         exist;otherwise, prompts the user to enter change in quantity on hand
 *         and updates the database.
 */
void update(void){
    int i,number,change;
    printf("Enter part number: ");
    scanf("%d",&number);
    i= find_part(number);
    if(i >=0){
        printf("Enter change in quantity on hand: ");
        scanf("%d",&change);
        inventory[i].on_hand=change;
    } else
        printf("Part not found.\n");
}

/**
 * print:Prints a listing of all parts in the database,showing the part number, part name, and quantity
 *       on hand, Parts are printed in the order in which they were entered into the database.
 */
void print(void){
    int i;
    printf("Part Number     Part Name                   "
           "Quantity on Hand\n");
    for (i = 0;  i< num_parts; i++)
        printf("%7d         %-25s%11d\n",inventory[i].number,inventory[i].name,
               inventory[i].on_hand);

}
//int read_line(char str[], int n) {
//    int ch,i=0;
//    while (isspace(ch = getchar()));//判断ch是否是空白字符。如果不是空白字符，循环停止，ch中包含一个非空白字符
//    while (ch != '\n' && ch != EOF) {
//        if (i < n)
//            str[i++] = ch; //缺少初始化，导致i的值大于>25,导致一直进入不来
//        ch = getchar();
//    }
//    str[i] = '\0';
//    return i;
//}