//2025.2.19 17：00 仍然无法正确读取数据
//2025.2.19 17：03 oops报错，重启后能够正确读取所有数据，Devcpp有bug 

#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int N = 30;
vector<int> p[N];
//vector<vector<int>> p;

typedef pair<int,int> PII;

int n; //木块的数量 

PII find(int x)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<p[i].size();j++)
		{
			if(x == p[i][j])
			{
				return {i,j};
			}
		}
	}
	return {-1,-1};
}

void clean(PII px)
{
	for(int i=px.second+1;i<p[px.first].size();i++)
	{
		int t = p[px.first][i];
		p[t].push_back(t); 
	}
	p[px.first].resize(px.second+1);
}

void move(PII px,PII py)
{
	for(int i=px.second;i<p[px.first].size();i++)
	{
		p[py.first].push_back(p[px.first][i]);
	}
	p[px.first].resize(px.second);
}

void print(vector<int> p[])
{
	for(int i=0;i<n;i++)
	{
		cout << i << ":";
		for(int j=0;j<p[i].size();j++)
		{
			cout << " " << p[i][j];
		}
		cout << endl;
	}
}

//void clean(int x, int y)
//{
// // 把 [x, y] 以上的?块归位
// for(int j = y + 1; j < p[x].size(); j++)
// {
// int t = p[x][j];
// p[t].push_back(t);
// }
// p[x].resize(y + 1);
//}
//void move(int x1, int y1, int x2)
//{
// // 把 [x1, y1] 及其以上的?块放在 x2 上?
// for(int j = y1; j < p[x1].size(); j++)
// {
// p[x2].push_back(p[x1][j]);
// }
// p[x1].resize(y1);
//}

int main()
{
	cin >> n;
	for(int i=0;i<n;i++)
	{
		p[i].push_back(i);	//重要：使用pushback会自动扩容 
	}	
	string op1,op2;
	int a,b;
	while(cin >> op1 >> a >> op2 >> b)
	{
		cout << "op1: " << op1 << " a: " << a << " op2: " << op2 << " b: " << b << endl;  // 调试输出
		PII pa = find(a);
//		int x1 = pa.first,y1 = pa.second; //clean（）函数可以传入x1，y1作为参数，写起来会跟明了 
		PII pb = find(b);
//		int x2 = pb.first,y2 = pb.second;
		if(pa.first == pb.first)
		{
			continue;
		}
		if(op1 == "move")
		{
			clean(pa); //将a上方木块归位 
		}
		if(op2 == "onto")
		{
			clean(pb);
		}
		move(pa,pb);
	}
	print(p);
	
	return 0;
}
