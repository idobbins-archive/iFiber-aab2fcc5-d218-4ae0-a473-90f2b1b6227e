
struct icontext {
  void *r_return;
  void *r_stack;
  void *r_preserved_0;
  void *r_preserved_1;
  void *r_preserved_2;
  void *r_preserved_3;
  void *r_preserved_4;
  void *r_preserved_5;
  void *r_preserved_6;
  void *r_preserved_7;
  void *r_preserved_8;
  void *r_preserved_9;
  void *r_preserved_10;
};

extern void icontext_set(struct icontext *);

extern void icontext_get(struct icontext *);
