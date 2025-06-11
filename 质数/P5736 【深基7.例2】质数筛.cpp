#include <iostream>

using namespace std;

int n;

bool isprime(int a)
{
	if(a <= 1) return false;
	
	for(int i=2;i<=a/i;i++)
	{
		if(a % i == 0) return false;
	}

	return true;
}

int main() 
{
	cin >> n;
	for(int i=1;i<=n;i++)
	{
		int a; cin >> a;
		if(isprime(a)) cout << a << " "; 
	}
	
	return 0;
}
