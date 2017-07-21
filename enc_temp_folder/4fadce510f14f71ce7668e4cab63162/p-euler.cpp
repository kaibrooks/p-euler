// Kai Brooks
// Project Euler

#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <chrono>

using namespace std;
typedef chrono::high_resolution_clock Clock;

// Initalize functions
int		kill();
bool	isPrime(long a);
bool	isPalindrome(int a);

int	p1();
int	p2();
int	p3();
int	p4();
int	p5();
int	p6();
int	p7();
long long p8();


// Initialize structs
const string currentDateTime() {
	time_t     now = time(0);
	struct tm  tstruct;
	char       buf[80];
	tstruct = *localtime(&now);
	strftime(buf, sizeof(buf), "%Y-%m-%d %X", &tstruct);
	return buf;
}

// Initalize arrays

int main() {
	auto start = Clock::now();

	// Call the function associated with the problem here
	cout << p8();

	auto end = Clock::now();
	cout << endl << "Completed in " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << " ms." << endl;

	kill();
}

int kill() {
	// Kill the program
	cout << endl << "[End] " << endl;
	getchar();
	return 0;
}

// General functions used in multiple problems

bool isPrime(long a) {
	// Check if a is prime
	if (a < 3 || a % 2 == 0) {	// Exclude even numbers, 0, 1, and 2
		return 0;
	}

	if (a <= 3) {
		return a > 1;
	}
	else if (a % 2 == 0 || a % 3 == 0) {
		return 0;
	}
	else {
		for (int i = 5; i * i <= a; i += 6) {
			if (a % i == 0 || a % (i + 2) == 0) {
				return 0;
			}
		}
		return 1;
	}

}

bool isPalindrome(int a) {
	// Check if a is a palindrome
	stringstream ss;
	ss << a;
	string ssnum = ss.str();

	for (int i = 0; i < ssnum.length(); i++) {
		char x = ssnum[i];
		char y = ssnum[(ssnum.length() - 1) - i];
		if (x != y) {
			return 0;
		}
	}
	return 1;
}

// Individual problems

int p1() {
	// Sum all multiples of 3 and 5 for numbers below 1000
	int sum = 0;
	for (int i = 0; i < 1000; i++) {
		if (i % 3 == 0 || i % 5 == 0) {
			sum += i;
		}
	}
	return sum;
}

int p2() {
	// Find the sum of all even-valued Fibonacci terms, whose values < 4,000,000
	// Fibonacci sequence: 1,2,3,5,8,13,21,34,55,89... (term n = n-1 + n-2)
	int fib = 1;
	int oldfib = 0;
	int sum = 0;

	while (fib < 4000000) {
		fib = fib + oldfib;
		oldfib = fib - oldfib;

		if (fib % 2 == 0) {
			sum += fib;
		}
	}
	return sum;
}

int p3() {
	// Find the largest prime factor of 600851475143
	long long largest = 0;
	long long num = 600851475143;

	for (long long i = sqrt(num) + 1; i > 0; i -= 2) {
		if (num % i == 0) {
			if (isPrime(i)) {
				largest = i;
				break;
			}
		}
	}
	return largest;
}

int p4() {
	// Find the largest palindrome made from the product of two three-digit numbers
	// Ex: The largest two-digit palindrome is 9009 = 91*99

	int num = 0;
	int largest = 0;

	// Brute force
	for (int i = 1; i < 999; i++) {
		for (int j = 1; j < 999; j++) {
			num = i*j;
			if (isPalindrome(num)) {
				if (num > largest) {
					largest = num;
				}
			}

		}
	}
	return largest;
}

int p5() {
	// Smallest number that can be divided by each numbers 1-20
	// 2250 is smallest of 1-10
	int i = 0;
	bool pass = 0;
	int mult;

	// Multiply the largest number and use that as the "test number" to find multiples from
	while (pass == 0) {
		pass = 1;								// Set pass tag on by default, turn it off if an equation has a remainder
		i++;
		mult = 20 * i;							// Multiple of the largest number, check if all other numbers divide by this
		for (int j = 1; j < 20; j++) {			// Try number less than 20, break if any come out with a remainder
			if (mult % j != 0) {				// Has a remainder, fails test
				pass = 0;
				break;
			}
		}

	}
	return  mult;
}

