/* =============================
 * Created by Kamil Owczarz on 3/7/2018.
 *==============================
 */

#include "proto.h"

int main() {
    ldb a, b, step;
    std::cout << "podaj a, b i długosc przedzialu" << "\n";
    std::cin >> a;
    std::cin >> b;
    std::cin >> step;
    std:: cout << rct(a, b, step) << "\n" << trp(a, b, step) << "\n" << MC(a, b, step);
    return 0;
}

//oblicznie odległości punktu należącego do funkcji od osi OX
ldb funVal(ldb x) {
    //reuturn fabsl(dowolna funkcja);
    //return fabsl(3 * x * x * x + 3 * x * x + 7 * x + 21);
    return fabsl(x);
}

//obliczanie całki metodą prostokątów
ldb rct(ldb a, ldb b, ldb step) {
    ldb area = 0;
    for (ldb i = a; i < b + step / 2.; i += step)
        area += funVal(i + step / 2.) * step;
    return area;
    //return pole pod całką
}

//obliczanie całki metodą trapezów
ldb trp(ldb a, ldb b, ldb step) {
    ldb area = 0;
    ldb fVal1 = funVal(a);
    for (ldb i = a; i < b + step; i += step) {
        ldb fVal2 = funVal(i + step);
        area += ((fVal1 + fVal2) * step) / 2.;
        fVal1 = fVal2;
    }
    return area;
    //return pole pod całką
}

//obliczanie całki metodą Monte Carlo
ldb MC(ldb a, ldb b, ldb step) {
    int ptIn = 0;
    step = (b - a) / step; //by liczba iteracji była porównywalna do wcześniejszych metod
    srand((unsigned)time(nullptr));
    ldb ya = 0;
    ldb yb = ceil(MAX(funVal(a),funVal(b)));
    for (int i = 0; i < step; i++)
        ptIn += rngPoint(a, b), rngPoint(ya, yb);
    return (ptIn / step) * ((b-a) * (yb-ya));
    //return pole pod całką
}

//losowanie punktu do met Monte Carlo
ldb rngPoint(ldb a, ldb b) {
    return a + static_cast<long double>(rand()) / static_cast<long double>((RAND_MAX+1)) * (b-a);
}