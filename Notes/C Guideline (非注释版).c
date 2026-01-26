#define _CRT_SECURE_NO_WARNINGS 1放在整个文件开头可以避免编译器对c语言原函数报错的情况
c语言中，大部分情况下，1为真，0为假

	运算符号：
	&&		并
	||			或
	!			非
	!=			不等于
	==		若等于
	+=		自增……
	-=			自减……
	++(后)	先使用，后自增1
	--	(后)	先使用，后自减1
	++(前)	先自增1，后使用
	--(前)	先自减1，后使用
	%			取模（余数）
	x ? y : z	x为真时，取值y；x为假时，取值z

char   整型变量    1字节      范围：-128~127
char   变量[数据]={……}			字符串定义，其中数据为字符串长度
unsigned char    取值范围：0~255
 short int/unsigned short int       2字节      范围-32768~32767/0~65535
int          4字节
long		不多赘述
long long	不多赘述

	printf语句中，%d——十进制数(int/long int)
	%2d——十进制数，两位数，不足时向右对齐
	%-2d——十进制数，两位数，不足时向左对齐
	%hd——十进制数(short/short int/unsigned short int)
	%ld——十进制数(long)
	%c——字符(char)
	%s——字符串(char[字符数量]=…)
	%f——浮点型数据(float)
	%lf——更精准的浮点型数据(double)
	%p——打印地址
	%o——八进制数
	%x——十六进制数
	\n——换行
	\t——制表符

scanf          输入函数        格式：scanf("%…%…"，&变量,&变量);

	if        选择语句        格式：if(条件)
											{
												语句1;
												语句2;
												……
											}
											else if(条件)
											{
												语句1;
												语句2;
												……
											}
											else
											{
												语句1;
												语句2;
												……
											}
	while        循环语句        格式：while(条件)
												  {
													  语句1;
													  语句2;
													  ……
												  }
	注：当处于条件之外时，while循环终止


    100以内所有奇数显示
int main()
{
	short a=1;
	short A;
	A = a % 2;
	while (a < 100)
	{
		if (A == 1)
		{
			printf("%d\n", a);
			a++;
			A = a % 2;
		}
		else
		{
			a++;
			A = a % 2;
		}
	}
	return 0;
}


	switch		半选择语句		说明：当进入switch语句时，若无break，则会依次向下进行。
	使用：
	switch(整型变量)
	{
		case 整型常量表达式(1):[注：即上方“整型变量”]
			语句1;
			语句2;
			…
			(break;)[注：如果要跳出switch语句，不执行下方case语句，可使用break跳出]
		case 整型常量表达式(2):
			语句1;
			语句2;
			…
			(break;)
		…
		(
		default:
			语句1;
			语句2;
			(break;)
		[注：当整型变量表达式不为上述所有case情况，可用default语句表示]
		)
	}


	switch分支语句实例
	int day = 0;
	printf("今天星期");
	scanf("%d",&day);
	switch (day)
	{
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
			printf("哦，今天又要工作了\n");
			break;
		case 6:
		case 7:
			printf("太棒了，是休息日");
		default:
			printf("你不对劲，你一定不是地球人 (doge)\n");
	}

术语科普：expr=expression		[计]表达式
stmt=statement		[计]语句

	while			循环语句
	格式：
	while (表达式)
	{
		语句1;
		语句2;
		…
	}
	[注：其中，若遇见break语句，则直接跳出while循环；若为continue语句，则跳过本次循环，重新回到while语句判断部分]
	[注：只要表达式为真，那么while语句就可以一直进行，直到表达式为假，则停止]


	while循环语句实例
	int x = 0;
	while (x <= 10)
	{
		printf("%d\t", x);
		x++;
	}


	getchar+putchar用法：
	char/int 变量=getchar();				——————此处输入数字/字符串/字符[注：如输入值为字符串，则putchar只会输出第一个字符，数据串同理]
	[
	char/int 变量;
	变量=getchar();
	]
	putchar(变量);			——————此处输出字符/数字(单个)
	[注：getchar只能够输入字符，不可以输入数据，同时putchar输出getchar输入的字符。在printf语句中，若想输出被getchar赋值的表达式/变量，需要使用%c]


	getchar+putchar使用实例：
	char x = 0 ;
	x = getchar();
	putchar(x);

注：字符串EOF其意为End Of File,值为-1
若要跳出赋值为非EOF的语句，可使用Ctrl+Z跳出
注：scanf在读取字符串时，遇到空格或转行(\n)时会停止读取字符串，就此终止。而后面的字符/字符串(包括停止读取的空格、回车及后方空格、回车)将会遗留在缓存区。而getchar在读取时，一次只能读取一个字符，且若为空格及回车，都会被getchar读取。
所以，如出现scanf读取字符串不完全(即碰到空格或回车停止转行时)，缓存区尚有遗留，而后续需要用到其他的读取字符/字符串的函数/语句，用下方语句将缓存区清空，以免造成error

	int ch=0;
	while((ch=getchar())!='\n')
	{
		;
	}

