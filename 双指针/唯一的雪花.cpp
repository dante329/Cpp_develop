#include<iostream>
#include<unordered_map>
using namespace std;
const int N =  1e6 + 10;
int a[N];
int T,n;
//unordered_map<int,int> mp; //�������������Ҫע�����ǰ������� 

int main()
{
	cin >> T;
	while(T--)
	{
		cin >> n;
		for(int i=1;i<=n;i++) cin >> a[i];
		int left = 1, right = 1;
		int ret = 0;
		unordered_map<int,int> mp; //ά������������Ԫ�س��ִ��� 
		while(right <= n)
		{
			
	//����˼·		
	//		if(mp[a[right]] < 1) 
	//		{
	//			mp[a[right++]]++;
	//			ret = max(ret,right-left+1);
	//		}
	//		else mp[a[left++]]--;
	
	//��ȷ˼· 
			//������ 
			mp[a[right]]++;
			//�������ڵ�Ԫ���Ƿ�Ϸ�
			while(mp[a[right]] > 1)
			{
				//�Ƿ��ͽ���whileѭ���������� 
				mp[a[left++]]--;
			}
			ret = max(ret,right-left+1);
			right++;
		}
		cout << ret << endl;
	} 
	return 0;
} 
