//
// Created by Kamil Owczarz on 3/7/2018.
//

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <ctime>
#include "functions.cpp"



typedef long double ldb;

struct intArea;

intArea rct(ldb, ldb, ldb); // NOLINT
intArea trp(ldb, ldb, ldb); // NOLINT
intArea MC(ldb, ldb, ldb); // NOLINT
long double rngPoint(ldb, ldb); // NOLINT