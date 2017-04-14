#include<sys/un.h>
#include<stdio.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
char * msg = "this is a client \n";
int c_fd,i;
c_fd = socket(AF_INET,SOCK_STREAM,0);
struct sockaddr_in addr;
addr.sin_family = AF_INET;
addr.sin_port = htons(50001);
addr.sin_addr.s_addr = inet_addr(argv[1]);
i=connect(c_fd,(struct sockaddr *)&addr,sizeof (addr));
if(i<0)
{
perror("connect");
exit(-1);
}
int len ;
len=strlen(msg)+1;
write(c_fd,msg,len);
close(c_fd);
exit(0);
}




