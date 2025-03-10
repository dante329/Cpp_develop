#include<iostream>
#include<set>

using namespace std;

int a[] = {10, 60, 20, 70, 80, 30, 90, 40, 100, 50};

int main()
{
	set<int> mp1;
	set<string> mp2;
	
	//将数组a中的所有元素添加到mp1中
	for(int x:a)
	{
		mp1.insert(x);
	}
	//mp1是一颗红黑树，所以mp1的中序遍历是升序的 
	for(auto x:mp1)
	{
		cout << x << " ";
	 } 
	cout << endl;
	
	if(mp1.count(1)) cout << "1" << endl;
	if(mp1.count(10)) cout << "10" << endl;
	if(mp1.count(30)) cout << "30" << endl;
	
	mp1.erase(10);
	mp1.erase(30);
	
	if(mp1.count(10)) cout << "10" << endl;
	else cout << "no" << endl;
	if(mp1.count(30)) cout << "30" << endl;
	else cout << "no" << endl;
	
	auto x = mp1.lower_bound(20);
	auto y = mp1.upper_bound(20);
	
	cout << *x << " " << *y << endl;
	
	return 0;
 } 
