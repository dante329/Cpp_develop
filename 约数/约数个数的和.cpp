#include<iostream>
#include<vector>
const int N = 1e8 + 10;
int n,sum;
std::vector<int> d[N];
int main()
{
    std::cin >> n;
    for(int i=1;i<=n/2;i++)
    {
        sum += n/i;
    }
    sum += n - n/2; //·ÀÆæÊý
    std::cout << sum;
}
