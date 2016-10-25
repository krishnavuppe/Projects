#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

typedef struct
{
	int buffer[32];
	int head;
	int tail;
        int maxLen;
}ringbuff;


int BufPush(ringbuff *p, int data)
{
	int next = p->head + 1;
	if (next >= p->maxLen){next = 0;}

	if (next == p->tail){return -1;}

	p->buffer[p->head] = data;
	p->head = next;
	return 0;
}

int BufPop(ringbuff *p, int *data)
{
	if (p->head == p->tail){return -1;}

	*data = p->buffer[c->tail];
	p->buffer[p->tail] = 0;

	int next = p->tail + 1;
	if(next >= p->maxLen){next = 0;}

	p->tail = next;

	return 0;
}

int main()
{

int shmID,i,txdata=0;

ringbuff *shm;
ringbuff cb;

cb.head = 0;
cb.tail = 0;
cb.maxLen = 31;

shmID = shmget(1009, sizeof(ringbuff) , 0666 | IPC_CREAT);

shm = shmat(shmID, NULL, 0);

memcpy(&shm[0], &cb, sizeof(ringbuff));


for(i=0;i<30;i++)
{
txdata += 4;
if (BufPush(&shm[0], txdata)) {printf("Out of space in CB");}
printf("The data%d written to Cbuff is: %d \n",i+1, txdata);
}
getchar();
printf("head: %d and tail: %d\n",shm[0].head,shm[0].tail);
return 0;
}
