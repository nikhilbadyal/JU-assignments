#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#define BUFFER_SIZE 1024  
int main() 
{ 
    int fd; 
    char * myfifo = "/tmp/myfifo"; 
    mkfifo(myfifo, 0666); 
    char buffer[BUFFER_SIZE], dummy; 
    while (1){ 
        fd = open(myfifo, O_RDWR); 
	    printf("Enter Meassage: ");
	    scanf("%[^\n]s",buffer);
	    scanf("%c",&dummy);
        printf("Broadcasting...\n");
	    write(fd, buffer, strlen(buffer)+1);
        sleep(2);
        read(fd, buffer, BUFFER_SIZE);//to clear the buffer 
        close(fd); 
    } 
    return 0; 
}