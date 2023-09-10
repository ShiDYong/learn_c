/********************************************************************************
* @author: mason shi
* @date: 2023/8/21 22:34
* @version: 1.0
* @description: 17.5链表的实现
 * 链表(Linked List)是由一连串的结构(称为节点)组成的，其中每个节点都包含指向链表中下一个节点的指针，链表
 * 中的最后一个节点包含一个空指针，画图时一般用斜线表示。链表比数组更灵活，可以容易地在链表中插入和删除节点，也是
 * 说允许链表根据需要扩大和缩小。另一方面，我们失去了数组的"随机访问"能力。我们可以用相同的时间访问数组内的任何元素，
 * 而访问链表中的节点用时则不同。如果节点距离链表的开始处很近，那么访问到它会很快；反之，若节点靠近链表结尾处，访问到
 * 它就很慢。
 * ========数组为何从 0 开始========================
　　从数组存储的内存模型上来看，“下标”最确切的定义应该是“偏移（offset）”。如果用 a 来表示数组的首地址，
   a[0] 就是偏移为 0 的位置，也就是首地址，a[k]就表示偏移 k 个 type_size 的位置，所以计算 a[k] 的内存地址只需要
   用这个公式：1 a[k]_address = base_address + k * type_size
　　如果数组从 1 开始，公式则应是： 1 a[k]_address = base_address + (k-1)*type_size
　　从 1 开始编号，每次随机访问数组元素都多了一次减法运算，对于 CPU 来说，就是多了一次减法指令。数组作为非常基础的数据结构，
   通过下标随机访问数组元素又是其非常基础的编程操作，效率的优化就要尽可能做到极致。 所以为了减少一次减法操作，数组选择了
   从 0 开始编号，而不是从 1 开始。此外，从 0 开始，更多是历史原因。C 语言数组下标从 0 开始，
   之后的语言也大多沿用了这种做法。
********************************************************************************/
#include<stdlib.h>
#include<stdio.h>

/*1.声明节点类型：为了建立链表，首先需要一个表示表中单个节点的结构。如下，先假设节点只包含一个整数(即节点的数据)和指向
 * 表中下一个节点的指针,成员next具有struct node*类型，这就意味着它能存储一个指向node结构的指针。node这个名字没有任何
 * 特殊含义，只是一个普通的结构标而已.
 * */
struct node {
    int value;/*data stored in the node*/
    struct node *next; /*pointer tho the next node*/
};



struct node *add_to_list(struct node *list, int n);

struct node *read_numbers(void);

struct node *search_list(struct node *list, int n);

struct node *delete_from_list(struct node *list, int n);


void printList(struct node *list);
/*2.关于node结构，通常可以选择使用标记或者typedef来定义一种特殊的结构类型的名字。但是，在结构有一个指向相同类型的指针成员是(像node那样)，
 * ，要求使用结构标记。没有node标记，就没有办法声明next的类型。
 * */


/*2.上面已经声明来node结构，还需要记录表开始的位置。就是需要一个始终指向表中第一个节点的变量。这里把变量名为first*/
struct node *first = NULL;//把first初始化为NULL表明链表初始为空.

int main(void) {
    // read_numbers();
    struct node *first = NULL;
    // Add nodes to the linked list
    first = add_to_list(first, 1); //不能忘记了要调用add_to_list的返回值存储到first中
    first = add_to_list(first, 2);
    first = add_to_list(first, 3);
    first = add_to_list(first, 4);
    printf("Linked list after adding nodes: \n");
    printList(first);
    //删除指定结点
    first = delete_from_list(first, 5);
    printf("Linked list after delete nodes: \n");
    printList(first);

    /* struct node* head = NULL;
     struct node* second = NULL;
     struct node* third = NULL;

     // Allocate memory for nodes and populate data
     head = (struct node*)malloc(sizeof(struct node));
     second = (struct node*)malloc(sizeof(struct node));
     third = (struct node*)malloc(sizeof(struct node));

     head->value = 1;
     head->next = second;

     second->value = 2;
     second->next = third;

     third->value = 3;
     third->next = NULL;*/

    return 0;
}


