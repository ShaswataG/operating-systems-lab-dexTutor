#include<unistd.h>
#include<stdio.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>

int main() {
	int n, m;
	char buf[50];
	m = open("fifo1", O_RDONLY);
	read(m, buf, 50);
	printf("Data: %s", buf);
	printf("Receiver has completed execution\n");
	return 0;
}
