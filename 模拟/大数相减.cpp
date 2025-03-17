#include<iostream>

using namespace std;
const int N = 1e6 + 10; 
int a[N],b[N],c[N];
int la,lb,lc;

bool cmp(string& x,string& y) //如果第一个参数小就返回true 
{
	if(x.size() != y.size())
	{
		return x.size() < y.size();
	}
	else
	{
		return x < y;
	}
}

void sub(int c[],int a[],int b[])
{
	for(int i=0;i<lc;i++)
	{
		c[i] += a[i] - b[i];
		if(c[i] < 0)
		{
			c[i + 1] -= 1; //c[i+1] = -1;
			c[i] += 10;
		}
	}
	while(lc > 1 && c[lc-1] == 0 ) lc--; //lc最多减到1 
}

int main()
{
	string x,y;
	cin >> x >> y;
	if(cmp(x,y))  
	{
		swap(x,y); //确保x比y大，因为等会要用大数减小数
		cout << "-"; //交换了说明题目给的是大数减小数，结果为负数 
	}
	la = x.length(); lb = y.length(); lc = max(la,lb);
	//转化成数组形式 注意减去字符'0' 
	for(int i=0;i<la;i++) a[i] = x[la-1-i] - '0';
	for(int i=0;i<lb;i++) b[i] = y[lb-1-i] - '0';
	//执行减法 
	sub(c,a,b); 
	//输出c数组结果
	for(int i=lc-1;i>=0;i--) cout << c[i]; 
	return 0;
} 
