#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "log1p.h"

#define N 1000000

double values[N];


double bench_fn(double (*f)(double), const char* name) {
   const double time_in_s = 0;

   for (int i = 0; i < sizeof(values)/sizeof(values[0]); ++i) {
      double res = f(values[i]);
   }

   printf("%s: %g seconds\n", name, time_in_s);
}


int main() {
   srand(time(NULL));

   for (unsigned i = 0; i < N; ++i) {
      values[i] = rand()/RAND_MAX;
   }

   for (int i = 0; i < sizeof(functions)/sizeof(functions[0]); ++i) {
      bench_fn(functions[i].f, functions[i].name);
   }

   return 0;
}
