#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
	int q;
	printf("Before fork\n");
	q = fork();
	if (q == 0) {
		printf("I am child having PID %d\n", getpid());
		printf("My parent's PID is %d\n", getppid());
	} else {
		printf("I am parent having PID %d\n", getpid());
		wait(NULL);
		printf("My child's PID is %d\n", q);
	}
	return 0;
}
