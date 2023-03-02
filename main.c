
#include <iatomic.h>
#include <icontext.h>
#include <istack.h>

#include <stdio.h>
#include <stdlib.h>

static struct icontext base_context;
static struct icontext fiber_context;

static struct iatomic exit_condition = {0};

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

    char data[1024];
    void* sp = istack_get_pointer(data, 1024);

    icontext_get(&base_context);

    printf("hello, world!\n");

    if(iatomic_equal(&exit_condition, 0)) {
        iatomic_increment(&exit_condition);
        icontext_set(&base_context);
    }
//  struct iatomic a = {1};

//  iatomic_add(&a, 1);

//  int r = iatomic_equal(&a, 2);

//  iatomic_increment(&a);

//  r = iatomic_equal(&a, 3);
}