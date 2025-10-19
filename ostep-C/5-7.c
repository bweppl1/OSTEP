#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();

	if (pid < 0) {
		perror("fork failed");
	}
	else if (pid == 0) {
		close(STDOUT_FILENO);
		printf("hello from child\n");
	}

	printf("hello from parent\n");
}
