#include <iostream>

int get_fibonacci_last_digit(int n) {
  //write your code here
	if (n <= 1)
		return n;

	int *fibList = new int [n+1];
	for (int i = 0; i <= n; i++)
		fibList[i] = 0;

	fibList[0] = 0;
	fibList[1] = 1;
	for (int i = 2; i <= n; i++)
		fibList[i] = (fibList[i-1] + fibList[i-2])%10;
	
	int fibValue = fibList[n];

	delete [] fibList;

	return fibValue;

  return 0;
}

int main() {
  int n;
  std::cin >> n;
  int c = get_fibonacci_last_digit(n);
  std::cout << c << '\n';
}
