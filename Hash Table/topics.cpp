//��ϣ�����Ƕ���ͬԪ����ȥ�����õ�
//�����ͳ����ͬԪ���ۼƳ��ֵĴ�����������unordered_map<Ԫ������,int> mp��ÿ��������ͬ��a��mp[a]++�Ϳ���ͳ���ظ����� 
#include<iostream> 
#include<unordered_map>
using namespace std;
unordered_map<string,int> mp;

string name;
int score;

int main()
{
	int n; cin >> n;
	while(n--)
	{
		int op; cin >> op;
		switch(op)
		{
			case 1:
				cin >> name >> score;
				mp[name] = score; //û�о��½�Ȼ��ֵ 
				cout << "OK" << endl;
				break;
			case 2:
				cin >> name;
				if(mp.find(name) != mp.end()) cout << mp[name] << endl;
				else cout << "Not found" << endl;
				break;
			case 3:
				cin >> name;
				if(mp.find(name) != mp.end()) 
				{
					mp.erase(name);
					cout << "Deleted successfully" << endl;
				}
				else cout << "Not found" << endl;
				break;
			case 4:
				cout << mp.size() << endl;				
		}
	}
	
	return 0;
 } 
