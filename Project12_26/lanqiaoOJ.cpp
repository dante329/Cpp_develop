#include <iostream>
#include <string>
#include <climits>
using namespace std;

//12.26�ڶ��� AC
//bool is_prime(int n)
//{
//	for(int i=2;i*i<n;++i)
//	{
//		if(n%i==0)
//			return false;
//	}
//	return true;
//		
//}
//
//
//bool is_prime(int n) {
//    if (n <= 1) return false;
//    if (n == 2) return true;  
//    if (n % 2 == 0) return false; 
//    for (int i = 3; i * i <= n; i += 2) {
//        if (n % i == 0) return false;
//    }
//    return true;
//}
//
//int main()
//{
//	string str;
//	getline(cin,str);
//	int sta[26] = {0};
//	int maxn=0,minn=INT_MAX;
//	for(char ch:str)
//	{
//		sta[ch-'a']++;
//	}
//	for(int i=0;i<26;++i)
//	{
//		if (sta[i] > 0)
//		{
//			maxn = max(sta[i],maxn);
//			minn = min(sta[i],minn);
//		}
//		
//	}
//	if(is_prime(maxn-minn))
//	{
//		cout << "Lucky Word" << endl;
//		cout << maxn-minn << endl;
//	}	
//	else
//	{
//		cout << "No Answer" << endl;
//		cout << "0" << endl;
//	}
//	return 0;
//}

//bool is_prime(int n)
//{
//	for(int i=2;i*i<n;++i)
//	{
//		if(n%i==0)
//			return false;
//	}
//	return true;
//		
//}

//12.26�ڶ��� �ݸ壨WA�� 
//bool is_prime(int n) //�ǳ�����������ж� 
//{
//	int count=1;
//	for(int i=2;i<=n;++i) //�Ż����жϵ�sqrt(n)֮ǰ�Ϳ����ˣ������ǳɶԳ��ֵ� p1 = a , p2 = n/a 
//	{
//		if(n%i==0)
//			count++;
//	}
//	if(count == 2)
//		return true;
//	else
//		return false;
//}
//int main()
//{
//	string str;
//	getline(cin,str);
//	int sta[100] = {0};
//	int maxn=0,minn=0;  //minnҪ����Сֵ��Ҫ�ȸ�һ���ܴ��ֵ��������INT_MAX 
//	for(char ch:str)
//	{
//		sta[ch]++;
//	}
//	for(int i:sta)
//	{
//		maxn = max(i,maxn);
//		minn = min(i,minn);
//	}
//	if(is_prime(maxn-minn))
//	{
//		cout << "Lucky Word" << endl;
//		cout << maxn-minn << endl;
//	}	
//	else
//	{
//		cout << "No Answer" << endl;
//		cout << "0" << endl;
//	}
//	return 0;
//}


//int main()
//{
//	string str;
//	getline(cin,str);
//	int count1=0,count2=0;
//	for(char ch:str)
//	{
//		if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
//			count1++;
//		else
//			count2++;
//	}
//	cout << count1 <<endl << count2<< endl;
//	
//	return 0;
//}


//ͳ���������� AC 
//������ɫ��ɸ��
//int main()
//{
//	int n;
//	cin >> n;
//	bool is_prime[n+1] = { };
//	for(int i=2;i<n+1;++i)
//	{
//		is_prime[i] = true;
//	}
//	
//	for(int i=2;i*i<=n;++i) //ֻ��Ҫɸѡ������n 
//	{
//		if(is_prime[i])
//		{
//			for(int j=i*2;j<=n;j+=i)
//			{
//				is_prime[j] = false;
//			}
//		}
//	}
//	
//	int count = 0;
//	for(int i=2;i<=n;++i)
//	{
//		if(is_prime[i])
//		{
//			count++;
//		}
//	}
//	
//	cout << count << endl;
//	return 0;
//}

//ͳ���������� �ݸ� ��TLE�� 
//int main()
//{
//	int n;
//	cin >> n;
//	bool arrn[n] = { };
//	for(int i=1;i<=n;++i)
//	{	
//		if(!arrn[i])
//		{
//			int count = 0;
//			for(int j=1;j<=i;++j)
//			{
//				if(j%i==0)
//					count++;
//			}
//			if(count == 2)
//			{
//				for(int a=i;a<n;a*=2)
//				{
//					arrn[a] = true;
//				}
//			}
//		}
//	}
//	  
//	
//	return 0;
//}


//int main()
//{
//	int n;
//	cin >> n;
//	int sum = 0;
//	for(int i=1;i<=n;++i)
//	{
//		int count =0;
//		for(int j=1;j<=i;++j)
//		{
//			if(i%j==0)
//			{
//				count++;
//			}
//		}
//		if(count == 2)
//		{
//			sum++;
//		}
//	}
//	cout << sum << endl;
//	
//	return 0;
//} 

//��������  AC
//const int MAXN = 3 * 1000000; // ���Χ N
//vector<int> minPrime(MAXN + 1); // �洢ÿ��������С������
//vector<long long> prefixSum(MAXN + 1); // �洢ǰ׺��
//
//void preprocess() {
//    // ��ʼ����С����������
//    for (int i = 2; i <= MAXN; ++i) {
//        if (minPrime[i] == 0) { // ��� i ������
//            for (int j = i; j <= MAXN; j += i) {
//                if (minPrime[j] == 0) {
//                    minPrime[j] = i; // �����С������
//                }
//            }
//        }
//    }
//
//    // ����ǰ׺������
//    for (int i = 2; i <= MAXN; ++i) {
//        prefixSum[i] = prefixSum[i - 1] + minPrime[i];
//    }
//}
//
//int main() {
//    preprocess(); // Ԥ������С�����Ӻ�ǰ׺��
//
//    int T;
//    cin >> T;
//    while (T--) {
//        int N;
//        cin >> N;
//        cout << prefixSum[N] << endl; // ��ѯǰ׺��
//    }
//
//    return 0;
//}

//�������� (TLE)
//int Fun(int n)
//{
//	if(n<=1)
//	{
//		return -1;
//	 } 
//	
//	for(int i=2;i<=sqrt(n);++i)
//	{
//		if(n%i==0)
//			return i;
//	}
//	return n;//n���������� 
//}
//
//int main() 
//{
//	int t;
//	cin >> t;	
//	while(t--)
//	{
//		int n;
//		cin >> n;
//		int sum = 0;	
//		for(int i=2;i<=n;++i)
//		{
//				sum += Fun(i);	
//		}
//		cout << sum << endl; //ÿ�����������Ҫ��ӡ 
//	}	
//	
//	return 0;
//}