for		循环语句
格式：

	for(表达式1;表达式2;表达式3)[注：可省略]
	{
		语句1;
		语句2;
		……
	}
	[注：在for循环语句中，continue、break语句依然适用，作用同于while语句。表达式1为初始化部分，用于初始化循环变量；表达式2为条件判断部分，用于判断循环何时终止；表达式3为调整部分，用于循环条件的调整]
	[注：流程：表达式1  -->  表达式2  -->  for循环内语句  -->  表达式3  -->  表达式1  -->  ……]


	for循环语句实例：显示1-10内的自然数
	int num;
	for (num = 0; num <= 10; num++)
	{
		if (num == 0)
			continue;
		printf("%d\n", num);
	}

	do…while		循环语句
	格式：
	do
	{
		语句1;
		语句2;
		…
	}
	while(表达式);
	[注：在do…while 循环语句中，continue、break 语句依然适用，作用同于while语句。]
	[注：do…while 循环语句至少执行一次。当条件经过do部分后，若表达式为真，则继续循环；若表达式为假，则跳出循环]


	strlen		库函数			用于求取字符串长度，且不包括“\0”，并返回字符串长度的值，返回值为size_t!（注意无符号）
	包含于string.h头文件中
	所以引用前须声明：
	#include<string.h>
	声明：
	size_t strlen(const char * str);
	参数字符串一定以'\0'结尾，因为strlen函数是读取字符串直到'\0'之前
	格式：
	char arr[]="Welcome to China!!!"
	int x=0;
	x=strlen(arr);
	其中，x的值为arr字符串的长度的值


	Sleep		库函数（必须大写）			使程序运行暂时停止
	包含于windows.h头文件中
	所以引用前须声明：
	#include <windows.h>
	格式：
	Sleep (表达式);
	[注：单位为毫秒，1000毫秒为1秒]


	system			库函数				执行DOS命令
	包含于stdlib.h头文件中
	所以引用前须声明：
	#include<stdlib.h>
	格式：
	system("DOS命令");

	system库函数DOS命令：
	例如，用 system("color 0A"); 其中color后面的0是背景色代号，A是前景色代号。各颜色代码如下：
	0=黑色 1=蓝色 2=绿色 3=湖蓝色 4=红色 5=紫色 6=黄色 7=白色 8=灰色 9=亮蓝色 A=亮绿色 B=亮湖蓝色 C=亮红色 D=亮紫色 E=亮黄色 F=亮白色
	（注意：Microsoft Visual C++6.0 支持system）
	颜色属性由两个十六进制数字指定 -- 第一个对应于背景，第二个对应于前景。每个数字
	可以为以下任何值:
	0 = 黑色 8 = 灰色（“亮黑色”）
	1 = 蓝色 9 = 亮蓝色
	2 = 绿色 A = 亮绿色
	3 = 湖蓝色 B = 亮湖蓝色
	4 = 红色 C = 亮红色
	5 = 紫色 D = 亮紫色
	6 = 黄色 E = 亮黄色
	7 = 白色 F = 亮白色
	cls——clear the screan, 清空屏幕


	rand			库函数			生成随机数，可赋值
	包含于stdlib.h头文件中
	所以引用前须声明：
	#include<stdlib.h>
	格式：
	int result;
	result = rand();
	注：rand库函数单独使用时具有规律性，输出值有周期（很长），如需完全随机值，可参考srand库函数


	srand			库函数		设置rand随机值取值起始点
	包含于stdlib.h头文件中
	所以引用前须声明：
	#include<stdlib.h>
	格式：
	void srand(unsigned int seed);
	注：当srand库函数中输入值为整形常量时，rand库函数输出值依旧具有规律性，如要求rand库函数输出值具有完全随机性，可参考time库函数


	time			库函数			取时间戳为返回结果，同时返回结果为一个名为time_t的一个变量，同时，time_t变量为一个long型变量
	包含于time.h头文件中
	所以引用前须声明：
	#include<time.h>
	格式：
	time_t time(time_t * timer);
	注：时间戳=计算机当前时间-计算机生成时间(1970.1.1 00:00:00)[单位：秒]

若想要rand库函数输出值具有完全随机性，可使用以下代码定义：
srand((unsigned int)time(NULL));
此时输出的srand具有完全随机性

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>

void Menu(int times,int times_two)
{
	printf("################################\n");
	printf("########  数 字 游 戏  #########\n");
	printf("###### 1  Start	  0  Exit ######\n");
	printf("################游玩次数：%-3d###\n", times);
	printf("################猜测次数：%-3d###\n", times_two);
	printf("################################\n");
	printf("请选择>>");
}

int Game(int times_two = 0)
{
	int answer = 0;
	int guess = 0;
	answer = rand() % 101;
	printf("################################\n");
	while (1)
	{
		printf("请猜测数字(0~100)>>");
		scanf("%d", &guess);
		if (guess < answer)
		{
			printf("猜小了呢，请继续吧\n");
		}
		else if (guess > answer)
		{
			printf("猜大了呢，请继续吧\n");
		}
		else
		{
			printf("猜对了呢！！！不错不错！！！\n");
			times_two++;
			printf("本次猜测次数为：%d\n", times_two);
			Sleep(3000);
			system("cls");
			break;
		}
		times_two++;
	}
	return times_two;
}

int main()
{
	int times = 0;
	int result = 0;
	int times_2 = 0;
	srand((unsigned int)time(NULL));
	do
	{
		Menu(times,times_2);
		scanf("%d", &result);
		switch (result)
		{
		case 1:
			times++;
			system("cls");
			times_2+=Game();
			break;
		case 0:
			printf("退出游戏...\n");
			Sleep(500);
			system("cls");
			break;
		default:
			printf("输入错误，请再次输入\n");
			Sleep(500);
			system("cls");
			break;
		}
	}
	while (result != 0);
	return 0;
}


	strcpy		库函数			覆盖字符、字符串或指针
	包含于string.h头文件中
	所以引用前须声明：
	#include<string.h>
	格式：
	char * strcpy ( char * destination, const char * source )
	即将括号内后方字符、字符串或指针覆盖到前方
	注：如若后方字符串位数不及前方字符串，则只覆盖其所有位数(包括‘/0’)，其余不做改变. 而因为使用printf库函数打印字符串时，只会打印到'/0'字符前，所以会显示为之前的const char * source字符串，不会显示被覆盖字符串后方未被覆盖部分

	strcpy自实现：
	char* my_strcpy(char* dest, const char* src)
	{
		assert(dest != NULL);
		assert(src != NULL);
		//防止空指针
		char* ret = dest;
		//存储
		while (*dest++ = *src++)
			;
		//复制，括号内条件满足：
		//1.自增
		//2.赋值
		//3.判断是否为'\0'
		return ret;
		//返回
	}

	puts		库函数			打印标准字符串
	包含于stdio,h头文件中
	所以引用前须声明：
	#include<stdio.h>
	格式：
	puts(const char * str);
	显示为打印出的str字符串
	注：与printf库函数相似，只能打印字符串，但是要比printf库函数方便许多，且同样是在字符串的'/0'字符前停止打印(不包括'/0'字符)


	下面是strcpy库函数和puts库函数的实例：
	#include<stdio.h>
	#include<string.h>

	int main()
	{
		char arr_1[] = "Qing Xian";
		char arr_2[] = "Shu Yijie";
		puts(arr_2);
		strcpy(arr_2, arr_1);
		puts(arr_2);
		return 0;
	}


	memset			库函数			覆盖指针内存块中内容
	包含于string.h头文件中
	所以引用前须声明：
	#include<string.h>
	格式：
	memset(void * str, int c, size_t num);
	即将str指针内存块中的前num个字符全都替换为c
	注：memset库函数中，"int c"部分可以为单个字符，可以为数字，也可以为字符串。当"int c"部分为数字时，在程序运行中会将该数值转换为对应的ASCII码值，然后进行替换；如果为字符串时，程序会予以警告，但依然能够运行，不过替换部分将为乱码，且每次输出结果不同


	memset库函数使用实例：
	#include<stdio.h>
	#include<string.h>

	int main()
	{
		char arr[] = "Hello, player! I'm Qing Xian, the mader of the procedure!";
		memset(arr, 'w', 5);
		memset(arr, 5, 1);
		puts(arr);
		return 0;
	}


	goto			语句			把控制无条件转移到同一函数内的被标记的语句
	格式：
	goto label;
	...
	...
	label:
	statement;
	在这里，"label"可以使任何除C关键字以外的纯文本，他可以设置在C程序中goto语句的前面或者后面


	goto语句运用实例：
	#include<stdio.h>
	#include<string.h>

	int main()
	{
		char arr[] = "Here is Qing Xian!";
		goto then;
		memset(arr, '#', 4);
		puts(arr);
	then:
		puts(arr);
		return 0;
	}
	可以看见，在程序输出结果上，并没有运行memset库函数，也没有打印出被memset库函数修改后的arr字符串，实现了goto语句的作用


	指针的运用实例:
	#include<stdio.h>
	#include<windows.h>

	void swap(int*x, int*y)
	{
		int exchange;
		exchange = *x;
		*x = *y;
		*y = exchange;
	}
	
	int main()
	{
		system("color 0A");
		int a;
		int b;
		printf("请输入>>\n");
		printf("a=");
		scanf("%d", &a);
		printf("b=");
		scanf("%d", &b);
		swap(&a, &b);
		printf("正在交换a与b的值中...\n");
		Sleep(2000);
		printf("交换成功!\n");
		printf("a=%d\n", a);
		printf("b=%d\n", b);
		printf("请按回车键退出...\n");
		getchar();
		getchar();
		return 0;
	}
	注:形参实例化后其实相当于实参的一份临时拷贝
	此处为传址调用,即函数内部可以接收到实参的地址/指针,可以切实对实参做出改变


