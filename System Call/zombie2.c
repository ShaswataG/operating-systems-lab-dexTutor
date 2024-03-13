#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
	int q;
	q = fork();
	if (q == 0) {
		printf("I am child having PID %d\n", getpid());
		printf("My parent's PID is %d\n", getppid());
		sleep(2);
		printf("Test\n");
	} else {
		wait(NULL);
		sleep(8);
		printf("I am parent having PID %d\n", getpid());
		printf("My child's PID is %d\n", q);
	}

	return 0;
}
