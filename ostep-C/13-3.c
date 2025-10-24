#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
	size_t memory_size;
	int sleep_time;
	
	// get memory size
	printf("How much memory to allocate? (Megabytes): ");
	// handle invalid memory input
	if(scanf("%zu", &memory_size) != 1 || memory_size == 0) {
		fprintf(stderr, "Out of memory??????\n");
		return 1;
	}

	// allocate
	memory_size *= 1000000U;
	// handle failed malloc
	void *ptr = malloc(memory_size);
	if (ptr == NULL) {
		fprintf(stderr, "MALLOC FAILED, RUNNNN!!\n");
		return 1;
	}

	memset(ptr, 0, memory_size); // forcing allocation
	printf("Allocating %zu bytes at pointer %p\n", memory_size, ptr);

	// get run time
	printf("How long to hold? (sec.): ");
	if (scanf("%d", &sleep_time) != 1 || sleep_time == 0) {
		fprintf(stderr, "Sleep input error.\n");
		free(ptr);
		return 1;
	}

	sleep(sleep_time);

	// end program
	free(ptr);
	printf("Program ended. Memory free.\n");
	return 0;
}
