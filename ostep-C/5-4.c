#include <unistd.h>

int main() {
	execl("ls", "ls", "-l", NULL);

	return 0;
}
