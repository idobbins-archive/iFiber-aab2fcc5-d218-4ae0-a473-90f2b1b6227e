
#include <context.h>

#include <stdio.h>

int main() {
  volatile int a = 0;

  struct icontext c;

  icontext_get(&c);

  printf("hello world\n");

  if (a == 0) {
    a = 1;
    icontext_set(&c);
  }

}