#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int fd[2];
	pipe(fd);

	pid_t pid = fork();


	if (pid < 0) {
		perror("fork failed");
	}
	else if (pid == 0) {
		close(fd[0]); // close read 
		printf("hello\n");
		close(fd[1]); // close write - signals ready 
	}
	else {
		close(fd[1]); // close write
		char buffer;
		while (read(fd[0], &buffer, 1) > 0); // holds process until child closes write
		printf("goodbye\n");
		close(fd[0]); // closes read
	}
	return 0;
}
