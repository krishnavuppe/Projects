/*
   client.c
   solves part of the equation a2+2b+6c sent by server
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/socket.h>
#include<arpa/inet.h>
#include<unistd.h>

int main()
{
    int sock,mul,s;
    struct sockaddr_in server;
    char message[2000] , server_reply[2000],reply[2000];
    char o;
    //Create socket
    sock = socket(AF_INET , SOCK_STREAM , 0);
    if (sock == -1)
    {
        printf("Could not create socket");
	exit(-1);
    }
    puts("Socket created");

    server.sin_addr.s_addr = inet_addr("192.168.1.104");
    server.sin_family = AF_INET;
    server.sin_port = htons( 10000 );

    //Connect to remote server
    if (connect(sock , (struct sockaddr *)&server , sizeof(server)) == -1)
    {
        perror("connect failed. Error");
        exit(-1);
    }

    puts("Connected\n");

    while(1)
    {
        puts("waiting");
        //Receive a reply from the server
        if( read(sock , server_reply , 2000) < 0)
        {
            puts("recv failed");
            exit(-1);
        }
        puts(server_reply);
        sprintf(&o,"%.1s",server_reply);

        s = atoi(&o);
    	mul = atoi(&server_reply[1]);
        memset(server_reply,0,strlen(server_reply));

    	if(s==1)
    	{
        mul *= mul;
        }
    	else if(s==2)
    	{
        mul *= 2;
        }
    	else if(s==3)
    	{
        mul *= 6;
        }

    	sprintf(server_reply,"%d",mul);
    	//Send data
    	if( send(sock , server_reply , strlen(server_reply) , 0) < 0)
    	{
        	puts("Send failed");
        	exit(-1);
        }
    	memset(server_reply,0,strlen(server_reply));
    }
}
