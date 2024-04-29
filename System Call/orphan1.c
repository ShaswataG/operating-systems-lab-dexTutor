#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
	int q;
	q = fork();
	if (q == 0) {
		sleep(15);
		printf("I am child having PID %d\n", getpid());
		printf("My parent's PID is %d\n", getppid());
	} else {
		sleep(10);
		printf("I am parent having PID %d\n", getpid());
		printf("My child's PID is %d\n", q);
	}

	return 0;
}
