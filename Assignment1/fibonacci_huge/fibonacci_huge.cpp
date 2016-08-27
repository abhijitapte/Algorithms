#include <iostream>
#include <vector>

long long get_fibonacci_huge(long long n, long long m) {
  //write your code here
        if (n <= 1)
                return n;

        std::vector<long long> fibList;

        fibList.push_back(0);
        fibList.push_back(1);
	
	long long pisanoPeriodLength = 0;
	long long msquare = m*m;
	long long i = 2;

	while(1)
	{
		if (i> 2 && fibList[i-1] == 0 && fibList[i-2] == 1)
		{
			pisanoPeriodLength = i-1;
			break; // no further computations
                }
		long long fib = (fibList[i-1] + fibList[i-2])%m;
		fibList.push_back(fib);
		i++;
	}

        int fibValue = fibList[n%pisanoPeriodLength];

        return fibValue;


  return 0;
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge(n, m) << '\n';
}
