#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
unordered_map<int,int> mp;
typedef long long LL;
const int N = 2e4 + 10;
LL a[N],b[N],n;
LL disc[N*2],pos;  //������������ɢ����a��b����Ҫ�õ�ʱ����ȥdisc����
LL f[N*2];

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++) 
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i]; 
		disc[++pos] = b[i];
	}
	//��ɢ�� 
	sort(disc+1,disc+1+pos); 
	pos = unique(disc+1,disc+1+pos) - (disc+1);

	for(int i=1;i<=pos;i++)
	{
		int x = disc[i]; 
		mp[x] = i; 	
	}
	//����������� 
	for(int i=1;i<=n;i++)
	{
		int l = mp[a[i]], r = mp[b[i]]; //x,y��ʾ��ɢ���ֵ 
		f[l]++, f[r]--;
	}
	//��ԭ����
	for(int i=1;i<=pos;i++) 
	{
		f[i] += f[i-1];
	}
	//����������
	int ret = 0;
	for(int i=1;i<=pos;i++) 
	{
		int j =  i;
		while(j<=pos && f[j]>0) j++; //jͣ�µ�λ�þ���0 
		ret += disc[j] - disc[i];
		i = j;
	}
	cout << ret << endl;
	return 0;
}
