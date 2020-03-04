#include <stdio.h>
#include <stdlib.h>

typedef struct {
  int months;
  double contribution;
  double rate_of_return;
} retire_info;

double bankInfo(int startAge, double initial, retire_info re_info) {
  for (int i = 0; i < re_info.months; i++) {
    printf("Age %3d month %2d you have $%.2lf\n", startAge/12, startAge%12, initial);
    startAge++;
    initial = initial * (1 + re_info.rate_of_return/12) + re_info.contribution;
  }
  return initial;
}

void retirement(int startAge, double initial, retire_info working, retire_info retired) {
  initial = bankInfo(startAge, initial, working);
  startAge = startAge + working.months;
  bankInfo(startAge, initial, retired);
}

int main(void) {
  retire_info working, retired;
  working.months = 489;
  working.contribution = 1000;
  working.rate_of_return = 0.045;

  retired.months = 384;
  retired.contribution = -4000;
  retired.rate_of_return = 0.01;

  retirement(327, 21345, working, retired);
  return EXIT_SUCCESS;
}
