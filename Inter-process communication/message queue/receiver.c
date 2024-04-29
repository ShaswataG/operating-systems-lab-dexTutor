#include<sys/ipc.h>
#include<sys/types.h>
#include<sys/msg.h>
#include<stdio.h>
#include<string.h>

#define MAX 10

struct my_msg {
	long int type;
	char text[MAX];
};

int main() {
	struct my_msg some_data;
	long int msg_to_rcv = 0;
	int running = 1;
	char buf[20];
	int msgid = msgget((key_t) 1234, 0666 | IPC_CREAT);
	if (msgid == -1) {
		printf("Couldn't create message queue\n");
	} else {
		while(running == 1) {
			msgrcv(msgid, (void*) &some_data, MAX, msg_to_rcv, 0);
			printf("Message received: %s\n", some_data.text);
			if(strncmp(some_data.text, "end", 3) == 0) {
				running = 0;
			}
		}
	}
	msgctl(msgid, IPC_RMID, 0);
	return 0;
}
