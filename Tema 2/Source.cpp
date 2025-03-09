#include <iostream>
using namespace std;

long long FunctInficatoareEuler(long long n)
{
	long long r = n, p = 2;
	while (p * p <= n)
	{
		if (n % p == 0)
		{
			while (n % p == 0)
				n = n / p;
			r = r - r / p;
		}
		if (p == 2) p++;
		else p = p + 2;
	}
	if (n > 1)
		r = r - r / n;
	return r;
}

int main()
{
	long long n;
	cout << "Dati numarul ";
	cin >> n;
	cout << "phi(" << n << ")= " << FunctInficatoareEuler(n);
	return 0;
}