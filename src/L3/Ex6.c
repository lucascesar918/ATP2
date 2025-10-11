#include <stdio.h>

typedef struct {
  int day;
  char *month;
  int year;
} Date;

void print_date(Date date) {
  printf("%02d, %s, %d\n", date.day, date.month, date.year);
}

int main() {
  Date today = {7, "Outubro", 2025};

  print_date(today);

  return 0;
}