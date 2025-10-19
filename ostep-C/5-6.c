#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	pid_t pid = fork();

	if (pid == 0) {
		printf("child\n");
		int status;
		waitpid(pid, &status, 0);
	}
	else {
		printf("parent\n");
	}
}
