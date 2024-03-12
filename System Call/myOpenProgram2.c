#include<unistd.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>

int main() {
	int n, fd, fd1;
	char buf[50];
	fd = open("source.txt", O_RDONLY);
	fd1 = open("target.txt", O_CREAT | O_WRONLY | O_APPEND, 0642);
	n = read(fd, buf, 10);
	write(fd1, buf, n);
	return 0;
}
