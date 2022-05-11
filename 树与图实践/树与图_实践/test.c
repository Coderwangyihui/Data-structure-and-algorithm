#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>
#define bool char
#define true 1
#define false 0
typedef int Elemtype;
//递归与分治
//Hanoi汉诺塔问题

//大整数乘法计算问题O(nlog2n)

//主方法
//------------------------------------------------------------------------------------------------------------

//树的实践
//满二叉树、完全二叉树使用顺序存储结构.一般二叉树使用链式存储结构

//二叉链表
typedef struct Bitreenode {
	Elemtype data;
	struct Bitreenode* left;
	struct Bitreenode* right;
}Bitreenode, * Bitree;
//三叉链表
typedef struct rdtreenode {
	Elemtype data;
	struct Bitreenode* left;
	struct Bitreenode* right;
	struct Bitreenode* parent;
}rdtreenode, * rdtree;

//二叉树
//初始化
bool initBitree(Bitree L)
{
	L->data = 0;
	L->left = L->right = NULL;
	return true;
}
//先序遍历
bool firstprint(Bitree L)
{
	if (!L)
	{
		return false;
	}
	printf("%d", L->data);
	firstprint(L->left);
	firstprint(L->right);
	return true;
}
//中序遍历
bool midrprint(Bitree L)
{
	if (!L)
	{
		return false;
	}
	midprint(L->left);
	printf("%d", L->data);
	midprint(L->right);
	return true;
}
//后序遍历
bool lastprint(Bitree L)
{
	if (!L)
	{
		return false;
	}
	lastprint(L->left);
	lastprint(L->right);
	printf("%d", L->data);
	return true;
}
//先序中序构造二叉树
bool creatBitree(Elemtype preord[], Elemtype midord[], int n, Bitree L)
{
	if (n <= 0)
	{
		L = NULL;
		return false;
	}
	PreInord(preord, midord, 1, n, 1, n, L);
	return true;
}
bool PreInord(Elemtype preord[], Elemtype midord[], int i, int j, int k, int h, Bitree L)
{
	int m = k;
	L->data = preord[i];
	while (preord[i] != midord[m]) {
		m++;
	}
	if (m == k)
	{
		L->left = NULL;
	}
	else
	{
		PreInord(preord, midord, i + 1, i + m - k, k, m - 1, L->left);
	}
	if (m == h)
	{
		L->right = NULL;
	}
	else
	{
		PreInord(preord, midord, i + m - k + 1, j, m + 1, h, L->right);
	}
	return true;
}
//层次遍历
typedef struct linknode {
	Elemtype data;
	struct linknode* next;
}*linknode;
typedef struct linkqueue {
	linknode rear;
	linknode front;
}linkqueue;
bool initlinkqueue(linkqueue* L)
{
	L->rear->next = L->front->next = NULL;
	return true;
}
bool pushlinkqueue(linkqueue* L, Elemtype e)
{
	linknode newnode = (linknode*)malloc(sizeof(linknode));
	linknode p = L->front;
	while (p->next)
	{
		p = p->next;
	}
	newnode->data = e;
	newnode->next = NULL;
	p->next = newnode;
	return true;
}
bool ADD(linkqueue* s,Bitree p)
{
	pushlinkqueue(s, p->data);
	ADD(s,p->left);
	ADD(s,p->right);
	
}
bool levelprint(Bitree L)//undone
{
	linkqueue* s;
	initlinkqueue(s);
	Bitree p = L;
	if (!p)
	{
		return false;
	}
	ADD(s,p);
	ADD(s,p->left);
	ADD(s,p->right);
	
	printlist(s);
	return true;
}
//二叉树叶子计数
int leafcount(Bitree L)
{
	static int count = 0;
	if (L->right == NULL && L->left == NULL)
	{
		count++;
	}
	return firstprint(L->left) + firstprint(L->right);
}
//二叉树深度
int depthBitree(Bitree L)
{
	if (L = NULL)
	{
		return 0;
	}
	if (L->left == NULL && L->right == NULL)
	{
		return 1;
	}
	return 1 + (depthBitree(L->left) > depthBitree(L->right)) ? depthBitree(L->left): depthBitree(L->right);
}

