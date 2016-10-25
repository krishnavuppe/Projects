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


int BufPush(ringbuff *c, int data)
{
	int next = c->head + 1;
	if (next >= c->maxLen){next = 0;}

	if (next == c->tail){return -1;}

	c->buffer[c->head] = data;
	c->head = next;
	return 0;
}

int BufPop(ringbuff *c, int *data)
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

int shmID,i,rxdata=0;

ringbuff *shm;

shmID = shmget(1009, sizeof(ringbuff) , 0666 );

shm = shmat(shmID, NULL, 0);

printf("head: %d and tail: %d\n",shm[0].head,shm[0].tail);

for(i=0;i<30;i++)
{
if (BufPop(&shm[0], &rxdata)) {printf("CB is empty");}
printf("The data%d read from ringbuff is: %d \n",i+1, rxdata);
}
getchar();
printf("head: %d and tail: %d\n",shm[0].head,shm[0].tail);
return 0;
}
