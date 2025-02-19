#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int N = 30;
vector<int> p[N];

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
}

void clean(PII& px)
{
	for(int i=px.second+1;i<p[px.first].size();i++)
	{
		p[p[px.first][i]].push_back(p[px.first][i]); 
	}
	p[px.first].resize(px.second+1);
}

void move(PII& px,PII& py)
{
	for(int i=px.second;i<p[px.first].size();i++)
	{
		for(int j=py.second;j<p[py.first].size();j++)
		{
			p[py.first].insert(p[py.first].begin()+j,p[px.first][i]);
		}
	}
}

void move_top(PII& px,PII& py)
{
	for(int i=px.second;i<p[px.first].size();i++)
	{
		p[py.first].push_back(p[px.first][i]); 
	}
}


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
		PII pa = find(a);
		int x1 = pa.first,y1 = pa.second;
		PII pb = find(b);
		int x2 = pb.first,y2 = pb.second;
		if(x1 == x2)
		{
			continue;
		}
		if(op1 == "move")
		{
			clean(pa); //将a上方木块归位 
		}
		else if(op1 == "pile")
		{
			move(pa,pb);	
		} 
		if(op2 == "onto")
		{
			clean(pb);
			move(pa,pb);
		}
		else if(op2 == "over")
		{
			move_top(pa,pb);
		}
	}
	
	
	return 0;
}
