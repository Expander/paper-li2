#include <stdio.h>
#include <math.h>
#include "log1p.h"

unsigned failed = 0;
unsigned passed = 0;


const double values[] = {
   0, 0.1, -0.1
};


#define CHECK_CLOSE(val,a,b,eps,name) do {                              \
      const double aa = fabs(a);                                        \
      const double ab = fabs(b);                                        \
      const double mx = aa > ab ? aa : ab;                              \
      const double ae = fabs(eps);                                      \
      const double rel = fabs(aa - ab)/(1 + mx);                        \
      if (rel < ae) {                                                   \
         passed++;                                                      \
      } else {                                                          \
         printf("Error in %s(%g): %g ~!~ %g (rel. diff. %g < %g)\n", name, val, aa, ab, rel, ae); \
         failed++;                                                      \
      }                                                                 \
   } while (0);


int main() {
   const double eps = 1e-6;

   for (int i = 0; i < sizeof(functions)/sizeof(functions[0]); ++i) {
      for (int v = 0; v < sizeof(values)/sizeof(values[0]); ++v) {
         const double (*f)(double) = functions[i].f;
         const double val = values[v];
         CHECK_CLOSE(val, f(val), log1p(val), eps, functions[i].name);
      }
   }

   printf("Tests passed: %u/%u\n", passed, passed + failed);

   return failed > 0;
}
