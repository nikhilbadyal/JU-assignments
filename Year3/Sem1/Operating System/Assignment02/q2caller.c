#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#define BUFFER_SIZE 80
int main(){
    int fd;
    char * myfifo = "/tmp/myfifo";
    mkfifo(myfifo, 0666);
    char buffer_in[BUFFER_SIZE], buffer_out[BUFFER_SIZE],dummy;
    while (1){
        fd = open(myfifo, O_WRONLY);
	printf("Enter your message: ");
        //fgets(buffer_out, BUFFER_SIZE, stdin);
	scanf("%[^\n]s",buffer_out);
	scanf("%c",&dummy);        
	write(fd, buffer_out, strlen(buffer_out)+1);
        close(fd);
        fd = open(myfifo, O_RDONLY);
        read(fd, buffer_in, sizeof(buffer_in));
        printf("Reciever: %s\n", buffer_in);
        close(fd);
    }
    return 0;
}