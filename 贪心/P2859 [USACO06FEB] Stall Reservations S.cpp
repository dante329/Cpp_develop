#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 5e4 + 10;
struct node
{
	int x; //奶牛开始时间 / 产房结束时间 
	int y; //奶牛结束时间 / 产房编号 
	int z; //奶牛编号 
	
	bool operator<(const node& other) const
	{
		return x > other.x; //大于号是小根堆 
	}
}a[N];
int n;

bool cmp(node& n1,node& n2)
{
	return n1.x < n2.x;
}

int main()
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i].x >> a[i].y;
		a[i].z = i;
	}
	sort(a+1,a+n+1,cmp);
	priority_queue<node> pq;
	int ret[N]; //由于还要打印第几个奶牛去了哪一个产房，就需要一个数组来记录 
	//先把第一个奶牛放进去，从第二个开始算
	int cnt = 1; //既能记录需要多少产房，又能标记目前最大的产房号 
	pq.push({a[1].y,1}); 
	ret[a[1].z] = 1; 
	for(int i=2;i<=n;i++)
	{
		int begin = a[i].x, end = a[i].y;
		node t = pq.top(); //把目前产房结束时间最小的那个拿出来比较 
		if(begin > t.x) //最小的那个已经产完了 
		{
			pq.pop(); //把原来的奶牛弄走 
			pq.push({end,t.y}); //放入新的奶牛，产房号还是原来的 
			ret[a[i].z] = t.y; //在ret中记录第几头奶牛去了第几号产房 
		}
		else //需要新开产房
		{
			cnt++;
			pq.push({end,cnt});
			ret[a[i].z] = cnt;  
		} 
	}
	cout << cnt << endl;
	for(int i=1;i<=n;i++) cout << ret[i] << endl;
	return 0;
}
