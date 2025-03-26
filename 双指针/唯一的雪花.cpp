#include<iostream>
#include<unordered_map>
using namespace std;
const int N =  1e6 + 10;
int a[N];
int T,n;
//unordered_map<int,int> mp; //多组测试用例，要注意清空前面的数据 

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		int left = 1, right = 1;
		int ret = 0;
		unordered_map<int,int> mp; //维护窗口内所有元素出现次数 
		while(right <= n)
		{
			
	//错误思路		
	//		if(mp[a[right]] < 1) 
	//		{
	//			mp[a[right++]]++;
	//			ret = max(ret,right-left+1);
	//		}
	//		else mp[a[left++]]--;
	
	//正确思路 
			//进窗口 
			mp[a[right]]++;
			//检查进窗口的元素是否合法
			while(mp[a[right]] > 1)
			{
				//非法就进入while循环，出窗口 
				mp[a[left++]]--;
			}
			ret = max(ret,right-left+1);
			right++;
		}
		cout << ret << endl;
	} 
	return 0;
} 
