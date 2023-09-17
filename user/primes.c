#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

void panic(char*);
void test();

int i;
int n;
int p[2];
int pid = 0;

int
main(int argc, char *argv[])
{


  if (pipe(p) < 0)
    panic("pipe");


  if (fork() == 0) {
    test();
  }else {
    int s;
    for (s = 2; s < 35; s++) {
      write(p[1], &s, 1);
    }
  }





  close(p[0]);
  close(p[1]);
  wait(0);
  exit(0);
}


void
test() {
  read(p[0], &n, 1);
  fprintf(1, "%d:prime  %d\n", getpid(), n);



  close(0);
  dup(p[0]);
  close(p[0]);
  close(p[1]);

  if (pipe(p) < 0)
    panic("pipe");


  while (read(0, &i, 1) != 0) {
    if (i % n != 0) {
      write(p[1], &i, 1);
      if (pid == 0 && (pid = fork()) == 0) {
        test();
      }
    }
  }
}


void
panic(char* s)
{
  fprintf(2, "%s\n", s);
  exit(1);
}


