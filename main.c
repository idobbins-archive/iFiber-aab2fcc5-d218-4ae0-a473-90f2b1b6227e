
#include <context.h>

#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

void fiber() {
  printf("fib(32) = %d", fib(32));
  exit (0);
}

int main() {

  char data[1024];

  char *sp = (char *)(data + sizeof data);
  sp = (char *)((uintptr_t)sp & -16L);
  sp -= 128;

  volatile int a = 0;

  struct icontext c;

  c.r_return = (void*)fiber;
  c.r_stack = sp;

  icontext_set(&c);
}