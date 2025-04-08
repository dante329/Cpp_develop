//善用全局变量和回溯 
#include <iostream>
using namespace std;
string s; //全局变量记录结果
int n; 

void dfs(int pos)
{
	if(pos > n)
	{
		cout << s << endl;
		return;
	}
	
	//不选(需要以字典序输出答案，先考虑N字典序较小)
	s += 'N';
	dfs(pos+1); //当前pos选了N之后去处理下一位，具体怎么处理先不管，等dfs写完了之后就知道了 
	s.pop_back(); //当dfs(pos+1);执行完之后，就是回溯，要将N删掉 
	//选 
	s += 'Y';
	dfs(pos+1);
	s.pop_back();
}

int main() 
{
	cin >> n;
	dfs(1);
	return 0;
}