//二叉排序树

//按值查找二叉排序树(ASL)
//Plan A:
Bitree searchsortBitreeA(Bitree L, Elemtype key)
{
	Bitree p = L;
	while (p)
	{
		if (key == p->data)
		{
			return p;
		}
		if (key > p->data)
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}
	}
	return NULL;
}
//Plan B;
Bitree searchsortBitreeB(Bitree L, Elemtype key)//p=L
{
	Bitree p = L;
	if (!p||key == p->data)
	{
		return p;
	}
	if (key > p->data)
	{
		return searchsortBitree(key, p->right);
	}
	else
	{
		return searchsortBitree(key, p->left);
	}
}
//插入结点
bool insertsortBitree(Bitree L, Elemtype key)
{
	Bitree p = L;
	if (searchsortBitreeB(L, key)) 
	{
		return false;
	}
	Bitreenode* s = (Bitreenode*)malloc(sizeof(Bitreenode));
	s->data = key;
	s->left = NULL;
	s->right = NULL;
	if (!p)
	{
		L = s;
	}
	while(1)
	{
		if (!p->left && !p->right)
		{
			break;
		}
		if (key > p->data)
		{
			p = p->right;
		}
		else
		{
			p = p->left;
		}
	}
	if (key > p->data)
	{
		p->right = s;
	}
	else 
	{
		p->left = s;
	}
}
//删除结点
bool delectsortBitree(Bitree L, Elemtype key)
{
	if (!searchsortBitreeA(key,L)) 
	{
		return false;
	}
	Bitree p = searchsortBitreeA(key, L);
	if (!p->left  && !p->right)
	{
		p = NULL;
	}
	if (p->left && !p->right) 
	{
		Bitree q = p->left;
		p = p->left;
		free(q);
		q = NULL;
	}
	if (!p->left && p->right)
	{
		Bitree q = p->right;
		p = p->right;
		free(q);
		q = NULL;
	}
	if (p->left && p->right)
	{
		//求key的前驱或者后继  这里给出求后继的算法（前驱同理）
		Bitree pt = p->right;
		while (pt->left)
		{
			pt = pt->left;
		}
		p->data = pt->data;
		Bitree ptt = pt->right;
		pt = pt->right;
		free(ptt);
		ptt = NULL;
	}
}
//堆排序
bool heapsortsqlist(Elemtype r[],int first,int last)//small top
{
	
}
//树的表示

//树的双亲表示法(顺序存储结构)
#define MAX 100
#define MAXSIZE 1000
typedef struct treenode{
	Elemtype data;
	int parent;
}treenodeP;
typedef struct treeparent{
	treenodeP r[MAX];
	int start, end;
}treeparent;
//树的孩子表示法(链式存储结构)
typedef struct treelinklist {
	int num;//该结点在表头数组的下标
	struct treelinklist* next;
}treelinklist;
typedef struct treenode {
	Elemtype data;
	struct treelinklist* firstnext;
}treenodeC, * Tlist;//表头信息存储
typedef struct treechild {
	treenodeC r[MAXSIZE];
	int start, end;
}treechild;
//双亲孩子表示法
typedef struct treelinklist {
	int num;//该结点在表头数组的下标
	struct treelinklist* next;
}treelinklist;
typedef struct treenode {
	Elemtype data;
	int parent;
	struct treelinklist* firstnext;
}treenodeC, * Tlist;//表头信息存储
typedef struct treechild {
	treenodeC r[MAXSIZE];
	int start, end;
}treechild;

//森林的孩子兄弟表示法
typedef struct treechildbro {
	Elemtype data;
	struct treechildbro *firstchild, *nextbro;
}treechildbro;

//图的基本实践
//图的存储

//邻接矩阵
//无权图：0-1邻接矩阵
//有权图：带权邻接矩阵

