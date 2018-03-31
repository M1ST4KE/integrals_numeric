/* =============================
 * Created by Kamil Owczarz on 3/7/2018.
 *==============================
 */

#include "proto.h"


struct intArea {
    ldb f1;
    ldb f2;
    ldb f3;
    ldb f4;
};

int main() {
    ldb a, b, step;
    bool run = false;
    int i = 0;
    std::cout << "podaj  przedział całkowania a, b i ddokladnosc" << "\n";
    std::cin >> a;
    std::cin >> b;
    std::cin >> step;
    step = 1. / step;
    do {
        while (step == 0) {
            std::cout << "podaj dokladonsc rozna od 0\n";
            std::cin >> step;
            step = 1. / step;
            i++;
            if (i > 3){
                std::cout << "przekroczono maksymalna liczbe wprowadzenia blednych argumentow\n";
                system("pause");
                return 1;
            }
        }
        if (step < 0.1 || run){
            run = true;
            intArea mc = MC(a, b, step), tr = trp(a, b, step), rc = rct(a, b, step);
            std::cout << "funkcja f1 = 1 / (5 + 4cos(x))" << "\n";
            std::cout << "obliczona metoda prostakatow....... " << rc.f1 << "\n";
            std::cout << "obliczona metoda trapezow.......... " << tr.f1 << "\n";
            std::cout << "obliczona metoda Monte Carlo....... " << mc.f1 << "\n";
            std::cout << "funkcja f2 = sqrt(exp(x) - 1)" << "\n";
            std::cout << "obliczona metoda prostakatow....... " << rc.f2 << "\n";
            std::cout << "obliczona metoda trapezow.......... " << tr.f2 << "\n";
            std::cout << "obliczona metoda Monte Carlo....... " << mc.f2 << "\n";
            std::cout << "funkcja f3 = (4x + 3) / sqr(x^2 + 5x +7)" << "\n";
            std::cout << "obliczona metoda prostakatow....... " << rc.f3 << "\n";
            std::cout << "obliczona metoda trapezow.......... " << tr.f3 << "\n";
            std::cout << "obliczona metoda Monte Carlo....... " << mc.f3 << "\n";
            std::cout << "funkcja f4 = x^3 / (x^2 - 5x + 6)" << "\n";
            std::cout << "obliczona metoda prostakatow....... " << rc.f4 << "\n";
            std::cout << "obliczona metoda trapezow.......... " << tr.f4 << "\n";
            std::cout << "obliczona metoda Monte Carlo....... " << mc.f4 << "\n";
            system("pause");
            return 0;
        }
        else {
            std::cout << "czy na pewno chcesz uruchomic program z tak mala dokladonsca?\n(t/n)\n";
            char runTxt;
            std::cin >> runTxt;
            if (runTxt == 't' || runTxt == 'T')
                run = true;
            else {
                std::cout << "podaj nowa dokladnosc";
                std::cin >> step;
                step = 1. / step;
            }
        }
        if (i > 3){
            std::cout << "przekroczono maksymalna liczbe wprowadzenia blednych argumentow\n";
            system("pause");
            return 1;
        }
        i++;
    } while (!run);

}

//obliczanie całki metodą prostokątów
intArea rct(ldb a, ldb b, ldb step) {
    intArea ar{0, 0, 0, 0};
    while (a < b) {
        ar.f1 += fun1(a + step / 2.);
        ar.f2 += fun2(a + step / 2.);
        ar.f3 += fun3(a + step / 2.);
        ar.f4 += fun4(a + step / 2.);
        a += step;
    }
    ar.f1 *= step;
    ar.f2 *= step;
    ar.f3 *= step;
    ar.f4 *= step;
    return ar;
    //return pole pod całką
}

//obliczanie całki metodą trapezów
intArea trp(ldb a, ldb b, ldb step) {
    intArea ar{};
    ar.f1 = (a + b) / 2;
    ar.f2 = (a + b) / 2;
    ar.f3 = (a + b) / 2;
    ar.f4 = (a + b) / 2;
    while (a < b) {
        a += step;
        ar.f1 += fun1(a);
        ar.f2 += fun2(a);
        ar.f3 += fun3(a);
        ar.f4 += fun4(a);
    }
    ar.f1 *= step;
    ar.f2 *= step;
    ar.f3 *= step;
    ar.f4 *= step;
    return ar;
    //return pole pod całką
}

//obliczanie całki metodą Monte Carlo
intArea MC(ldb a, ldb b, ldb step) {
    intArea fVal{0, 0, 0, 0};
    step = (b - a) / step;    //by liczba iteracji była porównywalna do wcześniejszych metod
    srand(static_cast<unsigned int>(time(nullptr)));
    int i;
    for (i = 0; i < step; i++) {
        fVal.f1 += fun1(rngPoint(a, b));
        fVal.f2 += fun2(rngPoint(a, b));
        fVal.f3 += fun3(rngPoint(a, b));
        fVal.f4 += fun4(rngPoint(a, b));
    }
    fVal.f1 = (fVal.f1 / i) * (b - a);
    fVal.f2 = (fVal.f2 / i) * (b - a);
    fVal.f3 = (fVal.f3 / i) * (b - a);
    fVal.f4 = (fVal.f4 / i) * (b - a);

    return fVal;
    //return pole pod całką
}

//losowanie punktu do met Monte Carlo
ldb rngPoint(ldb a, ldb b) {
    return a + static_cast<long double>(rand()) / static_cast<long double>((RAND_MAX+1)) * (b-a); // NOLINT
}
