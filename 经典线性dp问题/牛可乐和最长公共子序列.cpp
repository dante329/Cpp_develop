#include<iostream>
using namespace std;
const int N = 5010;
int f[N][N]; //f[i][j]��ʾa�ַ�����1~i��b�ַ�����1~j����������еĳ��� 
string a,b;

int main()
{
	while(cin >> a >> b)
	{
		int len1 = a.size(), len2 = b.size();
		a = " " + a, b = " " + b;
		
		for(int i=1;i<=len1;i++)
		{
			for(int j=1;j<=len2;j++)
			{
				if(a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
				else f[i][j] = max(f[i-1][j], f[i][j-1]); //�ڶ�ά����ͼ�У�f[i-1][j]��f[i][j]�����棬f[i][j-1]��f[i][j]����ߣ��������ڱ�����f[i][j]֮ǰ���Ѿ�������ˣ��ǿ���ֱ�������ǵ�ֵ���õ� 
			}
		}
			
		cout << f[len1][len2] << endl;
	}
		
	
	return 0;
 } 
