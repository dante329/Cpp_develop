#include <iostream>
using namespace std;

////1.判断奇偶数 
//int main()
//{
//	int n;
//	cin >> n;
//	if((n&1)==1)  //要注意运算符的优先性，不加括号就会先执行==比较运算符 
//		cout << "奇数";
//	else
//		cout << "偶数";  
//	return 0;
//}

////2.保留二进制中的指定位 （保留取出来的指定位的数值，其他位为0） 
//#include <cmath>
//int main()
//{
//	int n=0;
//	for(int i=pow(2,0);i<=pow(2,4);i*=2) 
//	{
//		n+=i;
//	}
//	cout << n << endl;
//	int a=0;
//	cin >> a;
//	a &= n; //保留对应位 
//	cout << a << endl;
//	return 0;
//}

//3.将二进制中的某一位或者几位设置为1，将那几位|1即可 

////4.获取二进制中的指定位，也可以理解成上一条中只保留某一位 
////方法：需要哪一位就把那一位右移到第0位上，然后再&1 ，即 (x >> i) & 1
//#include<bitset>
//int main()
//{
//	int n = 0b10011;
//	int a = (n>>4)&1; //获取n的第四位 
//	cout << bitset<8>(n) << endl; //std::bitset<32> 表示将整数按 32 位二进制形式表示。
//	cout << a << endl;
//	return 0;
//}

//5.将指定二进制位设置为0
//方法：我们知道一个二进制位只要&0结果肯定为0，所以我们先将1左移到指定的位，然后将整个数字取反就得到了11110111这样的序列，再与被操作数&即可 
//x &= ~(1<<i)

//6.将指定二进制位反转（0变1，1变0）
//方法：利用异或，相同为0，不同为1的特点
//可以使用另一个数 m ，使得 m 的二进制中第 i 位为1 ，其余位置为 0 。然后令两个数进行按位异或运算（ x ^ m ）

//7.将二进制中最右边的1变成0 ， x = x&(x-1) 

//8.只保留二进制位中最右边的1，x & -x
//正数的原反补相同，当x取负之后，-x的补码会相比于x的补码发生改变 ，而这个变化正好是与原来的二进制下序列最右边的 1位置相同，其他的1对应的位置都相反 
