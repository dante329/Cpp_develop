#include<iostream>

using namespace std;

const int N = 1e5 +10;

int e[N],ne[N],pre[N],h,id; //静态模拟实现链表的时候一定要注意链表的 逻辑结构 和 物理结构 ，在链表逻辑结构上的第一个节点（非头节点）可能是在物理结构（数组）的最后一个位置上 

int mp[N];

//遍历打印 
void print()
{
	for(int i=ne[h];i;i=ne[i])
	{
		cout << e[i] << " ";
	}
	cout << endl;
} 

//头插 
void push_front(int x)
{
	//为新节点分配位置 
	id++;
	//将新节点的值放入链表
	e[id] = x; 
	//先修改新节点的前后指针
	pre[id] = h;
	ne[id] = ne[h];
	//再修改头节点下一个节点的前指针
	pre[ne[h]] = id;
	//最后再修改头节点的后指针，这一步一定要最后修改
	ne[h] = id;
	//更新mp数组 
	mp[x] = id;
}

//按值查找
int find(int x)
{
	return mp[x];	
} 

//在任意位置之后插入一个节点
void insert_back(int p,int x)
{
	id++;
	e[id] = x;
	mp[x] = id;
	
	pre[id] = p;
	ne[id] = ne[p];
	
	pre[ne[p]] = id;
	ne[p] = id;
}
 
//在任意位置之前插入一个节点
void insert_front(int p,int x)
{
	id++;
	e[id] = x;
	mp[x] = id;
	
	pre[id] = pre[p];
	ne[id] = p;
		
	ne[pre[p]] = id;
	pre[p] = id;
}
 
//删除任意位置的节点（头节点可以和中间节点合并，最后一个节点也可以合并，但是会改变头节点的pre） 
void erase(int p)
{
	if (p == 0) //如果删除头节点 
	{
		return;
	}
	else if (ne[p] == 0) //删除最后一个节点 
	{
		ne[pre[p]] = ne[p];
		mp[e[p]] = 0;
	}
	else //删除中间节点 
	{
		ne[pre[p]] = ne[p]; 
		mp[e[p]] = 0;
	}
 } 
 
int main()
{
	for(int i=1;i<=5;i++)
	{
		push_front(i);
		print();
	}
	
//	cout << find(1) << endl << find(4) << endl << find(9);

//	insert_back(2,22);
//	print();
//	insert_back(3,33);
//	print();

	insert_front(2,22);
	print();
	insert_front(3,33);
	print();
	return 0;
}
