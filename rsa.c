#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "../BitVector/BitVector.h"

void apply_sieve(BitVector *bv, int max)
{
	int i;
	for (i = 2; i * i <= max; i++)
	{
		int j;
		for (j = i + i; j < max; j += i)
		{
			UNSET_BIT(bv, j - 2);
		}
	}
}

int main()
{
	printf("Please enter an integer: ");
	int n;
	scanf("%d", &n);

	if (n < 0)
	{
		printf("Sorry, that number is too big or is negative. Try again.\n");
		return 1;
	}

	BitVector primes;
	INITIALIZE(&primes, n);
	SET_ALL_BITS(&primes);

	printf("Applying sieve...\n");
	apply_sieve(&primes, n + 2);

	int count = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (GET_BIT(&primes, i))
		{
			count++;
		}
	}
	printf("%d primes below %d\n", count, n + 2);

	FREE_BITVECTOR(&primes);
	return 0;
}
