#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char* argv[]){
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if(rc == 0){
	  int i = (int) waitpid(0,NULL,0);
	  printf("child, %d\n", i);
  }
  else if(rc > 0){ //parent
	  int i = (int) waitpid(rc,NULL,0);	  
	  printf("parent, %d\n", i);
  }
  else{
	  printf("error making the shit\n");
  }
  return 0;
}
