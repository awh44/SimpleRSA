#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <limits.h>

#include "../ADT_List/ADT_List.h"


#define MAX_NUM 1000000

void apply_sieve(List *l, int max)
{
	Node *prime_node = FIRST(l);
	while ((!IS_END(prime_node)) && (RETRIEVE(prime_node) * RETRIEVE(prime_node) < max))
	{
		int current_prime = RETRIEVE(prime_node);
		Node *node = NEXT(prime_node);
		while (!IS_END(node))
		{
			if (RETRIEVE(node) % current_prime == 0)
			{
				REMOVE(node);
			}
			else
			{
				node = NEXT(node);
			}
		}
		prime_node = NEXT(prime_node);
	}
}

int main()
{
	//printf("Please enter an integer: ");
	int n = MAX_NUM;
	//scanf("%d", &n);

	List primes;
	INITIALIZE(&primes);

	int i;
	for (i = n; i > 1; i--)
	{
		INSERT(i, FIRST(&primes));
	}

	apply_sieve(&primes, n);
	PRINTLIST(&primes);

	FREE_LIST(&primes);

	return 0;
}
