#include<sys/ipc.h>
#include<sys/shm.h>
#include<string.h>
#include<stdio.h>
#include<unistd.h>

int main() {
	void* shm;
	char buf[50];
	int shm_id, n;
	shm_id = shmget(60, 50, 0777 | IPC_CREAT);
	if (shm_id == -1) {
		printf("Error\n");
	} else {
		shm = shmat(shm_id, NULL, 0);
		printf("Process attached at %p\n", shm);
		printf("Enter data: ");
		read(0, buf, 50);
		strcpy(shm, buf);
		printf("You wrote %s", (char*) shm);
	}
	return 0;
}
