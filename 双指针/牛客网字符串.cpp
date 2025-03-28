#include<iostream>
using namespace std;
string s;
int mp[26];
int kind;
int main()
{
	cin >> s;
	int left = 0,right = 0;
	int len = s.size();
	int ret = len;
	while(right < len)
	{
		if(mp[s[right] - 'a']++ == 0) kind++;
		while(kind == 26)
		{
			int n = right - left + 1;
			if(ret > n) ret = n;
			if(mp[s[left++] - 'a']-- == 1) kind--;
		}
		right++;
	}
	cout << ret << endl;
	return 0;
}
