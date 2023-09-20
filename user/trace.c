#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main(int argc, char *argv[])
{
  int i;

  if (argc < 1) {
    fprintf(2, "please input sleep time..\n");
    exit(1);
  }

  i = atoi(argv[1]);


//  fprintf(2, "param 1 %s \n", argv[2]);
  //fprintf(2, "param 2 %s \n", (argv + 2)[0]);
  if (fork() == 0) {
    trace(i);
    exec(argv[2], argv + 2);
  }else {
   
  }
  wait(0);
  exit(0);
}
