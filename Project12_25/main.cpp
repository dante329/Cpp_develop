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
				max_word_index = it_pre - str.begin(); //it_pre指向的是一个单词的首字母，更新it_pre前计算并存储出这个单词首字母的下标，在输出时要用到 
			}
			it_pre = it_cur + 1; //it_cur指向的是空格 
		}	
	} 
	cout << str.substr(max_word_index,max_size);
	return 0;
}



//int main() {
//    string str;
//    getline(cin, str); // 使用 getline 读取整行输入
//
//    int size = 0;        // 当前单词长度
//    int max_size = 0;    // 最大单词长度
//    int max_word_index = 0; // 最长单词首字母索引
//    int start_index = 0; // 当前单词的首字母索引
//
//    for (int i = 0; i <= str.size(); ++i) {
//        if (i == str.size() || str[i] == ' ') { // 单词结束条件
//            size = i - start_index; // 当前单词长度
//            if (size > max_size) {  // 更新最大长度及索引
//                max_size = size;
//                max_word_index = start_index;
//            }
//            start_index = i + 1; // 更新到下一个单词的开始位置
//        }
//    }
//
//    // 输出最长单词
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
//    double num1 = 0.0 / 0.0;  // 产生 NaN
//    double num2 = 1.0 / 0.0;  // 产生 Infinity
//
//    cout << "NaN as string: " << to_string(num1) << endl;  // 输出：nan
//    cout << "Infinity as string: " << to_string(num2) << endl;  // 输出：inf
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
//	cout << str << endl;  //插入string，想要插入单个字符时，string内就存储单个字符 
//
//	str = "Dante 798";
//	str.insert(0,"Hello ");  //插入C语言风格的字符串 
//	cout << str << endl;
//	
//	str = "Dante 798";
//	str.insert(3,5,'x');  //在"Dan"后面插入5个'x' 
//	cout << str << endl;
//	str = "Dante 798";
//	
//	string sub_str = "Hello world!";   //想要将"world"插入"Dan"后面 
//	str.insert(3,sub_str,6,5);  //从"Hello world!"的下标6开始往后截取5个长度 
//	cout << str << endl;
//	return 0;
//}


//int main() {
//    string str = "Hello";
//
//    // 使用统一接口遍历
//    for (string::iterator it = str.begin(); it != str.end(); ++it) //这里的string::iterator类型可以写成auto，让程序自己判断类型
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
//    using StringIterator = std::string::iterator;  // 为 std::string::iterator 创建别名
//
//    std::string str = "Hello, World!";
//    for (StringIterator it = str.begin(); it != str.end(); ++it) {
//        std::cout << *it << " ";
//    }
//
//    return 0;
//}

// Merry Christmas
