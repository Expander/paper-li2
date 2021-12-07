Needs["FunctionApproximations`"];

(* bring rational function to standard form *)
PolynomialStandardForm[expr_, x_] :=
    Module[{n = Numerator[expr], d = Denominator[expr], c},
           c = d /. x -> 0;
           Expand[n/c] / Expand[d/c]
    ];

pade = EconomizedRationalApproximation[Log[1+x]/x, {x, {-1,1}, 3, 3}]

pade = PolynomialStandardForm[pade,x]
