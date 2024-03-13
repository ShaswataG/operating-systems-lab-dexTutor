#include<stdio.h>
#include<unistd.h>
#include<pthread.h>

int i, j;

void* thread_function(void* arg) {
	printf("Inside Thread\n");
	for (i = 0; i < 5; i++) {
		printf("%d ", i);
//		sleep(1);
	}
	printf("\n");
}

int main() {
	pthread_t a_thread;
	pthread_create(&a_thread, NULL, thread_function, NULL);
//	pthread_join(a_thread, NULL);
	printf("Inside Main Process\n");
	for (j = 20; j < 25; j++) {
		printf("%d ", j);
		sleep(1);
	}
	printf("\n");
	return 0;
}
