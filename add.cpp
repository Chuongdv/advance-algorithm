#include <iostream>
using namespace std;
int main()
{

	unsigned long long int a, b,a1,a2,b1,b2;
	unsigned long long int t;
	cin >> a;
	cin >> b;
	t = a + b;

	if ((t<a)||(t<b))
	{
		a1 = a / 1000;
		b1 = b / 1000;
		a2 = a % 1000;
		b2 = b % 1000;
		t = a2 + b2;
		if (t > 1000)
		{
			int k = a1 + b1 + 1;
			cout << k;
			cout << (t % 1000);
		}
		else if (t == 1000)
		{
			int k = a1 + b1 + 1;
			cout << k;
			cout << "000";
		}
		else
		{
			cout << (a1+b1);
		//	cout << t;
		}
	}
	else {
		cout << t;
	}


}
