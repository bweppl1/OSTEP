#include <string.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
	int pipefd[2];
	pipe(pipefd);

	const int CHILDREN_COUNT = 2;

	pid_t children[CHILDREN_COUNT];

	for (int i = 0; i < CHILDREN_COUNT; i++) {
		pid_t pid = fork();

		if (pid < 0) {
			perror("fork failed");
		}
		else if (pid == 0) {
			close(pipefd[0]); // close read pipe
			printf("First child, #%d, with PID: %d\n", i, getpid());
			char *sending_message = "hello world!";
			write(pipefd[1], sending_message, strlen(sending_message));
			close(pipefd[1]);
			exit(i);	
		}
		else if (pid > 0) {
			close(pipefd[1]); // clopsing write pipe
			char buf[100];
			ssize_t received_message = read(pipefd[0], buf, sizeof(buf) - 1);

			if (received_message > 0) {
				buf[received_message] = '\0'; // null terminate
				printf("!dlrow olleh - %s\n", buf);
			}
			close(pipefd[0]);
		}


	}
	return 0;
}
