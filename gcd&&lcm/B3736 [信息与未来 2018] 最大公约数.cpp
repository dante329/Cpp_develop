#include <iostream>

using namespace std;

int x,y,z;

int gcd(int x,int y)
{
	return y == 0 ? x : gcd(y,x % y);
}

int main() 
{
	cin >> x >> y >> z;
	
	cout << gcd(gcd(x,y),z);
	
	return 0;
}
