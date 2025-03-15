#include <iostream>
 
using namespace std;

int n;
const int N = 1e5 + 10;
int a[N];

void down(int parent,int sz)
{
	int child = parent * 2;
	
	while(child <=sz)
	{
		if(child + 1 <= sz && a[child + 1] > a[child]) child++;
		if(a[parent] >= a[child]) return;	
		swap(a[parent],a[child]);
		
		parent = child;
		child = parent * 2;
	}
 } 

void heap_sort()
{
	//���� �ӵ�һ����Ҷ�ӽڵ���������ִ�����µ��� 
	//O(n)
	for(int i = n/2;i>=1;i--)
	{
		down(i,n);
	 } 
	//���� �����Ǵ���ѣ����Ѷ�Ԫ�غ����һ��Ԫ�ؽ������ó����һ��Ԫ����Ϊ��������ֵ��ͬʱ�ѵĽṹ���ƻ����µ������ڶ����Ԫ�أ����ν��� 
	//O(nlogn)
	for(int j = n;j>1;j--)
	{
		swap(a[1],a[j]); //��ʱ�ĵ�һ��Ԫ���Ѿ��ź��ˣ�������Ԫ�� 		
		down(1,j-1); //������֮��ѵĴ�С�ͼ�һ�����ֵ�Ѿ����ź��� 
	 } 
}

int main()
{
	cin >> n;
	//������ 
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	heap_sort();
	//��ӡ��� 
	for(int i=1;i<=n;i++)
	{
		cout << a[i] << " ";
	}
	
	return 0;
}
