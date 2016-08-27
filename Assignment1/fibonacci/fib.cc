#include <iostream>

#if 0
int calc_fib(int n) {
    if (n <= 1)
        return n;

    return calc_fib(n - 1) + calc_fib(n - 2);
}
#endif

int calc_fib(int n)
{
#if 0
	std::vector<int> fibList(n, 0);
#endif

	if (n <= 1)
		return n;

	int *fibList = new int [n+1];
	for (int i = 0; i <= n; i++)
		fibList[i] = 0;

	fibList[0] = 0;
	fibList[1] = 1;
	for (int i = 2; i <= n; i++)
		fibList[i] = fibList[i-1] + fibList[i-2];
	
	int fibValue = fibList[n];

	delete [] fibList;

	return fibValue;
}



int main() {
    int n = 0;
    std::cin >> n;

    std::cout << calc_fib(n) << '\n';
    return 0;
}
