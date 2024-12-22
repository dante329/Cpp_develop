#include <bits/stdc++.h>
using namespace std;

//int main()
//{
//	string s1;
//	getline(cin,s1);//<string.h>
//	getline(cin,s1,'c');
//	cout << s1;
//	return 0;
//}

//int main() {
//    string S, T;
//    cin >> S >> T;
//
//    int i = 0, j = 0;
//    int lenS = S.size(), lenT = T.size();
//
//    // 遍历 S 和 T，寻找 T 中从第一个字符开始的最长连续子序列
//    while (i < lenS && j < lenT) {
//        if (S[i] == T[j]) {
//            j++;  // 找到匹配的字符，T[j] 匹配成功
//        }
//        i++;  // 不论是否匹配，i 都需要增加
//    }
//
//    // 输出结果：j 是最长匹配的长度
//    cout << j << endl;
//    return 0;
//}

//int main()
//{
//	string s,t;
//	cin >> s >> t;
//	int count = 0;
//	for(int i=0;i<s.size();++i)
//	{		
//		if(s[i]==t[count]&&count<t.size())
//		{
//			count++;
//		}			
//	} 
//	cout << count <<endl; 
//	
//	return 0;
//}


//int main()
//{
//	int round;
//	cin >> round;
//	while(round--)
//	{
//		int n;
//	    cin >> n;
//	
//	    // 初始化灯的状态，0表示开，1表示关
//	    int arr[n];
//	    memset(arr, 0, sizeof(arr));
//	
//	    // 模拟每个人的操作
//	    for (int i = 0; i < n; ++i) {
//	        for (int j = i; j < n; j += (i + 1)) {
//	            // 反转灯的状态
//	            arr[j] = !arr[j];
//	        }
//    }
//	int count = 0;
//    // 输出关着的灯编号（0表示开，1表示关）
//    for (int i = 0; i < n; ++i) {
//        if (arr[i] == 1) {
//            count++;
//        }
//    }
//    cout << count;
//	}
//	
//	return 0;
//}

//const int N = 1110;
//char ch1[N];
//int ch2[26] = {0};
//
//int main()
//{
//    cin >> ch1;
//    int i=0;
//    while(ch1[i])
//    {
//    	ch2[ch1[i]-'a'] += 1;
//    	++i;
//	}
//	int flag =0;
//	for(int j=0;ch1[j];++j)
//	{
//		if(ch2[ch1[j]-'a']==1)
//		{
//			flag=1;
//			cout << (char)(j+'a');
//			return 0;
//		}
//	}
//	cout << "no";
//    return 0;
//}

//const int N = 1110;
//char ch1[N];
//int ch2[26] = {0}; // 小写字母频率数组
//
//int main() {
//    cin >> ch1;
//
//    // 统计每个字母的出现次数
//    for (int i = 0; ch1[i]; ++i) {
//        ch2[ch1[i] - 'a']++;
//    }
//
//    // 按输入字符串顺序查找第一个只出现一次的字符
//    for (int i = 0; ch1[i]; ++i) {
//        if (ch2[ch1[i] - 'a'] == 1) {
//            cout << ch1[i] << endl; // 输出第一个满足条件的字符
//            return 0; // 找到后直接退出
//        }
//    }
//
//    // 如果没有找到，输出 "no"
//    cout << "no" << endl;
//    return 0;
//}


//查找第一个仅出现一次的字符时，没有按照输入字符串的顺序进行判断，
//而是按照字母表顺序（从 a 到 z）遍历 ch2 数组。这会导致错误结果。
//const int N = 1110;
//char ch1[N];
//int ch2[26] = {0};
//
//int main()
//{
//    cin >> ch1;
//    int i=0;
//    while(ch1[i])
//    {
//    	ch2[ch1[i]-'a'] += 1;
//    	++i;
//	}
//	int flag =0;
//	for(int j=0;j<26;++j)
//	{
//		if(ch2[j]==1)
//		{
//			flag=1;
//			cout << (char)(j+'a');
//			return 0;
//		}
//	}
//	cout << "no";
//    return 0;
//}


//int main()
//{
//	char ch1[110];
//	char ch2[110];
//	cin >> ch1;
//	for(int i=0;i<strlen(ch1);++i)
//	{
//		if(i==strlen(ch1)-1)
//		{
//			ch2[i]=ch1[i]+ch1[0];
//		}
//		else
//		{
//			ch2[i]=ch1[i]+ch1[i+1];
//		}
//	}
//	cout << ch2 <<endl; 
//	return 0;
// } 

//int main() 
//{
//	int count =0;
//	double ratio;
//	char ch1[510];
//	char ch2[510];
//	cin >> ratio >> ch1 >>ch2;
//	for(int i=0;i<strlen(ch1);++i)
//	{
//		if(ch1[i]==ch2[i])
//		{
//			count++;
//		}
//	}    
//	if((double)count/strlen(ch1)>=ratio)
//	{
//		cout << "yes";
//	}
//	else
//	{
//		cout << "no";
//	}
//	
//	return 0;
//}
	


//int main() 
//{
//	int count = 0;
//	char ch[256];
//	fgets(ch,255,stdin);
//	for(int i:ch)
//	{
//		if(i>=48&&i<=57)
//		{
//			count++;
//		}
//	}
//	cout << count << endl;
//	return 0;
//}
