#include <unistd.h>
#include <stdio.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <sys/time.h>
int main()
{
    int c_socket;
    char ans[1024];
    char msg[1024];
    c_socket = socket(AF_INET,SOCK_STREAM,0);
    if(c_socket==-1)
    {
        printf("Couldn't open socket!\n");
        return 0;
    }    
    struct sockaddr_in client;
    client.sin_family = AF_INET;
    client.sin_port = htons(9000);
    client.sin_addr.s_addr = INADDR_ANY;
    if(connect(c_socket,(const struct sockaddr*)&client,sizeof(client)))
    {
        printf("Can't connect to Server!\n");
        return 0;
    }    
    int num1,num2;
    int choice;
    int result;

    recv(c_socket,msg,sizeof(msg),0);
    printf("%s",msg);//recv and print welcome msg
    recv(c_socket,msg,sizeof(msg),0);
    printf("%s",msg);//recv and print rules list
    recv(c_socket,msg,sizeof(msg),0);
    printf("%s",msg);//recv and print ready msg



    //Question 1
    recv(c_socket,&msg,sizeof(msg),0);
    printf("%s",msg);
    printf("Enter your Answer:");
    scanf("%s",&ans);
    send(c_socket,ans,sizeof(ans),0);//sends answer
    recv(c_socket,&msg,sizeof(msg),0);//recvs right or wrong
    printf("%s",msg);
    recv(c_socket,&msg,sizeof(msg),0);//recvs end or continue
    if(strcmp(msg,"end")==0)
    {    
        close(c_socket);
        return 0;
    }

    //Question 2
    recv(c_socket,&msg,sizeof(msg),0);
    printf("%s",msg);
    printf("Enter your Answer:");
    scanf("%s",&ans);
    send(c_socket,ans,sizeof(ans),0);//sends answer
    recv(c_socket,&msg,sizeof(msg),0);//recvs right or wrong
    printf("%s",msg);
    recv(c_socket,&msg,sizeof(msg),0);//recvs end or continue
    if(strcmp(msg,"end")==0)
    {
        close(c_socket);
        return 0;
    } 

    //Question 3
    recv(c_socket,&msg,sizeof(msg),0);
    printf("%s",msg);
    printf("Enter your Answer:");
    scanf("%s",&ans);
    send(c_socket,ans,sizeof(ans),0);//sends answer
    recv(c_socket,&msg,sizeof(msg),0);//recvs right or wrong
    printf("%s",msg);
    recv(c_socket,&msg,sizeof(msg),0);//recvs end or continue
    if(strcmp(msg,"end")==0)
    {
        close(c_socket);
        return 0;
    }  


    //Question 4
    recv(c_socket,&msg,sizeof(msg),0);
    printf("%s",msg);
    printf("Enter your Answer:");
    scanf("%s",&ans);
    send(c_socket,ans,sizeof(ans),0);//sends answer
    recv(c_socket,&msg,sizeof(msg),0);//recvs right or wrong
    printf("%s",msg);
    recv(c_socket,&msg,sizeof(msg),0);//recvs end or continue
    if(strcmp(msg,"end")==0)
    {
        close(c_socket);
        return 0;
    }


    //Question 5
    recv(c_socket,&msg,sizeof(msg),0);
    printf("%s",msg);
    printf("Enter your Answer:");
    scanf("%s",&ans);
    send(c_socket,ans,sizeof(ans),0);//sends answer
    recv(c_socket,&msg,sizeof(msg),0);//recvs right or wrong
    printf("%s",msg);
    recv(c_socket,&msg,sizeof(msg),0);//recvs end or continue
    if(strcmp(msg,"end")==0)
    {
        close(c_socket);
        return 0;
    }
    close(c_socket);

}
