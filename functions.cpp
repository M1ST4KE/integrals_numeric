//
// Created by kamil on 3/30/2018.
//

#include <cmath>

typedef long double ldb;

ldb f1(ldb x){
    return 1. / (5. + 4. * cosl(x));
}

ldb f2(ldb x){
    return sqrtl(expl(x) - 1.);
}

ldb f3(ldb x){
    return (4 * x + 3.) / sqrtl(powl(x, 2.) + 5. * x + 7.);
}

ldb f4(ldb x){
    return powl(x, 3.) / (powl(x, 2.) - 5 * x + 6);
}