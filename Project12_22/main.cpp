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
//    // ���� S �� T��Ѱ�� T �дӵ�һ���ַ���ʼ�������������
//    while (i < lenS && j < lenT) {
//        if (S[i] == T[j]) {
//            j++;  // �ҵ�ƥ����ַ���T[j] ƥ��ɹ�
//        }
//        i++;  // �����Ƿ�ƥ�䣬i ����Ҫ����
//    }
//
//    // ��������j ���ƥ��ĳ���
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
//	    // ��ʼ���Ƶ�״̬��0��ʾ����1��ʾ��
//	    int arr[n];
//	    memset(arr, 0, sizeof(arr));
//	
//	    // ģ��ÿ���˵Ĳ���
//	    for (int i = 0; i < n; ++i) {
//	        for (int j = i; j < n; j += (i + 1)) {
//	            // ��ת�Ƶ�״̬
//	            arr[j] = !arr[j];
//	        }
//    }
//	int count = 0;
//    // ������ŵĵƱ�ţ�0��ʾ����1��ʾ�أ�
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
//int ch2[26] = {0}; // Сд��ĸƵ������
//
//int main() {
//    cin >> ch1;
//
//    // ͳ��ÿ����ĸ�ĳ��ִ���
//    for (int i = 0; ch1[i]; ++i) {
//        ch2[ch1[i] - 'a']++;
//    }
//
//    // �������ַ���˳����ҵ�һ��ֻ����һ�ε��ַ�
//    for (int i = 0; ch1[i]; ++i) {
//        if (ch2[ch1[i] - 'a'] == 1) {
//            cout << ch1[i] << endl; // �����һ�������������ַ�
//            return 0; // �ҵ���ֱ���˳�
//        }
//    }
//
//    // ���û���ҵ������ "no"
//    cout << "no" << endl;
//    return 0;
//}


//���ҵ�һ��������һ�ε��ַ�ʱ��û�а��������ַ�����˳������жϣ�
//���ǰ�����ĸ��˳�򣨴� a �� z������ ch2 ���顣��ᵼ�´�������
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
