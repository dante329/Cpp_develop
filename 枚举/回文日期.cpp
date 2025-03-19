//枚举所有月日组合，反推年份，这样用时更短 
#include<iostream>
using namespace std;

int days[] = {0,31,29,31,30,31,30,31,31,30,31,30,31};

int main()
{
	int cnt = 0;
	int x,y; cin >> x >> y;
	for(int i=1;i<=12;i++)
	{
		for(int j=1;j<=days[i];j++)
		{
			int ret = j%10*1000 + j/10*100 + i%10*10 + i/10;
			ret = ret * 10000 + i*100 + j; 
			if(ret >= x && ret <= y) cnt++;
		}
	} 
	cout << cnt; 
	return 0;
}
