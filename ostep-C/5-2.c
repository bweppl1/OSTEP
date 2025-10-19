#include <string.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>

int main() {
	int fd = open("text.txt", O_RDWR);

	printf("File Descriptor: %d\n", fd);
	
	pid_t pid = fork();

	if (pid < 0) {
		perror("Failed Fork");
	}
	else if (pid == 0) {
		printf("Forked File Descriptor: %d\n", fd);
	}
	else {
		printf("Main File Descriptor: %d\n", fd);
	}

	char *text = "Hello how is everyone?\n";

	write(fd, text, strlen(text));
	
	return 0;
}

