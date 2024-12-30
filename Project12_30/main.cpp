//#include <iostream>
//#include <string>
//using namespace std;
//
//int main() 
//{
//    string str = "12345";
//    int num = stoi(str,NULL,16);
//    cout << "Converted integer: " << num << endl;  // Êä³ö£ºConverted integer: 12345
//    return 0;
//}     

#include <iostream>
#include <string>
using namespace std;

int main() 
{
	int n;
	string s;
	cin >> n >> s;	
    cout << stoi(s,NULL,n);
	return 0;
}

//#include <iostream>
//#include <string>
//#include <cmath>
//using namespace std;
//
//void change(int n,string s)
//{
//	int sz = s.size();
//	int j=0;
//	int ret = 0;
//	for(int i=sz-1;i>=0;--i)
//	{
//		if(s[i]<='9')
//		{
//			ret += (s[i]-'0')*pow(n,j++);
//		}
//		else
//		{
//			ret += (s[i]-'A'+10)*pow(n,j++);
//		}
//	}
//	cout << ret;
//}
//
//int main() 
//{
//	int n;
//	string s;
//	cin >> n >> s;	
//	change(n,s);
//	return 0;
//}



//
//#include <iostream>
//#include <string>
//#include <cmath>
//using namespace std;
//
//void change(int n,int x,int i)
//{
//	if(n>=x)
//		change(n/x,x,++i);
//	cout << str.find(n%x)*pow(x,i);
//}
//
//int main() 
//{
//	int n,x;
//	cin >> n >> x;	
//	change(n,x,0);
//	return 0;
//}

//#include <iostream>
//#include <string>
//using namespace std;
//
//string str = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//
//void change(int n,int x)
//{
//	if(n>=x)
//		change(n/x,x);
//	cout << str[n%x];
//}
//
//int main() 
//{
//	int n,x;
//	cin >> n >> x;	
//	change(n,x);
//	return 0;
//}
