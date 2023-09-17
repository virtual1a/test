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
  fprintf(1, "begin sleep\n");
  sleep(i);
  fprintf(1, "end sleep\n");
  exit(0);
}
