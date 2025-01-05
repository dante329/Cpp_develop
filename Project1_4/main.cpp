#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int x1=6;
	x1 = x1|(x1-1);
	cout << x1 << endl; 
	return 0;
}

//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() 
//{
//	int x1=0,x2=0;
//	string s;
//	cin >> x1 >> s >> x2;
////	cin >> x1;
////	cin >> s;
////	cin >> x2;
//	cout << x1 << " " <<  s  << " " << x2;
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//string str = "0123456789ABCDEF";
//
//void print(int num,int x)
//{
//	if(num >= x)
//	{
//		print(num/x,x);
//	}
//	cout << str[num%x];
//
//}
//
//int main() 
//{
//	int x1=0,x2=0;
//	string s;
//	cin >> x1;
//	cin >> s;
//	cin >> x2;
//	int num = stoi(s,NULL,x1);
//	print(num,x2);
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//string str = "0123456789ABCDEF";
//
//void print(int num,int x)
//{
//	if(num >= x)
//	{
//		print(num/x,x);
//	}
//	else
//	{
//		cout << str[num%x];
//	}
//}
//
//int main() 
//{
//	int x1,x2;
//	string s;
//	cin >> x1,s,x2;
//	int num = stoi(s,NULL,x1);
//	print(num,x2);
//	return 0;
//}
