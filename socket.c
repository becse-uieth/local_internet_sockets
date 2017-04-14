#include<stdio.h>
#include<sys/un.h> 
#include<sys/socket.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>

int main(int argc,char*argv[])
{
int s_fd;
char msg[1000],ch;
s_fd=socket(AF_LOCAL,SOCK_STREAM,0);
struct sockaddr_un addr;
addr.sun_family=AF_LOCAL;
strcpy(addr.sun_path,argv[1]);
bind(s_fd,(struct sockaddr *)&addr,sizeof(addr));
listen(s_fd,5);
int c_fd,i=0;
struct sockaddr_un c_addr;
socklen_t size_addr = sizeof (c_addr);
c_fd=accept(s_fd,(struct sockaddr *)&c_addr,&size_addr);
int count =1;
count+=1;
while(count)
{
count=read (c_fd,&ch,1);
msg[i]=ch;
i++;
}
close(s_fd);
printf("%s",msg);
exit(0);
}
