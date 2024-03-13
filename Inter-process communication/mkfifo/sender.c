#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
	int m, n;
	char buf[50];
	printf("Enter data: ");
	m = read(0, buf, 50);
	n = open("fifo1", O_WRONLY);
	write(n, buf, m);
	printf("Sender with PID %d has completed execution\n", getpid());
	return 0;
}
