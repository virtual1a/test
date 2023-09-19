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

  trace(i);
  fprintf(2, "param 1 %s \n", argv[2]);
  fprintf(2, "param 2 %s \n", (argv + 3)[0]);
  exec(argv[2], argv+3);
  trace(0);
  exit(0);
}
