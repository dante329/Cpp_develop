#include <iostream>
using namespace std;

int cal(int a,int b,char c)
{
	switch(c)
	{
		case '+':
			return a+b;
		case '-':
			return a-b;
		case '*':
			return a*b;
		case '/':
			return a/b;
		case '%':
			return a%b;
	}
 } 

int main() 
{
	int a,b;
	char c;
	cin >> a >> c >> b;
	cout << cal(a,b,c) << endl;
	return 0;
}

//int main() 
//{
//	cin.tie(0);
//	ios::sync_with_stdio(false);
//	cout << "ÇëÊäÈëÊı×Ö£º" << endl; 
//	int a;
//	cin >> a;
//	
//	return 0;
//}