函数运用实例:
#include<stdio.h>
#include<windows.h>

int prime_number(int x)
{
	int y ;
	for (y = 2; y < x; y++)
	{
		if ((x%y == 0) || (x == 1 || 0))
		{
			return 0;
			goto NO;
		}
	}
	return x;
NO:
	;
}

int main()
{
	system("color 0A");
	int a;
	int b;
	again:
	printf("请输入所需求取的素数(如若只需确定某数是否为素数,则请输入两次)>>\n");
	printf("如若想退出程序,则请在起始值与终止值下同一输入'-1'\n");
	printf("起始值>>");
	scanf("%d", &a);
	printf("终止值>>");
	scanf("%d", &b);
	if (a < 0 || (b<0 || a>b))
	{
		if (a == -1 && b == -1)
		{
			goto exit;
		}
		printf("输入错误,请再次输入!!!\n");
		Sleep(1000);
		system("cls");
		goto again;
	}
	printf("期间素数为>>\n");
	int times = 0;
	for (; a <= b; a++)
	{
		int result;
		result = prime_number(a);
		if (result != 0)
		{
			printf("%d\n",result);
		}
		else
		{
			times++;
		}
	}
exit:
	printf("退出程序...");
	return 0;
}



	最好在其他源文件中编写自定义函数,使用对应的头文件声明
	声明格式见下:
	如若现编写了一个自定义函数:
	int Add(int x, int y)
	{
		return x + y; 
	}
	则在头文件中声明为:
	#ifndef __ADD_H__   (ifndef = if not define)
	#define __ADD_H__
	int Add(int , int );
	#endif
	在主函数使用自定义函数时,须引用对应头文件:
	#include"Add.h"

警报stack overflow:栈区溢出
https://stackoverflow.com/	程序员的知乎
https://github.com/

	递归的运用实例:
	#include<stdio.h>
	#include<windows.h>

	void print(int x)
	{
		if (x >= 10)
		{
			print(x / 10);			//这里使用到了递归
		}
		printf("%d", x % 10);
		Sleep(200);
	}

	int main()
	{
		int num;
		printf("需打印值>>");
		scanf("%d", &num);
		print(num);
		return 0;
	}


	注:在调用自定义函数时,字符串只会被调用第一个字符的地址,所以需要用到指针
	例:
	int Strlen(char *string)
{
	if (*string ! = ' \0') 
		return 1+Strlen(string + 1);
	else 
		return 0;
}

int main()
{
	char arr[] = "jjj";
	int a = Strlen(arr);
	printf("%d\n", a);
	return 0;
}
	其中,在自定义函数Strlen中,采用了指针变量


斐波那契数列数字求取实例(递归使用实例):
#include<stdio.h>
#include<windows.h>

int Fibonacci(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return Fibonacci(n - 1) + Fibonacci(n - 2);
}

int main()
{
	int num;
	int i = 0;
	do
	{
		if (i == 0)
			goto first;
		system("color 0C");
		printf("输入错误!!!\n");
		Sleep(3000);
		system("cls");
		system("color 07");
		first:
		printf("请输入所需求取的斐波那契数列内该数字的顺序数(num > = 0)>>  num = ");
		scanf("%d", &num);
		i++;
	}
	while (num < 0);
	system("color 07");
	int result = Fibonacci(num);
	printf("您所需求的数字为>> result = %d\n", result);
	return 0;
}


斐波那契数列求值方法优化:
#include<stdio.h>
#include<windows.h>

