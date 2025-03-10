#include<iostream>
#include<map>

using namespace std;

void print(map<string,int>& mp)
{
	for(auto& x:mp)
	{
		cout << "姓名:" << x.first << " " << "值：" << x.second << endl; 
	}
}

int main()
{
	map<string,int> mp; //k-v
	
	mp.insert({"王誉皓",1});
	mp.insert({"左晋儒",2});
	mp.insert({"老弟",3});
	
	print(mp); //打印map 
	
	//重载 [] ，使得 map可以像数组那样使用。
	cout << mp["老弟"] << endl;
	mp["老弟"] = 1e5;
	cout << mp["老弟"] << endl;
	
	cout << "查询猪毛前的map：" << endl << endl;
	print(mp);
	
	//像这样用[]查询一个map中没有的key时，会先插入map，然后再查询
	//插入的内容：key就是括号里的内容，value就是默认值 
	cout << "猪毛的值：" ;  
	cout << mp["猪毛"] << endl << endl;
	 
	cout << "查询猪毛后的map：" << endl;
	print(mp);
	
	mp.erase("猪毛"); //删除只用传入key值
	 
	//为了防止以上这种情况发生，我们在用中括号的时候先判断有没有这个元素
	if(mp.count("猪毛")) cout << mp["猪毛"] << endl;
	else cout << "no" << endl;
	
	if(mp.count("王誉皓") && mp["王誉皓"] == 1) cout << "yes" << endl;
	else cout << "no" << endl;
	return 0;
}
