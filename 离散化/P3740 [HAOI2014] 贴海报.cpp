#include<iostream>
#include<algorithm>
#include<unordered_map>
using namespace std;
const int N = 1010;
int n,m;
int a[N],b[N];
int disc[N * 4],pos; //discҪ��ɢ��a��b����ÿ��Ԫ�ص�����Ԫ�� 
unordered_map<int,int> mp;

int main()
{
	cin >> n >> m;
	//������
	for(int i=1;i<=m;i++)
	{
		cin >> a[i] >> b[i];
		disc[++pos] = a[i]; disc[++pos] = a[i]+1; 
		disc[++pos] = b[i]; disc[++pos] = b[i]+1; 
	}
	//��ɢ��	
	sort(disc+1,disc+1+pos);
	int cnt = 0;
	for(int i=1;i<=pos;i++)
	{
		if(mp.count(disc[i])) continue;
		mp[disc[i]] = ++cnt;	
	} 
	//ģ�������� 
	int w[N * 4];
	for(int i=1;i<=m;i++)
	{
		//����ɢ��֮���ֵȥ�������ұ߽� a[i] ~ b[i] 
		int l = mp[a[i]], r = mp[b[i]];
		for(int j=l;j<=r;j++) w[j] = i;	
	} 
	//����ж��ٸ���ͬ������ 
	bool st[N * 4];
	int ret = 0;
	for(int i=1;i<=cnt;i++) //��w�����꺣��֮�󣬺��������ұ߽���b[i]�������ֵ����ɢ��������Χ��cnt 
	{
		int x = w[i];
		if(st[x] == true || x == 0) continue;
		ret++;
		st[x] = true;
	}
	cout << ret << endl;
	return 0;
}
