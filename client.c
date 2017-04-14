#include<sys/un.h>
#include<stdio.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<string.h>
#include<unistd.h>
int main(int argc,char* argv[])
{
int c_fd;
c_fd = socket(AF_LOCAL,SOCK_STREAM,0);
struct sockaddr_un addr;
addr .sun_family = AF_LOCAL;
strcpy(addr.sun_path,argv[1]);
connect(c_fd,(struct sockaddr *)&addr,sizeof (addr));
char *msg = "this is client";
int len;
len = strlen(msg);
write(c_fd , msg , len+1);
exit(0);
close(c_fd);
}

