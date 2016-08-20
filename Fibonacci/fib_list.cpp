#include <iostream>
#include <vector>

long long FibList(int n)
{
	std::vector<long long> fibList(n, 0);
	fibList[0] = 0;
	fibList[1] = 1;
	for (int i = 2; i < n; i++)
		fibList[i] = fibList[i-1] + fibList[i-2];

	return fibList[n-1];
}


int main(void)
{
	int n;
	std::cout << "Enter the value of n: ";
	std::cin >> n;

	std::cout << n << "th Fibonacci number is: " << FibList(n) << std::endl;

	return 0;
}