long int Fibonacci(int times)
{
	int x = 0;
	int y = 1;
	int result;
	switch (times)
	{
	case 0:
		return x;
	case 1:
		return y;
	default:
		for (times; times >= 2; times--)
		{
			result = x + y;
			x = y;
			y = result;
		}
		return result;
	}

}
int main()
{
	int num;
	int i = 0;
	do
	{
		if (i == 0)
			goto first;
		system("color 0C");
		printf("输入错误!!!\n");
		Sleep(3000);
		system("cls");
		system("color 07");
	first:
		printf("请输入所需求取的斐波那契数列内该数字的顺序数(num > = 0)>>  num = ");
		scanf("%d", &num);
		i++;
	}
	while (num < 0);
	system("color 07");
	long int result;
	result = Fibonacci(num);
	printf("您所需求的数字为>>  result = %d", result);
	return 0;
}


	一维数组的创建和初始化
	数组的创建:
	type_t		arr_name		[const_n]
	//type_t 是指数组的元素类型
	//const_n 是一个常量表达式,用来指定数组的大小
	注:[ ]内部不可以输入变量,只能输入常量表达式
	当数组不完全初始化时:
	int arr[10] = { 1 , 2 , 3 };
	未被初始化的部分将以'\0'的形式默认初始化
	下方:
	char arr[5] = { 'a' , 'b' };
	char arr_1[5] = { 'a' , 98 };
	char arr_2[5] = "ab";
	由监视窗口可见,arr数组与arr_2数组看似是相同的,但实际上arr_2数组中第三个字符并不是系统默认初始化的,而arr数组是的
	其中,arr数组与arr_1数组是完全相同的.由此可得,一维数组的读取方式为ASCII码值
	当一位数组初始化定义为字符串时,其后一定会有一个'\0'字符(即字符串的结束标志)
	其中如若使用sizeof库函数求取字符串arr_2,所得值为5
	但是使用strlen库函数求取字符串arr_2,所得值为2
	可见,使用strlen库函数求取字符串长度时,会在'\0'字符前停止读取
	而sizeof库函数会避免这种情况,求取数组原有长度

	数组是使用下标来访问的,下标是从0开始的
	数组的大小可以通过计算得到
	int arr[10];
	int sz=sizeof(arr)/sizeof(arr[0]);

	数组所占的空间大小 = 元素个数 * 元素类型<见下>:
	int main()
{
	system("color 0A");
	int order;
	char arr[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	int arr1[] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
	for (order = 0; order <= sizeof(arr) / sizeof(arr[0]); order++)
	{
		printf("order = %d\naddress = %p\n\n", order, &arr1[order]);
		printf("order = %d\naddress = %p\n\n", order, &arr[order]);
	}
	return 0;
}
	其中,地址由低到高,分配空间相同



二维数组的创建和初始化
	int arr[3][4];
	char arr[3][5];
	double arr[2][4];
	比如,举个例子:
	int arr[3][4];
	其创建了这样一个数组,甚至可以称之为矩阵:
	int		int		int		int
	int		int		int		int
	int		int		int		int
	即三行四列,前行后列
	当这样不完全初始化二维数组时:
	int arr[3][4] = { 1,2,3,4,5,6 };
	其可视化显现大致为这样:
	1		2		3		4
	5		6		\0		\0
	\0		\0		\0		\0
	由此可见,当像这样不完全初始化二维数组时,初始化值将会以此从左至右,从上至下赋值,余下未赋值部分以'\0'默认初始化
	如若像此初始化二维数组:
	int arr[3][4] = { { 1,2,3 } , { 4,5 } };
	其可视化显现大致为这样:
	1		2		3		\0
	4		5		\0		\0
	\0		\0		\0		\0
	其实此处相当于将这个二维数组视作为了3个一维数组,依次赋值而已
	注:二维数组只能省略行参数,不可省略列参数
	例:
	int arr[][4] = { { 1,2,3,4 } , { 5,6,7,8 } };
	则其可视化显现大致为这样:
	1		2		3		4
	5		6		7		8
	由此可得:省略的行参数取决于编写的默认行数<即大括号内的一维数组数>

	数组名是数组首元素的地址
	但是有两个例外:
	1. sizeof( 数组名 ) - 数组名表示整个数组 - 计算的是整个数组的大小(单位: 字节)
	2. &数组名 - 数组名表示整个数组 - 取出的是整个数组的地址


	void print(int num)
{

	printf("%d  ", num % 10);
	if (num > 9)
	{
		print(num / 10);
	}
}

int main()
{
	int number = 0;
	printf("请输入>>>\n");
	printf("number = ");
	scanf("%d", &number);
	print(number);
	return 0;
}

原码
	原码就是符号位加上真值的绝对值
    即用第一位表示符号 其余位表示值
反码
	正数的反码是其本身，负数的反码是在其原码的基础上符号位不变，其余各个位取反
补码
	正数的补码就是其本身，负数的补码是在其反码的基础上+1
Summarize:正数的原码反码补码相同
	
		+7									－7
原码	00000000 00000000 00000000 00000111	10000000 00000000 00000000 00000111
反码	00000000 00000000 00000000 00000111	11111111 11111111 11111111 11111000
补码	00000000 00000000 00000000 00000111	11111111 11111111 11111111 11111001

操作符详解：
	算术操作符
		+ 	－	*	/	%
		和	差	积	商	模
		%只能作用于整数型数据
		
	移位操作符
		>>			<<
		右移操作符	左移操作符
		右移操作符：
		对补码采取算术位移
			算术右移：右边丢弃，左边补上原符号位	
			逻辑右移：右边丢弃，左边补零
		下面是一个有关于右移操作符的例子：
		int main()
		{
			int a = 16;
			//16 = 00000000 00000000 00000000 00010000
			int b = a >> 2;
			//右移两位，算术位移：	00000000 00000000 00000000 00000100 = 4
			//即16/（2^2） = 4
			int c = -1;
			//-1原码：	10000000 00000000 00000000 00000001
			//  反码：	11111111 11111111 11111111 11111110
			//  补码：	11111111 11111111 11111111 11111111
			int d = c >> 1;
			//移动后：	11111111 11111111 11111111 11111111
			//故为－1
			printf（"%d    %d\n", b, d);
			return 0;
		}
		总结：对正数右移n位，相当于将正数除以2ⁿ
		左移操作符：
		对补码进行操作，丢弃左边，右边补零
			实例：
			int main()
			{
				int a = 5;
				//5补码：	00000000 00000000 00000000 00000101
				int b = a << 1;
				//位移：	00000000 00000000 00000000 00001010
				//故为10
				printf("%d\n", b);
				return 0;
			}
		总结：对正数左移n位，相当于将正数乘上2ⁿ
		还有对位移操作符的进一步应用，见"输入数据二进制中1个数.c"文件
	
	位操作符
		&		|		^
		按位与	按位或	按位异或
		注：只能作用于整型数据
		例子：
		#include <stdio.h>
		int main()
		{
			int a = 3;
			//00000000 00000000 00000000 00000011
	
			int b = 5;
			//00000000 00000000 00000000 00000101
			
			// & － 有假为假，双真才真（与门）
			int c = a & b;
			//00000000 00000000 00000000 00000001
			
			// | － 有真为真，无真为假（或门）
			int d = a | b;
			//00000000 00000000 00000000 00000111
	
			// ^ － 同假异真（异或门）
			int e = a ^ b;
			//00000000 00000000 00000000 00000110
	
			printf("&: %d\n",c);//1
			printf("|: %d\n",d);//7
			printf("^: %d\n",e);//6
	
			return 0;
		}
		按位异或的进阶使用请见"数据交换无临时变量搭建.c"文件
	
	赋值操作符
		简单赋值符：
			即等于“=”
			赋值操作符的运算顺序是从右往左，<——
			赋值操作符可以连续使用
			例子：
			int a = 10;
			int x = 0;
			int y = 20;
			a = x = y = 1;
			
			等效于：
			int a = 10;
			int x = 0;
			int y = 20;
			x = y + 1;
			a = x;
		复合赋值符：
			+=	  －=	*=	    /=	  %=	 >>=	  <<=	  &=	   |=	     ^=
			自加  自减	自乘  自取模 自除   自右移  自左移 自按位与 自按位或 自按位异或
	
	单目操作符
		!		    -	+  	   &			sizeof						        ~				    --		      ++				   * 					      (type)
	 逻辑反操作   负值 正值 取地址   操作数的类型长度（单位：字节）	对一个数的二进制按位取反   前置、后置--   前置后置++  间接访问操作符（解引用操作符）	   强制类型转换
		在sizeof操作符中，运算与赋值并不会在程序运行时进行，sizeof的优先级更高
		按位取反~操作符是对存储数据的补码取反（所有位次）
	
	关系操作符
		>	>=	<	<=	!=	==

	逻辑操作符
		&&		||
	   逻辑与	 逻辑或
		具体运算参见红石笔记
		逻辑运算符只要能够计算出结果，就会立即跳出运算！
		
	条件操作符
		exp1 ? exp2 :exp3
		exp1为真时，运行并输出exp2结果
		exp1为假时，运行并输出exp3结果

	逗号表达式
		exp1, exp2, exp3, …expN
		用逗号隔开的多个表达式，从左向右依次执行，输出结果为expN的结果

	下标引用、函数调用和结构成员
		下标引用操作符[]
			操作数：数组名 * 1 + 索引值 * 1
			e.g.
				int arr[10];
				arr[9] = 10;
				其中[]的两个操作数是arr与9
		函数调用操作符()
			接受一个或者多个操作数：第一个操作数为函数名，剩余操作数为传递给函数的参数
				（无需举例）
		结构成员
			注：请先阅读下文结构体变量创建
			.		结构体.成员名
			->		结构体指针->成员名（指针引用时使用）
			
			e.g.
				typedef struct arknights
				{
					char name[20];
					int age;
					char sex[5];
				}AN;

				void Pri_AN1(AN a)
				{
					printf("Name: %s\n", a.name);
					printf("Age: %d\n", a.age);
					printf("Sex: %s\n", a.sex);
				}

				void Pri_AN2(AN* a)
				{
					printf("Name: %s\n", a->name);
					printf("Age: %d\n", a->age);
					printf("Sex: %s\n", a->sex);
				}
				//此处提供的两个自定义函数，无论是从效率还是内存开销上来看，指针引用的Pri_AN2都更占优势，这也充分体现了指针在C语言中的优越性