/*
 * 3.创建节点：构建链表时，需要逐个创建节点，并且把生成的每个节点加入加入链表中。创建节点包括3个步骤：
 * 1.为节点分配内存单元；
 * 2.把数据存储到节点中；
 * 3.把节点插入链表中。
 * */

/**
 * 在链表的开始处插入节点的方法实现
 * @param list 指向旧链表中首节点的指针
 * @param n 需要存储在新节点中的整数
 * @return
 */
struct node *add_to_list(struct node *list, int n) {
    //3.为了创建节点，需要一个变量临时指向该节点(直到该节点插入链表中为止)。设此变量为new_node:
    struct node *new_node;
    //4.使用malloc函数为新节点分配内存空间，并把返回值保存在new_node中：
    new_node = malloc(sizeof(struct node));//现在new_node指向了一个内存块，且此内存块正好能放下一个node结构
    /*注意：传给sizeof的是待分配的类型的名字，而不是指向此类型的指针的名字
     * new_node=malloc(sizeof(new_node));这种写法是错误的，虽然该写法仍然能够通过编译，但是malloc函数将只为指向node结构
     * 的指针分配足够的内存单元。当程序试图把数据存储到new_node可能指向的节点时，可能会引起崩溃。*/
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list.\n");
        exit(EXIT_FAILURE);
    }
    //5.将数据存储到新节点的成员中value中
    // (*new_node).value=10;
    /*为了访问节点的成员value，可以间接寻址运算符*(引用new_node指向的结构)，然后使用选择运算符.(选择此结构内的一个成员.)
     * 在*new_node两边的圆括号时强制要求的，因为运算符.的优先级高于运算符*
     * */
    /*6.利用指针访问结构中的成员是很普遍的，C语言提供了一种运算符。此运算符称为右箭头选择：->
     * new_node->value = 10;来替代(*new_node).value=10;
     * 它先对new_node间接寻址以定位所指向的结构，然后再选择结构的成员value.
     * 由运算符->产生左值，所以在任何地方都可以允许普通变量的地方使用它。
     * 如：scanf("%d",&new_node->value);
     * 注意，尽管new_node是一个指针，运算符&仍然是需要的。如果没有运算符&,就会把new_node->value的值传递给scanf函数，
     * 而这个值是int类型。
     * */
    //7.链表的开始处是最容易插入节点的地方，如果new_node正指向要插入的节点，并且first正指向链表中的首节点，那么
    //为了把节点插入到链表首先需要修改节点的成员next,使其指向先前在链表开始处的节点；
    // new_node->next=first;
    //使first指向新节点;
    // first = new_node;
    new_node->value = n;
    new_node->next = list;
    return new_node;
    /*注意：add_to_list函数不会修改指针list,而是返回指向新产生的节点的指针(现在位于链表的开始处).当调用add_to_list函数时，需要
     * 返回值存储到first中*/
}

/*下列函数用add_to_list来创建一个含有用户输入的数的链表*/
struct node *read_numbers(void) {
    struct node *first = NULL;
    int n;
    for (;;) {
        printf("Enter a series of integers (0 to terminate): ");
        scanf("%d", &n);
        if (n == 0)
            return first;
        first = add_to_list(first, n);/*⚠️：链表内的数会发生顺序倒置，因为first始终指向包含最后输入的数的节点*/
    }

}

/**
 *
 * 17.5.5:搜素链表：
 * 一旦创建了链表，需要为某个特殊的字段而搜索链表。虽然while循环可以用于搜索链表，但是for循环语句常常是首选。
 * 我们习惯于在编写含有计数操作的循环时使用for语句，但是for语句的灵活性使它也适合其他工作，包括对链表的操作。
 * 下面一种访问链表中节点的习惯方法，使用了指针变量p来跟踪“当前”节点：
 * 惯用法：for(p =first; p!=NULL; p=p->next)
 * 赋值表达式p=p->next使指针p从一个结点移动到下一个结点。当编写遍历链表的循环时，在C语言中总是采用这种形式的赋值表达式。
 * @param list 要查询的链表
 * @param n 要查询的数据
 * @return
 */
