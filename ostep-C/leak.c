#include <stdlib.h>
#include <stdio.h>

int main() {
	int *x = malloc(sizeof(int));

	*x = 10;

	printf("Allocating %ld bytes", sizeof(x));

	return 0;
}
