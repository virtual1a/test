#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void panic(char*);

int
main(int argc, char *argv[])
{
  int p[2];
  char i;

  if (pipe(p) < 0)
    panic("pipe");




  if (fork() == 0) {
    read(p[0], &i, 1);
    fprintf(1, "%d:received ping %c\n", getpid(), i);
    write(p[1], "A", 1);

  }else {
    write(p[1], "B", 1);
    wait(0);
    read(p[0], &i, 1);
    fprintf(1, "%d:received pong %c\n", getpid(), i);
  }


  close(p[0]);
  close(p[1]);
 

  exit(0);
}

void
panic(char* s)
{
  fprintf(2, "%s\n", s);
  exit(1);
}
