
#include <iatomic.h>
#include <icontext.h>
#include <istack.h>

#include <pthread.h>

#include <stdio.h>

static struct icontext base_context = {};
static struct icontext fiber_context = {};

static struct iatomic exit_condition = {0};

int fib(int n) {
  if (n <= 1)
    return n;
  return fib(n - 1) + fib(n - 2);
}

void fiber() {
  printf("fib(32) = %d\n", fib(32));

  iatomic_increment(&exit_condition);
  icontext_load(&base_context);
}

void thread(){

}

int main() {

  char data[1024];
  void *sp = istack_get_pointer(data, 1024);

  fiber_context.return_address = (void*)fiber;
  fiber_context.stack_pointer = sp;

  icontext_save(&base_context);

  printf("hello, world!\n");

  if (iatomic_equal(&exit_condition, 0)) {
    icontext_load(&fiber_context);
  }

  printf("goodbye!\n");
}