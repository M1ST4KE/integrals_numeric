/* =============================
 * Created by Kamil Owczarz on 3/7/2018.
 *==============================
 */

#include "proto.h"


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
            std::cout << "obliczone metoda prostakatow....... " << rct(a, b, step) << "\n";
            std::cout << "obliczone metoda trapezow.......... " << trp(a, b, step) << "\n";
            std::cout << "obliczone metoda Monte Carlo....... " << MC(a, b, step) << "\n";
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
        area += funVal(a + step / 2.);
        a += step;
    }
    area *= step;
    return area;
    //return pole pod całką
}

//obliczanie całki metodą trapezów
ldb trp(ldb a, ldb b, ldb step) {
    ldb area = (a + b) / 2;
    while (a < b) {
        a += step;
        area += funVal(a);
    }
    area *= step;
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
