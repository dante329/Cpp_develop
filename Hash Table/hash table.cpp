////������������ϣ����������̽�ⷨ�����ϣ��ͻ 
//#include <iostream>
//#include <cstring>
//using namespace std;
//
//const int N = 23, INF = 0x3f3f3f3f; //Nȡ�����������Ĵ�С������������Ϊn����ʹ�ó���������ʱ��ģ������ѡ��һ����ȡ����2n����С��������������̽�ⷨ���ٵ������СҲ��N��ʾ 
//
//int h[N]; 
//
//void init()
//{
//	memset(h,0x3f,sizeof h);
//}
//
////����̽�ⷨ�����ϣ��ͻ���ҵ���ȷ��ӳ���ϵ 
//int fun(int x)
//{
//	int id = ((x % N) + x) % N; //ģ��ģ��ȡģ���x������ȡģΪ������������Խ������ȡģ�Ƿ�ֹ����ȡģ���x���� 
//	while(h[id] != INF && h[id] != x)
//	{
//		id++;
//		if(id == N) id = 0; //�ߵ�β����ͷ��ʼ 
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


//����ַ�������ϣ��ͻ

#include<iostream>

using namespace std;

const int N = 23;

int h[N];

int e[N],ne[N],id;

//��ϣ���� 
int fun(int x)
{
	return (x % N + x) % N;
}

//���뺯�� 
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

