
#include "istack.h"

#include <stdlib.h>

void *istack_get_pointer(void *stack, unsigned int size) {
  char *result = (char *)(stack + size);
  result = (char *)((uintptr_t)result & -16L);
  result -= 128;

  return (void *)result;
}

