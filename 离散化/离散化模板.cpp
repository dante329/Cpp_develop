//��ʽһ������ + ȥ�� + ���ֲ��ң���disc�����β���a��ÿ��Ԫ�أ�������disc�е��±꣩ 
//#include <iostream>
//#include <algorithm>
//using namespace std; 
//const int N = 1e5 + 10;
//int a[N],n;
//int disc[N],pos;
//
////������x�������±� 
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
//		disc[++pos] = a[i]; //pos��������ö���±������ 
//	}
//	sort(disc+1,disc+pos+1); //Ĭ��������
//	pos = unique(disc+1,disc+pos+1) - (disc+1); //��Ԫ��ȥ�� pos���������ȥ�غ�Ԫ�صĸ��� 
//	for(int i=1;i<=n;i++)
//	{	
//		printf("%d��ɢ�����ֵΪ%d\n",a[i],binary_search(a[i]));
//	} 
//	
//	return 0;
//}
//��ʽ�������� + ��ϣ��ȥ�ز��Ҽ�¼��ɢ�����ֵ 
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
	sort(disc+1,disc+pos+1); //Ĭ��������
	int cnt = 0;
	for(int i=1;i<=pos;i++)
	{
		int x = disc[i];
		if(mp.count(x)) continue;
		mp[x] = ++cnt; //��ϣ���д������ disc�еĸ���Ԫ�� ���� ��С����ֱ��ǵڼ��� 
	}
	for(int i=1;i<=n;i++)
	{	
		printf("%d��ɢ�����ֵΪ%d\n",a[i],mp[a[i]]);
	} 
	
	return 0;
}
