#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main()
{
int n, status=10;
printf("Enter the number of time you want to use fork(): ");
scanf("%d",&n);
for (int i = 0; i < n; i++){
pid_t pid = fork();
if(pid<0){
perror("Fork failed");
return 1;
}
else if (pid == 0) {
printf("I am a child process with PID: %d, Parent PID: %d\n", getpid(), getppid());
}
else{
printf("I am a parent process with PID: %d, Child PID: %d\n", getpid(),pid); wait(&status);
}
}
return 0;
}
