#include <iostream>
#include <chrono>


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
	
	using namespace std::chrono;
	auto begin = high_resolution_clock::now() ;

	long long nthFib = FibRecurs(n);
	std::cout << n << "th Fibonacci number is: " << nthFib << std::endl;
	
	auto end = high_resolution_clock::now();
	auto ticks = duration_cast<microseconds>(end-begin);
	
    	std::cout << "It took me " << ticks.count()/1000000.0 << " seconds.\n" ;

	return 0;
}

