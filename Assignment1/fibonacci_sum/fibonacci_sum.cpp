#include <iostream>
#include <vector>

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

int main() {
  long long n = 0;
  std::cin >> n;
  std::cout << fibonacci_sum(n);
}
