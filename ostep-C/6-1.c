#define  _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sched.h>
#include <string.h>


int main() {
	// simulate single processor setup to test process speed of operations: context switching, piping between parent/child
	cpu_set_t set;
	CPU_ZERO(&set); // clear cpus
	CPU_SET(0, &set); // using cpu 0 exclusively
	
	// create pipe
	int fd_one[2];
	int fd_two[2];
	pipe(fd_one);
	pipe(fd_two);

	// create fork
	pid_t pid = fork();

	// timer
	struct timeval start, end;

	int process_count = 10000;

	gettimeofday(&start, NULL);		
	// child writes i times
	if (pid == 0) {
		close(fd_one[0]);
		close(fd_two[1]);
		
		for(int i = 0; i < process_count; i++) {
			// p1 write
			char p1_message[100];
			snprintf(p1_message, sizeof(p1_message), "hello #%d from process 1!", i);
			write(fd_one[1], p1_message, strlen(p1_message));
			
			// p1 read
			char buff[100];
			int bytes_p1 = read(fd_two[0], buff, sizeof(buff));
			// if (bytes_p1 > 0) {
			// 	buff[bytes_p1] = '\0';
			// 	printf("process 1 received: %s\n", buff);
			// }
		}
		close(fd_one[1]);
		close(fd_two[0]);
		_exit(0);
	}
	else {
		// parent received and reads i messages
		close(fd_one[1]);
		close(fd_two[0]);

		for(int i = 0; i < process_count; i++) {
			char p2_message[100];
			snprintf(p2_message, sizeof(p2_message), "hello #%d from process 2!", i);
			// p2 write
			write(fd_two[1], p2_message, strlen(p2_message));
			// p2 read
			char buf[100];
			int bytes = read(fd_one[0], buf, sizeof(buf));
			// if (bytes > 0) {
			// 	buf[bytes] = '\0'; // clear buffer
			// 	printf("process 2 received: %s\n", buf);
			// }
		}
		close(fd_one[0]);
		close(fd_two[1]);
	}

	gettimeofday(&end, NULL);

	double context_switch_timer = ((end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0);
	double seconds_per_switch = context_switch_timer / (process_count * 2);

	printf("Seconds per context switch: %.6f\n", seconds_per_switch);

	return 0;
}