struct node *search_list(struct node *list, int n) {
    //struct node *p;
    //1.实现方式一：依赖链表搜索惯用法
    /* for (p = list; p != NULL; p = p->next)
         if (p->value == n)
             return p;
     return NULL;*/

    //2.实现方式二：出去变量p，而用list自身来跟踪当前当前结点
    /* for(;list !=NULL;list=list->next)
         if(list->value !=n) //因为list是原始链表指针的副本，所以在函数内不会改变它不会有任何损失.
             return list;
      return NULL;*/

    //方式三：把判定list->value = n和判定list !=NULL合并起来
    /*for (; list != NULL && list->value != n; list = list->next);
    return list; //因为到达链表末尾时list为NULL，所以即使找不到n，返回list也是正确的。
    */

    //方式四：使用while语句，那么search_list函数就会更加清楚
    while (list != NULL && list->value != n)
        list = list->next;
    return list;

}


/**
 *17.5.6 从链表中删除结点：把数据存储到链表中有一个很大的好处，那就是可以轻松地删除不需要的结点，具体实现：
 * 1.定位要删除的结    1   1qqwrtu689ghuiklot点；
 * 2.改变前一个结点，从而使它绕过删除结点；
 * 3.调用free函数收回删除结点占用的内存空间。
 * @param list
 * @param n
 * @return
 */
struct node *delete_from_list(struct node *list, int n) {
    /*1.第(1)步并不像看起来那么容易。如果按照显而易见的方式搜索链表，那么将在指针指向要删除的结点时终止搜索
     * 。但是，这样做就不能执行第(2)步了，因为第(2)步要求改变前一个结点。
     *针对这个问题有各种不同的解决办法。这里使用“追踪指针”方法：在第(1)步搜索链表时，将保留一个指向前一个结点的指针(prev),
     * 还有指向当前结点的指针(cur).如果list指向待搜索的链表，并且n是要删除的整数，那么下列循环就可以实现第(1)步：
     * */
    struct node *cur, *prev;
    for (cur = list, prev = NULL; cur != NULL && cur->value != n;
         prev = cur, cur = cur->next);
    /*这里展示了C语言中for语句的威力。它采用了空循环体并运用逗号，却能够执行搜索n所需全部操作。
     * 当n循环终止时，cur指向要删除的结点，而prev指向前一个结点(如果有的话)*/
    //可用下面的while语句替代：
    // Search for the node to be deleted
//    while (cur != NULL && cur->value != n) {
//        prev = cur;
//        cur = cur->next;
//    }

    //2.根据第(2)步骤要求执行绕过操作
    if (cur == NULL)
        return list; /*n was not fond*/
    if (prev == NULL)
        list = list->next; /*n is in the first node*/
    else
        prev->next = cur->next; //使前一个结点中的指针指向了当前结点后面的结点
    //3.第(3)步骤释放内存
    free(cur);
    return list;

}

// Function to print the linked list
void printList(struct node *list) {
    struct node *first = list;
    while (first != NULL) {
        printf("%d ", first->value);
        first = first->next;
    }
    printf("\n");
}


/**
 * 指向指针的指针：当函数的实际参数是指针变量时，有时候会希望函数能通过让指针指向别处来改变此变量，
 * 这就需要用到指向指针的指针。
 * 下面给函数add_to_list传递一个指向first的指针，就能实现让函数add_to_list修改first
 * @param list
 * @param n
 */
void add_to_list_double_pointer(struct node **list, int n) {
    struct node *new_node;
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: malloc failed in add_to_list.\n");
        exit(EXIT_FAILURE);
    }
    new_node->value = n;
    new_node->next = *list;
    *list = new_node;
    /*
     * 当调用该函数时，第一个实际参数将是first的地址：
     * add_to_list(&first,10);
     * 既然给list赋予了first的地址，那么可以使用*list作为first的别名。特别是把new_node赋值*list会修改first的内容。
     * */

}