int p6() {
	// Find the difference between the sum of the squares of the first 100 natural numbers and the square of the sums
	// ie: [(a + b + c)^2] - [a^2 + b^2 +c^2]
	// First 10 numbers: 3025 - 385 = 2640
	int sum = 0;
	int sum2 = 0;
	for (int i = 1; i <= 100; i++) {
		sum += i;
		sum2 = sum2 + (i*i);
	}
	sum *= sum;						// Square the sum

	return sum - sum2;

}

int p7() {
	// Find the 10,001st prime number
	int foundPrimes = 1;	// Pre-filling 2 as a prime number
	int lastPrime = 2;

	for (int i = 3; foundPrimes < 10001; i += 2) {
		if (isPrime(i)) {
			foundPrimes++;
			lastPrime = i;
		}
	}
	return lastPrime;
}

long long p8() {
	// Find the largest product of any 13 adjacent numbers in this series:
	// Largest four-number product: 9*9*8*9 = 5832
	/*	73167176531330624919225119674426574742355349194934
		96983520312774506326239578318016984801869478851843
		85861560789112949495459501737958331952853208805511
		12540698747158523863050715693290963295227443043557
		66896648950445244523161731856403098711121722383113
		62229893423380308135336276614282806444486645238749
		30358907296290491560440772390713810515859307960866
		70172427121883998797908792274921901699720888093776
		65727333001053367881220235421809751254540594752243
		52584907711670556013604839586446706324415722155397
		53697817977846174064955149290862569321978468622482
		83972241375657056057490261407972968652414535100474
		82166370484403199890008895243450658541227588666881
		16427171479924442928230863465674813919123162824586
		17866458359124566529476545682848912883142607690042
		24219022671055626321111109370544217506941658960408
		07198403850962455444362981230987879927244284909188
		84580156166097919133875499200524063689912560717606
		05886116467109405077541002256983155200055935729725
		71636269561882670428252483600823257530420752963450
	*/

	int adjacents = 13;	// Adjacent numbers to check
	long long  largest = 0;
	int largestPos;

	string str = "7316717653133062491922511967442657474235534919493496983520312774506326239578318016984801869478851843858615607891129494954595017379583319528532088055111254069874715852386305071569329096329522744304355766896648950445244523161731856403098711121722383113622298934233803081353362766142828064444866452387493035890729629049156044077239071381051585930796086670172427121883998797908792274921901699720888093776657273330010533678812202354218097512545405947522435258490771167055601360483958644670632441572215539753697817977846174064955149290862569321978468622482839722413756570560574902614079729686524145351004748216637048440319989000889524345065854122758866688116427171479924442928230863465674813919123162824586178664583591245665294765456828489128831426076900422421902267105562632111110937054421750694165896040807198403850962455444362981230987879927244284909188845801561660979191338754992005240636899125607176060588611646710940507754100225698315520005593572972571636269561882670428252483600823257530420752963450";

	// Make array
	int * series;
	series = new int[str.length()];

	// Write string to an array as an int
	for (int i = 0; i < str.length(); i++) {
		series[i] = str.at(i);					// Write the string to an array
		series[i] -= 48;						// Fix the string to int ASCII conversion
	}



	// Search array for largest adjacent numbers
	for (int i = 0; i < str.length()-adjacents; i++) {
		long long  checkNum = 1;	// Reset this to 1, not 0, because it will be multiplied by itself (and other values)

		
		for (int j = 0; j < adjacents; j++) {
			checkNum = checkNum * series[i + j];
			if (checkNum == 0) {
				break;
			}
		}

		if (checkNum > largest) {
			largest = checkNum;
		}
		checkNum = 1;	
	}

	delete[] series;

	return largest;
}
