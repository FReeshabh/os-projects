//Rishabh Tewari
//Operating Systems CS 4352
//Miniproject-3
#include <stdio.h>
#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void execute(char* const args[])
{
  int i; 
  printf("*** Entered:");
  for (i = 0; args[i] != NULL; i++)
    printf(" %s", args[i]);
  printf(" (%d words)\n", i);

  //My Code from here
  pid_t pid;
  pid = fork();
  int status;

  if (pid < 0) {
    /* ERROR */
    fprintf(stderr, "ERROR: Fork failed");
    exit(1);
  } 
  else if (pid == 0){
    // Child Process
        if ((execvp(*args, args)) < 0 ) //returns negative if invalid
          fprintf(stderr, "\n***Command not found\n");
  } 
  else {
    //Parent Process
    
    // We know that the child process is being executed, and the parent process needs to wait for it to finish running
    if ( waitpid(pid, &status, 0) == -1 ) {
        perror("waitpid() failed");
        exit(EXIT_FAILURE);
    }
    if ( WIFEXITED(status) ) {
        if(WEXITSTATUS(status) != 0) //If the exit code is not 0. Display the code
            printf("***Command exited with %d\n", WEXITSTATUS(status));
        else //if the exit code is 0, show the program ended sucessfully
            printf("***Command exited sucessfully\n");
    }
  }
}
