#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if(rc == 0){
	  close(STDOUT_FILENO);
	  printf("child\n");
  }
  else if(rc > 0){ //parent
	  wait(NULL);
	  printf("parent\n");
  }
  else{
	  printf("error making the shit\n");
  }
  return 0;
}
