
struct iatomic {
  int value;
};

void iatomic_add(struct iatomic *a, int v);
int iatomic_equal(struct iatomic *a, int v);

void iatomic_increment(struct iatomic *a);
