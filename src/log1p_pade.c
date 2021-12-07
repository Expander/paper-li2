double log1p_pade(double x) {
   const double num = 1 + 51064./40143*x +
      44320./120429*x*x + 320./40143*x*x*x;
   const double den = 1 + 23712./13381*x +
      12320./13381*x*x + 5120./40143*x*x*x;
   return x*num/den;
}
