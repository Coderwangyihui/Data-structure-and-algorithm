#define _CRT_SECURE_NO_WARNINGS 1
//#include<stdio.h>
//数组实现 
//int* sort(int* arr, int length);
//int main()
//{
//	int arr[10] = { 10,9,8,7,6,5,4,3,2,1 };
//	int i, length=sizeof(arr)/sizeof(arr[0]);
//	for (i = 0;i < length;i++)
//		printf("%d ", sort(arr, length)[i]);
//	puts("\n");
//	return 0;
//}
//int* sort(int* arr,int length)
//{
//	int i,j;
//	for (j = 0;j < length-1;j++)
//	{
//		for(i=j;i>=0;i--)
//		{
//			if (arr[i] > arr[i + 1])
//			{
//				arr[i] = arr[i] ^ arr[i + 1];
//				arr[i + 1] = arr[i] ^ arr[i + 1];
//				arr[i] = arr[i] ^ arr[i + 1];
//			}
//		}
//	}
//	return arr;
//}
//链表实现（未完成）
//typedef struct arr {
//	int info;
//	struct arr* p;
//}arr;
//int main()
//{
//	arr a[10];
//	int i, length = sizeof(a) / sizeof(a[0]);
//	for (i = 0;i < length;i++)
//    {
//		a[i].info = length;
//		if (i == length)
//			*(a[i].p) = a[i + 1];
//		else
//			a[i].p = NULL;
//	}
//	for (i = 0;i < length;i++)
//		printf("%d ", sort(a, length)[i]);
//	puts("\n");
//	return 0;
//}
//int* sort(arr* a, int length)
//{
//}
#include<stdlib.h>
#include<stdio.h>
#define lengthe 10000
#define Maxsize 10 //静态顺序表的初始最大容量
#define Initsize 10 //动态顺序表的初始最大容量
#define bool char
#define true 1
#define false 0
typedef int Elemtype;//自定义数据元素的数据类型
//顺序表的基本实现done
//顺序表的结构体定义
typedef struct Sqlist{//静态分配
	Elemtype data[Maxsize];
	int length;//静态表的当前长度(元素个数)
}Sqlist;
typedef struct Seqlist {//动态分配
	Elemtype* data;
	int length;
	int maxsize;//动态表的最大容量
}Seqlist;
//顺序表的判空、遍历输出
bool isempty(Sqlist L)
{
	if (L.length == 0)
	{
		printf("empty\n");
		return false;
	}
	printf("Sqlist:-->\n");
	for (int i = 0;i < L.length;i++)
	{
			printf("%d - ->", L.data[i]);
	}
	printf("end\n");
	return true;
}
bool isempty(Seqlist L)
{
	if (L.length == 0)
	{
		printf("empty\n");
		return false;
	}
	printf("Seqlist:-->\n");
	for (int i = 0;i < L.length;i++)
	{
		printf("%d - ->", L.data[i]);
	}
	printf("end\n");
	return true;
}
//初始化
bool InitSqlist(Sqlist* L)
{
	L->length = 0;
	//for (int i = 0;i < L->length;i++)
	//{
	//	L->data[i] = 0;
	//}
	return true;
}
bool InitSeqlist(Seqlist* L)
{
	L->length = 0;
	L-> maxsize = Maxsize;
	L->data = (Elemtype*)malloc(Maxsize * sizeof(Elemtype));
	return true;
}
//顺序表的元素插入
bool insertSqlist(Sqlist* L,int i,Elemtype e)
{
	if (i<1 || i> (L->length+1 ))
	{
		printf("error11!\n");
		return false;
	}
	if (L->length >= Maxsize)
	{
		printf("error!12\n");
		return false;
	}
	for (int j = L->length;j >= i;j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i-1] = e;
	L->length++;
	return true;
}
bool insertSqelist(Seqlist* L, int i, Elemtype e)
{
	if (i<1 || i> L->length+1)
	{
		printf("error21!\n");
		return false;
	}
	if (L->length >= L->maxsize)
	{
		printf("error22!\n");
		return false;
	}
	for (int j = L->length;j >= i;j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i - 1] = e;
	L->length++;
	return true;
}
//顺序表的遍历输出
bool PintSqlist(Sqlist L)
{
	for (int i = 0;i < L.length;i++)
	{
		printf("%d-->", L.data[i]);
	}
	return true;
}
bool PintSeqlist(Seqlist L)
{
	for (int i = 0;i < L.length;i++)
	{
		printf("%d-->", L.data[i]);
	}
	return true;
}
//顺序表的元素删除（按位删除）
bool SqlistElemDelect(Sqlist* L, int i, Elemtype* e)//将e的值带出顺序表  通过e可以返回多个值借助于指针形式
{
	if (i<1 || i> L->length)
	{
		printf("error11!\n");
		return false;
	}
	if (L->length < 1)
	{
		printf("error!\n");
		return false;
	}
	*e = L->data[i - 1];
	for (int j = i-1;j < L->length-1;j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}
bool SeqlistElemDelect(Seqlist* L, int i, Elemtype* e)//将e的值带出顺序表  通过e可以返回多个值借助于指针形式
{
	if (i<1 || i> L->length + 1)
	{
		printf("error11!\n");
		return false;
	}
	if (L->length < 1)
	{
		printf("erroe!\n");
		return false;
	}
	*e = L->data[i - 1];
	for (int j = i - 1;j < L->length - 1;j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}
//Elemtype SqlistElemDelect(Sqlist L, int i)
//{
//	return 删除元素的值；      只能返回一个值
//}
// 顺序表的按值删除 

//顺序表的按值查找
//顺序查找
int Sqlistsearch(Sqlist L, Elemtype e)
{
	if (!L.length)
	{
		return 0;
	}
	for (int i = 0;i < L.length;i++)
	{
		if (e == L.data[i])
		{
			return i + 1;
		}
	}
}
int Seqlistsearch(Seqlist L, Elemtype e)
{
	for (int i = 0;i < L.length;i++)
	{
		if (e == L.data[i])
		{
			return i + 1;
		}
	}
	return 0;
}
//折半查找
int searchsqlisthalf(Sqlist L, Elemtype e)
{
	int low = 1;
	int high = L.length;
	int mid = (low + high) / 2;
	while (low <= high)
	{
		if (e == L.data[mid - 1])
		{
			return mid;
		}
		else
		{
			if (e > L.data[mid - 1])
			{
				low = mid + 1;
				mid = (low + high) / 2;
			}
			else
			{
				high = mid - 1;
				mid = (low + high) / 2;
			}
		}
	}
	return 0;
}
int searchseqlisthalf(Seqlist L, Elemtype e)
{
	int low = 1;
	int high = L.length;
	int mid = (low + high) / 2;
	while (low <= high)
	{
		if (e == L.data[mid - 1])
		{
			return mid;
		}
		else
		{
			if (e > L.data[mid - 1])
			{
				low = mid + 1;
				mid = (low + high) / 2;
			}
			else
			{
				high = mid - 1;
				mid = (low + high) / 2;
			}
		}
	}
	return 0;
}
//动态顺序表的扩容
bool IncreaseSeqlist(Seqlist* L,int h)
{
	Elemtype* p = L->data;
	L->data = (Elemtype*)malloc((Maxsize+h) * sizeof(Elemtype));
	for (int i = 0;i < L->length;i++)//转移数据
	{
		L->data[i] = p[i];
	}
	L->maxsize +=  h;
	free(p);
	p = NULL;
	return true;
}
//测试代码如下：

//int main()
//{
//	Sqlist L1;
//	Seqlist L2;
//	//L2.maxsize = 1;
//	InitSqlist(&L1);
//	InitSeqlist(&L2);
//	//printf("%d", L2.maxsize);
//	insertSqlist(&L1, 1, 1);
//	insertSqlist(&L1, 2, 2);
//	insertSqlist(&L1, 3, 3);
//	insertSqlist(&L1, 4, 44444);
//	insertSqelist(&L2, 1, 1);
//	insertSqelist(&L2, 2, 2);
//	insertSqelist(&L2, 3, 3);
//	insertSqelist(&L2, 4, 2222);
//	int e;
//	SqlistElemDelect(&L1, 2, &e);
//	SeqlistElemDelect(&L2, 2, &e);
//	printf("e=%d\n", e);
//
//	printf("1 is located in %d(sqlist)\n", Sqlistsearch(L1, 1));
//	printf("2222 is located in %d(seqlist)\n", Seqlistsearch(L2, 2222));
//	PintSqlist(L1);
//	printf("end\n");
//	PintSeqlist(L2);
//	puts("end\n");
//	printf("end\n");
//
//	isemptysq(L1);
//	printf("end\n");
//	isemptyseq(L2);
//	printf("end\n");
//
//	int h = 8 * sizeof(Elemtype);
//	IncreaseSeqlist(&L2, h);
//	return 0;
//	//int* p = (int*)malloc(lengthe * sizeof(int));
//	//int arr[lengthe];
//	//p=arr;
//	//if (!p)
//	//	return 0;
//	//int length = 0;
//	//int listsize = length * sizeof(int);
//	//return ture;
//	////iniSqlist
//}

//链表的基本实现done
//结构体定义
typedef struct Lnode {
	Elemtype data;//数据元素
	struct Lnode* next;
}Lnode, * linklist;//*linklist是专指向头结点的指针
//为什么头结点与数据结点结构一致？？？
//typedef struct Lnode {
//	int data;//数据元素个数
//	struct Lnode* next;
//}*linklist;//*linklist是专指向头结点的指针
//typedef struct Lnode {
//	Elemtype data;//数据元素
//	struct Lnode* next;
//}Lnode; 

//初始化
bool Initnode1(linklist L)
{
	L->data = 0;//0个数据元素
	L->next = NULL;//头结点的初始化
	return true;
}	  
//int main1()
//{
//	linklist L;
//  L = (linklist)malloc(sizeof(Lnode));
//	Initnode1(L);
//}
//L分配的空间会在返回函数后销毁 不再使用
linklist InitLnode2()
{
	linklist L = (linklist)malloc(sizeof(Lnode));
	L->data = 0;
	L->next = NULL;//头结点的初始化
	return L;
}
//int main2()
//{
//	linklist L=InitLnode2();
//}
bool Pintlinklist(linklist L)
{
	linklist p = L;
	while (p->next)
	{
		p = p->next;
		printf("%d- ->", p->data);
	}
	puts("NULL\n");
	return true;
}
//头插法
bool headinsertlinklist(linklist L)
{
	linklist newnode;
	Elemtype newdata;
	scanf("%d", &newdata);
	while (newdata != 9999)
	{
		newnode = (linklist)malloc(sizeof(Lnode));
		newnode->next = L->next;
		L->next = newnode;
		newnode->data = newdata;
		L->data++;
		scanf("%d", &newdata);
	}
	return true;
}
//尾插法
bool tailinsertlinklist(linklist L)
{
	linklist newnode;
	linklist tailnode=L;
	Elemtype newdata;
	while (tailnode->next)
	{
		tailnode= tailnode->next;
	}
	//插入操作
	scanf("%d", &newdata);
	while (newdata != 9999)
	{
		newnode = (linklist)malloc(sizeof(Lnode));
		newnode->next = NULL;
		newnode->data = newdata;
		tailnode->next = newnode;
		tailnode = newnode;
		L->data++;
		scanf("%d", &newdata);
	}
	return true;
}
//按位插入
bool insertlinklinstbylocate(linklist L, int i,Elemtype e)
{
	if (i<1 || i>(L->data+1))
	{
		return false;
	}
	linklist p = searchlinklistbylocate(L, i-1);
	linklist newnode = (linklist)malloc(sizeof(Lnode));
	newnode->data = e;
	newnode->next = p->next;
	p->next = newnode;
	L->data++;
	return true;
}
//按位删除
bool delectlinklistbylocate(linklist L, int i)
{
	if(!L->next)
	{
		return false;
	}
	if (i<1 || i>L->data )
	{
		return false;
	}
	linklist p = searchlinklistbylocate(L, i - 1);
	linklist s = p->next;
	p->next = s->next;
	free(s);
	s = NULL;
	return true;
}
//销毁链表
bool destorylkinklist(linklist L)
{
	while (!L->next)
	{
		delectlinklistbylocate(L, 1);
	}
	free(L);
	L = NULL;
	return true;
}
//按位查找
linklist searchlinklistbylocate(linklist L,int i)
{
	if (i==0)
		return L;//有意义的
	if (i<1 || i>L->data)
		return NULL;
	linklist p=L;
	for (int j = 0;j < i;j++)
	{
		p = p->next;
	} 
	return p;
}
//按值查找
linklist searchlinklistbyvalue(linklist L, Elemtype e)
{
	linklist p = L;
	if (!L->next)
		return L;
	while (p =p->next)
	{
		if (e == p->data)
			return p;
	}
	return NULL;
}
//测试代码：

//int main()
//{
//	linklist L;
//	L = (linklist)malloc(sizeof(Lnode));
//	Initnode1(L);
//	headinsertlinklist(L);
//	tailinsertlinklist(L);
//	insertlinklinstbylocate(L, 2, 3333);
//	insertlinklinstbylocate(L, 3, 4444);
//	Pintlinklist(L);
//
//	delectlinklistbylocate(L, 3);
//	Pintlinklist(L);
//	destorylkinklist(L);
//	return 0;
//}
//查找算法实践
//顺序查找

//查找算法实践done
//按值查找
int searchsqlistbyvalue(Sqlist L, Elemtype e)
{
	if (!L.length)
	{
		return 0;
	}
	for (int i = 0;i < L.length;i++)
	{
		if(e==L.data[i])
		{
			return i+1	;
		}
	}
}
linklist searchlinklistbyvalue(linklist L, Elemtype e)
{
	linklist p = L;
	if (!L->next)
		return L;
	while (p = p->next)
	{
		if (e == p->data)
			return p;
	}
	return NULL;
}
//折半查找
int searchseqlisthalf(Seqlist L, Elemtype e)
{
	int low = 1;
	int high = L.length;
	int mid = (low + high) / 2;
	while (low <= high)
	{
		if (e == L.data[mid - 1])
		{
			return mid;
		}
		else
		{
			if (e > L.data[mid - 1])
			{
				low = mid + 1;
				mid = (low + high) / 2;
			}
			else
			{
				high = mid - 1;
				mid = (low + high) / 2;
			}
		}
	}
	return 0;
}//已在顺序表实现
//索引查找
struct block {
	int key;
	int start;
	int end;
}block[4];//分块 三块用于存储数据 第一块空出方便逻解释
int blocksearch(int num, Elemtype a[])
{
	int i = 1, j;
	while (i < 4 && num>block[i].key) {
		i++;
	}
	if (i > 3)
	{
		return 0;
	}
	//块内部查找元素
	j = block[i].start;
	for (;j < block[i].end;j++)
	{
		if (num == a[j])
		{
			return j + 1;
		}
	}
	while (j <= block[i].end && a[j] != num) {
		j++;
	}
	if (j > block[i].end)
	{
		j = 0;
	}
	return j;
}
//blocksearch函数测试代码：

//int main()
//{
//	int i, j = 0, key;
//	int a[16] = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16 };
//	for (i = 1;i < 4;i++)
//	{
//		block[i].start = j + 1;//1 j=0
//		j++;//j=1
//		block[i].end = j + 4;//5
//		j += 4;//j=5
//		block[i].key = a[j];
//	}
//	printf("%d\n", blocksearch(7, a));
//	return 0;
//}
//哈希查找（除留余数法、线性探测再散列法）!!!
//构造了哈希表的同时也将数据存储，查找到的是在哈希表内的位置
#define max 20
int hashSeqlist(Elemtype a[],int size,Elemtype e)
{
	int list[max] = {0};
	for (int i = 0;i < size;i++)
	{
		if (!list[a[i] % 13])
		{
			list[a[i] % 13] = a[i];//实现哈希函数并存入数组中
		}
		else
		{
			while (1)
			{
				static int j = 1;
				if (!list[a[i] % 13 + j])
				{
					list[a[i] % 13 + j] = a[i];
					break;
				}
				j++;
			}
		}
	}
	if (list[e % 13])
	{
		while (1)
		{
			static int j = 0;
			if (e==list[e % 13 + j])
			{
				int i = e % 13 + j;
				return i;
			}
			j++;
		}
	}
	else return 0;
}
//测试代码：

//int main()
//{
//	linklist L = InitLnode2();
//	headinsertlinklist(L);//输入9999才会停止插入
//	linklist p=searchlinklistbyvalue(L, 6);
//	printf("%d\n",p->data);//确认指针指向了正确的地址
//	Elemtype arr[] = { 9,21,7,6,5,4,3,2,1,8 };
//	printf("%d\n", hashSeqlist(arr, 10, 8));
//	return 0;
//}
//特殊链表的实践
//双向链表

//循环链表
typedef struct circleSeqlist {
	Elemtype data;
	struct circleSeqlist* next;
}circleSeqlist, * Qseqlist;
//初始化
bool initcircleSeqlist(Qseqlist L)
{
	L->data = 0;
	L->next = L;
	return true;
}
//头插法、尾插法、按位插入法
//按位删除
//按值查找！！判断返回条件！！

//双向链表
typedef struct edLnode {
	Elemtype data;
	struct edLnode* prior;
	struct edLnode* next;
}edLnode,*edlinklist;
//初始化
bool initedLnode(edlinklist L)
{
	L->data = 0;
	L->prior = L->next = NULL;
	return true;
}
//头插法、尾插法、按位插入法!!
//按位删除!!
//按值查找

//双向循环链表
typedef struct circleedLnode {
	Elemtype data;
	struct edLnode* prior;
	struct edLnode* next;
}circleedLnode;
//初始化
bool initcircleedLnode(circleedLnode* L)
{
	L->data = 0;
	L->next = L;
	L->prior = L;
}
//插入!!
//删除!!
//查找
 
//特殊线性表的实践 
//顺序栈(一般是静态分配内存)!!!!done
#define MAX 100
typedef struct sqstack
{
	Elemtype data[MAX];
	int base;
	int top;
}sqstack;
bool initsqstack(sqstack* L)
{
	L->top = L->base = -1;
	return true;
}
bool destorysqstack(sqstack* L)
{
	Elemtype* e;
	while (L->top)
	{
		popsqstack(L, e);
	}
	free(L);
	L = NULL;
	return true;
}
bool pushsqstack(sqstack* L, Elemtype e)
{
	if (L->top == MAX-1)
	{
		return false;
	}
	L->top++;
	L->data[L->top] = e;
	return true;
}
bool popsqstack(sqstack* L,Elemtype* e)
{
	if (-1==L->top )
	{
		return false;
	}
	*e = L->data[L->top];
	L->top--;
	return true;
}
bool visitsqstack(sqstack* L, int i)
{
	if (i > L->top)
	{
		return false;
	}
	printf("%d", L->data[i]);
	return true;
}
bool gettopstack(sqstack* L, Elemtype* e)
{
	if (!(L->top + 1))
	{
		return false;
	}
	*e = L->data[L->top];
	return true;
}
//测试代码：

//int main()
//{
//	sqstack* L = (sqstack*)malloc(sizeof(sqstack));
//	initsqstack(L);
//	for (int i = 0;i < 16;i++)
//	{
//		pushsqstack(L, i);
//	}
//	for (int j = 0;j < 16;j++)
//	{
//		visitsqstack(L, j);
//	}
//	Elemtype* p, * e;
//	p = (Elemtype*)malloc(sizeof(Elemtype));
//	e = (Elemtype*)malloc(sizeof(Elemtype));
//	popsqstack(L, p);
//	printf("p=%d\n", *p);
//	gettopstack(L, e);
//	printf("e=%d\n", *e);
//	destorysqstack(L);
//	return 0;
//}

//链栈的实践(链栈中可以不设置头结点)done
typedef struct linkstack {
	Elemtype data;
	struct linkstack* next;
}linkstack,*headstack;
//typedef struct stack {
//	linkstack* L;
//	int count;
//}stack;	
bool initlinkstack(linkstack* p)
{
	p = (linkstack*)malloc(sizeof(linkstack));
	p->next = NULL;
	return true;
}
bool pushlinkstack(linkstack* p, Elemtype e)
{
	linkstack* newnode = (linkstack*)malloc(sizeof(linkstack));
	newnode->data = e;
	newnode->next = p->next;
	p->next = newnode;
	return true;
}
bool poplinkstack(linkstack* p, Elemtype* e)
{
	if (!p->next)
	{
		return false;
	}
	linkstack* s = p->next;
	*e = s->data;
	p->next = s->next;
	free(s);
	s = NULL;
	return true;
}
bool gettoplinkstack(linkstack* p, Elemtype* e)
{
	if (!p->next)
	{
		return false;
	}
	*e = p->next->data;
	printf("%d", *e);
	return true;
}
//测试代码：

//int main()
//{
//	linkstack* p = (linkstack*)malloc(sizeof(linkstack));
//	initlinkstack(p);
//	for (int i = 0;i < 16;i++)
//	{
//		pushlinkstack(p, i);
//	}
//	Elemtype* e = (Elemtype*)malloc(sizeof(Elemtype));
//	gettoplinkstack(p, e);
//	Elemtype* m = (Elemtype*)malloc(sizeof(Elemtype));
//	poplinkstack(p, e);
//	gettoplinkstack(p, m);
//	return 0;
//}

//栈的应用：
//数制转换
#if 0
void conversion ()
{
	InitStack(S);
	scanf("%d", N);
	while (N) 
	{
		Push(S, N % 8);//余数进栈
		N = N / 8;            //保留商数
	}
	while (!StackEmpty(S)) 
	{
		Pop(S, e);  //从高位到低位弹出
		printf("%d", e);
	}
} // conversion
#endif
//表达式求值
#if 0
void exp_reduced （）
{
	Init_SeqStack(OPTR)； 
	Push_SeqStack(OPTR，’#’)； 
	Init_SeqStack(OPND)；
	read(w)；
	while !(w == ‘#’ && Get _SeqStack(OPTR) == ‘#’)
	{
		if (w ！ = 运算符)
			Push_SeqStack(OPND，w);
		else
			switch (ch = precede(Get _SeqStack(OPTR)，w))
			{
				case ch = = ’＜’：
				{
					Push_SeqStack(OPTR，w)；
					read(w)；
					break;
				}
					case ch = = ’＝’：
				{
					x = Pop_SeqStack(OPTR)；
					read(w)；
					break;
				}
					case ch = = ’＞’：
				{
					theta = Pop_SeqStack(OPTR)；
					b = Pop_SeqStack(OPND)；
					a = Pop_SeqStack(OPND)；
					Push_SeqStack(OPND，operate(a ，theta，b));
					break;
				}
			}
	}	
	Return (Get _SeqStack(OPND));
}
#endif
//迷宫求解
#if 0
int  path(int maze[m][n], item move[8])
{
	SeqStack  s; 
	datetype  temp; 
	int  x, y, d, i, j;
	temp.x = 1;  
	temp.y = 1; 
	temp.d = -1;
	Push_SeqStack(s，temp);
	while (!Empty_SeqStack(s))
	{
		Pop_SeqStack(s, ＆temp);
		x = temp.x; 
		y = temp.y;  
		d = temp.d + 1;
		while (d < 8)
		{
			i = x + move[d].x;   
			j = y + move[d].y;
			if (maze[i][j] = = 0)
			{
				temp = { x, y, d };
				Push_SeqStack(s, temp);
				x = i; 
				y = j; 
				maze[x][y] = -1;
				if (x == m && y = = n)  
					return 1; /*迷宫有路*/
				else 
					d = 0;
			}
			else  
				d++;
		} /*while (d<8)*/
	}  /*while */
	return  0;/*迷宫无路*/
}
#endif

//顺序队列done
#define MAXSIZE 100
typedef struct sqqueue{
	Elemtype data[MAXSIZE];
	int front;
	int roar;
}sqqueue;
bool initsqqueue(sqqueue* L)
{
	L->front = L->roar = 0;
	return true;
}
bool insqqueue(sqqueue* L, Elemtype e)
{
	if (L->roar == MAXSIZE)
	{
		return false;
	}
	L->data[L->roar] = e;
	L->roar++;
	return true;
}
bool outsqqueue(sqqueue* L, Elemtype* e)
{
	if (L->front==L->roar)
	{
		return false;
	}
	L->front++;
	return true;
}
bool gethead(sqqueue* L, Elemtype* e)
{
	if (L->front == L->roar)
	{
		return false;
	}
	*e = L->data[L->front];
	return true;
}
//测试代码
 
//int main()
//{
//	sqqueue* L = (sqqueue*)malloc(sizeof(sqqueue));
//	initsqqueue(L);
//	for (int i = 0;i < 16;i++)
//	{
//		insqqueue(L, i);
//	}
//	Elemtype* e = (Elemtype*)malloc(sizeof(Elemtype));
//	gethead(L, e);
//	printf("%d\n", *e);
//	outsqqueue(L, e);
//	Elemtype* m = (Elemtype*)malloc(sizeof(Elemtype));
//	gethead(L, m);
//	printf("%d\n", *m);
//	return 0;
//}

//循环队列done
//plan A：空出一个存储空间
//循环队列
//plan A：空出一个存储空间
typedef struct circlequeue {
	Elemtype data[MAXSIZE];
	int front;
	int roar;
}circlequeue;
bool initcirclequeueA(circlequeue* L)
{
	L->front = L->roar = 0;
	return true;
}
bool pushcirclequeueA(circlequeue* L, Elemtype e)
{
	if ((L->roar + 1) % MAXSIZE == L->front)
	{
		return false;
	}//判断队满的方法
	L->roar = (L->roar + 1) % MAXSIZE;
	L->data[L->roar] = e;
	return true;
}
bool outcirclequeueA(circlequeue* L, Elemtype* e)
{
	if (L->roar == L->front)
	{
		return false;
	}//判断队空的方法
	*e = L->data[(L->front + 1) % MAXSIZE];
	L->front = (L->front + 1) % MAXSIZE;
	return true;
}
int numberqueueA(circlequeue* L)
{
	return (L->front - L->roar + MAXSIZE) % MAXSIZE;
}
bool getheadA(circlequeue* L, Elemtype* e)
{
	if (!((L->front - L->roar + MAXSIZE) % MAXSIZE))
	{
		return false;
	}
	*e = L->data[(L->front + 1) % MAXSIZE];
	return true;
}
//测试代码
 
//int main()
//{
//	circlequeue* L = (circlequeue*)malloc(sizeof(circlequeue));
//	initcirclequeueA(L);
//	for (int i = 0;i < 16;i++)
//	{
//		pushcirclequeueA(L, i);
//	}
//	Elemtype* e = (Elemtype*)malloc(sizeof(Elemtype));
//	getheadA(L, e);
//	printf("%d\n", *e);
//	outcirclequeueA(L, e);
//	Elemtype* m = (Elemtype*)malloc(sizeof(Elemtype));
//	getheadA(L, m);
//	printf("%d\n", *m);
//	return 0;
//}

//plan B：加入计数器count
typedef struct circlequeueB {
	Elemtype data[MAXSIZE];
	int front;
	int rear;
	int count;
}circlequeueB;
bool initcirclequeueB(circlequeueB* L)
{
	L->front = L->rear = 0;
	L->count = 0;
	return true;
}
bool pushcirclequeueB(circlequeueB* L, Elemtype e)
{
	if (MAXSIZE == L->count)
	{
		return false;
	}//判断队满的方法
	L->data[L->rear] = e;
	L->rear = (L->rear + 1) % MAXSIZE;
	L->count++;
	return true;
}
bool outcirclequeueB(circlequeueB* L, Elemtype* e)
{
	if (!L->count)
	{
		return false;
	}
	*e = L->data[L->front];
	L->front = (L->front + 1) % MAXSIZE;
	L->count++;
	return true;
}
int numberqueueB(circlequeueB* L)
{
	return L->count;
}
bool getheadB(circlequeueB* L, Elemtype* e)
{
	if (!L->count)
	{
		return false;
	}
	*e = L->data[L->front];
	return true;
}
//测试代码：
 
//int main()
//{
//	circlequeueB* L = (circlequeueB*)malloc(sizeof(circlequeueB));
//	initcirclequeueB(L);
//	for (int i = 0;i < 16;i++)
//	{
//		pushcirclequeueB(L, i);
//	}
//	Elemtype* e = (Elemtype*)malloc(sizeof(Elemtype));
//	getheadB(L, e);
//	printf("%d\n", *e);
//	outcirclequeueB(L, e);
//	Elemtype* m = (Elemtype*)malloc(sizeof(Elemtype));
//	getheadB(L, m);
//	printf("%d\n", *m);
//	return 0;
//}

//plan C；设立标志位
typedef struct circlequeueC {
	Elemtype data[MAXSIZE];
	int front;
	int roar;
	int flag;
}circlequeueC;
bool initcirclequeueC(circlequeueC* L)
{
	L->front = L->roar = -1;
	L->flag = false;
	return true;
}
bool pushcirclequeueC(circlequeueC* L, Elemtype e)
{
	if (L->roar == L->front && L->flag)
	{
		return false;
	}//判断队列满的方法
	L->roar = (L->roar + 1) % MAXSIZE;
	L->data[L->roar] = e;
	L->flag = true;
	return true;
}
bool outcirclequeueC(circlequeueC* L, Elemtype* e)
{
	if (L->roar == L->front && !L->flag)
	{
		return false;
	}//判断队列空的方法
	*e = L->data[L->front];
	L->front = (L->front + 1) % MAXSIZE;
	L->flag = false;
	return true;
}
int numberqueueC(circlequeueC* L)
{
	return (L->front - L->roar + MAXSIZE) % MAXSIZE;
}
bool getheadC(circlequeueC* L, Elemtype* e)
{
	if (L->roar == L->front && !L->flag)
	{
		return false;
	}
	*e = L->data[L->front + 1];
	return true;
}
//测试代码

//int main()
//{
//	circlequeueC* L = (circlequeueC*)malloc(sizeof(circlequeueC));
//	initcirclequeueC(L);
//	for (int i = 0;i < 16;i++)
//	{
//		pushcirclequeueC(L, i);
//	}
//	Elemtype* e = (Elemtype*)malloc(sizeof(Elemtype));
//	getheadC(L, e);
//	printf("%d\n", *e);	
//	Elemtype* m = (Elemtype*)malloc(sizeof(Elemtype));
//	outcirclequeueC(L, e);
//	getheadC(L, m);
//	printf("%d\n", *m);
//	return 0;
//}

//链队列done
typedef struct Lnode {
	Elemtype data;
	struct Lnode* next;
}Lnode, * linknode;
typedef struct linkqueue {
	linknode roar;
	linknode front;
}linkqueue;
bool initlinkqueue(linkqueue* L)
{
	linknode temp = (linknode)malloc(sizeof(Lnode));
	temp->next = NULL;
	L->front = temp;
	L->roar = temp;
	return true;
}
bool pushlinkqueue(linkqueue* L, Elemtype e)
{
	linknode newnode = (linknode)malloc(sizeof(Lnode));
	newnode->data = e;
	newnode->next = NULL;
	L->roar->next = newnode;
	L->roar = newnode;
	return true;
}
bool outlinkqueue(linkqueue* L, Elemtype* e)
{
	if (L->front == L->roar)
	{
		return false;
	}
	if (L->front->next == L->roar)
	{
		L->front = NULL;
		L->front = L->roar;
	}
	else
	{
		L->front->next = L->front->next->next;
	}
	*e = L->front->next->data;
	return true;
}
int numberlinlqueue(linkqueue* L)
{
	int count = 0;
	linknode p = L->front;
	while (L->front == L->roar)
	{
		p = p->next;
		count++;
	}
	return count;
}
bool gethead(linkqueue* L, Elemtype* e)
{
	if (L->front == L->roar)
	{
		return false;
	}
	*e = L->front->next->data;
	return true;
}
//测试代码：

//int main()
//{
//	linkqueue* L = (linkqueue*)malloc(sizeof(linkqueue));
//	initlinkqueue(L);
//	for (int i = 0;i < 16;i++)
//	{
//		pushlinkqueue(L, i);
//	}
//	Elemtype* e = (Elemtype*)malloc(sizeof(Elemtype));
//	Elemtype* m = (Elemtype*)malloc(sizeof(Elemtype));
//	gethead(L, e);
//	printf("%d\n", *e);
//	outlinkqueue(L, e);
//	gethead(L, m);
//	printf("%d\n", *m);
//	return 0;
//}

//排序算法实践done

//插入排序
Elemtype* insertsort(Elemtype* r, int size)
{
	for (int j = 1;j < size;j++)
	{
		for (int i = j;i > 0;i--)
		{
			if (*(r + i) < *(r + i - 1))
			{
				*(r + i) = *(r + i - 1) ^ *(r + i);
				*(r + i - 1) = *(r + i - 1) ^ *(r + i);
				*(r + i) = *(r + i - 1) ^ *(r + i);
			}
			else
			{
				break;
			}
		}
	}
	return r;
}
//折半插入排序
Elemtype* midinsertsort(Elemtype* r, int size)
{
	for (int i = 1;i < size;i++)
	{
		int front = 0;
		int rear = i - 1;
		int starear = i;
		int mid = (front + rear) / 2;
		if (*(r + i) > *(r + i - 1))
		{
			;
		}
		else
		{
			if (*r > *(r + i))
			{
				rear = 0;
			}
			else
			{
				while (front + 1 != rear)
				{
					if (*(r + i) < *(r + mid))
					{
						rear = mid - 1;
						mid = (front + rear) / 2;
					}
					else
					{
						front = mid + 1;
						mid = (front + rear) / 2;
					}
				}
			}
			Elemtype p = r[i];
			while (starear > rear)
			{
				*(r + starear) = *(r + starear - 1);
				starear--;
			}
			*(r + rear) = p;
		}
	}
	return r;
}
//希尔排序
Elemtype* shellsort(Elemtype* r, int size)
{
	for (int gap = size / 2;gap > 0;gap /= 2)
	{
		for (int j = gap;j < size;j++)
		{
			for (int i = j;i > 0;i--)
			{
				if (*(r + i) < *(r + i - gap))
				{
					*(r + i) = *(r + i - gap) ^ *(r + i);
					*(r + i - gap) = *(r + i - gap) ^ *(r + i);
					*(r + i) = *(r + i - gap) ^ *(r + i);
				}
				else
				{
					break;
				}
			}
		}
	}
	return r;
}
//冒泡排序
Elemtype* bubblesort(Elemtype* r, int size)
{
	for (int j = size;j > 0;j--)
	{
		for (int i = 1;i < j;i++)
		{
			if (*(r + i - 1) > *(r + i))
			{
				*(r + i - 1) = *(r + i) ^ *(r + i - 1);
				*(r + i) = *(r + i) ^ *(r + i - 1);
				*(r + i - 1) = *(r + i) ^ *(r + i - 1);
			}
		}
	}
	return r;
}
//冒泡排序改进
Elemtype* newbubblesort(Elemtype* r, int size)
{
	int p = size;
	while (p != 1)
	{
		int rear = 0;
		for (int i = 1;i < p;i++)
		{
			if (*(r + i - 1) > *(r + i))
			{
				*(r + i - 1) = *(r + i) ^ *(r + i - 1);
				*(r + i) = *(r + i) ^ *(r + i - 1);
				*(r + i - 1) = *(r + i) ^ *(r + i - 1);
				rear = i;
			}
		}
		p = rear;
	}
	return r;
}
//快速排序!!!
bool swap(Elemtype p, Elemtype q)
{
	Elemtype tmp;
	tmp = p;
	p = q;
	q = tmp;
	return true;
}
int partition(int arr[], int low, int high)
{
	int pivot = arr[low];
	while (low < high)
	{
		while (arr[high] >= pivot && low < high)
			high--;
		arr[low] = arr[high];
		while (arr[low] <= pivot && low < high)
			low++;
		arr[high] = arr[low];
	}
	//int i = low;
	//for (int j = low; j < high; j++)
	//{
	//    // 比pivot小的，全部换到前面去
	//    if (arr[j] < pivot)
	//        swap(arr[j], arr[i++]);
	//}
	//// 此时，i指向的元素一定大于等于pivot
	//swap(arr[high], arr[i]);
	arr[low] = pivot;
	return low;
}
void qsort(int* arr, int low, int high)
{
	if (low < high)
	{
		int mid = partition(arr, low, high);
		qsort(arr, low, mid - 1);
		qsort(arr, mid + 1, high);
	}
}
//int main()
//{
//	int arr[] = { 9,8,7,6,5,4,3,2,1 };
//	int len = sizeof(arr) / sizeof(arr[0]);
//	for (int i = 0;i < len;i++)
//	{
//		printf("%d->", arr[i]);
//	}
//	puts("end\n");
//	qsort(arr, 0, len - 1);
//	for (int i = 0;i < len;i++)
//	{
//		printf("%d->", arr[i]);
//	}
//	puts("end\n");
//	return 0;
//}
//选择排序
Elemtype* choicesort(Elemtype* r, int front, int rear)
{
	while (front < rear)
	{
		int key = front;
		int j = front;
		while (j < rear)
		{
			j++;
			if (r[key] > r[j])
				key = j;
		}
		if (r[key] < r[front])
		{
			r[key] = r[key] ^ r[front];
			r[front] = r[key] ^ r[front];
			r[key] = r[key] ^ r[front];
		}
		front++;
		choicesort(r, front, rear);
	}
	return r;
}
//2-归并排序
void merge(Elemtype* r, Elemtype* p, int front1, int front2, int rear2)
{
	int p1 = front1, p2 = front2, p3 = p1, rear1 = p2 - 1;
	while (p1 <= rear1 && p2 <= rear2)
	{
		if (r[p1] < r[p2])
			p[p3++] = r[p1++];
		else
			p[p3++] = r[p2++];
	}
	while (p1 <= rear1)
	{
		p[p3++] = r[p1++];
	}
	while (p2 <= rear2)
	{
		p[p3++] = r[p2++];
	}
	for (int i = front1;i <= rear2;i++)
	{
		r[i] = p[i];
	}
}
void merge_sort_divide(Elemtype* r, Elemtype* p, int start, int end)
{
	if (start < end)
	{
		int mid = (start + end) / 2;
		merge_sort_divide(r, p, start, mid);
		merge_sort_divide(r, p, mid + 1, end);
		merge(r, p, start, mid + 1, end);
	}
}
void merge_sort(Elemtype* r, int size)
{
	Elemtype* temp = (Elemtype*)malloc(sizeof(Elemtype) * size);
	merge_sort_divide(r, temp, 0, size - 1);
	free(temp);
}
//测试代码
//int main()
//{
//	int r[] = { 9,8,7,6,5,4,3,2,1 };
//	int size = sizeof(r) / sizeof(r[0]);
//	Elemtype* p = insertsort(r, size);
//	for (int i = 0;i < size;i++)
//	{
//		printf("%d-->", *(p + i));
//	}
//	printf("\n");
//	return 0;
//}

//Now we come into the end!!