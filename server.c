#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>

int main(int argc, char* argv[])
{
	int sfd = 0;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("sfd = %d\n", sfd);
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(atoi(argv[2]));
	saddr.sin_addr.s_addr = inet_addr(argv[1]);

	bind(sfd, (struct sockaddr*)&saddr, sizeof(struct sockaddr));
	listen(sfd, 4);

	int cfd = 0;
	struct sockaddr_in caddr;
	socklen_t len = 0;
	cfd = accept(sfd, (struct sockaddr*)&caddr, &len);
	
	char buf[32] = {0};

	while(1)
	{
		memset(buf, 0, 32);
		read(cfd, buf, 32);
		printf("rcv: %s\n", buf);
	}

	close(sfd);
	return 0;
}


