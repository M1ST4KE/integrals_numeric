//
// Created by Kamil Owczarz on 3/7/2018.
//

#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <iostream>
#include <ctime>


#define MAX(a,b) (a > b)?a:b

typedef long double ldb;

long double funVal(long double);
long double rct(long double, long double, long double);
long double trp(long double, long double, long double);
long double MC(long double, long double, long double);
long double rngPoint(long double, long double);