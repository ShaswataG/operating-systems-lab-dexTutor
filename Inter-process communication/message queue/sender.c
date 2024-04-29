#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#include<stdio.h>

#define MAX 50

struct my_msg {
	long int msg_type;
	char msg_text[MAX];
};

int main() {
	int running = 1;
	int msgid;
	struct my_msg some_data;
	char buf[20];
	msgid = msgget((key_t) 1234, 0666 | IPC_CREAT);
	if (msgid == -1) {
		printf("Error: Couldn't create message queue\n");
	} else {
		while (running) {
			printf("Enter text: ");
			fgets(buf, 20, stdin);
			some_data.msg_type = 1;
			strcpy(some_data.msg_text, buf);
			if (msgsnd(msgid, (void*) &some_data, MAX, 0) == -1) {
				printf("Error: Couldn't send message\n");
			}
			if (strncmp(buf, "end", 3) == 0) {
				running = 0;
			}
		}
	}
	return 0;

}