结构体变量的创建  struct：
	struct 结构体类型名
	{
		成员列表
	}结构体变量名1, 结构体变量名2, ……;//此处创建的为全局变量

	struct tag
	{
		member - list;
	}variable - list;//一定记得结构体的创建最后要跟分号

	e.g.
		struct student
		{
			int num;
			char name[20];
			char sex;
			int age;
			float score;
			char addr[30];
		}student1, student2;

		int main()
		{
			struct student student3;
			student3 = { 3, "nihao", '1', 21, 90, "addr" };
			return 0;
		}

	可以使用typedef函数来实现结构体变量名称的简化：
		typedef struct student
		{
			......;
		}Stu;

		int main()
		{
			Stu x;
			return 0;
		}
	此处即将struct student 类型结构体变量重命名为Stu
	结构体成员牵引请见上方“结构成员”操作符

指针：
	数据类型* 变量名;
	32位机器中，存放32比特，4字节
	64位机器，存放64比特，8字节
	指针类型决定了指针进行解引用操作时，能够访问空间的大小，同时也决定了指针变量的步长（操作单位）
	e.g.
		int *指针的步长为4字节
		double *指针的步长为8字节
	不同种类的指针变量所占的内存一致
	更高级指针不再做出解释

野指针：
	指针指向的位置不可知的指针
	1.未初始化指针
		int *p;	//初始化随机地址，不可知
		*p = 20;
	2.越界访问指针
		int arr[5] = { 0 };
		int *p = arr;
		*(p + 5) = 10;//越界
	3.指针指向的空间释放
		int *test()
		{
			int a = 1;
			return &a;
		}
		int main()
		{
			int *p = test()
			*p = 10;		//指针空间被释放，查询无效
			return 0;
		}

	避免野指针，记得初始化，可以NULL赋值
		int* p = NULL;
	注意数组的指针范围，可以从初始位置到末位后一位指针指定，但不允许出现初始位置前一位地址指针，不合法
		可以通过指针与指针之间的加减运算替代传统计数器！

数组与指针之间的关系：
	数组名直接引用等同于引用数组的首元素地址 >> char str[10] = { 0 }; 有str == &str[0];
	&数组名  为取出整个数组的地址，尽管地址与首元素地址相同，但步长与数组中元素个数相关
	当出现sizeof(数组名)时，sizeof运算符是将整个数组纳入运算

指针数组：
	存放指针的数组
	e.g.
		int a = 1;
		int b = 2;
		int c = 3;
		int* parr[3] = { &a, &b, &c };
	其中parr为指针数组

内存申请：
	内存主要分为三个大区>>
	1.栈区
		局部变量
		函数的形式参数（形参）
		函数调用
		……
	2.堆区
		动态内存分配
		malloc / free
		realloc
		calloc
		……
	3.静态区
		全局变量
		静态变量
		……

数据结构：
	1.线形数据结构
		顺序表
		链表
		栈
		队列
		……
	2.树形数据结构
		二叉树
		……
	3.图
		……

//函数栈帧的创建和销毁

C语言数据变量类型：
1.内置类型（请见前文，不再赘述）
	char, short, int, long, long long, float, double, void, ……
2.自定义类型（构造类型）
	数组类型
	结构体类型 struct
	枚举类型   enum
	联合类型   union

整型变量存储：
	前情提要：“原码，反码，补码”
	大端（字节序）存储：数据的低位保存在内存的高地址，而数据的高位保存在内存的低地址
	小端（字节序）存储：数据的低位保存在内存的低地址，而数据的高位保存在内存的高地址

设计程序判断当前机器的字节序存储模式：
	int check_sys()
	{
		int a = 1;
		return *(char*)&a;
	}

	int main()
	{
		int ret = check_sys();
		if (ret)
			printf("小端存储\n");
		else
			printf("大端存储\n");
		return 0;
	}

所有的整型变量定义可在limits.h头文件中查看（包括char），浮点型变量在float.h中查看

浮点型数据在内存中的存储：
	int main()
	{
		int n = 9;
		float* pFloat = (float*)&n;
		printf("n = %d\n", n);
		printf("*pFloat = %f\n\n", *pFloat);

		*pFloat = 9.0;
		printf("n = %d\n", n);
		printf("*pFloat = %f\n", *pFloat);
		return 0;
	}
	result:	9	0.000000	1091567616		9.000000
	
	根据国际标准IEEE（电气和电子工程协会）754，任意一个二进制浮点数V可以表示成以下形式：
		V： (-1)^s * M * 2^E
		其中(-1)^s 表示符号位，s = 0时，V为正数；s = 1时， V为负数
		M表示有效数字，大于等于1，且小于2
		2^E 表示指数位
	例如 >> 9.0 = 1001.0 = (-1)^0 * 1.001 * 2^3;	其中，s = 0, M = 1.001, E = 3;

	对于32位浮点数（单精度浮点数），最高位为符号位s，再8位为指数位E，余23位为有效数字M
	对于64位浮点数（双精度浮点数），最高位为符号位s，再11位为指数位E，余52位为有效数字M
		1.其中由于有效数字M小数点前均为1，故只存储小数位，读取取出时补1即可
		2.关于指数位E，IEEE规定为无符号数据存储，故存储时，E会加上其存储上限的中间数（单精度为127，双精度为1023），读取时再减去中间数即可

	注：当指数位E为全零时，有效数字不再加上小数点前面的1，以还原其极小的真实值；当E全为1且M全为0时，数据表现为正负无穷大

	9：
	0000 0000 0000 0000 0000 0000 0000 1001
