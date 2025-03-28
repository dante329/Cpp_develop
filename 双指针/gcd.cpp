#include<iostream>
using namespace std;
int binary_gcd(int a, int b) {
    if (a == 0) return b;
    if (b == 0) return a;
    
    // 移除公共的2因子
    int shift = __builtin_ctz(a | b);
    a >>= __builtin_ctz(a);
    
    do {
        b >>= __builtin_ctz(b);
        if (a > b) std::swap(a, b);
        b -= a;
    } while (b != 0);
    
    return a << shift;
}
int main()
{
	cout << binary_gcd(124,75);
	return 0;
 } 
