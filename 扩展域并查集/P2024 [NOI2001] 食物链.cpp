//扩展域并查集 
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
////	if(op == 1 && !issame(x,y)) return false; //不能直接写issame，如果他们之间还没有分配任何关系，这时候指定他们为同类不应该是假话 
////	if(op == 2 && issame(x,y) || op == 2 && find(x) == find(y + n)) return false;
////	return true;
////}
//
//bool check(int op,int x,int y)
//{
//	if(x > n || y > n) return false;
//	if(op == 1) //x、y同类 
//	{
//		//举反例 x吃y || y吃x 
//		if(find(x) == find(y+n) || find(x) == find(y+2*n)) return false; 
//	} 
//	if(op == 2) //x吃y 
//	{
//		//举反例 同类 || y吃x 
//		if(find(x) == find(y) || find(x) == find(y + n)) return false;
//	} 
//	return true;
//}
//
//int main()
//{
//	cin >> n >> k;
//	
//	//用并查集一进来就要初始化，扩展域并查集初始化全部范围 
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

//带权并查集 
#include<iostream>

using namespace std;

const int N = 5e4 + 10;

int fa[N]; //并查集 
int d[N]; //权值 

int n,k;

int find(int x)
{
	if(fa[x] == x) return x;
	
	int t = find(fa[x]); //路径压缩，配合return fa[x] = t;会使父节点挂在根节点下 
	
	d[x] += d[fa[x]]; //权值改变 
	
	return fa[x] = t;
}

//带权并查集的合并是需要知道要合并的两个集合之间的权值 
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
	//带权并查集是通过权值差来判断关系 
	while(k--)
	{
		int op,x,y; cin >> op >> x >> y;
		
		if(x > n || y > n) ret++;
		else if(op == 1) //同类 
		{
			//判断假话，不是同类 
			if(find(x) == find(y) && ((d[y]-d[x]) % 3 + 3) % 3 != 0) ret++;
			else un(x,y,0); //是真话就要维护并查集 
		}
		else //x吃y 
		{
			if(find(x) == find(y) && ((d[y]-d[x]) % 3 + 3) % 3 != 1) ret++;
			else un(x,y,2);
		}
	}
	
	cout << ret;
	return 0;
} 
