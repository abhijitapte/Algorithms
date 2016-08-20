#include <iostream>

#include <chrono>

#include <map>

typedef std::map<int, int> NumberComputationMap;
NumberComputationMap g_computationMap;

long long FibRecurs(int n)
{
	g_computationMap[n]++;

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

	for (int i = 1; i <= n; i++)
		g_computationMap.insert(std::pair<int, int>(i, 0));

	using namespace std::chrono;
	auto begin = high_resolution_clock::now() ;

	long long nthFib = FibRecurs(n);
	std::cout << n << "th Fibonacci number is: " << nthFib << std::endl;
	
	auto end = high_resolution_clock::now();
	auto ticks = duration_cast<microseconds>(end-begin);
	
    	std::cout << "It took me " << ticks.count()/1000000.0 << " seconds.\n" ;

	std::cout << "Table of number of computations of each intermediate Fibonacci number" << std::endl;
	std::cout << "======================\n";
	std::cout << "Number	Computations\n";
	std::cout << "======================\n";
	std::for_each(
		g_computationMap.begin(),
		g_computationMap.end(),
		[](const NumberComputationMap::value_type& val) {
			std::cout << val.first << "\t" << val.second << std::endl;
		});

	return 0;
}

