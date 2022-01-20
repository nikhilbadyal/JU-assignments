#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
        //pid_t data type stands for process identification and it is used to represent process ids.
        // Whenever, we want to declare a variable that is going to be deal with the process ids we can use pid_t data type.
	pid_t child1, child2;
	int parent_pid = getpid();//this function returns the process id of the calling process
        child1 = fork();//child process is being created which runs parallel to the parent process
        int i, j;
        if(child1 < 0) {
                perror("Fork failed.\n");
                return 1;
        } else if(child1 == 0) {
                for(i=1;i<=10;i++) {
                        printf("Parent PID : %d, Process PID : %d, Iteration no: %d\n", parent_pid, getpid(), i);
                        sleep(2);
                }
        } else {
                child2 = fork();
                if(child2 < 0) {
                        perror("Fork failed.\n");
                } else if(child2 == 0 ) {
                        for(j=1;j<=10;j++) {
                                printf("Parent PID : %d, Process PID : %d, Iteration no: %d\n", parent_pid, getpid(), j);
                                sleep(1);
                        }
                }

        }
	// wait(NULL);
        // wait(NULL);
        return 0;
}
//fork() return negative when creation of child process was unsucessful, zero it is rturned to the newly child process.
//positive when returned to parent.The value contain the process Id ogf the child process.