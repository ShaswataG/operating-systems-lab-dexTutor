#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
	int n, fd, fd1;
	char buf[50];
	fd = open("source.txt", O_CREAT | O_RDWR, 0642);
	n = read(0, buf, 50);
	write(fd, buf, n);
	return 0;
}

