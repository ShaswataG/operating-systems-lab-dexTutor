#include<stdio.h>
#include<unistd.h>
int main() {
	int n = write(0, "Good morning\n", 12);
	printf("Return value of write() = %d\n", n);
	return 0;
}
