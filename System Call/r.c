#include<stdio.h>
#include<unistd.h>

int main() {
	int n;
	char buf[30];
//	printf("Enter data: ");
	n = read(0, buf, 30);
//	printf("Data: ");
	write(1, buf, n);
	return 0;
}
