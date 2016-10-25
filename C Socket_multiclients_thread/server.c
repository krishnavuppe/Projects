/*
   server.c
solves the equation A^2+2B+6C by assigned parts of computation to clients
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<pthread.h>

int A,B,C,D,a,b,c,i,t,X,Y,Z,clientnum,count;

void *connection_handler(void *socket_desc)
{
    i++;
    int j = i;
    int eq = 1;
    int client_sock;
    client_sock = *(int*)socket_desc;
    int num;
    char c_message[2000];

    //Free the socket pointer
    free(socket_desc);

    while(1)
    {
    		if(j==1)
    		{
        		sprintf(&c_message[0],"%d",j);
    			sprintf(&c_message[1],"%d",a);
    		}
    		else  if(j==2)
    		{
			sprintf(&c_message[0],"%d",j);
        		sprintf(&c_message[1],"%d",b);
    		}
    		else if(j==3)
    		{
			sprintf(&c_message[0],"%d",j);
        		sprintf(&c_message[1],"%d",c);
    		}

    		if( write(client_sock , c_message , strlen(c_message)) < 0)
    		{
         		puts("error during write");
    		}

    		memset(c_message,0,strlen(c_message));

    		read(client_sock , c_message , 2000);
    		num = atoi(c_message);
    		puts(c_message);
    		memset(c_message,0,strlen(c_message));

    		if(j==1)
    		{
        		A = num;
			X = 1;
    		}
    		else  if(j==2)
    		{
        		B = num;
			Y = 1;
    		}
    		else if(j==3)
    		{
        		C = num;
			Z = 1;
    		}

		while(eq == count){}
		eq++;
		

/*              while(X == 1 || Y == 1 || Z == 1 ){}*/
	        
    }
}


int main(int argc , char *argv[])
{
    srand(time(NULL));

    int socket_desc , client_sock , g , *new_sock;
    struct sockaddr_in server , client;

    //Create socket
    socket_desc = socket(AF_INET , SOCK_STREAM , 0);
    if (socket_desc == -1)
    {
        printf("Could not create socket");
    }
    puts("Socket created");

    //Prepare the sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 10000 );

    //Bind
    if( bind(socket_desc,(struct sockaddr *)&server , sizeof(server)) < 0)
    {
        //print the error message
        perror("bind failed. Error");
        return 1;
    }
    puts("bind done");

    //Listen
    listen(socket_desc , 3);

    //Accept and incoming connection
    puts("Waiting for incoming connections...");
    g = sizeof(struct sockaddr_in);

    //accept connection from an incoming client
    while(1)
    {
          t++;
	  if(t==1)
	  {
		printf("Program for solving A^2 + 2B + 6c \n ");
		a = (rand()%9)+1;
		b = (rand()%9)+1;
		c = (rand()%9)+1;
                printf("new randomly entered nums are A= %d, B= %d, C= %d\n",a,b,c);
		X=0,Y=0,Z=0;
		count++;
          }
          if(X>0 && Y>0 && Z>0)
	  {
		D = A+B+C;
		printf("Solution of the equation%d is: %d\n",count,D);
		A=0,B=0,C=0,D=0,a=0,b=0,c=0,t=0;
		getchar();
		printf("\n\n Starting a new equation calculation\n\n");
	  }
     

	  if(clientnum < 3)
          {
                client_sock = accept(socket_desc, (struct sockaddr *)&client, (socklen_t*)&g);

	  	if (client_sock < 0)
   	  	{
       	      		perror("accept failed");
             	        return 1;
   	  	}
          	puts("Connection accepted");

    	  	pthread_t sniffer_thread;
          	new_sock = malloc(1);
          	*new_sock = client_sock;

          	if( pthread_create( &sniffer_thread , NULL ,  connection_handler , (void*) new_sock) < 0)
          	{
              		perror("could not create thread");
              		return 1;
          	}

          	//Now join the thread , so that we dont terminate before the thread
          	//pthread_join( sniffer_thread , NULL);
          	puts("Handler assigned");
		clientnum ++;
          }
    }

    return 0;
}
