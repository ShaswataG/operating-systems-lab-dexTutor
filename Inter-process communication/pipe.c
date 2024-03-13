#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<string.h>

int main() {
	int f[2], n, p;
	char buf1[50];
	char buf2[50];
	char msg[50];
	pipe(f);
	printf("Before fork\n");
	p = fork();
	if (p > 0) {
	//	printf("PARENT WITH PID: %d\n", getpid());
	//	printf("Enter data: ");
	//	strcpy(msg, "Parent\nEnter data: ");
	//	write(1, msg, strlen(msg));
		n = read(0, buf1, 50);
		write(f[1], buf1, n);
	} else {
	//	printf("CHILD WITH PID: %d", getpid());
	//	strcpy(msg, "CHILD\nData: ");
	//	write(1, msg, 50);
		n = read(f[0], buf2, 50);
		write(1, buf2, n);
	}
	return 0;
}
