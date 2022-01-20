#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
#define BUFFER_SIZE 1024
int main(){ 
	int fd; 
	char * myfifo = "/tmp/myfifo"; 
	mkfifo(myfifo, 0666); 
	char str1[BUFFER_SIZE], str2[BUFFER_SIZE]; 
    while (1){
		fd = open(myfifo,O_RDWR); 
    	read(fd, str1, BUFFER_SIZE); //read from fifo
		printf("%s\n", str1); 
		write(fd, str1, strlen(str1)+1); //write back to the fifo
		sleep(2);
        close(fd); 
    } 
    return 0; 
}  