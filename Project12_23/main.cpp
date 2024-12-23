#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	int arr[10];
	cin >> arr;//err
	cout << arr[0];
	return 0;
}


//int main()
//{
// char arr[20] = "abcdef";
// cout << "数组的长度:" << sizeof(arr)/sizeof(arr[0]) << endl; //注释1
// //输出20
// cout << "字符串的长度:" << strlen(arr) << endl;
// //输出6
// return 0;
//}

//int main()
//{
//	char str1[100] = "abcdef";
//	cout << sizeof(str1)/sizeof(char) << endl;  
//
//	char str2[] = "abcdef";
//	cout << sizeof(str2)/sizeof(char) << endl;
//	return 0;
//}

//int main()
//{
//  int n;
//  cin >> n;
//  int arr[n+1];
//  for (int i = 1; i <= n; i++) {
//        cin >> arr[i];
//    }
//  int maxn =0;
//  for(int i=1;i<=n;++i)
//  {
//  	for(int j=i;j<=n;++j)
//  	{
//  		maxn = max(maxn,abs(i-j)+abs(arr[i]-arr[j]));
//	  }
//   } 
//   cout << maxn;
//  return 0;
//}

//bool isClean(int i)
//{
//	while(i)
//	{
//		int rem = i % 10;
//		if(rem == 2)
//		{
//			return false;
//		}
//		i /= 10;
//	}
//	return true;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	int count =0;
//	for(int i=1;i<=n;++i)
//	{
//		if(isClean(i))
//			count++;
//		else
//			continue;
//	} 
//	cout << count;
//	return 0;
//}

//int main() {
//	string s;
//	getline(cin,s);
//	int count = 0;
//	for(string::iterator it=s.begin();it<s.end();++it)
//	{
//		if(*it != '\n' && *it != ' ')
//		{
//			count++;
//		}
//	}
//	cout << count;
//	return 0;
//}

//int main() {
////	string str="abcdef";
//	string str("abcdef");
//	for(string::iterator it=str.begin();it<str.end();it++)
//	{
//		cout << *it ;
//	}
//	return 0;
//}
