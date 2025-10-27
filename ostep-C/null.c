#include <stdlib.h>
#include <stdio.h>

int main() {
	int *x = malloc(sizeof(int));

	x = NULL;

	printf("X is: %d\n", *x);

	return 0;
}
