#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/shm.h>

int main() {
	void * shm;
	int shm_id, n;
	shm_id = shmget(960, 50, 0777);
	if (shm_id == -1) {
		printf("Error\n");
	} else {
		shm = shmat(shm_id, NULL, 0);
		printf("Process attached to %p", shm);
		printf("Data: %s\n", (char*) shm);
	}
	return 0;
}
