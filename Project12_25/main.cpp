#include <iostream>
#include <string>
using namespace std;

int main()
{
	string str;
	getline(cin,str);
	string::iterator it_pre = str.begin();
	int size = 0;
	int max_size = 0;
	int max_word_index = 0;
	for(string::iterator it_cur = it_pre ; it_cur <= str.end() ;++it_cur)
	{
		if(*it_cur == ' ' || it_cur == str.end())
		{
			size = it_cur - it_pre;
			if(size>max_size)
			{
				max_size = size;
				max_word_index = it_pre - str.begin(); //it_preָ�����һ�����ʵ�����ĸ������it_preǰ���㲢�洢�������������ĸ���±꣬�����ʱҪ�õ� 
			}
			it_pre = it_cur + 1; //it_curָ����ǿո� 
		}	
	} 
	cout << str.substr(max_word_index,max_size);
	return 0;
}



//int main() {
//    string str;
//    getline(cin, str); // ʹ�� getline ��ȡ��������
//
//    int size = 0;        // ��ǰ���ʳ���
//    int max_size = 0;    // ��󵥴ʳ���
//    int max_word_index = 0; // ���������ĸ����
//    int start_index = 0; // ��ǰ���ʵ�����ĸ����
//
//    for (int i = 0; i <= str.size(); ++i) {
//        if (i == str.size() || str[i] == ' ') { // ���ʽ�������
//            size = i - start_index; // ��ǰ���ʳ���
//            if (size > max_size) {  // ������󳤶ȼ�����
//                max_size = size;
//                max_word_index = start_index;
//            }
//            start_index = i + 1; // ���µ���һ�����ʵĿ�ʼλ��
//        }
//    }
//
//    // ��������
//    cout << str.substr(max_word_index, max_size);
//    return 0;
//}



//int main()
//{
//	char str[10]  = "hello";
//	for(char ch:str)
//	{
//		cout << ch << ' ';
//	}
//	return 0;
//}


//int main()
//{
//	string s = "hello";
//	for(char ch:s)
//	{
//		cout << ch << ' ';
//	}
//	return 0;
//}





//int main()
//{
//
//    double num1 = 0.0 / 0.0;  // ���� NaN
//    double num2 = 1.0 / 0.0;  // ���� Infinity
//
//    cout << "NaN as string: " << to_string(num1) << endl;  // �����nan
//    cout << "Infinity as string: " << to_string(num2) << endl;  // �����inf
//
//    return 0;
//
//}

//int main()
//{
//	string str = "Dante 798";
//	string s = " and";
//	
//	str.insert(5,s);  
//	cout << str << endl;  //����string����Ҫ���뵥���ַ�ʱ��string�ھʹ洢�����ַ� 
//
//	str = "Dante 798";
//	str.insert(0,"Hello ");  //����C���Է����ַ��� 
//	cout << str << endl;
//	
//	str = "Dante 798";
//	str.insert(3,5,'x');  //��"Dan"�������5��'x' 
//	cout << str << endl;
//	str = "Dante 798";
//	
//	string sub_str = "Hello world!";   //��Ҫ��"world"����"Dan"���� 
//	str.insert(3,sub_str,6,5);  //��"Hello world!"���±�6��ʼ�����ȡ5������ 
//	cout << str << endl;
//	return 0;
//}


//int main() {
//    string str = "Hello";
//
//    // ʹ��ͳһ�ӿڱ���
//    for (string::iterator it = str.begin(); it != str.end(); ++it) //�����string::iterator���Ϳ���д��auto���ó����Լ��ж�����
//    {
//        cout << *it << " ";
//    }
//    cout << endl;
//
//    return 0;
//}

//int main()
//{
// string str = "abcdef"; 
// cout << str << endl;
// for(string::iterator it = str.begin();it<str.end();++it)
// {
// 	*it = 'x';
// 	cout << *it;
// }
// cout << endl;
// return 0;
//}

//int main() {
//    using StringIterator = std::string::iterator;  // Ϊ std::string::iterator ��������
//
//    std::string str = "Hello, World!";
//    for (StringIterator it = str.begin(); it != str.end(); ++it) {
//        std::cout << *it << " ";
//    }
//
//    return 0;
//}

// Merry Christmas
