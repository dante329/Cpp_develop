//��չ�򲢲鼯 
//#include<iostream>
//using namespace std;
//const int N = 5e4 + 10;
//int fa[N * 3];
//int n,k;
//int ret;
//
//int find(int x)
//{
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
//}
//
//void un(int x,int y)
//{
//	fa[find(x)] = find(y);
//}
//
//bool issame(int x,int y)
//{
//	return find(x) == find(y);
//}
//
////bool check(int op,int x,int y)
////{
////	if(x > n || y > n) return false;
////	if(op == 1 && !issame(x,y)) return false; //����ֱ��дissame���������֮�仹û�з����κι�ϵ����ʱ��ָ������Ϊͬ�಻Ӧ���Ǽٻ� 
////	if(op == 2 && issame(x,y) || op == 2 && find(x) == find(y + n)) return false;
////	return true;
////}
//
//bool check(int op,int x,int y)
//{
//	if(x > n || y > n) return false;
//	if(op == 1) //x��yͬ�� 
//	{
//		//�ٷ��� x��y || y��x 
//		if(find(x) == find(y+n) || find(x) == find(y+2*n)) return false; 
//	} 
//	if(op == 2) //x��y 
//	{
//		//�ٷ��� ͬ�� || y��x 
//		if(find(x) == find(y) || find(x) == find(y + n)) return false;
//	} 
//	return true;
//}
//
//int main()
//{
//	cin >> n >> k;
//	
//	//�ò��鼯һ������Ҫ��ʼ������չ�򲢲鼯��ʼ��ȫ����Χ 
//	for(int i=1;i<=n*3;i++) fa[i] = i;
//	
//	while(k--)
//	{
//		int op,x,y;
//		cin >> op >> x >> y;
//		if(!check(op,x,y)) 
//		{
//			ret++;
//			continue;
//		}
//		if(op == 1)
//		{	
//			un(x,y);
//			un(x+n,y+n);
//			un(x+2*n,y+2*n);
//		}
//		else
//		{
//			un(x,y+2*n);
//			un(x+n,y);
//			un(x+2*n,y+n);
//		}
//	}
//	cout << ret; 
//	return 0;
//} 

//��Ȩ���鼯 
#include<iostream>

using namespace std;

const int N = 5e4 + 10;

int fa[N]; //���鼯 
int d[N]; //Ȩֵ 

int n,k;

int find(int x)
{
	if(fa[x] == x) return x;
	
	int t = find(fa[x]); //·��ѹ�������return fa[x] = t;��ʹ���ڵ���ڸ��ڵ��� 
	
	d[x] += d[fa[x]]; //Ȩֵ�ı� 
	
	return fa[x] = t;
}

//��Ȩ���鼯�ĺϲ�����Ҫ֪��Ҫ�ϲ�����������֮���Ȩֵ 
void un(int x,int y,int w) 
{
	int fx = find(x),fy = find(y);
	if(fx != fy)
	{
		fa[fx] = fy;
		d[fx] = w + d[y] - d[x];
	}
}

int main()
{
	cin >> n >> k;
	
	for(int i=1;i<=n;i++) fa[i] = i;
	
	int ret = 0;
	//��Ȩ���鼯��ͨ��Ȩֵ�����жϹ�ϵ 
	while(k--)
	{
		int op,x,y; cin >> op >> x >> y;
		
		if(x > n || y > n) ret++;
		else if(op == 1) //ͬ�� 
		{
			//�жϼٻ�������ͬ�� 
			if(find(x) == find(y) && ((d[y]-d[x]) % 3 + 3) % 3 != 0) ret++;
			else un(x,y,0); //���滰��Ҫά�����鼯 
		}
		else //x��y 
		{
			if(find(x) == find(y) && ((d[y]-d[x]) % 3 + 3) % 3 != 1) ret++;
			else un(x,y,2);
		}
	}
	
	cout << ret;
	return 0;
} 
