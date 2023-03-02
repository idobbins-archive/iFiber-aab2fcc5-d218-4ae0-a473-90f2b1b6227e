
#define ICONTEXT_RESERVED_COUNT 10

struct icontext {
  __attribute__((unused)) void *return_address;
  __attribute__((unused)) void *stack_pointer;
  __attribute__((unused)) void *__reserved__[ICONTEXT_RESERVED_COUNT];
};

extern void icontext_load(struct icontext *);

extern void icontext_save(struct icontext *);
