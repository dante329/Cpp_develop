#include <iostream>
using namespace std;
const int N = 2e5 + 10;
int fa[N];
int n;

int find(int x)
{
	if(x == fa[x]) return x;
	return fa[x] = find(fa[x]);
//	return fa[x] == x ? x : fa[x] = find(fa[x]);
}

int main() 
{
	cin >> n;
	for(int i=1;i<=n;i++) fa[i] = i;
	
	int T;
	cin >> T;
	while(T--)
	{
		int x,y,z; cin >> z >> x >> y;
		if(z == 1) 
		{
			int fx = find(x);
			int fy = find(y);
			fa[fx] = fy;	
		}	
		else
		{
			if(find(x) == find(y)) cout << "Y" << endl;
			else cout << "N" << endl;
		}
	} 
		
	return 0;
}
