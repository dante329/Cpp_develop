//ʱ�临�Ӷ�O(n*logn) �����ڴ����������ϴ�� 
#include<iostream>

using namespace std;

const int N = 1e5 + 10;

int f[N], len; //f[i]��ʾ����Ϊi�����������е���СĩβԪ�أ�len��¼f����ĳ��ȣ�����a[i]��f[i]�����ζ�ſ��Խ��ڳ���Ϊi�ĵ�ǰ��������еĺ��棬���ǳ��ȼ�1��Ҫ��a[i]�浽f[++len] 
//ΪʲôҪ����С��̰�ġ� 
//f[N]����������ϸ���� 
int n; 
int a[N];
 
int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) cin >> a[i];
	
	for(int i=1;i<=n;i++)
	{
		if(len == 0 || a[i] > f[len]) //f�л�û���� || ��ǰa[i]���ڵ�ǰ������е���СĩβԪ��f[len] -> �¿��ٿռ佫��ǰ���a[i]���ȥ 
		{
			f[++len] = a[i];
		}
		else //a[i]��������f[len]������f[len]֮ǰ��Ԫ�����ҵ����ʵ�λ��ƥ�䣬�ö����Ż� 
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
	
	//�������f����ĳ��ȣ��ʹ���������������еĳ��� 
	cout << len;
	return 0;
}
