#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[]){
  printf("hello world (pid:%d)\n", (int) getpid());
  int x = 100;
  printf("value of x at the start:%d\n", x);
  int rc = fork();
  if(rc == 0){
	  x = x + 2;
	  printf("child process pid:%d, value of x:%d\n", (int) getpid(), x);
  }
  else if(rc > 0){
	  x = x + 2;
	  printf("parent process pid:%d ,child process pid:%d , value of x:%d\n", (int) getpid(), rc, x);
  }
  else{
	  printf("error making the shit\n");
  }
  return 0;
}
