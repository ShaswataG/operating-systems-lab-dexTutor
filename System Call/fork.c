#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
	int q;
	q = fork();
	if (q < 0) {
		printf("Fork unsuccessful");
	} else if (q == 0) {
		printf("I am child process\nMy PID is %d\n", getpid());
		printf("My parent's PID is %d\n", getppid());
	} else {
		printf("I am parent process\nMy PID is %d\n", getpid());
		printf("My child's PID is %d\n", q);
		printf("My parent's PID is %d\n\n", getppid());
	}
	return 0;
}
