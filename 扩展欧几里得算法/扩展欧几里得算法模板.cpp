//求ax+by = gcd(a,b)的整数通解 
LL exgcd(LL a, LL b, LL& x, LL& y)
{
	if(b == 0) //递归出口 
	{
		x = 1;
		y = 0;
		return a;
	}
	
	//当b不为0时，根据递推关系由下一层的x1、y1确定当前层的x、y，直到b为0时一层一层返回得到整个式子的特解
	
	//先求下一层的x1、y1 
	LL x1, y1, d;	
	d = exgcd(b, a % b, x1, y1);
	//求当前层的x，y 
	x = y1;
	y = x1 - a / b * y1;
	
	return d;
}
x
{
	LL a, b, x, y;
	int d = exgcd(a, b, x, y);	
	cout << x << " " << y;	
	return 0;
} 
