#include <iostream>
#include <vector>
using std::vector;


int fibonacci_sum(long long n) {
  //write your code here
  
        if (n <= 1)
                return n;

	int m = 10; // modulo 10

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

//	std::cout << "pisanoPeriodLength = " << pisanoPeriodLength << std::endl;

        int fNPlus2 = fibList[(n+2)%pisanoPeriodLength];
	if (fNPlus2 == 0)
		fNPlus2 = m;
	int sum = fNPlus2 - 1;
	return sum;
}



long long get_fibonacci_partial_sum(long long n, long long m) {
#if 0
  vector<int> f(n + 1, 0);
  f.at(0) = 0;
  f.at(1) = 1;
  for (long long i = 2; i <= n; ++i)
    f.at(i) = (f.at(i-1) + f.at(i-2)) % 10;

  int result = 0;
  for (long long i = m; i <= n; ++i)
    result += (result + f.at(i)) % 10;
#endif

	int fromSum = fibonacci_sum(n-1);
	int toSum = fibonacci_sum(m);
	
	int result = (toSum - fromSum + 10) % 10;

  return result;
}

int main() {
    long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum(from, to) << '\n';
}
