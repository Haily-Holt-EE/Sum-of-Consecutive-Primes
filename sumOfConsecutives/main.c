#include "primes.h"

int main (void)
{
	int num = 0, found = 0, size = 0, i = 0;
	int *conseq = NULL;

	printf("Please enter a number: ");
	scanf("%d", &num);

	found = isSumofConsequtivePrimes(num, &conseq, &size);

	if (found == 1)
	{
		printf("Your number is the sum of consecutive primes!\n");
		printf("Consecutive prime numbers: ");

		for (i = 0; i < size; i++)
		{
			printf("%d ", conseq[i]);
		}

		printf("\n\n");
	}
	else
	{
		printf("Your number is NOT the sum of consecutive primes!\n\n");
	}

	free(conseq);

	return 0;
}