#include <stdio.h>
#include <unistd.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/time.h>
#include <sys/types.h>
#include<time.h>

#define MAXLINE 1024

int main()
{
    int s_socket,c_socket;
    struct timeval t1,t2;
    pid_t childpid;
    int ex;


    char ans[MAXLINE];
    char welcome[MAXLINE] = "Welcome to KBC!!!\n";
    char rules[MAXLINE] = "This is an MCQ Quiz where four options will be given and you have to select and type the correct option.\nThe time given for each question is 60 seconds.\n If you select the wrong option or if you don't respond within the time, you will be eliminated.\n";
    char ready[MAXLINE] = "\nLet's Start!\n\n";
    char late[MAXLINE] = "You have not submitted in Time! You are elimintated!\n";
    char correct[MAXLINE] = "Correct Answer!\n\n\n";
    char wrong[MAXLINE] = "Wrong Answer! You are Eliminated! Better Luck Next Time!\n";
    char win[MAXLINE] = "CONGRATULATIONS! You are the winner!\n\n";
    char lose[MAXLINE] = "You lose. Well tried.\n\n";
    char end[MAXLINE] = "end";
    char cont[MAXLINE] = "continue";

    char ques1[MAXLINE] = "PM of India?\nA.Modi\nB.Rahul\nC.Trump\nD.Putin\n";
    char ques2[MAXLINE] = "Prez of India?\nA.Modi\nB.Kovind\nC.Trump\nD.Putin\n";
    char ques3[MAXLINE] = "Prez of USA?\nA.Modi\nB.Rahul\nC.Trump\nD.Putin\n";
    char ques4[MAXLINE] = "Prez of Russia?\nA.Modi\nB.Rahul\nC.Trump\nD.Putin\n";
    char ques5[MAXLINE] = "Capital Of India?\nA.Mumbai\nB.Kolkata\nC.Delhi\nD.Chennai\n";

    int minname;

    s_socket = socket(AF_INET,SOCK_STREAM,0);
    if(s_socket==-1)
    {
        printf("Socket couldn't be created!\n");
        return 0;
    }
    struct sockaddr_in server,client;
    memset(&server,0,sizeof(server));
    server.sin_family = AF_INET;
    server.sin_port = htons(9000);
    server.sin_addr.s_addr = INADDR_ANY;
    if(bind(s_socket,(const struct sockaddr*)&server,sizeof(server)))
    {
        printf("Bind unsuccessful!\n");
        return 0;
    }    
    if(listen(s_socket, 10) == 0)
    {
		printf("Listening..\n");
    }
	 
    socklen_t size = sizeof(client);

    
    while(1)
    {
		c_socket = accept(s_socket,(struct sockaddr*)&client,&size);
		if(c_socket < 0)
        {
			exit(1);
		}
		printf("Connection accepted from %s:%d\n", inet_ntoa(client.sin_addr), ntohs(client.sin_port));
        if((childpid = fork()) == 0)
        {
            double total_time = 0;
            double elapsedTime;
            double mintime = 51;

		    close(s_socket);
            send(c_socket,welcome,sizeof(welcome),0);//Send Welcome Message
            send(c_socket,rules,sizeof(rules),0);//Send Rules
            send(c_socket,ready,sizeof(ready),0);//Sends Ready Message



            //Question 1
            send(c_socket,ques1,sizeof(ques1),0);
            gettimeofday(&t1, NULL);
            bzero(ans,sizeof(ans));
            recv(c_socket,&ans,sizeof(ans),0);
            gettimeofday(&t2, NULL);
            elapsedTime = t2.tv_sec - t1.tv_sec;
            if(elapsedTime > 60) 
            {
                send(c_socket,late,sizeof(late),0);//Send Late Message
                send(c_socket,end,sizeof(end),0);
                printf("Disconnected from %s port %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                total_time = 0;
            }
            total_time = total_time + elapsedTime;
            if(strcmp(ans,"A")!=0)
            {
                send(c_socket,wrong,sizeof(wrong),0);//Send Wrong Message
                send(c_socket,end,sizeof(end),0);
                printf("Disconnected from %s port %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                total_time = 0;
            }
            else
            {
                send(c_socket,correct,sizeof(correct),0);
                send(c_socket,cont,sizeof(cont),0);
            }



            //Question 2
            send(c_socket,ques2,sizeof(ques2),0);
            gettimeofday(&t1, NULL);
            bzero(ans,sizeof(ans));
            recv(c_socket,&ans,sizeof(ans),0);
            gettimeofday(&t2, NULL);
            elapsedTime = t2.tv_sec - t1.tv_sec;
            if(elapsedTime > 60) 
            {
                send(c_socket,late,sizeof(late),0);//Send Late Message
                send(c_socket,end,sizeof(end),0);
                printf("Disconnected from %s port %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                total_time = 0;
            }
            total_time = total_time + elapsedTime;
            if(strcmp(ans,"B")!=0)
            {
                send(c_socket,wrong,sizeof(wrong),0);//Send Wrong Message
                send(c_socket,end,sizeof(end),0);
                printf("Disconnected from %s port %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                total_time = 0;
            }
            else
            {
                send(c_socket,correct,sizeof(correct),0);
                send(c_socket,cont,sizeof(cont),0);
            }


            //Question 3
            send(c_socket,ques3,sizeof(ques3),0);
            gettimeofday(&t1, NULL);
            bzero(ans,sizeof(ans));
            recv(c_socket,&ans,sizeof(ans),0);
            gettimeofday(&t2, NULL);
            elapsedTime = t2.tv_sec - t1.tv_sec;
            if(elapsedTime > 60) 
            {
                send(c_socket,late,sizeof(late),0);//Send Late Message
                send(c_socket,end,sizeof(end),0);
                printf("Disconnected from %s port %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                total_time = 0;
            }
            total_time = total_time + elapsedTime;
            if(strcmp(ans,"C")!=0)
            {
                send(c_socket,wrong,sizeof(wrong),0);//Send Wrong Message
                send(c_socket,end,sizeof(end),0);
                printf("Disconnected from %s port %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                total_time = 0;
            }
            else
            {
                send(c_socket,correct,sizeof(correct),0);
                send(c_socket,cont,sizeof(cont),0);
            }


            //Question 4
            send(c_socket,ques4,sizeof(ques4),0);
            gettimeofday(&t1, NULL);
            bzero(ans,sizeof(ans));
            recv(c_socket,&ans,sizeof(ans),0);
            gettimeofday(&t2, NULL);
            elapsedTime = t2.tv_sec - t1.tv_sec;
            if(elapsedTime > 60) 
            {
                send(c_socket,late,sizeof(late),0);//Send Late Message
                send(c_socket,end,sizeof(end),0);
                printf("Disconnected from %s port %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                total_time = 0;
            }
            total_time = total_time + elapsedTime;
            if(strcmp(ans,"D")!=0)
            {
                send(c_socket,wrong,sizeof(wrong),0);//Send Wrong Message
                send(c_socket,end,sizeof(end),0);
                printf("Disconnected from %s port %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                total_time = 0;
            }
            else
            {
                send(c_socket,correct,sizeof(correct),0);
                send(c_socket,cont,sizeof(cont),0);
            }



            //Question 5
            send(c_socket,ques5,sizeof(ques5),0);
            gettimeofday(&t1, NULL);
            bzero(ans,sizeof(ans));
            recv(c_socket,&ans,sizeof(ans),0);
            gettimeofday(&t2, NULL);
            elapsedTime = t2.tv_sec - t1.tv_sec;
            if(elapsedTime > 60) 
            {
                send(c_socket,late,sizeof(late),0);//Send Late Message
                send(c_socket,end,sizeof(end),0);
                printf("Disconnected from %s port %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                total_time = 0;
            }
            total_time = total_time + elapsedTime;
            if(strcmp(ans,"C")!=0)
            {
                send(c_socket,wrong,sizeof(wrong),0);//Send Wrong Message
                send(c_socket,end,sizeof(end),0);
                printf("Disconnected from %s port %d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
                total_time = 0;
            }
            else
            {
                send(c_socket,correct,sizeof(correct),0);
                send(c_socket,cont,sizeof(cont),0);
            }



            printf("Total Time taken by %d: %f seconds\n",ntohs(client.sin_port),total_time);
            if(total_time < mintime)
	        {
		        mintime = total_time;
	            minname = ntohs(client.sin_port);
	        }
            printf("Do you want to exit (Press 1 to exit): \n"); //0 to exit
		    scanf("%d", &ex);
	        if(ex==1)
	        {
                break;
            }

        }
    }
    close(s_socket);
    close(c_socket);
	printf("Disconnected.\n");
    printf("winner is %d\n",minname);
    return 0;
}
