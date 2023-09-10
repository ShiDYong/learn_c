/********************************************************************************
* @author: mason shi
* @date: 2023/8/27 09:58
* @version: 1.0
* @description: 有序链表的实现：
 * 如果链表的的结点是有序的(按照结点中的数据排序)，则称该链表为有序链表。往有序链表中插入结点会更困难一些
 * 因为不再始终把结点放在链表的开始位置。但是搜索会更快(在到达期望结点应该出现的位置后，就可以停止查找了)。
 * 下面的案例表明，插入结点的难度增加了，但搜索也更快了。
 *
********************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

#define NAME_LEN 25

/*part结构将包含一个额外的成员(指向链表中下一个结点的指针),而且变量inventory是指向链表首结点的指针*/
struct part {
    int number;
    char name[NAME_LEN];
    int on_hand;
    struct part *next;
};
struct part *inventory = NULL;/*points to first part*/

int read_line(char str[], int n);

struct part *find_part(int number);

void insert(void);

void search(void);

void update(void);

void print(void);


int main(void) {
    char code;
    for (;;) {
        printf("Enter operation code: ");
        scanf("%c", &code);
        while (getchar() != '\n');/*skips to end of line*/

        switch (code) {
            case 'i':insert();
                break;
            case 's':search();
                break;
            case 'u': update();
                break;
            case 'p':print();
                break;
            case 'q': return 0;
            default:printf("Illegal code\n");
        }
        printf("\n");


    }


}

/**
 * 因为链表inventory是根据零件编号排序的，所以find_part函数可以通过在结点的零件编号大于或等于需要的零件编号时
 * 停止搜索来节省时间
 * @param number
 * @return 函数返回指针，此指针指向的结点含有需要的零件编号
 */
struct part *find_part(int number){
    struct part *p;
    for(p =inventory;p!=NULL && number > p->number;p=p->next);
    if(p!=NULL && p->number==number)
        return p;
    return NULL;
}

/**
 * 要确定新零件在链表中所处的位置，并且把它插入那个位置。除此之外还要判断检查零件编号是否已经出现在链表中来
 * Prompts the user for information about a new part and then inserts the part into the inventory
 * list;the list remains sorted by part number.Prints an error message and returns prematurely if the
 * prat already exists or space could not be allocated for the part.
 */
void insert(){
    struct part *cur,*prev,*new_node;
    new_node = malloc(sizeof(struct part));
    if(new_node==NULL){
        printf("Database is full: cat's add more parts.\n");
        return;
    }
    printf("Enter part number: ");
    scanf("%d",&new_node->number);
    //先过滤小于要插入数据的数
    for(cur=inventory,prev=NULL; cur != NULL && new_node->number > cur->number;
      prev=cur,cur=cur->next);
    //判断要插入的数据是否已经在链表中存在
    if(cur !=NULL && new_node->number == cur->number){
        printf("Part already exists.\n");
        free(new_node);
        return;
    }
    printf("Enter part name: ");
    //这里不需要scanf函数使用编写的函数更高效
    read_line(new_node->name,NAME_LEN);
    printf("Enter quantity on hand: ");
    scanf("%d", &new_node->on_hand);
    new_node->next = cur;
    if(prev==NULL)
        inventory = new_node;
    else
        prev->next=new_node;


}


/**
 * search:Prompts the user to enter a part number,then looks up the part in the database.If the part
 * exists,prints the name and quantity on hand; if not, prints an error message.
 */
void search(){
    int number;
    struct part *p;
    printf("Enter part number: ");
    scanf("%d",&number);
    p= find_part(number);
    if(p!=NULL){
        printf("Part name: %s\n",p->name);
        printf("Quantity on hand: %d\n",p->on_hand);
    } else
        printf("Part not found.\n");

}

/**
 * update: Prompts the user to enter a part number.Prints an error message if the part doesn't exist;
 * otherwise,prompts the user to enter change in quantity on hand and updates the database.
 */
void update(void){
    int number, change;
    struct part *p;
    printf("Enter part number: ");
    scanf("%d",&number);
    p = find_part(number);
    if(p!=NULL){
        printf("Enter change in quantity on hand: ");
        scanf("%d",&change);
        p->on_hand +=change;
    } else
        printf("Part not found.\n");

}


/**
 * print: Prints a listing of all parts in the database,
 *        showing the part number,part name,and quantity on hand. Part numbers will aapear
 *        in ascending order.
 */
void print(void){
    struct part *p;
    printf("Part Number     Part Name"
           "Quantity on Hand\n");
    for(p=inventory; p!=NULL; p=p->next)
        printf("%7d         %-25s%11d\n",p->number,p->name,p->on_hand);


}
/**
 * read_line: Skips leading white-space characters, then reads the remainder of the input
 * line and stores it in str. Truncates the line if its length exceeds n. Returns the number of
 * characters stored.
 * @param str
 * @param n
 * @return
 */
int read_line(char str[], int n) {
    int ch, i = 0;
    while (isspace(ch = getchar()));//判断ch是否是空白字符。如果不是空白字符，循环停止，ch中包含一个非空白字符
    while (ch != '\n' && ch != EOF) {
        if (i < n)
            str[i++] = ch;
        ch = getchar();
    }
    str[i] = '\0';
    return i;
}