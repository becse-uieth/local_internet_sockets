#include<stdio.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
int main(int argc,char* argv[])
{
int s_fd;
s_fd = socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_port = htonl(50001);
addr.sin_addr.s_addr = inet_addr(argv[1]);
bind(s_fd,(struct sockaddr * )&addr, sizeof (addr));
listen(s_fd,5);
struct sockaddr_in c_addr;
socklen_t size_addr;
int c_fd;
c_fd = accept(s_fd,(struct sockaddr *)&addr,&size_addr);
char ch;
char msg[100];
int i=0 ,count = 1 ;
while(count)
{
count = read(c_fd,&ch,1);
msg[i] = ch;
i++;
}
printf("%s",msg);
close(s_fd);
exit(0);
}

