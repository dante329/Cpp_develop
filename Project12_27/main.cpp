#include <iostream>
#include <string>
using namespace std;



//���ֵ����⴦��ʽ����string���գ�stoi����� 
//int main()
//{
//	string str;
//	cin >> str;
//	for(int i=0;i<str.size();++i)
//	{
//		if(str[i]%2 == 0)
//			str[i] = '0';
//		else
//			str[i] = '1';
// 	}
// 	cout << stoi(str) << endl;
//	return 0;
// } 

//�ַ����ӷ����� 
//int main()
//{
//	string str = "123";
//	string s1 = str + char(1);
//	cout << s1 << endl;
//	s1 = str + char(97);
//	cout << s1 << endl;
//	s1 = str + char(49);
//	cout << s1 << endl;
//	s1 = str + char(999);
//	cout << s1 << endl;
//	cout << endl;
//	
//	string s2 = str + to_string(1);
//	cout << s2 << endl;
//	cout << endl;
//	
//	char ch_arr[] = "abcdef"; 
//	string s3 = str + ch_arr;
//	cout << s3 << endl;
//	cout << endl;
//		
//	string s4 = str + "csdn";
//	cout << s4 << endl;
//		
//	return 0;
//}

//�ƶ�����  TLE 
//void moveLeft(int arr[], int dest, int n) {
//    // �� arr[dest] �Ƶ���ǰ��
//    int temp = arr[dest];
//    for (int i = dest; i > 1; --i) {
//        arr[i] = arr[i - 1];  // ����
//    }
//    arr[1] = temp;  // �� arr[dest] �ŵ���ǰ��
//}
//
//void moveRight(int arr[], int dest, int n) {
//    // �� arr[dest] �Ƶ������
//    int temp = arr[dest];
//    for (int i = dest; i < n; ++i) {
//        arr[i] = arr[i + 1];  // ����
//    }
//    arr[n] = temp;  // �� arr[dest] �ŵ������
//}
//
//int main() {
//    int n, m;
//    cin >> n >> m;
//    
//    int arr[n + 1];  // ����һ�����飬������ 1 �� n
//    for (int i = 1; i <= n; ++i) {
//        arr[i] = i;  // ��ʼ��Ϊ 1, 2, ..., n
//    }
//
//    while (m--) {
//        char input;  // ���������� 
//        int dest;    // ������ 
//        cin >> input >> dest;
//
//        switch(input) {
//            case 'L':  // ���Ʋ���
//                moveLeft(arr, dest, n);
//                break;
//            case 'R':  // ���Ʋ���
//                moveRight(arr, dest, n);
//                break;
//        }
//    }
//
//    // ��������������
//    for (int i = 1; i <= n; ++i) {
//        cout << arr[i] << ' ';
//    }
//
//    return 0;
//}


//������ WA
//����ֱ�ӽ��� 
//void Swap(int* p1 ,int* p2)
//{
//	int tmp = *p1;
//	*p1 = *p2;
//	*p2 = tmp;
//}
//
//int main()
//{
//	int n,m;
//	//��һ�ж�ȡ��� 
//	cin >> n >> m;
//	int arr[n+1];
//	//��ʼ��Ϊ1��2��3��4������n 
//	for(int i=1;i<=n;++i)
//	{
//		arr[i] = i;
//	}
//	while(m--)
//	{
//		char input;  //���������� 
//		int dest;  //������ 
//		cin >> input >> dest;
//		switch(input)
//		{
//			case 'L':
//				{
//					Swap(&arr[1],&arr[dest]);
//					break;
//				}
//			case 'R':
//				{
//					Swap(&arr[n],&arr[dest]);
//					break;
//				}
//		 } 	
//	}
//	for(int a=1;a<=n;++a)
//	{
//		cout << arr[a] << ' ';
//	}
//	return 0;
//}



//������ 
//int main()
//{
//	int n,m;
//	//��һ�ж�ȡ��� 
//	cin >> n >> m;
//	string arr;
//	//��ʼ��Ϊ1��2��3��4������n 
//	for(int i=0;i<n;++i)
//	{
//		arr += to_string(i);
//	}
//	while(m--)
//	{
//		char input;  //���������� 
//		string dest;  //������ 
//		cin >> input >> dest;
//		switch(input)
//		{
//			case 'L':
//				{
//					arr = dest + arr;
//					break;
//				}
//			case 'R':
//				{
//					arr = arr + dest;
//					break;
//				}
//		 } 	
//	}
//	for(int a=0;a<n;++a)
//	{
//		cout << arr[a] << ' ';
//	}
//	return 0;
//}

// P5734
//int main() 
//{
//	string str;
//	int q;
//	cin >> q >> str;	
//	while(q--)
//	{
//		int input = 0;
//		cin >> input;
//		switch(input)
//		{
//			case 1:
//			{
//				string s;
//				cin >> s;
//				str += s;
//				cout << str << endl;
//				break;
//			}	
//			case 2:
//			{
//				int a,b;
//				cin >> a >> b;
//				str = str.substr(a,b);
//				cout << str << endl;
//				break;
//			}
//			case 3:
//			{
//				string s;
//				int a;
//				cin >> a >> s;
//				str.insert(a ,s);
//				cout << str << endl;
//				break;
//			}
//			case 4:
//			{				
//				string s;
//				cin >> s;
//				int index = str.find(s);
////				if(index != string::npos)
////				{
////				    cout << index << endl;
////				}
////				else
////				{
////				    cout << -1 << endl;
////				}
//				cout << index << endl;
//			}
//		}
//	}
//	
//	return 0;
//}
