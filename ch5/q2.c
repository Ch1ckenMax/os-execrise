#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
  printf("hello world (pid:%d)\n", (int) getpid());
  close(STDOUT_FILENO);
  open("./q2.output", O_CREAT|O_WRONLY|O_TRUNC, S_IRWXU);
  int rc = fork();
  if(rc == 0){
	  printf("child process pid:%d\n", (int) getpid());
  }
  else if(rc > 0){
	  printf("parent process pid:%d\n", (int) getpid());
  }
  else{
	  printf("error making the shit\n");
  }
  return 0;
}
