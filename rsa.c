#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "../BitVector/BitVector.h"

//treat the BitVector as "backwards" - i.e., mark the composites as true, not the primes
void apply_sieve(BitVector *bv, int max)
{
	int i;
	for (i = 2; i * i <= max; i++)
	{
		if (GET_BIT(bv, i - 2))
		{
			continue;
		}

		int j;
		for (j = i + i; j < max; j += i)
		{
			SET_BIT(bv, j - 2);
		}
	}
}

int main()
{
	printf("Please enter an integer: ");
	int n;
	scanf("%d", &n);

	BitVector primes;
	INITIALIZE(&primes, n);

	apply_sieve(&primes, n + 2);

	int count = 0;
	int i;
	for (i = 0; i < n; i++)
	{
		if (!GET_BIT(&primes, i))
		{
			//printf("%d\n", i + 2);
			count++;
		}
	}
	printf("%d primes below %d\n", count, n + 2);

	FREE_BITVECTOR(&primes);
	return 0;
}
