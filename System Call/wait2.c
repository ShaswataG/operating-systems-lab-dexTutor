#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

int main() {
	int p, q, w1;
	printf("Before fork\n");
	q = fork();
	if (q == 0) {
		printf("I am first child having PID %d\n", getpid());
		printf("My parent's PID is %d\n", getppid());
	} else {
		p = fork();
		if (p == 0) {
			printf("I am second child having PID %d\n", getpid());
			printf("My parent's PID is %d\n", getppid());
		} else {
			printf("I am parent having PID %d\n", getpid());
			w1 = waitpid(p, NULL, 0);	
			printf("My first child's PID is %d\n", q);
			printf("My second child's PID is %d\n", p);
		}
	}
	return 0;
}
