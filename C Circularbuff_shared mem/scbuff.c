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
}circBuf_t;


int circBufPush(circBuf_t *c, int data)
{
	int next = c->head + 1;
	if (next >= c->maxLen){next = 0;}

	if (next == c->tail){return -1;}

	c->buffer[c->head] = data;
	c->head = next;
	return 0;
}

int circBufPop(circBuf_t *c, int *data)
{
	if (c->head == c->tail){return -1;}

	*data = c->buffer[c->tail];
	c->buffer[c->tail] = 0;

	int next = c->tail + 1;
	if(next >= c->maxLen){next = 0;}

	c->tail = next;

	return 0;
}

int main()
{

int shmID,i,txdata=0;

circBuf_t *shm;
circBuf_t cb;

cb.head = 0;
cb.tail = 0;
cb.maxLen = 31;

shmID = shmget(1009, sizeof(circBuf_t) , 0666 | IPC_CREAT);

shm = shmat(shmID, NULL, 0);

memcpy(&shm[0], &cb, sizeof(circBuf_t));


for(i=0;i<30;i++)
{
txdata += 4;
if (circBufPush(&shm[0], txdata)) {printf("Out of space in CB");}
printf("The data%d written to Cbuff is: %d \n",i+1, txdata);
}
getchar();
printf("head: %d and tail: %d\n",shm[0].head,shm[0].tail);
return 0;
}