--> 0 00000000 00000000000000000001001
-->即(-1)^0 * (1/0).00000000000000000001001 * 2^(-127)，输出为0.000000
	9.0：
	1001.0
	(-1)^0 * (1).00100000000000000000000 * 2^3
--> 0 10000010 00100000000000000000000
--> 0100 0001 0001 0000 0000 0000 0000 0000
	即1091567616

指针进阶：
	1.字符指针
		[1]引用字符串
			e.g.1
				int main()
				{
					char arr[] = "abcdefg";
					char* p = arr;
					printf("%s\n", arr);
					printf("%s\n", p);
					return 0;
				}
				二者输出结果一致
			e.g.2
				int main()
				{
					const char* p = "abcdefg";
					//将"abcdefg"作为一个常量字符串，取其首元素地址放入指针p中
					//const修饰p指针，使得*p无法被修改
					printf("%c\n", *p);
					printf("%s\n", p);

					//*p = 'w'不可执行，一定注意"abcdefg"为常量字符串，不可改动
					return 0;
				}
				结果：
					a
					abcdefg
	2.数组指针
		存放指针的数组
		int *arr[5];
		char *ch[5];
		均为指针数组
		e.g.
			int main()
			{
				int arr1[] = { 1,2,3,4,5 };
				int arr2[] = { 2,3,4,5,6 };
				int arr3[] = { 3,4,5,6,7 };
				int* arr[] = { arr1,arr2,arr3 };//将三个数组的首元素存入，形成类似于二维数组的结构
				
				int i = 0;
				for (i = 0; i < 3; i++)
				{
					int j = 0;
					for (j = 0; j < 5; j++)
					{
						printf("%d  ", *(arr[i] + j));
					}
					printf("\n");
				}
				return 0;
			}
	3.指针数组
		存放数组地址的指针
		e.g.
			int main()
			{
				int arr[5] = { 1,2,3,4,5 };
				int (*p)[5] = &arr;
				//作为一个指针数组，其本质为数组，加上括号的原因时[]的优先级高于*，此处创建的p即为一个指向有五个元素的数组的指针，变量后面的[5]即指向含有五个元素的东东，*p本身为指针

				char* arr1[5];
				char* (*p1)[5] = &arr1；
				//此处存放一个数组指针，其类型为char* ，参数为[5]，故直接沿用，中间添上(*变量名)，形成一个指针数组

				//指针数组的使用1
				for (int i = 0; i < 5; i++)
				{
					printf("%3d", (*p)[i]);//这里(*p)即为整个数组arr（即：(*p) = (*(&arr)) = arr），随后通过[i]找到对应元素
					printf("%3d\n", *((*p) + i));//这里是通过(*p)得到数组首元素地址（即数组名），通过指针运算指向各个元素，解引用得到对应值
				}
				//但是此种使用方法极其麻烦，可以以如下方式完全平替
				int* pp = arr;
				for (int i = 0; i < 5; i++)
					printf("%3d", *(p + i));//通过指针的步长解决，更加直接简单

				//指针数组的使用2
				int arrr[3][5] = { {1,2,3,4,5},{2,3,4,5,6},{3,4,5,6,7} };
				print1(arrr, 3, 5);//形参打印函数
				print2(arrr, 3, 5);//指针数组打印函数
				//此处传入数组名arrr，即arrr首元素地址
				//对于一个多维数组，应该先将其视为一个一维数组，其相并列的内容为其元素，此处arrr数组的首元素即{1,2,3,4,5}(一个一维数组)，所以传入的为数组{1,2,3,4,5}这个数组的地址，应当用一个对应的数组指针接受，即定义的int (*p)[5]  （因为这个数组的长度为5）
				
				return 0;
			}
			//补充：对于一个数组，arr[i] == *(arr + i);

			void print1(int arrr[3][5],int y, int x)
			{
				for (int i = 0; i < y; printf("\n"), i++)
					for (int j = 0; j < x; j++)
						printf("%3d", arrr[i][j]);
			}//无需多言

			void print2(int (*p)[5], int y, int x)
			{
				for (int i = 0; i < y; printf("\n"), i++)
					for (int j = 0; j < x; j++)
						printf("%3d", (*(p + i))[j]);
						//printf("3d", *(*(p + i) + j));同理，输出一致
						//printf("3d", *(p[i] + j));
						//printf("3d", p[i][j]; 
						//+的优先级低于*，所以加上括号
						//p自身即为这个数组的地址，该数组的步长为一整个数组，即有此运算，通过+i来指引p引向对应行，[j]以定位
			}
	4.数组传参和指针传参
		[1]一维数组传参
			void test(int arr[]){}
			void test(int arr[10]){}
			void test(int* arr){}
			void test2(int* arr[20]){}
			void test2(int** arr){}
			//以上传参均正确合法且有效
			int main()
			{
				int arr1[10];
				int* arr2[20];
				test(arr1);
				test2(arr2);
			}
		[2]二维数组传参
			void test(int arr[3][5]){}
			void test(int arr[][5]){}
			//void test(int arr[][]){}不可，二维数组的列不可省略
			//void test(int arr[3][]){}同理
			//void test(int *arr){}不可，传入为一维数组的地址，而非单个元素地址
			//void test(int *arr[5]){}不可，此为指针数组，而非数组指针
			void test(int (*arr)[5]){}
			//void test(int **arr){}不可，此为二级指针，存入应为数组地址

			int main()
			{
				int arr[3][5] = { 0 };
				test(arr);
				return 0；
			}
		[3]一级指针传参
			可以直接传递数据地址或者一维数组名（即其首元素地址），也可以传递一级指针变量，无需多言
		[4]二级指针传参
			可以直接传递一级指针地址或者以及指针数组名（即其首元素一级指针的地址），也可以传递二级指针变量，同上
	5.函数指针
		指向函数的指针
		e.g.
			int add(int a, int b)
			{
				return a + b;
			}

			int main()
			{
				int a = 1;
				int b = 2;
				printf("%p\n", &add);
				printf("%p\n", add);
				//得到的两个地址相同
				//函数名与&函数名完全相同，均得到函数地址

				int (*p)(int, int) = add;
				//定义一个函数指针，要有原函数的所有相关信息，如返回数值类型，参数类型等（由于函数的()优先级比*高，所以要加上()保证其为指针而非函数）

				printf("%d\n", (*p)(a, b));//与前两种打印相同，此处显示函数指针的基础使用
				printf("%d\n", p(a, b));//与上方同理，由于&函数名 == 函数名，故可以不用解引用
				//(**p)(a, b)	(***p)(a, b)等同理，均得到相同结果
				return 0;
			}

		思考题1：
			(*(void(*)()0)();
			是将0这个数值转换为void(*)()函数指针类型，然后解引用并运用
		思考题2：
			void(*signal(int, void(*)(int)))(int)
			此处揭示了返回值为函数指针的函数如何定义（此处返回的函数指针类型为void(*)(int)）
			该函数名称为signal,引入参数为int与void(*)(int)，形式是将这一部分（名称以及参数）放入返回函数指针类型中间
			简化（typedef）:
				typedef void(*new)(int);
				这里将一个变量，即函数指针变量void(*)()用typedef给予新的名称new
				注意typedef在重定义变量名称时新变量名的位置（特殊）
				则起始代码可简化为
					new signal(int, new);
	6.函数指针数组
		还是从函数指针入手
		int add(int x, int y)
		{
			return x + y;
		}
		int sub(int x,int y)
		{
			return x - y;
		}
		int mul(int x, int y)
		{
			return x * y;
		}
		int div(int x, int y)
		{
			return x / y;
		}
		则有
		int main()
		{
			int (*p[])(int, int) = { 0,add,sub,mul,div };//直接在变量名后面紧跟数据量，参考优先级，重定义为一个含有四个元素的数组，元素类型为函数指针int(*)(int, int)，即一个函数指针数组
			int chc = 0;
			int x = 0, y = 0;
			scanf("%d", &chc);
			scanf("%d %d", &x, &y);
			printf("%d\n", p[chc](x, y));//一个函数转换表，简化了代码
			return 0;
		}
	7.指向函数指针数组的指针
		指向函数指针数组的指针 是一个 指针，指向一个 数组，数组的元素是 函数指针
		e.g.
		int main()
		{
			int (*p[4])(int, int);
			//p是一个函数指针数组，可容纳四个元素，元素类型为int (*)(int, int)函数指针
			int (*(*pp)[4])(int, int) = &p;
			//pp是一个指向函数指针数组的指针，(*pp)表示其为指针，[4]表示其指向一个含有四个元素的数组，外围int(*)(int, int)指明元素类型
			return 0;
		}
	8.回调函数
		回调函数就是一个通过函数指针调用的函数。如果你把函数的指针/地址作为参数传递给另一个函数，当这个指针被用来调用其所指向的函数时，我们就说这是回调函数。
		回调函数不是由该函数的实现方直接调用，而是在特定的事件或条件发生时由另外的一方调用，用于对该事件或条件进行响应
		e.g.（接函数指针数组例子实现）
			void Calc(int (*p)(int,int))
			{
				int x = 0, y = 0;
				scanf("%d %d", &x, &y);
				printf("%d\n", p(x, y));
			}
			//条件引用Calc，比如Calc(add)等，此处省略

		void* 指针变量讲解：
			无类型指针，可以接受任意类型的地址
			int main()
			{
				int a = 10;
				void* p = &a;

				//*p = 0;	(error!)
				//此处p指针类型依旧为void，将该指针解引用并赋一个整形值不合法，因为虚空索敌(bushi)
				//即void* 指针类型不允许解引用，因为不知道其操作字节数
				//p++;		(error!)
				//void* 类型指针不知步长！
				float b = 1.0;
				p = &b;


				return 0;
			}
	9.题目分析
		看课件去OAO

	strcmp		库函数		对两个给定字符串进行比较
	包含于 string.h 头文件中
	所以引用前须声明：
	#include <string.h>
	声明：
	int strcmp(const char* str1, const char* str2);
	对str1与str2字符串逐个字符用ASCLL值进行比较，直到得到结果为止
	有：
		return < 0				str1 < str2
		return = 0				str1 = str2
		return > 0				str1 > str2
	使用见下方qsort库函数实例

	自实现strcmp：
	int my_strcmp(const char* str1, const char* str2)
	{
		assert(str1 && str2);
		while (*str1 == *str2)
		{
			if (*str1 == '\0')
				return 0;
			str1++, str2++;
		}
		if (*str1 > *str2)
			return 1;
		else
			return -1;
	}

	qsort		库函数		对数组进行快速排序
	包含于 stdlib.h 头文件中
	所以引用前须声明：
	#include <stdlib.h>
	声明：
	void qsort(void *base, size_t nitems, size_t size, int(*compar)(const void * , const void * ));
	base指针指向操作地址，nitems引入元素个数，size引入单个元素大小，compar函数指针回调一个对应的比较函数
	qsort库函数自身只提供排序方式，其对应元素比较需要回调相应函数以适应
	其中compar函数指针指向的对应函数有如下要求：（这样最终得到的排序是从小到大，如果想要从大到小可以逆向输入）
		return < 0				前项 < 后项
		return = 0				前项 = 后项
		return > 0				前项 > 后项
	使用：

		#include <stdlib.h>
		#include <stdio.h>
		#include <string.h>
		int cmp_int (const void * e1, const void * e2)
		{
			//整形排序
			return *(int*)e1 - *(int*)e2;
			//想实现倒序可以采用以下方式
			//return *(int*)e2 - *(int*)e1;
		}
		
		int cmp_flt (const void * e1, const void * e2)
		{
			//同理
			if (*(float*)e1 > *(float*)e2)
				return 1;
			else if (*(float*)e1 < *(float*)e2)
				return -1;
			else
				return 0;
			//return (int)(*(float*)e1 - *(float*)e2);
			//注释里的这种写法严格意义上来说并不好，强制类型转换成为int造成的精度缺失会导致e1、e2指向变量差值小于1时无法得到有效比较
			//但是一定要记住返回值为int型
		}

		struct Stu {
			char name[20];
			int age;
		};

		int cmp_Stu_name(const void* e1, const void* e2)
		{
			return strcmp(((struct Stu*)e1) -> name, ((struct Stu*)e2) -> name);
			//->的优先级高于强制类型转换，注意加括号
			//展示了strcmp的用法
		}

		int cmp_Stu_age(const void* e1, const void* e2)
		{
			return (((struct Stu*)e1)->age - ((struct Stu*)e2)->age);
		}

		void prt_Stu_arr(struct Stu* arr, const int sz)
		{
			//打印结构体
			for (int i = 0; i < sz; i++)
				printf("name = %s\nage = %d\n", arr[i].name, arr[i].age);
			printf("\n");
		}

		int main()
		{
			int arr1[10] = { 1,5,2,6,8,4,7,9,3,0 };
			int sz1 = sizeof(arr1) / sizeof(arr1[0]);
			qsort(arr1, sz1, sizeof(arr1[0]), cmp_int);//因为函数地址与函数名本身一致，所以可以直接传入函数名
			for (int i = 0; i < sz1; i++)
				printf("%2d", arr1[i]);

			float arr2[10] = { 1.0,5.0,6.0,9.0,7.0,2.0,8.0,4.0,3.0,0.0 };
			int sz2 = sizeof(arr2) / sizeof(arr2[0]);
			qsort(arr2, sz2, sizeof(arr2[0]), cmp_flt);
			for (int i = 0; i < sz2; i++)
				printf("%2f", arr2[i]);

			struct Stu arr3[3] = { {"zhangsan", 18},{"lisi",19},{"wangwu",17} };
			int sz3 = sizeof(arr3) / sizeof(arr3[0]);
			qsort(arr3, sz3, sizeof(arr3[0]), cmp_Stu_name);
			prt_Stu_arr(arr3, sz3);
			qsort(arr3, sz3, sizeof(arr3[0]), cmp_Stu_age);
			prt_Stu_arr(arr3, sz3);
			return 0;
		}

模拟qsort，自定义函数通用排序bubble_sort:
	#include <stdio.h>

	void swap(char* e1, char* e2)
	{
		*e1 = *e1 ^ *e2;
		*e2 = *e1 ^ *e2;
		*e1 = *e1 ^ *e2;//通过按位异或来实现无变量交换数值
	}

	void bubble_sort(void* base, int sz, int width, int (*cmp)(const void* e1, const void* e2))
	{
		char* ba = (char*)base;//强制类型转换，步长有效化
		for (int i = 0; i < sz - 1; i++)//趟数
			for (int j = 0; j < sz - 1 - i; j++)//每趟比较数
				//if (cmp(ba + j * width, ba + (j + 1) * width) >= 1)
				if (cmp(&ba[j * width], &ba[(j + 1) * width]) >= 1)//探询是否交换
					for (int k = 0; k < width - 1; k++)//根据给定数据width来交换数值，完全实现步长
					{
						/*
						第一种写法
						char ex = *(ba + j * width + k);
						*(ba + j * width + k) = *(ba + (j + 1) * width + k);
						*(ba + (j + 1) * width + k) = ex;
						*/

						/*
						第二种写法
						*(ba + j * width + k) = *(ba + j * width + k) ^ *(ba + (j + 1) * width + k);
						*(ba + (j + 1) * width + k) = *(ba + j * width + k) ^ *(ba + (j + 1) * width + k);
						*(ba + j * width + k) = *(ba + j * width + k) ^ *(ba + (j + 1) * width + k);//通过按位异或来实现无变量交换数值
						*/

						/*
						第三种写法
						ba[j * width + k] = ba[j * width + k] ^ ba[(j + 1) * width + k];
						ba[(j + 1) * width + k] = ba[j * width + k] ^ ba[(j + 1) * width + k];
						ba[j * width + k] = ba[j * width + k] ^ ba[(j + 1) * width + k];//视为数组，观感更好，[]中运算编译时只会计算一次，而后调用，效率更高
						*/

						//第四种写法
						swap(&ba[j * width + k], &ba[(j + 1) * width + k]);//调用函数，尽管相对于第三种写法效率下降，但可读性更强
					}
	}

	int cmp_int(const void* e1, const void* e2)
	{
		return *(int*)e1 - *(int*)e2;
	}

	int main()
	{
		int arr[10] = { 1,5,9,6,8,7,3,2,4,0 };
		int sz = sizeof(arr) / sizeof(arr[0]);
		bubble_sort(arr, sz, sizeof(arr[0]), cmp_int);
		for (int i = 0; i < sz; i++)
			printf("%d\t", arr[i]);
		return 0;
	}

	assert		库宏		允许诊断信息被写入到标准错误文件中,即添加诊断
	包含在assert.h头文件中
	所以引用前须声明：
	#include <assert.h>
	声明：
	assert(expression);
	用于在程序运行时检查某个表达式是否为真。如果该表达式为假，assert() 宏会输出错误信息并终止程序的执行
	expression为一个你希望检查的条件表达式，可以为任何变量或者任意C表达式
	expression为TRUE时，assert()不执行动作；为FALSE时，assert()会在标准错误stderr上显示错误信息，并中止程序执行

	strcat		库函数		在一字符串后追加另一字符串
	包含在string.h头文件中
	所以引用前须声明：
	#include <string.h>
	声明：
	char* strcat(char* dest, const char* src)
	其中src为追加字符串，dest为增长的字符串
	注意，在追加字符串时，一定要保证dest有足够空间存放整个字符串
	src的追加是在遇到dest中的第一个'\0'时，用整个字符串（包括'\0'）替换掉'\0'

	strcat自实现：
	char* my_strcat(char* dest, const char* src)
	{
		char* ret = dest;
		assert(dest && src);
		while (*dest)
			dest++;
		while (*dest++ = *src++);
		return ret;
	}

	strncpy		库函数		用于字符串复制
	包含在string.h头文件中
	所以引用前须声明：
	#include <string.h>
	声明：
	char* strncpy(char* dest, const char* src, size_t n)
	dest为指向用于存储复制内容的目标字符串，src为要复制的字符串，n为要从源中复制的字符数
	当n大于复制源字符串的长度时，会将不足的长度用\0补齐，而后复制过去

	strncmp		库函数		用于比较两个字符串的前n个字符是否相等
	包含在string.h头文件中
	所以引用前须声明：
	#include <string.h>
	声明：
	int strncmp(const char* str1, const char* str2, size_t n)
	str1，str2为进行比较的两个字符串，n为要比较的最大字符数
	返回值：
		<0		str1<str2
		=0		str1=str2
		>0		str1>str2
	太过简单，不做展示

	strncat		库函数		与strcat同理，多一个字符数参数，不做讲解
	包含在string.h头文件中
	所以引用前须声明：
	#include <string.h>
	声明：
	char* strncat(char* dest, const char* src, size_t n)

	strstr		库函数		在字符串中查找子字符串
	包含在string.h头文件中
	所以引用前须声明：
	#include <string.h>
	声明：
	char* strstr(const char* haystack, const char* needle);
	haystack为主字符串，needle为子字符串，返回值为指向该位置的指针或者NULL

	自实现strstr：
	char* my_strstr(const char* haystack, const char* needle) {
		assert(haystack && needle);
		while (*haystack++ != *needle);
		while (*haystack++ == *needle++);
		if (!*needle)
			return *haystack;
		else
			return NULL;
	}

	strtok		库函数		将字符串分割为多个子字符串
	包含在string.h头文件中
	所以引用前须声明：
	#include <string.h>
	声明：
	char* strtok(char* str, const char* delim)
	其中str是作用的字符串， 第一次调用时传入对应字符串，而后循环传入NULL，表示继续分割同一字符串，delim为分割符，返回值为指向下一个标记的指针