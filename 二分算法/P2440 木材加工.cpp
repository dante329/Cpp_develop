#include<iostream>
using namespace std;
typedef long long LL;
int n,k;
const int N = 1e5 + 10;
LL a[N];

int calc(int l)
{
	LL ret = 0;
	for(int i=1;i<=n;i++)
	{
		ret += a[i]/l;
	}
	return ret;
}

int main()
{
	cin >> n >> k;
	//�����ݣ�������󳤶�
	LL maxLen = 0;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i];
		maxLen = max(a[i],maxLen);
	}  
	//�Ӵ�Сö�ٳ��Ȼᳬʱ 
//	for(int l=maxLen;l>=1;l--)
//	{
//			
//	} 
	//�ö����Ż�
	LL left = 0, right = maxLen, mid = 0;
	while(left < right)
	{
		mid = (left+right+1)/2;
		if(calc(mid) >= k) left = mid;
		else right = mid - 1;
	} 
	cout << left << endl;
    return 0;
}
