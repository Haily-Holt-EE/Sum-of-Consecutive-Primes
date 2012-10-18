#include "primes.h"

//Creates an array of all prime numbers less than the inputted number, then traverses backwards through that array while summing numbers to see if there is a consecutive sum of primes.
int isSumofConsequtivePrimes( int n, int **consecutives, int *size )
{
	int *primeNums = NULL;
	int i = 0, primeCount = 0, backwardsI = 0, backwardsI2 = 0, primesSum = 0, found = 0;

	for (i = 2; i < n; i++)//populates an array with all of the prime numbers less than the number inputted by the user.
	{
		if (isPrime(i))
		{
			primeCount++;
			primeNums = (int*)realloc((int*)primeNums, (sizeof(int) * primeCount));
			primeNums[primeCount - 1] = i;
		}
	}

	for (backwardsI = primeCount; (backwardsI > 0) && (found != 1); backwardsI-- )//Starts at outermost prime number, then counts down each time sum of consecutive primes is not found.
	{
		//essentially sets everything previously modified by the inner for-loop to a zero / "empty" value.
		primesSum = 0;
		*size = 0;
		free(*consecutives);
		*consecutives = NULL;

		for (backwardsI2 = backwardsI - 1; (primesSum < n) && (backwardsI2 >= 0); backwardsI2--)//Sums the numbers in the array down from the index of the outer for-loop
		{
			(*size)++;
			*consecutives = (int *)realloc((int*)(*consecutives), (sizeof(int) * (*size)));
			(*consecutives)[(*size) - 1] = primeNums[backwardsI2];

			primesSum += primeNums[backwardsI2];

			if (primesSum == n)
			{
				found = 1;
			}
		}
	}

	free(primeNums);
	return found;

}

//Returns 1 (true) or 0 (false) corresponding to whether a number is prime or not.
int isPrime( int n )
{
	int root = 0, i = 0;

	root = sqrt((double)n) + 1;

	for(i = 2; i < root; i++)
	{
		if (n % i == 0)
		{
			return 0;
		}
	}

	return 1;
}

