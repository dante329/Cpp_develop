////除留余数法哈希函数，线性探测法处理哈希冲突 
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int N = 23, INF = 0x3f3f3f3f; //N取决于数据量的大小，假设数据量为n，在使用除留余数法时，模数的下选择一般是取大于2n的最小质数，这里线性探测法开辟的数组大小也用N表示 
//
//int h[N]; 
//
//void init()
//{
//	memset(h,0x3f,sizeof h);
//}
//
////线性探测法处理哈希冲突，找到正确的映射关系 
//int fun(int x)
//{
//	int id = ((x % N) + x) % N; //模加模，取模后加x处理负数取模为负数的情况，对结果重新取模是防止正数取模后加x过大 
//	while(h[id] != INF && h[id] != x)
//	{
//		id++;
//		if(id == N) id = 0; //走到尾部从头开始 
//	}
//	return id;
//}
//
//void insert(int x)
//{
//	h[fun(x)] = x;
//}
//
//bool find(int x)
//{
//	return h[fun(x)] == x;
//}
//
//int main(int argc, char** argv) 
//{
//	init();
//	int n; cin >> n;
//	while(n--)
//	{
//		int op,x;
//		cin >> op >> x;
//		if(op == 1)
//		{
//			insert(x);
//		}
//		else
//		{
//			if(find(x)) cout << "yes" << endl;
//			else cout << "no" << endl;
//		}
//		
//	}
//	
//	return 0;
//}


//链地址法处理哈希冲突

#include<iostream>

using namespace std;

const int N = 23;

int h[N];

int e[N],ne[N],id;

//哈希函数 
int fun(int x)
{
	return (x % N + x) % N;
}

//插入函数 
void insert(int x)
{
	int idx = fun(x);
	
	h[idx] = ++id;
	e[id] = x;
	ne[id] = h[idx];
	h[idx] = id;
}

bool find(int x)
{
	int idx = fun(x);
	for(int i = h[idx];i;i = ne[i])
	{
		if(e[i] == x) return true;
	}
	return false;
}

int main()
{
	int n; cin >> n;
	while(n--)
	{
		int op,x;
		cin >> op >> x;
		if(op == 1)
		{
			insert(x);
		}
		else
		{
			if(find(x)) cout << "yes" << endl;
			else cout << "no" << endl;
		}
		
	}
	return 0;
 } 

