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
//    string str1;            // Ĭ�Ϲ��죬�������ַ���
//    string str2("Hello");   // ʹ���ַ�����������ʼ��
//    string str3 = "World";  // ʹ�ø�ֵ��ʼ��
//    string str4(str2);      // ʹ����һ���ַ�����ʼ��
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
// getline (cin, name, 'x');  //�Զ������ַ�'x'Ϊ������־
// cout << name << endl;
// return 0;
//}


//int main ()
//{
// string name;
// getline (cin, name);  //Ĭ����'\n'Ϊ������־
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
