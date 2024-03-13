#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main() {
	int q, r;
	printf("Before first fork\n");
	q = fork();
	if (q < 0) {
		printf("Fork unsuccessful\n");
	} else if (q > 0) {
		printf("I am Parent with PID %d\n", getpid());
		printf("My child's PID is %d\n\n", q);
	} else {
		printf("I am Child with PID %d\n", getpid());
		printf("My parent's PID is %d\n", getppid());
		printf("Before second fork\n\n");
		r = fork();
		if (r < 0) {
			printf("Second fork unsuccessful\n");
		} else if (r > 0) {
			printf("I am Child with PID %d\n", getpid());
			printf("My parent's PID is %d\n", getppid());
			printf("My child's PID is %d\n\n", r);
		} else {
			printf("I am Grandchild with PID %d\n", getpid());
			printf("My parent's PID is %d\n\n", getppid());
		}
	
	}
	printf("Common endpoint\n");
	return 0;
}
