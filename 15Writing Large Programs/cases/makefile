#为了更易于构建大型程序，UNIX系统发明了makefile的该概念。这个文件包含构建程序的必要信息。makefile不仅列出了作为程序的
#一部分的哪些文件，而且还描述了文件之间的依赖性。下面如果line.c包含了line.h，那么就说line.c依赖于line.h,因此修改line.h
#之后就需要重新编译line.c
justify:	justify.o word.o line.o
	gcc -o justify justify.o word.o line.o
#这里总共有4组代码，每组称为一条规则，每条规则的第一行给出了目标文件，跟在后边的是它所依赖的文件。第二行是待执行的命令
#当目标文件所依赖的文件发生改变时，需要重新构建目标文件，此时执行第二行的命令。

justify.o:	justify.c word.h line.h
	gcc -c justify.c
word.o: word.c word.h
	gcc -c word.c
line.o: line.c line.h
	gcc -c line.c

#一旦为程序创建了makefile,就能使用make实用程序来创建(重新构建)该程序了。通过检查于程序中每个文件相关的时间和日期，make可以确定
#那个文件是过期的。然后，它会调用必要的命令来重新构建程序；
#make的具体细节：
#1.makefile的每个命令前面都必须有一个制表符，不是一串空格；
#2.通过使用make目标文件，这里make justify,构建可运行的目标文件；
#3.对生成的目标文件进行运行：./justify <case_text.txt;
#4.重定向输出: ./justify <case_text.txt> case_new.log
#5.以上可以在命令行中执行
