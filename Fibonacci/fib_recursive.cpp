#include <iostream>


long long FibRecurs(int n)
{

	if (n <= 1)
		return n;
	else
		return FibRecurs(n-1) + FibRecurs(n-2);
}

int main(void)
{
	int n;
	
	std::cout << "Enter the value of n: ";
	std::cin >> n;
	
	long long nthFib = FibRecurs(n);
	std::cout << n << "th Fibonacci number is: " << nthFib << std::endl;
	
	return 0;
}

