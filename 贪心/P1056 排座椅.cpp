#include<iostream> 
#include<algorithm> 
using namespace std;
const int N = 2010; 
struct node
{
	int index,cnt;
}row[N],col[N];
int m,n,k,l,d;

bool cmp1(node& n1,node& n2)
{
	return n1.cnt > n2.cnt;
}

bool cmp2(node& n1,node& n2)
{
	return n1.index < n2.index;
}
int main()
{
	cin >> m >> n >> k >> l >> d;
	//��ʼ��row��col��index 
	for(int i=1;i<=m;i++) row[i].index = i;
	for(int i=1;i<=n;i++) col[i].index = i;
	
	while(d--)
	{
		int x,y,p,q; cin >> x >> y >> p >> q;	
		if(x == p) col[min(y,q)].cnt++;
		else row[min(x,p)].cnt++;
	} 
	
	//������m��n��Χ�ڰ���cnt�Ӵ�С���� 
	sort(row+1,row+m+1,cmp1);
	sort(col+1,col+n+1,cmp1);
	
	//��ǰk��l�����ݰ���index���� 
	sort(row+1,row+k+1,cmp2);
	sort(col+1,col+l+1,cmp2);
	
	//���ǰk��l��
	for(int i=1;i<=k;i++) cout << row[i].index << " ";
	cout << endl;
	for(int i=1;i<=l;i++) cout << col[i].index << " ";
	cout << endl;
	return 0;
}
