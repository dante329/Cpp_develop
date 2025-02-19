//2025.2.19 17��00 ��Ȼ�޷���ȷ��ȡ����
//2025.2.19 17��03 oops�����������ܹ���ȷ��ȡ�������ݣ�Devcpp��bug 

#include<iostream>
#include<vector>
#include<string>

using namespace std;

const int N = 30;
vector<int> p[N];
//vector<vector<int>> p;

typedef pair<int,int> PII;

int n; //ľ������� 

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
// // �� [x, y] ���ϵ�?���λ
// for(int j = y + 1; j < p[x].size(); j++)
// {
// int t = p[x][j];
// p[t].push_back(t);
// }
// p[x].resize(y + 1);
//}
//void move(int x1, int y1, int x2)
//{
// // �� [x1, y1] �������ϵ�?����� x2 ��?
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
		p[i].push_back(i);	//��Ҫ��ʹ��pushback���Զ����� 
	}	
	string op1,op2;
	int a,b;
	while(cin >> op1 >> a >> op2 >> b)
	{
		cout << "op1: " << op1 << " a: " << a << " op2: " << op2 << " b: " << b << endl;  // �������
		PII pa = find(a);
//		int x1 = pa.first,y1 = pa.second; //clean�����������Դ���x1��y1��Ϊ������д����������� 
		PII pb = find(b);
//		int x2 = pb.first,y2 = pb.second;
		if(pa.first == pb.first)
		{
			continue;
		}
		if(op1 == "move")
		{
			clean(pa); //��a�Ϸ�ľ���λ 
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
