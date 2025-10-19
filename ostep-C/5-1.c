#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int x = 1;

	printf("Parent Process ID: %d - X = %d\n", getpid(), x);

	pid_t pid = fork();

	if (pid == 0) {
		printf("Child Process ID: %d - X = %d\n", getpid(), x);
	}
	else {
		x = 20;
		printf("Modified Parent Process ID: %d - X = %d\n", getpid(), x);
	} 

	printf("Final X - PID: %d, X: %d\n", getpid(), x);
}


