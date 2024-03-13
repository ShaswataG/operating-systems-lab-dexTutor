#include<unistd.h>
#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>

int main() {
	int n;
	n = mkfifo("fifo1", 0777);
	printf("Named pipe created\n");
	return 0;
}
