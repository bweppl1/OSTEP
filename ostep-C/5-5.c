#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();

	if (pid == 0) {
		wait(NULL);
		printf("child\n");
	}
	else {
		printf("parent\n");
	}
}