//邻接表（无向图、有向图）
typedef struct node {
	Elemtype data;
	struct node* next;
}node;
typedef struct graphlist{
	Elemtype data;
	node* firstnode;
}graphlist;
//有向图的逆邻接表
//十字链表:有向图（结合邻接表和逆邻接表）
typedef struct orthnode {
	Elemtype data;
	edgenode* head, * tail;
}orthnode;
typedef struct edgenode{
	orthnode *front, * rear;
	edgenode * head, * tail;
}edgenode;
//邻接多重表:无向图
typedef struct listnode{
	int flag;
	Elemtype data;
	edgenodelist* firstdege;
}listnode;
typedef struct edgenodelist{
	struct edgenodelist *edge1, *edge2;
	listnode* node1, * node2;
}edgenodelist;
//图的遍历（伪代码要求）
//深度优先遍历
#if 0 
void dfs(int v0)
{
	visited[v0] = 1;/*访问标志置为1，表示已被访问*/
	w = firstadj(g, v0); /* w是v0的第一个邻接点 */
	while (w != 0)
	{
		if (visited[w] == 0) dfs(w); /*顶点未被访问，则递归的进行深度遍历 */
		w = nextadj(g, v0, w) /*顶点已访问，则取顶点v0在w后面的下一个邻接点 */
	}
}
void travergraph(g)
{
	for (i = 1;i <= n;i++)  
		visited[i] = 0;   /* 标志数组初始化 */
	for (i = 1;i <= n;i++)
	{
		if (visited[i] == 0)
			dfs(i);    /* 深度优先遍历时调用dfs(i)  */
	}
		
}
#endif
//广度优先遍历(层次遍历)
#if 0
Void bfs(Graph g, int v0)/* 从v0出发广度优先遍历图g  */
{        
	visited[v0] = 1;
	Enqueue(Q, v0);
	While(!Empty(Q)) {
		v = Dlqueue(Q);            /* 取队头元素v   */
		w = Firstadj(g, v);         /* 求v的第一个邻接点 */
		while (w != 0) {
			if (visited[w] == 0) {
				visited[w] = 1;
				Enqueue(Q, w);
			}
			w = Nextadj(g, v, w);        /* 求下一个邻接点   */
		}
	}
}
#endif
//图的应用
//一、最小生成树
//Prim算法(选结点)
#if 0
void minispantree_PRIM(int gn[][max], int vtxnum)
{
	int v, i, j, k;
	float min;
	for (v = 1;v < vtxnum;v++)
	{
		Closedge[v].vex = 0;
		Closedge[v].lowcost = gn[0][v];
	}/* 从序号为0的顶点出发生成最小生成树  */
	Closedge[0].lowcost = 0; 
	Closedge[0].vex = 0;
	for (i = 1;i < vtxnum;i++)
	{
		k = minimum(closedge);
		printf(“<% i, % i>”, closedge[k].vex, k);         /* 输出生成树的边 */
		closedge[k].lowcost = 0;                  /*  顶点k并入U */
		for (v = 1;v < vtxnum;v++)
		{
			if (gn[k][v] < closedge[v].lowcost)
			{
				Closedge[v].lowcost = gn[k][v];
				Closedge[v].vex = k;
			}
		}
	}
}
int minimum(closedge)
{
	int min, h, k;
	min = ∞; h = 1;
	for (k = 1;k < vtxnum;k++)
	{
		if (closedge[k].lowcost != 0 && closedge[k].lowcost < min)
		{
			min = closedge[k].lowcost;  h = k;
		}
		return h; //返回边权值最小的结点k
	}
}
#endif
//kruskal算法(选边)
//
//二、拓扑排序(有向图线性化、检查有向图中是否存在回路)（AOV网）顶点活动
#if 0
Void findIndegree(algraph g, int* indegree)      /* 求出图中所有顶点的入度  */
{
	int  i;
	arcnode* p;
	for (i = 0;i < g.vexnum;i++)
		indegree[i] = 0;
	for (i = 0;i < g.vexnum;i++)
	{
		p = g.vertices[i].firstarc;
		while (p)
		{
			++indegree[p->adjvex];
			p = p->nextarc;
		}
	}
}
#endif
//三、关键路径（AOE网）边活动（掌握算法）
//  最早发生、最迟发生时间
// 
//四、最短路径
//Dijkstra算法
#if 0
void Dijkstra(Mgraph Gn, int v0, int path[], int dist[]) /*求有向网Gn的v0顶点到其余顶点v的最短路径*/
{
	int s[VEX_NUM];
	/* s标记已找到最短路径的顶点,初值只包括v0，即s[0]=1*/
	/* dist记录源点到其他各顶点当前的最短距离，其初值为：dist[i] = G.arcs[0][i] i=1，2，…，n-1*/
	for (int v = 0; v < VEX_NUM; v++)
	{
		s[v] = 0;
		dist[v] = Gn.arcs[v0][v];
		if (dist[v] < MAXINT)
			path[v] = v0; //如果可达，v的前驱节点为v0
		else
			path[v] = -1; //否则为-1
	}
	dist[v0] = 0;
	s[v0] = 1; /*初始时源点v0∈S集*/
    /* 循环求v0到某个顶点v的最短路径，并将v加入S集*/
    /*算法执行时从S以外的顶点集合（V -S）中选出一个顶点w，使dist[w]的值最小。 然后将w加入集合S中，即s[w]=1；同时调整集合（V-S）中的各个顶点的距离值：  从原来的dist[j]和dist[w]+cost[w][j]中选择较小的值作为新的dist[j]。重复上述过程， 直到S中包含图中所有顶点，或再也没有可加入到S中的顶点为止。*/
	for (int i = 1; i < VEX_NUM - 1; i++) 
	{
		int min = MAXINT;
		v = -1;
		for (int w = 0; w < VEX_NUM; w++) /* 找出最小的dist[w] */
			if (!s[w] && dist[w] < min) { /*顶点w不属于S,且离v0更近*/
				v = w;
				min = dist[w];
			}
		if (v == -1)  break;     /* 已无顶点可加入S中，退出外层for  */
		s[v] = 1; /*顶点v并入S*/
	 /* 调整集合V-S中的各个顶点的距离值 */
		for (int j = 0; j < VEX_NUM; j++) /*更新当前最短路径及距离*/
			if (!s[j] && (min + Gn.arcs[v][j] < dist[j])) {/*dist[j]是v0到顶点j当前的最短路径*/
				dist[j] = min + Gn.arcs[v][j];/*v0经v到顶点j的距离= min + Gn.arcs[v][j];*/
				path[j] = v;
			}/*if*/
	}/*for*/
}
#endif
//Floyd算法
#if 0
void Floyd(int cost[][], Mgraph Gn, int path[][])//弗洛伊德(Floyd)算法(P166)
{
	int i, j, k;
	for (i = 0;i < n;i++)
	{
		for (j = 0;j < n;j++)
		{
			Gn.arcs[i][j] = cost[i][j];
			if (i == j) 
				path[i][j] = -1;
			else if (cost[i][j] < maxint)  
				path[i][j] = i;
			else  
				path[i][j] = -1;
		}
	}
	for (k = 0;k < n;k++)
	{
		for (i = 0;i < n;i++)
		{
			for (j = 0;j < n;j++)
			{
				if (Gn.arcs[i][j] > (Gn.arcs[i][k] + Gn.arcs[k][j]))
				{
					Gn.arcs[i][j] = Gn.arcs[i][k] + Gn.arcs[k][j];
					path[i][j] = path[k][j];
				}
			}
		}
	}
}
#endif
//贪心算法	

//活动安排问题

//---------------------------------------------------------------------------------------------------------------
//动态规划

//权重化的活动安排问题

//多个矩阵连乘模块设计

//0-1背包问题

//最长公共子序列问题

