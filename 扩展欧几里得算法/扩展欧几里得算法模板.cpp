//��ax+by = gcd(a,b)������ͨ�� 
LL exgcd(LL a, LL b, LL& x, LL& y)
{
	if(b == 0) //�ݹ���� 
	{
		x = 1;
		y = 0;
		return a;
	}
	
	//��b��Ϊ0ʱ�����ݵ��ƹ�ϵ����һ���x1��y1ȷ����ǰ���x��y��ֱ��bΪ0ʱһ��һ�㷵�صõ�����ʽ�ӵ��ؽ�
	
	//������һ���x1��y1 
	LL x1, y1, d;	
	d = exgcd(b, a % b, x1, y1);
	//��ǰ���x��y 
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
