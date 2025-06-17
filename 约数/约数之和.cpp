#include<iostream>
using namespace std;
int ret,n;
int main()
{
    cin >> n;
    for(int i=1;i<=n/i;i++)
    {
        if(n % i == 0) 
        {
            ret += i;
            if(i != n/i) ret += n/i;
        }
    }
    
    cout << ret;
    return 0;
}
