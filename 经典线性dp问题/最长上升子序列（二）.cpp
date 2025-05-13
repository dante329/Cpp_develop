//时间复杂度O(n*logn) 可用于处理数据量较大的 
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int f[N], len; //f[i]表示长度为i的上升子序列的最小末尾元素，len记录f数组的长度，遇到a[i]比f[i]大的意味着可以接在长度为i的当前最大子序列的后面，于是长度加1就要将a[i]存到f[++len] 
//为什么要存最小，贪心。 
//f[N]里面的数据严格递增 
int n; 
int a[N];
 
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++)
	{
		if(len == 0 || a[i] > f[len]) //f中还没有数 || 当前a[i]大于当前最长子序列的最小末尾元素f[len] -> 新开辟空间将当前这个a[i]存进去 
		{
			f[++len] = a[i];
		}
		else //a[i]并不大于f[len]，就在f[len]之前的元素中找到合适的位置匹配，用二分优化 
		{
			int l = 1, r = len;
			while(l < r)
			{
				int mid = (l + r) / 2;
				if(f[mid] >= a[i]) r = mid;
				else l = mid + 1;
			}
			f[l] = a[i];
		}
	}
	
	//最终输出f数组的长度，就代表最大上升子序列的长度 
	cout << len;
	return 0;
}
