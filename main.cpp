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
    std::cout << "obliczone metoda prostakatow....... " << rct(a, b, step) << "\n";
    std::cout << "obliczone metoda trapezow.......... " << trp(a, b, step) << "\n";
    std::cout << "obliczone metoda Monte Carlo....... " << MC(a, b, step) << "\n";
    return 0;
}

//oblicznie odległości punktu należącego do funkcji od osi OX
ldb funVal(ldb x) {
    //reudturn fabsl(dowolna funkcja);
    return fabsl(3 * x * x * x + 3 * x * x + 7 * x + 21);
    //return x;
}

//obliczanie całki metodą prostokątów
ldb rct(ldb a, ldb b, ldb step) {
    ldb area = 0;
    while (a < b) {
        area += funVal(a + step / 2.) * step;
        a += step;
    }
    return area;
    //return pole pod całką
}

//obliczanie całki metodą trapezów
ldb trp(ldb a, ldb b, ldb step) {
    ldb area = 0;
    ldb fVal1 = funVal(a);
    while (a < b) {
        a += step;
        ldb fVal2 = funVal(a);
        area += ((fVal1 + fVal2) * step) / 2.;
        fVal1 = fVal2;
    }
    return area;
    //return pole pod całką
}

//obliczanie całki metodą Monte Carlo
ldb MC(ldb a, ldb b, ldb step) {
    ldb fVal = 0;
    step = (b - a) / step;    //by liczba iteracji była porównywalna do wcześniejszych metod
    srand(static_cast<unsigned int>(time(nullptr)));
    int i;
    for (i = 0; i < step; i++)
        fVal += funVal(rngPoint(a, b));
    fVal = (fVal / i) * (b - a);

    return fVal;
    //return pole pod całką
}

//losowanie punktu do met Monte Carlo
ldb rngPoint(ldb a, ldb b) {
    return a + static_cast<long double>(rand()) / static_cast<long double>((RAND_MAX+1)) * (b-a);
}