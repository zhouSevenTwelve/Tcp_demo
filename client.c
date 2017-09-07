#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <netinet/in.h>
#include <string.h>

int main(int argc, char* argv[])
{
	int sfd = 0;
	sfd = socket(AF_INET, SOCK_STREAM, 0);
	printf("sfd = %d\n", sfd);
	struct sockaddr_in saddr;
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(atoi(argv[2]));
	saddr.sin_addr.s_addr = inet_addr(argv[1]);

	connect(sfd, (struct sockaddr*)&saddr, sizeof(struct sockaddr));

	char buf[32] = {0};

	while(1)
	{
		memset(buf, 0, 32);
		gets(buf);
		write(sfd, buf, strlen(buf));
	}
	
	close(sfd);
	return 0;
}


