#include <stdio.h>
#include <stdlib.h>

int main() {
	int *data = malloc(100 * sizeof(*data));

	// Verify allocation
	if (data == NULL) {
		printf("Allocation failed.");
		return 1;
	}

	for(int i = 0; i < 100; i++) {
		data[i] = i;
	}

	// data[100] = 100;

	printf("Array item 50: %d\n", data[50]);

	// printf("Array item 100: %d\n", data[100]);
	
	free(&data[35]);
	//
	// printf("Array valye 51: %d\n", data[51]);
	
	return 0;

}
