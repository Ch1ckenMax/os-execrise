#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h>

int main(int argc, char* argv[]){
  printf("hello world (pid:%d)\n", (int) getpid());
  int rc = fork();
  if(rc == 0){
	  printf("hello ima gonna run the program bin ls\n");
	  
	  //arguments
	  char* args[2];
	  args[0] = strdup("/bin/ls");
	  args[1] = (char*) NULL;
	  execl(args[0],strdup("/bin/ls"),(char*) NULL);

	  
  }
  else if(rc > 0){ //parent

	  printf("This is the parent process\n");
  }
  else{
	  printf("error making the shit\n");
  }
  return 0;
}
