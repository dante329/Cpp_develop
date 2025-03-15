//Ĭ�Ͻ������ 
#include <iostream>
using namespace std;

const int N = 1e6 + 10;
int n,heap[N]; //n������¼heap��ŵ���ЧԪ�ظ�����heap�����洢�ѵ����ݣ����ӹ�ϵ�ǿ���ʽ���������������ȫ�������� 

//���ϵ��� �������ӽڵ�Ҫ�����ڵ㻻��һ���ӽڵ�ĸ��ڵ�ֻ��һ��������ֱ�ӽ������ɣ� 
void up(int child) //����Ҫ�����Ľڵ���±꣨�±����Ψһ�ԣ���������ڵ��ֵ��ͬ�� 
{
	int parent = child / 2;
	while(parent >= 1 && heap[child] > heap[parent]) // ���������parent >= 1 ��������parent > 1 �� parent > 1ʱ������ýڵ������ģ���ôֻ�ܱ��������Ѷ����ӽڵ��λ�á�
	{
		swap(heap[child],heap[parent]);
		//���������Ǹ�Ԫ�ؾͲ����ˣ����Ѿ�����ȷ��λ�����ˣ���������Ҫ����child�ڵ� ��Ȼ�����ɹ�ʽ�ó�parent�ڵ� 
		child = parent;
		parent = child / 2;
	}
}

//���µ��� �����ڵ�Ҫ���ӽڵ㻻��һ�����ڵ�����������ӽڵ㣬��������Ҫ�ҳ������Ǹ��ӽڵ����Ƚϣ� 
//void down(int parent)
//{
//	int child = parent * 2; //��Ĭ��ָ����ڵ�
//	if(heap[child] < heap[child + 1]) child++;
//	while(parent < n && heap[parent] < heap[child]) //parent < n���ж���ȫû�б�Ҫ��child��parent���ж�child���� 
//	{
//		swap(heap[parent],heap[child]);
//		parent = child;
//		child = parent / 2;	
//	} 
//}

//void down(int parent)
//{
//	int child = parent * 2; //��Ĭ��ָ����ڵ� ˼����child��������parent�õ��ģ����ʱ����û�п��ܳ�����n�أ�����Ҫ���ж�child�Ƿ���� 
//	while(child <= n) //���Ӵ��ڲ�������   //child <= n������if�е�child + 1 <=n���Ժϲ��� child < n
//	{
//		if(child + 1 <=n && heap[child] < heap[child + 1]) child++;
//		while(heap[parent] < heap[child]) //���ﻹ��while������ѭ���ˣ�Ҫ�����������Ϊ����ѭ�������壬����Ҫ��if�ж� 
//		{
//			parent = child;
//			child = parent / 2; //©��̫�� 
//		}
//	}
//}

//void down(int parent)
//{
//	int child = parent * 2; //��Ĭ��ָ����ڵ� ˼����child��������parent�õ��ģ����ʱ����û�п��ܳ�����n�أ�����Ҫ���ж�child�Ƿ���� 
//	while(child <= n) //���Ӵ��ڲ�������   //child <= n������if�е�child + 1 <=n���Ժϲ��� child < n
//	{
//		if(child + 1 <=n && heap[child] < heap[child + 1]) child++;
//		if(heap[parent] >= heap[child]) return; //>=
//		swap(heap[parent],heap[child]);
//		parent = child;
//		child = parent * 2;
//		
//	}
//}

void down(int parent)
{
	int child = parent * 2; //��Ĭ��ָ����ڵ� ˼����child��������parent�õ��ģ����ʱ����û�п��ܳ�����n�أ�����Ҫ���ж�child�Ƿ���� 
	while(child < n) //���Ӵ��ڲ�������   //child <= n������if�е�child + 1 <=n���Ժϲ��� child < n
	{
		if(heap[child] < heap[child + 1]) child++;
		if(heap[parent] >= heap[child]) return; //heap[parent] >= heap[child]��heap[parent] > heap[child]����һ������������ȷ��
		swap(heap[parent],heap[child]);
		parent = child;
		child = parent * 2;
		
	}
}

void push(int x)
{
	heap[++n] = x; //��տ�ʼn=0�������һ��Ԫ�ص�ʱ��++n������1��λ�ô��룬0��λ��û���κ�Ԫ�� 
	up(n);
}

void pop()
{
	swap(heap[1],heap[n]);
	n--;
	down(1);
}

int size()
{
	return n;
}

int top() //���topʵ��������bug�ģ�������û��Ԫ�ص�ʱ���ǲ��ܵ�������ӿڵģ�����������������ǲ��ں�����ʵ�֣������ڵ���ǰ���м�� 
{
	return heap[1];
}

int main() 
{
	int a[10] = {1, 41, 23, 10, 11, 2, -1, 99, 14, 0};
	
	for(int i=0;i<sizeof(a)/sizeof(int);i++)
	{
		push(a[i]);
	}
	
	while(size())
	{
		cout << top() << " ";
		pop();
	}
	
	
	return 0;
}
