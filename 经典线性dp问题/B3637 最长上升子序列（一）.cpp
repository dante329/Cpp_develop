//ʱ�临�Ӷ�O(n^2) ��������С��ʹ�� 
#include <iostream>
using namespace std;
const int N = 5010;

int a[N];
int f[N]; //f[i]��ʾ��a[i]Ϊ��β�������������У�����������еĳ��� 
int n;
 
int main() 
{
	cin >> n;
	
	for(int i=1;i<=n;i++) cin >> a[i];
	
	int ret = 0;
	for(int i=1;i<=n;i++)
	{
		f[i] = 1; //������������һ������Ϊ�����У��������볤��Ϊ1���ȳ�ʼ��Ϊ1
		for(int j=1;j<i;j++)
		{
			if(a[j] < a[i])
			{
				f[i] = max(f[i], f[j] + 1);
			}
		}	
		ret = max(ret,f[i]);
	}	
	
	cout << ret;
	return 0;
}
