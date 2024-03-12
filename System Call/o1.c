#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<unistd.h>

int main() {
	int n, fd;
	char buf[10];
	fd = open("text1.txt", O_RDONLY);
	n = read(fd, buf, 10);
	write(1, buf, n);
	return 0;
}
