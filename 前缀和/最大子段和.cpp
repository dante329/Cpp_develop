#include<iostream>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;

LL f[N];
int n;

int main()
{
	cin >> n;
	LL ret = -1e11;
	LL premini = 0;  
	for(int i=1;i<=n;i++)
	{
		int x; cin >> x;
		f[i] = f[i-1] + x;
		//����Ӷκ��� f[i] - f[x]  (1 <= x < i)
		//����ret�����ֵ 
		ret = max(f[i] - premini,ret);
		//�ٸ���premini����Сֵ premini����f[x]��f[x]������С��ʱ���ǲ���ȡ��iλ�õ� 
		premini = min(f[i],premini); 
		
	}
	cout << ret; 
	return 0;
 } 
