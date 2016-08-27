#include <iostream>

int gcd(int a, int b)
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

int main(void)
{
	int a;
	int b;
	std::cin >> a >> b;
	std::cout << "gcd: " << gcd(a, b) << std::endl;
	return 0;
}

