//方式一：排序 + 去重 + 二分查找（在disc中依次查找a的每个元素，返回在disc中的下标） 
//#include <iostream>
//#include <algorithm>
//using namespace std; 
//const int N = 1e5 + 10;
//int a[N],n;
//int disc[N],pos;
//
////二分找x，返回下标 
//int binary_search(int x)
//{
//	int left = 1,right = pos;	
//	while(left < right)
//	{
//		int mid = (left + right) / 2;
//		if(disc[mid] >= x) right = mid;
//		else left = mid + 1;`
//	}
//	return left
//}
//
//int main() 
//{
//	cin >> n;
//	for(int i=1;i<=n;i++) 
//	{
//		cin >> a[i];
//		disc[++pos] = a[i]; //pos在这里起到枚举下标的作用 
//	}
//	sort(disc+1,disc+pos+1); //默认排升序
//	pos = unique(disc+1,disc+pos+1) - (disc+1); //给元素去重 pos在这里接收去重后元素的个数 
//	for(int i=1;i<=n;i++)
//	{	
//		printf("%d离散化后的值为%d\n",a[i],binary_search(a[i]));
//	} 
//	
//	return 0;
//}
//方式二：排序 + 哈希表去重并且记录离散化后的值 
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std; 
const int N = 1e5 + 10;
int a[N],n;
int disc[N],pos;
unordered_map<int,int> mp;

int main() 
{
	cin >> n;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
		disc[++pos] = a[i]; 
	}
	sort(disc+1,disc+pos+1); //默认排升序
	int cnt = 0;
	for(int i=1;i<=pos;i++)
	{
		int x = disc[i];
		if(mp.count(x)) continue;
		mp[x] = ++cnt; //哈希表中储存的是 disc中的各个元素 及其 从小到大分别是第几号 
	}
	for(int i=1;i<=n;i++)
	{	
		printf("%d离散化后的值为%d\n",a[i],mp[a[i]]);
	} 
	
	return 0;
}
