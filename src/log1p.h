double log1p_naive(double);
double log1p_horner(double);
double log1p_estrin(double);
double log1p_pade(double);
double log1p_mixed(double);

struct Fn {
   double (*f)(double);
   const char* name;
};

const struct Fn functions[] = {
   { log1p_naive , "log1p_naive"  },
   { log1p_horner, "log1p_horner" },
   { log1p_estrin, "log1p_estrin" },
   { log1p_pade  , "log1p_pade"   },
   { log1p_mixed , "log1p_mixed"  },
};
