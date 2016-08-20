#Fibonacci Numbers

Fibonacci numbers can be summarized by the following relation
```
  F(0) = 0
  F(1) = 1
  F(n) = F(n-1) + F(n-2)
```

The following relation gives the formula for calculating the nth term of Fibonacci number.
![nth term](https://github.com/abhijitapte/Algorithms/blob/master/Fibonacci/nth-Term.png)

The [proof][Fibonacci relation proof] for the same can be obtained by solving recurrence relation.
The notes by Prof. William Chen is a nice read on [Recurrence relations][Recurrence relations].

## Slower recursive version

### The Algorithm

Naturally, the relation defined above will tempt anyone to first attempt write a recursive solution. This [Recursive Fibonacci version] will do the following:
```
long long FibRecurs(int n)
{
	if (n <= 1)
		return n;
	else
		return FibRecurs(n-1) + FibRecurs(n-2);
}

```

But this computation is very slow. In order to analyze how slow it is, let's first add the timing measurements. 

### Timing measurements

If we were to time our implementation, we have to capture two time snapshots, the `start` and the `end`, one before invoking the `FibRecurs` and one after.
Thereafter, we take the difference between the two.
```
	auto begin = high_resolution_clock::now();
	// the code to be measured goes here
	// ...
	auto end = high_resolution_clock::now();
```

The [revised program][Timing measurements] uses `high_resolution_clock::now()` defined in `<chrono>`. This will return time in microseconds.

The program was tested on `Apple MacBook Air` with 1.3GHz processor.
```
$ sysctl -n machdep.cpu.brand_string
Intel(R) Core(TM) i5-4250U CPU @ 1.30GHz
```

The algorithm runs miserably even if it were asked to calculate Fibonacci numbers for moderately sized input. A capture of running this program with various inputs is as below:
```
$ ./a.out 
Enter the value of n: 35
35th Fibonacci number is: 9227465
It took me 0.100344 seconds.

$ ./a.out 
Enter the value of n: 40
40th Fibonacci number is: 102334155
It took me 1.01347 seconds.

$ ./a.out 
Enter the value of n: 41
41th Fibonacci number is: 165580141
It took me 1.64344 seconds.

$ ./a.out 
Enter the value of n: 42
42th Fibonacci number is: 267914296
It took me 2.67049 seconds.

$ ./a.out 
Enter the value of n: 43
43th Fibonacci number is: 433494437
It took me 4.28299 seconds.

$ ./a.out 
Enter the value of n: 44
44th Fibonacci number is: 701408733
It took me 6.87272 seconds.

$ ./a.out 
Enter the value of n: 45
45th Fibonacci number is: 1134903170
It took me 11.0777 seconds.

$ ./a.out 
Enter the value of n: 46
46th Fibonacci number is: 1836311903
It took me 17.9435 seconds.

$ ./a.out 
Enter the value of n: 47
47th Fibonacci number is: 2971215073
It took me 29.0247 seconds.

$ ./a.out 
Enter the value of n: 48
48th Fibonacci number is: 4807526976
It took me 47.1092 seconds.

$ ./a.out 
Enter the value of n: 49
49th Fibonacci number is: 7778742049
It took me 78.4121 seconds.

$ ./a.out 
Enter the value of n: 50
50th Fibonacci number is: 12586269025
It took me 129.322 seconds.
```

It should come as no surprise having these numbers, you can pretty much guess time this program could take to solve for `n=100` i.e., the `100th` Fibonacci number.
That's very slow indeed.

Let us now go under the hood to find out what's really happening wrong.
Let the number of lines of code to be executed to compute `nth` Fibonacci number be `T(n)`.
Then from the code, 2 lines are required for `n <= 1`, however for computing Fibonacci number `n > 1` is given by: `T(n) = 3 + T(n-1) + T(n-2)`. This is fairly similar to the Fibonacci sequence relation and intuitively, `T(n) >= F(n)`.
Considering we are running this program on a 1GHz processor (1E9) and considering `F(100)` is approximately `1.77E21`, it would take more than `56000 years` to wait for output on the console!

### Unnecessary computations

The computations of intermediate Fibonacci numbers are unoptimal. In order to demonstrate this, we consider storing the number of computations in a map in the [revised version][Computations].
This map holds pairs where keys are the intermediate Fibonacci numbers and the values represent the number of times the result has been computed. 
This map is initialized by adding all numbers `1 to n` and setting the corresponding values to zeroes. To simplify a global map variable is used and the corresponding entry in the map for which the value is being computed is incremented at the beginning of the `FibRecurs` method.
The following output shows the number of computations of intermediate numbers:
```
$ ./a.out 
Enter the value of n: 35
35th Fibonacci number is: 9227465
It took me 1.36375 seconds.
Table of number of computations of each intermediate Fibonacci number
======================
Number	Computations
======================
0       5702887
1	    9227465
2	    5702887
3	    3524578
4	    2178309
5	    1346269
6	    832040
7	    514229
8	    317811
9	    196418
10	    121393
11	    75025
12	    46368
13	    28657
14    	17711
15    	10946
16    	6765
17	    4181
18	    2584
19	    1597
20	    987
21	    610
22	    377
23	    233
24	    144
25	    89
26	    55
27	    34
28	    21
29    	13
30    	8
31    	5
32    	3
33    	2
34    	1
35    	1

```

Obviously, the repeated computations are really slowing down the program. 

  [Recursive Fibonacci version]: <https://github.com/abhijitapte/Algorithms/blob/master/Fibonacci/fib_recursive.cpp>
  [Timing measurements]: <https://github.com/abhijitapte/Algorithms/blob/master/Fibonacci/fib_recursive_time.cpp>
  [Computations]: <https://github.com/abhijitapte/Algorithms/blob/master/Fibonacci/fib_recursive_time_computations.cpp>
  [Fibonacci relation proof]: <http://pages.pacificcoast.net/~cazelais/222/rec.pdf>
  [Recurrence relations]: <https://rutherglen.science.mq.edu.au/wchen/lndmfolder/dm16.pdf>
