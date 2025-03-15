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
	//建堆 从第一个非叶子节点向上依次执行向下调整 
	//O(n)
	for(int i = n/2;i>=1;i--)
	{
		down(i,n);
	 } 
	//排序 建的是大根堆，将堆顶元素和最后一个元素交换，拿出最后一个元素作为结果的最大值，同时堆的结构被破坏重新调整出第二大的元素，依次进行 
	//O(nlogn)
	for(int j = n;j>1;j--)
	{
		swap(a[1],a[j]); //此时的第一个元素已经排好了，是最大的元素 		
		down(1,j-1); //交换完之后堆的大小就减一，最大值已经被排好了 
	 } 
}

int main()
{
	cin >> n;
	//读数据 
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	heap_sort();
	//打印结果 
	for(int i=1;i<=n;i++)
	{
		cout << a[i] << " ";
	}
	
	return 0;
}
