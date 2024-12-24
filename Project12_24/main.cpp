#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int main()
{
	string s1;
	string s2 = "hello";
	string s3 = "hello world";
	string s4 = "Dante hello world"; 
	cout << "s1:" << s1.size() << endl;
	cout << "s2:" << s2.size() << endl;
	cout << "s3:" << s3.size() << endl;
	cout << "s4:" << s4.size() << endl;
	cout << "s1:" << s1.length() << endl;
	cout << "s2:" << s2.length() << endl;
	cout << "s3:" << s3.length() << endl;
	cout << "s4:" << s4.length() << endl;
	return 0;
}

//int main() {
//    string str1;            // 默认构造，创建空字符串
//    string str2("Hello");   // 使用字符串字面量初始化
//    string str3 = "World";  // 使用赋值初始化
//    string str4(str2);      // 使用另一个字符串初始化
//
//    cout << str1 << " " << str2 << " " << str3 << " " << str4 << endl;
//    return 0;
//}

//int main()
//{	
//	char ch1[10] = "abcdef";
//	char ch2[10] = { 0 };
//	strncpy(ch2, ch1, 7);
//	cout << ch2 << endl;
//	return 0;
//}

//int main ()
//{
// string name;
// getline (cin, name, 'x');  //自定义以字符'x'为结束标志
// cout << name << endl;
// return 0;
//}


//int main ()
//{
// string name;
// getline (cin, name);  //默认以'\n'为结束标志
// cout << name << endl;
// return 0;
//}

//int main()
//{
// 	char arr[20] = { 0 };
//	cin >> arr;
// 	cout << arr << endl;
// 	return 0;
//}


//int main() 
//{
// 	char arr[20] = {0};
// 	scanf("%s", arr);
//	printf("%s", arr);
//	return 0;
//}
