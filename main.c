
#include <iatomic.h>
#include <icontext.h>
#include <istack.h>

#include <stdio.h>
#include <stdlib.h>

int fib(int n) {
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

void fiber() {
  printf("fib(32) = %d", fib(32));

  exit(0);
}

int main() {

  //  char data[1024];
  //  void* sp = istack_get_pointer(data, 1024);

  //  struct icontext c;

  //  c.r_return = (void *)fiber;
  //  c.r_stack = sp;

  //  icontext_set(&c);

  struct iatomic a = {1};

  iatomic_add(&a, 1);

  int r = iatomic_equal(&a, 2);

  iatomic_increment(&a);

  r = iatomic_equal(&a, 3);
}