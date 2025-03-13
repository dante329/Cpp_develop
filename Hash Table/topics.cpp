//哈希表中是对相同元素有去重作用的
//如果想统计相同元素累计出现的次数，可以用unordered_map<元素类型,int> mp，每次遇到相同的a，mp[a]++就可以统计重复次数 
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
				mp[name] = score; //没有就新建然后赋值 
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
