#include <iostream>
#include <vector>
using namespace std;

const int N = 1e5 + 10;

//创建全局变量 e(element)数组储存数据值，ne(next)数组模拟储存指针值 ，h记录头节点位置(h为0，是哨兵位)，id记录数组长度
//将两个数组看作是一起的
int e[N],ne[N],id,h;
 
//int mp[N];
vector<int> mp(N,-1);
 
void Push_Front(int n) //头插的第一个元素，尾插的最后一个元素，在ne数组中存储的指针都是0，因为这个模拟链表本质上是两个数组，初始化的值全部都是0 
{
	id++; //为新来的节点分配位置 ，id++之后id的值就变成了1，所以永远不可能在0位置上添加值，0位置为哨兵位 
	e[id] = n; //将数据n存储在e数组中 
	ne[id] = ne[h]; //先将原来哨兵位指向的节点位置赋值给新来的节点 
	ne[h] = id; //再将新节点的下标赋值给头节点储存，这个过程不能反过来，要不然会找不到原来头节点中存放的下一个节点 
	
	mp[n] = id; //在mp数组中存储值对应的下标，方便按值查询 
}

void print()
{
	for(int i = ne[h];i!=0;i=ne[i])
	{
		cout << e[i] << "-->";
	}
	cout << "NULL" << endl << endl;
}

// 按值查找 方式一 
// 通过链表的顺序按值查询，不能直接通过数组查找，因为有些值可能已经被在链表中被删除掉了 
//int find(int x)
//{
//	for(int i=ne[h];i;i=ne[i]) //遍历链表 
//	{
//		if(x == e[i])
//		{
//			return i;	//返回匹配的下标						
//		}
//	}
//	return -1;
//} 

//按值查找 方式二
int find(int x) //通过mp数组查找有局限性：1.存储的数据不能太大，无法存储10e9 ; 2.不能存储相同的数字 
{
	return mp[x];
}

//在任意位置插入元素 
void insert(int p,int x) //p为要插入的位置，x为要插入的值 
{
	id++;
	e[id] = x;
	ne[id] = ne[p];
	ne[p] = id; 
	
	mp[x] = id;
}

//删除任意位置之后的元素 
void erase(int p)
{
	//要判断这个位置是不是在最后一个节点，如果是在最后一个节点去直接执行会造成循环链表
	if(ne[p]) //不是最后一个节点，它的指针域一定不为0 
	{
		mp[e[ne[p]]] = 0; //先要将要删除的那个节点的值在mp中的值删除！！！ 
		ne[p] = ne[ne[p]]; //直接跳过中间的那个元素 
	} 
	 
 } 


int main()
{
	for(int i=1;i<=5;i++)
	{
		Push_Front(i);
		print();
	}
	
//	cout << find(1) << endl;
//	cout << find(5) << endl;
//	cout << find(7) << endl;
	
	erase(1);
	print();
	erase(4);
	print();
	
	return 0;
}
