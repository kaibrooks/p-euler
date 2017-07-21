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
	cout << p1();

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
